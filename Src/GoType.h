//Version 1.5

#ifndef NEWTYPE_H
#define NEWTYPE_H

#include "GoTree.h"
#include "GoSymbol.h"

void init();
void mainTypeProgram(program *p, int i);
void typeImpProg(program *p, SymbolTable *t, int i);
void symDECLIST(decList *d, SymbolTable *t, int i);
void symDEC(dec *d, SymbolTable *t, int i);
void symVARDEC(varDec *v, SymbolTable *t);
void symVARLIST(varList *v, SymbolTable *t);
void symVAR(var *v, SymbolTable *t);
void symTYPEIDLIST(identifierList *i, SymbolTable *t, TYPETREE *ty);
TYPETREE *symTYPE(type *typ, SymbolTable *t);

TYPETREE *idSet(char *id, SymbolTable *t);
void symSTRUCTTYPE(structType *s, SymbolTable *t, TYPETREELIST *ty);
void symSTRUCTLIST(structList *s, SymbolTable *t, TYPETREELIST *ty);
void symSTRUCTPARAM(param *p, SymbolTable *t, TYPETREELIST *ty);

void symIDIDLIST(identifierList *i, SymbolTable *t, char *idtype);
void symIDEXPLIST(identifierList *i, expList *e, SymbolTable *t);
void symIDTYPEEXPLIST(identifierList *i, expList *e, SymbolTable *t, TYPETREE *s);
void symIDIDTYPEEXPLIST(identifierList *i, expList *e, SymbolTable *t, char *idtype);

TYPETREELIST *symSTRUCTTYPEIDLIST(identifierList *i, SymbolTable *t, TYPETREE *ty, TYPETREELIST *tylist);
TYPETREELIST *symSTRUCTIDIDLIST(identifierList *i, SymbolTable *t, char *idtype, TYPETREELIST *tylist);


void symTYPELINELIST(typeLineList *l, SymbolTable *t);
void symTYPEDEC(typeDec *d, SymbolTable *t);
void symTYPELINE(typeLine *l, SymbolTable *t);

void symFUNCDEC(funcDec *f, SymbolTable *t, int i);
TYPETREELIST *symPARAM(param *p, SymbolTable *t, TYPETREELIST *tytreelist);
void symPARAMLIST(paramList *p, SymbolTable *t, TYPETREELIST *tytreelist);
void symPARAMFIX(param *p, SymbolTable *t);
void symPARAMLISTFIX(paramList *p, SymbolTable *t);
TYPETREELIST *symPARAMTYPEIDLIST(identifierList *i, SymbolTable *t, TYPETREE *ty, TYPETREELIST *tylist);
TYPETREELIST *symPARAMIDIDLIST(identifierList *i, SymbolTable *t, char *idtype, TYPETREELIST *tylist);

void symBLOCK(block *b, SymbolTable *t, char* currFunc, int i);
void typeImplementationIncDecStatement(incDecStmt *i,  SymbolTable *t);
void symSTMTEXP(stmtExp *s, SymbolTable *t);
void symPRINT(print *p, SymbolTable *t);

void symCOND(condition *c, SymbolTable *t);
void symSIMPLESTATE(simpleStatement *s, SymbolTable *t);

int atLeastOne(expList *e, SymbolTable *t);
void symSHORTEXPLIST(expList *i, expList *e, SymbolTable *t);
void symASSIGNEXPLIST(expList *i, expList *e, SymbolTable *t);
void symASSIGNMENT(assignment *a, SymbolTable *t);
void symIFSTATE(ifStmt *i, SymbolTable *t, char* currFunc, int j);

void symSTATEMENT(statement *s, SymbolTable *t, char *currFunc, int i);
void symSTATELIST(statementList *s, SymbolTable *t, char *currFunc, int i);
void symRETURN(returning *r, SymbolTable *t, char* currFunc);void symFORLOOP(forLoop *f, SymbolTable *t, char* currFunc, int i);

void caseExpCheck(expList *e, SymbolTable *t, SymbolType ty);
void symCASEFALL(caseFall *c, SymbolTable *t, SymbolType ty, char *currFunc, int i);
void symCASELIST(caseList *c, SymbolTable *t, SymbolType ty, char *currFunc, int i);
void symSWITCHSTATE(switchStmt *s, SymbolTable *t, char *currFunc, int i);

void symEXPLIST(expList *e, SymbolTable *t);
void symEXP(exp *e, SymbolTable *t);
void checkArgumentTypes(type *t,expList *e);
int comparable(exp *a,exp *b);
int ordered(exp *e);
int orderedAddOp(addOp *e);
void typeImplementationAddOp(addOp *a, SymbolTable *t);
void typeMulOp(mulOp *m, SymbolTable *t);
int numericAddOp(addOp *e);
int numericMulOp(mulOp *e);
int numeric(factor *e);
void typeFactor(factor *f, SymbolTable *t);

void expToParams(TYPETREELIST *ttl, expList *e, SymbolTable *t);

SymbolType getStructType(FIELDACCESS *accessor, TYPETREELIST *ttl);
FIELDACCESS *getBase(FIELDACCESS *accessor);
int printAccess(FIELDACCESS *accessor);
TYPETREELIST *structRecursion(TYPETREELIST *t, FIELDACCESS *fa);
SymbolType structFieldAccess(TYPETREELIST *ty, char *identifier);
TYPETREE *toEnd(TYPETREE *ty);
#endif
