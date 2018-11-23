/*
   * @File : scanner.l
   * @Author : 임현 (201511054@sangmyung.kr)
   * @Since : 2018 - 05 - 23
*/

/* ====================================================================== */

%{

typedef struct l_type_struct {	/* lex for var and num */
  char *lex;
} l_type;

typedef struct t_type_struct {	/* type for type_specifier */
  unsigned char type;
} t_type;

/* ====================================================================== */

#include "parser.h"
#include <string.h>

/* ====================================================================== */

#define	ACCEPT(x) return(x)
#define	ACCEPT_LEX(x) \
{ \
  yytext[yyleng] = '\0'; \
  lex = malloc(yyleng + 1); \
  strcpy(lex, yytext); \
  return(x); \
}

/* ====================================================================== */

char *lex;			/* current lexeme of ID or NUM */
int source_line_no = 1;		/* source line number */

/* ====================================================================== */

%}

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
