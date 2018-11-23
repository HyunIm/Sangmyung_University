/*
   * @File : parser.y
   * @Author : 임현 (201511054@sangmyung.kr)
   * @Since : 2018 - 05 - 23
*/

/* ====================================================================== */

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "symbol.c"

/* ====================================================================== */

extern FILE *yyin;		/* FILE * for input file */
extern char *yytext;		/* current lexeme is stored here */

extern char *lex;		/* lexeme of ID and NUM from scanner */
extern int source_line_no;	/* souce line number */

/* ====================================================================== */

int position;			/* current symbol's kind */

int global_offset;		/* global variable offset */
int local_offset;		/* local variable offset */
int *current_offset;		/* current offset pointer */

int farg_count;			/* no of formal args in function declaration */
int aarg_count;			/* no of actual args in function call */

unsigned int ip = 0;		/* instruction pointer */

/* ====================================================================== */

typedef struct l_type_struct {	/* lex attribute for var and num */
  char *lex;
} l_type;

typedef struct t_type_struct {	/* type attribute for type_specifier */
  unsigned char type;
} t_type;

%}

/* ====================================================================== */

%start program

%union {
  l_type lval;
  t_type tval;
}

%token VOID INT
%token IF ELSE WHILE RETURN
%token INPUT OUTPUT
%token PLUS MINUS MULTIPLY DIVIDE
%token LT LE GT GE EQ NE
%token ASSIGN
%token SEMICOLON COMMA
%token LPAR RPAR LBRACKET RBRACKET LBRACE RBRACE
%token ID NUM
%token UNDEFINED

%type <lval> var num
%type <tval> type_specifier

%%

/* ====================================================================== */

/* Syntax Rule (문맥 자유 언어의 규칙 {C 코드}로 구성) */

program :
	{
		position=GLOBAL;
		current_table=global_table=create_table("_global");
		current_offset=&global_offset;
		*current_offset=0;

		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");
		fprintf(stdout, "%-10s %-10s %-10s %-10s %10s %10s\n", "table", "symbol", "kind", "type", "size", "offset");
		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");
	}
	var_declaration_list fun_declaration_list
	{
		print_table(global_table);
		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");

	}
;

var_declaration_list
	: var_declaration_list var_declaration
 	| empty
;

fun_declaration_list
	: fun_declaration_list fun_declaration 
	| fun_declaration
;

var_declaration 
	: type_specifier var SEMICOLON
	{
		if ($<tval>1.type == 3)
			error("error 00: %s %s \"%s\"", "wrong void", "variable", $<lval>2.lex);
		if (find_symbol(current_table, $<lval>2.lex) != NULL)
			error("error 10: %s %s \"%s\"", "redefined", "variable", $<lval>2.lex);

		add_symbol(current_table, $<lval>2.lex, position, $<tval>1.type, 1, *current_offset);
		*current_offset = *current_offset + 1;
	}
	| type_specifier var LBRACKET num RBRACKET SEMICOLON
	{
		int n = atoi($<lval>4.lex);

		if ($<tval>1.type == 3)
			error("error 01: %s %s \"%s\"", "wrong void", "array", $<lval>2.lex);
		if (find_symbol(current_table, $<lval>2.lex) != NULL)
			error("error 11: %s %s \"%s\"", "redefined", "array", $<lval>2.lex);

		add_symbol(current_table, $<lval>2.lex, position, INT_ARRAY_TYPE, n, *current_offset + n - 1);
		*current_offset = *current_offset + n;
	}
;

type_specifier
	: INT
	{
		$<tval>$.type=INT_TYPE;
	}
	| VOID
	{
		$<tval>$.type=VOID_TYPE;
	}
;

var
	: ID
	{
		$<lval>$.lex = lex;
	}
;

num
	: NUM
	{
		$<lval>$.lex = lex;
	}
;

fun_declaration
	: type_specifier var 
	{
		position = ARGUMENT;
		current_table = local_table = create_table($<lval>2.lex);
		
		if (find_symbol(global_table, $<lval>2.lex) != NULL)
			error("error 12: %s %s \"%s\"", "redefined", "function", $<lval>2.lex);

		current_offset = &local_offset;
		*current_offset = 0;
		farg_count = 0;
	}
	LPAR params RPAR
	{
		add_symbol(global_table, $<lval>2.lex, FUNCTION, $<tval>1.type, farg_count, ip);
		position=LOCAL;
	}
	LBRACE local_declarations statement_list RBRACE
	{
		print_table(current_table);
		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");

	}
;

params
	: param_list
	| VOID
;

param_list
	: param_list COMMA param
	{
		farg_count++;
	}
	| param
	{
		farg_count = 1;
	}
;

param
	: type_specifier var
	{
		if ($<tval>1.type == 3)
			error("error 02: %s %s \"%s\"", "wrong void", "argument", $<lval>2.lex);
		if (find_symbol(current_table, $<lval>2.lex) != NULL)
			error("error 13: %s %s \"%s\"", "redefined", "argument", $<lval>2.lex);

		add_symbol(current_table, $<lval>2.lex, position, $<tval>1.type, 1, *current_offset);
		*current_offset = *current_offset + 1;
	}
	| type_specifier var LBRACKET RBRACKET
	{
		if ($<tval>1.type == 3)
			error("error 03: %s %s \"%s\"", "wrong void", "array argument", $<lval>2.lex);
		if (find_symbol(current_table, $<lval>2.lex) != NULL)
			error("error 14: %s %s \"%s\"", "redefined", "array argument", $<lval>2.lex);

		add_symbol(current_table, $<lval>2.lex, position, INT_P_TYPE, 1, *current_offset);
		*current_offset = *current_offset + 1;
	}
