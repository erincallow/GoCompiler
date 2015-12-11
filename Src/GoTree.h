#ifndef GOTREE_H
#define GOTREE_H
//#include "GoSymbol.h"


typedef enum SymbolType{intTYPE, floatTYPE, boolTYPE, runeTYPE, stringTYPE, sliceTYPE, arrayTYPE, structTYPE, noTYPE} SymbolType;

typedef struct TYPETREE{
	char *idType; 
	SymbolType type;
	int typeDec;
	int funcDec;
	int lineno;
	union{
		struct TYPETREE *arrayType;
		struct TYPETREELIST *structType;
		struct TYPETREELIST *funcType;
	}val;
} TYPETREE;

typedef struct TYPETREELIST{
	int lineno;
//	enum{emptytree, typetreetree} kind;
	char *idName;
	union{
		struct{struct TYPETREE *tytree; struct TYPETREELIST *tytreelist;}typetreelist;
	} val;
} TYPETREELIST;

typedef struct FIELDACCESS {
	char *name;
	struct FIELDACCESS *next;
	struct FIELDACCESS *previous;
	int first;
} FIELDACCESS;

typedef struct SYMBOL {
        char *name;
        struct TYPETREE type;
        struct SYMBOL *next;
	struct TYPETREE *array;
} SYMBOL;


typedef struct program{
	enum{progK} kind;
	union{
		struct {struct package *left; struct decList *right;} progE;
	} val;
} program;


typedef struct package{
        int lineno;
	enum{packageK} kind;
	union{
		char *packageE;
	} val;
} package;

typedef struct decList{
	enum{emptyDecK,fullDecK} kind;
	union{
		//emptyDec
		struct {struct dec *left; struct decList *right;} fullDecE;
	} val;
} decList;

typedef struct dec{
	enum{varDecK,typeDecK,funcDecK} kind;
	union{
		struct varDec *varDecE;
		struct typeDec *typeDecE;
		struct funcDec *funcDecE;
	} val;
} dec;

typedef struct varDec{
	enum{singleK,distributedK} kind;
	union{
		struct var *varE;
		struct varList *varListE;
	} val;
} varDec;

typedef struct varList{
	enum{varK,varListK} kind;
	union{
		struct {struct var *variable;} variableE;
		struct {struct var *variable; struct varList *variableList;} varListE;
	} val;
} varList;

typedef struct var{
        int lineno;	
	enum{typeK, veqK, vtypeEqK,vidK,vidEqK} kind;
	union{
		struct {struct identifierList *names; struct type *idType;} typeE;
		struct {struct identifierList *names; struct expList *eqExp;} eqE;
		struct {struct identifierList *names; struct type *idType; struct expList *eqExp;} typeEqE;
		struct {struct identifierList *names; char *idType;} vidE;
		struct {struct identifierList *names; char *idType; struct expList *eqExp;} vidEqE;
	} val;
} var;

typedef struct identifierList{
	int lineno;
	enum{singleidK,multipleK} kind;
	union{
		struct {struct identifierList *idList; char *identifier;} idListE; //note - the order is reversed for identifierlist and identifier in the parser
		char *singleE;
	} val;
	TYPETREE type;
} identifierList;

//how the hell do we add user-defined types???
//typedef struct Type{
//	enum{INT,FLOAT,STRING,RUNE,BOOL} kind;
//	union{

typedef struct structType{
	enum{fullStructTypeK,emptyStructTypeK} kind;
	union{
		struct structList * left;
		//nothing
	} val;
	//SymbolTable *s;
} structType;

typedef struct structList{
	enum{singlestructK,manystructK} kind;
	union{
		struct param *singlestructE;
		struct{struct param *left; struct structList *right;} manystructE;
	} val;
	//SymbolTable *st;
} structList;

typedef struct typeDec{
        int lineno;
	enum{singleDecK, manyDecK} kind;
	union{
		struct typeLine *singleDecE;
		struct typeLineList *manyDecE;
	} val;
} typeDec;

