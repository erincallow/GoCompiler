//Version 1.5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GoSymbol.h"
#include "GoType.h"
#include "memory.h"
#include "GoTree.h"
#include "error.h"
extern SymbolTable *symTable;
int flag;

void mainTypeProgram(program *p, int i){
	flag = 0;
        //SymbolTable *symTable;
        symTable = initSymbolTable();
	TYPETREE *t;
	t = NEW(TYPETREE);
	t->type = boolTYPE;
	putSymbol(symTable, "true", *t);
	putSymbol(symTable, "false", *t);
//	i = 1;
	typeImpProg(p, symTable, i);
	if(i==1){
	printSymbolTable(symTable);
	}
}

void typeImpProg(program *p, SymbolTable *t, int i){
        symDECLIST(p->val.progE.right, t, i);
}

void symDECLIST(decList *d, SymbolTable *t, int i){
        switch(d->kind){
                case emptyDecK:
			//printSymbolTable(t);
                        break;
                case fullDecK:
                        symDEC(d->val.fullDecE.left, t, i);
                        symDECLIST(d->val.fullDecE.right, t, i);
			break;
        }
}

void symDEC(dec *d, SymbolTable *t, int i){
        switch(d->kind){
                case varDecK:
                        symVARDEC(d->val.varDecE, t);
			break;
                case typeDecK:
                        symTYPEDEC(d->val.typeDecE, t);
                        break;
                case funcDecK:
                        symFUNCDEC(d->val.funcDecE, t, i);
                        break;
        }
}

void symVARDEC(varDec *v, SymbolTable *t){
	switch(v->kind){
                case singleK:
                        symVAR(v->val.varE, t);
                        break;
                case distributedK:
                        symVARLIST(v->val.varListE, t);
                        break;
        }

}

void symVARLIST(varList *v, SymbolTable *t){
	switch(v->kind){
                case varK:
                        symVAR(v->val.variableE.variable, t);
                        break;
                case varListK:
                        symVAR(v->val.varListE.variable, t);
                        symVARLIST(v->val.varListE.variableList, t);
                        break;
        }
}

void symVAR(var *v, SymbolTable *t){
	//printf("inside VAR\n");
	TYPETREE *tytree;
	tytree = NEW(TYPETREE);
        switch(v->kind){
                case typeK:
			tytree = symTYPE(v->val.typeE.idType, t);
                        symTYPEIDLIST(v->val.typeE.names, t, tytree);
                        break;
                 case vidK:
                        symIDIDLIST(v->val.vidE.names, t, v->val.vidE.idType);
			break;
		case veqK:
			//COME BACK HERE
			//need check to make sure there are no arrays slices or structs in list
                        symIDEXPLIST(v->val.eqE.names, v->val.eqE.eqExp, t);
                        break;
                case vtypeEqK:
			tytree = symTYPE(v->val.typeEqE.idType,t);
                        symIDTYPEEXPLIST(v->val.typeEqE.names,v->val.typeEqE.eqExp,t, tytree);
                        break;
                case vidEqK:
                        symIDIDTYPEEXPLIST(v->val.vidEqE.names, v->val.vidEqE.eqExp, t, v->val.vidEqE.idType);
                        break;
        }
	free(tytree);
}


void symTYPEIDLIST(identifierList *i, SymbolTable *t, TYPETREE *ty){
	//printf("inside TYPEIDLIST\n");
	switch(i->kind){
		case singleidK:
			if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
			}
			putSymbol(t, i->val.singleE, *ty);
			break;
		case multipleK:
			if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
			putSymbol(t, i->val.idListE.identifier, *ty);
			symTYPEIDLIST(i->val.idListE.idList, t, ty);
			break;
	}
}


TYPETREE *symTYPE(type *typ, SymbolTable *st){
	//printf("inside TYPE\n");
	TYPETREE *t;
	t = NEW(TYPETREE);
	switch(typ->kind){
                case typeintK:
			t->type = intTYPE;
			typ->ty.type = intTYPE;
			typ->ty.val.arrayType = NULL;
			return t;
			break;
                case typefloatK:
                        t->type = floatTYPE;
			typ->ty.type = floatTYPE;
			typ->ty.val.arrayType = NULL;
			return t;
                        break;
                case typestringK:
			t->type = stringTYPE;
			typ->ty.type = stringTYPE;
			typ->ty.val.arrayType = NULL;
			return t;
                        break;
                case typeruneK:
                        t->type = runeTYPE;
			typ->ty.type = runeTYPE;
			typ->ty.val.arrayType = NULL;
			return t;
			break;
                case typeboolK:
			t->type = boolTYPE;
			typ->ty.type = boolTYPE;
			typ->ty.val.arrayType = NULL;
			return t;
                        break;
                
		case typesliceK:
			t->type = sliceTYPE;
			t->val.arrayType = symTYPE(typ->val.typesliceE, st);
                        return t;
			break;
                case typedecarrayK:
			t->type = arrayTYPE;
			t->val.arrayType = symTYPE(typ->val.typedecarrayE.right, st);
                        return t;
			break;
                case typeoctarrayK:
			t->type = arrayTYPE;
			t->val.arrayType = symTYPE(typ->val.typeoctarrayE.right, st);
                        return t;
			break;
                case typehexarrayK:
			t->type = arrayTYPE;
			t->val.arrayType = symTYPE(typ->val.typehexarrayE.right, st);
                        return t;
			break;
		case typenoveltyK:
			return t;
			break;
		case typesliceIDK:
			t->type = sliceTYPE;
			t->val.arrayType = idSet(typ->val.typesliceIDE, st);
			return t;
			break;
		case typedecarrayIDK:
			t->type = arrayTYPE;
			t->val.arrayType = idSet(typ->val.typedecarrayIDE.right, st);
			return t;
			break;
		case typeoctarrayIDK:
			t->type = arrayTYPE;
			t->val.arrayType = idSet(typ->val.typeoctarrayIDE.right, st);
			return t;
			break;
		case typehexarrayIDK:
			t->type = arrayTYPE;
			t->val.arrayType = idSet(typ->val.typehexarrayIDE.right, st);
			return t;
			break;
		case typestructtypeK: 
			typ->ty.val.structType = NEW(TYPETREELIST);
		//	printf("inside struct case\n");
			t->type = structTYPE;
			st = scopeSymbolTable(st);
			//printf("%s up", typ->ty.val.structType->idName);
			symSTRUCTTYPE(typ->val.t, st, typ->ty.val.structType);
			t->val.structType = typ->ty.val.structType;
		//	printf("%d HERE ", t->val.structType->val.typetreelist.tytree->type);
			return t;
			break;
		}
}

TYPETREE *idSet(char *id, SymbolTable *t){
	TYPETREE *tyt;
	tyt = NEW(TYPETREE);
	if(symbolDefined(t, id) == 0){
		reportError("Error - ID undefined", tyt->lineno);
	}
	tyt->idType = id;
	return tyt;
}


void symSTRUCTTYPE(structType *s, SymbolTable *t, TYPETREELIST *ty){
	//printf("inside structTYPE\n");
	switch(s->kind){
		case fullStructTypeK:
			t = scopeSymbolTable(t);
			symSTRUCTLIST(s->val.left, t, ty);
			break;
		case emptyStructTypeK:
			break;
	}
}

void symSTRUCTLIST(structList *s, SymbolTable *t, TYPETREELIST *ty){
	//printf("inside structLIST\n");
        switch(s->kind){
                case singlestructK:
			//t = scopeSymbolTable(t);
                        symSTRUCTPARAM(s->val.singlestructE, t, ty);
                        //s->st = getCurrScope(t);
			break;
                case manystructK:
			
                        symSTRUCTPARAM(s->val.manystructE.left, t, ty);
		//	printf("%d testest\n", ty->val.typetreelist.tytree->type);
			ty->val.typetreelist.tytreelist = NEW(TYPETREELIST);
                        symSTRUCTLIST(s->val.manystructE.right, t, ty->val.typetreelist.tytreelist);
		//	printf("%d testest\n", ty->val.typetreelist.tytree->type);
                        break;
        }
}

void symSTRUCTPARAM(param *p, SymbolTable *t, TYPETREELIST *ty){
	//printf("inside structPARAM\n");
        //printf("inside PARAM\n");
        switch(p->kind){
                case onlyparam:
                        //symTYPE(p->val.onlyE.type, t);
                        symSTRUCTTYPEIDLIST(p->val.onlyE.names, t, symTYPE(p->val.onlyE.type, t), ty);
                        break;
                case idparam:
			//idSet(p->val.idE.type);
                        symSTRUCTIDIDLIST(p->val.idE.names, t, p->val.idE.type, ty);
                        break;
        }
}

TYPETREELIST *symSTRUCTTYPEIDLIST(identifierList *i, SymbolTable *t, TYPETREE *ty, TYPETREELIST *tylist){
        //printf("inside structTYPEIDLIST\n");
	switch(i->kind){
                case singleidK:
			//printf("inside singleidK\n");
                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
			//printf("past if %s\n", i->val.singleE );
			tylist->idName = i->val.singleE;
			tylist->val.typetreelist.tytree = ty;
 			tylist->val.typetreelist.tytreelist = NULL;
			//printf("past setting values\n");	
			putSymbol(t, i->val.singleE, *ty);
                        return tylist;
			break;
                case multipleK:
			//printf("inside multiple\n");
                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        reportError("Error - variable %s already declared\n",i->lineno);
                                        exit(0);
                        }
			//printf("after symbol defined\n");
			//printf("%s\n", i->val.idListE.identifier);
			//printf("%s\n", tylist->idName);
			tylist->idName = i->val.idListE.identifier;
			//printf("%s\n", i->val.idListE.identifier);
                        tylist->val.typetreelist.tytree = ty;
                        putSymbol(t, i->val.idListE.identifier, *ty);
			//printf("before recurse\n");
			tylist->val.typetreelist.tytreelist = NEW(TYPETREELIST);
                        return symSTRUCTTYPEIDLIST(i->val.idListE.idList, t, ty, tylist->val.typetreelist.tytreelist);
                        break;
        }
}



