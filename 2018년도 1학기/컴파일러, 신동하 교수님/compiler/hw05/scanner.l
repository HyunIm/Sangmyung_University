/*
   * @File : scanner.l
   * @Author : 임현 (201511054@sangmyung.kr)
   * @Since : 2018 - 05 - 09
*/

/* ====================================================================== */

%{
	/* -------- #include, #define 및 C 언어 변수 선언 -------- */
#include "parser.h"
#include <string.h>

/* ====================================================================== */

	// ACCEPT 매크로
#define	ACCEPT(x) return(x)
#define	ACCEPT_LEX(x) \
{ \
  yytext[yyleng] = '\0'; \
  lex = malloc(yyleng + 1); \
  strcpy(lex, yytext); \
  return(x); \
}

/* ====================================================================== */

int source_line_no = 1;		// 몇 번째 라인인지 출력할 변수
char *lex;			/* current lexeme of ID or NUM */

/* ====================================================================== */

%}
	/* -------- Flex Macro -------- */
digit				[0-9]
letter				[a-zA-Z]

%%
	/* -------- Keywords -------- */
"void"		ACCEPT(VOID);
"int"		ACCEPT(INT);
"if"		ACCEPT(IF);
"else"		ACCEPT(ELSE);
"while"		ACCEPT(WHILE);
"return"	ACCEPT(RETURN);
"input"		ACCEPT(INPUT);
"output"	ACCEPT(OUTPUT);

	/* -------- Special symbols -------- */
"+"	ACCEPT(PLUS);
"-"	ACCEPT(MINUS);
"*"	ACCEPT(MULTIPLY);
"/"	ACCEPT(DIVIDE);
"<"	ACCEPT(LT);
"<="	ACCEPT(LE);
">"	ACCEPT(GT);
">="	ACCEPT(GE);
"=="	ACCEPT(EQ);
"!="	ACCEPT(NE);
"="	ACCEPT(ASSIGN);
","	ACCEPT(COMMA);
";"	ACCEPT(SEMICOLON);
"("	ACCEPT(LPAR);
")"	ACCEPT(RPAR);
"{"	ACCEPT(LBRACE);
"}"	ACCEPT(RBRACE);
"["	ACCEPT(LBRACKET);
"]"	ACCEPT(RBRACKET);

	/* -------- Identifier -------- */
({letter}|_)({letter}|{digit}|_)*	ACCEPT_LEX(ID);

	/* -------- Number -------- */
{digit}{digit}*				ACCEPT_LEX(NUM);

	/* -------- WhiteSpaces -------- */
" "	{}
"\t"	{}
"\r"	{}
"\n"	{source_line_no++;}

	/* -------- Comments -------- */
"/*".*|\n*"*/"		{}
"//".*"\n"		{source_line_no++;}

	/* -------- 오류 -------- */
.	ACCEPT_LEX(UNDEFINED);
%%

/* ====================================================================== */
