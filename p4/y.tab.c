/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_AND = 258,
     TOK_OR = 259,
     TOK_LESS = 260,
     TOK_GREAT = 261,
     TOK_LEQ = 262,
     TOK_GREQ = 263,
     TOK_NEQ = 264,
     TOK_EQ = 265,
     TOK_PLUS = 266,
     TOK_MINUS = 267,
     TOK_MULT = 268,
     TOK_DIV = 269,
     TOK_NOT = 270,
     KW_BOOLEAN = 271,
     KW_CLASS = 272,
     KW_FALSE = 273,
     KW_INT = 274,
     MAIN = 275,
     KW_PUBLIC = 276,
     KW_TRUE = 277,
     KW_VOID = 278,
     KW_IF = 279,
     KW_ELSE = 280,
     KW_RETURN = 281,
     KW_WHILE = 282,
     KW_LENGTH = 283,
     KW_STATIC = 284,
     KW_STRING = 285,
     KW_NEW = 286,
     KW_PRIVATE = 287,
     SYSTEM_OUT_PRINT = 288,
     SYSTEM_OUT_PRINTLN = 289,
     INTEGER_PARSE_INT = 290,
     INTEGER_LITERAL = 291,
     STRING_LITERAL = 292,
     ID = 293
   };
#endif
/* Tokens.  */
#define TOK_AND 258
#define TOK_OR 259
#define TOK_LESS 260
#define TOK_GREAT 261
#define TOK_LEQ 262
#define TOK_GREQ 263
#define TOK_NEQ 264
#define TOK_EQ 265
#define TOK_PLUS 266
#define TOK_MINUS 267
#define TOK_MULT 268
#define TOK_DIV 269
#define TOK_NOT 270
#define KW_BOOLEAN 271
#define KW_CLASS 272
#define KW_FALSE 273
#define KW_INT 274
#define MAIN 275
#define KW_PUBLIC 276
#define KW_TRUE 277
#define KW_VOID 278
#define KW_IF 279
#define KW_ELSE 280
#define KW_RETURN 281
#define KW_WHILE 282
#define KW_LENGTH 283
#define KW_STATIC 284
#define KW_STRING 285
#define KW_NEW 286
#define KW_PRIVATE 287
#define SYSTEM_OUT_PRINT 288
#define SYSTEM_OUT_PRINTLN 289
#define INTEGER_PARSE_INT 290
#define INTEGER_LITERAL 291
#define STRING_LITERAL 292
#define ID 293




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include "typecheck.h"
#include "codegen.h"
#include "node.h"

void yyerror(char *);
extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;