TYPETREELIST *symPARAMTYPEIDLIST(identifierList *i, SymbolTable *t, TYPETREE *ty, TYPETREELIST *tylist){
        //printf("inside paramTYPEIDLIST\n");
        switch(i->kind){
                case singleidK:
                        //printf("inside singleidK\n");
                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
                        //printf("past if %s\n", i->val.singleE );
                        tylist->idName = i->val.singleE;
                        tylist->val.typetreelist.tytree = ty;
                        tylist->val.typetreelist.tytreelist = NULL;
                        //printf("past setting values\n");
                        return tylist;
                        break;
                case multipleK:
                        //printf("inside multiple\n");
                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        reportError("Error - variable %s already declared\n",i->lineno);
                                        exit(0);
                        }
                        //printf("after symbol defined\n");
                        //printf("%s\n", i->val.idListE.identifier);
                        //printf("%s\n", tylist->idName);
                        tylist->idName = i->val.idListE.identifier;
                        //printf("%s\n", i->val.idListE.identifier);
                        tylist->val.typetreelist.tytree = ty;
                        //printf("before recurse\n");
                        tylist->val.typetreelist.tytreelist = NEW(TYPETREELIST);
                        return symPARAMTYPEIDLIST(i->val.idListE.idList, t, ty, tylist->val.typetreelist.tytreelist);
                        break;
        }
}





TYPETREELIST *symSTRUCTIDIDLIST(identifierList *i, SymbolTable *t, char *idtype, TYPETREELIST *tylist){
        //printf("inside structIDIDLIST\n");
	switch(i->kind){
                case singleidK:
                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
                        if(typeDefined(t, idtype) == 0){
                                printf("Error - type %s not defined\n", idtype);
                                exit(0);
                        }
                        else{
				tylist->idName = i->val.singleE;
				tylist->val.typetreelist.tytree = &getSymbol(t, idtype)->type;
                                tylist->val.typetreelist.tytreelist = NULL;
				putSymbolIdType(t, i->val.singleE, idtype);
                        }
			return tylist;
                        break;
                case multipleK:
                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
                        if(typeDefined(t, idtype) == 0){
                                printf("Error - type %s not defined\n", idtype);
                                exit(0);
                        }
                        else{
				tylist->idName = i->val.idListE.identifier;
				tylist->val.typetreelist.tytree = &getSymbol(t, idtype)->type;
                                putSymbolIdType(t, i->val.idListE.identifier, idtype);;
                               	return symSTRUCTIDIDLIST(i->val.idListE.idList, t, idtype, tylist->val.typetreelist.tytreelist);
                        break;
                        }
                }
}


TYPETREELIST *symPARAMIDIDLIST(identifierList *i, SymbolTable *t, char *idtype, TYPETREELIST *tylist){
        //printf("inside paramIDIDLIST\n");
        switch(i->kind){
                case singleidK:
                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
                        if(typeDefined(t, idtype) == 0){
                                printf("Error - type %s not defined\n", idtype);
                                exit(0);
                        }
                        else{
                                tylist->idName = i->val.singleE;
                                tylist->val.typetreelist.tytree = &getSymbol(t, idtype)->type;
                                tylist->val.typetreelist.tytreelist = NULL;
                        }
                        return tylist;
                        break;
                case multipleK:
                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
                        if(typeDefined(t, idtype) == 0){
                                printf("Error - type %s not defined\n", idtype);
                                exit(0);
                        }
                        else{
                                tylist->idName = i->val.idListE.identifier;
                                tylist->val.typetreelist.tytree = &getSymbol(t, idtype)->type;
                                return symPARAMIDIDLIST(i->val.idListE.idList, t, idtype, tylist->val.typetreelist.tytreelist);
                        break;
                        }
                }
}







void symIDIDLIST(identifierList *i, SymbolTable *t, char *idtype){
	//printf("inside IDIDLIST\n");
        switch(i->kind){
                case singleidK:
	//		printf("variable: %s\n", i->val.singleE);
                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
			if(typeDefined(t, idtype) == 0){
				printf("Error - type %s not defined\n", idtype);
                                exit(0);
			}
			else{
	//			printf("past type defined\n");
				putSymbolIdType(t, i->val.singleE, idtype);
			}
                        break;
                case multipleK:
                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s already declared\n",i->val.singleE);
                                        exit(0);
                        }
                        if(typeDefined(t, idtype) == 0){
                        	printf("Error - type %s not defined\n", idtype);
                                exit(0);
			}
			else{
				putSymbolIdType(t, i->val.idListE.identifier, idtype);;
				symIDIDLIST(i->val.idListE.idList, t, idtype);
                        break;
        		}
		}
}



void symIDEXPLIST(identifierList *i, expList *e, SymbolTable *t){
	//printf("inside IDEXPLIST\n");
        switch(i->kind){
                case singleidK:
                        switch(e->kind){
                                case ExpK:
                                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        printf("Error - %s has already been defined in its current scope\n",i->val.singleE);
                                        exit(0);

                                        }
                                        else{
                                        symEXP(e->val.expE, t);
                                        i->type = e->val.expE->type;//returns a TypeTree
	//				printf("%d\n", i->type.type);
					putSymbol(t, i->val.singleE, i->type);
                                        }
                                        break;
                                case expListK:
                                        break;
                        break;
			}
                case multipleK:
                        switch(e->kind){
                                case ExpK:
                                        break;
                                case expListK:
                                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s has already been declared\n",i->val.singleE);
                                        exit(0);
                                        } else {
					symEXP(e->val.expListE.expression, t);
					i->type = e->val.expListE.expression->type;
					putSymbol(t, i->val.idListE.identifier, i->type);
                                        symIDEXPLIST(i->val.idListE.idList, e->val.expListE.expressionList,  t);
                                        }
                                        break;
                        }
                        break;
	}	
}
		

void symIDTYPEEXPLIST(identifierList *i, expList *e, SymbolTable *t, TYPETREE *s){
        //printf("inside IDTYPEEXPLIST\n");
	switch(i->kind){
                case singleidK:
                        switch(e->kind){
                                case ExpK:
                                        if(symbolDefined(t, i->val.singleE) == 1) {
                                        	printf("Error - %s has already been defined in its current scope\n",i->val.singleE);
                                        exit(0);
					}
					symEXP(e->val.expE, t);
					//printf("%d here?\n", e->val.expE->type.type);
					if(e->val.expE->type.type != s->type){
						printf("Error - expression does not match type defined\n");
					exit(0);
                                        }else{
                                        i->type = e->val.expE->type;
                                        //printf("%d\n", i->type.type);
                                        putSymbol(t, i->val.singleE, i->type);
                                        }
                                        break;
                                case expListK:
                                        break;
                        }
			break;
                case multipleK:
                        switch(e->kind){
                                case ExpK:
                                        break;
                                case expListK:
                                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s has already been declared\n",i->val.singleE);
                                        exit(0);
                                        }
					symEXP(e->val.expListE.expression, t); 
					if(e->val.expListE.expression->type.type != s->type){
                                                printf("Error - expression does not match type defined\n");
					exit(0);
					} else {
                                        //to TA's: note that we give a type to identifiers because we weren't able to get anything other than identifiers on the LH side of assignments and the like
                                        //HERE an Id list can't have one type
					//i->type.type = e->val.expListE.expression->type.type;
                                        i->type = e->val.expListE.expression->type;
					putSymbol(t, i->val.idListE.identifier, i->type);                                      
                                        symIDTYPEEXPLIST(i->val.idListE.idList, e->val.expListE.expressionList, t, s);
                                        }
                                        break;
                        }
                        break;
        }
}

void symIDIDTYPEEXPLIST(identifierList *i, expList *e, SymbolTable *t, char *idtype){
        //printf("inside IDIDTYPEEXPLIST\n");
	switch(i->kind){
                case singleidK:
                        switch(e->kind){
                                case ExpK:
                                        if(symbolDefined(t, i->val.singleE) == 1) {
                                                printf("Error - %s has already been defined in its current scope\n",i->val.singleE);
                                        exit(0);
                                        }
					if(typeDefined(t, idtype) == 0){
                                		printf("Error - type %s not defined\n", idtype);
                                		exit(0);
                        		}
					
					SYMBOL *s;
					s = getSymbol(t, idtype);
					
                                        symEXP(e->val.expE, t);
                                        if(e->val.expE->type.type != s->type.type){
                                                printf("Error - expression does not match type defined\n");
                                        exit(0);
                                        }else{
                                        i->type.idType = idtype;
                                        //printf("%d\n", i->type.idType);
					putSymbolIdType(t, i->val.singleE, idtype);
                                        }
                                        break;
                                case expListK:
                                        break;
                        }
			break;
		case multipleK:
                        switch(e->kind){
                                case ExpK:
                                        break;
                                case expListK:
                                        if(symbolDefined(t, i->val.idListE.identifier) == 1) {
                                        printf("Error - variable %s has already been declared\n",i->val.singleE);
                                        exit(0);
					}
                                        if(typeDefined(t, idtype) == 0){
                                                printf("Error - type %s not defined\n", idtype);
                                                exit(0);
                                        }
			
					SYMBOL *s;
					s = getSymbol(t, idtype);

                                        symEXP(e->val.expListE.expression, t);
                                        if(e->val.expListE.expression->type.type != s->type.type){
                                                printf("Error - expression does not match type defined\n");
                                        exit(0);
                                        } else {
                                        i->type.idType = idtype;
                                        putSymbolIdType(t, i->val.idListE.identifier, idtype);  
                                        symIDIDTYPEEXPLIST(i->val.idListE.idList, e->val.expListE.expressionList,  t, idtype);
                                        }
                                        break;
                        }
                        break;
        }
}


