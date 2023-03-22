/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parser.y"
{
    struct ASTNode* node;
    int integer;
    char * string;
}
/* Line 1529 of yacc.c.  */
#line 131 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

