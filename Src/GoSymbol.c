//Version 1.5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GoSymbol.h"
#include "memory.h"
#include "GoTree.h"
#include "error.h"

extern SymbolTable *table;
extern int lineno;
int Hash(char *str){
        unsigned int hash = 0;
        while (*str) hash = (hash << 1) + *str++;
        return hash % HashSize;
}

SymbolTable *initSymbolTable(){
        SymbolTable *t;
        int i;
        t = NEW(SymbolTable);
        for(i = 0; i < HashSize; i++) t->table[i] = NULL;
        t->next = NULL;
        return t;
}

SymbolTable *scopeSymbolTable(SymbolTable *s){
        SymbolTable *t;
        t = initSymbolTable();
        t->next = s;
        return t;
}


//Puts normal types
SYMBOL *putSymbol(SymbolTable *t, char *name, TYPETREE kind){
        //printf("inside put symbol %s\n", name);
	int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
	//printf("past the for\n");
        s = NEW(SYMBOL);
        s->name = name;
        s->type.type = kind.type;
	s->type.idType = NULL;
	s->type.typeDec = 0;
	s->type.funcDec = 0;
        s->next = t->table[i];
	//printf("past setting\n");
	if(kind.type == arrayTYPE || kind.type == sliceTYPE){
		s->array = kind.val.arrayType;
	//	printf("just to see that it worked %d\n", s->array->type);
        }
	//printf("past the first if\n");
	if(kind.type == structTYPE){
		s->type.val.structType = kind.val.structType;
	}
	t->table[i] = s;
	//printf("end of put symbol %s\n", name);
	//printf("we set the type to %d\n", s->type.type);
        return s;
}

//Puts IDTypes
SYMBOL *putSymbolIdType(SymbolTable *t, char *name, char *idType){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
        s = NEW(SYMBOL);
        s->name = name;
	//printf("before setting the type %s?\n", idType);
	s->type.type = getPrimitive(t, idType);
	//printf("after setting the type %d?\n",s->type.type);
        s->type.idType = idType;
	s->type.typeDec = 0;
	s->type.funcDec = 0;
        s->next = t->table[i];
        if(getPrimitive(t, idType) == arrayTYPE || getPrimitive(t, idType) == sliceTYPE){
		s->array = getTreePrim(t, idType);
	}
	//printf("did i even get here?\n");
	if(getPrimitive(t, idType) == structTYPE){
	//	printf("into here?\n");
		s->type.val.structType = getStructTreePrim(t, idType)->val.structType;
	//	printf("AHHHH %s\n", s->type.val.structType->idName);
	} 
	t->table[i] = s;
        return s;
}


SYMBOL *putSymbolTypeDec(SymbolTable *t, char *name, TYPETREE kind){
	int i = Hash(name);
	SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
        s = NEW(SYMBOL);
        s->name = name;
        s->type.type = kind.type;
	s->type.idType = NULL;
	s->type.typeDec = 1;
	s->type.funcDec = 0;
        s->next = t->table[i];
        if(kind.type == arrayTYPE || kind.type == sliceTYPE){
                s->array = kind.val.arrayType;
        }
	if(kind.type == structTYPE){
                s->type.val.structType = kind.val.structType;
	}
	t->table[i] = s;
	return s;
}


SYMBOL *putSymbolFuncDec(SymbolTable *t, char *name, TYPETREE kind){
	//printf("inside put symbol funcdec %s\n", name);
	//printf("ttl next %s\n", kind.val.structType->idName);
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
        s = NEW(SYMBOL);
        s->name = name;
	s->type.idType = NULL;
        s->type.type = kind.type;
        s->type.funcDec = 1;
        s->next = t->table[i];
        if(kind.type == arrayTYPE || kind.type == sliceTYPE){
                s->array = kind.val.arrayType;
        }
	if(kind.type == structTYPE){
                s->type.val.structType = kind.val.structType;
        }else if(kind.val.structType != NULL){
		s->type.val.structType = kind.val.structType;
	}//else{
           //     s->type.val.structType = NULL;
        //}
	t->table[i] = s;
	//printf("through the function\n");
        return s;
}