void symTYPEDEC(typeDec *d, SymbolTable *t){
	//printf("inside TYPEDEC\n");
	switch(d->kind){
                case singleDecK:
                        symTYPELINE(d->val.singleDecE, t);
                        break;
                case manyDecK:
                        symTYPELINELIST(d->val.manyDecE, t);
                        break;
        }
}

void symTYPELINELIST(typeLineList *l, SymbolTable *t){
	//printf("inside TYPELINELIST\n");
	switch(l->kind){
                case tLineK:
                        symTYPELINE(l->val.tLine, t);
                        break;
                case tLineListK:
                        symTYPELINE(l->val.tLineListE.tLine, t);
                        symTYPELINELIST(l->val.tLineListE.tLineList, t);
                        break;
        }
}


void symTYPELINE(typeLine *l, SymbolTable *t){
	//printf("inside TYPELINE\n");
        TYPETREE *tree;
        tree = NEW(TYPETREE);
	switch(l->kind){
                case singletypeK:
                        if(typeAlreadyInScope(t, l->val.singleE.name) == 1){
                        printf("Error - This type %s has already been defined as a type in this scope\n",l->val.singleE.name);
                        exit(0);
			}
			if(symbolDefined(t, l->val.singleE.name) == 1){
                        printf("Error - The identifier %s has already been defined as a variable in this scope\n", l->val.singleE.name);
                        exit(0);
                        }else{
			tree = symTYPE(l->val.singleE.right,t);
			//printf("what's up with the tree? %d\n\n", tree->type);
			//printf("the type I'm putting in is %s\n\n", l->val.singleE.name);
                        putSymbolTypeDec(t, l->val.singleE.name, *tree);
                        }
                        break;
                case singleIDK:
			//printf("Inside singleID\n");
			if(typeDefined(t, l->val.singleIDE.right) == 0){
                        printf("Error - The type %s being assigned has not been defined\n",l->val.singleIDE.right);
                        exit(0);
                        }
			if(symbolDefined(t, l->val.singleIDE.name) == 1){
			printf("Error - The identifier %s has already been defined as a variable in this scope\n", l->val.singleIDE.name);
			exit(0);
			}
                        if(typeAlreadyInScope(t, l->val.singleIDE.name) == 1){
                        printf("Error - This type %s has already been defined as a type in this scope\n",l->val.singleIDE.name);
                        exit(0);
                        }else{
			//printf("before putsymbol\n");
			//printf("%s\n", l->val.singleIDE.right);
			//printf("%s\n", l->val.singleIDE.name);
                        putSymbolIdTypeDec(t, l->val.singleIDE.name, l->val.singleIDE.right);
			}//ISSUE HERE WITHE INPUTTING INTO SYMBOL TABLE NOT SURE WHY
                        break;
		case structK:
			break;
		case structIDK:
			break;
		case emptyType:
			break;
		case structTypeK:
			break;
        }
	free(tree);
}

void symFUNCDEC(funcDec *f, SymbolTable *t, int i){
	//printf("inside FUNCDEC\n");
	TYPETREE *tyt;
	tyt = NEW(TYPETREE);
	switch(f->kind){
                case typeful:
			//printf("inside typeful %s \n", f->val.typefulE.identifier );
                        if(symbolDefined(t, f->val.typefulE.identifier) == 1){
                        printf("Error - %s already defined in this scope\n",f->val.typefulE.identifier);
                        exit(0);
                        } else {
                        tyt = symTYPE(f->val.typefulE.type,t);
			//t = scopeSymbolTable(t);
			tyt->val.structType = NEW(TYPETREELIST);
                        symPARAMLIST(f->val.typefulE.pList, t, tyt->val.structType);
			//f->st = getCurrScope(t);
			//printf("ttl check %s\n", tyt->val.structType->idName);
			putSymbolFuncDec(t, f->val.typefulE.identifier, *tyt);
			t = scopeSymbolTable(t);
			symPARAMLISTFIX(f->val.typefulE.pList, t);
			symBLOCK(f->val.typefulE.Blocky, t, f->val.typefulE.identifier, i);
                        }
                        break;

                case typeless:
			//printf("inside typeless %s \n", f->val.typelessE.identifier); 
                        if(symbolDefined(t, f->val.typelessE.identifier) == 1){
                        printf("Error - %s already defined in this scope\n",f->val.typelessE.identifier);
                        exit(0);
                        } else {
			tyt->type = noTYPE;
			//t = scopeSymbolTable(t)
			tyt->val.structType = NEW(TYPETREELIST);;
                        symPARAMLIST(f->val.typelessE.pList, t, tyt->val.structType);
			putSymbolFuncDec(t, f->val.typefulE.identifier, *tyt);
			//f->st = getCurrScope(t);
                        t = scopeSymbolTable(t);
			symPARAMLISTFIX(f->val.typelessE.pList, t);
			symBLOCK(f->val.typelessE.Blocky, t, f->val.typefulE.identifier, i);
                        }
                        break;
                case typeIDK:
			//printf("inside typeIDK %s \n", f->val.typeIDE.identifier);
			//printf("inside typeIDK\n");
                        if(symbolDefined(t, f->val.typeIDE.identifier) == 1){
                        printf("Error - %s already defined in this scope\n",f->val.typeIDE.identifier);
                        exit(0);
                        } else if(typeDefined(t, f->val.typeIDE.type) == 0){
                        printf("Error - %s is not defined as a type\n",f->val.typeIDE.type);      
                        exit(0);
                        }
			else{
			tyt->type = getPrimitive(t, f->val.typeIDE.type);
			tyt->val.structType = NEW(TYPETREELIST);
                        //t = scopeSymbolTable(t);
			symPARAMLIST(f->val.typeIDE.pList, t, tyt->val.structType);
                        putSymbolIdFuncDec(t, f->val.typeIDE.identifier, f->val.typeIDE.type);
			//f->st = getCurrScope(t);
			t = scopeSymbolTable(t);
			symPARAMLISTFIX(f->val.typeIDE.pList, t);
			symBLOCK(f->val.typeIDE.Blocky, t, f->val.typeIDE.identifier, i);
                        break;
			}
		case noIDK://matches to noIDE
			//printf("inside noIDK %s \n", f->val.noIDE.identifier);
			//printf("inside noIDK\n");
                        if(symbolDefined(t, f->val.noIDE.identifier) == 1){
                        printf("Error - %s already defined in this scope\n",f->val.noIDE.identifier);
                        exit(0);
                        } else if(typeDefined(t, f->val.noIDE.name) == 0){
                        printf("Error - %s is not defined as a type\n",f->val.noIDE.name);
                        exit(0);
                        }
			else{
			tyt->type = noTYPE;
                        putSymbolIdFuncDec(t,f->val.noIDE.identifier, f->val.noIDE.name);
			t = scopeSymbolTable(t);
                        symBLOCK(f->val.noIDE.Blocky, t, f->val.noIDE.identifier, i);
                        }
                        break;
                case nonoK://matches to noparamnotype
			//printf("inside nonoK %s \n", f->val.noparamnotype.identifier);
			//printf("inside nonoK\n");
                        if(symbolDefined(t, f->val.noparamnotype.identifier) == 1){
                        printf("Error - %s already defined in this scope\n",f->val.noparamnotype.identifier);
                        exit(0);
                        }else{
			tyt->type = noTYPE;
			putSymbolFuncDec(t, f->val.noparamnotype.identifier, *tyt);
                        t = scopeSymbolTable(t);
                        symBLOCK(f->val.noparamnotype.Blocky, t, f->val.noparamnotype.identifier, i);
                        }
                        break;
                case noK://matches to notypeE
			//printf("inside noK %s \n", f->val.notype.identifier);
			//printf("inside noK\n");
                        if(symbolDefined(t, f->val.notype.identifier) == 1){
                        printf("Error - %s already defined in this scope\n",f->val.notype.identifier);
                        exit(0);
			}
			tyt = symTYPE(f->val.notype.type,t);
                        putSymbolFuncDec(t, f->val.notype.identifier, *tyt); 
                        t = scopeSymbolTable(t);
			symBLOCK(f->val.notype.Blocky, t, f->val.notype.identifier, i);
                        break;
        }
}

TYPETREELIST *symPARAM(param *p, SymbolTable *t, TYPETREELIST *tytreelist){
	//printf("inside PARAM\n");
	switch(p->kind){
		case onlyparam:
			//tytreelist = NEW(TYPETREELIST);
			//printf("the type returned is %d\n", symTYPE(p->val.onlyE.type, t)->type);
			return symPARAMTYPEIDLIST(p->val.onlyE.names, t, symTYPE(p->val.onlyE.type, t), tytreelist);
			break;
		case idparam:
			//tytreelist = NEW(TYPETREELIST);
			return symPARAMIDIDLIST(p->val.idE.names, t, p->val.idE.type, tytreelist);
			break;
	}
}

void symPARAMLIST(paramList *p, SymbolTable *t, TYPETREELIST *tytreelist){
        //printf("inside PARAMLIST\n");
	TYPETREELIST *ttl;
        ttl = NEW(TYPETREELIST);
	switch(p->kind){
                case emptyParamListK://not actually empty
			//printf("into the last\n");
                        symPARAM(p->val.p, t, tytreelist);
                        break;
                case fullParamListK:
			//printf("inside full param list\n");
                        ttl = symPARAM(p->val.fullE.p, t, tytreelist);
			//printf("past here\n");
			ttl->val.typetreelist.tytreelist = NEW(TYPETREELIST);
                        symPARAMLIST(p->val.fullE.pl, t, ttl->val.typetreelist.tytreelist);//->val.typetreelist.tytreelist);
          		//printf("past paramlist?\n");
	                break;
        }
}



