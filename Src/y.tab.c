/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "GoParser.y"

#include <stdlib.h>
#include <stdio.h>
#include "GoTree.h"
//Version 2.0
extern char *yytext;
extern char *last;
extern program *theprogram;
void yyerror (char const *s){
	fprintf(stderr,"Error: %s\n",s);
	exit(0);
}
int yylex();

/* Line 371 of yacc.c  */
#line 83 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tHEX = 258,
     tOCT = 259,
     tDEC = 260,
     tRUNE = 261,
     tBOOL = 262,
     INTERPRETEDSTRING = 263,
     RAWSTRING = 264,
     tIDENTIFIER = 265,
     tFLOAT = 266,
     tRUNES = 267,
     TRUE = 268,
     FALSE = 269,
     BREAK = 270,
     CASE = 271,
     CHAN = 272,
     CONST = 273,
     CONTINUE = 274,
     DEFAULT = 275,
     DEFER = 276,
     ELSE = 277,
     FALLTHROUGH = 278,
     FOR = 279,
     FUNC = 280,
     GO = 281,
     GOTO = 282,
     IF = 283,
     IMPORT = 284,
     INTERFACE = 285,
     MAP = 286,
     PACKAGE = 287,
     RANGE = 288,
     RETURN = 289,
     SELECT = 290,
     STRUCT = 291,
     SWITCH = 292,
     TYPE = 293,
     VAR = 294,
     INT = 295,
     PRINT = 296,
     FLOAT = 297,
     PRINTLN = 298,
     BOOL = 299,
     APPEND = 300,
     RUNE = 301,
     STRING = 302,
     SEMICOLON = 303,
     NEWLINE = 304,
     PLUS = 305,
     MINUS = 306,
     TIMES = 307,
     DIV = 308,
     MOD = 309,
     AMP = 310,
     PIPE = 311,
     CARAT = 312,
     COUT = 313,
     CIN = 314,
     AMPCARAT = 315,
     SELFPLUS = 316,
     SELFMINUS = 317,
     SELFTIMES = 318,
     SELFDIV = 319,
     SELFMOD = 320,
     AMPEQUALS = 321,
     PIPEEQUALS = 322,
     CARATEQUALS = 323,
     COUTEQUALS = 324,
     CINEQUALS = 325,
     WTF = 326,
     AND = 327,
     OR = 328,
     REDIRECT = 329,
     INCREMENT = 330,
     DECREMENT = 331,
     DOESEQUALS = 332,
     LT = 333,
     GT = 334,
     EQUALS = 335,
     NOT = 336,
     NEQ = 337,
     LE = 338,
     GE = 339,
     COMPAT = 340,
     ELLIPSIS = 341,
     LEFTPAREN = 342,
     RIGHTPAREN = 343,
     LEFTSQUARE = 344,
     RIGHTSQUARE = 345,
     LEFTBRACE = 346,
     RIGHTBRACE = 347,
     COMMA = 348,
     PERIOD = 349,
     FULLCOLON = 350,
     ESCAPEA = 351,
     ESCAPEB = 352,
     ESCAPEF = 353,
     ESCAPEV = 354,
     ESCAPESLASH = 355,
     ESCAPEAPOSTROPHE = 356,
     INVALID = 357
   };
#endif
/* Tokens.  */
#define tHEX 258
#define tOCT 259
#define tDEC 260
#define tRUNE 261
#define tBOOL 262
#define INTERPRETEDSTRING 263
#define RAWSTRING 264
#define tIDENTIFIER 265
#define tFLOAT 266
#define tRUNES 267
#define TRUE 268
#define FALSE 269
#define BREAK 270
#define CASE 271
#define CHAN 272
#define CONST 273
#define CONTINUE 274
#define DEFAULT 275
#define DEFER 276
#define ELSE 277
#define FALLTHROUGH 278
#define FOR 279
#define FUNC 280
#define GO 281
#define GOTO 282
#define IF 283
#define IMPORT 284
#define INTERFACE 285
#define MAP 286
#define PACKAGE 287
#define RANGE 288
#define RETURN 289
#define SELECT 290
#define STRUCT 291
#define SWITCH 292
#define TYPE 293
#define VAR 294
#define INT 295
#define PRINT 296
#define FLOAT 297
#define PRINTLN 298
#define BOOL 299
#define APPEND 300
#define RUNE 301
#define STRING 302
#define SEMICOLON 303
#define NEWLINE 304
#define PLUS 305
#define MINUS 306
#define TIMES 307
#define DIV 308
#define MOD 309
#define AMP 310
#define PIPE 311
#define CARAT 312
#define COUT 313
#define CIN 314
#define AMPCARAT 315
#define SELFPLUS 316
#define SELFMINUS 317
#define SELFTIMES 318
#define SELFDIV 319
#define SELFMOD 320
#define AMPEQUALS 321
#define PIPEEQUALS 322
#define CARATEQUALS 323
#define COUTEQUALS 324
#define CINEQUALS 325
#define WTF 326
#define AND 327
#define OR 328
#define REDIRECT 329
#define INCREMENT 330
#define DECREMENT 331
#define DOESEQUALS 332
#define LT 333
#define GT 334
#define EQUALS 335
#define NOT 336
#define NEQ 337
#define LE 338
#define GE 339
#define COMPAT 340
#define ELLIPSIS 341
#define LEFTPAREN 342
#define RIGHTPAREN 343
#define LEFTSQUARE 344
#define RIGHTSQUARE 345
#define LEFTBRACE 346
#define RIGHTBRACE 347
#define COMMA 348
#define PERIOD 349
#define FULLCOLON 350
#define ESCAPEA 351
#define ESCAPEB 352
#define ESCAPEF 353
#define ESCAPEV 354
#define ESCAPESLASH 355
#define ESCAPEAPOSTROPHE 356
#define INVALID 357



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "GoParser.y"

int intconst;
char *stringconst;
char charconst;
float floatconst;
struct program *program;
struct package *package;
struct decList *decList;
struct dec *dec;
struct varDec *varDec;
struct varList *varList;
struct var *var;
struct identifierList *identifierList;
struct structList *structList;
struct typeDec *typeDec;
struct typeLineList *typeLineList;
struct typeLine *typeLine;
struct funcDec *funcDec;
struct param *param;
struct paramList *paramList;
struct block *block;
struct statementList *statementList;
struct statement *statement;
struct simpleStatement *simpleStatement;
struct assignment *assignment;
struct incDecStmt *incDecStmt;
struct print *print;
struct returning *returning;
struct ifStmt *ifStmt;
struct forLoop *forLoop;
struct switchStmt *switchStmt;
struct caseList *caseList;
struct caseFall *caseFall;
struct stmtExp *stmtExp;
struct condition *condition;
struct selfOp *selfOp;
struct type *type;
struct expList *expList;
struct exp *exp;
struct addOp *addOp;
struct mulOp *mulOp;
struct factor *factor;
struct structType *structType;