typedef struct typeLineList{
	enum{tLineK,tLineListK} kind;
	union{
		struct typeLine *tLine;
		struct {struct typeLine *tLine; struct typeLineList *tLineList;} tLineListE;
	} val;
} typeLineList;
//-----------------------------------------------------------------------------

//note - type added here CHANGE
typedef struct typeLine{
	enum{singletypeK,structK,singleIDK,structIDK,emptyType, structTypeK} kind;
	union{
		struct{char *name; struct type *right;} singleE;
		struct {char *structname; struct structList *right;} structE;
		struct {char *name; char *right;} singleIDE;
		char *name;
		struct {char *structname; struct paramList *right;} structIDE;
		struct {char *left; struct structType *right;} structTypeE;
	} val;
} typeLine;

//Daniel switched from this here

//CHANGES
typedef struct funcDec{
        int lineno;
	enum{typeful,typeless,nonoK,noK,typeIDK,noIDK} kind;
	union{  //note that 'no X' doesn't actually mean that particular enumeration lacks an X - I just really suck at naming things
		struct {char *identifier; struct paramList *pList; struct type *type; struct block *Blocky;} typefulE;
		struct {char *identifier; struct paramList *pList; struct block *Blocky;} typelessE;
		struct {char *identifier; struct paramList *pList; char *type; struct block *Blocky;} typeIDE;
		struct {char *identifier; struct block *Blocky;} noparamnotype;
		struct {char *identifier; struct type *type; struct block *Blocky;} notype;
		struct {char *identifier; char *name; struct block *Blocky;} noIDE;
	} val;
	//SymbolTable *st;
} funcDec;

typedef struct param{
	enum{onlyparam,idparam} kind;
	union{
		struct {struct identifierList *names; struct type *type;} onlyE;
		struct {struct identifierList *names; char *type;} idE;
	} val;
} param;

//CHANGe
typedef struct paramList{
	enum{emptyParamListK,fullParamListK} kind;
	union{
		struct param *p;
		struct {struct param *p; struct paramList *pl;} fullE;
	} val;
} paramList;


typedef struct assignment{
	int lineno;
	enum{idListAssK, selfOpAssK} kind;
	union{
		struct{struct expList *idList; struct expList *expressionList;} idListAssE;
		struct{struct exp *identifier; struct selfOp *selfOperator; struct exp *expression;} opSelfAssE;
	} val;
} assignment;

typedef struct incDecStmt{
	enum{incK,ddecK} kind;
	union{
		struct exp *up;
		struct exp *down;
	} val;
} incDecStmt;

//typedef struct blockDec{
//	enum{varDecK, typeDecK, idDecK} kind;
//	union{
//		struct{varDec *vDec;} varDecE;
//		struct{typeDec *tDec;} typeDecE;
//		struct{char *identifier; exp *expression; expList *expressionList;} idDecE;
//	} val;
//} blockDec;

typedef struct print{
	enum{printK, printlnK,printemptyK,printlnemptyK} kind;
	union{
		struct{struct expList *expressionList;} printE;
		struct{struct expList *expressionList;} printlnE;
		//nothing for printemptyK
		//nothing for printlnemptyK either
	} val;
} print;

typedef struct returning{
	enum{returnK, returnExpK} kind;
	union{
		//returnK
		struct{struct exp *expression;} returnExpE;
	} val;
} returning;
//CHANGE - no 'block' after else in third case
typedef struct ifStmt{
	enum{ifK, ifelseK, ifelseifK, ifS, ifelseS,ifelseifS} kind;
	union{
		struct{struct simpleStatement *Simple; struct condition *ifCond; struct block *stateList;} ifE;
		struct{struct condition *ifCond; struct block *stateList;} ifES;
		struct{struct simpleStatement *Simple; struct condition *ifCond; struct block *stateList1; struct block *stateList2;} ifelseE;
		struct{struct condition *ifCond; struct block *stateList1; struct block *stateList2;} ifElseES;
		struct{struct simpleStatement *Simple; struct condition *ifCond; struct block *stateList1; struct ifStmt *recurse;} ifelseelseE;
		struct{struct condition *ifCond; struct block *stateList1; struct ifStmt *recurse;} ifelseelseES;
	} val;
} ifStmt;