;

local_declarations
	: local_declarations var_declaration 
	| empty
;

statement_list
	: statement_list statement 
	| empty
;

statement
	: compound_stmt 
	| expression_stmt 
	| selection_stmt
	| iteration_stmt 
	| funcall_stmt 
	| return_stmt 
	| input_stmt
	| output_stmt
;

compound_stmt
	: LBRACE statement_list RBRACE
;

expression_stmt
	: expression SEMICOLON 
	| SEMICOLON
;

expression
	: var ASSIGN expression
	{
		char *var = $<lval>1.lex;
		struct symbol *symbolp;
		symbolp = lookup_symbol(var);
		if (symbolp == NULL)
			error("error 20: %s %s \"%s\"", "undefined", "variable", $<lval>1.lex);
		if (symbolp->kind == 3 || symbolp->kind == 4)
			error("error 30: %s %s \"%s\"", "type error", "variable", $<lval>1.lex);
	}
	| var LBRACKET expression RBRACKET ASSIGN expression
	{
		char *var = $<lval>1.lex;
		struct symbol *symbolp;
		symbolp = lookup_symbol(var);
		
		if (symbolp == NULL)
			error("error 21: %s %s \"%s\"", "undefined", "array", $<lval>1.lex);
		if (symbolp->kind == 3 || symbolp->kind == 4)
			error("error 31: %s %s \"%s\"", "type error", "array", $<lval>1.lex);
	}
	| simple_expression
;

simple_expression
	: additive_expression relop additive_expression
	| additive_expression
;

relop
	: LT 
	| LE 
	| GT 
	| GE 
	| EQ 
	| NE 
;

additive_expression
	: additive_expression addop term 
	| term
;

addop
	: PLUS 
	| MINUS
;

term
	: term mulop factor 
	| factor
;

mulop
	: MULTIPLY 
	| DIVIDE
;

factor
	: LPAR expression RPAR
	| var 
	{
		char *var = $<lval>1.lex;
		struct symbol *symbolp;
		symbolp = lookup_symbol(var);
		if (symbolp == NULL)
			error("error 20: %s %s \"%s\"", "undefined", "variable", $<lval>1.lex);
	}
	| var LBRACKET expression RBRACKET
	{
		char *var = $<lval>1.lex;
		struct symbol * symbolp;
		symbolp = lookup_symbol(var);
		if (symbolp == NULL)
			error("error 21: %s %s \"%s\"", "undefined", "array", $<lval>1.lex);

	}
	| num 
	| PLUS num 
	| MINUS num
;

selection_stmt
	: IF LPAR expression RPAR statement ELSE statement
;

iteration_stmt
	: WHILE LPAR expression RPAR statement
;

funcall_stmt
	: var ASSIGN call
	| var LBRACKET expression RBRACKET ASSIGN call
	| call
;

call
	: var
	{
		struct symbol *symbolp;
		symbolp = lookup_symbol($<lval>1.lex);
		
		if (symbolp == NULL)
			error("error 22: %s %s \"%s\"", "undefined", "function call", $<lval>1.lex);
		if (symbolp->kind == 3 || symbolp->kind == 4)
			error("error 40: %s %s \"%s\"", "type error", "function", $<lval>1.lex);

		aarg_count = 0;
	}
	LPAR args RPAR
	{
		struct symbol *symbolp;
		symbolp = lookup_symbol($<lval>1.lex);
		if (symbolp->size != aarg_count)
			error("error 32: %s %s \"%s\"", "wrong no argument", "function", $<lval>1.lex);
	}
;

args
	: arg_list 
	| empty
;

arg_list
	: arg_list COMMA expression 
	| expression
;

return_stmt
	: RETURN SEMICOLON 
	| RETURN expression SEMICOLON
;

input_stmt
	: INPUT var SEMICOLON 
	| INPUT var LBRACKET expression RBRACKET SEMICOLON
;

output_stmt
	: OUTPUT expression SEMICOLON
;

empty
	: 
;

%%

/* ====================================================================== */

int yyerror(char *message)
{
  print_table(current_table);
  fprintf(stdout,
	"---------- ---------- ---------- ---------- ---------- ----------\n");
  print_table(global_table);
  fprintf(stdout,
	"---------- ---------- ---------- ---------- ---------- ----------\n");
  fprintf(stderr, "line %d: %s at \"%s\"\n", source_line_no, message,
	  yytext);
}

/* ====================================================================== */

int error(char *fmt, char *s1, char *s2, char *s3, char *s4)
{
  print_table(current_table);
  fprintf(stdout,
	"---------- ---------- ---------- ---------- ---------- ----------\n");
  print_table(global_table);
  fprintf(stdout,
	"---------- ---------- ---------- ---------- ---------- ----------\n");
  fprintf(stdout, "line %d: ", source_line_no);
  fprintf(stdout, fmt, s1, s2, s3, s4);
  fprintf(stdout, "\n");
  fflush(stdout);
  exit(-1);
}

/* ====================================================================== */

int main(int argc, char *argv[])
{
  if(argc != 2) {
    fprintf(stderr, "usage: symbol file\n");
    exit(1);
  }
  yyin = fopen(argv[1], "r");
  if(yyin == NULL) {
    fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
    exit(1);
  }
  yyparse();

  return 0;
}

/* ====================================================================== */
