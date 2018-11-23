/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "parser.y" /* yacc.c:339  */


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


#line 107 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    RETURN = 263,
    INPUT = 264,
    OUTPUT = 265,
    PLUS = 266,
    MINUS = 267,
    MULTIPLY = 268,
    DIVIDE = 269,
    LT = 270,
    LE = 271,
    GT = 272,
    GE = 273,
    EQ = 274,
    NE = 275,
    ASSIGN = 276,
    SEMICOLON = 277,
    COMMA = 278,
    LPAR = 279,
    RPAR = 280,
    LBRACKET = 281,
    RBRACKET = 282,
    LBRACE = 283,
    RBRACE = 284,
    ID = 285,
    NUM = 286,
    UNDEFINED = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "parser.y" /* yacc.c:355  */

  l_type lval;
  t_type tval;

#line 185 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    80,    99,   100,   104,   105,   109,   119,
     134,   138,   145,   152,   160,   172,   159,   185,   186,   190,
     194,   201,   211,   224,   225,   229,   230,   234,   235,   236,
     237,   238,   239,   240,   241,   245,   249,   250,   254,   264,
     275,   279,   280,   284,   285,   286,   287,   288,   289,   293,
     294,   298,   299,   303,   304,   308,   309,   313,   314,   322,
     331,   332,   333,   337,   341,   345,   346,   347,   352,   351,
     373,   374,   378,   379,   383,   384,   388,   389,   393,   396
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "IF", "ELSE", "WHILE",
  "RETURN", "INPUT", "OUTPUT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LT",
  "LE", "GT", "GE", "EQ", "NE", "ASSIGN", "SEMICOLON", "COMMA", "LPAR",
  "RPAR", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "ID", "NUM",
  "UNDEFINED", "$accept", "program", "$@1", "var_declaration_list",
  "fun_declaration_list", "var_declaration", "type_specifier", "var",
  "num", "fun_declaration", "$@2", "$@3", "params", "param_list", "param",
  "local_declarations", "statement_list", "statement", "compound_stmt",
  "expression_stmt", "expression", "simple_expression", "relop",
  "additive_expression", "addop", "term", "mulop", "factor",
  "selection_stmt", "iteration_stmt", "funcall_stmt", "call", "$@4",
  "args", "arg_list", "return_stmt", "input_stmt", "output_stmt", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -110,     8,  -110,  -110,    45,  -110,  -110,  -110,    45,  -110,
     -12,  -110,   -12,  -110,  -110,    17,  -110,  -110,   -11,     4,
    -110,    10,    53,    28,    37,   -12,    43,     3,  -110,  -110,
      44,  -110,    45,    42,    48,  -110,  -110,  -110,    45,  -110,
    -110,   -12,    73,  -110,    17,    55,    64,    30,   -12,    -7,
     -11,   -11,  -110,    -7,  -110,  -110,    -5,  -110,  -110,  -110,
    -110,    49,  -110,   156,    52,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,    -7,    -7,  -110,     9,    50,    29,    69,
    -110,  -110,    67,   108,    -7,    -7,    74,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,    -7,    -7,  -110,  -110,
      -7,    68,    75,    -7,    -7,  -110,  -110,    -7,  -110,  -110,
    -110,     1,  -110,  -110,    78,    -7,    51,    47,    52,  -110,
     135,   135,    79,    80,    87,  -110,    84,    89,  -110,    -7,
     115,  -110,   101,   103,    -7,  -110,    -7,    96,   135,    -7,
    -110,  -110,  -110,  -110,  -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    79,     1,     0,     5,    11,    10,     3,     4,
       0,     7,     0,     6,    12,    14,    14,     8,     0,     0,
      13,     0,     0,     0,    11,     0,     0,    17,    20,     9,
      21,    15,     0,     0,     0,    19,    22,    79,    79,    24,
      23,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    79,    16,    58,    60,    25,    27,
      28,     0,    40,    42,    50,    54,    29,    30,    31,    67,
      32,    33,    34,     0,     0,    74,    58,     0,     0,     0,
      61,    62,     0,     0,     0,     0,     0,    36,    51,    52,
      43,    44,    45,    46,    47,    48,     0,     0,    55,    56,
       0,     0,     0,     0,     0,    75,    76,     0,    78,    57,
      35,    58,    38,    65,     0,    79,    58,    41,    49,    53,
       0,     0,     0,     0,    59,    73,     0,    70,    71,     0,
       0,    64,    59,     0,     0,    69,     0,     0,     0,     0,
      77,    39,    66,    72,    59,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,    88,     2,   -10,    -4,   119,
    -110,  -110,  -110,  -110,    97,  -110,    77,  -109,  -110,  -110,
     -40,  -110,  -110,    38,  -110,    36,  -110,    35,  -110,  -110,
    -110,   -81,  -110,  -110,  -110,  -110,  -110,  -110,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,     8,     9,    25,    76,    57,    11,
      19,    34,    26,    27,    28,    38,    42,    58,    59,    60,
      61,    62,    96,    63,    97,    64,   100,    65,    66,    67,
      68,    69,    86,   126,   127,    70,    71,    72,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,     5,    16,   113,    50,    51,    10,    77,     3,    79,
      12,   130,   131,    82,    21,    30,    84,    53,    14,   -68,
      20,    85,   103,    14,    20,   -68,    32,   104,    22,   145,
     103,    44,    56,   101,   102,   104,    39,    23,    78,    17,
      41,    50,    51,    18,   112,   114,    80,    81,     6,     7,
      29,   106,    75,   142,    53,   107,    24,     7,    88,    89,
      14,    20,   -18,   112,   122,    98,    99,   123,    31,    36,
      33,    87,   105,    56,   111,   125,    37,   129,    45,    73,
      46,    47,    48,    49,    50,    51,   116,   116,    74,   137,
     116,   108,   109,   120,   141,    52,   143,    53,   115,   141,
     121,    54,    55,    14,    20,   124,   132,   133,   134,   135,
      56,    56,   136,    45,   128,    46,    47,    48,    49,    50,
      51,   138,   139,   144,   111,   140,    40,    13,    56,    35,
      52,    83,    53,   118,   117,   119,    54,   110,    14,    20,
      45,     0,    46,    47,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,    53,
       0,     0,     0,    54,     0,    14,    20,    88,    89,     0,
       0,    90,    91,    92,    93,    94,    95
};

