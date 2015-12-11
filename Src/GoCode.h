#include "GoTree.h"

void codetypedec(typeDec *t);
void codeprogram(program *p);
void codepackage(package *p);
void codedeclist(decList *d);
void codedec(dec *d);
void codevardec(varDec *v);
void codevarlist(varList *v);
void codevar(var *v);
void codetype(type *t, char *name, int init);
void codeidentifierlist(identifierList *i);
void dummyassignment(identifierList *i, expList *e, int t); 
void codemain();
void codefuncdec(funcDec *f);
void codeparamlist(paramList *pl);
void codeparam(param *p);
void printparamtype(identifierList *i, type *t);
void printparamname(identifierList *i, char *t);
void codeblock(block *b);
void codestatementlist(statementList *sl);
void codestatement(statement *s);
void codeif(ifStmt *i);
void codeforloop(forLoop *f);
void codeswitch(switchStmt *s);
void codecaselist(caseList *cl,exp *e);
void codecase(caseFall *c,exp*e);
void codereturn(returning *r);
void codeprint(print *p);
void codesimplestatement(simpleStatement *s);
void codestmtexp(stmtExp *s);
void codeincdec(incDecStmt *id);
void codeassignment(assignment *a);
void dummyassignmentexp(expList *i, expList *e, int f);
void codeexpList(expList *e);
void codeexp(exp *e);
void codeaddOp(addOp *e);
void codemulOp(mulOp *e);
void codefactor(factor *e);
void codeselfop(selfOp *s,exp *l,exp *r);
void codetypetree(TYPETREE *t,char *name);


