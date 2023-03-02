/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    KW_BOOLEAN = 258,              /* KW_BOOLEAN  */
    KW_CLASS = 259,                /* KW_CLASS  */
    KW_FALSE = 260,                /* KW_FALSE  */
    KW_INT = 261,                  /* KW_INT  */
    MAIN = 262,                    /* MAIN  */
    KW_PUBLIC = 263,               /* KW_PUBLIC  */
    KW_TRUE = 264,                 /* KW_TRUE  */
    KW_VOID = 265,                 /* KW_VOID  */
    KW_IF = 266,                   /* KW_IF  */
    KW_ELSE = 267,                 /* KW_ELSE  */
    KW_RETURN = 268,               /* KW_RETURN  */
    KW_WHILE = 269,                /* KW_WHILE  */
    KW_LENGTH = 270,               /* KW_LENGTH  */
    KW_STATIC = 271,               /* KW_STATIC  */
    KW_STRING = 272,               /* KW_STRING  */
    KW_NEW = 273,                  /* KW_NEW  */
    KW_PRIVATE = 274,              /* KW_PRIVATE  */
    SYSTEM_OUT_PRINT = 275,        /* SYSTEM_OUT_PRINT  */
    SYSTEM_OUT_PRINTLN = 276,      /* SYSTEM_OUT_PRINTLN  */
    INTEGER_LITERAL = 277,         /* INTEGER_LITERAL  */
    STRING_LITERAL = 278,          /* STRING_LITERAL  */
    ID = 279                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_BOOLEAN 258
#define KW_CLASS 259
#define KW_FALSE 260
#define KW_INT 261
#define MAIN 262
#define KW_PUBLIC 263
#define KW_TRUE 264
#define KW_VOID 265
#define KW_IF 266
#define KW_ELSE 267
#define KW_RETURN 268
#define KW_WHILE 269
#define KW_LENGTH 270
#define KW_STATIC 271
#define KW_STRING 272
#define KW_NEW 273
#define KW_PRIVATE 274
#define SYSTEM_OUT_PRINT 275
#define SYSTEM_OUT_PRINTLN 276
#define INTEGER_LITERAL 277
#define STRING_LITERAL 278
#define ID 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

    struct ASTNode* node;
    int integer;
    char * string;

#line 121 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
