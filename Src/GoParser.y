
%{
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
%}
%error-verbose
%union{
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
}

%token <intconst> tHEX tOCT tDEC tRUNE
%token <stringconst> tBOOL INTERPRETEDSTRING RAWSTRING tIDENTIFIER
%token <floatconst> tFLOAT
%token <charconst> tRUNES
%token TRUE FALSE BREAK CASE CHAN CONST CONTINUE DEFAULT DEFER ELSE FALLTHROUGH FOR FUNC GO GOTO IF IMPORT INTERFACE MAP PACKAGE RANGE RETURN SELECT STRUCT SWITCH TYPE VAR INT PRINT FLOAT PRINTLN BOOL APPEND RUNE STRING SEMICOLON NEWLINE PLUS MINUS TIMES DIV MOD AMP PIPE CARAT COUT CIN AMPCARAT SELFPLUS SELFMINUS SELFTIMES SELFDIV SELFMOD AMPEQUALS PIPEEQUALS CARATEQUALS COUTEQUALS CINEQUALS WTF AND OR REDIRECT INCREMENT DECREMENT DOESEQUALS LT GT EQUALS NOT NEQ LE GE COMPAT ELLIPSIS LEFTPAREN RIGHTPAREN LEFTSQUARE RIGHTSQUARE LEFTBRACE RIGHTBRACE COMMA PERIOD FULLCOLON ESCAPEA ESCAPEB ESCAPEF ESCAPEV ESCAPESLASH ESCAPEAPOSTROPHE INVALID
/*%token unary*/
/*%token binary*/

%type <program> program;
%type <package> package;
%type <decList> decList;
%type <dec> dec;
%type <varDec> varDec;
%type <varList> varList;
%type <var> var;
%type <identifierList> identifierList;
%type <structList> structList;
%type <typeDec> typeDec;
%type <typeLineList> typeLineList;
%type <typeLine> typeLine;
%type <funcDec> funcDec;
%type <param> param;
%type <paramList> paramList;
%type <block> block;
%type <statementList> statementList;
%type <statement> statement;
%type <simpleStatement> simpleStatement;
%type <assignment> assignment;
%type <incDecStmt> incDecStmt;
%type <print> print;
%type <returning> return;
%type <ifStmt> ifStmt;
%type <forLoop> forLoop;
%type <switchStmt> switchStmt;
%type <caseList> caseList;
%type <caseFall> case;
%type <stmtExp> stmtExp;
%type <condition> condition;
%type <selfOp> selfOp;
%type <type> type;
%type <expList> expList;
%type <exp> exp;
%type <addOp> addOp;
%type <mulOp> mulOp;
%type <factor> factor;
%type <factor> simple_term;
%type <structType> structType;

%left OR
%left AND
%left DOESEQUALS NEQ GT GE LT LE
%left PLUS MINUS PIPE CARAT
%left TIMES DIV MOD COUT CIN AMP AMPCARAT
/*%left binary*/
/*%left UPLUS UMINUS UNOT UCARAT UTIMES UAMP UPAREN*/
%start program
%%

program: package decList { theprogram = makeprogram ($1, $2); }
;

package: PACKAGE tIDENTIFIER SEMICOLON { $$ = makepackage ($2); }
;

//note - this is a list of declarations AT LEAST ZERO long
decList: dec decList { $$ = makedecListfull ($1, $2); }
       |/*empty*/    { $$ = makedecListempty (); }
;

dec: varDec SEMICOLON { $$ = makeVarDec ($1); }
   | typeDec SEMICOLON { $$ = maketypeDec ($1); }
   | funcDec { $$ = makefuncDec ($1);  }
;
varDec: VAR var { $$ = makeVarDecsingle ($2); }
      | VAR LEFTPAREN varList RIGHTPAREN { $$ = makeVarDecdistributed ($3); }
;

//note - the following is a list of 'var' that is AT LEAST ONE long
varList: var SEMICOLON { $$ = makeVarListbase ($1); }
       | var SEMICOLON varList { $$ = makeVarListrecurse ($1, $3); }
;

var: identifierList type { $$ = makeVartype ($1,$2); }
   | identifierList tIDENTIFIER { $$ = makeVarid($1,$2); }
   | identifierList EQUALS expList { $$ = makeVarEQ ($1, $3); }
   | identifierList type EQUALS expList { $$ = makeVartypeEQ($1, $2, $4); }
   | identifierList tIDENTIFIER EQUALS expList { $$ = makeVarIDEQ($1, $2, $4); }
;