static const yytype_int16 yycheck[] =
{
      10,     2,    12,    84,    11,    12,     4,    47,     0,    49,
       8,   120,   121,    53,    18,    25,    21,    24,    30,    24,
      31,    26,    21,    30,    31,    24,    23,    26,    24,   138,
      21,    41,    42,    73,    74,    26,    37,    27,    48,    22,
      38,    11,    12,    26,    84,    85,    50,    51,     3,     4,
      22,    22,    22,   134,    24,    26,     3,     4,    11,    12,
      30,    31,    25,   103,   104,    13,    14,   107,    25,    27,
      26,    22,    22,    83,    84,   115,    28,    26,     5,    24,
       7,     8,     9,    10,    11,    12,    96,    97,    24,   129,
     100,    22,    25,    25,   134,    22,   136,    24,    24,   139,
      25,    28,    29,    30,    31,    27,    27,    27,    21,    25,
     120,   121,    23,     5,   115,     7,     8,     9,    10,    11,
      12,     6,    21,    27,   134,    22,    38,     8,   138,    32,
      22,    54,    24,    97,    96,   100,    28,    29,    30,    31,
       5,    -1,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,
      -1,    -1,    -1,    28,    -1,    30,    31,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,    36,    71,     3,     4,    37,    38,
      39,    42,    39,    42,    30,    40,    40,    22,    26,    43,
      31,    41,    24,    27,     3,    39,    45,    46,    47,    22,
      40,    25,    23,    26,    44,    47,    27,    28,    48,    71,
      38,    39,    49,    71,    40,     5,     7,     8,     9,    10,
      11,    12,    22,    24,    28,    29,    40,    41,    50,    51,
      52,    53,    54,    56,    58,    60,    61,    62,    63,    64,
      68,    69,    70,    24,    24,    22,    40,    53,    40,    53,
      41,    41,    53,    49,    21,    26,    65,    22,    11,    12,
      15,    16,    17,    18,    19,    20,    55,    57,    13,    14,
      59,    53,    53,    21,    26,    22,    22,    26,    22,    25,
      29,    40,    53,    64,    53,    24,    40,    56,    58,    60,
      25,    25,    53,    53,    27,    53,    66,    67,    71,    26,
      50,    50,    27,    27,    21,    25,    23,    53,     6,    21,
      22,    53,    64,    53,    27,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    35,    34,    36,    36,    37,    37,    38,    38,
      39,    39,    40,    41,    43,    44,    42,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    52,    52,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    62,    63,    63,    63,    65,    64,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     2,     1,     3,     6,
       1,     1,     1,     1,     0,     0,    11,     1,     1,     3,
       1,     2,     4,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     3,     6,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     4,
       1,     2,     2,     7,     5,     3,     6,     1,     0,     5,
       1,     1,     3,     1,     2,     3,     3,     6,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 80 "parser.y" /* yacc.c:1646  */
    {
		position=GLOBAL;
		current_table=global_table=create_table("_global");
		current_offset=&global_offset;
		*current_offset=0;

		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");
		fprintf(stdout, "%-10s %-10s %-10s %-10s %10s %10s\n", "table", "symbol", "kind", "type", "size", "offset");
		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");
	}
#line 1395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "parser.y" /* yacc.c:1646  */
    {
		print_table(global_table);
		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");

	}
#line 1405 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2].tval).type == 3)
			error("error 00: %s %s \"%s\"", "wrong void", "variable", (yyvsp[-1].lval).lex);
		if (find_symbol(current_table, (yyvsp[-1].lval).lex) != NULL)
			error("error 10: %s %s \"%s\"", "redefined", "variable", (yyvsp[-1].lval).lex);

		add_symbol(current_table, (yyvsp[-1].lval).lex, position, (yyvsp[-2].tval).type, 1, *current_offset);
		*current_offset = *current_offset + 1;
	}
