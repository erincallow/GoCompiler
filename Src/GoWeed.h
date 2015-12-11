//Version 1.5

#include "GoTree.h"

void weedProgram(program *p);
void weeddeclist(decList *dl);
void weeddec(dec *d);
void weedvardec(varDec *v);
void weedvarlist(varList *v);
void weedvar(var *v);
int weedidentifierlist(identifierList *i);
void weedfuncdec(funcDec *f);
void weedblock(block *b,int i);
void weedstatementlist(statementList *sl,int i);
void weedstatement(statement *s,int i);
void weedsimplestatement(simpleStatement *s);
void weedif(ifStmt *i, int n);
void weedforloop(forLoop *f);
void weedswitch(switchStmt *s);
int weedcaselist(caseList *cl);
int weedcase(caseFall *c);
int weedexpList(expList *e,int i);
void weedexp(exp *e, int i);
void weedIDlist(expList *e);
void weedID(exp *e);
void weedLHlist(expList *e);
void weedLH(exp *e);
void weedIsID(expList *e);
void weedIsIDexp(exp *e);
void weedRHlist(expList *e);
void weedRH(exp *e);
void weedincdec(incDecStmt *i);