void symPARAMFIX(param *p, SymbolTable *t){
        //printf("inside PARAMFIX\n");
        switch(p->kind){
                case onlyparam:
                        symTYPEIDLIST(p->val.onlyE.names, t, symTYPE(p->val.onlyE.type, t));
                        break;
                case idparam:
                        symIDIDLIST(p->val.idE.names, t, p->val.idE.type);
                        break;
        }
}

void symPARAMLISTFIX(paramList *p, SymbolTable *t){
        //printf("inside PARAMLISTFIX\n");
        switch(p->kind){
                case emptyParamListK://not actually empty
                        //printf("into the last\n");
                        symPARAMFIX(p->val.p, t);
                        break;
                case fullParamListK:
                        symPARAMFIX(p->val.fullE.p, t);
                        //printf("past here\n");
                        symPARAMLISTFIX(p->val.fullE.pl, t);//->val.typetreelist.tytreelist);
                        //printf("past paramlist?\n");
                        break;
        }
}


void symBLOCK(block *b, SymbolTable *t, char* currFunc, int i){
	symSTATELIST(b->val.left, t, currFunc, i);
	if(i==1){
	printCurrScope(t);
	}
}

void symSTATELIST(statementList *s, SymbolTable *t, char* currFunc, int i){
        switch(s->kind){
		//printf("inside statelist\n");
                case emptyStateListK:
		//	printf("was WHAT?! empty\n");
                        break;
                case stateListK:
		//	printf("no empty\n");
                        symSTATEMENT(s->val.stateListE.state, t, currFunc, i);
                        symSTATELIST(s->val.stateListE.stateList, t, currFunc, i);
                        break;
        }
}

void symSTATEMENT(statement *s, SymbolTable *t, char* currFunc, int i){
        switch(s->kind){
                case ssimpleK:
                        symSIMPLESTATE(s->val.simple, t);
                        break;
                case sprintK:
                        symPRINT(s->val.print, t);
                        break;
                case sreturnK:
                        symRETURN(s->val.returned, t, currFunc);
                        break;
                case sifK:
                        symIFSTATE(s->val.iffy, t, currFunc, i);
                        break;
                case sforK:
                        symFORLOOP(s->val.loop, t, currFunc, i);
                        break;
                case sswitchK:
                        symSWITCHSTATE(s->val.switchy, t, currFunc, i);
                        break;
                case svar:
                        symVARDEC(s->val.var, t);
                        break;
                case stype:
                        symTYPEDEC(s->val.tvar, t);
                        break;
                case sblock:
			t = scopeSymbolTable(t);
                	symSTATELIST(s->val.block, t, currFunc, i);
			if(i==1){
                        printCurrScope(t);
			}
			break;
                case sbreakK:
                        break;
                case scontinueK:
                        break;
        }
}



void symRETURN(returning *r, SymbolTable *t, char* currFunc){
	//printf("inside symRETURN\n");
	//printf("%s\n", currFunc);
	SYMBOL *temp;
	temp = NEW(SYMBOL);
	temp = getFunc(t, currFunc);
	//printf("past getfunc\n");
	//printf("%d\n", temp->type.type);
        switch(r->kind){
                case returnK:	
			if(temp->type.type != noTYPE){
                        	printf("Error - function missing valid return type\n");
				exit(0);
                        	
                	}
                	break;
                case returnExpK:
			symEXP(r->val.returnExpE.expression, t);
	//		printf("%d blahblah\n", temp->type.type);
	//		printf("%d bllosl\n", r->val.returnExpE.expression->type.type);
			//if(temp->type.idType != NULL){
			//	if(r->val.returnExpE.expression->type.idType != temp->type.idType){
			//		printf("Error - function return type not matching function output type\n");
			//		exit(0);
			//	}
			//}
			//else{
	//			printf("%d\n", r->val.returnExpE.expression->type.type);
	//			printf("%d\n", temp->type.type);
                		if(r->val.returnExpE.expression->type.type != temp->type.type){
                        		printf("Error - function return type not matching function output type\n");
                			exit(0);
				}
			//}
			break;
	}
}


void typeImplementationIncDecStatement(incDecStmt *i, SymbolTable *t){
		switch(i->kind){
			case incK:
	//			printf("inside incr\n");
				symEXP(i->val.up, t);
                		if((i->val.up->type.type!=intTYPE) && (i->val.up->type.type!=floatTYPE) && (i->val.up->type.type!=runeTYPE)){
                        		printf("Error - '++' and '--' may only be used with int or float variables\n");
                        		exit(0);
                		}
				break;
			case ddecK:
	//			printf("inside decre\n");
				symEXP(i->val.down, t);
	//			printf("the type up here is %d\n", i->val.down->type.type);
				if((i->val.down->type.type!=intTYPE)&&(i->val.down->type.type!=floatTYPE)&&(i->val.down->type.type!=runeTYPE)){
					printf("Error - '++' and '--' may only be used with int or float variables\n");
				exit(0);
				}
				break;
		}
}


void symSTMTEXP(stmtExp *s, SymbolTable *t){
        if(s->kind==stmtExpK){
                symEXP(s->val.expStmt, t);
        }
}

void symPRINT(print *p,  SymbolTable *t){
        //printf("inside print\n");
	switch(p->kind){
                case printK:
                symEXPLIST(p->val.printE.expressionList, t);
                break;

                case printlnK:
	//	printf("inside print ln\n");
                symEXPLIST(p->val.printlnE.expressionList, t);
                break;
		
		case printemptyK:
		break;
	
		case printlnemptyK:
		break;
	}
}

void symFORLOOP(forLoop *f, SymbolTable *t, char *currFunc, int i){
        switch(f->kind){
                case stateListLoopK:
		t = scopeSymbolTable(t);
                symBLOCK(f->val.stateListLoopE.stateList,t, currFunc, i);
                break;

                case condLoopK:
		t = scopeSymbolTable(t);
                symCOND(f->val.condLoopE.cond, t);
		if(f->val.condLoopE.cond->type.idType != NULL){
			if(getPrimitive(t, f->val.condLoopE.cond->type.idType) != boolTYPE){
				printf("Error - condition in for loop must be bool\n");
                        	exit(0);
                	}
		} else {
	//		printf("%d\n", f->val.condLoopE.cond->type.type); 
			if(f->val.condLoopE.cond->type.type != boolTYPE){
				printf("Error - condition in for loop must be bool\n");
                                exit(0);
                        }
		}
//		t = scopeSymbolTable(t);
                symBLOCK(f->val.condLoopE.stateList,t, currFunc, i);
                break;

                case idCondLoopK:
		t = scopeSymbolTable(t);
                symSIMPLESTATE(f->val.idCondLoopE.simpleState1, t);
                symCOND(f->val.idCondLoopE.cond, t);
                if(f->val.idCondLoopE.cond->type.idType != NULL){
			if(getPrimitive(t, f->val.idCondLoopE.cond->type.idType) != boolTYPE){
				printf("Error - condition in for loop must be bool\n");
                                exit(0);
                        }
                } else { 
                        if(f->val.idCondLoopE.cond->type.type != boolTYPE){
				printf("Error - condition in for loop must be bool\n");
                                exit(0);
                        }
                }
                symSIMPLESTATE(f->val.idCondLoopE.simpleState2, t);
                //t = scopeSymbolTable(t);
		symBLOCK(f->val.idCondLoopE.stateList,t, currFunc, i);
		break;
		case nocondK:
		t = scopeSymbolTable(t);
		symSIMPLESTATE(f->val.nocondE.simpleState1, t);
                symSIMPLESTATE(f->val.nocondE.simpleState2, t);
                //t = scopeSymbolTable(t);
		symBLOCK(f->val.nocondE.stateList,t, currFunc, i);
		break;
	}
	//printSymbolTable(t);
}

void symSIMPLESTATE(simpleStatement *s, SymbolTable *t){
	//printf("inside SIMPLESTATE\n");
	switch(s->kind){
                case emptyStmtK:
			//printf("empty\n");
                        break;
                case assignK:
		//	printf("assign\n");
                        symASSIGNMENT(s->val.assignE, t);
                        break;
                case incDecK:
			//printf("incdec\n");
	//		printf("incdec\n");
                        typeImplementationIncDecStatement(s->val.incDecE, t);
                        break;
                case sstmtExpK:
			//printf("sstmtexp\n");
                        symSTMTEXP(s->val.stmtexp, t);
                        break;
                case shortK:
	//		printf("shork\n");
	//		printf("shortk\n");
                        symEXPLIST(s->val.shortE.right, t);
	//		printf("past explist\n");
			if(atLeastOne(s->val.shortE.left, t) == 0) {
				reportError("Error - at least one variable needs to be undefined in the current scope",s->val.shortE.left->val.expE->lineno);
                        }
	//		printf("past if test\n");
			symSHORTEXPLIST(s->val.shortE.left, s->val.shortE.right, t);
                        break;
        }
}


void symASSIGNMENT(assignment *a, SymbolTable *t){
	//printf("inside assign\n");
	switch(a->kind){
		case idListAssK:
			symEXPLIST(a->val.idListAssE.idList, t);
			symEXPLIST(a->val.idListAssE.expressionList, t);
			symASSIGNEXPLIST(a->val.idListAssE.idList, a->val.idListAssE.expressionList, t);
			break;
		case selfOpAssK:
			symEXP(a->val.opSelfAssE.identifier, t);
			symEXP(a->val.opSelfAssE.expression, t);
			if(a->val.opSelfAssE.identifier->type.type != a->val.opSelfAssE.expression->type.type){
				reportError("Error - types in selfOp do not match", a->val.opSelfAssE.identifier->lineno);
			}
			break;
	}
}