/* Line 387 of yacc.c  */
#line 376 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 404 "y.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   983

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNRULES -- Number of states.  */
#define YYNSTATES  322

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    14,    17,    20,    22,
      25,    30,    33,    37,    40,    43,    47,    52,    57,    60,
      65,    68,    72,    77,    81,    84,    88,    91,    94,    99,
     106,   113,   122,   128,   136,   144,   150,   157,   162,   163,
     166,   171,   175,   179,   181,   182,   185,   188,   190,   192,
     194,   197,   199,   202,   205,   208,   211,   216,   220,   225,
     234,   242,   245,   248,   250,   254,   262,   271,   280,   287,
     295,   303,   306,   310,   316,   322,   327,   332,   333,   335,
     337,   341,   343,   346,   349,   351,   355,   357,   359,   361,
     363,   365,   367,   369,   371,   373,   375,   377,   381,   385,
     387,   389,   391,   393,   395,   397,   401,   406,   411,   416,
     420,   425,   430,   435,   437,   439,   443,   447,   451,   455,
     459,   463,   467,   471,   475,   477,   481,   485,   489,   493,
     495,   499,   503,   507,   511,   515,   519,   523,   525,   528,
     531,   534,   537,   540,   543,   545,   547,   549,   551,   553,
     555,   557,   559,   561,   566,   570,   577,   582,   586,   588,
     590,   595
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   105,   106,    -1,    32,    10,    48,    -1,
     107,   106,    -1,    -1,   108,    48,    -1,   111,    48,    -1,
     127,    -1,    39,   110,    -1,    39,    87,   109,    88,    -1,
     110,    48,    -1,   110,    48,   109,    -1,   132,   136,    -1,
     132,    10,    -1,   132,    80,   137,    -1,   132,   136,    80,
     137,    -1,   132,    10,    80,   137,    -1,    38,   115,    -1,
      38,    87,   112,    88,    -1,   115,    48,    -1,   115,    48,
     112,    -1,    36,    91,   114,    92,    -1,    36,    91,    92,
      -1,   125,    48,    -1,   125,    48,   114,    -1,    10,   136,
      -1,    10,    10,    -1,    28,   121,   120,    48,    -1,    28,
     130,    48,   121,   120,    48,    -1,    28,   121,   120,    22,
     120,    48,    -1,    28,   130,    48,   121,   120,    22,   120,
      48,    -1,    28,   121,   120,    22,   116,    -1,    28,   130,
      48,   121,   120,    22,   116,    -1,    37,   130,    48,   138,
      91,   118,    92,    -1,    37,   138,    91,   118,    92,    -1,
      37,   130,    48,    91,   118,    92,    -1,    37,    91,   118,
      92,    -1,    -1,   119,   118,    -1,    16,   137,    95,   122,
      -1,    20,    95,   122,    -1,    91,   122,    92,    -1,   138,
      -1,    -1,   123,   122,    -1,   130,    48,    -1,   129,    -1,
     128,    -1,   116,    -1,   117,    48,    -1,   124,    -1,    15,
      48,    -1,    19,    48,    -1,   108,    48,    -1,   111,    48,
      -1,    91,   122,    92,    48,    -1,    24,   120,    48,    -1,
      24,   121,   120,    48,    -1,    24,   130,    48,   121,    48,
     130,   120,    48,    -1,    24,   130,    48,    48,   130,   120,
      48,    -1,   132,   136,    -1,   132,    10,    -1,   125,    -1,
     125,    93,   126,    -1,    25,    10,    87,   126,    88,   120,
      48,    -1,    25,    10,    87,   126,    88,   136,   120,    48,
      -1,    25,    10,    87,   126,    88,    10,   120,    48,    -1,
      25,    10,    87,    88,   120,    48,    -1,    25,    10,    87,
      88,   136,   120,    48,    -1,    25,    10,    87,    88,    10,
     120,    48,    -1,    34,    48,    -1,    34,   138,    48,    -1,
      41,    87,   137,    88,    48,    -1,    43,    87,   137,    88,
      48,    -1,    41,    87,    88,    48,    -1,    43,    87,    88,
      48,    -1,    -1,   134,    -1,   131,    -1,   137,    85,   137,
      -1,   135,    -1,   138,    75,    -1,   138,    76,    -1,    10,
      -1,    10,    93,   132,    -1,    61,    -1,    62,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    71,    -1,   137,    80,   137,
      -1,   138,   133,   138,    -1,   138,    -1,    40,    -1,    42,
      -1,    47,    -1,    46,    -1,    44,    -1,    89,    90,   136,
      -1,    89,     5,    90,   136,    -1,    89,     4,    90,   136,
      -1,    89,     3,    90,   136,    -1,    89,    90,    10,    -1,
      89,     5,    90,    10,    -1,    89,     4,    90,    10,    -1,
      89,     3,    90,    10,    -1,   113,    -1,   138,    -1,   138,
      93,   137,    -1,   138,    73,   138,    -1,   138,    72,   138,
      -1,   138,    77,   138,    -1,   138,    82,   138,    -1,   138,
      79,   138,    -1,   138,    84,   138,    -1,   138,    78,   138,
      -1,   138,    83,   138,    -1,   139,    -1,   139,    50,   139,
      -1,   139,    51,   139,    -1,   139,    56,   139,    -1,   139,
      57,   139,    -1,   140,    -1,   140,    52,   140,    -1,   140,
      53,   140,    -1,   140,    54,   140,    -1,   140,    58,   140,
      -1,   140,    59,   140,    -1,   140,    55,   140,    -1,   140,
      60,   140,    -1,   141,    -1,    50,   142,    -1,    51,   142,
      -1,    81,   142,    -1,    57,   142,    -1,    52,   142,    -1,
      55,   142,    -1,   142,    -1,    10,    -1,     5,    -1,    11,
      -1,     4,    -1,     3,    -1,     6,    -1,     8,    -1,     9,
      -1,   142,    87,   137,    88,    -1,   142,    87,    88,    -1,
      45,    87,    10,    93,   138,    88,    -1,   136,    87,   138,
      88,    -1,    87,   138,    88,    -1,    13,    -1,    14,    -1,
     142,    89,   138,    90,    -1,   142,    94,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   123,   127,   128,   131,   132,   133,   135,
     136,   140,   141,   144,   145,   146,   147,   148,   151,   152,
     156,   157,   160,   161,   163,   164,   167,   168,   175,   176,
     177,   178,   179,   180,   183,   184,   185,   186,   189,   190,
     193,   194,   197,   200,   203,   204,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   220,   221,   222,
     223,   227,   228,   231,   232,   235,   236,   237,   238,   239,
     240,   243,   244,   247,   248,   249,   250,   253,   254,   255,
     256,   257,   260,   261,   264,   265,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   281,   282,   285,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   305,   306,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   320,   321,   322,   323,   324,
     326,   327,   328,   329,   330,   331,   332,   333,   335,   336,
     337,   338,   339,   340,   341,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tHEX", "tOCT", "tDEC", "tRUNE", "tBOOL",
  "INTERPRETEDSTRING", "RAWSTRING", "tIDENTIFIER", "tFLOAT", "tRUNES",
  "TRUE", "FALSE", "BREAK", "CASE", "CHAN", "CONST", "CONTINUE", "DEFAULT",
  "DEFER", "ELSE", "FALLTHROUGH", "FOR", "FUNC", "GO", "GOTO", "IF",
  "IMPORT", "INTERFACE", "MAP", "PACKAGE", "RANGE", "RETURN", "SELECT",
  "STRUCT", "SWITCH", "TYPE", "VAR", "INT", "PRINT", "FLOAT", "PRINTLN",
  "BOOL", "APPEND", "RUNE", "STRING", "SEMICOLON", "NEWLINE", "PLUS",
  "MINUS", "TIMES", "DIV", "MOD", "AMP", "PIPE", "CARAT", "COUT", "CIN",
  "AMPCARAT", "SELFPLUS", "SELFMINUS", "SELFTIMES", "SELFDIV", "SELFMOD",
  "AMPEQUALS", "PIPEEQUALS", "CARATEQUALS", "COUTEQUALS", "CINEQUALS",
  "WTF", "AND", "OR", "REDIRECT", "INCREMENT", "DECREMENT", "DOESEQUALS",
  "LT", "GT", "EQUALS", "NOT", "NEQ", "LE", "GE", "COMPAT", "ELLIPSIS",
  "LEFTPAREN", "RIGHTPAREN", "LEFTSQUARE", "RIGHTSQUARE", "LEFTBRACE",
  "RIGHTBRACE", "COMMA", "PERIOD", "FULLCOLON", "ESCAPEA", "ESCAPEB",
  "ESCAPEF", "ESCAPEV", "ESCAPESLASH", "ESCAPEAPOSTROPHE", "INVALID",
  "$accept", "program", "package", "decList", "dec", "varDec", "varList",
  "var", "typeDec", "typeLineList", "structType", "structList", "typeLine",
  "ifStmt", "switchStmt", "caseList", "case", "block", "condition",
  "statementList", "statement", "forLoop", "param", "paramList", "funcDec",
  "return", "print", "simpleStatement", "incDecStmt", "identifierList",
  "selfOp", "assignment", "stmtExp", "type", "expList", "exp", "addOp",
  "mulOp", "factor", "simple_term", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   105,   106,   106,   107,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   121,   122,   122,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   128,   128,   129,   129,   129,   129,   130,   130,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     2,     1,     2,
       4,     2,     3,     2,     2,     3,     4,     4,     2,     4,
       2,     3,     4,     3,     2,     3,     2,     2,     4,     6,
       6,     8,     5,     7,     7,     5,     6,     4,     0,     2,
       4,     3,     3,     1,     0,     2,     2,     1,     1,     1,
       2,     1,     2,     2,     2,     2,     4,     3,     4,     8,
       7,     2,     2,     1,     3,     7,     8,     8,     6,     7,
       7,     2,     3,     5,     5,     4,     4,     0,     1,     1,
       3,     1,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     4,     3,
       4,     4,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     6,     4,     3,     1,     1,
       4,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,     0,     0,     0,     2,
       5,     0,     0,     8,     3,     0,     0,     0,    18,    84,
       0,     9,     0,     4,     6,     7,     0,    27,     0,   100,
     101,   104,   103,   102,     0,   113,    26,     0,     0,     0,
       0,     0,    14,     0,    13,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    19,    20,    85,    10,    11,     0,
     149,   148,   146,   150,   151,   152,   145,   147,   158,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
     114,   124,   129,   137,   144,     0,     0,    44,     0,     0,
       0,     0,    62,    61,    23,     0,     0,     0,     0,     0,
     109,   105,    21,    12,    17,     0,   138,   139,   142,   143,
     141,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,    77,    77,     0,    77,     0,     0,    44,     0,     0,
      49,     0,     0,    44,    51,    48,    47,     0,    79,    78,
      81,     0,    99,    68,     0,    64,     0,     0,     0,    22,
      24,   112,   108,   111,   107,   110,   106,     0,   157,     0,
     117,   116,   118,   122,   120,   119,   123,   121,   115,   125,
     126,   127,   128,   130,   131,   132,   135,   133,   134,   136,
     154,     0,     0,   161,    70,    52,    53,     0,     0,     0,
     114,     0,     0,    71,     0,    38,     0,   114,     0,     0,
       0,    54,    55,    50,    42,    45,    46,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      82,    83,     0,    69,     0,    65,     0,    25,     0,   156,
     153,   160,    57,     0,     0,     0,     0,    72,     0,     0,
       0,    38,     0,    38,     0,     0,     0,     0,     0,    97,
      80,    98,    67,    66,     0,    58,    77,     0,    43,     0,
      28,     0,     0,    44,    37,    39,    38,     0,     0,    75,
       0,    76,     0,    56,   155,     0,    77,    32,     0,     0,
      44,    41,     0,    38,    35,    73,    74,     0,     0,    30,
       0,    29,    40,    36,     0,    60,     0,    33,     0,    34,
      59,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,   148,    40,    41,   149,    37,
      35,    95,    38,   150,   151,   260,   261,    88,   208,   152,
     153,   154,    46,    47,    13,   155,   156,   157,   158,    48,
     242,   159,   160,    78,   161,    80,    81,    82,    83,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -262
