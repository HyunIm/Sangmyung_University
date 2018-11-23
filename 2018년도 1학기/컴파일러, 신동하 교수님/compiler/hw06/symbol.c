/*
   * @File : symbol.c
   * @Author : 임현 (201511054@sangmyung.kr)
   * @Since : 2018 - 05 - 23
*/

/* ====================================================================== */

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE	11	/* hash array size */

				/* symbol's kind */
#define GLOBAL		0	/* global variable */
#define LOCAL		1	/* local variable */
#define ARGUMENT	2	/* formal argument */
#define FUNCTION	3	/* function name */
#define FUNCTIONI	4	/* incomplete function */
				/* symbol's type */
#define INT_TYPE	0	/* int type */
#define INT_ARRAY_TYPE	1	/* int array type */
#define INT_P_TYPE	2	/* int [] type */
#define VOID_TYPE	3	/* void type */

/* ====================================================================== */

char *symbol_kind[5] = {"global", "local", "argument", "function", "functioni"};
char *symbol_type[4] = {"int", "int array", "int *", "void"};

struct symbol {
  char *name;			/* symbol's name */
  unsigned char kind;		/* symbol's kind */
  unsigned char type;		/* symbol's type */
  unsigned int size;		/* byte size or no of args */
  unsigned int offset;		/* relative memory offset */
  unsigned int ip[128];		/* ip that calls this function */
  unsigned int ipc;		/* ip count in ip[] */
  struct symbol *next;		/* next symbol pointer */
};

struct table {
  char *name;			/* function name */
  struct symbol *hash[HASH_SIZE];	/* hash array */
};

struct table *global_table;	/* global symbol table */
struct table *local_table;	/* local symbol table */
struct table *current_table;	/* current symbol table */

/* ====================================================================== */

int hash_function(char *name)
{
	int hashval;

	for (hashval = 0; *name != '\0'; )
		hashval += *name++;

	return hashval % HASH_SIZE;
}

struct table *create_table(char *name)
{
	struct table *tablep;
	int i;

	if ((tablep=(struct table *) malloc(sizeof(*tablep)))==NULL)
		error("can't malloc in create_table");

	tablep->name = name;
	for (i = 0; i < HASH_SIZE; i++)
		tablep->hash[i] = NULL;

	return tablep;
}

struct symbol *add_symbol(struct table *tablep, char *name, unsigned char kind, unsigned char type, unsigned int size, unsigned int offset)
{
	int hashval;
	struct symbol *symbolp;

	if ((symbolp = (struct symbol *) malloc(sizeof(*symbolp))) == NULL)
		error("can't malloc in add_symbol()");
	symbolp->name = name;
	symbolp->kind = kind;
	symbolp->type = type;
	symbolp->size = size;
	symbolp->offset = offset;
	symbolp->ipc = 0;

	hashval = hash_function(name);
	symbolp->next = tablep->hash[hashval];
	tablep->hash[hashval] = symbolp;

	return symbolp;
}

struct symbol *find_symbol(struct table *tablep, char *name)
{
	struct symbol *symbolp;

	for (symbolp = tablep->hash[hash_function(name)]; symbolp != NULL; symbolp = symbolp->next)
		if (strcmp(name, symbolp->name) == 0)
			return symbolp;
	return NULL;
}

struct symbol *lookup_symbol(char *name)
{
	struct symbol *symbolp;

	if ((symbolp = find_symbol(local_table, name)) == NULL)
		if ((symbolp = find_symbol(global_table, name)) == NULL)
			return NULL;
	return symbolp;
}

void print_table(struct table *tablep)
{
	struct symbol *symbolp;
	int i;

	for (i = 0; i < HASH_SIZE; i++)
		for (symbolp = tablep->hash[i]; symbolp != NULL; symbolp = symbolp->next)
			fprintf(stdout, "%-10s %-10s %-10s %-10s %10i %10i\n", tablep->name, symbolp->name, symbol_kind[symbolp->kind], symbol_type[symbolp->type], symbolp->size, symbolp->offset);
}

/* ====================================================================== */