struct ASTNode* root;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "parser.y"
{
    struct ASTNode* node;
    int integer;
    char * string;
}
/* Line 193 of yacc.c.  */
#line 196 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 209 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    43,     2,     2,    46,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    25,    31,    35,    38,    39,    44,
      45,    47,    51,    59,    65,    71,    77,    82,    86,    89,
      92,    93,    95,    98,   102,   107,   109,   113,   115,   117,
     119,   124,   129,   140,   143,   144,   147,   148,   151,   155,
     156,   160,   164,   168,   172,   176,   180,   184,   188,   192,
     196,   198,   202,   206,   208,   210,   212,   214,   216,   219,
     222,   225,   229,   231,   235,   237,   241,   244,   245,   248,
     249,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    17,    38,    39,    54,    64,
      21,    29,    23,    20,    40,    30,    41,    42,    38,    43,
      39,    57,    44,    44,    -1,    60,    38,    71,    55,    45,
      -1,    32,    29,    52,    -1,    54,    53,    -1,    -1,    46,
      38,    71,    55,    -1,    -1,    52,    -1,    39,    57,    44,
      -1,    24,    40,    68,    43,    56,    25,    56,    -1,    27,
      40,    68,    43,    56,    -1,    34,    40,    68,    43,    45,
      -1,    33,    40,    68,    43,    45,    -1,    58,    47,    68,
      45,    -1,    26,    68,    45,    -1,    62,    45,    -1,    57,
      56,    -1,    -1,    38,    -1,    38,    59,    -1,    41,    68,
      42,    -1,    59,    41,    68,    42,    -1,    61,    -1,    60,
      41,    42,    -1,    19,    -1,    16,    -1,    30,    -1,    38,
      40,    72,    43,    -1,    35,    40,    68,    43,    -1,    21,
      29,    60,    38,    40,    65,    43,    39,    57,    44,    -1,
      64,    63,    -1,    -1,    66,    67,    -1,    -1,    60,    38,
      -1,    46,    66,    67,    -1,    -1,    68,    11,    69,    -1,
      68,    12,    69,    -1,    68,     3,    68,    -1,    68,     4,
      68,    -1,    68,     5,    68,    -1,    68,     6,    68,    -1,
      68,     7,    68,    -1,    68,     8,    68,    -1,    68,    10,
      68,    -1,    68,     9,    68,    -1,    69,    -1,    69,    13,
      70,    -1,    69,    14,    70,    -1,    70,    -1,    36,    -1,
      37,    -1,    22,    -1,    18,    -1,    15,    70,    -1,    11,
      70,    -1,    12,    70,    -1,    40,    68,    43,    -1,    58,
      -1,    58,    48,    28,    -1,    62,    -1,    31,    61,    59,
      -1,    47,    68,    -1,    -1,    68,    73,    -1,    -1,    46,
      68,    73,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    80,   100,   109,   115,   120,   125,   131,
     140,   144,   148,   154,   159,   163,   167,   172,   176,   182,
     187,   192,   196,   203,   207,   218,   223,   231,   235,   239,
     249,   254,   260,   271,   276,   281,   286,   291,   298,   303,
     312,   318,   324,   330,   336,   342,   348,   354,   360,   366,
     372,   379,   385,   391,   398,   402,   406,   410,   414,   419,
     424,   429,   433,   437,   441,   445,   452,   456,   461,   466,
     471,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_AND", "TOK_OR", "TOK_LESS",
  "TOK_GREAT", "TOK_LEQ", "TOK_GREQ", "TOK_NEQ", "TOK_EQ", "TOK_PLUS",
  "TOK_MINUS", "TOK_MULT", "TOK_DIV", "TOK_NOT", "KW_BOOLEAN", "KW_CLASS",
  "KW_FALSE", "KW_INT", "MAIN", "KW_PUBLIC", "KW_TRUE", "KW_VOID", "KW_IF",
  "KW_ELSE", "KW_RETURN", "KW_WHILE", "KW_LENGTH", "KW_STATIC",
  "KW_STRING", "KW_NEW", "KW_PRIVATE", "SYSTEM_OUT_PRINT",
  "SYSTEM_OUT_PRINTLN", "INTEGER_PARSE_INT", "INTEGER_LITERAL",
  "STRING_LITERAL", "ID", "'{'", "'('", "'['", "']'", "')'", "'}'", "';'",
  "','", "'='", "'.'", "$accept", "Program", "MainClass", "VarDecl",
  "StaticVarDecl", "StaticVarDeclList", "VarDeclExpList", "Statement",
  "StatementList", "LeftValue", "Index", "Type", "PrimeType", "MethodCall",
  "StaticMethodDecl", "StaticMethodDeclList", "FormalList", "Arg",
  "ArgList", "Exp", "Term", "Factor", "ExpDecl", "ExpList", "ExpTail", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   123,
      40,    91,    93,    41,   125,    59,    44,    61,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,    19,     5,     3,     2,     0,     4,     0,
       1,     3,     7,     5,     5,     5,     4,     3,     2,     2,
       0,     1,     2,     3,     4,     1,     3,     1,     1,     1,
       4,     4,    10,     2,     0,     2,     0,     2,     3,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     1,     3,     1,     3,     2,     0,     2,     0,
       3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     7,    34,     0,     6,
       0,     0,     0,    33,    28,    27,    29,     5,     0,    25,
       0,    67,     0,     0,     0,     0,     9,    26,     0,     0,
       0,     0,     0,    57,    56,     0,     0,    54,    55,    21,
       0,    62,    64,    66,    50,    53,     0,     0,     0,    36,
      59,    60,    58,     0,     0,    69,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     4,     0,     0,     0,    39,    65,     0,
      71,     0,     0,     0,    61,    63,    42,    43,    44,    45,
      46,    47,    49,    48,    40,    41,    51,    52,     9,     0,
      37,     0,     0,    35,    31,     0,    68,    30,    23,     0,
       8,     0,    20,    39,    71,    24,     0,     0,    38,    70,
       0,     0,     0,     0,     0,     0,    20,    32,    10,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    17,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,    16,     3,     0,    13,    15,    14,
       0,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   128,     9,     7,    47,   129,   117,    41,
      57,    18,    19,    42,    13,    10,    76,    77,   103,    43,
      44,    45,    26,    81,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int16 yypact[] =
{
       2,    -7,    42,  -115,     1,  -115,  -115,    12,    20,  -115,
      43,    60,    58,  -115,  -115,  -115,  -115,  -115,    -5,  -115,
      61,    45,    52,   129,    40,    17,   104,  -115,   112,   114,
      17,    17,    17,  -115,  -115,    60,   115,  -115,  -115,    18,
      17,   109,  -115,   331,    72,  -115,   120,   117,   130,    60,
    -115,  -115,  -115,   124,    17,    17,    17,   125,   116,   140,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    45,  -115,   132,    62,   131,   193,   125,   126,
      -1,   134,   207,    17,  -115,  -115,   216,   226,    93,    93,
      93,    93,    93,    93,    72,    72,  -115,  -115,   104,   199,
    -115,   139,    60,  -115,  -115,    17,  -115,  -115,  -115,   247,
    -115,   204,  -115,   193,    -1,  -115,   200,   244,  -115,  -115,
     205,   206,    17,   208,   221,   222,  -115,  -115,  -115,  -115,
     198,   202,  -115,    17,    63,    17,    17,    17,   268,    17,
    -115,   289,   136,  -115,   177,   187,   197,  -115,   106,   220,
     137,   137,   224,   227,  -115,  -115,   240,  -115,  -115,  -115,
     137,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,   255,  -115,  -115,   169,   -62,  -114,  -104,
     223,   -19,   238,  -100,  -115,  -115,  -115,   173,   167,   -40,
      38,    31,   209,  -115,   171
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      58,    24,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   138,   130,    79,    80,    82,   131,   141,     1,
      86,    87,    88,    89,    90,    91,    92,    93,    30,    31,
      75,     4,    32,    21,   130,    33,    22,   130,   131,    34,
       6,   131,     5,   109,     8,   105,   130,   130,    35,    11,
     131,   131,    36,    37,    38,    39,   130,    40,    55,    56,
     131,    50,    51,    52,    12,   114,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    14,    14,    29,    15,
      15,    22,   134,    75,    23,    70,    71,    20,   156,   157,
      16,    16,    25,   142,    27,   144,   145,   146,   161,   148,
     100,    96,    97,    22,    68,    69,    94,    95,   143,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    28,
      46,   154,    48,    14,    49,    54,    15,    59,    72,    84,
      74,   121,    73,   122,   123,    56,    83,    16,    85,   104,
     124,   125,    36,    99,   101,    39,   126,   107,   112,   150,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     151,    62,    63,    64,    65,    66,    67,    68,    69,    60,
     152,    62,    63,    64,    65,    66,    67,    68,    69,   102,
     153,   111,   116,   120,   132,   139,   133,   140,   135,   108,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      14,   136,   137,    15,   155,   160,    17,   110,   121,   158,
     122,   123,   159,    53,    16,   113,    78,   124,   125,    36,
     118,    98,    39,   126,    14,   119,     0,    15,   127,   115,
       0,     0,   121,     0,   122,   123,     0,     0,    16,     0,
       0,   124,   125,    36,     0,    14,    39,   126,    15,     0,
       0,     0,   147,   121,     0,   122,   123,     0,     0,    16,
       0,     0,   124,   125,    36,     0,     0,    39,   126,     0,
       0,     0,     0,   149,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
      40,    20,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   126,   117,    54,    55,    56,   117,   132,    17,
      60,    61,    62,    63,    64,    65,    66,    67,    11,    12,
      49,    38,    15,    38,   138,    18,    41,   141,   138,    22,
      39,   141,     0,    83,    32,    46,   150,   151,    31,    29,
     150,   151,    35,    36,    37,    38,   160,    40,    40,    41,
     160,    30,    31,    32,    21,   105,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    16,    16,    38,    19,
      19,    41,   122,   102,    23,    13,    14,    29,   150,   151,
      30,    30,    47,   133,    42,   135,   136,   137,   160,   139,
      38,    70,    71,    41,    11,    12,    68,    69,    45,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    20,
      46,    45,    40,    16,    40,    40,    19,    48,    38,    43,
      30,    24,    45,    26,    27,    41,    41,    30,    28,    43,
      33,    34,    35,    41,    43,    38,    39,    43,    39,    43,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      43,     5,     6,     7,     8,     9,    10,    11,    12,     3,
      43,     5,     6,     7,     8,     9,    10,    11,    12,    46,
      43,    42,    38,    43,    39,    47,    40,    45,    40,    42,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      16,    40,    40,    19,    44,    25,    11,    98,    24,    45,
      26,    27,    45,    35,    30,   102,    53,    33,    34,    35,
     113,    72,    38,    39,    16,   114,    -1,    19,    44,    42,
      -1,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    16,    38,    39,    19,    -1,
      -1,    -1,    44,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    50,    51,    38,     0,    39,    54,    32,    53,
      64,    29,    21,    63,    16,    19,    30,    52,    60,    61,
      29,    38,    41,    23,    60,    47,    71,    42,    20,    38,
      11,    12,    15,    18,    22,    31,    35,    36,    37,    38,
      40,    58,    62,    68,    69,    70,    46,    55,    40,    40,
      70,    70,    70,    61,    40,    40,    41,    59,    68,    48,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    38,    45,    30,    60,    65,    66,    59,    68,
      68,    72,    68,    41,    43,    28,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    71,    41,
      38,    43,    46,    67,    43,    46,    73,    43,    42,    68,
      55,    42,    39,    66,    68,    42,    38,    57,    67,    73,
      43,    24,    26,    27,    33,    34,    39,    44,    52,    56,
      58,    62,    39,    40,    68,    40,    40,    40,    57,    47,
      45,    57,    68,    45,    68,    68,    68,    44,    68,    44,
      43,    43,    43,    43,    45,    44,    56,    56,    45,    45,
      25,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 73 "parser.y"
    {   
        (yyval.node) = new_node(NODETYPE_PROGRAM, yylineno);
        root = (yyval.node);
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
    }
    break;

  case 3:
#line 87 "parser.y"
    {   
        (yyval.node) = new_node(NODETYPE_MAINCLASS, yylineno);
        set_string_value((yyval.node), (yyvsp[(14) - (19)].string));
        add_child((yyval.node), (yyvsp[(4) - (19)].node));
        add_child((yyval.node), (yyvsp[(5) - (19)].node));
        add_child((yyval.node), (yyvsp[(17) - (19)].node));
    }
    break;

  case 4:
#line 100 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_VARDECL, yylineno);
        set_string_value((yyval.node), (yyvsp[(2) - (5)].string));
        add_child((yyval.node), (yyvsp[(1) - (5)].node));
        add_child((yyval.node), (yyvsp[(3) - (5)].node));
        add_child((yyval.node), (yyvsp[(4) - (5)].node));
    }
    break;

  case 5:
#line 109 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_STATICVARDECL, yylineno);
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
    }
    break;

  case 6:
#line 115 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_STATICVARDECLLIST, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 7:
#line 120 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 8:
#line 125 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_VARDECLEXPLIST, yylineno);
        set_string_value((yyval.node), (yyvsp[(2) - (4)].string));
        add_child((yyval.node), (yyvsp[(3) - (4)].node));
        add_child((yyval.node), (yyvsp[(4) - (4)].node));
    }
    break;

  case 9:
#line 131 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 10:
#line 140 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_VARDECL, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
    }
    break;

  case 11:
#line 144 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_STATEMENTLIST, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
    }
    break;

  case 12:
#line 148 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_IFELSE, yylineno);
        add_child((yyval.node), (yyvsp[(3) - (7)].node));
        add_child((yyval.node), (yyvsp[(5) - (7)].node));
        add_child((yyval.node), (yyvsp[(7) - (7)].node));
    }
    break;

  case 13:
#line 154 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_WHILE, yylineno);
        add_child((yyval.node), (yyvsp[(3) - (5)].node));
        add_child((yyval.node), (yyvsp[(5) - (5)].node));
    }
    break;

  case 14:
#line 159 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PRINTLN, yylineno);
        add_child((yyval.node), (yyvsp[(3) - (5)].node));
    }
    break;

  case 15:
#line 163 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PRINT, yylineno);
        add_child((yyval.node), (yyvsp[(3) - (5)].node));
    }
    break;

  case 16:
#line 167 "parser.y"
    { 
        (yyval.node) = new_node(NODETYPE_REASSIGN, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (4)].node));
        add_child((yyval.node), (yyvsp[(3) - (4)].node));
    }
    break;

  case 17:
#line 172 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_RETURN, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
    }
    break;

  case 18:
#line 176 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_METHODCALL, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
    }
    break;

  case 19:
#line 182 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_STATEMENTLIST, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 20:
#line 187 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 21:
#line 192 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LEFTVALUE, yylineno);
        set_string_value((yyval.node), (yyvsp[(1) - (1)].string));
    }
    break;

  case 22:
#line 196 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LEFTVALUEINDEX, yylineno);
        set_string_value((yyval.node), (yyvsp[(1) - (2)].string));
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 23:
#line 203 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_INDEX, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
    }
    break;

  case 24:
#line 207 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_INDEXLIST, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (4)].node));
        add_child((yyval.node), (yyvsp[(3) - (4)].node));
    }
    break;

  case 25:
#line 218 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_TYPE, yylineno);
        (yyval.node) -> data.type = (yyvsp[(1) - (1)].node) -> data.type;
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
    }
    break;

  case 26:
#line 223 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_TYPE, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        (yyval.node) -> data.type = (yyvsp[(1) - (3)].node) -> data.type;
        (yyval.node) -> data.num_indices = (yyvsp[(1) - (3)].node) -> data.num_indices + 1;
    }
    break;

  case 27:
#line 231 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE, yylineno);
        (yyval.node) -> data.type = DATATYPE_INT;
    }
    break;

  case 28:
#line 235 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE, yylineno);
        (yyval.node) -> data.type = DATATYPE_BOOLEAN;
    }
    break;

  case 29:
#line 239 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE, yylineno);
        (yyval.node) -> data.type = DATATYPE_STR;
    }
    break;

  case 30:
#line 249 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_METHODCALL, yylineno);
        set_string_value((yyval.node), (yyvsp[(1) - (4)].string));
        add_child((yyval.node), (yyvsp[(3) - (4)].node));
    }
    break;

  case 31:
#line 254 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PARSEINT, yylineno);
        add_child((yyval.node), (yyvsp[(3) - (4)].node));
    }
    break;

  case 32:
#line 262 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_STATICMETHODDECL, yylineno);
        set_string_value((yyval.node), (yyvsp[(4) - (10)].string));
        add_child((yyval.node), (yyvsp[(3) - (10)].node));
        add_child((yyval.node), (yyvsp[(6) - (10)].node));
        add_child((yyval.node), (yyvsp[(9) - (10)].node));
    }
    break;

  case 33:
#line 271 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_STATICMETHODDECLLIST, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 34:
#line 276 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 35:
#line 281 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_FORMALLIST, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 36:
#line 286 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 37:
#line 291 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_ARG, yylineno);
        set_string_value((yyval.node), (yyvsp[(2) - (2)].string));
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
    }
    break;

  case 38:
#line 298 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_ARGLIST, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
    }
    break;

  case 39:
#line 303 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 40:
#line 312 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_ADDOP, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 41:
#line 318 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_SUBOP, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));        
        // fill out other semantics
    }
    break;

  case 42:
#line 324 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_AND, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 43:
#line 330 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_OR, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 44:
#line 336 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_COMPLESS, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 45:
#line 342 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_COMPGREAT, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 46:
#line 348 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_COMPLEQ, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 47:
#line 354 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_COMPGREQ, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 48:
#line 360 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_COMPEQ, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 49:
#line 366 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_COMPNEQ, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 50:
#line 372 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_TERM, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
        // fill out other semantics
    }
    break;

  case 51:
#line 379 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_MULOP, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 52:
#line 385 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_DIVOP, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
        // fill out other semantics
    }
    break;

  case 53:
#line 391 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_FACTOR, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
        // fill out other semantics
    }
    break;

  case 54:
#line 398 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LITERAL, yylineno);
        set_int_value((yyval.node), (yyvsp[(1) - (1)].integer));
    }
    break;

  case 55:
#line 402 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LITERAL, yylineno);
        set_string_value((yyval.node), (yyvsp[(1) - (1)].string));
    }
    break;

  case 56:
#line 406 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LITERAL, yylineno);
        set_boolean_value((yyval.node), true);
    }
    break;

  case 57:
#line 410 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LITERAL, yylineno);
        set_boolean_value((yyval.node), false);
    }
    break;

  case 58:
#line 414 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NOT, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
        // fill out other semantics
    }
    break;

  case 59:
#line 419 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_PLUSOP, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
        // fill out other semantics
    }
    break;

  case 60:
#line 424 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_MINUSOP, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
        // fill out other semantics
    }
    break;

  case 61:
#line 429 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
    }
    break;

  case 62:
#line 433 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LEFTVALUE, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
    }
    break;

  case 63:
#line 437 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_LENGTH, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (3)].node));
    }
    break;

  case 64:
#line 441 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_METHODCALL, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (1)].node));
    }
    break;

  case 65:
#line 445 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_ARRAY, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
    }
    break;

  case 66:
#line 452 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_EXPDECL, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 67:
#line 456 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 68:
#line 461 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_EXPLIST, yylineno);
        add_child((yyval.node), (yyvsp[(1) - (2)].node));
        add_child((yyval.node), (yyvsp[(2) - (2)].node));
    }
    break;

  case 69:
#line 466 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;

  case 70:
#line 471 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_EXPTAIL, yylineno);
        add_child((yyval.node), (yyvsp[(2) - (3)].node));
        add_child((yyval.node), (yyvsp[(3) - (3)].node));
    }
    break;

  case 71:
#line 476 "parser.y"
    {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2191 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 479 "parser.y"


void yyerror(char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

int main(int argc, char* argv[])
{
    yyin = fopen(argv[1], "r");

    // Checks for syntax errors and constructs AST
    if (yyparse() != 0) return 1;

    // Traverse the AST to check for semantic errors if no syntac errors
    checkProgram(root);

    // Return after type errors are reported
    if (num_errors != 0) return 1; 

    // Perform codegen
    genProgram(root, argv[1]);
    
    return 0;
}
