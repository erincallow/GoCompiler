#include "GoTree.h"
#include "memory.h"
#include "GoSymbol.h"

extern int lineno;

program *makeprogram(package *left,decList *right){
	program *e;
	e=NEW(program);
	e->kind=progK;
	e->val.progE.left=left;
	e->val.progE.right=right;
	return e;
}

package *makepackage(char* name){
	package *e;
	e=NEW(package);
	e->kind=packageK;
	e->val.packageE=name;
	return e;
}

decList *makedecListempty(){
	decList *e;
	e=NEW(decList);
	e->kind=emptyDecK;
	return e;
}

decList *makedecListfull(dec *left, decList *right){
	decList *e;
	e=NEW(decList);
	e->kind=fullDecK;
	e->val.fullDecE.left=left;
	e->val.fullDecE.right=right;
	return e;
}

dec *makeVarDec(varDec *varDecE){
	dec *e;
	e=NEW(dec);
	e->kind=varDecK;
	e->val.varDecE=varDecE;
	return e;
}

dec *maketypeDec(typeDec *typeDecE){
	dec *e;
	e=NEW(dec);
	e->kind=typeDecK;
	e->val.typeDecE=typeDecE;
	return e;
}

dec *makefuncDec(funcDec *funcDecE){
	dec *e;
	e=NEW(dec);
	e->kind=funcDecK;
	e->val.funcDecE=funcDecE;
	return e;
}

varDec *makeVarDecsingle(var *varE){
	varDec *e;
	e=NEW(varDec);
	e->kind=singleK;
	e->val.varE=varE;
	return e;
}

varDec *makeVarDecdistributed(varList *varListE){
	varDec *e;
	e=NEW(varDec);
	e->kind=distributedK;
	e->val.varListE=varListE;
	return e;
}

varList *makeVarListbase(var *v){
	varList *e;
	e=NEW(varList);
	e->kind=varK;
	e->val.variableE.variable=v;
	return e;
}

varList *makeVarListrecurse(var *v, varList *vl){
	varList *e;
	e=NEW(varList);
	e->kind=varListK;
	e->val.varListE.variable=v;
	e->val.varListE.variableList=vl;
	return e;
}

var *makeVartype(identifierList *names, type *idType){
	var *e;
	e=NEW(var);
        e->lineno=lineno;
	e->kind=typeK;
	e->val.typeE.names=names;
	e->val.typeE.idType=idType;
	return e;
}

var *makeVarEQ(identifierList *names, expList *eqExp){
	var *e;
	e=NEW(var);
        e->lineno=lineno;
	e->kind=veqK;
	e->val.eqE.names=names;
	e->val.eqE.eqExp=eqExp;
	return e;
}

var *makeVartypeEQ(identifierList *names, type *idType, expList *eqExp){
	var *e;
	e=NEW(var);
        e->lineno=lineno;
	e->kind=vtypeEqK;
	e->val.typeEqE.names=names;
	e->val.typeEqE.idType=idType;
	e->val.typeEqE.eqExp=eqExp;
	return e;
}

var *makeVarid(identifierList *names, char *idType){
	var *e;
	e=NEW(var);
        e->lineno=lineno;
	e->kind=vidK;
	e->val.vidE.names=names;
	e->val.vidE.idType=idType;
	return e;
}

var *makeVarIDEQ(identifierList *names, char *idType, expList *eqExp){
	var *e;
	e=NEW(var);
        e->lineno=lineno;
	e->kind=vidEqK;
	e->val.vidEqE.names=names;
	e->val.vidEqE.idType=idType;
	e->val.vidEqE.eqExp=eqExp;
	return e;
}

identifierList *makeidListsingle(char *name){
	identifierList *e;
	e=NEW(identifierList);
	e->kind=singleidK;
	e->val.singleE=name;
	return e;
}

identifierList *makeidListmultiple(identifierList *idList, char *identifier){
	identifierList *e;
	e=NEW(identifierList);
	e->kind=multipleK;
	e->val.idListE.idList=idList;
	e->val.idListE.identifier=identifier;
	return e;
}

structType *makestructTypefull(structList *left){
	structType *e;
	e=NEW(structType);
	e->kind=fullStructTypeK;
	e->val.left=left;
	return e;
}