typeDec: TYPE typeLine { $$ = maketypeDecsingle ($2); }
       | TYPE LEFTPAREN typeLineList RIGHTPAREN { $$ = maketypeDecmany ($3); }
;

//note - the following is a list of typelines that is AT LEAST ONE long
typeLineList: typeLine SEMICOLON { $$ = maketypeLineListsingle ($1); }
            | typeLine SEMICOLON typeLineList { $$ = maketypeLineListmany ($1,$3); }
;

structType: STRUCT LEFTBRACE structList RIGHTBRACE { $$ = makestructTypefull($3); }
	  | STRUCT LEFTBRACE RIGHTBRACE { $$ = makestructTypeempty(); }

structList: param SEMICOLON {$$=makestructListsingle($1);}
	  | param SEMICOLON structList {$$=makestructListmany($1,$3);}
;
//add square braces here - one production for types, one for identifier-types
typeLine: tIDENTIFIER type { $$ = maketypeLinesingle ($1,$2); }
        | tIDENTIFIER tIDENTIFIER {$$=maketypeLinesingleID($1,$2);}
	/*| tIDENTIFIER STRUCT LEFTBRACE structList RIGHTBRACE { $$ = maketypeLinemany ($1,$4); }
	| tIDENTIFIER STRUCT LEFTBRACE RIGHTBRACE { $$ = maketypeLineempty($1); }*/
	/*| tIDENTIFIER STRUCT LEFTBRACE paramList RIGHTBRACE{$$=maketypeLinemanyID($1,$4);}*/
	/*| tIDENTIFIER structType { $$ = maketypeLinestructtype($1,$2); }*/
;

ifStmt: IF condition block SEMICOLON { $$ = makeif ($2,$3);  }
      | IF simpleStatement SEMICOLON condition block SEMICOLON { $$ = makesimpleif ($2, $4, $5); }
      | IF condition block ELSE block SEMICOLON { $$ = makeifelse ($2,$3,$5); }
      | IF simpleStatement SEMICOLON condition block ELSE block SEMICOLON { $$ = makesimpleifelse ($2, $4, $5, $7); }
      | IF condition block ELSE ifStmt { $$ = makeifelseif ($2,$3,$5); }
      | IF simpleStatement SEMICOLON condition block ELSE ifStmt{ $$ = makesimpleifelseif ($2, $4, $5, $7); }
;

switchStmt: SWITCH simpleStatement SEMICOLON exp LEFTBRACE caseList RIGHTBRACE { $$ = makeswitchleftright ($2, $4, $6); }
          | SWITCH exp LEFTBRACE caseList RIGHTBRACE { $$ = makeswitchright ($2,$4); }
          | SWITCH simpleStatement SEMICOLON LEFTBRACE caseList RIGHTBRACE { $$ = makeswitchleft ($2, $5); }
          | SWITCH LEFTBRACE caseList RIGHTBRACE { $$ = makeswitchnone ($3); }
;

caseList: /*empty*/ { $$ = makecaseListempty (); }
        | case caseList { $$ = makecaseListfull ($1, $2); }
;

case: CASE expList FULLCOLON statementList { $$ = makecasecase ($2, $4); }
    | DEFAULT FULLCOLON statementList { $$ = makecasedefault ($3); }
;

block: LEFTBRACE statementList RIGHTBRACE { $$ = makeblock ($2); }
;

condition: exp { $$ = makecondition ($1); }
;

statementList: /*empty*/ { $$ = makestatementListempty (); }
             | statement statementList { $$ = makestatementListfull ($1, $2); }
;

statement: simpleStatement SEMICOLON {$$ = makesimplestatement ($1); }
         | print {$$ = makeprintstatement ($1); }
         | return { $$ = makestatementreturning ($1); }
	 | ifStmt { $$ = makestatementif ($1); }
	 | switchStmt SEMICOLON { $$ = makestatementswitch ($1); }
         | forLoop { $$ = makestatementfor ($1); }
	 | BREAK SEMICOLON { $$ = makestatementbreak (); }
	 | CONTINUE SEMICOLON { $$ = makestatementcontinue (); }
	 | varDec SEMICOLON  { $$ = makestmtvardec($1); }
	 | typeDec SEMICOLON { $$ = makestmttypedec($1); }
	 | LEFTBRACE statementList RIGHTBRACE SEMICOLON { $$ = makestatementblock($2); }
;