SYMBOL *putSymbolIdTypeDec(SymbolTable *t, char *name, char *idType){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
        s = NEW(SYMBOL);
        s->name = name;
	s->type.type = getPrimitive(t, idType);
	//s->type.idType = NULL;
	//s->type.type = noTYPE;
	//printf("the type name %s\n", name);
	//printf("the type val %s\n", idType); 
	s->type.idType = idType;
        s->type.typeDec = 1;
	s->type.funcDec = 0;
        s->next = t->table[i];
	//printf("here?\n");
        if(getPrimitive(t, idType) == arrayTYPE || getPrimitive(t, idType) == sliceTYPE){
          //      printf("inside primitive\n");
	//	printf("%d\n", getTreePrim(t, idType)->type);
		s->array = getTreePrim(t, idType);
        }
	if(getPrimitive(t, idType) == structTYPE){
          //      printf("we get inside the get prim crap\n\n");
		s->type.val.structType = getStructTreePrim(t, idType)->val.structType;
        }
	t->table[i] = s;
        return s;
}

SYMBOL *putSymbolIdFuncDec(SymbolTable *t, char *name, char *idType){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
        s = NEW(SYMBOL);
        s->name = name;
	s->type.type = getPrimitive(t, idType);
	//s->type.idType = NULL;
	//s->type.type = noTYPE;
        s->type.idType = idType;
        s->type.funcDec = 1;
        s->next = t->table[i];
        if(getPrimitive(t, idType) == arrayTYPE || getPrimitive(t, idType) == sliceTYPE){
                s->array = getTreePrim(t, idType);
        }
	if(getPrimitive(t, idType) == structTYPE){
                s->type.val.structType = getStructTreePrim(t, idType)->val.structType;
        }else if(getStructTreePrim(t, idType)->val.structType != NULL){
                s->type.val.structType = getStructTreePrim(t, idType)->val.structType;
        }
	t->table[i] = s;
        return s;
}

/*SYMBOL *putStructSymbol(SymbolTable *t, char *name, TYPETREE *ty){
	int i = Hash(name);
	SYMBOL *s;
	for(s = t->table[i]; s; s = s->next){
		if (strcmp(s->name, name) == 0) return s;
	}
	s = NEW(SYMBOL);
	s->name = name;
	s->type.type = structTYPE;
	//s->array 



}
*/


//needs to account for ID TYPE as well

SYMBOL *getSymbol(SymbolTable *t, char *name){
        int i = Hash(name);
	SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name, name) == 0) return s;
        }
        if (t->next==NULL) return NULL;
        return getSymbol(t->next, name);
}

SYMBOL *getFunc(SymbolTable *t, char *name){
        //printf("inside get func\n");
	int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
	//	printf("looping\n");
		if(t->next == NULL){
			if ((strcmp(s->name, name) == 0) && (s->type.funcDec == 1)){ 
	//			printf("returning\n");
				return s;
			}
        	}
	}
	//printf("next scope down\n");
        return getFunc(t->next, name);
}


int symbolDefined(SymbolTable *t, char *name){
//	printSymbolTable(t);
        //printf("%s inside sym def\n", name);
	int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
	//	printf("looking\n");
                if (strcmp(s->name, name) == 0) return 1;
        }
	
	return 0;
//	if(t->next != NULL){
//		return symbolDefined(t->next, name);
//	}
//	else{ return 0; }
}

int symbolAccess(SymbolTable *t, char *name){
//      printSymbolTable(t);
       // printf("%s inside sym def", name);
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
        //      printf("looking\n");
                if (strcmp(s->name, name) == 0) return 1;
        }
        //printf("before bad return\n");
//        return 0;
        if(t->next != NULL){
                return symbolAccess(t->next, name);
        }
        else{ return 0; }
}

int typeAlreadyInScope(SymbolTable *t, char *name){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if ((strcmp(s->name, name) == 0) && (s->type.typeDec == 1)){
                       // printf("returning\n");
                         return 1;
                }
        }
	return 0;
        //if(t->next != NULL){
        //        return typeDefined(t->next, name);
        //}
        //else { return 0; }
}




int typeDefined(SymbolTable *t, char *name){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if ((strcmp(s->name, name) == 0) && (s->type.typeDec == 1)){
	//		printf("returning\n");
			 return 1;
        	}
	}
	if(t->next != NULL){
		return typeDefined(t->next, name);
	}
	else { return 0; }
}