void symASSIGNEXPLIST(expList *i, expList *e, SymbolTable *t){
       //printf("inside ASIGNEXPLIST\n");
       switch(i->kind){
                case ExpK:
                        switch(e->kind){
                                case ExpK:
	//				printf("before exp\n");
                                        symEXP(i->val.expE, t);
	//				printf("the type returned left is: %d\n", i->val.expE->type.type);
					
                                        symEXP(e->val.expE, t);
	//				printf("the type returned right is: %d\n", e->val.expE->type.type);
					//printf("%d", i->val.expE->val.addOpE->val.mulOpE->val.factorE->type.type);

					//printf("%d", e->val.expE->type.type);
//					if(symbolDefined(t, i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE) == 0){
//                                                reportError("Error - id in assignment has not been defined", i->val.expE->lineno);
//                                        }
                                        if(i->val.expE->type.type != e->val.expE->type.type){
                                                reportError("Error - a type in assignment does not match", e->val.expE->lineno);
                                        }
                                        break;
                                case expListK:
                                        break;
                        break;
                        }
                case expListK:
                        switch(e->kind){
                                case ExpK:
                                        break;
                                case expListK:
                                        symEXP(e->val.expListE.expression, t);
//                                        if(symbolDefined(t, i->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE) == 0){
//						reportError("Error - id in assignment has not been defined", i->val.expE->lineno);
//					}
					if((i->val.expListE.expression->type.type != e->val.expListE.expression->type.type)){
                                                reportError("Error - type of assignment for declared variables do not match", e->val.expE->lineno);
                                        }
                                        symASSIGNEXPLIST(i->val.expListE.expressionList, e->val.expListE.expressionList,  t);
                                        break;
                        }
                        break;
        }
}


void symSHORTEXPLIST(expList *i, expList *e, SymbolTable *t){
	//printf("inside SHORTEXPLIST\n"); 
	TYPETREE *typetree;
	typetree = NEW(TYPETREE);
       switch(i->kind){
                case ExpK:
                        switch(e->kind){
                                case ExpK:
	//				printf("single\n");
					symEXP(e->val.expE, t);
	//				printf("the expression type is %d\n", e->val.expE->type.type);	
	//				printf("the name %s\n", i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE);
					if((symbolDefined(t, i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE) == 1)){
	//					printf("symbol defined\n");
						symEXP(i->val.expE, t);
						if(i->val.expE->type.type != e->val.expE->type.type){
                                                	reportError("Error - types in short var dec do not match", e->val.expE->lineno);//newerror
                                        	}
					}
					else{
						if(e->val.expE->type.idType != NULL){
							putSymbolIdType(t, i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE, e->val.expE->type.idType);
						}else{
	//						printf("we got inside here\n");
							//printf("the type tree prim out %d\n", e->val.expE->type.val.arrayType->type);
							typetree = &e->val.expE->type;
	//						printf("after set\n");
							//printf("the next type %d\n", typetree->val.arrayType->type);
							putSymbol(t, i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE, *typetree);
						}
					}
	//				printf("end of single\n");
	
                                        break;
                                case expListK:
                                        break;
                        break;
                        }
                case expListK:
                        switch(e->kind){
                                case ExpK:
                                        break;
                                case expListK:
					symEXP(e->val.expListE.expression, t);
                                        if((symbolDefined(t, i->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE) == 1)){
                                                symEXP(i->val.expListE.expression, t);
                                                if(i->val.expListE.expression->type.type != e->val.expListE.expression->type.type){
                                                        reportError("Error - types in short var dec do not match", e->val.expListE.expression->lineno);//newerror
                                                }
                                        }
                                        else{
                                                if(e->val.expListE.expression->type.idType != NULL){
                                                        putSymbolIdType(t, i->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE, e->val.expListE.expression->type.idType);
                                                }else{
							typetree = &e->val.expListE.expression->type;
                                                        putSymbol(t, i->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE, *typetree);
                                                }
                                        }

					symSHORTEXPLIST(i->val.expListE.expressionList, e->val.expListE.expressionList,  t);
                                        break;
                        }
                        break;
        }
}

int atLeastOne(expList *e, SymbolTable *t){
	switch(e->kind){
		case ExpK:
			if(symbolDefined(t, e->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE) == 0){
				return 1;
			}else{ return 0;}
			break;
		case expListK:
			if(symbolDefined(t, e->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE) == 0){
				return 1;
			}else{
			return atLeastOne(e->val.expListE.expressionList, t);
			}
			break;
	}	
}


void symCOND(condition *c, SymbolTable *t){
	symEXP(c->val.condE, t);
	c->type.type = c->val.condE->type.type;
}


void symIFSTATE(ifStmt *i, SymbolTable *t, char* currFunc, int j){
	//printf("inside IFSTMT\n");
        SymbolTable *t1;
	t1 = initSymbolTable();
	switch(i->kind){

                case ifK://ifES
	//	printf("ifk\n");
		t = scopeSymbolTable(t);
                symCOND(i->val.ifES.ifCond, t);
                if(i->val.ifES.ifCond->type.type!=boolTYPE){
                        reportError("Error - condition in if statement must be of type boolean", i->val.ifES.ifCond->val.condE->lineno);
                }
                symBLOCK(i->val.ifES.stateList, t, currFunc, j);
                break;

                case ifelseS://ifelseE
	//	printf("ifelseK\n");
		t1 = scopeSymbolTable(t);
                symSIMPLESTATE(i->val.ifelseE.Simple, t1);
                symCOND(i->val.ifelseE.ifCond, t1);
                if(i->val.ifelseE.ifCond->type.type !=boolTYPE){
                        reportError("Error - condition in if/else statement must be of type boolean", i->val.ifelseE.ifCond->val.condE->lineno);
                }
                symBLOCK(i->val.ifelseE.stateList1, t1, currFunc, j);
                t = scopeSymbolTable(t);
		symSIMPLESTATE(i->val.ifelseE.Simple, t);
		symBLOCK(i->val.ifelseE.stateList2, t, currFunc, j);
                break;

                case ifelseifS://ifelseelseE
	//	printf("ifelseifK\n");
		t1 = scopeSymbolTable(t);
                symSIMPLESTATE(i->val.ifelseelseE.Simple, t1);
		symCOND(i->val.ifelseelseE.ifCond,t1);
                if(i->val.ifelseelseE.ifCond->type.type!=boolTYPE){
                        reportError("Error - condition in if/else statement must be of type boolean", i->val.ifelseelseE.ifCond->val.condE->lineno);
                }
                symBLOCK(i->val.ifelseelseE.stateList1, t1, currFunc, j);
                t = scopeSymbolTable(t);
		symSIMPLESTATE(i->val.ifelseelseE.Simple, t);
		symIFSTATE(i->val.ifelseelseE.recurse, t, currFunc, j);
                break;

		case ifS://ifE
	//	printf("ifS\n");
		t = scopeSymbolTable(t);
		symSIMPLESTATE(i->val.ifE.Simple, t);
                symCOND(i->val.ifE.ifCond,t);
                if(i->val.ifE.ifCond->type.type!=boolTYPE){
                        reportError("Error - condition in if statement must be of type boolean", i->val.ifE.ifCond->val.condE->lineno);
                }
                symBLOCK(i->val.ifE.stateList, t, currFunc, j);
                break;

                case ifelseK://ifElseES
	//	printf("ifelseS\n");
		t1 = scopeSymbolTable(t);
                symCOND(i->val.ifElseES.ifCond, t1);
                if(i->val.ifElseES.ifCond->type.type!=boolTYPE){
                        reportError("Error - condition in if/else statement must be of type boolean",i->val.ifElseES.ifCond->val.condE->lineno);
                }
                symBLOCK(i->val.ifElseES.stateList1, t1, currFunc, j);
                t = scopeSymbolTable(t);
		symBLOCK(i->val.ifElseES.stateList2, t, currFunc, j);
                break;

                case ifelseifK://ifelseelseES
	//	printf("ifelseifS\n");
                t1 = scopeSymbolTable(t);
		symCOND(i->val.ifelseelseES.ifCond, t1);
                if(i->val.ifelseelseES.ifCond->type.type!=boolTYPE){
                        reportError("Error - condition must be boolean", i->val.ifelseelseES.ifCond->val.condE->lineno);
                }
                symBLOCK(i->val.ifelseelseES.stateList1, t1, currFunc, j);
                t = scopeSymbolTable(t);
		symIFSTATE(i->val.ifelseelseES.recurse, t, currFunc, j);
                break;
}
}

void symSWITCHSTATE(switchStmt *s, SymbolTable *t, char *currFunc, int i){
	//printf("inside SWITCH\n");
	t = scopeSymbolTable(t);
        switch(s->kind){
                case leftright:
			//printf("inside leftright\n");
                        symSIMPLESTATE(s->val.leftrightE.simple, t);
                        symEXP(s->val.leftrightE.e, t);
                        symCASELIST(s->val.leftrightE.cases, t, s->val.leftrightE.e->type.type, currFunc, i);
                        break;
                case right:
			//printf("inside right\n");
                        symEXP(s->val.rightE.e, t);
                        symCASELIST(s->val.rightE.cases, t, s->val.rightE.e->type.type, currFunc, i);
                        break;
                case left:
			//printf("inside left\n");
                        symSIMPLESTATE(s->val.leftE.simple, t);
                        symCASELIST(s->val.leftE.cases, t, noTYPE, currFunc, i);
                        break;
                case none:
			//printf("inside case\n");
                        symCASELIST(s->val.noneE.cases, t, noTYPE, currFunc, i);
                        break;
        }
}

