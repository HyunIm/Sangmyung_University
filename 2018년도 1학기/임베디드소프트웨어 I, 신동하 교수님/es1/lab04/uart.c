// ======================================================================
// File: uart.c
// Author : 임현 (201511054@sangmyung.kr)
// Since : 2018 - 04 - 17
// Note that only UART1 of BeagleBone is used here!
// ======================================================================

#include <uart.h>

// ======================================================================

// ======== 매크로 ========

// volatile : 내가 바꾸지 않더라도 바뀔 수 있다고 경고
// 	-> IO Devied 전부 이렇게 선언
// unsigned int : 4 바이트

// addr을 주면 읽어옴
#define IO_READ(addr)		(*(volatile unsigned int *)(addr))
// addr과 val을 주면 씀
#define IO_WRITE(addr, val)	(*(volatile unsigned int *)(addr) = (val))

// ======================================================================

// 레지스터 주소 매크로
#define UART1_RHR_REG	0x44e09000	// UART1 Receive holding register
#define UART1_THR_REG	0x44e09000	// UART1 Transmit holding register
#define UART1_LSR_REG	0x44e09014	// UART1 Line status register

// &로 체크하기 위한 매크로
#define LSR_RX_FIFO_E	0x01	// LSR receive fifo empty
#define LSR_TX_FIFO_E	0x20	// LSR transmit fifo empty

// ======================================================================

// UART에서 한 문자 입력
int UART_getc(void)
{
	unsigned int c;	// 입력할 문자 지역 변수

	// Status를 읽어서 empty하고 &
	// Read UART1_LSR_REG and check LSR_RX_FIFO_E bit
	while ((IO_READ(UART1_LSR_REG) & LSR_RX_FIFO_E) == 0);

	// Read a character from UART1_RHR_REG.
	c = IO_READ(UART1_RHR_REG);

	// 입력이 오면 화면 출력으로 확인
	// Echo back the character.
	UART_putc(c);

	// 읽어온 character return
	return (int) c;
}

// ======================================================================

// UART에서 한 문자 입력 (no blocking)
int UART_getc_noblock(void)
{
	unsigned int c;	// 입력할 문자 지역 변수

	// no blocking이니 0이면 return 0
	while ((IO_READ(UART1_LSR_REG) & LSR_RX_FIFO_E) == 0)
		return 0;

	// UART1_RHR_REG에서 character를 하나 읽어옴
	c = IO_READ(UART1_RHR_REG);

	// 입력이 오면 화면 출력으로 확인
	UART_putc(c);

	// 읽어온 character return
	return (int) c;
}

// ======================================================================

// UART에서 32비트(=8개 숫자) 16진수 입력
unsigned int UART_gethex(void)
{
	unsigned int c;	// 입력할 문자열(16진수) 지역 변수
	int result = 0; // ASCII -> Hex로 바꿀 지역 변수

	while ((c = UART_getc()))	// 한 문자씩 처리
	{
		// c가 캐리지 리턴 혹은 다음 줄 인 경우
		if ((c == '\r') || (c == '\n'))
			break;	// 입력 종료
		
		result *= 16;	// 자릿수 증가
		
		if ('0' <= c && c <= '9')	// '0' <= c <= '9' (즉 숫자라면)
			result += c - '0';	// ASCII -> Number ('0'을 빼줌)
		else if ('a' <= c && c <= 'f')	// 'a' <= c <= 'f' (즉 알파벳 소문자라면)
			result += c - 'a' + 10; // ASCII -> Number ('a'를 빼고 10을 더함)
					// 10을 더하는 이유는 hex에서 a는 10이기 때문
		else if ('A' <= c && c <= 'F')	// 'A' <= c <= 'F' (즉 알파벳 대문자라면) 
			result += c - 'A' + 10;	// ASCII -> Number ('a'를 빼고 10을 더함)
		else		// 숫자도, 알파벳도 아닐 경우 비정상 종료
			return -1;
	}

	// ASCII -> Hex로 바꾼 값 반환
	return result;
}

// ======================================================================

// UART에서 한 줄 입력
char *UART_gets(char *str)
{
	unsigned int c; // 입력할 문자 지역 변수
	int index = 0;	// 배열의 index를 나타내기 위한 지역 변수

	while ((c = UART_getc()))	// 한 문자씩 처리
	{
		// c가 캐리지 리턴 혹은 다음 줄 인 경우
		// 즉, 한 줄 입력이 끝났을 경우
		if ((c == '\r') || (c == '\n'))
			break;	// 입력 종료
		str[index++] = c;	// str배열에 현재 문자를 넣고 index++(후위연산)
	}
	
	str[index] = '\0';	// 마지막을 '\0'(=NULL)으로 삽입함으로써 문자열로 만들어줌

	// 생성한 문자열 반환
	return str;
}

// ======================================================================

// UART로 한 문자 출력
int UART_putc(int c)
{
	// if c is a '\r' or a '\n', put a '\r' and a '\n'.
	if ((c == '\r') || (c == '\n')) {
		c = '\r';

		// Read UART1_LSR_REG and check LSR_TX_FIFO_E bit.
		while ((IO_READ(UART1_LSR_REG) & LSR_TX_FIFO_E) == 0);

		// Write a character to UART1_THR_REG.
		IO_WRITE(UART1_THR_REG, c);

		c = '\n';
	}

	// Read UART1_USR_REG and check LSR_TX_FIFO_E bit.
	while ((IO_READ(UART1_LSR_REG) & LSR_TX_FIFO_E) == 0);

	// Write a character to UART1_THR_REG.
	IO_WRITE(UART1_THR_REG, c);

	return c;
}

// ======================================================================

// UART로 한 스트링 출력
int UART_puts(const char *s)
{
	int index = 0; // 배열의 index를 나타내기 위한 지역 변수

	while (s[index] != '\0')	// '\0'(=NULL=문자열 끝)이 나올 때 까지
		UART_putc(s[index++]);	// 입력 배열을 하나씩 읽음 (후위연산)

	// 정상 종료
	return 0;
}

// ======================================================================

// 화면을 지움 (VT100 단말기 기준)
// ANSI/VT100 Terminal Control Escape Sequences 참고
// -> (http://www.termsys.demon.co.uk/vtansi.htm)
void UART_clear(void)
{
	// Erase Screen		<ESC>[2J
	// 여기서 ESC문자는 아스키 코드로 0x1B
	UART_puts("\x1B[2J");
}

// ======================================================================

// 화면의 좌표 (x, y) 커서로 보냄
// ANSI/VT100 Terminal Control Escape Sequences 참고
void UART_goto(int x, int y)
{
	// Cursor Home		<ESC>[{ROW};{COLUMN}H
	UART_printf("\x1B[%d;%dH", y, x);
}

// ======================================================================

// sprintf()
int UART_sprintf(char *out, const char *format, ...)
{
  extern int print(char **out, int *varg);

  register int *varg = (int *) (&format);
  return print(&out, varg);
}

// ======================================================================

// printf()
int UART_printf(const char *format, ...)
{
  extern int print(char **out, int *varg);

  register int *varg = (int *) (&format);
  return print(0, varg);
}

// ======================================================================