#line 1419 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "parser.y" /* yacc.c:1646  */
    {
		int n = atoi((yyvsp[-2].lval).lex);

		if ((yyvsp[-5].tval).type == 3)
			error("error 01: %s %s \"%s\"", "wrong void", "array", (yyvsp[-4].lval).lex);
		if (find_symbol(current_table, (yyvsp[-4].lval).lex) != NULL)
			error("error 11: %s %s \"%s\"", "redefined", "array", (yyvsp[-4].lval).lex);

		add_symbol(current_table, (yyvsp[-4].lval).lex, position, INT_ARRAY_TYPE, n, *current_offset + n - 1);
		*current_offset = *current_offset + n;
	}
#line 1435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "parser.y" /* yacc.c:1646  */
    {
		(yyval.tval).type=INT_TYPE;
	}
#line 1443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "parser.y" /* yacc.c:1646  */
    {
		(yyval.tval).type=VOID_TYPE;
	}
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 146 "parser.y" /* yacc.c:1646  */
    {
		(yyval.lval).lex = lex;
	}
#line 1459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "parser.y" /* yacc.c:1646  */
    {
		(yyval.lval).lex = lex;
	}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 160 "parser.y" /* yacc.c:1646  */
    {
		position = ARGUMENT;
		current_table = local_table = create_table((yyvsp[0].lval).lex);
		
		if (find_symbol(global_table, (yyvsp[0].lval).lex) != NULL)
			error("error 12: %s %s \"%s\"", "redefined", "function", (yyvsp[0].lval).lex);

		current_offset = &local_offset;
		*current_offset = 0;
		farg_count = 0;
	}
