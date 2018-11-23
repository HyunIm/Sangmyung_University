#include <string.h>
#include <stdio.h>

void normal_function(const char* input)
{
	char buf[10];
	
	printf("Stack before input :\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
	// strcpy 함수를 통해 input값을 buf에 복사
	// strcpy 함수는 NTBS 보장을 안 하기 때문에 모두 복사
	strcpy(buf, input);
	printf("%s\n", buf);
	printf("Stack after input :\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
}

// 해킹 성공을 Test 해볼 함수
// 해당 함수의 주소 값(0x8048498)으로 ret값을 덮어씌움
void hacked_function(void)
{
	printf("I am hacked!\n");
}

int main(int argc, char* argv[])
{
	// normal_function과 hacked_function의 시작 주소 출력
	printf("The address of normal_function = %p\n", normal_function);
	printf("The address of hacked_function = %p\n", hacked_function);

	// 명령행 인자가 2개가 아니라면 비정상 종료
	if (argc != 2)
	{
		printf("Input one argument\n");
		return -1;
	}

	// 2번째 명령행 인자를 normal_function 매개변수로 넣음
	normal_function(argv[1]);
	
	return 0;
}