structType *makestructTypeempty(){
	structType *e;
	e=NEW(structType);
	e->kind=emptyStructTypeK;
	return e;
}

structList *makestructListsingle(param *left){
	structList *e;
	e=NEW(structList);
	e->kind=singlestructK;
	e->val.singlestructE=left;
	return e;
}

structList *makestructListmany(param *left, structList *right){
	structList *e;
	e=NEW(structList);
	e->kind=manystructK;
	e->val.manystructE.left=left;
	e->val.manystructE.right=right;
	return e;
}

typeDec *maketypeDecsingle(typeLine *singleDecE){
	typeDec *e;
	e=NEW(typeDec);
	e->lineno=lineno;
	e->kind=singleDecK;
	e->val.singleDecE=singleDecE;
	return e;
}

typeDec *maketypeDecmany(typeLineList *manyDecE){
	typeDec *e;
	e=NEW(typeDec);
	e->lineno=lineno;
	e->kind=manyDecK;
	e->val.manyDecE=manyDecE;
	return e;
}

typeLineList *maketypeLineListsingle(typeLine *t){
	typeLineList *e;
	e=NEW(typeLineList);
	e->kind=tLineK;
	e->val.tLine=t;
	return e;
}

typeLineList *maketypeLineListmany(typeLine *t, typeLineList *tl){
	typeLineList *e;
	e=NEW(typeLineList);
	e->kind=tLineListK;
	e->val.tLineListE.tLine=t;
	e->val.tLineListE.tLineList=tl;
	return e;
}

typeLine *maketypeLinesingle(char *name, type *right){
	typeLine *e;
	e=NEW(typeLine);
	e->kind=singletypeK;
	e->val.singleE.name=name;
	e->val.singleE.right=right;
	return e;
}

typeLine *maketypeLinemany(char *name,structList *right){
	typeLine *e;
	e=NEW(typeLine);
	e->kind=structK;
	e->val.structE.structname=name;
	e->val.structE.right=right;
	return e;
}

typeLine *maketypeLinesingleID(char *name, char *right){
	typeLine *e;
	e=NEW(typeLine);
	e->kind=singleIDK;
	e->val.singleIDE.name=name;
	e->val.singleIDE.right=right;
	return e;
}

typeLine *maketypeLinemanyID(char *name, paramList *right){
	typeLine *e;
	e=NEW(typeLine);
	e->kind=structIDK;
	e->val.structIDE.structname=name;
	e->val.structIDE.right=right;
	return e;
}

typeLine *maketypeLineempty(char *name){
	typeLine *e;
	e=NEW(typeLine);
	e->kind=emptyType;
	e->val.name=name;
	return e;
}

typeLine *maketypeLinestructtype(char *left,structType *right){
	typeLine *e;
	e=NEW(typeLine);
	e->kind=structTypeK;
	e->val.structTypeE.left=left;
	e->val.structTypeE.right=right;
	return e;
}

funcDec *makefuncDecfull(char *name, paramList *pList, type *t, block *Blocky){
	funcDec *e;
	e=NEW(funcDec);
	e->lineno=lineno;
	e->kind=typeful;
	e->val.typefulE.identifier=name;
	e->val.typefulE.pList=pList;
	e->val.typefulE.type=t;
	e->val.typefulE.Blocky=Blocky;
	return e;
}

funcDec *makefuncDecless(char *name, paramList *pList, block *Blocky){
	funcDec *e;
	e=NEW(funcDec);
	e->lineno=lineno;
	e->kind=typeless;
	e->val.typelessE.identifier=name;
	e->val.typelessE.pList=pList;
	e->val.typelessE.Blocky=Blocky;
	return e;
}

funcDec *makefuncDecnono(char *name, block *Blocky){
	funcDec *e;
	e=NEW(funcDec);
	e->lineno=lineno;
	e->kind=nonoK;
	e->val.noparamnotype.identifier=name;
	e->val.noparamnotype.Blocky=Blocky;
	return e;
}

