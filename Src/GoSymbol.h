//Version 1.5

#ifndef NEWSYMBOL_H
#define NEWSYMBOL_H

#define HashSize 317
#include "GoTree.h"

typedef struct SymbolTable {
        SYMBOL *table[HashSize];
        struct SymbolTable *next;//pointer to another symbol table 
        } SymbolTable;

void printSymbolTable(SymbolTable *t);
void printCurrScope(SymbolTable *t);
void arrayPrint(TYPETREE *array);
void structPrint(TYPETREELIST *structTree);
int Hash(char *str);
SymbolTable *initSymbolTable();
SymbolTable *scopeSymbolTable(SymbolTable *s);

SYMBOL *putSymbolIdTypeDec(SymbolTable *t, char *name, char *idType);
SYMBOL *putSymbolIdType(SymbolTable *t, char *name, char *idType);
SYMBOL *putSymbolTypeDec(SymbolTable *t, char *name, TYPETREE kind); 
SYMBOL *putSymbol(SymbolTable *t, char *name, TYPETREE kind);
SYMBOL *putSymbolFuncDec(SymbolTable *t, char *name, TYPETREE kind);
SYMBOL *putSymbolIdFuncDec(SymbolTable *t, char *name, char *idType);

TYPETREE *getStructTreePrim(SymbolTable *t, char *name);
TYPETREE *getTreePrim(SymbolTable *t, char *name);
SymbolType getPrimitive(SymbolTable *t, char *name);
SymbolTable *getCurrScope(SymbolTable *t);

int symbolAccess(SymbolTable *t, char *name);

SYMBOL *getFunc(SymbolTable *t, char *name);
SYMBOL *getSymbol(SymbolTable *t, char *name);
int symbolDefined(SymbolTable *t, char *name);
int typeDefined(SymbolTable *t, char *name);
int typeAlreadyInScope(SymbolTable *t, char *name);
int funcDefined(SymbolTable *t, char *name);
SYMBOL *symVar(char *name, SymbolTable *t);

#endif
