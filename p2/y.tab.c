/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include "typecheck.h"
#include "node.h"
void yyerror(char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;

struct ASTNode* root;

#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_AND = 258,                 /* TOK_AND  */
    TOK_OR = 259,                  /* TOK_OR  */
    TOK_LESS = 260,                /* TOK_LESS  */
    TOK_GREAT = 261,               /* TOK_GREAT  */
    TOK_LEQ = 262,                 /* TOK_LEQ  */
    TOK_GREQ = 263,                /* TOK_GREQ  */
    TOK_NEQ = 264,                 /* TOK_NEQ  */
    TOK_EQ = 265,                  /* TOK_EQ  */
    TOK_PLUS = 266,                /* TOK_PLUS  */
    TOK_MINUS = 267,               /* TOK_MINUS  */
    TOK_MULT = 268,                /* TOK_MULT  */
    TOK_DIV = 269,                 /* TOK_DIV  */
    KW_BOOLEAN = 270,              /* KW_BOOLEAN  */
    KW_CLASS = 271,                /* KW_CLASS  */
    KW_FALSE = 272,                /* KW_FALSE  */
    KW_INT = 273,                  /* KW_INT  */
    MAIN = 274,                    /* MAIN  */
    KW_PUBLIC = 275,               /* KW_PUBLIC  */
    KW_TRUE = 276,                 /* KW_TRUE  */
    KW_VOID = 277,                 /* KW_VOID  */
    KW_IF = 278,                   /* KW_IF  */
    KW_ELSE = 279,                 /* KW_ELSE  */
    KW_RETURN = 280,               /* KW_RETURN  */
    KW_WHILE = 281,                /* KW_WHILE  */
    KW_LENGTH = 282,               /* KW_LENGTH  */
    KW_STATIC = 283,               /* KW_STATIC  */
    KW_STRING = 284,               /* KW_STRING  */
    KW_NEW = 285,                  /* KW_NEW  */
    KW_PRIVATE = 286,              /* KW_PRIVATE  */
    SYSTEM_OUT_PRINT = 287,        /* SYSTEM_OUT_PRINT  */
    SYSTEM_OUT_PRINTLN = 288,      /* SYSTEM_OUT_PRINTLN  */
    INTEGER_PARSE_INT = 289,       /* INTEGER_PARSE_INT  */
    INTEGER_LITERAL = 290,         /* INTEGER_LITERAL  */
    STRING_LITERAL = 291,          /* STRING_LITERAL  */
    ID = 292                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define KW_BOOLEAN 270
#define KW_CLASS 271
#define KW_FALSE 272
#define KW_INT 273
#define MAIN 274
#define KW_PUBLIC 275
#define KW_TRUE 276
#define KW_VOID 277
#define KW_IF 278
#define KW_ELSE 279
#define KW_RETURN 280
#define KW_WHILE 281
#define KW_LENGTH 282
#define KW_STATIC 283
#define KW_STRING 284
#define KW_NEW 285
#define KW_PRIVATE 286
#define SYSTEM_OUT_PRINT 287
#define SYSTEM_OUT_PRINTLN 288
#define INTEGER_PARSE_INT 289
#define INTEGER_LITERAL 290
#define STRING_LITERAL 291
#define ID 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

    struct ASTNode* node;
    int integer;
    char * string;

#line 221 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_AND = 3,                    /* TOK_AND  */
  YYSYMBOL_TOK_OR = 4,                     /* TOK_OR  */
  YYSYMBOL_TOK_LESS = 5,                   /* TOK_LESS  */
  YYSYMBOL_TOK_GREAT = 6,                  /* TOK_GREAT  */
  YYSYMBOL_TOK_LEQ = 7,                    /* TOK_LEQ  */
  YYSYMBOL_TOK_GREQ = 8,                   /* TOK_GREQ  */
  YYSYMBOL_TOK_NEQ = 9,                    /* TOK_NEQ  */
  YYSYMBOL_TOK_EQ = 10,                    /* TOK_EQ  */
  YYSYMBOL_TOK_PLUS = 11,                  /* TOK_PLUS  */
  YYSYMBOL_TOK_MINUS = 12,                 /* TOK_MINUS  */
  YYSYMBOL_TOK_MULT = 13,                  /* TOK_MULT  */
  YYSYMBOL_TOK_DIV = 14,                   /* TOK_DIV  */
  YYSYMBOL_KW_BOOLEAN = 15,                /* KW_BOOLEAN  */
  YYSYMBOL_KW_CLASS = 16,                  /* KW_CLASS  */
  YYSYMBOL_KW_FALSE = 17,                  /* KW_FALSE  */
  YYSYMBOL_KW_INT = 18,                    /* KW_INT  */
  YYSYMBOL_MAIN = 19,                      /* MAIN  */
  YYSYMBOL_KW_PUBLIC = 20,                 /* KW_PUBLIC  */
  YYSYMBOL_KW_TRUE = 21,                   /* KW_TRUE  */
  YYSYMBOL_KW_VOID = 22,                   /* KW_VOID  */
  YYSYMBOL_KW_IF = 23,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 24,                   /* KW_ELSE  */
  YYSYMBOL_KW_RETURN = 25,                 /* KW_RETURN  */
  YYSYMBOL_KW_WHILE = 26,                  /* KW_WHILE  */
  YYSYMBOL_KW_LENGTH = 27,                 /* KW_LENGTH  */
  YYSYMBOL_KW_STATIC = 28,                 /* KW_STATIC  */
  YYSYMBOL_KW_STRING = 29,                 /* KW_STRING  */
  YYSYMBOL_KW_NEW = 30,                    /* KW_NEW  */
  YYSYMBOL_KW_PRIVATE = 31,                /* KW_PRIVATE  */
  YYSYMBOL_SYSTEM_OUT_PRINT = 32,          /* SYSTEM_OUT_PRINT  */
  YYSYMBOL_SYSTEM_OUT_PRINTLN = 33,        /* SYSTEM_OUT_PRINTLN  */
  YYSYMBOL_INTEGER_PARSE_INT = 34,         /* INTEGER_PARSE_INT  */
  YYSYMBOL_INTEGER_LITERAL = 35,           /* INTEGER_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 36,            /* STRING_LITERAL  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '.'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Program = 49,                   /* Program  */
  YYSYMBOL_MainClass = 50,                 /* MainClass  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_StaticVarDecl = 52,             /* StaticVarDecl  */
  YYSYMBOL_StaticVarDeclList = 53,         /* StaticVarDeclList  */
  YYSYMBOL_VarDeclExpList = 54,            /* VarDeclExpList  */
  YYSYMBOL_Statement = 55,                 /* Statement  */
  YYSYMBOL_StatementList = 56,             /* StatementList  */
  YYSYMBOL_LeftValue = 57,                 /* LeftValue  */
  YYSYMBOL_Index = 58,                     /* Index  */
  YYSYMBOL_Type = 59,                      /* Type  */
  YYSYMBOL_PrimeType = 60,                 /* PrimeType  */
  YYSYMBOL_MethodCall = 61,                /* MethodCall  */
  YYSYMBOL_StaticMethodDecl = 62,          /* StaticMethodDecl  */
  YYSYMBOL_StaticMethodDeclList = 63,      /* StaticMethodDeclList  */
  YYSYMBOL_FormalList = 64,                /* FormalList  */
  YYSYMBOL_Arg = 65,                       /* Arg  */
  YYSYMBOL_ArgList = 66,                   /* ArgList  */
  YYSYMBOL_Exp = 67,                       /* Exp  */
  YYSYMBOL_ExpDecl = 68,                   /* ExpDecl  */
  YYSYMBOL_ExpList = 69,                   /* ExpList  */
  YYSYMBOL_ExpTail = 70                    /* ExpTail  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    42,     2,     2,    45,     2,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    71,    91,   100,   106,   111,   116,   122,
     131,   135,   139,   145,   150,   155,   159,   166,   170,   181,
     186,   193,   197,   201,   211,   218,   229,   234,   239,   244,
     249,   255,   260,   269,   273,   277,   281,   285,   290,   294,
     298,   302,   310,   314,   319,   324,   329,   334
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_AND", "TOK_OR",
  "TOK_LESS", "TOK_GREAT", "TOK_LEQ", "TOK_GREQ", "TOK_NEQ", "TOK_EQ",
  "TOK_PLUS", "TOK_MINUS", "TOK_MULT", "TOK_DIV", "KW_BOOLEAN", "KW_CLASS",
  "KW_FALSE", "KW_INT", "MAIN", "KW_PUBLIC", "KW_TRUE", "KW_VOID", "KW_IF",
  "KW_ELSE", "KW_RETURN", "KW_WHILE", "KW_LENGTH", "KW_STATIC",
  "KW_STRING", "KW_NEW", "KW_PRIVATE", "SYSTEM_OUT_PRINT",
  "SYSTEM_OUT_PRINTLN", "INTEGER_PARSE_INT", "INTEGER_LITERAL",
  "STRING_LITERAL", "ID", "'{'", "'('", "'['", "']'", "')'", "'}'", "';'",
  "','", "'.'", "'='", "$accept", "Program", "MainClass", "VarDecl",
  "StaticVarDecl", "StaticVarDeclList", "VarDeclExpList", "Statement",
  "StatementList", "LeftValue", "Index", "Type", "PrimeType", "MethodCall",
  "StaticMethodDecl", "StaticMethodDeclList", "FormalList", "Arg",
  "ArgList", "Exp", "ExpDecl", "ExpList", "ExpTail", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -15,   -29,    15,   -37,    -9,   -37,   -37,    -6,     3,   -37,
      16,   -13,    14,   -37,   -37,   -37,   -37,   -37,   -23,   -37,
      25,     4,     0,    36,    12,     9,    11,   -37,    20,    21,
     -37,   -37,   -13,   -37,   -37,    22,     9,   -34,   -37,   -37,
      26,    18,    35,   -22,    27,     9,    23,     9,    39,     4,
     -37,    28,   -13,    29,   -13,     9,    30,    24,    31,   -37,
      33,   -37,    11,    34,    13,    32,    38,   -37,    37,     9,
       9,   -37,   -37,   -37,   -37,    42,   -37,   -37,   -37,   -37,
      40,    24,    41,   -11,   -37,   -37,    44,    45,    46,   -37,
     -37,   -37,   -37,     9,     9,    -5,    47,    48,    43,    49,
      50,   -37,   -37,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     7,    27,     0,     6,
       0,     0,     0,    26,    22,    21,    23,     5,     0,    19,
       0,    43,     0,     0,     0,     0,     9,    20,     0,     0,
      36,    35,     0,    33,    34,    15,     0,    38,    40,    42,
       0,     0,     0,    32,     0,    45,     0,     0,     0,    43,
       4,     0,     0,     0,     0,     0,    41,    47,     0,    37,
       0,    39,     9,     0,     0,    32,     0,    28,     0,     0,
       0,    44,    24,    16,     8,     0,    30,    31,    14,    17,
       0,    47,     0,     0,    18,    46,     0,     0,     0,    25,
      10,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     3,    12,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,    61,   -37,   -37,    51,   -37,   -12,   -37,
     -37,   -17,    55,   -37,   -37,   -37,   -37,    52,    53,   -36,
      54,   -37,     7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    90,     9,     7,    41,    91,    83,    37,
      56,    18,    19,    38,    13,    10,    53,    65,    54,    39,
      26,    58,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,     1,    14,    24,    14,    15,    47,    15,     4,    57,
      14,    60,    48,    15,    21,     5,    16,    22,    16,    68,
     -29,    87,    88,    52,    16,     8,    30,    87,    88,     6,
      31,    11,    89,    80,    81,    64,    12,    64,    98,    32,
      14,    27,    20,    15,    33,    34,    35,    23,    36,    29,
      76,    25,    22,    22,    16,    28,    40,    96,    97,    42,
      43,    45,    50,    49,    51,    59,    61,    55,    63,    70,
      69,    66,    17,    72,    73,    75,    78,    52,    79,    82,
      95,    84,    92,    86,    93,    94,   101,    44,    85,    99,
     100,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,    67,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,    77
};

static const yytype_int8 yycheck[] =
{
      36,    16,    15,    20,    15,    18,    40,    18,    37,    45,
      15,    47,    46,    18,    37,     0,    29,    40,    29,    55,
      42,    32,    33,    45,    29,    31,    17,    32,    33,    38,
      21,    28,    43,    69,    70,    52,    20,    54,    43,    30,
      15,    41,    28,    18,    35,    36,    37,    22,    39,    37,
      37,    47,    40,    40,    29,    19,    45,    93,    94,    39,
      39,    39,    44,    37,    29,    42,    27,    40,    40,    45,
      40,    42,    11,    42,    41,    41,    38,    45,    41,    37,
      92,    41,    38,    42,    39,    39,    43,    32,    81,    42,
      42,    -1,    -1,    44,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    49,    50,    37,     0,    38,    53,    31,    52,
      63,    28,    20,    62,    15,    18,    29,    51,    59,    60,
      28,    37,    40,    22,    59,    47,    68,    41,    19,    37,
      17,    21,    30,    35,    36,    37,    39,    57,    61,    67,
      45,    54,    39,    39,    60,    39,    67,    40,    46,    37,
      44,    29,    45,    64,    66,    40,    58,    67,    69,    42,
      67,    27,    68,    40,    59,    65,    42,    65,    67,    40,
      45,    70,    42,    41,    54,    41,    37,    66,    38,    41,
      67,    67,    37,    56,    41,    70,    42,    32,    33,    43,
      51,    55,    38,    39,    39,    56,    67,    67,    43,    42,
      42,    43,    44,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    52,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    61,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,    19,     5,     3,     2,     0,     4,     0,
       1,     5,     5,     2,     0,     1,     4,     3,     4,     1,
       3,     1,     1,     1,     4,    10,     2,     0,     2,     0,
       2,     3,     0,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     2,     0,     2,     0,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: MainClass  */
#line 64 "parser.y"
              {   
        (yyval.node) = new_node(NODETYPE_PROGRAM, yylineno);
        root = (yyval.node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1343 "y.tab.c"
    break;

  case 3: /* MainClass: KW_CLASS ID '{' StaticVarDeclList StaticMethodDeclList KW_PUBLIC KW_STATIC KW_VOID MAIN '(' KW_STRING '[' ']' ID ')' '{' StatementList '}' '}'  */
#line 78 "parser.y"
    {   
        (yyval.node) = new_node(NODETYPE_MAINCLASS, yylineno);
        set_string_value((yyval.node), (yyvsp[-5].string));
        add_child((yyval.node), (yyvsp[-15].node));
        add_child((yyval.node), (yyvsp[-14].node));
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1355 "y.tab.c"
    break;

  case 4: /* VarDecl: Type ID ExpDecl VarDeclExpList ';'  */
#line 91 "parser.y"
                                       {
        (yyval.node) = new_node(NODETYPE_VARDECL, yylineno);
        set_string_value((yyval.node), (yyvsp[-3].string));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1367 "y.tab.c"
    break;

  case 5: /* StaticVarDecl: KW_PRIVATE KW_STATIC VarDecl  */
#line 100 "parser.y"
                                 {
        (yyval.node) = new_node(NODETYPE_STATICVARDECL, yylineno);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1376 "y.tab.c"
    break;

  case 6: /* StaticVarDeclList: StaticVarDeclList StaticVarDecl  */
#line 106 "parser.y"
                                    {
        (yyval.node) = new_node(NODETYPE_STATICVARDECLLIST, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1386 "y.tab.c"
    break;

  case 7: /* StaticVarDeclList: %empty  */
#line 111 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1394 "y.tab.c"
    break;

  case 8: /* VarDeclExpList: ',' ID ExpDecl VarDeclExpList  */
#line 116 "parser.y"
                                  {
        (yyval.node) = new_node(NODETYPE_VARDECLEXPLIST, yylineno);
        set_string_value((yyval.node), (yyvsp[-2].string));
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1405 "y.tab.c"
    break;

  case 9: /* VarDeclExpList: %empty  */
#line 122 "parser.y"
       {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1413 "y.tab.c"
    break;

  case 10: /* Statement: VarDecl  */
#line 131 "parser.y"
            {
        (yyval.node) = new_node(NODETYPE_VARDECL, yylineno);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1422 "y.tab.c"
    break;

  case 11: /* Statement: SYSTEM_OUT_PRINTLN '(' Exp ')' ';'  */
#line 135 "parser.y"
                                         {
        (yyval.node) = new_node(NODETYPE_STATEMENT, yylineno);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1431 "y.tab.c"
    break;

  case 12: /* Statement: SYSTEM_OUT_PRINT '(' Exp ')' ';'  */
#line 139 "parser.y"
                                       {
        (yyval.node) = new_node(NODETYPE_STATEMENT, yylineno);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1440 "y.tab.c"
    break;

  case 13: /* StatementList: StatementList Statement  */
#line 145 "parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_STATEMENTLIST, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1450 "y.tab.c"
    break;

  case 14: /* StatementList: %empty  */
#line 150 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1458 "y.tab.c"
    break;

  case 15: /* LeftValue: ID  */
#line 155 "parser.y"
       {
        (yyval.node) = new_node(NODETYPE_LEFTVALUE, yylineno);
        set_string_value((yyval.node), (yyvsp[0].string));
    }
#line 1467 "y.tab.c"
    break;

  case 16: /* LeftValue: LeftValue '[' Exp ']'  */
#line 159 "parser.y"
                            {
        (yyval.node) = new_node(NODETYPE_LEFTVALUE, yylineno);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1477 "y.tab.c"
    break;

  case 17: /* Index: '[' Exp ']'  */
#line 166 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_INDEX, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1486 "y.tab.c"
    break;

  case 18: /* Index: Index '[' Exp ']'  */
#line 170 "parser.y"
                        {
        (yyval.node) = new_node(NODETYPE_INDEX, yylineno);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1496 "y.tab.c"
    break;

  case 19: /* Type: PrimeType  */
#line 181 "parser.y"
              {
        (yyval.node) = new_node(NODETYPE_TYPE, yylineno);
        (yyval.node) -> data.type = (yyvsp[0].node) -> data.type;
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1506 "y.tab.c"
    break;

  case 20: /* Type: Type '[' ']'  */
#line 186 "parser.y"
                   {
        (yyval.node) = new_node(NODETYPE_TYPE, yylineno);
        (yyval.node) -> data.type = (yyvsp[-2].node) -> data.type;
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1516 "y.tab.c"
    break;

  case 21: /* PrimeType: KW_INT  */
#line 193 "parser.y"
           {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE, yylineno);
        (yyval.node) -> data.type = DATATYPE_INT;
    }
#line 1525 "y.tab.c"
    break;

  case 22: /* PrimeType: KW_BOOLEAN  */
#line 197 "parser.y"
                 {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE, yylineno);
        (yyval.node) -> data.type = DATATYPE_BOOLEAN;
    }
#line 1534 "y.tab.c"
    break;

  case 23: /* PrimeType: KW_STRING  */
#line 201 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_PRIMETYPE, yylineno);
        (yyval.node) -> data.type = DATATYPE_STR;
    }
#line 1543 "y.tab.c"
    break;

  case 24: /* MethodCall: ID '(' ExpList ')'  */
#line 211 "parser.y"
                       {
        (yyval.node) = new_node(NODETYPE_METHODCALL, yylineno);
        set_string_value((yyval.node), (yyvsp[-3].string));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1553 "y.tab.c"
    break;

  case 25: /* StaticMethodDecl: KW_PUBLIC KW_STATIC Type ID '(' FormalList ')' '{' StatementList '}'  */
#line 220 "parser.y"
        {
        (yyval.node) = new_node(NODETYPE_STATICMETHODDECL, yylineno);
        set_string_value((yyval.node), (yyvsp[-6].string));
        add_child((yyval.node), (yyvsp[-7].node));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1565 "y.tab.c"
    break;

  case 26: /* StaticMethodDeclList: StaticMethodDeclList StaticMethodDecl  */
#line 229 "parser.y"
                                          {
        (yyval.node) = new_node(NODETYPE_STATICMETHODDECLLIST, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1575 "y.tab.c"
    break;

  case 27: /* StaticMethodDeclList: %empty  */
#line 234 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1583 "y.tab.c"
    break;

  case 28: /* FormalList: ArgList Arg  */
#line 239 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_FORMALLIST, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1593 "y.tab.c"
    break;

  case 29: /* FormalList: %empty  */
#line 244 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1601 "y.tab.c"
    break;

  case 30: /* Arg: Type ID  */
#line 249 "parser.y"
            {
        (yyval.node) = new_node(NODETYPE_ARG, yylineno);
        set_string_value((yyval.node), (yyvsp[0].string));
    }
#line 1610 "y.tab.c"
    break;

  case 31: /* ArgList: ',' Arg ArgList  */
#line 255 "parser.y"
                    {
        (yyval.node) = new_node(NODETYPE_ARGLIST, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1620 "y.tab.c"
    break;

  case 32: /* ArgList: %empty  */
#line 260 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1628 "y.tab.c"
    break;

  case 33: /* Exp: INTEGER_LITERAL  */
#line 269 "parser.y"
                    {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        set_int_value((yyval.node), (yyvsp[0].integer));
    }
#line 1637 "y.tab.c"
    break;

  case 34: /* Exp: STRING_LITERAL  */
#line 273 "parser.y"
                     {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        set_string_value((yyval.node), (yyvsp[0].string));
    }
#line 1646 "y.tab.c"
    break;

  case 35: /* Exp: KW_TRUE  */
#line 277 "parser.y"
              {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        set_boolean_value((yyval.node), true);
    }
#line 1655 "y.tab.c"
    break;

  case 36: /* Exp: KW_FALSE  */
#line 281 "parser.y"
               {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        set_boolean_value((yyval.node), false);
    }
#line 1664 "y.tab.c"
    break;

  case 37: /* Exp: '(' Exp ')'  */
#line 285 "parser.y"
                  {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        (yyval.node) -> data.type = (yyvsp[-1].node) -> data.type;
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1674 "y.tab.c"
    break;

  case 38: /* Exp: LeftValue  */
#line 290 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1683 "y.tab.c"
    break;

  case 39: /* Exp: LeftValue '.' KW_LENGTH  */
#line 294 "parser.y"
                              {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1692 "y.tab.c"
    break;

  case 40: /* Exp: MethodCall  */
#line 298 "parser.y"
                 {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1701 "y.tab.c"
    break;

  case 41: /* Exp: KW_NEW PrimeType Index  */
#line 302 "parser.y"
                             {
        (yyval.node) = new_node(NODETYPE_EXP, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1711 "y.tab.c"
    break;

  case 42: /* ExpDecl: '=' Exp  */
#line 310 "parser.y"
            {
        (yyval.node) = new_node(NODETYPE_EXPDECL, yylineno);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1720 "y.tab.c"
    break;

  case 43: /* ExpDecl: %empty  */
#line 314 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1728 "y.tab.c"
    break;

  case 44: /* ExpList: Exp ExpTail  */
#line 319 "parser.y"
                {
        (yyval.node) = new_node(NODETYPE_EXPLIST, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1738 "y.tab.c"
    break;

  case 45: /* ExpList: %empty  */
#line 324 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1746 "y.tab.c"
    break;

  case 46: /* ExpTail: ',' Exp ExpTail  */
#line 329 "parser.y"
                    {
        (yyval.node) = new_node(NODETYPE_EXPTAIL, yylineno);
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1756 "y.tab.c"
    break;

  case 47: /* ExpTail: %empty  */
#line 334 "parser.y"
      {
        (yyval.node) = new_node(NODETYPE_NULLABLE, yylineno);
    }
#line 1764 "y.tab.c"
    break;


#line 1768 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 337 "parser.y"


void yyerror(char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

int main(int argc, char* argv[] )
{
    yyin = fopen( argv[1], "r" );

    // Checks for syntax errors and constructs AST
    if (yyparse() != 0)
        return 1;

    // Traverse the AST to check for semantic errors if no syntac errors
    checkProgram(root);
    
    return 0;
}