funcDec *makefuncDecno(char *name, type *t, block *Blocky){
	funcDec *e;
	e=NEW(funcDec);
	e->lineno=lineno;
	e->kind=noK;
	e->val.notype.identifier=name;
	e->val.notype.type=t;
	e->val.notype.Blocky=Blocky;
	return e;
}

funcDec *makefuncDecid(char *name, paramList *pList, char *type, block *Blocky){
	funcDec *e;
	e=NEW(funcDec);
	e->lineno=lineno;
	e->kind=typeIDK;
	e->val.typeIDE.identifier=name;
	e->val.typeIDE.pList=pList;
	e->val.typeIDE.type=type;
	e->val.typeIDE.Blocky=Blocky;
	return e;
}

funcDec *makefuncDecnoid(char *name, char *type, block *Blocky){
	funcDec *e;
	e=NEW(funcDec);
	e->lineno=lineno;
	e->kind=noIDK;
	e->val.noIDE.identifier=name;
	e->val.noIDE.name=type;
	e->val.noIDE.Blocky=Blocky;
	return e;
}

param *makeparam(identifierList *names, type *type){
	param *e;
	e=NEW(param);
	e->kind=onlyparam;
	e->val.onlyE.names=names;
	e->val.onlyE.type=type;
	return e;
}

param *makeparamid(identifierList *names, char *type){
	param *e;
	e=NEW(param);
	e->kind=idparam;
	e->val.idE.names=names;
	e->val.idE.type=type;
	return e;
}

paramList *makeparamListempty(param *p){
	paramList *e;
	e=NEW(paramList);
	e->kind=emptyParamListK;
	e->val.p=p;
	return e;
}

paramList *makeparamListfull(param *p, paramList *pl){
	paramList *e;
	e=NEW(paramList);
	e->kind=fullParamListK;
	e->val.fullE.p=p;
	e->val.fullE.pl=pl;
	return e;
}

block *makeblock(statementList *left){
	block *e;
	e=NEW(block);
	e->kind=only;
	e->val.left=left;
	return e;
}

statementList *makestatementListempty(){
	statementList *e;
	e=NEW(statementList);
	e->kind=emptyStateListK;
	return e;
}

statementList *makestatementListfull(statement *state, statementList *stateList){
	statementList *e;
	e=NEW(statementList);
	e->kind=stateListK;
	e->val.stateListE.state=state;
	e->val.stateListE.stateList=stateList;
	return e;
}

statement *makesimplestatement(simpleStatement *simple){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=ssimpleK;
	e->val.simple=simple;
	return e;
}

statement *makeprintstatement(print *print){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sprintK;
	e->val.print=print;
	return e;
}

statement *makestatementreturning(returning *returned){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sreturnK;
	e->val.returned=returned;
	return e;
}

statement *makestatementif(ifStmt *iffy){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sifK;
	e->val.iffy=iffy;
	return e;
}

statement *makestatementfor(forLoop *loop){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sforK;
	e->val.loop=loop;
	return e;
}

statement *makestatementswitch(switchStmt *switchy){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sswitchK;
	e->val.switchy=switchy;
	return e;
}

statement *makestatementbreak(){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sbreakK;
	return e;
}

statement *makestatementcontinue(){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=scontinueK;
	return e;
}

statement *makestatementblock(statementList *block){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=sblock;
	e->val.block=block;
	return e;
}

simpleStatement *makesimplestmtempty(){
	simpleStatement *e;
	e=NEW(simpleStatement);
        e->lineno=lineno;
	e->kind=emptyStmtK;
	return e;
}

simpleStatement *makesimplestmtassign(assignment *assignE){
	simpleStatement *e;
	e=NEW(simpleStatement);
        e->lineno=lineno;
	e->kind=assignK;
	e->val.assignE=assignE;
	return e;
}

simpleStatement *makesimplestmtincDec(incDecStmt *incDecE){
	simpleStatement *e;
	e=NEW(simpleStatement);
        e->lineno=lineno;
	e->kind=incDecK;
	e->val.incDecE=incDecE;
	return e;
}

simpleStatement *makesimplestmtstmtexp(stmtExp *stmtexp){
	simpleStatement *e;
	e=NEW(simpleStatement);
        e->lineno=lineno;
	e->kind=sstmtExpK;
	e->val.stmtexp=stmtexp;
	return e;
}