#line 1483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 172 "parser.y" /* yacc.c:1646  */
    {
		add_symbol(global_table, (yyvsp[-4].lval).lex, FUNCTION, (yyvsp[-5].tval).type, farg_count, ip);
		position=LOCAL;
	}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "parser.y" /* yacc.c:1646  */
    {
		print_table(current_table);
		fprintf(stdout, "---------- ---------- ---------- ---------- ---------- ----------\n");

	}
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "parser.y" /* yacc.c:1646  */
    {
		farg_count++;
	}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "parser.y" /* yacc.c:1646  */
    {
		farg_count = 1;
	}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].tval).type == 3)
			error("error 02: %s %s \"%s\"", "wrong void", "argument", (yyvsp[0].lval).lex);
		if (find_symbol(current_table, (yyvsp[0].lval).lex) != NULL)
			error("error 13: %s %s \"%s\"", "redefined", "argument", (yyvsp[0].lval).lex);

		add_symbol(current_table, (yyvsp[0].lval).lex, position, (yyvsp[-1].tval).type, 1, *current_offset);
		*current_offset = *current_offset + 1;
	}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 212 "parser.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-3].tval).type == 3)
			error("error 03: %s %s \"%s\"", "wrong void", "array argument", (yyvsp[-2].lval).lex);
		if (find_symbol(current_table, (yyvsp[-2].lval).lex) != NULL)
			error("error 14: %s %s \"%s\"", "redefined", "array argument", (yyvsp[-2].lval).lex);

		add_symbol(current_table, (yyvsp[-2].lval).lex, position, INT_P_TYPE, 1, *current_offset);
		*current_offset = *current_offset + 1;
	}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 255 "parser.y" /* yacc.c:1646  */
    {
		char *var = (yyvsp[-2].lval).lex;
		struct symbol *symbolp;
		symbolp = lookup_symbol(var);
		if (symbolp == NULL)
			error("error 20: %s %s \"%s\"", "undefined", "variable", (yyvsp[-2].lval).lex);
		if (symbolp->kind == 3 || symbolp->kind == 4)
			error("error 30: %s %s \"%s\"", "type error", "variable", (yyvsp[-2].lval).lex);
	}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 265 "parser.y" /* yacc.c:1646  */
    {
		char *var = (yyvsp[-5].lval).lex;
		struct symbol *symbolp;
		symbolp = lookup_symbol(var);
		
		if (symbolp == NULL)
			error("error 21: %s %s \"%s\"", "undefined", "array", (yyvsp[-5].lval).lex);
		if (symbolp->kind == 3 || symbolp->kind == 4)
			error("error 31: %s %s \"%s\"", "type error", "array", (yyvsp[-5].lval).lex);
	}
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 315 "parser.y" /* yacc.c:1646  */
    {
		char *var = (yyvsp[0].lval).lex;
		struct symbol *symbolp;
		symbolp = lookup_symbol(var);
		if (symbolp == NULL)
			error("error 20: %s %s \"%s\"", "undefined", "variable", (yyvsp[0].lval).lex);
	}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 323 "parser.y" /* yacc.c:1646  */
    {
		char *var = (yyvsp[-3].lval).lex;
		struct symbol * symbolp;
		symbolp = lookup_symbol(var);
		if (symbolp == NULL)
			error("error 21: %s %s \"%s\"", "undefined", "array", (yyvsp[-3].lval).lex);

	}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 352 "parser.y" /* yacc.c:1646  */
    {
		struct symbol *symbolp;
		symbolp = lookup_symbol((yyvsp[0].lval).lex);
		
		if (symbolp == NULL)
			error("error 22: %s %s \"%s\"", "undefined", "function call", (yyvsp[0].lval).lex);
		if (symbolp->kind == 3 || symbolp->kind == 4)
			error("error 40: %s %s \"%s\"", "type error", "function", (yyvsp[0].lval).lex);

		aarg_count = 0;
	}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 364 "parser.y" /* yacc.c:1646  */
    {
		struct symbol *symbolp;
		symbolp = lookup_symbol((yyvsp[-4].lval).lex);
		if (symbolp->size != aarg_count)
			error("error 32: %s %s \"%s\"", "wrong no argument", "function", (yyvsp[-4].lval).lex);
	}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1631 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 400 "parser.y" /* yacc.c:1906  */


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