typedef struct forLoop{
	int lineno;
	enum{stateListLoopK, condLoopK, idCondLoopK, nocondK} kind;
	union{
		struct{struct block *stateList;} stateListLoopE;
		struct{struct condition *cond; struct block *stateList;} condLoopE;
		struct{struct simpleStatement *simpleState1; struct condition *cond; struct simpleStatement *simpleState2; struct block *stateList;} idCondLoopE;
		struct{struct simpleStatement *simpleState1; struct simpleStatement *simpleState2; struct block *stateList;} nocondE;
	} val;
} forLoop;

typedef struct switchStmt{
	enum{leftright,right,left,none} kind;
	union{
		struct{struct simpleStatement *simple; struct exp *e; struct caseList *cases;} leftrightE;
		struct{struct exp *e; struct caseList *cases;} rightE;
		struct{struct simpleStatement *simple; struct caseList *cases;} leftE;
		struct{struct caseList *cases;} noneE;
	} val;
} switchStmt;

typedef struct caseList{
	enum{emptyCase,fullCase} kind;
	union{
		//empty
		struct{struct caseFall *casey; struct caseList *right;} caseX;
	} val;
} caseList;

struct expList;
struct statementList;

typedef struct caseFall{
	enum{caseX,defaultX} kind;
	union{
		struct{struct expList *left; struct statementList *right;} caseE;
		struct statementList *defaultE;
	} val;
} caseFall;

//CHANGE - also empty case
typedef struct stmtExp{
	enum{stmtExpK} kind;
	union{
		struct exp *expStmt;
	} val;
} stmtExp;


//need to support varDec here - CHANGE
typedef struct simpleStatement{
        int lineno;
	enum{emptyStmtK,assignK,incDecK,sstmtExpK,shortK} kind;
        union{
                //empty
                struct assignment *assignE;
                struct incDecStmt *incDecE;
                struct stmtExp *stmtexp;
                //struct typeDec *typeE;
                //struct varDec *varE;
                struct {struct expList *left; struct expList *right;} shortE;
        } val;
} simpleStatement;

typedef struct statement{
        int lineno;
        enum{ssimpleK,sprintK,sreturnK,sifK,sforK,sswitchK,sbreakK,scontinueK,svar,stype,sblock} kind;
        union{
                struct simpleStatement *simple;
                struct print *print;
                struct returning *returned;
                struct ifStmt *iffy;
                struct forLoop *loop;
                struct switchStmt *switchy; //nothing for break or continue
		struct varDec *var;
		struct typeDec *tvar;
		struct statementList *block;
        } val;
} statement;

typedef struct statementList{
        enum{emptyStateListK, stateListK} kind;
        union{
                //empty
                struct {struct statement *state; struct statementList *stateList;} stateListE;
        } val;
} statementList;

typedef struct block{
        enum{only} kind;
        union{
                struct statementList *left;
        } val;
} block;

typedef struct condition{
	enum{condK} kind;
	union{
		struct exp *condE;
	} val;
	TYPETREE type;
} condition;

typedef struct selfOp{ //this way we can designate which self-operator we've used
	enum{selfplus,selfminus,selftimes,selfdiv,selfmod,ampequals,pipeequals,caratequals,coutequals,cinequals,wtf} kind;
} selfOp;

//put some stuff for recursive types (slices, arrays) in tree.h and tree.c
//CHANGE - add in support for recursive
typedef struct type{
	enum{typeintK,typefloatK,typestringK,typeruneK,typeboolK,typesliceK,typedecarrayK,typeoctarrayK,typehexarrayK,typenoveltyK, typesliceIDK,typedecarrayIDK,typeoctarrayIDK,typehexarrayIDK,typestructtypeK} kind;
	union{
		struct type *typesliceE;
		struct{int size; struct type *right;} typedecarrayE;
		struct{int size; struct type *right;} typeoctarrayE;
		struct{int size; struct type *right;} typehexarrayE;
		char *typesliceIDE;
		struct{int size; char *right;} typedecarrayIDE;
		struct{int size; char *right;} typeoctarrayIDE;
		struct{int size; char *right;} typehexarrayIDE;
		struct structType *t;
	} val;
	TYPETREE ty;
} type;