statement *makestmttypedec(typeDec *typeE){
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=stype;
	e->val.tvar=typeE;
	return e;
}

statement *makestmtvardec(varDec *varE){
	
	statement *e;
	e=NEW(statement);
	e->lineno=lineno;
	e->kind=svar;
	e->val.var=varE;
	return e;
}

simpleStatement *makesimplestmtshort(expList *left,expList *right){
	simpleStatement *e;
	e=NEW(simpleStatement);
	e->kind=shortK;
	e->val.shortE.left=left;
	e->val.shortE.right=right;
	return e;
}

assignment *makeassignmentlist(expList *idList,expList *expressionList){
	assignment *e;
	e=NEW(assignment);
	e->lineno=lineno;
	e->kind=idListAssK;
	e->val.idListAssE.idList=idList;
	e->val.idListAssE.expressionList=expressionList;
	return e;
}

assignment *makeassignmentself(exp *name,selfOp *selfOperator,exp *expression){
	assignment *e;
	e=NEW(assignment);
	e->lineno=lineno;
	e->kind=selfOpAssK;
	e->val.opSelfAssE.identifier=name;
	e->val.opSelfAssE.selfOperator=selfOperator;
	e->val.opSelfAssE.expression=expression;
	return e;
}

incDecStmt *makeincDecup(exp *up){
	incDecStmt *e;
	e=NEW(incDecStmt);
	e->kind=incK;
	e->val.up=up;
	return e;
}

incDecStmt *makeincDecdown(exp *down){
	incDecStmt *e;
	e=NEW(incDecStmt);
	e->kind=ddecK;
	e->val.down=down;
	return e;
}

print *makeprint(expList *expressionList){
	print *e;
	e=NEW(print);
	e->kind=printK;
	e->val.printE.expressionList=expressionList;
	return e;
}

print *makeprintln(expList *expressionList){
	print *e;
	e=NEW(print);
	e->kind=printlnK;
	e->val.printlnE.expressionList=expressionList;
	return e;
}

print *makeprintempty(){
	print *e;
	e=NEW(print);
	e->kind=printemptyK;
	return e;
}

print *makeprintlnempty(){
	print *e;
	e=NEW(print);
	e->kind=printlnemptyK;
	return e;
}

returning *makereturnempty(){
	returning *e;
	e=NEW(returning);
	e->kind=returnK;
	return e;
}

returning *makereturnfull(exp *expression){
	returning *e;
	e=NEW(returning);
	e->kind=returnExpK;
	e->val.returnExpE.expression=expression;
	return e;
}

ifStmt *makesimpleif(simpleStatement *simple, condition *ifCond, block *stateList){
	ifStmt *e;
	e=NEW(ifStmt);
	e->kind=ifS;
	e->val.ifE.Simple=simple;
	e->val.ifE.ifCond=ifCond;
	e->val.ifE.stateList=stateList;
	return e;
}

ifStmt *makeif(condition *ifCond,block *stateList){
         ifStmt *e;
	 e=NEW(ifStmt);
         e->kind=ifK;
         e->val.ifES.ifCond=ifCond;
         e->val.ifES.stateList=stateList;
         return e;
}

ifStmt *makesimpleifelse(simpleStatement *Simple, condition *ifCond, block *stateList1, block *stateList2){
	ifStmt *e;
	e=NEW(ifStmt);
	e->kind=ifelseS;
	e->val.ifelseE.Simple=Simple;
	e->val.ifelseE.ifCond=ifCond;
	e->val.ifelseE.stateList1=stateList1;
	e->val.ifelseE.stateList2=stateList2;
	return e;
}

ifStmt *makeifelse(condition *ifCond, block *stateList1, block *stateList2){
	ifStmt *e;
	e=NEW(ifStmt);
	e->kind=ifelseK;
	e->val.ifElseES.ifCond=ifCond;
	e->val.ifElseES.stateList1=stateList1;
	e->val.ifElseES.stateList2=stateList2;
	return e;
}