void symCASELIST(caseList *c, SymbolTable *t, SymbolType ty, char *currFunc, int i){
        //printf("inside caselist\n");
	switch(c->kind){
                case emptyCase:
                        break;
                case fullCase:
                        symCASEFALL(c->val.caseX.casey, t, ty, currFunc, i);
                        symCASELIST(c->val.caseX.right, t, ty, currFunc, i);
                        break;
        }
}

void symCASEFALL(caseFall *c, SymbolTable *t, SymbolType ty, char *currFunc, int i){
        //printf("inside casefall\n");
	switch(c->kind){
                case caseX:
                        symEXPLIST(c->val.caseE.left, t);
                        caseExpCheck(c->val.caseE.left, t, ty);
			symSTATELIST(c->val.caseE.right, t, currFunc, i);
                        break;
                case defaultX:
                        symSTATELIST(c->val.defaultE, t, currFunc, i);
                        break;
        }
}


void caseExpCheck(expList *e, SymbolTable *t, SymbolType ty){
	//printf("inside caseExpCheck\n");
	switch(e->kind){
		case ExpK:
			symEXP(e->val.expE, t);
				if(e->val.expE->type.type != ty){
					if(ty == noTYPE){
						break;
					}
					else{
						reportError("Error - expression type in case does not match switch expression type defined", e->val.expE->lineno); //newerror
					}
				}
			break;
		case expListK:
			symEXP(e->val.expListE.expression, t);
				if(e->val.expListE.expression->type.type != ty){
					if(ty == noTYPE){
                                       	       break;
                                       	}
                          		else{  
                                       		reportError("Error - expression type in case does not match switch expression type defined", e->val.expE->lineno); //newerror
					}	
				}
			caseExpCheck(e->val.expListE.expressionList, t, ty);
			break;
	}
}

void symEXPLIST(expList *e, SymbolTable *t){
        switch(e->kind){
                case ExpK:
                symEXP(e->val.expE, t);
                break;

                case expListK:
                symEXP(e->val.expListE.expression, t);
                symEXPLIST(e->val.expListE.expressionList, t);
                break;
}
}


void checkArgumentTypes(type *t,expList *e){
}
//will need this eventually to typecheck a function call


int comparable(exp *a,exp *b){
        if(!((a->type.type==b->type.type)||((a->type.type==intTYPE)&&((b->type.type==intTYPE)||(b->type.type==runeTYPE)))||((a->type.type==runeTYPE)&&((b->type.type==intTYPE)||(b->type.type==runeTYPE))))){
                return 0;
        }
        return 1;
}

int ordered(exp *e){
        if(e->type.type==intTYPE||e->type.type==floatTYPE||e->type.type==stringTYPE||e->type.type==runeTYPE){
                return 1;
        }
        return 0;
}

int orderedAddOp(addOp *e){
        if(e->type.type==intTYPE||e->type.type==floatTYPE||e->type.type==stringTYPE||e->type.type==runeTYPE){
                return 1;
        }
        return 0;
}


void symEXP(exp *e, SymbolTable *t){
	//printf("inside EXP\n");
        switch(e->kind){
                case orK:
                symEXP(e->val.orE.left, t);
                symEXP(e->val.orE.right, t);

		if((e->val.orE.left->type.type != boolTYPE) || (e->val.orE.right->type.type != boolTYPE)){
			printf("Error - both operands of '||' must be of type bool\n");
                        exit(0);
                }
		
                //if (!(e->val.orE.left->type.type==boolTYPE&&e->val.orE.right->type.type==boolTYPE)){
                //        printf("Error - both operands of '||' must be of type bool\n");
                //        exit(0);
                //}
                e->type.type=boolTYPE;
                break;

                case andK:
                symEXP(e->val.andE.left, t);
                symEXP(e->val.andE.right, t);
                if (!(e->val.andE.left->type.type==boolTYPE&&e->val.orE.right->type.type==boolTYPE)){
                        printf("Error - both operands of '&&' must be of type bool\n");
                        exit(0);
                }
                e->type.type=boolTYPE;
                break;

                case eqK:
                symEXP(e->val.eqE.left, t);
                symEXP(e->val.eqE.right, t);
                if (!(comparable(e->val.eqE.left,e->val.eqE.right))){
                        printf("Error - illegal comparison\n");
                        exit(0);
                }
                e->type.type=boolTYPE;
                break;

		case neqK:
                symEXP(e->val.neqE.left, t);
                symEXP(e->val.neqE.right, t);
                if (!(comparable(e->val.neqE.left,e->val.neqE.right))){
                        printf("Error - illegal comparison\n");
                        exit(0);
                }
                e->type.type=boolTYPE;
                break;

                case GTK:
                symEXP(e->val.GTE.left, t);
                symEXP(e->val.GTE.right, t);
                if(!(ordered(e->val.GTE.left),ordered(e->val.GTE.right))){
                        printf("Error - types in GTE are not ordered\n");
                        exit(0);
                }
		if(!(comparable(e->val.GTE.left, e->val.GTE.right))){
			reportError("Error - types on either side do no match\n", e->lineno);
		}
                e->type.type=boolTYPE;
                break;

                case GEK:
                symEXP(e->val.GEE.left, t);
                symEXP(e->val.GEE.right, t);
                if(!(ordered(e->val.GEE.left),ordered(e->val.GEE.right))){
                        printf("Error - types in GTE are not ordered\n");
                        exit(0);
                }
		if(!(comparable(e->val.GEE.left, e->val.GEE.right))){
			reportError("Error - types on either side do no match\n", e->lineno);   
                }
                e->type.type=boolTYPE;
                break;

                case LTK:
                symEXP(e->val.LTE.left, t);
                symEXP(e->val.LTE.right, t);
                if(!(ordered(e->val.LTE.left),ordered(e->val.LTE.right))){
                        printf("Error - types in GTE are not ordered\n");
                        exit(0);
                }
		if(!(comparable(e->val.LTE.left, e->val.LTE.right))){
                        reportError("Error - types on either side do no match\n", e->lineno); 
                }
                e->type.type=boolTYPE;
                break;

		case LEK:
                symEXP(e->val.LEE.left, t);
                symEXP(e->val.LEE.right, t);
                if(!(ordered(e->val.LEE.left),ordered(e->val.LEE.right))){
                        printf("Error - types in GTE are not ordered\n");
                        exit(0);
                }
		if(!(comparable(e->val.LEE.left, e->val.LEE.right))){
                        reportError("Error - types on either side do no match\n", e->lineno); 
                }
                e->type.type=boolTYPE;
                break;

                case addOpK:
                typeImplementationAddOp(e->val.addOpE, t);
                e->type = e->val.addOpE->type;
		break;
}
}


void typeImplementationAddOp(addOp *a, SymbolTable *t){
        switch(a->kind){
                case plusK:
                typeImplementationAddOp(a->val.plusE.left, t);
                typeImplementationAddOp(a->val.plusE.right, t);
		//a->type->val.type=a->val.plusE.left->type->val.type;
                if (!((numericAddOp(a->val.plusE.left)&&numericAddOp(a->val.plusE.right))||(a->val.plusE.left->type.type==stringTYPE&&a->val.plusE.right->type.type==stringTYPE)||(a->val.plusE.left->type.type==runeTYPE&&a->val.plusE.right->type.type==runeTYPE))){
                        printf("Error - '+' reserved for numbers and strings\n");
                        exit(0);
                }
		if(a->val.plusE.right->type.type != a->val.plusE.left->type.type){
			reportError("Error - types on each side do not match\n", a->lineno);
		}
		a->type = a->val.plusE.left->type;
                break;

                case minusK:
                typeImplementationAddOp(a->val.minusE.left, t);
                typeImplementationAddOp(a->val.minusE.right, t);
                //a->type->val.type=a->val.plusE.left->type->val.type;
		if (!((numericAddOp(a->val.minusE.left)&&numericAddOp(a->val.minusE.right))||(a->val.minusE.left->type.type==runeTYPE&&a->val.minusE.right->type.type==runeTYPE))){
                        printf("Error - '-' is reserved for numbers and runes\n");
                        exit(0);
                }
		if(a->val.minusE.right->type.type != a->val.minusE.left->type.type){
			  reportError("Error - types on each side do not match\n", a->lineno);
                }
                a->type = a->val.minusE.left->type;
                break;

                case pipeK:
                typeImplementationAddOp(a->val.pipeE.left, t);
                typeImplementationAddOp(a->val.pipeE.right, t);
                //a->type->val.type=intTYPE;
		if (!((a->val.pipeE.left->type.type==intTYPE&&a->val.pipeE.right->type.type==intTYPE)||(a->val.pipeE.left->type.type==runeTYPE&&a->val.pipeE.right->type.type==runeTYPE))){
                        printf("Error - '|' is reserved for integers and runes\n");
                        exit(0);
                }
		a->type.type=intTYPE;
                break;

		case caratK:
                typeImplementationAddOp(a->val.caratE.left, t);
                typeImplementationAddOp(a->val.caratE.right, t);
                //a->type->val.type=intTYPE; 
		if (!((a->val.caratE.left->type.type==intTYPE&&a->val.caratE.right->type.type==intTYPE)||((a->val.caratE.left->type.type==runeTYPE&&a->val.caratE.right->type.type==runeTYPE)))){
                        printf("Error - '^' is reserved for integers and runes\n");
                        exit(0);
                }
		a->type.type=intTYPE;
                break;

                case mulOpK:
               	typeMulOp(a->val.mulOpE, t);
                a->type = a->val.mulOpE->type;
		break;
}
}