typedef struct expList{
	enum{ExpK, expListK} kind;
	union{
		struct exp *expE;
		struct{struct exp *expression; struct expList *expressionList;} expListE;
	} val;
} expList;

typedef struct exp{
        int lineno;
	enum{orK,andK,eqK,neqK,GTK,GEK,LTK,LEK,addOpK} kind;
	union{
		struct{struct exp *left; struct exp *right;} orE;
		struct{struct exp *left; struct exp *right;} andE;
		struct{struct exp *left; struct exp *right;} eqE;
		struct{struct exp *left; struct exp *right;} neqE;
		struct{struct exp *left; struct exp *right;} GTE;
		struct{struct exp *left; struct exp *right;} GEE;
		struct{struct exp *left; struct exp *right;} LTE;
		struct{struct exp *left; struct exp *right;} LEE;
		struct addOp *addOpE;
	} val;
	TYPETREE type;
} exp;

typedef struct addOp{
	int lineno;
	enum{plusK,minusK,pipeK,caratK,mulOpK } kind;
	union{
		struct{struct addOp *left; struct addOp *right;} plusE;
		struct{struct addOp *left; struct addOp *right;} minusE;
		struct{struct addOp *left; struct addOp *right;} pipeE;
		struct{struct addOp *left; struct addOp *right;} caratE;
		struct mulOp *mulOpE;
	} val;
	TYPETREE type;
} addOp;

typedef struct mulOp{
	int lineno;
	enum{timesK,divK,modK,coutK,cinK,ampK,ampcaratK,factorK} kind;
	union{
		struct{struct mulOp *left; struct mulOp *right;} timesE;
                struct{struct mulOp *left; struct mulOp *right;} divE;
                struct{struct mulOp *left; struct mulOp *right;} modE;
                struct{struct mulOp *left; struct mulOp *right;} coutE;
                struct{struct mulOp *left; struct mulOp *right;} cinE;
                struct{struct mulOp *left; struct mulOp *right;} ampE;
                struct{struct mulOp *left; struct mulOp *right;} ampcaratE;
                struct factor *factorE;
	} val;
	TYPETREE type;
} mulOp;


typedef struct factor{
	int lineno;
	enum{parenK,uplusK,uminusK,notK,ucaratK,utimesK,uampK,idK,decK,octK,floatK,hexK,runeK,interpretedK,rawK,castK,funccallK,funccallemptyK,appendK,trueK,falseK,arrayK,estructK} kind;
	union{
		struct factor *uplusE;
		struct factor *uminusE;
		struct factor *notE;
		struct factor *ucaratE;
		struct factor *utimesE;
		struct factor *uampE;
		struct factor *simpleTerm;
		char *idE;
		int decE;
		int octE;
		int hexE;
		float floatE;
		char runeE;
		char *interpretedE;
		char *rawE;
		struct {struct type *left; struct exp *right;} castE;
		struct {struct factor *name; struct expList *right;} funccallE;
		struct factor *funccallemptyE;
		struct {char *name; struct exp *right;} appendE;
		struct exp *parenE;
		struct {struct factor *left; struct exp *right;} arrayE;
		struct {struct factor *left; char *right;} structE;
	} val;
	TYPETREE type;
	FIELDACCESS accessOrder;
} factor;