ifStmt *makesimpleifelseif(simpleStatement *Simple, condition *ifCond, block *stateList1, ifStmt *recurse){
	ifStmt *e;
	e=NEW(ifStmt);
	e->kind=ifelseifS;
	e->val.ifelseelseE.Simple=Simple;
	e->val.ifelseelseE.ifCond=ifCond;
	e->val.ifelseelseE.stateList1=stateList1;
	e->val.ifelseelseE.recurse=recurse;
	return e;
}

ifStmt *makeifelseif(condition *ifCond,block *stateList1, ifStmt *recurse){
	ifStmt *e;
	e=NEW(ifStmt);
	e->kind=ifelseifK;
	e->val.ifelseelseES.ifCond=ifCond;
	e->val.ifelseelseES.stateList1=stateList1;
	e->val.ifelseelseES.recurse=recurse;
	return e;
}

forLoop *makefor(block *stateList){
	forLoop *e;
	e=NEW(forLoop);
	e->lineno=lineno;
	e->kind=stateListLoopK;
	e->val.stateListLoopE.stateList=stateList;
	return e;
}

forLoop *makeforcond(condition *cond,block *stateList){
	forLoop *e;
	e=NEW(forLoop);
        e->lineno=lineno;
	e->kind=condLoopK;
	e->val.condLoopE.cond=cond;
	e->val.condLoopE.stateList=stateList;
	return e;
}

forLoop *makeforidcond(simpleStatement *simpleState1, condition *cond, simpleStatement *simpleState2, block *stateList){
	forLoop *e;
	e=NEW(forLoop);
        e->lineno=lineno;
	e->kind=idCondLoopK;
	e->val.idCondLoopE.simpleState1=simpleState1;
	e->val.idCondLoopE.cond=cond;
	e->val.idCondLoopE.simpleState2=simpleState2;
	e->val.idCondLoopE.stateList=stateList;
	return e;
}

forLoop *makefornocond(simpleStatement *simpleState1,simpleStatement *simpleState2, block *stateList){
	forLoop *e;
	e=NEW(forLoop);
        e->lineno=lineno;
	e->kind=nocondK;
	e->val.nocondE.simpleState1=simpleState1;
	e->val.nocondE.simpleState2=simpleState2;
	e->val.nocondE.stateList=stateList;
	return e;
}

switchStmt *makeswitchleftright(simpleStatement *simple, exp *expression, caseList *cases){
	switchStmt *e;
	e=NEW(switchStmt);
	e->kind=leftright;
	e->val.leftrightE.simple=simple;
	e->val.leftrightE.e=expression;
	e->val.leftrightE.cases=cases;
	return e;
}

switchStmt *makeswitchright(exp *expression, caseList *cases){
	switchStmt *e;
	e=NEW(switchStmt);
	e->kind=right;
	e->val.rightE.e=expression;
	e->val.rightE.cases=cases;
	return e;
}

switchStmt *makeswitchleft(simpleStatement *simple, caseList *cases){
	switchStmt *e;
	e=NEW(switchStmt);
	e->kind=left;
	e->val.leftE.simple=simple;
	e->val.leftE.cases=cases;
	return e;
}

switchStmt *makeswitchnone(caseList *cases){
	switchStmt *e;
	e=NEW(switchStmt);
	e->kind=none;
	e->val.noneE.cases=cases;
	return e;
}

caseList *makecaseListempty(){
	caseList *e;
	e=NEW(caseList);
	e->kind=emptyCase;
	return e;
}

caseList *makecaseListfull(caseFall *casey,caseList *right){
	caseList *e;
	e=NEW(caseList);
	e->kind=fullCase;
	e->val.caseX.casey=casey;
	e->val.caseX.right=right;
	return e;
}

caseFall *makecasecase(expList *left, statementList *right){
	caseFall *e;
	e=NEW(caseFall);
	e->kind=caseX;
	e->val.caseE.left=left;
	e->val.caseE.right=right;
	return e;
}

caseFall *makecasedefault(statementList *defaultE){
	caseFall *e;
	e=NEW(caseFall);
	e->kind=defaultX;
	e->val.defaultE=defaultE;
	return e;
}

stmtExp *makestmtexp(exp *e){
	stmtExp *s;
	s=NEW(stmtExp);
	s->val.expStmt=e;
	return s;
	}