static const yytype_int16 yypact[] =
{
     -13,    18,    32,    -2,    15,  -262,    41,    10,    11,  -262,
      -2,    16,    22,  -262,  -262,   -11,   122,    64,  -262,    -7,
      78,  -262,   108,  -262,  -262,  -262,     1,  -262,     0,  -262,
    -262,  -262,  -262,  -262,    12,  -262,  -262,     8,    55,    78,
      24,    56,    34,   726,    39,    37,    27,    33,   160,     3,
      40,    44,    46,   321,  -262,    64,  -262,  -262,    78,   726,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
      36,   781,   781,   781,   781,   781,   781,   726,    58,  -262,
     228,    60,   689,  -262,   -60,   726,    48,   227,    76,    48,
      78,    91,  -262,  -262,  -262,    50,    95,   377,   433,   489,
    -262,  -262,  -262,  -262,  -262,   136,   -60,   -60,   -60,   -60,
     -60,   -60,   874,   726,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   726,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   726,   451,   726,   137,  -262,   101,   103,
     105,   283,   726,   506,   339,    69,    72,   227,   112,   115,
    -262,   117,    79,   227,  -262,  -262,  -262,   124,  -262,  -262,
    -262,   -32,   843,  -262,   126,  -262,    48,   138,    48,  -262,
      78,  -262,  -262,  -262,  -262,  -262,  -262,    90,  -262,   882,
     135,   611,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,    96,   860,  -262,  -262,  -262,  -262,   143,    48,   144,
     768,    48,   146,  -262,   175,    45,   155,   810,   561,   616,
      93,  -262,  -262,  -262,  -262,  -262,  -262,   726,   726,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   726,  -262,   157,  -262,   162,  -262,   726,  -262,
    -262,  -262,  -262,   167,   671,     2,   726,  -262,   726,   121,
     128,    45,   395,    45,   178,   139,   180,   151,   186,  -262,
    -262,   562,  -262,  -262,   895,  -262,   726,   195,   562,    -6,
    -262,    48,   149,   227,  -262,  -262,    45,   507,   153,  -262,
     202,  -262,   208,  -262,  -262,    48,   726,  -262,   212,     4,
     227,  -262,   170,    45,  -262,  -262,  -262,   232,    48,  -262,
      -6,  -262,  -262,  -262,   184,  -262,   233,  -262,   235,  -262,
    -262,  -262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,  -262,  -262,   275,  -262,    84,   237,   282,    89,   243,
    -262,   129,   295,  -261,  -262,  -228,  -262,   -86,  -141,  -143,
    -262,  -262,   -41,   213,  -262,  -262,  -262,  -135,  -262,    51,
    -262,  -262,  -262,     9,   -29,   -75,    52,   669,  -262,   791
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -115
static const yytype_int16 yytable[] =
{
     138,   211,   112,   164,   220,   167,   209,   212,    96,   216,
     225,    19,   162,    19,    79,    50,    51,    52,   297,     1,
      16,    19,   142,     6,   279,    36,   310,   134,     4,   135,
     104,    44,     5,   285,   136,   288,     7,     8,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    86,   227,   317,
     280,    15,   311,   228,    89,   207,   137,    93,   302,    22,
     202,   258,   101,    14,    24,   259,   210,   210,   214,   217,
      25,    22,   162,    28,    16,   314,    26,    29,   162,    30,
     244,    31,   246,    32,    33,    87,    39,    11,    19,    45,
      56,    49,    12,   188,    11,    94,    54,    17,    20,    12,
     168,   166,    53,    55,    58,   201,   172,   174,   176,    22,
     123,   124,    57,   277,    59,   281,   125,   126,    42,    85,
      90,    91,   253,   105,   163,   255,    34,    28,    87,    96,
      97,    29,    27,    30,    98,    31,    99,    32,    33,    87,
     301,   295,   169,   170,    28,   113,   177,   203,    29,   204,
      30,   205,    31,   206,    32,    33,   218,   312,    28,   219,
     221,   308,    29,   222,    30,   223,    31,   271,    32,    33,
      92,   224,   226,   274,   243,   189,   190,   191,   192,   278,
      34,   278,    87,   248,   250,   268,   245,   287,    43,   265,
     267,   252,   254,   298,   256,   299,    28,    34,   269,   270,
      29,   162,    30,   262,    31,   272,    32,    33,   162,   307,
     273,    34,   116,   117,   118,   275,   283,   119,   120,   121,
     284,   162,   316,   257,   318,   162,   289,   290,   291,   282,
      60,    61,    62,    63,   293,    64,    65,    66,    67,   292,
      68,    69,   139,   296,   300,   304,   140,   114,   115,    34,
     305,   141,   116,   117,   118,   142,   306,   119,   120,   121,
     309,   143,   313,    28,   144,     7,     8,    29,   145,    30,
     146,    31,    70,    32,    33,   -77,   319,    71,    72,    73,
     315,   320,    74,   321,    75,    23,    60,    61,    62,    63,
      21,    64,    65,    66,    67,   103,    68,    69,   102,   247,
     114,   115,    18,   165,     0,   116,   117,   118,    76,     0,
     119,   120,   121,     0,    77,     0,    34,     0,   147,    28,
       0,   122,     0,    29,     0,    30,     0,    31,    70,    32,
      33,   100,     0,    71,    72,    73,     0,     0,    74,     0,
      75,     0,    60,    61,    62,    63,     0,    64,    65,    66,
      67,     0,    68,    69,     0,     0,     0,    28,     0,     0,
       0,    29,     0,    30,    76,    31,     0,    32,    33,     0,
      77,     0,    34,     0,    87,    28,     0,     0,     0,    29,
       0,    30,     0,    31,    70,    32,    33,   171,     0,    71,
      72,    73,     0,     0,    74,     0,    75,     0,    60,    61,
      62,    63,     0,    64,    65,    66,    67,     0,    68,    69,
      34,     0,     0,    28,     0,     0,     0,    29,     0,    30,
      76,    31,     0,    32,    33,     0,    77,     0,    34,     0,
     215,    28,     0,     0,     0,    29,     0,    30,     0,    31,
      70,    32,    33,   173,     0,    71,    72,    73,     0,     0,
      74,     0,    75,     0,    60,    61,    62,    63,     0,    64,
      65,    66,    67,     0,    68,    69,    34,     0,     0,    28,
       0,     0,     0,    29,     0,    30,    76,    31,     0,    32,
      33,     0,    77,     0,    34,     0,   286,    28,     0,     0,
       0,    29,     0,    30,     0,    31,    70,    32,    33,   175,
       0,    71,    72,    73,     0,     0,    74,     0,    75,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,    68,
      69,     0,    34,     0,     0,    28,     0,     0,     0,    29,
       0,    30,    76,    31,     0,    32,    33,     0,    77,   200,
      34,     0,    28,     0,     0,     0,    29,     0,    30,     0,
      31,    70,    32,    33,   213,     0,    71,    72,    73,     0,
       0,    74,     0,    75,    60,    61,    62,    63,     0,    64,
      65,    66,    67,     0,    68,    69,     0,     0,    34,   114,
     115,     0,     0,     0,   116,   117,   118,    76,     0,   119,
     120,   121,     0,    77,     0,    34,     0,    28,   303,     0,
       0,    29,     0,    30,     0,    31,    70,    32,    33,     0,
       0,    71,    72,    73,     0,     0,    74,     0,    75,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,    68,
      69,     0,     0,     0,   114,   115,     0,     0,     0,   116,
     117,   118,    76,     0,   119,   120,   121,     0,    77,   264,
      34,     0,    28,     0,     0,     0,    29,     0,    30,     0,
      31,    70,    32,    33,     0,     0,    71,    72,    73,     0,
       0,    74,     0,    75,    60,    61,    62,    63,     0,    64,
      65,    66,    67,   114,    68,    69,     0,     0,   116,   117,
     118,     0,     0,   119,   120,   121,     0,    76,     0,     0,
       0,     0,     0,    77,   266,    34,     0,    28,     0,     0,
       0,    29,     0,    30,     0,    31,    70,    32,    33,   276,
       0,    71,    72,    73,     0,     0,    74,     0,    75,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,    68,
      69,   127,   128,   129,   130,     0,     0,   131,   132,   133,
       0,     0,    76,     0,     0,     0,     0,     0,    77,     0,
      34,     0,    28,     0,     0,     0,    29,     0,    30,     0,
      31,    70,    32,    33,     0,     0,    71,    72,    73,     0,
       0,    74,     0,    75,    60,    61,    62,    63,     0,    64,
      65,    66,    67,     0,    68,    69,   193,   194,   195,   196,
     197,   198,   199,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,    77,     0,    34,   -99,    28,     0,     0,
       0,    29,     0,    30,     0,    31,    70,    32,    33,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     114,   115,     0,   240,   241,   116,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,     0,     0,   -99,   -43,
       0,   122,   106,   107,   108,   109,   110,   111,    77,     0,
      34,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   114,   115,     0,   240,   241,   116,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,     0,     0,
       0,   263,     0,   122,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   114,   115,     0,   240,   241,
     116,   117,   118,  -114,     0,   119,   120,   121,  -114,     0,
       0,     0,   114,   115,     0,     0,   122,   116,   117,   118,
       0,     0,   119,   120,   121,     0,   114,   115,     0,     0,
     251,   116,   117,   118,   114,   115,   119,   120,   121,   116,
     117,   118,   178,     0,   119,   120,   121,   114,   115,     0,
     249,     0,   116,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   294
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-262)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      86,   142,    77,    89,   147,    91,   141,   142,    49,   144,
     153,    10,    87,    10,    43,     3,     4,     5,   279,    32,
      10,    10,    28,    25,    22,    16,    22,    87,    10,    89,
      59,    22,     0,   261,    94,   263,    38,    39,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    10,    80,   310,
      48,    10,    48,    85,    45,   141,    85,    48,   286,     8,
     135,    16,    53,    48,    48,    20,   141,   142,   143,   144,
      48,    20,   147,    36,    10,   303,    87,    40,   153,    42,
     166,    44,   168,    46,    47,    91,    93,     3,    10,    88,
      39,    91,     3,   122,    10,    92,    88,    87,    87,    10,
      91,    10,    90,    48,    48,   134,    97,    98,    99,    58,
      50,    51,    88,   254,    80,   256,    56,    57,    10,    80,
      93,    88,   208,    87,    48,   211,    89,    36,    91,   170,
      90,    40,    10,    42,    90,    44,    90,    46,    47,    91,
     283,   276,    92,    48,    36,    87,    10,    10,    40,    48,
      42,    48,    44,    48,    46,    47,    87,   300,    36,    87,
      48,   296,    40,    48,    42,    48,    44,   242,    46,    47,
      10,    92,    48,   248,    48,   123,   124,   125,   126,   254,
      89,   256,    91,    93,    88,    92,    48,   262,    80,   218,
     219,    48,    48,   279,    48,   281,    36,    89,   227,   228,
      40,   276,    42,    48,    44,    48,    46,    47,   283,   295,
      48,    89,    77,    78,    79,    48,    95,    82,    83,    84,
      92,   296,   308,    48,   310,   300,    48,    88,    48,   258,
       3,     4,     5,     6,    48,     8,     9,    10,    11,    88,
      13,    14,    15,    48,    95,    92,    19,    72,    73,    89,
      48,    24,    77,    78,    79,    28,    48,    82,    83,    84,
      48,    34,    92,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    92,    50,    51,    52,
      48,    48,    55,    48,    57,    10,     3,     4,     5,     6,
       8,     8,     9,    10,    11,    58,    13,    14,    55,   170,
      72,    73,     7,    90,    -1,    77,    78,    79,    81,    -1,
      82,    83,    84,    -1,    87,    -1,    89,    -1,    91,    36,
      -1,    93,    -1,    40,    -1,    42,    -1,    44,    45,    46,
      47,    10,    -1,    50,    51,    52,    -1,    -1,    55,    -1,
      57,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    13,    14,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    -1,    42,    81,    44,    -1,    46,    47,    -1,
      87,    -1,    89,    -1,    91,    36,    -1,    -1,    -1,    40,
      -1,    42,    -1,    44,    45,    46,    47,    10,    -1,    50,
      51,    52,    -1,    -1,    55,    -1,    57,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    13,    14,
      89,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    42,
      81,    44,    -1,    46,    47,    -1,    87,    -1,    89,    -1,
      91,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,
      45,    46,    47,    10,    -1,    50,    51,    52,    -1,    -1,
      55,    -1,    57,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    13,    14,    89,    -1,    -1,    36,
      -1,    -1,    -1,    40,    -1,    42,    81,    44,    -1,    46,
      47,    -1,    87,    -1,    89,    -1,    91,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    44,    45,    46,    47,    10,
      -1,    50,    51,    52,    -1,    -1,    55,    -1,    57,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    13,
      14,    -1,    89,    -1,    -1,    36,    -1,    -1,    -1,    40,
      -1,    42,    81,    44,    -1,    46,    47,    -1,    87,    88,
      89,    -1,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    -1,
      -1,    55,    -1,    57,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    13,    14,    -1,    -1,    89,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    81,    -1,    82,
      83,    84,    -1,    87,    -1,    89,    -1,    36,    91,    -1,
      -1,    40,    -1,    42,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    51,    52,    -1,    -1,    55,    -1,    57,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    13,
      14,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,
      78,    79,    81,    -1,    82,    83,    84,    -1,    87,    88,
      89,    -1,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    51,    52,    -1,
      -1,    55,    -1,    57,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    72,    13,    14,    -1,    -1,    77,    78,
      79,    -1,    -1,    82,    83,    84,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    -1,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    -1,    -1,    55,    -1,    57,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    13,
      14,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      89,    -1,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    51,    52,    -1,
      -1,    55,    -1,    57,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    13,    14,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    89,    48,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    44,    45,    46,    47,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    48,    91,
      -1,    93,    71,    72,    73,    74,    75,    76,    87,    -1,
      89,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    72,    73,    -1,    -1,    93,    77,    78,    79,
      -1,    -1,    82,    83,    84,    -1,    72,    73,    -1,    -1,
      90,    77,    78,    79,    72,    73,    82,    83,    84,    77,
      78,    79,    88,    -1,    82,    83,    84,    72,    73,    -1,
      88,    -1,    77,    78,    79,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,   104,   105,    10,     0,    25,    38,    39,   106,
     107,   108,   111,   127,    48,    10,    10,    87,   115,    10,
      87,   110,   132,   106,    48,    48,    87,    10,    36,    40,
      42,    44,    46,    47,    89,   113,   136,   112,   115,    93,
     109,   110,    10,    80,   136,    88,   125,   126,   132,    91,
       3,     4,     5,    90,    88,    48,   132,    88,    48,    80,
       3,     4,     5,     6,     8,     9,    10,    11,    13,    14,
      45,    50,    51,    52,    55,    57,    81,    87,   136,   137,
     138,   139,   140,   141,   142,    80,    10,    91,   120,   136,
      93,    88,    10,   136,    92,   114,   125,    90,    90,    90,
      10,   136,   112,   109,   137,    87,   142,   142,   142,   142,
     142,   142,   138,    87,    72,    73,    77,    78,    79,    82,
      83,    84,    93,    50,    51,    56,    57,    52,    53,    54,
      55,    58,    59,    60,    87,    89,    94,   137,   120,    15,
      19,    24,    28,    34,    37,    41,    43,    91,   108,   111,
     116,   117,   122,   123,   124,   128,   129,   130,   131,   134,
     135,   137,   138,    48,   120,   126,    10,   120,   136,    92,
      48,    10,   136,    10,   136,    10,   136,    10,    88,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   137,   139,
     139,   139,   139,   140,   140,   140,   140,   140,   140,   140,
      88,   137,   138,    10,    48,    48,    48,   120,   121,   130,
     138,   121,   130,    48,   138,    91,   130,   138,    87,    87,
     122,    48,    48,    48,    92,   122,    48,    80,    85,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      75,    76,   133,    48,   120,    48,   120,   114,    93,    88,
      88,    90,    48,   120,    48,   120,    48,    48,    16,    20,
     118,   119,    48,    91,    88,   137,    88,   137,    92,   137,
     137,   138,    48,    48,   138,    48,    48,   121,   138,    22,
      48,   121,   137,    95,    92,   118,    91,   138,   118,    48,
      88,    48,    88,    48,    88,   130,    48,   116,   120,   120,
      95,   122,   118,    91,    92,    48,    48,   120,   130,    48,
      22,    48,   122,    92,   118,    48,   120,   116,   120,    92,
      48,    48
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1787 of yacc.c  */
#line 120 "GoParser.y"
    { theprogram = makeprogram ((yyvsp[(1) - (2)].package), (yyvsp[(2) - (2)].decList)); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 123 "GoParser.y"
    { (yyval.package) = makepackage ((yyvsp[(2) - (3)].stringconst)); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 127 "GoParser.y"
    { (yyval.decList) = makedecListfull ((yyvsp[(1) - (2)].dec), (yyvsp[(2) - (2)].decList)); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 128 "GoParser.y"
    { (yyval.decList) = makedecListempty (); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 131 "GoParser.y"
    { (yyval.dec) = makeVarDec ((yyvsp[(1) - (2)].varDec)); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 132 "GoParser.y"
    { (yyval.dec) = maketypeDec ((yyvsp[(1) - (2)].typeDec)); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 133 "GoParser.y"
    { (yyval.dec) = makefuncDec ((yyvsp[(1) - (1)].funcDec));  }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 135 "GoParser.y"
    { (yyval.varDec) = makeVarDecsingle ((yyvsp[(2) - (2)].var)); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 136 "GoParser.y"
    { (yyval.varDec) = makeVarDecdistributed ((yyvsp[(3) - (4)].varList)); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 140 "GoParser.y"
    { (yyval.varList) = makeVarListbase ((yyvsp[(1) - (2)].var)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 141 "GoParser.y"
    { (yyval.varList) = makeVarListrecurse ((yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].varList)); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 144 "GoParser.y"
    { (yyval.var) = makeVartype ((yyvsp[(1) - (2)].identifierList),(yyvsp[(2) - (2)].type)); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 145 "GoParser.y"
    { (yyval.var) = makeVarid((yyvsp[(1) - (2)].identifierList),(yyvsp[(2) - (2)].stringconst)); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 146 "GoParser.y"
    { (yyval.var) = makeVarEQ ((yyvsp[(1) - (3)].identifierList), (yyvsp[(3) - (3)].expList)); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 147 "GoParser.y"
    { (yyval.var) = makeVartypeEQ((yyvsp[(1) - (4)].identifierList), (yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expList)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 148 "GoParser.y"
    { (yyval.var) = makeVarIDEQ((yyvsp[(1) - (4)].identifierList), (yyvsp[(2) - (4)].stringconst), (yyvsp[(4) - (4)].expList)); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 151 "GoParser.y"
    { (yyval.typeDec) = maketypeDecsingle ((yyvsp[(2) - (2)].typeLine)); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 152 "GoParser.y"
    { (yyval.typeDec) = maketypeDecmany ((yyvsp[(3) - (4)].typeLineList)); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 156 "GoParser.y"
    { (yyval.typeLineList) = maketypeLineListsingle ((yyvsp[(1) - (2)].typeLine)); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 157 "GoParser.y"
    { (yyval.typeLineList) = maketypeLineListmany ((yyvsp[(1) - (3)].typeLine),(yyvsp[(3) - (3)].typeLineList)); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 160 "GoParser.y"
    { (yyval.structType) = makestructTypefull((yyvsp[(3) - (4)].structList)); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 161 "GoParser.y"
    { (yyval.structType) = makestructTypeempty(); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 163 "GoParser.y"
    {(yyval.structList)=makestructListsingle((yyvsp[(1) - (2)].param));}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 164 "GoParser.y"
    {(yyval.structList)=makestructListmany((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].structList));}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 167 "GoParser.y"
    { (yyval.typeLine) = maketypeLinesingle ((yyvsp[(1) - (2)].stringconst),(yyvsp[(2) - (2)].type)); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 168 "GoParser.y"
    {(yyval.typeLine)=maketypeLinesingleID((yyvsp[(1) - (2)].stringconst),(yyvsp[(2) - (2)].stringconst));}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 175 "GoParser.y"
    { (yyval.ifStmt) = makeif ((yyvsp[(2) - (4)].condition),(yyvsp[(3) - (4)].block));  }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 176 "GoParser.y"
    { (yyval.ifStmt) = makesimpleif ((yyvsp[(2) - (6)].simpleStatement), (yyvsp[(4) - (6)].condition), (yyvsp[(5) - (6)].block)); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 177 "GoParser.y"
    { (yyval.ifStmt) = makeifelse ((yyvsp[(2) - (6)].condition),(yyvsp[(3) - (6)].block),(yyvsp[(5) - (6)].block)); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 178 "GoParser.y"
    { (yyval.ifStmt) = makesimpleifelse ((yyvsp[(2) - (8)].simpleStatement), (yyvsp[(4) - (8)].condition), (yyvsp[(5) - (8)].block), (yyvsp[(7) - (8)].block)); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 179 "GoParser.y"
    { (yyval.ifStmt) = makeifelseif ((yyvsp[(2) - (5)].condition),(yyvsp[(3) - (5)].block),(yyvsp[(5) - (5)].ifStmt)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 180 "GoParser.y"
    { (yyval.ifStmt) = makesimpleifelseif ((yyvsp[(2) - (7)].simpleStatement), (yyvsp[(4) - (7)].condition), (yyvsp[(5) - (7)].block), (yyvsp[(7) - (7)].ifStmt)); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 183 "GoParser.y"
    { (yyval.switchStmt) = makeswitchleftright ((yyvsp[(2) - (7)].simpleStatement), (yyvsp[(4) - (7)].exp), (yyvsp[(6) - (7)].caseList)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 184 "GoParser.y"
    { (yyval.switchStmt) = makeswitchright ((yyvsp[(2) - (5)].exp),(yyvsp[(4) - (5)].caseList)); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 185 "GoParser.y"
    { (yyval.switchStmt) = makeswitchleft ((yyvsp[(2) - (6)].simpleStatement), (yyvsp[(5) - (6)].caseList)); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 186 "GoParser.y"
    { (yyval.switchStmt) = makeswitchnone ((yyvsp[(3) - (4)].caseList)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 189 "GoParser.y"
    { (yyval.caseList) = makecaseListempty (); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 190 "GoParser.y"
    { (yyval.caseList) = makecaseListfull ((yyvsp[(1) - (2)].caseFall), (yyvsp[(2) - (2)].caseList)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 193 "GoParser.y"
    { (yyval.caseFall) = makecasecase ((yyvsp[(2) - (4)].expList), (yyvsp[(4) - (4)].statementList)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 194 "GoParser.y"
    { (yyval.caseFall) = makecasedefault ((yyvsp[(3) - (3)].statementList)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 197 "GoParser.y"
    { (yyval.block) = makeblock ((yyvsp[(2) - (3)].statementList)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 200 "GoParser.y"
    { (yyval.condition) = makecondition ((yyvsp[(1) - (1)].exp)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 203 "GoParser.y"
    { (yyval.statementList) = makestatementListempty (); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 204 "GoParser.y"
    { (yyval.statementList) = makestatementListfull ((yyvsp[(1) - (2)].statement), (yyvsp[(2) - (2)].statementList)); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 207 "GoParser.y"
    {(yyval.statement) = makesimplestatement ((yyvsp[(1) - (2)].simpleStatement)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 208 "GoParser.y"
    {(yyval.statement) = makeprintstatement ((yyvsp[(1) - (1)].print)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 209 "GoParser.y"
    { (yyval.statement) = makestatementreturning ((yyvsp[(1) - (1)].returning)); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 210 "GoParser.y"
    { (yyval.statement) = makestatementif ((yyvsp[(1) - (1)].ifStmt)); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 211 "GoParser.y"
    { (yyval.statement) = makestatementswitch ((yyvsp[(1) - (2)].switchStmt)); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 212 "GoParser.y"
    { (yyval.statement) = makestatementfor ((yyvsp[(1) - (1)].forLoop)); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 213 "GoParser.y"
    { (yyval.statement) = makestatementbreak (); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 214 "GoParser.y"
    { (yyval.statement) = makestatementcontinue (); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 215 "GoParser.y"
    { (yyval.statement) = makestmtvardec((yyvsp[(1) - (2)].varDec)); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 216 "GoParser.y"
    { (yyval.statement) = makestmttypedec((yyvsp[(1) - (2)].typeDec)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 217 "GoParser.y"
    { (yyval.statement) = makestatementblock((yyvsp[(2) - (4)].statementList)); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 220 "GoParser.y"
    { (yyval.forLoop) = makefor ((yyvsp[(2) - (3)].block)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 221 "GoParser.y"
    { (yyval.forLoop) = makeforcond ((yyvsp[(2) - (4)].condition),(yyvsp[(3) - (4)].block)); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 222 "GoParser.y"
    { (yyval.forLoop) = makeforidcond ((yyvsp[(2) - (8)].simpleStatement), (yyvsp[(4) - (8)].condition), (yyvsp[(6) - (8)].simpleStatement), (yyvsp[(7) - (8)].block)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 223 "GoParser.y"
    { (yyval.forLoop) = makefornocond((yyvsp[(2) - (7)].simpleStatement),(yyvsp[(5) - (7)].simpleStatement),(yyvsp[(6) - (7)].block)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 227 "GoParser.y"
    { (yyval.param) = makeparam ((yyvsp[(1) - (2)].identifierList), (yyvsp[(2) - (2)].type)); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 228 "GoParser.y"
    {(yyval.param)=makeparamid((yyvsp[(1) - (2)].identifierList),(yyvsp[(2) - (2)].stringconst));}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 231 "GoParser.y"
    { (yyval.paramList) = makeparamListempty ((yyvsp[(1) - (1)].param)); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 232 "GoParser.y"
    { (yyval.paramList) = makeparamListfull ((yyvsp[(1) - (3)].param), (yyvsp[(3) - (3)].paramList)); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 235 "GoParser.y"
    { (yyval.funcDec) = makefuncDecless ((yyvsp[(2) - (7)].stringconst), (yyvsp[(4) - (7)].paramList), (yyvsp[(6) - (7)].block)); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 236 "GoParser.y"
    { (yyval.funcDec) = makefuncDecfull ((yyvsp[(2) - (8)].stringconst), (yyvsp[(4) - (8)].paramList), (yyvsp[(6) - (8)].type), (yyvsp[(7) - (8)].block)); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 237 "GoParser.y"
    {(yyval.funcDec)=makefuncDecid((yyvsp[(2) - (8)].stringconst),(yyvsp[(4) - (8)].paramList),(yyvsp[(6) - (8)].stringconst),(yyvsp[(7) - (8)].block));}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 238 "GoParser.y"
    { (yyval.funcDec) = makefuncDecnono ((yyvsp[(2) - (6)].stringconst), (yyvsp[(5) - (6)].block)); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 239 "GoParser.y"
    { (yyval.funcDec) = makefuncDecno ((yyvsp[(2) - (7)].stringconst), (yyvsp[(5) - (7)].type), (yyvsp[(6) - (7)].block)); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 240 "GoParser.y"
    {(yyval.funcDec)=makefuncDecnoid((yyvsp[(2) - (7)].stringconst),(yyvsp[(5) - (7)].stringconst),(yyvsp[(6) - (7)].block));}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 243 "GoParser.y"
    { (yyval.returning) = makereturnempty (); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 244 "GoParser.y"
    { (yyval.returning) = makereturnfull ((yyvsp[(2) - (3)].exp)); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 247 "GoParser.y"
    { (yyval.print) = makeprint ((yyvsp[(3) - (5)].expList)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 248 "GoParser.y"
    { (yyval.print) = makeprintln ((yyvsp[(3) - (5)].expList)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 249 "GoParser.y"
    { (yyval.print) = makeprintempty(); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 250 "GoParser.y"
    { (yyval.print) = makeprintlnempty(); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 253 "GoParser.y"
    { (yyval.simpleStatement) = makesimplestmtempty (); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 254 "GoParser.y"
    { (yyval.simpleStatement) = makesimplestmtassign ((yyvsp[(1) - (1)].assignment)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 255 "GoParser.y"
    { (yyval.simpleStatement) = makesimplestmtincDec ((yyvsp[(1) - (1)].incDecStmt)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 256 "GoParser.y"
    { (yyval.simpleStatement) = makesimplestmtshort ((yyvsp[(1) - (3)].expList), (yyvsp[(3) - (3)].expList)); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 257 "GoParser.y"
    { (yyval.simpleStatement) = makesimplestmtstmtexp ((yyvsp[(1) - (1)].stmtExp)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 260 "GoParser.y"
    { (yyval.incDecStmt) =  makeincDecup ((yyvsp[(1) - (2)].exp)); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 261 "GoParser.y"
    { (yyval.incDecStmt) = makeincDecdown ((yyvsp[(1) - (2)].exp)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 264 "GoParser.y"
    { (yyval.identifierList) = makeidListsingle ((yyvsp[(1) - (1)].stringconst)); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 265 "GoParser.y"
    { (yyval.identifierList) = makeidListmultiple ((yyvsp[(3) - (3)].identifierList), (yyvsp[(1) - (3)].stringconst)); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 268 "GoParser.y"
    { (yyval.selfOp) = makeselfplus (); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 269 "GoParser.y"
    { (yyval.selfOp) = makeselfminus (); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 270 "GoParser.y"
    { (yyval.selfOp) = makeselftimes (); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 271 "GoParser.y"
    { (yyval.selfOp) = makeselfdiv (); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 272 "GoParser.y"
    { (yyval.selfOp) = makeselfmod (); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 273 "GoParser.y"
    { (yyval.selfOp) = makeampequals (); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 274 "GoParser.y"
    { (yyval.selfOp) = makepipeequals (); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 275 "GoParser.y"
    { (yyval.selfOp) = makecaratequals (); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 276 "GoParser.y"
    { (yyval.selfOp) = makecoutequals (); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 277 "GoParser.y"
    { (yyval.selfOp) = makecinequals (); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 278 "GoParser.y"
    { (yyval.selfOp) = makewtf (); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 281 "GoParser.y"
    { (yyval.assignment) = makeassignmentlist ((yyvsp[(1) - (3)].expList), (yyvsp[(3) - (3)].expList)); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 282 "GoParser.y"
    { (yyval.assignment) = makeassignmentself ((yyvsp[(1) - (3)].exp), (yyvsp[(2) - (3)].selfOp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 285 "GoParser.y"
    { (yyval.stmtExp) = makestmtexp((yyvsp[(1) - (1)].exp)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 288 "GoParser.y"
    { (yyval.type) = makeint (); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 289 "GoParser.y"
    { (yyval.type) = makefloat (); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 290 "GoParser.y"
    { (yyval.type) = makestring (); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 291 "GoParser.y"
    { (yyval.type) = makerune (); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 292 "GoParser.y"
    { (yyval.type) = makebool (); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 293 "GoParser.y"
    { (yyval.type) = makeslice ((yyvsp[(3) - (3)].type)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 294 "GoParser.y"
    { (yyval.type) = makedec ((yyvsp[(2) - (4)].intconst),(yyvsp[(4) - (4)].type)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 295 "GoParser.y"
    { (yyval.type) = makeoct ((yyvsp[(2) - (4)].intconst),(yyvsp[(4) - (4)].type)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 296 "GoParser.y"
    { (yyval.type) = makehex ((yyvsp[(2) - (4)].intconst),(yyvsp[(4) - (4)].type)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 297 "GoParser.y"
    { (yyval.type) = makesliceID((yyvsp[(3) - (3)].stringconst)); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 298 "GoParser.y"
    { (yyval.type) = makedecID((yyvsp[(2) - (4)].intconst),(yyvsp[(4) - (4)].stringconst)); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 299 "GoParser.y"
    { (yyval.type) = makeoctID((yyvsp[(2) - (4)].intconst),(yyvsp[(4) - (4)].stringconst)); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 300 "GoParser.y"
    { (yyval.type) = makehexID((yyvsp[(2) - (4)].intconst),(yyvsp[(4) - (4)].stringconst)); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 301 "GoParser.y"
    {(yyval.type) = maketypestructtype((yyvsp[(1) - (1)].structType));}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 305 "GoParser.y"
    { (yyval.expList) = makeexpListsingle ((yyvsp[(1) - (1)].exp)); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 306 "GoParser.y"
    { (yyval.expList) = makeexpListfull ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].expList)); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 309 "GoParser.y"
    { (yyval.exp) = makeexpor ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 310 "GoParser.y"
    { (yyval.exp) = makeexpand ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 311 "GoParser.y"
    { (yyval.exp) = makeexpeq ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 312 "GoParser.y"
    { (yyval.exp) = makeexpneq ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 313 "GoParser.y"
    { (yyval.exp) = makeexpGT ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 314 "GoParser.y"
    { (yyval.exp) = makeexpGE ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 315 "GoParser.y"
    { (yyval.exp) = makeexpLT ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 316 "GoParser.y"
    { (yyval.exp) = makeexpLE ((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 317 "GoParser.y"
    { (yyval.exp) = makeexpaddop ((yyvsp[(1) - (1)].addOp)); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 320 "GoParser.y"
    { (yyval.addOp) = makeaddopplus ((yyvsp[(1) - (3)].addOp), (yyvsp[(3) - (3)].addOp)); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 321 "GoParser.y"
    { (yyval.addOp) = makeaddopminus ((yyvsp[(1) - (3)].addOp), (yyvsp[(3) - (3)].addOp)); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 322 "GoParser.y"
    { (yyval.addOp) = makeaddoppipe ((yyvsp[(1) - (3)].addOp), (yyvsp[(3) - (3)].addOp)); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 323 "GoParser.y"
    { (yyval.addOp) = makeaddopcarat ((yyvsp[(1) - (3)].addOp), (yyvsp[(3) - (3)].addOp)); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 324 "GoParser.y"
    { (yyval.addOp) = makeaddopmulop ((yyvsp[(1) - (1)].mulOp)); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 326 "GoParser.y"
    { (yyval.mulOp) = makemuloptimes ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 327 "GoParser.y"
    { (yyval.mulOp) = makemulopdiv ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 328 "GoParser.y"
    { (yyval.mulOp) = makemulopmod ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 329 "GoParser.y"
    { (yyval.mulOp) = makemulopcout ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 330 "GoParser.y"
    { (yyval.mulOp) = makemulopcin ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 331 "GoParser.y"
    { (yyval.mulOp) = makemulopamp ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 332 "GoParser.y"
    { (yyval.mulOp) = makemulopampcarat ((yyvsp[(1) - (3)].mulOp), (yyvsp[(3) - (3)].mulOp)); }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 333 "GoParser.y"
    { (yyval.mulOp) = makemulopfactor ((yyvsp[(1) - (1)].factor)); }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 335 "GoParser.y"
    { (yyval.factor) = makefactoruplus ((yyvsp[(2) - (2)].factor)); }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 336 "GoParser.y"
    { (yyval.factor) = makefactoruminus ((yyvsp[(2) - (2)].factor)); }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 337 "GoParser.y"
    { (yyval.factor) = makefactornot ((yyvsp[(2) - (2)].factor)); }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 338 "GoParser.y"
    { (yyval.factor) = makefactorucarat ((yyvsp[(2) - (2)].factor)); }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 339 "GoParser.y"
    { (yyval.factor) = makefactorutimes ((yyvsp[(2) - (2)].factor)); }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 340 "GoParser.y"
    { (yyval.factor) = makefactoruamp ((yyvsp[(2) - (2)].factor)); }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 341 "GoParser.y"
    { (yyval.factor)=(yyvsp[(1) - (1)].factor);}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 344 "GoParser.y"
    { (yyval.factor) = makefactorname ((yyvsp[(1) - (1)].stringconst)); }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 345 "GoParser.y"
    { (yyval.factor) = makefactordec ((yyvsp[(1) - (1)].intconst)); }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 346 "GoParser.y"
    { (yyval.factor) = makefactorfloat ((yyvsp[(1) - (1)].floatconst)); }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 347 "GoParser.y"
    { (yyval.factor) = makefactoroct ((yyvsp[(1) - (1)].intconst)); }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 348 "GoParser.y"
    { (yyval.factor) = makefactorhex ((yyvsp[(1) - (1)].intconst)); }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 349 "GoParser.y"
    { (yyval.factor) = makefactorrune ((yyvsp[(1) - (1)].intconst)); }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 350 "GoParser.y"
    { (yyval.factor) = makefactorinterpreted ((yyvsp[(1) - (1)].stringconst)); }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 351 "GoParser.y"
    { (yyval.factor) = makefactorraw ((yyvsp[(1) - (1)].stringconst)); }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 352 "GoParser.y"
    { (yyval.factor) = makefactorfunccall ((yyvsp[(1) - (4)].factor),(yyvsp[(3) - (4)].expList)); }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 353 "GoParser.y"
    {(yyval.factor) = makefactorfunccallempty((yyvsp[(1) - (3)].factor));}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 354 "GoParser.y"
    { (yyval.factor) = makefactorappend ((yyvsp[(3) - (6)].stringconst),(yyvsp[(5) - (6)].exp)); }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 355 "GoParser.y"
    { (yyval.factor) = makefactorcast ((yyvsp[(1) - (4)].type),(yyvsp[(3) - (4)].exp)); }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 356 "GoParser.y"
    { (yyval.factor) = makefactorparen ((yyvsp[(2) - (3)].exp)); }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 357 "GoParser.y"
    { (yyval.factor) = makefactortrue(); }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 358 "GoParser.y"
    { (yyval.factor) = makefactorfalse(); }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 359 "GoParser.y"
    {(yyval.factor) = makefactorarray((yyvsp[(1) - (4)].factor),(yyvsp[(3) - (4)].exp));}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 360 "GoParser.y"
    { (yyval.factor) = makefactorstruct((yyvsp[(1) - (3)].factor),(yyvsp[(3) - (3)].stringconst));}
    break;


/* Line 1787 of yacc.c  */
#line 3000 "y.tab.c"
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


/* Line 2050 of yacc.c  */
#line 362 "GoParser.y"