forLoop: FOR block SEMICOLON { $$ = makefor ($2); }
       | FOR condition block SEMICOLON { $$ = makeforcond ($2,$3); }
       | FOR simpleStatement SEMICOLON condition SEMICOLON simpleStatement block SEMICOLON { $$ = makeforidcond ($2, $4, $6, $7); }
       | FOR simpleStatement SEMICOLON SEMICOLON simpleStatement block SEMICOLON { $$ = makefornocond($2,$5,$6); }
;


param: identifierList type { $$ = makeparam ($1, $2); }
     | identifierList tIDENTIFIER {$$=makeparamid($1,$2);}
;

paramList: param { $$ = makeparamListempty ($1); }
         | param COMMA paramList { $$ = makeparamListfull ($1, $3); }
;

funcDec: FUNC tIDENTIFIER LEFTPAREN paramList RIGHTPAREN block SEMICOLON { $$ = makefuncDecless ($2, $4, $6); }
       | FUNC tIDENTIFIER LEFTPAREN paramList RIGHTPAREN type block SEMICOLON { $$ = makefuncDecfull ($2, $4, $6, $7); }
       | FUNC tIDENTIFIER LEFTPAREN paramList RIGHTPAREN tIDENTIFIER block SEMICOLON {$$=makefuncDecid($2,$4,$6,$7);}
       | FUNC tIDENTIFIER LEFTPAREN RIGHTPAREN block SEMICOLON { $$ = makefuncDecnono ($2, $5); }
       | FUNC tIDENTIFIER LEFTPAREN RIGHTPAREN type block SEMICOLON { $$ = makefuncDecno ($2, $5, $6); }
       | FUNC tIDENTIFIER LEFTPAREN RIGHTPAREN tIDENTIFIER block SEMICOLON {$$=makefuncDecnoid($2,$5,$6);}
;

return: RETURN SEMICOLON { $$ = makereturnempty (); }
      | RETURN exp SEMICOLON { $$ = makereturnfull ($2); }
;

print: PRINT LEFTPAREN expList RIGHTPAREN SEMICOLON { $$ = makeprint ($3); }
     | PRINTLN LEFTPAREN expList RIGHTPAREN SEMICOLON { $$ = makeprintln ($3); }
     | PRINT LEFTPAREN RIGHTPAREN SEMICOLON { $$ = makeprintempty(); }
     | PRINTLN LEFTPAREN RIGHTPAREN SEMICOLON { $$ = makeprintlnempty(); }
;

simpleStatement: /*empty*/ { $$ = makesimplestmtempty (); }
               | assignment { $$ = makesimplestmtassign ($1); }
               | incDecStmt { $$ = makesimplestmtincDec ($1); }
	       | expList COMPAT expList { $$ = makesimplestmtshort ($1, $3); }
               | stmtExp { $$ = makesimplestmtstmtexp ($1); }
;

incDecStmt: exp INCREMENT { $$ =  makeincDecup ($1); }
	  | exp DECREMENT { $$ = makeincDecdown ($1); }
;

identifierList: tIDENTIFIER { $$ = makeidListsingle ($1); }
              | tIDENTIFIER COMMA identifierList { $$ = makeidListmultiple ($3, $1); } /*reverse order $3 $1*/
;

selfOp: SELFPLUS { $$ = makeselfplus (); }
      | SELFMINUS { $$ = makeselfminus (); }
      | SELFTIMES { $$ = makeselftimes (); }
      | SELFDIV { $$ = makeselfdiv (); }
      | SELFMOD { $$ = makeselfmod (); }
      | AMPEQUALS { $$ = makeampequals (); }
      | PIPEEQUALS { $$ = makepipeequals (); }
      | CARATEQUALS { $$ = makecaratequals (); }
      | COUTEQUALS { $$ = makecoutequals (); }
      | CINEQUALS { $$ = makecinequals (); }
      | WTF { $$ = makewtf (); }
;

assignment: expList EQUALS expList { $$ = makeassignmentlist ($1, $3); }
          | exp selfOp exp { $$ = makeassignmentself ($1, $2, $3); }
;

stmtExp: exp { $$ = makestmtexp($1); }
;

