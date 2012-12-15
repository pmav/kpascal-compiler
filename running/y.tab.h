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
     EQUAL = 258,
     PLUS = 259,
     MINUS = 260,
     MOD = 261,
     DIV = 262,
     STAR = 263,
     OR = 264,
     AND = 265,
     UMINUS = 266,
     PROGRAM = 267,
     VAR = 268,
     FUNCTION = 269,
     ASSIGNMENT = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     WRITELN = 274,
     WHILE = 275,
     DO = 276,
     DOT = 277,
     PBEGIN = 278,
     END = 279,
     COLON = 280,
     SEMICOLON = 281,
     COMMA = 282,
     SLASH = 283,
     GE = 284,
     GT = 285,
     LE = 286,
     LT = 287,
     NOTEQUAL = 288,
     LPAREN = 289,
     RPAREN = 290,
     DTINTEGER = 291,
     DTBOOLEAN = 292,
     DTCHAR = 293,
     DTSTRING = 294,
     DTREAL = 295,
     TRUE = 296,
     FALSE = 297,
     STRING = 298,
     IDENTIFIER = 299,
     DIGSEQ = 300,
     FDIGSEQ = 301
   };
#endif
/* Tokens.  */
#define EQUAL 258
#define PLUS 259
#define MINUS 260
#define MOD 261
#define DIV 262
#define STAR 263
#define OR 264
#define AND 265
#define UMINUS 266
#define PROGRAM 267
#define VAR 268
#define FUNCTION 269
#define ASSIGNMENT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define WRITELN 274
#define WHILE 275
#define DO 276
#define DOT 277
#define PBEGIN 278
#define END 279
#define COLON 280
#define SEMICOLON 281
#define COMMA 282
#define SLASH 283
#define GE 284
#define GT 285
#define LE 286
#define LT 287
#define NOTEQUAL 288
#define LPAREN 289
#define RPAREN 290
#define DTINTEGER 291
#define DTBOOLEAN 292
#define DTCHAR 293
#define DTSTRING 294
#define DTREAL 295
#define TRUE 296
#define FALSE 297
#define STRING 298
#define IDENTIFIER 299
#define DIGSEQ 300
#define FDIGSEQ 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "pascal.y"
{
 char* string;
 char* identifier;
 unsigned digseq;
 float fdigseq;

 int fr; /* function_return */

 struct _a1  *ip;  /* is_program */
 struct _a2  *ph;  /* is_program_heading */
 struct _a3  *pb;  /* is_program_block */
 struct _a4  *vn;  /* is_var_name */ 
 struct _a5  *vdp; /* is_variable_declaration_part */
 struct _a7  *vd;  /* is_variable_declaration */
 struct _a16 *vnl; /* is_var_name_list */
 struct _a6  *sp;  /* is_statement_list */
 struct _a9  *st;  /* is_statement */
 struct _a10 *as;  /* is_assignment_statement */
 struct _a11 *ws;  /* is_writeln_statement */
 struct _a13 *ds;  /* is_digit_sequence */
 struct _a17 *wa;  /* is_writeln_argument */
 struct _a19 *wal; /* is_writeln_argument_list */
 struct _a18 *s;   /* is_string */
 struct _a12 *ex;  /* is_expression */
 struct _a21 *le;  /* is_logical_expression */
 struct _a25 *ile; /* is_internal_logical_expression */
 struct _a22 *is;  /* is_if_statement */
 struct _a23 *whs; /* if_while_statement */
 struct _a12 *be;  /* is_expression */
 struct _a30 *fa;  /* is_function_argument */
 struct _a29 *fal; /* is_function_argument_list */
 struct _a28 *f;   /* is_function */
 struct _a27 *fl;  /* is_function_list */
 struct _a31 *fc;  /* is_function_call */
 struct _a32 *fcal;/* is_function_call_argument_list */
}
/* Line 1489 of yacc.c.  */
#line 178 "running/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