void typeMulOp(mulOp *m, SymbolTable *t){
        switch(m->kind){
                case timesK:
                typeMulOp(m->val.timesE.left, t);
                typeMulOp(m->val.timesE.right, t);
                if (!((m->val.timesE.left->type.type==intTYPE&&m->val.timesE.right->type.type==intTYPE)||(m->val.timesE.left->type.type==floatTYPE&&m->val.timesE.right->type.type==floatTYPE)||(m->val.timesE.left->type.type==runeTYPE&&m->val.timesE.right->type.type==runeTYPE))){
                        printf("Error - '*' is reserved for integers, floats and runes\n");
                        exit(0);
                }
                m->type.type=intTYPE;
                break;

                case divK:
                typeMulOp(m->val.divE.left, t);
                typeMulOp(m->val.divE.right, t);
                if (!((m->val.divE.left->type.type==intTYPE&&m->val.divE.right->type.type==intTYPE)||(m->val.divE.left->type.type==floatTYPE&&m->val.divE.right->type.type==floatTYPE)||(m->val.divE.left->type.type==runeTYPE&&m->val.divE.right->type.type==runeTYPE))){
                        printf("Error - '/' is reserved for integers, floats and runes\n");
                        exit(0);
                }
                m->type.type=intTYPE;
                break;

                case modK:
                typeMulOp(m->val.modE.left, t);
                typeMulOp(m->val.modE.right, t);
                if (!((m->val.modE.left->type.type==intTYPE&&m->val.modE.right->type.type==intTYPE)||(m->val.divE.left->type.type==runeTYPE&&m->val.divE.right->type.type==runeTYPE))){
                        printf("Error - the percent symbol is reserved for integers, and runes\n");
                        exit(0);
                }
                m->type.type=intTYPE;
                break;

                case coutK:
                typeMulOp(m->val.coutE.left, t);
                typeMulOp(m->val.coutE.right, t);
                if (!((m->val.coutE.left->type.type==intTYPE&&m->val.coutE.right->type.type==intTYPE) || (m->val.coutE.left->type.type==runeTYPE&&m->val.coutE.right->type.type==runeTYPE))){
                        printf("Error - the '<<' symbol is reserved for integers or runes\n");
                        exit(0);
                }
		m->type.type=intTYPE;
                break;

                case cinK:
                typeMulOp(m->val.cinE.left, t);
                typeMulOp(m->val.cinE.right, t);
                if (!((m->val.cinE.left->type.type==intTYPE&&m->val.cinE.right->type.type==intTYPE)||(m->val.coutE.left->type.type==runeTYPE&&m->val.coutE.right->type.type==runeTYPE))){
                        printf("Error - the '>>' symbol is reserved for integers or runes\n");
                        exit(0);
                }
                m->type.type=intTYPE;
                break;

                case ampK:
                typeMulOp(m->val.ampE.left, t);
                typeMulOp(m->val.ampE.right, t);
                if (!((m->val.ampE.left->type.type==intTYPE&&m->val.ampE.right->type.type==intTYPE)||(m->val.ampE.left->type.type==runeTYPE&&m->val.ampE.right->type.type==runeTYPE))){
                        printf("Error - the '&' symbol is reserved for integers\n");
                        exit(0);
                }
                m->type.type=intTYPE;
                break;

                case ampcaratK:
                typeMulOp(m->val.ampcaratE.left, t);
                typeMulOp(m->val.ampcaratE.right, t);
                if (!((m->val.ampcaratE.left->type.type==intTYPE&&m->val.ampcaratE.right->type.type==intTYPE)||(m->val.ampcaratE.left->type.type==runeTYPE&&m->val.ampcaratE.right->type.type==runeTYPE))){
                        printf("Error - the '&^' symbol is reserved for integers\n");
                        exit(0);
                }
                m->type.type=intTYPE;
                break;

                case factorK:
                typeFactor(m->val.factorE, t);
		m->type = m->val.factorE->type;
                break;
}
}

int numericAddOp(addOp *e){
        if(e->type.type==intTYPE||e->type.type==floatTYPE){
                return 1;
        }
        return 0;
}

int numericMulOp(mulOp *e){
        if(e->type.type==intTYPE||e->type.type==floatTYPE||e->type.type==runeTYPE){
                return 1;
        }
        return 0;
}

int numeric(factor *e){
        if(e->type.type==intTYPE||e->type.type==floatTYPE||e->type.type==runeTYPE){
                return 1;
        }
        return 0;
}


void typeFactor(factor *f, SymbolTable *t){
	SYMBOL *s;
        switch(f->kind){
                case uplusK:
                typeFactor(f->val.uplusE, t);
	//	printf("type of uplus %d\n", f->val.uplusE->type.type);
                if (!numeric(f->val.uplusE)){
                        printf("Error - a unary '+' must have a numeric expression child\n");
                        exit(0);
                }
                f->type.type=f->val.uplusE->type.type;
                break;

                case uminusK:
                typeFactor(f->val.uminusE, t);
                if (!numeric(f->val.uminusE)){
                        printf("Error - a unary '-' must have a numeric expression child\n");
                        exit(0);
                }
                f->type.type=f->val.uminusE->type.type;
                break;

                case notK:
                typeFactor(f->val.notE, t);
                if (f->val.notE->type.type!=boolTYPE){
                        printf("Error - a unary '!' must have a boolean expression child\n");
                        exit(0);
                }
                f->type.type=boolTYPE;
                break;
                //is this bitwise negation? check
                case ucaratK:
                typeFactor(f->val.ucaratE, t);
                if (!numeric(f->val.ucaratE)){
                        printf("Error - bitwise negation must have an integer expression child\n");
                        exit(0);
                }
                f->type.type=f->val.ucaratE->type.type;
                break;

                case utimesK:
                typeFactor(f->val.utimesE, t);
                f->type.type=f->val.utimesE->type.type;
                break;

		case uampK:
                typeFactor(f->val.uampE, t);
                f->type.type=f->val.uampE->type.type;
                break;

                case decK: 
                f->type.type=intTYPE;
		break;

		case octK: 
                f->type.type=intTYPE;
		break;

		case hexK:
		//printf("setting to int\n");
                f->type.type=intTYPE;
                break;

                case runeK:
                f->type.type=runeTYPE;
                break;

                case rawK:
		case interpretedK:
                f->type.type=stringTYPE;
                break;

                case floatK:
		//printf("setting to float\n");
                f->type.type=floatTYPE;
		//printf("%d float\n", f->type.type);
                break;

                case trueK:
		//printf("true\n");
                f->type.type=boolTYPE;
		break;
		case falseK:
                f->type.type=boolTYPE;
                break;

                case idK:
	//	printf("identifier %s\n", f->val.idE);
		//printf("id spot\n");
		//{SYMBOL *s;
		if(symbolAccess(t, f->val.idE) == 1){
			s = getSymbol(t, f->val.idE);
			f->type = s->type;
			f->type.type = getPrimitive(t, s->name);
			f->type.idType = s->name;
	//		printf("the type down here is %d\n", f->type.type);
			f->type.val.arrayType = s->array;
		}else{
			reportError("Error - Identifier not declared",f->lineno);
		}
		//printf("breaking out\n");
                break;

                case castK:
	//	printf("inside cast\n");
                if (!((f->val.castE.left->ty.type == intTYPE||f->val.castE.left->ty.type ==floatTYPE||f->val.castE.left->ty.type==boolTYPE||f->val.castE.left->ty.type==runeTYPE)&&(f->val.castE.right->type.type==intTYPE||f->val.castE.right->type.type==floatTYPE||f->val.castE.right->type.type==boolTYPE||f->val.castE.right->type.type==runeTYPE))){
                        printf("Error - type casts must be to/from ints, floats, bools, or runes\n");
                        exit(0);
                }
		symEXP(f->val.castE.right, t);
		symTYPE(f->val.castE.left, t);
                f->type.type=f->val.castE.left->ty.type;
                break;

                case appendK:
	//		printf("%s\n", f->val.appendE.name);
			//SYMBOL *s;
			if(symbolAccess(t, f->val.appendE.name) == 0){
				reportError("Error - identifier being appended to does not exist", f->lineno);
			}
			s = getSymbol(t, f->val.appendE.name);
			//printf("symbol %d", s->type.type);
			symEXP(f->val.appendE.right, t);
			//printf("%d right\n", f->val.appendE.right->type.type);
			//printf("%d id\n", toEnd(s->array)->type);
			if(f->val.appendE.right->type.type != toEnd(s->array)->type){
				reportError("Error - appended value does not match type of identifier", f->lineno);			
			}
			f->type.val.arrayType = NEW(TYPETREE);
			f->type.val.arrayType = getTreePrim(t,f->val.appendE.name);
	//		printf("the type of the prim tree is %d\n", f->type.val.arrayType->type);
			f->type.type = sliceTYPE;
			
                break;
                
		case funccallK:
			if(f->val.funccallE.name->kind == idK){
	//		printf("the function being called is %s\n", f->val.funccallE.name->val.idE);
				if(funcDefined(t, f->val.funccallE.name->val.idE) == 0){
					if(typeDefined(t, f->val.funccallE.name->val.idE) == 1){
	//					printf("type defined\n");
						s = getSymbol(t, f->val.funccallE.name->val.idE);
	//					printf("casting to type %d\n", s->type.type);
						f->type = s->type;
						break;
					}else{
						reportError("Error - this function does not exist", f->lineno);//newerror
					}
				}else{
	//				printf("performing the function call\n");
					s = getFunc(t, f->val.funccallE.name->val.idE);
				//if(s->type.idType != NULL){
				//	f->type.idType = s->type.idType;
				//}else{
				//	f->type.type = s->type.type;
				//}
	//				printf("past getfunc\n");
					f->type = s->type;
	//				printf("%d the symbol type?\n", s->type.val.structType->val.typetreelist.tytree->type);
					expToParams(s->type.val.structType, f->val.funccallE.right, t);
				}
			}else{
				typeFactor(f->val.funccallE.name, t);
				f->type = f->val.funccallE.name->type;
			}
		//I have to check that the parameters match the types set, but I have literally no idea how or the time do to that
		//need to implement check argument type

                //typeImplementationExpressionList(f->val.funccallE.right);
                //note that we only support identifiers here, not expressions, for function names
                //x=readTable(table,val.funccallE.name);
                //checkArgumentTypes(x,f->val.funccallE.right);
                //f->type->val.type=r;
                break;
		case parenK:
	//		printf("passing through paren\n");
                        symEXP(f->val.parenE, t);
			f->type = f->val.parenE->type;
                        break;
		case funccallemptyK:
	//		printf("emptyfunccall\n");
			if(f->val.funccallemptyE->kind == idK){
	//			printf("inside first if\n");
				if(funcDefined(t, f->val.funccallemptyE->val.idE) == 0){
					if(typeDefined(t, f->val.funccallemptyE->val.idE) == 1){
                                                s = getSymbol(t, f->val.funccallemptyE->val.idE);
                                                f->type = s->type;
                                                break;
                                        }else{
                                		reportError("Error - this function does not exist", f->lineno);//newerror
					}
                        	}else{
	//				printf("function is defined\n");
                                	s = getFunc(t, f->val.funccallemptyE->val.idE);
                                       	f->type = s->type;
	//				printf("set the type\n");
                        	}
			}else{
				typeFactor(f->val.funccallemptyE, t);
				f->type = f->val.funccallemptyE->type;
			}
		break;
		case arrayK:
			//int i;
	//		printf("checking for an array like an asshole\n");
			//printf("%d \n", f->type.type);
			symEXP(f->val.arrayE.right, t);
	//		printf("past here\n");
			if(f->val.arrayE.right->type.type != intTYPE){
				reportError("Error - array location call must be an Integer", f->lineno);//newererror
			}
	//		printf("past the first if\n");
                        if(f->val.arrayE.left->kind == idK){
	//			printf("inside the if?\n");	
				if(symbolAccess(t, f->val.arrayE.left->val.idE) == 0){
					reportError("Error - identifier does not exist", f->lineno);
				}
          //                      printf("here?\n");
                                s = getSymbol(t, f->val.arrayE.left->val.idE);
            //                    printf("%s \n",f->val.arrayE.left->val.idE );
				//i = toEnd(s->array)->type;
				//printf("the name of s: %s\n", s->name);
				//printf("the array holds: %d\n", s->array->type);
				f->type = *toEnd(s->array);
			}else{
	//		printf("here?\n");
//			printf("before typeFactor\n"); 
			typeFactor(f->val.arrayE.left, t);
			f->type = f->val.arrayE.left->type;
			}
	//		printf("array %d\n", f->type.type);
			break;
		case estructK:
			if(f->val.structE.left->kind == idK){
				
				if(symbolAccess(t, f->val.structE.left->val.idE) == 0){
                                        reportError("Error - identifier does not exist", f->lineno);//newererror
                                }
				s = getSymbol(t, f->val.structE.left->val.idE);

				if(s->type.type != structTYPE){
                                        reportError("Error - Field selection is not a struct type", f->lineno);//newererror
                                }
				if(flag == 0){
					f->type.type = structFieldAccess(s->type.val.structType, f->val.structE.right);
				}else{
					f->accessOrder.name = f->val.structE.right;
					f->accessOrder.next = NEW(FIELDACCESS);
					f->accessOrder.next->name = f->val.structE.left->val.idE;
					f->accessOrder.next->next = NULL;
				}
			} else {
				flag = 1;

				f->accessOrder.name = f->val.structE.right;
				typeFactor(f->val.structE.left, t);
				f->accessOrder.next = NEW(FIELDACCESS);
				f->accessOrder.next = &f->val.structE.left->accessOrder;
				f->accessOrder.previous = NULL;
				f->accessOrder.first = 1;
				printAccess(&f->accessOrder);

				s = getSymbol(t, getBase(&f->accessOrder)->name);
				f->type.type = getStructType(getBase(&f->accessOrder)->previous, s->type.val.structType);
				
				flag = 0;
			}
			break;


}
}