int funcDefined(SymbolTable *t, char *name){
        int i = Hash(name);
        SYMBOL *s;
	while (t->next !=NULL){
		t=t->next;
	}
        for (s = t->table[i]; s; s = s->next){
                if ((strcmp(s->name, name) == 0) && (s->type.funcDec == 1)) return 1;
        }
        return 0;
}


SYMBOL *symVar(char *name, SymbolTable *t){
        SYMBOL *s;
        s = getSymbol(t, name);
        if (s==NULL){
//                printSymbolTable(t);
//                fclose(stdout);
//                freopen("result", "w", stdout);
                printf("Identifier %s not declared\n", name);
//                fclose(stdout);
                exit(0);
        } else { return s; }
}

SymbolTable *getCurrScope(SymbolTable *t){
	if(t->next != NULL){
		return getCurrScope(t->next);
	}
	return t;
}


void printSymbolTable( SymbolTable *t){
        int i;
	printf("Scope: \n");
        for(i = 0; i < HashSize; i++){
	if(t->table[i] != NULL){
		if(t->table[i]->type.funcDec == 1){
			//printf("got inside funcdec\n");
			printf("Name: %s  ", t->table[i]->name);
                        if (t->table[i]->type.type == 0){
                                printf("Type: int");
				//printf("%s\n", t->table[i]->type.val.structType->idName);
				if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 1){
                                printf("Type: float");
				if(t->table[i]->type.val.structType != NULL){
					structPrint(t->table[i]->type.val.structType);
				}
                        }
                        else if (t->table[i]->type.type == 2){
                                printf("Type: boolean");
				if(t->table[i]->type.val.structType != NULL){	
					structPrint(t->table[i]->type.val.structType);
				}
                        }
                        else if (t->table[i]->type.type == 3){
                                printf("Type: rune");
				if(t->table[i]->type.val.structType != NULL){
					structPrint(t->table[i]->type.val.structType);
                        	}
			}
                        else if (t->table[i]->type.type == 4){
                                printf("Type: string");
				if(t->table[i]->type.val.structType != NULL){
				structPrint(t->table[i]->type.val.structType);
                        	}
			}
                        else if (t->table[i]->type.type == 5){
                                printf("Type: slice");
				if(t->table[i]->array != NULL){
                                        arrayPrint(t->table[i]->array);
                                }
                                if(t->table[i]->type.val.structType != NULL){
					structPrint(t->table[i]->type.val.structType);
                        	}
			}
                        else if (t->table[i]->type.type == 6){
                                printf("Type: array");
                                if(t->table[i]->array != NULL){
					arrayPrint(t->table[i]->array);
				}
				if(t->table[i]->type.val.structType != NULL){
					structPrint(t->table[i]->type.val.structType);
				}
                        	
			}
                        else if (t->table[i]->type.type == 7){
                                printf("Type: struct");
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 8){
                                if(t->table[i]->type.idType != NULL){
                                        printf("Type: %s", t->table[i]->type.idType);
					if(t->table[i]->type.val.structType != NULL){
                                 	       structPrint(t->table[i]->type.val.structType);
                                	}
                                        if(t->table[i]->array != NULL){
                                                arrayPrint(t->table[i]->array);
                                        }
                                }else{ 
					printf("Type: none");
					if(t->table[i]->type.val.structType != NULL){
                                        	structPrint(t->table[i]->type.val.structType);
                                	}
				 }
                        }
                        printf("\n");
		}else{
	//		printf("inside printf\n");
                        printf("Name: %s  ", t->table[i]->name);
                        if (t->table[i]->type.type == 0){
                                printf("Type: int");
                        }
                        else if (t->table[i]->type.type == 1){
                                printf("Type: float");
                        }
			else if (t->table[i]->type.type == 2){
                                printf("Type: boolean");
                        }
                        else if (t->table[i]->type.type == 3){
                                printf("Type: rune");
                        }
			else if (t->table[i]->type.type == 4){
                                printf("Type: string");
                        }
                        else if (t->table[i]->type.type == 5){
                                printf("Type: slice");
				arrayPrint(t->table[i]->array);
                        }
			else if (t->table[i]->type.type == 6){
                                printf("Type: array");
				arrayPrint(t->table[i]->array);
                        }
                        else if (t->table[i]->type.type == 7){
                                printf("Type: struct");
				if(t->table[i]->type.val.structType != NULL){
					structPrint(t->table[i]->type.val.structType);
                        	}
			}
			else if (t->table[i]->type.type == 8){
                                if(t->table[i]->type.idType != NULL){
					printf("Type: %s", t->table[i]->type.idType);
					if(t->table[i]->array != NULL){
						arrayPrint(t->table[i]->array);
					}	
				}else{ printf("Type: none"); }
			}
			printf("\n");
        	}//printf("looping\n");
	}
	if(t->next != NULL){
		printSymbolTable(t->next);
	}
}
}
void arrayPrint(TYPETREE *array){
			if (array->type == 0){
				printf(" -> int");
                        }
                        else if (array->type == 1){
             	                printf(" -> float");
                        }
                        else if (array->type == 2){
                                printf(" -> boolean");
                        }
                        else if (array->type == 3){
                                printf(" -> rune");
                        }
                        else if (array->type == 4){
                                printf(" -> string");
                        }
                        else if (array->type == 5){
                                printf(" -> slice");
				arrayPrint(array->val.arrayType);
                        }
                        else if (array->type == 6){
                                printf(" -> array");
				arrayPrint(array->val.arrayType);
                        }
                        else if (array->type == 7){
                                printf(" -> struct");
				arrayPrint(array->val.structType->val.typetreelist.tytree);
                        }
                        else if (array->type == 8){
                                printf(" -> none");
                        }
                        //else
                        //        printf(" -> %s", array->idType);
                        return;
}