/*
exp *makefunccall(char *name, expList *eList){
	stmtExp *e;
	e=NEW(stmtExp);
	e->kind=stmtExpK;
	e->val.stmtExpE.name=name;
	e->val.stmtExpE.eList=eList;
	return e;
}*/

/*exp *makefunccallempty(char *identifier){
	stmtExp *e;
	e=NEW(stmtExp);
	e->kind=stmtExpK;
	e->val.identifier=identifier;
	return e;
}*/

condition *makecondition(exp *condE){
	condition *e;
	e=NEW(condition);
	e->kind=condK;
	e->val.condE=condE;
	return e;
}

selfOp *makeselfplus(){
	selfOp *e;
	e=NEW(selfOp);
	e->kind=selfplus;
	return e;
}

selfOp *makeselfminus(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=selfminus;
        return e;
}

selfOp *makeselftimes(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=selftimes;
        return e;
}

selfOp *makeselfdiv(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=selfdiv;
        return e;
}

selfOp *makeselfmod(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=selfmod;
        return e;
}

selfOp *makeampequals(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=ampequals;
        return e;
}

selfOp *makepipeequals(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=pipeequals;
        return e;
}

selfOp *makecaratequals(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=caratequals;
        return e;
}

selfOp *makecoutequals(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=coutequals;
        return e;
}

selfOp *makecinequals(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=cinequals;
        return e;
}

selfOp *makewtf(){
        selfOp *e;
        e=NEW(selfOp);
        e->kind=wtf;
        return e;
}

type *makeint(){
	type *e;
	e=NEW(type);
	e->kind=typeintK;
//	e->ty->type = intTYPE;
	return e;
}

type *makefloat(){
        type *e;
        e=NEW(type);
        e->kind=typefloatK;
        return e;
}

type *makestring(){
        type *e;
        e=NEW(type);
        e->kind=typestringK;
        return e;
}

type *makerune(){
        type *e;
        e=NEW(type);
        e->kind=typeruneK;
        return e;
}

type *makebool(){
        type *e;
        e=NEW(type);
        e->kind=typeboolK;
        return e;
}

type *makeslice(type *typesliceE){
        type *e;
        e=NEW(type);
        e->kind=typesliceK;
        e->val.typesliceE=typesliceE;
	return e;
}

type *makesliceID(char *typesliceIDE){
	type *e;
	e=NEW(type);
	e->kind=typesliceIDK;
	e->val.typesliceIDE=typesliceIDE;
	return e;
}

type *makedec(int size, type *right){
        type *e;
        e=NEW(type);
        e->kind=typedecarrayK;
	e->val.typedecarrayE.size=size;
	e->val.typedecarrayE.right=right;
        return e;
}

type *makedecID(int size, char *right){
	type *e;
	e=NEW(type);
	e->kind=typedecarrayIDK;
	e->val.typedecarrayIDE.size=size;
	e->val.typedecarrayIDE.right=right;
	return e;
}

type *makeoct(int size, type *right){
        type *e;
        e=NEW(type);
        e->kind=typeoctarrayK;
	e->val.typeoctarrayE.size=size;
	e->val.typeoctarrayE.right=right;
        return e;
}

type *makeoctID(int size, char *right){
	type *e;
	e=NEW(type);
	e->kind=typeoctarrayIDK;
	e->val.typeoctarrayIDE.size=size;
	e->val.typeoctarrayIDE.right=right;
	return e;
}

type *makehex(int size, type *right){
        type *e;
        e=NEW(type);
        e->kind=typehexarrayK;
	e->val.typehexarrayE.size=size;
	e->val.typehexarrayE.right=right;
        return e;
}

type *makehexID(int size, char *right){
	type *e;
	e=NEW(type);
	e->kind=typehexarrayIDK;
	e->val.typehexarrayIDE.size=size;
	e->val.typehexarrayIDE.right=right;
	return e;
}

type *makenovelty(){
        type *e;
        e=NEW(type);
        e->kind=typenoveltyK;
        return e;
}

type *maketypestructtype(structType *t){
	type *e;
	e=NEW(type);
	e->kind=typestructtypeK;
	e->val.t=t;
	return e;
}