program *makeprogram(package *left,decList *right);
package *makepackage(char* name);
decList *makedecListempty();
decList *makedecListfull(dec *left, decList *right);
dec *makeVarDec(varDec *varDecE);
dec *maketypeDec(typeDec *typeDecE);
dec *makefuncDec(funcDec *funcdecE);
structList *makestructListsingle(param *left);
structList *makestructListmany(param *left,structList *right);
structType *makestructTypefull(structList *left);
structType *makestructTypeempty();
varDec *makeVarDecsingle(var *varE);
varDec *makeVarDecdistributed(varList *varListE);
varList *makeVarListbase(var *v);
varList *makeVarListrecurse(var *v, varList *vl);
var *makeVartype(identifierList *names, type *idType);
var *makeVarEQ(identifierList *names, expList *eqExp);
var *makeVartypeEQ(identifierList *names, type *idType, expList *eqExp);
var *makeVarid(identifierList *names, char *idType);
var *makeVarIDEQ(identifierList *names, char *idType, expList *eqExp);
identifierList *makeidListsingle(char *name);
identifierList *makeidListmultiple(identifierList *idList, char *identifier);
typeDec *maketypeDecsingle(typeLine *singleDecE);
typeDec *maketypeDecmany(typeLineList *manyDecE);
typeLineList *maketypeLineListsingle(typeLine *t);
typeLineList *maketypeLineListmany(typeLine *t, typeLineList *tl);
typeLine *maketypeLinesingle(char *name, type *right);
typeLine *maketypeLinesingleID(char *name, char *right);
typeLine *maketypeLinemany(char *name,structList *right);
typeLine *maketypeLinemanyID(char *name, paramList *right);
typeLine *maketypeLineempty(char *name);
typeLine *maketypeLinestructtype(char *left,structType *right);
funcDec *makefuncDecfull(char *name, paramList *pList, type *t, block *Blocky);
funcDec *makefuncDecless(char *name, paramList *pList, block *Blocky);
funcDec *makefuncDecnono(char *name, block *Blocky);
funcDec *makefuncDecno(char *name, type *t, block *Blocky);
funcDec *makefuncDecid(char *name, paramList *pList, char *type, block *Blocky);
funcDec *makefuncDecnoid(char *name, char *type, block *Blocky);
param *makeparam(identifierList *names, type *type);
param *makeparamid(identifierList *names, char *type);
paramList *makeparamListempty(param *p);
paramList *makeparamListfull(param *p, paramList *pl);
block *makeblock(statementList *left);
statementList *makestatementListempty();
statementList *makestatementListfull(statement *state, statementList *stateList);
statement *makesimplestatement(simpleStatement *simple);
statement *makeprintstatement(print *print);
statement *makestatementreturning(returning *returned);
statement *makestatementif(ifStmt *iffy);
statement *makestatementfor(forLoop *loop);
statement *makestatementswitch(switchStmt *switchy);
statement *makestatementbreak();
statement *makestatementcontinue();
simpleStatement *makesimplestmtassign(assignment *assignE);
simpleStatement *makesimplestmtincDec(incDecStmt *incDecE);
simpleStatement *makesimplestmtstmtexp(stmtExp *stmtexp);
statement *makesimplestmttypedec(typeDec *typeE);
statement *makesimplestmtvardec(varDec *varE);
simpleStatement *makesimplestmtshort(expList *left,expList *right);
assignment *makeassignmentlist(expList *idList,expList *expressionList);
assignment *makeassignmentself(exp *name,selfOp *selfOperator,exp *expression);
incDecStmt *makeincDecup(exp *up);
incDecStmt *makeincDecdown(exp *down);
print *makeprint(expList *expressionList);
print *makeprintln(expList *expressionList);
print *makeprintempty();
print *makeprintlnempty();
returning *makereturnempty();
returning *makereturnfull(exp *expression);
ifStmt *makesimpleif(simpleStatement *simple, condition *ifCond, block *stateList);
ifStmt *makeif(condition *ifCond,block*stateList);
ifStmt *makesimpleifelse(simpleStatement *Simple, condition *ifCond, block *stateList1, block *stateList2);
ifStmt *makeifelse(condition *ifCond, block *stateList1, block *stateList2);
ifStmt *makesimpleifelseif(simpleStatement *Simple, condition *ifCond, block *stateList1, ifStmt *recurse);
ifStmt *makeifelseif(condition *ifCond,block *stateList1, ifStmt *recurse);
forLoop *makefor(block *stateList);
forLoop *makeforcond(condition *cond,block *stateList);
forLoop *makeforidcond(simpleStatement *simpleState1, condition *cond, simpleStatement *simpleState2, block *stateList);
forLoop *makefornocond(simpleStatement *simpleState1,simpleStatement *simpleState2, block *stateList);
switchStmt *makeswitchleftright(simpleStatement *simple, exp *expression, caseList *cases);
switchStmt *makeswitchright(exp *expression, caseList *cases);
switchStmt *makeswitchleft(simpleStatement *simple, caseList *cases);
switchStmt *makeswitchnone(caseList *cases);
caseList *makecaseListempty();
caseList *makecaseListfull(caseFall *casey,caseList *right);
caseFall *makecasecase(expList *left, statementList *right);
caseFall *makecasedefault(statementList *defaultE);
stmtExp *makestmtexp(exp *e);
condition *makecondition(exp *condE);
selfOp *makeselfplus();
selfOp *makeselfminus();
selfOp *makeselftimes();
selfOp *makeselfdiv();
selfOp *makeselfmod();
selfOp *makeampequals();
selfOp *makepipeequals();
selfOp *makecaratequals();
selfOp *makecoutequals();
selfOp *makecinequals();
selfOp *makewtf();
type *makeint();
type *makefloat();
type *makestring();
type *makerune();
type *makebool();
type *makeslice();
type *makedec();
type *makeoct();
type *makehex();
type *makenovelty();
type *makesliceID(char *typesliceIDE);
type *makedecID(int size, char *right);
type *makeoctID(int size, char *right);
type *makehexID(int size, char *right);
type *maketypestructtype(structType *t);
expList *makeexpListsingle(exp *expE);
expList *makeexpListfull(exp *expression, expList *expressionList);
exp *makeexpor(exp *left, exp *right);
exp *makeexpand(exp *left, exp *right);
exp *makeexpeq(exp *left, exp *right);
exp *makeexpneq(exp *left, exp *right);
exp *makeexpGT(exp *left, exp *right);
exp *makeexpGE(exp *left, exp *right);
exp *makeexpLT(exp *left, exp *right);
exp *makeexpLE(exp *left, exp *right);
exp *makeexpaddop(addOp *addOpE);
addOp *makeaddopplus(addOp *left, addOp *right);
addOp *makeaddopminus(addOp *left, addOp *right);
addOp *makeaddoppipe(addOp *left, addOp *right);
addOp *makeaddopcarat(addOp *left, addOp *right);
addOp *makeaddopmulop(mulOp *mulOpE);
mulOp *makemuloptimes(mulOp *left, mulOp *right);
mulOp *makemulopdiv(mulOp *left, mulOp *right);
mulOp *makemulopmod(mulOp *left, mulOp *right);
mulOp *makemulopcout(mulOp *left, mulOp *right);
mulOp *makemulopcin(mulOp *left, mulOp *right);
mulOp *makemulopamp(mulOp *left, mulOp *right);
mulOp *makemulopampcarat(mulOp *left, mulOp *right);
mulOp *makemulopfactor(factor *factorE);
factor *makefactorparen(exp *parenE);
factor *makefactoruplus(factor *uplusE);
factor *makefactoruminus(factor *uminusE);
factor *makefactornot(factor *notE);
factor *makefactorucarat(factor *ucaratE);
factor *makefactorutimes(factor *utimesE);
factor *makefactoruamp(factor *uampE);
factor *makefactorname(char * idE);
factor *makefactordec(int decE);
factor *makefactoroct(int octE);
factor *makefactorhex(int hexE);
factor *makefactorfloat(float floatE);
factor *makefactorrune(char runeE);
factor *makefactorinterpreted(char *interpreted);
factor *makefactorraw(char *raw);
factor *makefactorcast(type *left,exp *right);
factor *makefactorfunccall(factor *name,expList *right);
factor *makefactorfunccallempty(factor *name);
factor *makefactorappend(char *name,exp *right);
factor *makefactortrue();
factor *makefactorfalse();
simpleStatement *makesimplestmtempty();
factor *makefactorarray(factor *left, exp *right);
factor *makefactorstruct(factor *left, char *right);

statement *makestmttypedec(typeDec *typeE);
statement *makestmtvardec(varDec *varE);
statement *makestatementblock(statementList *block);
#endif
