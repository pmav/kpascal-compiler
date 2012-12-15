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




/* Copy the first part of user declarations.  */
#line 9 "pascal.y"


#include <stdio.h>
#include <stdlib.h>
#include "../functions/structures.h"
#include "../functions/functions.c"
#include "../symbol_table/symbol_table.c"
#include "../semantics/semantics.c"
#include "../translate/translate.c"

table_element *symbol_table;
function_element *function_table;

is_program *my_program;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
/* Line 187 of yacc.c.  */
#line 242 "running/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 255 "running/y.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    18,    24,    29,    33,    35,
      38,    43,    48,    53,    57,    59,    62,    64,    79,    92,
      96,    98,    99,   103,   105,   107,   109,   112,   114,   116,
     118,   120,   122,   130,   135,   143,   150,   160,   170,   183,
     188,   193,   197,   199,   200,   206,   210,   212,   214,   216,
     220,   224,   228,   230,   234,   238,   242,   246,   250,   254,
     256,   260,   264,   268,   272,   276,   280,   282,   284,   286,
     288,   290,   292,   294,   297,   299,   302,   304
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    26,    50,    22,    -1,    12,    73,
      -1,    13,    51,    54,    23,    59,    24,    -1,    13,    51,
      23,    59,    24,    -1,    54,    23,    59,    24,    -1,    23,
      59,    24,    -1,    52,    -1,    51,    52,    -1,    53,    25,
      36,    26,    -1,    53,    25,    37,    26,    -1,    53,    25,
      40,    26,    -1,    53,    27,    73,    -1,    73,    -1,    54,
      55,    -1,    55,    -1,    14,    73,    34,    56,    35,    25,
      58,    26,    13,    51,    23,    59,    24,    26,    -1,    14,
      73,    34,    56,    35,    25,    58,    26,    23,    59,    24,
      26,    -1,    56,    26,    57,    -1,    57,    -1,    -1,    53,
      25,    58,    -1,    36,    -1,    40,    -1,    37,    -1,    59,
      60,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      66,    -1,    20,    69,    21,    23,    59,    24,    26,    -1,
      16,    69,    17,    60,    -1,    16,    69,    17,    23,    59,
      24,    26,    -1,    16,    69,    17,    60,    18,    60,    -1,
      16,    69,    17,    60,    18,    23,    59,    24,    26,    -1,
      16,    69,    17,    23,    59,    24,    26,    18,    60,    -1,
      16,    69,    17,    23,    59,    24,    26,    18,    23,    59,
      24,    26,    -1,    73,    15,    71,    26,    -1,    73,    34,
      65,    35,    -1,    65,    27,    71,    -1,    71,    -1,    -1,
      19,    34,    67,    35,    26,    -1,    67,    27,    68,    -1,
      68,    -1,    75,    -1,    71,    -1,    69,    10,    69,    -1,
      69,     9,    69,    -1,    34,    69,    35,    -1,    70,    -1,
      71,     3,    71,    -1,    71,    30,    71,    -1,    71,    32,
      71,    -1,    71,    29,    71,    -1,    71,    31,    71,    -1,
      71,    33,    71,    -1,    71,    -1,    71,     4,    71,    -1,
      71,     5,    71,    -1,    71,     7,    71,    -1,    71,     8,
      71,    -1,    71,     6,    71,    -1,    34,    71,    35,    -1,
      74,    -1,    73,    -1,    64,    -1,    72,    -1,    41,    -1,
      42,    -1,    44,    -1,     5,    45,    -1,    45,    -1,     5,
      46,    -1,    46,    -1,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   115,   119,   120,   121,   122,   128,   129,
     133,   134,   135,   139,   140,   146,   147,   151,   152,   156,
     157,   158,   162,   166,   167,   168,   174,   175,   179,   180,
     181,   182,   188,   193,   194,   197,   198,   201,   202,   206,
     210,   214,   215,   216,   220,   224,   225,   229,   230,   236,
     237,   238,   239,   243,   244,   245,   246,   247,   248,   249,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     266,   267,   273,   277,   278,   279,   280,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQUAL", "PLUS", "MINUS", "MOD", "DIV",
  "STAR", "OR", "AND", "UMINUS", "PROGRAM", "VAR", "FUNCTION",
  "ASSIGNMENT", "IF", "THEN", "ELSE", "WRITELN", "WHILE", "DO", "DOT",
  "PBEGIN", "END", "COLON", "SEMICOLON", "COMMA", "SLASH", "GE", "GT",
  "LE", "LT", "NOTEQUAL", "LPAREN", "RPAREN", "DTINTEGER", "DTBOOLEAN",
  "DTCHAR", "DTSTRING", "DTREAL", "TRUE", "FALSE", "STRING", "IDENTIFIER",
  "DIGSEQ", "FDIGSEQ", "$accept", "program", "program_heading",
  "program_block", "variable_declaration_part", "variable_declaration",
  "var_name_list", "function_list", "function", "function_argument_list",
  "function_argument", "function_return", "statement_list", "statement",
  "while_statement", "if_statement", "assignment_statement",
  "function_call", "function_call_argument_list", "writeln_statement",
  "writeln_argument_list", "writeln_argument", "logical_expression",
  "internal_logical_expression", "expression", "boolean_expression",
  "var_name", "digit_sequence", "string", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    58,    58,    58,    59,    59,    60,    60,
      60,    60,    61,    62,    62,    62,    62,    62,    62,    63,
      64,    65,    65,    65,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    74,    74,    74,    74,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     6,     5,     4,     3,     1,     2,
       4,     4,     4,     3,     1,     2,     1,    14,    12,     3,
       1,     0,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     7,     4,     7,     6,     9,     9,    12,     4,
       4,     3,     1,     0,     5,     3,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    72,     3,     1,     0,     0,     0,
       0,     0,     0,    16,     0,     8,     0,    14,     0,     0,
       0,     0,     0,    27,    28,    29,    30,    31,     0,     2,
       0,    15,     0,     9,     0,     0,     0,    21,     0,     0,
      70,    71,    74,    76,    68,     0,    52,    59,    69,    67,
      66,     0,     0,     7,    26,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,    20,    73,    75,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,    77,     0,    46,    48,
      47,     0,     0,     6,     5,     0,    10,    11,    12,     0,
       0,     0,    51,    65,    50,    49,     0,    33,    53,    60,
      61,    64,    62,    63,    56,    54,    57,    55,    58,     0,
      42,     0,     0,     0,     0,    39,     4,    23,    25,    24,
      22,    19,     0,     0,     0,     0,    40,    45,    44,     0,
       0,     0,     0,    35,    41,     0,     0,    34,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    37,    36,     0,
       0,     0,     0,    18,     0,     0,    38,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    11,    14,    15,    16,    12,    13,    64,
      65,   130,    22,    23,    24,    25,    26,    44,   119,    27,
      87,    88,    45,    46,    47,    48,    28,    50,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int16 yypact[] =
{
      -7,   -33,    22,    11,   -36,   -36,   -36,   102,   -33,   -33,
       7,    21,    96,   -36,     1,   -36,   103,   -36,    15,    59,
      34,    59,    47,   -36,   -36,   -36,   -36,   -36,    77,   -36,
       7,   -36,     7,   -36,   104,     4,   -33,   -33,    41,    59,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   178,   -36,    72,
     -36,    14,    86,   -36,   -36,   134,    78,    93,     7,    85,
     118,   122,   -36,   106,   167,   -36,   -36,   -36,    79,   166,
      59,    59,   171,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   -36,   165,   -36,   274,
     -36,   144,   268,   -36,   -36,   198,   -36,   -36,   -36,   110,
     -33,   152,   -36,   -36,   -36,   -36,     7,   170,   274,   277,
     277,   -36,   -36,   -36,   274,   274,   274,   274,   274,   177,
     274,    26,    14,   163,     7,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   110,   204,   210,   134,   -36,   -36,   -36,   215,
     179,   180,     7,   -36,   274,   187,    16,   201,   221,   -36,
     -33,     7,   227,   195,   -19,   233,     7,   -36,   -36,     7,
     199,   242,   244,   -36,   206,   212,   -36,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,   -36,   -36,    94,   -13,   -35,   213,    -6,   -36,
     136,   119,   -16,   -10,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   133,   -18,   -36,    81,   -36,    -1,   -36,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,    33,    63,    52,   159,     1,    31,    17,    18,    70,
      71,     4,    54,    17,    56,     9,    57,    72,    49,    38,
      49,    68,     6,    19,    32,     4,    20,    21,    31,   150,
      74,    75,    76,    77,    78,    62,    17,     7,    49,   151,
      59,    60,    95,    29,    61,     4,    54,    54,    85,    37,
      49,     4,   104,   105,    49,    40,    41,    86,     4,    42,
      43,   103,   107,    19,    38,    63,    20,    21,    51,    49,
      49,    53,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    54,    66,    67,    70,    71,
     133,     4,    55,    39,    19,    70,    71,    20,    21,    17,
      40,    41,    93,     4,    42,    43,    84,    91,   139,    19,
       9,    96,    20,    21,   102,     8,     9,    94,     9,    30,
      69,    49,     4,    54,   143,    10,   148,    58,    35,    54,
      36,    99,    89,    36,    49,   155,    92,     4,    54,    38,
     161,    33,   157,   162,    97,    54,   127,   128,    98,    17,
     129,    54,    54,    17,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   120,   121,   124,    85,    73,
      74,    75,    76,    77,    78,    40,    41,   132,     4,    42,
      43,    73,    74,    75,    76,    77,    78,    19,   134,   138,
      20,    21,   122,   100,   106,    79,    80,    81,    82,    83,
     123,   103,   101,    89,   135,   146,   147,    79,    80,    81,
      82,    83,   136,   149,    19,     4,   144,    20,    21,   152,
      19,   158,   126,    20,    21,   163,    19,    34,   141,    20,
      21,    19,   166,   142,    20,    21,   131,    19,   167,   145,
      20,    21,     4,    19,   154,   153,    20,    21,     4,    19,
     156,   140,    20,    21,     4,   137,     0,   160,    19,     4,
      19,    20,    21,    20,    21,     4,   164,     0,   165,     0,
       0,     4,    74,    75,    76,    77,    78,     4,    74,    75,
      76,    77,    78,    76,    77,    78,     4,     0,     4,     0,
       0,     0,     0,     0,   125
};