expList *makeexpListsingle(exp *expE){
	expList *e;
	e=NEW(expList);
	e->kind=ExpK;
	e->val.expE=expE;
	return e;
}

expList *makeexpListfull(exp *expression, expList *expressionList){
	expList *e;
	e=NEW(expList);
	e->kind=expListK;
	e->val.expListE.expression=expression;
	e->val.expListE.expressionList=expressionList;
	return e;
}

exp *makeexpor(exp *left, exp *right){
	exp *e;
	e=NEW(exp);
	e->lineno=lineno;
	e->kind=orK;
	e->val.orE.left=left;
	e->val.orE.right=right;
	return e;
}

exp *makeexpand(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=andK;
        e->val.andE.left=left;
        e->val.andE.right=right;
        return e;
}

exp *makeexpeq(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=eqK;
        e->val.eqE.left=left;
        e->val.eqE.right=right;
        return e;
}

exp *makeexpneq(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=neqK;
        e->val.neqE.left=left;
        e->val.neqE.right=right;
        return e;
}

exp *makeexpGT(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=GTK;
        e->val.GTE.left=left;
        e->val.GTE.right=right;
        return e;
}

exp *makeexpGE(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=GEK;
        e->val.GEE.left=left;
        e->val.GEE.right=right;
        return e;
}

exp *makeexpLT(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=LTK;
        e->val.LTE.left=left;
        e->val.LTE.right=right;
        return e;
}

exp *makeexpLE(exp *left, exp *right){
        exp *e;
        e=NEW(exp);
	e->lineno=lineno;
        e->kind=LEK;
        e->val.LEE.left=left;
        e->val.LEE.right=right;
        return e;
}

exp *makeexpaddop(addOp *addOpE){
	exp *e;
	e=NEW(exp);
	e->lineno=lineno;
	e->kind=addOpK;
	e->val.addOpE=addOpE;
	return e;
}

addOp *makeaddopplus(addOp *left, addOp *right){
	addOp *e;
	e=NEW(addOp);
	e->kind=plusK;
	e->val.plusE.left=left;
	e->val.plusE.right=right;
	return e;
}

addOp *makeaddopminus(addOp *left, addOp *right){
        addOp *e;
        e=NEW(addOp);
        e->kind=minusK;
        e->val.minusE.left=left;
        e->val.minusE.right=right;
        return e;
}

addOp *makeaddoppipe(addOp *left, addOp *right){
        addOp *e;
        e=NEW(addOp);
        e->kind=pipeK;
        e->val.pipeE.left=left;
        e->val.pipeE.right=right;
        return e;
}

addOp *makeaddopcarat(addOp *left, addOp *right){
        addOp *e;
        e=NEW(addOp);
        e->kind=caratK;
        e->val.caratE.left=left;
        e->val.caratE.right=right;
        return e;
}

addOp *makeaddopmulop(mulOp *mulOpE){
	addOp *e;
	e=NEW(addOp);
	e->kind=mulOpK;
	e->val.mulOpE=mulOpE;
	return e;
}

mulOp *makemuloptimes(mulOp *left, mulOp *right){
	mulOp *e;
	e=NEW(mulOp);
	e->kind=timesK;
	e->val.timesE.left=left;
	e->val.timesE.right=right;
	return e;
}

mulOp *makemulopdiv(mulOp *left, mulOp *right){
        mulOp *e;
        e=NEW(mulOp);
        e->kind=divK;
        e->val.divE.left=left;
        e->val.divE.right=right;
        return e;
}
	
mulOp *makemulopmod(mulOp *left, mulOp *right){
        mulOp *e;
        e=NEW(mulOp);
        e->kind=modK;
        e->val.modE.left=left;
        e->val.modE.right=right;
        return e;
}

mulOp *makemulopcout(mulOp *left, mulOp *right){
        mulOp *e;
        e=NEW(mulOp);
        e->kind=coutK;
        e->val.coutE.left=left;
        e->val.coutE.right=right;
        return e;
}

mulOp *makemulopcin(mulOp *left, mulOp *right){
        mulOp *e;
        e=NEW(mulOp);
        e->kind=cinK;
        e->val.cinE.left=left;
        e->val.cinE.right=right;
        return e;
}

