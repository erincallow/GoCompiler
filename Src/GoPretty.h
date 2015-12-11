#ifndef GOPRETTY_H
#define GOPRETTY_H
#include "GoTree.h"

void prettycondition(condition *c, int i);
void prettyselfop(selfOp *s);
void prettytype(type *t);
void prettyexpList(expList *e);
void prettyexp(exp *e);
void prettyaddOp(addOp *e);
void prettymulOp(mulOp *e);
void prettyfactor(factor *e);
void prettystmtexp(stmtExp *s, int i);
void prettycase(caseFall *c, int i);
void prettycaselist(caseList *cl, int i);
void prettyswitch(switchStmt *s, int i);
void prettyforloop(forLoop *f, int i);
void prettyif(ifStmt *i, int n);
void prettyreturn(returning *r, int i);
void prettyprint(print *p, int i);
void prettyincdec(incDecStmt *id, int i);
void prettyassignment(assignment *a, int i);
void prettysimplestatement(simpleStatement *s, int i);
void prettystatement(statement *s, int i);
void prettystatementlist(statementList *sl, int i);
void prettyblock(block *b, int i);
void prettyparam(param *p);
void prettyparamlist(paramList *pl);
void prettyfuncdec(funcDec *f, int i);
void prettytypeline(typeLine *t);
void prettytypelinelist(typeLineList *tl);
void prettytypedec(typeDec *t);
void prettyidentifierlist(identifierList *i);
void prettyvar(var *v, int i);
void prettyvarlist(varList *v, int i);
void prettyvardec(varDec *v, int i);
void prettydec(dec *d, int i);
void prettydeclist(decList *dl, int i);
void prettypackage(package *p);
void prettyprogram(program *e, int i);

void prettytypepp(exp *e);
void prettytypelistpp(expList *e);
void prettysimplestatementtype(simpleStatement *s, int i);
void prettytypestruct(TYPETREELIST *t);

#endif