void structPrint(TYPETREELIST *structTree){
			if (structTree->val.typetreelist.tytree->type == 0){
                                printf(" -> int");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 1){
                                printf(" -> float");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 2){
                                printf(" -> boolean");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 3){
                                printf(" -> rune");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 4){
                                printf(" -> string");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 5){
                                printf(" -> (slice");
                                arrayPrint(structTree->val.typetreelist.tytree->val.arrayType);
				printf(")");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 6){
                                printf(" -> (array");
                                arrayPrint(structTree->val.typetreelist.tytree->val.arrayType);
				printf(")");
                        }
                        else if (structTree->val.typetreelist.tytree->type == 7){
                                printf(" -> (struct");
                                structPrint(structTree->val.typetreelist.tytree->val.structType);
                        	printf(")");
			}
                        else if (structTree->val.typetreelist.tytree->type == 8){
				printf(" -> none");
                        }
                        else if (structTree->val.typetreelist.tytree->idType != NULL){
//				printf("into s?\n");
                                printf(" -> %s", structTree->val.typetreelist.tytree->idType);
                        }else{
				if(structTree->val.typetreelist.tytreelist != NULL){
                                        structPrint(structTree->val.typetreelist.tytreelist);
                        	}else{
					return;
				}
			}
		
}


void printCurrScope(SymbolTable *t){
	int i;
	printf("Scope: \n");
        for(i = 0; i < HashSize; i++){
        if(t->table[i] != NULL){
                if(t->table[i]->type.funcDec == 1){
                        //printf("got inside funcdec\n");
                        printf("Name: %s  ", t->table[i]->name);
                        if (t->table[i]->type.type == 0){
                                printf("Type: int");
                                //printf("%s\n", t->table[i]->type.val.structType->idName);
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 1){
                                printf("Type: float");
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 2){
                                printf("Type: boolean");
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 3){
                                printf("Type: rune");
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 4){
                                printf("Type: string");
                                if(t->table[i]->type.val.structType != NULL){
                                structPrint(t->table[i]->type.val.structType);
                                }
                        }
			else if (t->table[i]->type.type == 5){
                                printf("Type: slice");
                                if(t->table[i]->array != NULL){
                                        arrayPrint(t->table[i]->array);
                                }
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 6){
                                printf("Type: array");
                                if(t->table[i]->array != NULL){
                                        arrayPrint(t->table[i]->array);
                                }
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }

                        }
                        else if (t->table[i]->type.type == 7){
                                printf("Type: struct");
                                if(t->table[i]->type.val.structType != NULL){
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 8){
                                if(t->table[i]->type.idType != NULL){
                                        printf("Type: %s", t->table[i]->type.idType);
                                        if(t->table[i]->type.val.structType != NULL){
                                               structPrint(t->table[i]->type.val.structType);
                                        }
                                        if(t->table[i]->array != NULL){
                                                arrayPrint(t->table[i]->array);
                                        }
                                }else{
                                        printf("Type: none");
                                        if(t->table[i]->type.val.structType != NULL){
                                                structPrint(t->table[i]->type.val.structType);
                                        }
                                 }
                        }
                        printf("\n");
                }else{
                        printf("Name: %s  ", t->table[i]->name);
                        if (t->table[i]->type.type == 0){
                                printf("Type: int");
                        }
                        else if (t->table[i]->type.type == 1){
                                printf("Type: float");
                        }
                        else if (t->table[i]->type.type == 2){
                                printf("Type: boolean");
                        }
                        else if (t->table[i]->type.type == 3){
                                printf("Type: rune");
                        }
                        else if (t->table[i]->type.type == 4){
                                printf("Type: string");
                        }
                        else if (t->table[i]->type.type == 5){
                                printf("Type: slice");
				arrayPrint(t->table[i]->array);
                        }
                        else if (t->table[i]->type.type == 6){
                                printf("Type: array");
				arrayPrint(t->table[i]->array);
                        }
                        else if (t->table[i]->type.type == 7){
                                printf("Type: struct");
			//	printf("%s\n", t->table[i]->type.val.structType);
				if(t->table[i]->type.val.structType != NULL){
			//		printf("inside print?");
                                        structPrint(t->table[i]->type.val.structType);
                                }
                        }
                        else if (t->table[i]->type.type == 8){
                       		if(t->table[i]->type.idType != NULL){
                                        printf("Type: %s", t->table[i]->type.idType);
                                        if(t->table[i]->array != NULL){
                                                arrayPrint(t->table[i]->array);
                                        }
                                }else{ printf("Type: none"); }
                        }
                        printf("\n");
                }
        }
}
}
SymbolType getPrimitive(SymbolTable *t, char *name){
//	printf("inside get primitive looking for %s\n", name);
        int i = Hash(name);
        SYMBOL *s;
	//printf("we're passing in %s\n", name);
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name, name) == 0){
	//		printf("the names match\n");
			if(s->type.idType != NULL){
	//			printf("the idtype of the symbol is %s\n", s->type.idType);
				return getPrimitive(t, s->type.idType);
			}else{ 
	//			printf("the primitive type is %d\n", s->type.type);
				return s->type.type; }
        	}
	}
	//printf("it just goes here for some reason\n");
        if (t->next==NULL){
	//	printf("didn't find it\n");
		printf("Error - Primitive does not exist\n");
		exit(0);
	}
        return getPrimitive(t->next, name);
}