mulOp *makemulopamp(mulOp *left, mulOp *right){
        mulOp *e;
        e=NEW(mulOp);
        e->kind=ampK;
        e->val.ampE.left=left;
        e->val.ampE.right=right;
        return e;
}

mulOp *makemulopampcarat(mulOp *left, mulOp *right){
        mulOp *e;
        e=NEW(mulOp);
        e->kind=ampcaratK;
        e->val.ampcaratE.left=left;
        e->val.ampcaratE.right=right;
        return e;
}

mulOp *makemulopfactor(factor *factorE){
	mulOp *e;
	e=NEW(mulOp);
	e->kind=factorK;
	e->val.factorE=factorE;
	return e;
}

factor *makefactorparen(exp *parenE){
	factor *e;
	e=NEW(factor);
	e->lineno=lineno;
	e->kind=parenK;
	e->val.parenE=parenE;
	return e;
}

factor *makefactoruplus(factor *uplusE){
        factor *e;
        e=NEW(factor);
        e->lineno=lineno;
        e->kind=uplusK;
        e->val.uplusE=uplusE;
        return e;
}

factor *makefactoruminus(factor *uminusE){
        factor *e;
        e=NEW(factor);
        e->lineno=lineno;
        e->kind=uminusK;
        e->val.uminusE=uminusE;
        return e;
}

factor *makefactornot(factor *notE){
        factor *e;
        e=NEW(factor);
        e->lineno=lineno;
        e->kind=notK;
        e->val.notE=notE;
        return e;
}

factor *makefactorucarat(factor *ucaratE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=ucaratK;
	e->val.ucaratE=ucaratE;
	return e;
}

factor *makefactorutimes(factor *utimesE){
        factor *e;
        e=NEW(factor);
        e->lineno=lineno;
        e->kind=utimesK;
        e->val.utimesE=utimesE;
        return e;
}

factor *makefactoruamp(factor *uampE){
        factor *e;
        e=NEW(factor);
        e->lineno=lineno;
        e->kind=uampK;
        e->val.uampE=uampE;
        return e;
}

factor *makefactorname(char *idE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=idK;
	e->val.idE=idE;
	return e;
}

factor *makefactordec(int decE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=decK;
	e->val.decE=decE;
	return e;
}

factor *makefactoroct(int octE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=octK;
	e->val.octE=octE;
	return e;
}

factor *makefactorhex(int hexE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=hexK;
	e->val.hexE=hexE;
	return e;
}

factor *makefactorfloat(float floatE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=floatK;
	e->val.floatE=floatE;
	return e;
}

factor *makefactorrune(char runeE){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=runeK;
	e->val.runeE=runeE;
	return e;
}

factor *makefactorinterpreted(char *interpreted){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=interpretedK;
	e->val.interpretedE=interpreted;
	return e;
}

factor *makefactorraw(char *raw){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=rawK;
	e->val.rawE=raw;
	return e;
}

factor *makefactorcast(type *left,exp *right){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=castK;
	e->val.castE.left=left;
	e->val.castE.right=right;
	return e;
}

factor *makefactorfunccall(factor *name,expList *right){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=funccallK;
	e->val.funccallE.name=name;
	e->val.funccallE.right=right;
	return e;
}

factor *makefactorfunccallempty(factor *name){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=funccallemptyK;
	e->val.funccallemptyE=name;
	return e;
}

factor *makefactorappend(char *name,exp *right){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=appendK;
	e->val.appendE.name=name;
	e->val.appendE.right=right;
	return e;
}

factor *makefactortrue(){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=trueK;
	return e;
}

factor *makefactorfalse(){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=falseK;
	return e;
}

factor *makefactorarray(factor *left, exp *right){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=arrayK;
	e->val.arrayE.left=left;
	e->val.arrayE.right=right;
	return e;
}

factor *makefactorstruct(factor *left, char *right){
	factor *e;
	e=NEW(factor);
        e->lineno=lineno;
	e->kind=estructK;
	e->val.structE.left=left;
	e->val.structE.right=right;
	return e;
}