static const yytype_int16 yycheck[] =
{
       1,    14,    37,    21,    23,    12,    12,     8,     9,     9,
      10,    44,    22,    14,    30,    14,    32,    17,    19,     5,
      21,    39,     0,    16,    23,    44,    19,    20,    34,    13,
       4,     5,     6,     7,     8,    36,    37,    26,    39,    23,
      36,    37,    58,    22,    40,    44,    56,    57,    34,    34,
      51,    44,    70,    71,    55,    41,    42,    43,    44,    45,
      46,    35,    72,    16,     5,   100,    19,    20,    34,    70,
      71,    24,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    95,    45,    46,     9,    10,
     106,    44,    15,    34,    16,     9,    10,    19,    20,   100,
      41,    42,    24,    44,    45,    46,    34,    21,   124,    16,
      14,    26,    19,    20,    35,    13,    14,    24,    14,    23,
      39,   122,    44,   133,   134,    23,   142,    23,    25,   139,
      27,    25,    51,    27,   135,   151,    55,    44,   148,     5,
     156,   154,   152,   159,    26,   155,    36,    37,    26,   150,
      40,   161,   162,   154,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    23,    34,     3,
       4,     5,     6,     7,     8,    41,    42,    25,    44,    45,
      46,     3,     4,     5,     6,     7,     8,    16,    18,    26,
      19,    20,    27,    26,    23,    29,    30,    31,    32,    33,
      35,    35,    35,   122,    27,    26,    26,    29,    30,    31,
      32,    33,    35,    26,    16,    44,   135,    19,    20,    18,
      16,    26,    24,    19,    20,    26,    16,    14,    24,    19,
      20,    16,    26,    23,    19,    20,   100,    16,    26,    24,
      19,    20,    44,    16,   150,    24,    19,    20,    44,    16,
      23,   132,    19,    20,    44,   122,    -1,    24,    16,    44,
      16,    19,    20,    19,    20,    44,    24,    -1,    24,    -1,
      -1,    44,     4,     5,     6,     7,     8,    44,     4,     5,
       6,     7,     8,     6,     7,     8,    44,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    48,    49,    44,    73,     0,    26,    13,    14,
      23,    50,    54,    55,    51,    52,    53,    73,    73,    16,
      19,    20,    59,    60,    61,    62,    63,    66,    73,    22,
      23,    55,    23,    52,    54,    25,    27,    34,     5,    34,
      41,    42,    45,    46,    64,    69,    70,    71,    72,    73,
      74,    34,    69,    24,    60,    15,    59,    59,    23,    36,
      37,    40,    73,    53,    56,    57,    45,    46,    69,    71,
       9,    10,    17,     3,     4,     5,     6,     7,     8,    29,
      30,    31,    32,    33,    34,    34,    43,    67,    68,    71,
      75,    21,    71,    24,    24,    59,    26,    26,    26,    25,
      26,    35,    35,    35,    69,    69,    23,    60,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    65,
      71,    71,    27,    35,    23,    26,    24,    36,    37,    40,
      58,    57,    25,    59,    18,    27,    35,    68,    26,    59,
      58,    24,    23,    60,    71,    24,    26,    26,    59,    26,
      13,    23,    18,    24,    51,    59,    23,    60,    26,    23,
      24,    59,    59,    26,    24,    24,    26,    26
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
# if YYLTYPE_IS_TRIVIAL
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
#line 111 "pascal.y"
    { (yyval.ip) = insert_program((yyvsp[(1) - (4)].ph), (yyvsp[(3) - (4)].pb)); my_program = (yyval.ip); }
    break;

  case 3:
#line 115 "pascal.y"
    { (yyval.ph) = insert_program_heading((yyvsp[(2) - (2)].vn)); }
    break;

  case 4:
#line 119 "pascal.y"
    { (yyval.pb) = insert_program_block((yyvsp[(2) - (6)].vdp), (yyvsp[(3) - (6)].fl), (yyvsp[(5) - (6)].sp)); }
    break;

  case 5:
#line 120 "pascal.y"
    { (yyval.pb) = insert_program_block((yyvsp[(2) - (5)].vdp), NULL, (yyvsp[(4) - (5)].sp)); }
    break;

  case 6:
#line 121 "pascal.y"
    { (yyval.pb) = insert_program_block(NULL, (yyvsp[(1) - (4)].fl), (yyvsp[(3) - (4)].sp)); }
    break;

  case 7:
#line 122 "pascal.y"
    { (yyval.pb) = insert_program_block(NULL, NULL, (yyvsp[(2) - (3)].sp)); }
    break;

  case 8:
#line 128 "pascal.y"
    { (yyval.vdp) = insert_variable_declaration_part(NULL, (yyvsp[(1) - (1)].vd)); }
    break;

  case 9:
#line 129 "pascal.y"
    { (yyval.vdp) = insert_variable_declaration_part((yyvsp[(1) - (2)].vdp), (yyvsp[(2) - (2)].vd)); }
    break;

  case 10:
#line 133 "pascal.y"
    { (yyval.vd) = insert_variable_declaration((yyvsp[(1) - (4)].vnl), d_INTEGER); }
    break;

  case 11:
#line 134 "pascal.y"
    { (yyval.vd) = insert_variable_declaration((yyvsp[(1) - (4)].vnl), d_BOOLEAN); }
    break;

  case 12:
#line 135 "pascal.y"
    { (yyval.vd) = insert_variable_declaration((yyvsp[(1) - (4)].vnl), d_REAL); }
    break;

  case 13:
#line 139 "pascal.y"
    { (yyval.vnl) = insert_var_name_list((yyvsp[(1) - (3)].vnl), (yyvsp[(3) - (3)].vn)); }
    break;

  case 14:
#line 140 "pascal.y"
    { (yyval.vnl) = insert_var_name_list(NULL, (yyvsp[(1) - (1)].vn)); }
    break;

  case 15:
#line 146 "pascal.y"
    { (yyval.fl) = insert_function_list((yyvsp[(1) - (2)].fl), (yyvsp[(2) - (2)].f)); }
    break;

  case 16:
#line 147 "pascal.y"
    { (yyval.fl) = insert_function_list(NULL, (yyvsp[(1) - (1)].f)); }
    break;

  case 17:
#line 151 "pascal.y"
    { (yyval.f) = insert_function((yyvsp[(2) - (14)].vn), (yyvsp[(4) - (14)].fal), (yyvsp[(7) - (14)].fr), (yyvsp[(10) - (14)].vdp), (yyvsp[(12) - (14)].sp), line_number); }
    break;

  case 18:
#line 152 "pascal.y"
    { (yyval.f) = insert_function((yyvsp[(2) - (12)].vn), (yyvsp[(4) - (12)].fal), (yyvsp[(7) - (12)].fr), NULL, (yyvsp[(10) - (12)].sp), line_number); }
    break;

  case 19:
#line 156 "pascal.y"
    { (yyval.fal) = insert_function_argument_list((yyvsp[(1) - (3)].fal), (yyvsp[(3) - (3)].fa)); }
    break;

  case 20:
#line 157 "pascal.y"
    { (yyval.fal) = insert_function_argument_list(NULL, (yyvsp[(1) - (1)].fa)); }
    break;

  case 21:
#line 158 "pascal.y"
    { (yyval.fal) = NULL; }
    break;

  case 22:
#line 162 "pascal.y"
    { (yyval.fa) = insert_function_argument((yyvsp[(1) - (3)].vnl), (yyvsp[(3) - (3)].fr), line_number); }
    break;

  case 23:
#line 166 "pascal.y"
    { (yyval.fr) = d_INTEGER; }
    break;

  case 24:
#line 167 "pascal.y"
    { (yyval.fr) = d_REAL; }
    break;

  case 25:
#line 168 "pascal.y"
    { (yyval.fr) = d_BOOLEAN; }
    break;

  case 26:
#line 174 "pascal.y"
    { (yyval.sp) = insert_statement_list((yyvsp[(1) - (2)].sp), (yyvsp[(2) - (2)].st)); }
    break;

  case 27:
#line 175 "pascal.y"
    { (yyval.sp) = insert_statement_list(NULL, (yyvsp[(1) - (1)].st)); }
    break;

  case 28:
#line 179 "pascal.y"
    { (yyval.st) = insert_statement_while((yyvsp[(1) - (1)].whs)); }
    break;

  case 29:
#line 180 "pascal.y"
    { (yyval.st) = insert_statement_if((yyvsp[(1) - (1)].is)); }
    break;

  case 30:
#line 181 "pascal.y"
    { (yyval.st) = insert_statement_assignment((yyvsp[(1) - (1)].as)); }
    break;

  case 31:
#line 182 "pascal.y"
    { (yyval.st) = insert_statement_writeln((yyvsp[(1) - (1)].ws)); }
    break;

  case 32:
#line 188 "pascal.y"
    { (yyval.whs) = insert_while_statement((yyvsp[(2) - (7)].le), (yyvsp[(5) - (7)].sp)); }
    break;

  case 33:
#line 193 "pascal.y"
    { (yyval.is) = insert_if_statement_single_then((yyvsp[(2) - (4)].le), (yyvsp[(4) - (4)].st)); }
    break;

  case 34:
#line 194 "pascal.y"
    { (yyval.is) = insert_if_statement_list_then((yyvsp[(2) - (7)].le), (yyvsp[(5) - (7)].sp)); }
    break;

  case 35:
#line 197 "pascal.y"
    { (yyval.is) = insert_if_statement_single_then_single_else((yyvsp[(2) - (6)].le), (yyvsp[(4) - (6)].st), (yyvsp[(6) - (6)].st)); }
    break;

  case 36:
#line 198 "pascal.y"
    { (yyval.is) = insert_if_statement_single_then_list_else((yyvsp[(2) - (9)].le), (yyvsp[(4) - (9)].st), (yyvsp[(7) - (9)].sp)); }
    break;

  case 37:
#line 201 "pascal.y"
    { (yyval.is) = insert_if_statement_list_then_single_else((yyvsp[(2) - (9)].le), (yyvsp[(5) - (9)].sp), (yyvsp[(9) - (9)].st)); }
    break;

  case 38:
#line 202 "pascal.y"
    { (yyval.is) = insert_if_statement_list_then_list_else((yyvsp[(2) - (12)].le), (yyvsp[(5) - (12)].sp), (yyvsp[(10) - (12)].sp)); }
    break;

  case 39:
#line 206 "pascal.y"
    { (yyval.as) = insert_assignment_statement_expression((yyvsp[(1) - (4)].vn), (yyvsp[(3) - (4)].ex)); }
    break;

  case 40:
#line 210 "pascal.y"
    { (yyval.fc) = insert_function_call((yyvsp[(1) - (4)].vn), (yyvsp[(3) - (4)].fcal), line_number); }
    break;

  case 41:
#line 214 "pascal.y"
    { (yyval.fcal) = insert_function_call_argument_list((yyvsp[(1) - (3)].fcal), (yyvsp[(3) - (3)].ex)); }
    break;

  case 42:
#line 215 "pascal.y"
    { (yyval.fcal) = insert_function_call_argument_list(NULL, (yyvsp[(1) - (1)].ex)); }
    break;

  case 43:
#line 216 "pascal.y"
    { (yyval.fcal) = NULL; }
    break;

  case 44:
#line 220 "pascal.y"
    { (yyval.ws) = insert_writeln_statement((yyvsp[(3) - (5)].wal)); }
    break;

  case 45:
#line 224 "pascal.y"
    { (yyval.wal) = insert_writeln_argument_list((yyvsp[(1) - (3)].wal), (yyvsp[(3) - (3)].wa)); }
    break;

  case 46:
#line 225 "pascal.y"
    { (yyval.wal) = insert_writeln_argument_list(NULL, (yyvsp[(1) - (1)].wa)); }
    break;

  case 47:
#line 229 "pascal.y"
    { (yyval.wa) = insert_writeln_argument_string((yyvsp[(1) - (1)].s)); }
    break;

  case 48:
#line 230 "pascal.y"
    { (yyval.wa) = insert_writeln_argument_expression((yyvsp[(1) - (1)].ex)); }
    break;

  case 49:
#line 236 "pascal.y"
    { (yyval.le) = insert_logical_expression((yyvsp[(1) - (3)].le), (yyvsp[(3) - (3)].le), d_AND); }
    break;

  case 50:
#line 237 "pascal.y"
    { (yyval.le) = insert_logical_expression((yyvsp[(1) - (3)].le), (yyvsp[(3) - (3)].le), d_OR); }
    break;

  case 51:
#line 238 "pascal.y"
    { (yyval.le) = (yyvsp[(2) - (3)].le); }
    break;

  case 52:
#line 239 "pascal.y"
    { (yyval.le) = insert_logical_expression_internal((yyvsp[(1) - (1)].ile)); }
    break;

  case 53:
#line 243 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_EQUAL); }
    break;

  case 54:
#line 244 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_GT); }
    break;

  case 55:
#line 245 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_LT); }
    break;

  case 56:
#line 246 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_GE); }
    break;

  case 57:
#line 247 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_LE); }
    break;

  case 58:
#line 248 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_NOTEQUAL); }
    break;

  case 59:
#line 249 "pascal.y"
    { (yyval.ile) = insert_internal_logical_expression((yyvsp[(1) - (1)].ex), NULL, d_DUMMY); }
    break;

  case 60:
#line 253 "pascal.y"
    { (yyval.ex) = insert_operator((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_PLUS, line_number); }
    break;

  case 61:
#line 254 "pascal.y"
    { (yyval.ex) = insert_operator((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_MINUS, line_number); }
    break;

  case 62:
#line 255 "pascal.y"
    { (yyval.ex) = insert_operator((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_DIV, line_number); }
    break;

  case 63:
#line 256 "pascal.y"
    { (yyval.ex) = insert_operator((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_STAR, line_number); }
    break;

  case 64:
#line 257 "pascal.y"
    { (yyval.ex) = insert_operator((yyvsp[(1) - (3)].ex), (yyvsp[(3) - (3)].ex), d_MOD, line_number); }
    break;

  case 65:
#line 258 "pascal.y"
    { (yyval.ex) = (yyvsp[(2) - (3)].ex); }
    break;

  case 66:
#line 259 "pascal.y"
    { (yyval.ex) = insert_expression_digit_sequence((yyvsp[(1) - (1)].ds), line_number); }
    break;

  case 67:
#line 260 "pascal.y"
    { (yyval.ex) = insert_expression_var_name((yyvsp[(1) - (1)].vn), line_number); }
    break;

  case 68:
#line 261 "pascal.y"
    { (yyval.ex) = insert_expression_function_call((yyvsp[(1) - (1)].fc), line_number); }
    break;

  case 69:
#line 262 "pascal.y"
    { (yyval.ex) = (yyvsp[(1) - (1)].be); }
    break;

  case 70:
#line 266 "pascal.y"
    { (yyval.be) = insert_expression_bool(1, line_number); }
    break;

  case 71:
#line 267 "pascal.y"
    { (yyval.be) = insert_expression_bool(0, line_number); }
    break;

  case 72:
#line 273 "pascal.y"
    { (yyval.vn) = insert_var_name((yyvsp[(1) - (1)].identifier), line_number); }
    break;

  case 73:
#line 277 "pascal.y"
    { (yyval.ds) = insert_digit_sequence(-(yyvsp[(2) - (2)].digseq)); }
    break;

  case 74:
#line 278 "pascal.y"
    { (yyval.ds) = insert_digit_sequence((yyvsp[(1) - (1)].digseq)); }
    break;

  case 75:
#line 279 "pascal.y"
    { (yyval.ds) = insert_float_digit_sequence(-(yyvsp[(2) - (2)].fdigseq)); }
    break;

  case 76:
#line 280 "pascal.y"
    { (yyval.ds) = insert_float_digit_sequence((yyvsp[(1) - (1)].fdigseq)); }
    break;

  case 77:
#line 284 "pascal.y"
    { (yyval.s) = insert_string((yyvsp[(1) - (1)].string)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2004 "running/y.tab.c"
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


#line 287 "pascal.y"



int yyerror (char *error_message) {
    printf ("ERROR at line %u: %s!\n", line_number, error_message);
    return 0;
}


int main() {

    int errors = 0;
    line_number = 1;
    statement_id = 0;

    if(yyparse() == 0) {
        printf("Syntax...: 0 errors\n");

        errors = check_program(my_program);

        printf("Semantic.: %d %s\n", errors, errors == 1 ? "error" : "errors");

        //show_symbol_table();

        if (errors == 0) {
            translate_program(my_program);
        }

    }

    return 0;
}