TYPETREE *getTreePrim(SymbolTable *t, char *name){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name, name) == 0){
                        if(s->type.idType != NULL){
                                return getTreePrim(t, s->type.idType);
                        }else{ return s->array; }
                }
        }

        if (t->next==NULL){
	//	printf("didn't find is\n");
                printf("Error - Primitive does not exist\n");
		exit(0);
	}
        return getTreePrim(t->next, name);
}

TYPETREE *getStructTreePrim(SymbolTable *t, char *name){
	//printf("inside get struct tree prim %s\n", name);
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name, name) == 0){
	//		printf("found it\n");
                        if(s->type.idType != NULL){
	//			printf("before recurse\n");
                                return getStructTreePrim(t, s->type.idType);
                        }else{ 
	//			printf("before return\n");
				return &s->type; }
                }
        }
	//printf("did not find\n");
        if (t->next==NULL){
                printf("Error - Primitive does not exist\n");
		exit(0);
	}
        return getStructTreePrim(t->next, name);
}



SYMBOL *boolPutSymbol(SymbolTable *t, char *name, TYPETREE kind){
        int i = Hash(name);
        SYMBOL *s;
        for (s = t->table[i]; s; s = s->next){
                if (strcmp(s->name,name)==0) return s;
        }
        s = NEW(SYMBOL);
        s->name = name;
        s->type.type = kind.type;
        s->type.idType = NULL;
        s->type.typeDec = 0;
        s->type.funcDec = 0;
        s->next = t->table[i];
        if(kind.type == arrayTYPE || kind.type == sliceTYPE){
                s->array = kind.val.arrayType;
        }
        t->table[i] = s;
        return s;
}

