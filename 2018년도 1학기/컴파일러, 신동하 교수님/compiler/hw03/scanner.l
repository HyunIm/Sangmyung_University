/**
  * @File : scanner.l
  * @Author : 임현 (201511054@sangmyung.kr)
  * @Since : 2018 - 04 - 13
  */

/* ====================================================================== */

%{
/* -------- #include, #define 및 C 언어 변수 선언 -------- */
// ACCEPT 매크로
#define ACCEPT(x) \
{ \
	printf("line=%i, token=%s, lexeme=\"%s\" \n", source_line_no, (char *)x, yytext); \
	fflush(stdout); \
}

// 몇 번째 라인인지 출력할 변수
int source_line_no = 1;
%}

	/* -------- flex macro -------- */
digit				[0-9]
letter				[a-zA-Z]

%%
	/* -------- Keywords -------- */
"void"		ACCEPT("VOID");
"int"		ACCEPT("INT");
"if"		ACCEPT("IF");
"else"		ACCEPT("ELSE");
"while"		ACCEPT("WHILE");
"return"	ACCEPT("RETURN");
"input"		ACCEPT("INPUT");
"output"	ACCEPT("OUTPUT");

	/* -------- Special symbols -------- */
"+"	ACCEPT("PLUS");
"-"	ACCEPT("MINUS");
"*"	ACCEPT("MULTIPLY");
"/"	ACCEPT("DIVIDE");
"<"	ACCEPT("LT");
"<="	ACCEPT("LE");
">"	ACCEPT("GT");
">="	ACCEPT("GE");
"=="	ACCEPT("EQ");
"!="	ACCEPT("NE");
"="	ACCEPT("ASSIGN");
","	ACCEPT("COMMA");
";"	ACCEPT("SEMICOLON");
"("	ACCEPT("LPAR");
")"	ACCEPT("RPAR");
"{"	ACCEPT("LBRACE");
"}"	ACCEPT("RBRACE");
"["	ACCEPT("LBRACKET");
"]"	ACCEPT("RBRACKET");

	/* -------- Identifier -------- */
({letter}|_)({letter}|{digit}|_)*	ACCEPT("ID");

	/* -------- Number -------- */
{digit}{digit}*				ACCEPT("NUM");

	/* -------- WhiteSpaces -------- */
" "	{}
"\t"	{}
"\r"	{}
"\n"	{source_line_no++;}

	/* -------- Comments -------- */
"/*".*|\n*"*/"		{}
"//".*"\n"		{source_line_no++;}

	/* -------- 오류 -------- */
.	ACCEPT("UNDEFINED");

%%

/* ====================================================================== */

int main(int argc, char *argv[])
{
  if(argc != 2) {
    fprintf(stderr, "usage: scanner file\n");
    exit(1);
  }
  yyin = fopen(argv[1], "r");
  if(yyin == NULL) {
    fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
    exit(1);
  }
  yylex();

  return 0;
}

/* ====================================================================== */
