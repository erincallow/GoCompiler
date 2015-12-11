/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2053 of yacc.c  */
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


/* Line 2053 of yacc.c  */
#line 307 "y.tab.h"
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