type : INT { $$ = makeint (); }
      | FLOAT { $$ = makefloat (); }
      | STRING { $$ = makestring (); }
      | RUNE { $$ = makerune (); }
      | BOOL{ $$ = makebool (); }
      | LEFTSQUARE RIGHTSQUARE type { $$ = makeslice ($3); }
      | LEFTSQUARE tDEC RIGHTSQUARE type { $$ = makedec ($2,$4); }
      | LEFTSQUARE tOCT RIGHTSQUARE type { $$ = makeoct ($2,$4); }
      | LEFTSQUARE tHEX RIGHTSQUARE type { $$ = makehex ($2,$4); }
      | LEFTSQUARE RIGHTSQUARE tIDENTIFIER { $$ = makesliceID($3); }
      | LEFTSQUARE tDEC RIGHTSQUARE tIDENTIFIER { $$ = makedecID($2,$4); }
      | LEFTSQUARE tOCT RIGHTSQUARE tIDENTIFIER { $$ = makeoctID($2,$4); }
      | LEFTSQUARE tHEX RIGHTSQUARE tIDENTIFIER { $$ = makehexID($2,$4); }
      | structType {$$ = maketypestructtype($1);}
/* | tIDENTIFIER { $$ = makenovelty($1); }*/
;

expList: exp { $$ = makeexpListsingle ($1); }
       | exp COMMA expList { $$ = makeexpListfull ($1, $3); }
;

exp: exp OR exp { $$ = makeexpor ($1, $3); }
   | exp AND exp { $$ = makeexpand ($1, $3); }
   | exp DOESEQUALS exp { $$ = makeexpeq ($1, $3); }
   | exp NEQ exp { $$ = makeexpneq ($1, $3); }
   | exp GT exp { $$ = makeexpGT ($1, $3); }
   | exp GE exp { $$ = makeexpGE ($1, $3); }
   | exp LT exp { $$ = makeexpLT ($1, $3); }
   | exp LE exp { $$ = makeexpLE ($1, $3); }
   | addOp { $$ = makeexpaddop ($1); }
/* under factor, add in something like exp LEFTSQUARE num RIGHTSQUARE */
;
addOp: addOp PLUS addOp { $$ = makeaddopplus ($1, $3); }
     | addOp MINUS addOp { $$ = makeaddopminus ($1, $3); }
     | addOp PIPE addOp { $$ = makeaddoppipe ($1, $3); }
     | addOp CARAT addOp { $$ = makeaddopcarat ($1, $3); }
     | mulOp { $$ = makeaddopmulop ($1); }
;
mulOp: mulOp TIMES mulOp { $$ = makemuloptimes ($1, $3); }
     | mulOp DIV mulOp { $$ = makemulopdiv ($1, $3); }
     | mulOp MOD mulOp { $$ = makemulopmod ($1, $3); }
     | mulOp COUT mulOp { $$ = makemulopcout ($1, $3); }
     | mulOp CIN mulOp { $$ = makemulopcin ($1, $3); }
     | mulOp AMP mulOp { $$ = makemulopamp ($1, $3); }
     | mulOp AMPCARAT mulOp { $$ = makemulopampcarat ($1, $3); }
     | factor { $$ = makemulopfactor ($1); }
;
factor: PLUS simple_term { $$ = makefactoruplus ($2); }
      | MINUS simple_term { $$ = makefactoruminus ($2); }
      | NOT simple_term { $$ = makefactornot ($2); }
      | CARAT simple_term { $$ = makefactorucarat ($2); }
      | TIMES simple_term { $$ = makefactorutimes ($2); }
      | AMP simple_term { $$ = makefactoruamp ($2); }
      | simple_term { $$=$1;}
;

simple_term: tIDENTIFIER { $$ = makefactorname ($1); }
      | tDEC { $$ = makefactordec ($1); }
      | tFLOAT { $$ = makefactorfloat ($1); }
      | tOCT { $$ = makefactoroct ($1); }
      | tHEX { $$ = makefactorhex ($1); }
      | tRUNE { $$ = makefactorrune ($1); }
      | INTERPRETEDSTRING { $$ = makefactorinterpreted ($1); }
      | RAWSTRING { $$ = makefactorraw ($1); }
      | simple_term LEFTPAREN expList RIGHTPAREN { $$ = makefactorfunccall ($1,$3); }
      | simple_term LEFTPAREN RIGHTPAREN {$$ = makefactorfunccallempty($1);}
      | APPEND LEFTPAREN tIDENTIFIER COMMA exp RIGHTPAREN { $$ = makefactorappend ($3,$5); }
      | type LEFTPAREN exp RIGHTPAREN { $$ = makefactorcast ($1,$3); }
      | LEFTPAREN exp RIGHTPAREN { $$ = makefactorparen ($2); }
      | TRUE { $$ = makefactortrue(); }
      | FALSE { $$ = makefactorfalse(); }
      | simple_term LEFTSQUARE exp RIGHTSQUARE {$$ = makefactorarray($1,$3);}
      | simple_term PERIOD tIDENTIFIER { $$ = makefactorstruct($1,$3);}
;
%%