FIELDACCESS *getBase(FIELDACCESS *accessor){
//	printf("inside get base\n");
	if(accessor->next == NULL){
		return accessor;
	}else{
		return getBase(accessor->next);
	}
}


SymbolType getStructType(FIELDACCESS *accessor, TYPETREELIST *ttl){
//	printf("inside get structType\n");
//	int i;
	if(accessor->previous == NULL){
//		printf("final check %s\n", accessor->name);
		return structFieldAccess(ttl, accessor->name);
	}else{
//		printf("whats being passed into struct recursion %s\n", accessor->name);
	//	i = structRecursion(ttl, accessor->name);//->val.typetreelist.tytree->type;
		//printf("what typetreelist is being returned: %s\n", structRecursion(ttl, accessor->previous->name)->idName);
		//printf("what is i? %d\n", i);
	//	if(accessor->previous == NULL){
	//		i = structRecursion(ttl, accessor->name);
	//		printf("returing i?\n");
	//		return i;
	//	} else {
		
//			printf("passing in previous %s\n", accessor->previous->name);
			return getStructType(accessor->previous, structRecursion(ttl, accessor));
	//	}
	}
} 


int printAccess(FIELDACCESS *accessor){
	if(accessor->next == NULL){
//		printf("access: %s\n", accessor->name);
//		printf("the previous accessor is %s\n", accessor->previous->name);
		return 0;
	}else{	
		if(accessor->first == 1){
//			printf("access: %s\n", accessor->name);
			accessor->next->previous = accessor;
			return printAccess(accessor->next);
		}else{
			accessor->next->previous = accessor;
//			printf("access: %s\n", accessor->name);
//			printf("the previous accessor is %s\n", accessor->previous->name);
                        return printAccess(accessor->next);
		}
	}
}

TYPETREELIST *structRecursion(TYPETREELIST *t, FIELDACCESS *fa){
//	printf("look for %s\n", fa->name);
//	printf("looking in typetreelist %s\n", t->idName);
//	printf("inside structe recursion\n");
	if(strcmp(t->idName, fa->name) == 0){
//		printf("name was found %s\n", t->idName);
//		printf("returning type %d\n", t->val.typetreelist.tytree->type);
		if(t->val.typetreelist.tytree->type != structTYPE){
//			printf("first\n");
			return t;
		} else {
//			printf("or second\n");
			return t->val.typetreelist.tytree->val.structType;
		}
	}else{
		if(t->val.typetreelist.tytreelist == NULL){
			reportError("Error - The identifier attempting to be accessed does not exist in the struct", t->lineno);
		}
		return structRecursion(t->val.typetreelist.tytreelist, fa);
	}
}


TYPETREE *toEnd(TYPETREE *ty){
	//printf("inside to end\n");
	if((ty->type != 6) && (ty->type != 5)){
	//	printf("before return\n");
		return ty;
	}
	else{
		return toEnd(ty->val.arrayType);
	}		
}


SymbolType structFieldAccess(TYPETREELIST *ty, char *identifier){
//	printf("field %s\n", identifier);
	if(strcmp(ty->idName, identifier) == 0){	
//		printf("before the first return\n");
		return ty->val.typetreelist.tytree->type;
	}else{
		if(ty->val.typetreelist.tytreelist == NULL){
			reportError("Error - The identifier attempting to be accessed does not exist in the struct", ty->lineno);//newererror
		}
	//	printf("segfaulting somewhere in here?\n");
		return structFieldAccess(ty->val.typetreelist.tytreelist, identifier);
	}
}


void expToParams(TYPETREELIST *ttl, expList *e, SymbolTable *t){
        //printf("inside exptoparams\n");
        	switch(e->kind){
                        case ExpK:
                                symEXP(e->val.expE, t);
	//			printf("broke out\n");
	//			printf("evaluating the expression type: %d\n", e->val.expE->type.type);
	//			printf("evaluating the typetree type: %d\n", ttl->val.typetreelist.tytree->type);
				if((e->val.expE->type.type != ttl->val.typetreelist.tytree->type)){
	//				printf("first if\n");
					if((e->val.expE->type.type == sliceTYPE) || (e->val.expE->type.type == arrayTYPE)){
						if((ttl->val.typetreelist.tytree->type != sliceTYPE) && (ttl->val.typetreelist.tytree->type != arrayTYPE)){
							reportError("Error - param given to function does match match type expected", e->val.expE->lineno);
                                		}
					}else{
						reportError("Error - param given to function does match match type expected", e->val.expE->lineno);	
					}
				}
	//			printf("here?\n");
                                break;
                        case expListK:
				//printf("list?\n");
				symEXP(e->val.expListE.expression, t);
				//printf("evaluating the expression type: %d\n", e->val.expListE.expression->type.type);
				//printf("evaluating the typetree type: %d\n", ttl->val.typetreelist.tytree->type);
				if(e->val.expListE.expression->type.type != ttl->val.typetreelist.tytree->type){	
				//	printf("i get here\n");
					if((e->val.expListE.expression->type.type == sliceTYPE) || (e->val.expListE.expression->type.type == arrayTYPE)){
				//		printf("i get to circle two\n");
						if((ttl->val.typetreelist.tytree->type != sliceTYPE) && (ttl->val.typetreelist.tytree->type != arrayTYPE)){
							reportError("Error - param given to function does match match type expected", e->val.expListE.expression->lineno);
						}
					}else{
						reportError("Error - param given to function does match match type expected", e->val.expListE.expression->lineno);
					}
				} 
                                expToParams(ttl->val.typetreelist.tytreelist, e->val.expListE.expressionList, t);
                	        break;
                        }
	//		printf("through exptoparam\n");
}



























