#include "GoCode.h"
#include "GoSymbol.h"
#include <stdio.h>
#include <string.h>

SymbolTable *symTable;
int namenum=0;

void codestruct(structType *s);
void codetypeid(SymbolType t);

void codemain(){
//printf("int main(int argc, char **argv){\n}\n");
}

void codecondition(condition *c){
codeexp(c->val.condE);
}

void codeselfop(selfOp *s, exp *l,exp *r){
switch(s->kind){
        case selfplus:
        printf("+=");
        break;

        case selfminus:
        printf("-=");
        break;

        case selftimes:
        printf("*=");
        break;

        case selfdiv:
        printf("/=");
        break;

        case selfmod:
        printf("%%=");
        break;

        case ampequals:
        printf("&=");
        break;

        case pipeequals:
        printf("|=");
        break;

        case caratequals:
        printf("^=");
        break;

        case coutequals:
        printf("<<=");
        break;

        case cinequals:
        printf(">>=");
        break;

        case wtf:
        //printf("&^=");
        printf("=");
	printf("~(");
	codeexp(l);
	printf("&");
	codeexp(r);
	printf(")");
	break;
}
}

void codefactor(factor *e){
switch(e->kind){
        case parenK:
        printf("(");
        codeexp(e->val.parenE);
        printf(")");
        break;

        case uplusK:
        printf("+");
        codefactor(e->val.uplusE);
        break;

        case uminusK:
        printf("-");
        codefactor(e->val.uminusE);
        break;

        case notK:
        printf("!");
        codefactor(e->val.notE);
        break;

        case ucaratK:
        printf("~");
        codefactor(e->val.ucaratE);
        break;

        case utimesK:
        printf("*");
        codefactor(e->val.utimesE);
        break;

        case uampK:
        printf("&");
        codefactor(e->val.uampE);
        break;

        case idK:
        printf("%s",e->val.idE);
        break;

        case decK:
        printf("%d",e->val.decE);
        break;

        case octK:
        printf("%o",e->val.octE);
        break;

        case hexK:
        printf("%x",e->val.hexE);
        break;

        case floatK:
        printf("%f",e->val.floatE);
        break;

        case runeK:
        printf("\'%c\'",e->val.runeE);
        break;

        case interpretedK:
        printf("%s",e->val.interpretedE);
        break;

        case rawK:
        printf("%s",e->val.rawE);
        break;

        case castK:
        printf("(");
	//not considering the below case for structs
	codetype(e->val.castE.left,"error message",0);
	printf(")");
        printf("(");
        codeexp(e->val.castE.right);
        printf(")");
        break;

        case funccallK:
	//printSymbolTable(symTable);
	if(funcDefined(symTable, e->val.funccallE.name->val.idE) == 0){
	printf("(");
	codefactor(e->val.funccallE.name);
	printf(")");
	}
	else{
        codefactor(e->val.funccallE.name);
	}
        printf("(");
        codeexpList(e->val.funccallE.right);
        printf(")");
        break;

        case funccallemptyK:
        codefactor(e->val.funccallemptyE);
        printf("()");
        break;

        case appendK:
        //printf("append(%s,",e->val.appendE.name);
	//printf("The type is: %d",e->type.type);
        switch(e->type.val.arrayType->type){

	case 0:
	//case intTYPE:
        printf("insertArray_int(&%s,",e->val.appendE.name);	
	break;

	case 1:
	//case floatTYPE:
        printf("insertArray_float(&%s,",e->val.appendE.name);
	break;

	case 4:
	//case stringTYPE:
	printf("insertArray_string(&%s,",e->val.appendE.name);
	break;

	case 2:
	//case boolTYPE:
        printf("insertArray_int(&%s,",e->val.appendE.name);
	break;

	case 3:
	//case runeTYPE:
        printf("insertArray_char(&%s,",e->val.appendE.name);
	break;
	}
	codeexp(e->val.appendE.right);
        printf(")");
        break;

        case trueK:
        printf("1");
        break;

        case falseK:
        printf("0");
        break;

        case arrayK:
        codefactor(e->val.arrayE.left);
        //printf("[");
        //codeexp(e->val.arrayE.right);
        //printf("]");
        printf(".array[");
	codeexp(e->val.arrayE.right);
	printf("]");
	break;

        case estructK:
        codefactor(e->val.structE.left);
        printf(".%s",e->val.structE.right);
        break;
}
}


void codemulOp(mulOp *e){
switch(e->kind){
        case timesK:
        codemulOp(e->val.timesE.left);
        printf("*");
        codemulOp(e->val.timesE.right);
        break;

        case divK:
        codemulOp(e->val.divE.left);
        printf("/");
        codemulOp(e->val.divE.right);
        break;

        case modK:
        codemulOp(e->val.modE.left);
        printf("%%");
        codemulOp(e->val.modE.right);
        break;

        case coutK:
        codemulOp(e->val.coutE.left);
        printf("<<");
        codemulOp(e->val.coutE.right);
        break;

        case cinK:
        codemulOp(e->val.cinE.left);
        printf(">>");
        codemulOp(e->val.cinE.right);
        break;

        case ampK:
        codemulOp(e->val.ampE.left);
        printf("&");
        codemulOp(e->val.ampE.right);
        break;

        case ampcaratK:
	printf("~(");
        codemulOp(e->val.ampcaratE.left);
        printf("|");
        codemulOp(e->val.ampcaratE.right);
	printf(")");
        break;

        case factorK:
        codefactor(e->val.factorE);
        break;

}
}

void codeaddOp(addOp *e){
switch(e->kind){
        case plusK:
        if(e->type.type!=stringTYPE){
	codeaddOp(e->val.plusE.left);
        printf("+");
        codeaddOp(e->val.plusE.right);
	}
	else if(e->type.type==stringTYPE){
	printf("concatenate(");
	codeaddOp(e->val.plusE.left);
	printf(",");
	codeaddOp(e->val.plusE.right);
	printf(")");
	}
        break;

        case minusK:
        codeaddOp(e->val.minusE.left);
        printf("-");
        codeaddOp(e->val.minusE.right);
        break;

        case pipeK:
        codeaddOp(e->val.pipeE.left);
        printf("|");
        codeaddOp(e->val.pipeE.right);
        break;

        case caratK:
        codeaddOp(e->val.caratE.left);
        printf("^");
        codeaddOp(e->val.caratE.right);
        break;

        case mulOpK:
        codemulOp(e->val.mulOpE);
        break;
}
}

void codeexp(exp *e){
switch(e->kind){
        case orK:
        codeexp(e->val.orE.left);
        printf("||");
        codeexp(e->val.orE.right);
        break;

        case andK:
        codeexp(e->val.andE.left);
        printf("&&");
        codeexp(e->val.orE.right);
        break;

        case eqK:
        codeexp(e->val.eqE.left);
        printf("==");
        codeexp(e->val.eqE.right);
        break;

        case neqK:
        codeexp(e->val.neqE.left);
        printf("!=");
        codeexp(e->val.neqE.right);
        break;

        case GTK:
        codeexp(e->val.GTE.left);
        printf(">");
        codeexp(e->val.GTE.right);
        break;

        case GEK:
        codeexp(e->val.GEE.left);
        printf(">=");
        codeexp(e->val.GEE.right);
        break;

        case LTK:
        codeexp(e->val.LTE.left);
        printf("<");
        codeexp(e->val.LTE.right);
        break;

        case LEK:
        codeexp(e->val.LEE.left);
        printf(">=");
        codeexp(e->val.LEE.right);
        break;

        case addOpK:
        codeaddOp(e->val.addOpE);
        break;
}
}


void codeexpList(expList *e){
switch(e->kind){
        case ExpK:
        codeexp(e->val.expE);
        break;

        case expListK:
        codeexp(e->val.expE);
        printf(", ");
        codeexpList(e->val.expListE.expressionList);
        break;
}
}

void array_thing(SymbolType *t,char *name,int init, int start){
//printf("Type is: %d\n",t);
switch(*t){
        case intTYPE:
                printf("Array_int %s",name);
                if(init){
                        printf(";\ninitArray_int(&%s,%d);\n",name,start);
                }
        break;

        case floatTYPE:
                printf("Array_float %s",name);
                if(init){
                        printf(";\ninitArray_float(&%s,%d);\n",name,start);
                }
        break;

        case runeTYPE:
                printf("Array_char %s",name);
                if(init){
                        printf(";\ninitArray_char(&%s,%d);\n",name,start);
                }
        break;

        case boolTYPE:
                printf("Array_int %s",name);
                if(init){
                        printf(";\ninitArray_int(&%s,%d);\n",name,start);
                }
        break;

        case stringTYPE:
                printf("Array_string %s",name);
                if(init){
                        printf(";\ninitArray_string(&%s,%d);\n",name,start);
                }
        break;
	default:
		printf("Error: no case hit in array_thing");
	break;
}
}

void codetypetree(TYPETREE *t,char *name){
switch(t->type){
	case intTYPE:
	printf("int ");
	break;

	case floatTYPE:
	printf("float ");
	break;

	case boolTYPE:
	printf("int ");
	break;

	case runeTYPE:
	printf("char ");
	break;

	case stringTYPE:
	printf("char *");
	break;

	case sliceTYPE:
	array_thing(&t->val.arrayType->type,name,1,1);
//	printf("[]");
	break;

	case arrayTYPE:
	//codetypetree(t->val.arrayType);
        array_thing(&t->val.arrayType->type,name,1,1);
	printf("[]");
	break;

	case structTYPE:
//	codetypetree(t->val.structType);	
	break;

	case noTYPE:
	//printf("Something has gone wrong here");
	codetypeid(getPrimitive(symTable,t->idType));
	break;
}
}

void dummyassignmentexp(expList *i, expList *e, int f){
switch(i->kind){
        case ExpK:
	//if(f==1 && (symbolDefined(symTable, i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE)==0)){
	if(f==1){
//		printf("Type is: %s\n",(char *)&e->val.expE->type.type);
		codetypetree(&e->val.expE->type,i->val.expE->val.addOpE->val.mulOpE->val.factorE->val.idE);
	}	
        codeexp(i->val.expE);
        printf("=");
	codeexp(e->val.expE);
        //printf("\n");
        break;

        case expListK:
        //if(f==1 && (symbolDefined(symTable, i->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE)==0)){
        if(f==1){ 
	       codetypetree(&e->val.expListE.expression->type,i->val.expListE.expression->val.addOpE->val.mulOpE->val.factorE->val.idE);
        }  
        codeexp(i->val.expListE.expression);
        printf("=");
	codeexp(e->val.expListE.expression);
        printf(";\n");
        dummyassignmentexp(i->val.expListE.expressionList,e->val.expListE.expressionList, f);
        break;
}
}

void codeassignment(assignment *a){
switch(a->kind){
        case idListAssK:
        //prettyexpList(a->val.idListAssE.idList);
        //prettyexpList(a->val.idListAssE.expressionList);
        dummyassignmentexp(a->val.idListAssE.idList,a->val.idListAssE.expressionList, 0);
	break;

        case selfOpAssK:
        codeexp(a->val.opSelfAssE.identifier);
        codeselfop(a->val.opSelfAssE.selfOperator,a->val.opSelfAssE.identifier,a->val.opSelfAssE.expression);
	if(a->val.opSelfAssE.selfOperator->kind!=wtf){
	codeexp(a->val.opSelfAssE.expression);
	}
//	printf(";\n");
        break;
}
}

void codeincdec(incDecStmt *id){
switch(id->kind){
        case incK:
        codeexp(id->val.up);
        printf("++");
        break;

        case ddecK:
        codeexp(id->val.down);
        printf("--");
        break;
}
}

void codestmtexp(stmtExp *s){
switch(s->kind){
        case stmtExpK:
        codeexp(s->val.expStmt);
        break;
}
}

void codesimplestatement(simpleStatement *s){
switch(s->kind){
        case emptyStmtK:
        //printf(";");
        break;

        case assignK:
        codeassignment(s->val.assignE);
        break;

        case incDecK:
        codeincdec(s->val.incDecE);
        break;

        case sstmtExpK:
        codestmtexp(s->val.stmtexp);
        break;

        //deal with this for pptype later
        case shortK: //need to implement a constructor for shortK
	dummyassignmentexp(s->val.shortE.left,s->val.shortE.right, 1);
        break;
}
}


//this is not going to be fun to implement


void codeprintcontent(expList *e, int newline){
                switch(e->kind){
                        case ExpK:
                                //codeprinttypetree(p->val.printE.expressionList->val.expression->type);
                                //printf(getPercent(p->val.printE.expressionList->val.expression->type),p->val.printE.expressionList->val.expression);
                                printf("printf(\"");
                                switch(e->val.expE->type.type){
                                        case intTYPE:
                                                printf("%%d");
                                        break;
                                        case floatTYPE:
                                                printf("%%f");
                                        break;
                                        case boolTYPE:
                                                printf("%%d");
                                        break;
                                        case runeTYPE:
                                                printf("%%c");
                                        break;
                                        case stringTYPE:
                                                printf("%%s");

                                        break;
                                        case sliceTYPE:
                                        case arrayTYPE:
                                        case structTYPE:
                                                printf("printf(\"Error in the original Go Code - you can't print out slices, arrays, or structs - you have to access elements/fields\"");
                                        break;
					case noTYPE:
						printf("Something has gone wrong here");
					break;
                                }
                                if(newline==1){
                                        printf("\\n");
                                }
				printf("\",");
				codeexp(e->val.expE);
                                printf(");\n");
                        break;

                        case expListK:
				printf("printf(\"");
                                switch(e->val.expListE.expression->type.type){
                                        case intTYPE:
                                                printf("%%d");
                                        break;
                                        case floatTYPE:
                                                printf("%%f");
                                        break;
                                        case boolTYPE:
                                                printf("%%d");
                                        break;
                                        case runeTYPE:
                                                printf("%%c");
                                        break;
                                        case stringTYPE:
                                                printf("%%s");
					break;
                                        case sliceTYPE:
                                        case arrayTYPE:
                                        case structTYPE:
                                                printf("printf(\"Error in the original Go Code - you can't print out slices, arrays, or structs - you have to access elements/fields\"");
                                        break;
                                        case noTYPE:
                                //              printf("Something has gone wrong here");
                                        break;
                                }
                                if(newline==1){
                                        printf("\\n");
                                }
				printf("\",");
				codeexp(e->val.expListE.expression);
				printf(");\n");
				codeprintcontent(e->val.expListE.expressionList, newline);
                        break;
                }

}

void codeprint(print *p){
switch(p->kind){
        case printK:
        	codeprintcontent(p->val.printE.expressionList,0);
	break;

        case printlnK:
       		codeprintcontent(p->val.printE.expressionList,1);
	break;

        case printemptyK:
        	printf("printf();\n");
        break;

        case printlnemptyK:
        	printf("printf(\"\n\");\n");
        break;
}
}

void codereturn(returning *r){
switch(r->kind){
        case returnK:
	//no return because void
        //printf("return");
        break;

        case returnExpK:
        printf("return ");
        codeexp(r->val.returnExpE.expression);
        printf(";\n");
	break;
}
}

void codecaseexplist(expList *e){
switch(e->kind){
	case ExpK:
	printf("case ");
	codeexp(e->val.expE);
	printf(":\n");
	break;

	case expListK:
	printf("case ");
	codeexp(e->val.expListE.expression);
	printf(":\n");
	codecaseexplist(e->val.expListE.expressionList);
	break;
}
}

void codecaseif(expList *el, exp *e){
switch(el->kind){
	case ExpK:
	codeexp(e);
	printf("==");
	codeexp(el->val.expE);
	break;

	case expListK:
	codeexp(e);
	printf("==");
	codeexp(el->val.expListE.expression);
	printf("||");
	codecaseif(el->val.expListE.expressionList,e);
	break;

}
}

void codecaseifempty(expList *el){
switch(el->kind){
	case ExpK:
	codeexp(el->val.expE);
	break;

	case expListK:
	codeexp(el->val.expListE.expression);
	printf("||");
	codecaseifempty(el->val.expListE.expressionList);
}
}

void codecase(caseFall *c,exp *e){
switch(c->kind){
        case caseX:
        //printf("case ");
	//this will cause a problem - multiple expressions for a single case
        //codeexpList(c->val.caseE.left);
        //printf(":\n");
	printf("if(");
        //codecaseexplist(c->val.caseE.left);
	codecaseif(c->val.caseE.left,e);
	printf("){\n");
	codestatementlist(c->val.caseE.right);
        printf("}\n");
	break;

        case defaultX:
        //printf("default: \n");
        printf("else{\n");
	codestatementlist(c->val.defaultE);
        printf("}\n");
	break;
}
}

void codecaseempty(caseFall *c){
switch(c->kind){
        case caseX:
        //printf("case ");
        //this will cause a problem - multiple expressions for a single case
        //codeexpList(c->val.caseE.left);
        //printf(":\n");
        printf("if(");
        //codecaseexplist(c->val.caseE.left);
        codecaseifempty(c->val.caseE.left);
        printf("){\n");
        codestatementlist(c->val.caseE.right);
        printf("}\n");
        break;

        case defaultX:
        //printf("default: \n");
        printf("else{\n");
        codestatementlist(c->val.defaultE);
        printf("}\n");
        break;
}
}

void codecaselist(caseList *cl,exp *e){
switch(cl->kind){
        case emptyCase:
        break;//do nothing

        case fullCase:
        codecase(cl->val.caseX.casey,e);
        codecaselist(cl->val.caseX.right,e);
        break;
}
}

void codecaselistempty(caseList *cl){
switch(cl->kind){
        case emptyCase:
        break;//do nothing

        case fullCase:
        codecaseempty(cl->val.caseX.casey);
        codecaselistempty(cl->val.caseX.right);
        break;
}
}

void codeswitch(switchStmt *s){
switch(s->kind){
        case leftright:
        codesimplestatement(s->val.leftrightE.simple);
	printf(";\n");
//	printf("switch(");
        //codeexp(s->val.leftrightE.e);
  //      printf("){\n");
        codecaselist(s->val.leftrightE.cases,s->val.leftrightE.e);
    //    printf("}\n");
	break;

        case right:
        //printf("switch(");
        //codeexp(s->val.rightE.e);
        //printf(") {\n");
        codecaselist(s->val.rightE.cases,s->val.rightE.e);
        //printf("}\n");
        break;

        case left:
        codesimplestatement(s->val.leftE.simple);
        printf(";\n");
	//printf("switch(");
        //printf("1) {\n");
        codecaselistempty(s->val.leftE.cases);
        //printf("}\n");
        break;

        case none:
        //printf("switch(1) {\n");
        codecaselistempty(s->val.noneE.cases);
        //printf("}\n");
        break;
}
}

void codeforloop(forLoop *f){
switch(f->kind){
        case stateListLoopK:
        printf("while(1) ");
        codeblock(f->val.stateListLoopE.stateList);
        printf("\n");
        break;

        case condLoopK:
        printf("while(");
        codecondition(f->val.condLoopE.cond);
        printf(")");
	codeblock(f->val.condLoopE.stateList);
        printf("\n");
        break;

        case idCondLoopK:
        printf("for(");
        codesimplestatement(f->val.idCondLoopE.simpleState1);
        printf(";");
        codecondition(f->val.idCondLoopE.cond);
        printf(";");
        codesimplestatement(f->val.idCondLoopE.simpleState2);
        printf(")");
	codeblock(f->val.idCondLoopE.stateList);
        printf("\n");
        break;

        case nocondK:
        printf("for(");
        codesimplestatement(f->val.nocondE.simpleState1);
        printf(";");
        printf("1;");
        codesimplestatement(f->val.nocondE.simpleState2);
        printf(")");
	codeblock(f->val.nocondE.stateList);
        printf("\n");
        break;

}
}

void codeif(ifStmt *i){
switch(i->kind){
        case ifK:
        printf("if(");
        codecondition(i->val.ifES.ifCond);
        printf(")");
	codeblock(i->val.ifES.stateList);
        printf("\n");
        break;

        case ifS:
        codesimplestatement(i->val.ifE.Simple);
        printf(";\n"); 
	printf("if(");
        codecondition(i->val.ifE.ifCond);
        printf(")");
	codeblock(i->val.ifE.stateList);
        printf("\n");
        break;

        case ifelseK:
        codesimplestatement(i->val.ifE.Simple);
        printf(";\n");
	printf("if(");
        codecondition(i->val.ifElseES.ifCond);
	printf(")");
	codeblock(i->val.ifElseES.stateList1);
        printf("else ");
        codeblock(i->val.ifElseES.stateList2);
        printf("\n");
        break;
        
	case ifelseS:
        codesimplestatement(i->val.ifelseE.Simple);
        printf(";\n");
	printf("if(");
        codecondition(i->val.ifelseE.ifCond);
	printf(")");
        codeblock(i->val.ifelseE.stateList1);
        printf("else ");
        codeblock(i->val.ifelseE.stateList2);
        printf("\n");
        break;

        case ifelseifK:
        printf("if(");
        codecondition(i->val.ifelseelseES.ifCond);
        printf(")");
	codeblock(i->val.ifelseelseES.stateList1);
        printf("else ");
        codeif(i->val.ifelseelseES.recurse);
        break;

	case ifelseifS:
        codesimplestatement(i->val.ifelseelseE.Simple);
        printf(";\n");
	printf("if(");
        codecondition(i->val.ifelseelseE.ifCond);
        printf(")");
	codeblock(i->val.ifelseelseE.stateList1);
        printf("else ");
        codeif(i->val.ifelseelseE.recurse);
        break;
}
}

void codestatement(statement *s){
printf("\t");
switch(s->kind){
        case ssimpleK:
        codesimplestatement(s->val.simple);
        printf(";\n");
        break;

        case sprintK:
        codeprint(s->val.print);
//        printf(";\n");
        break;

        case sreturnK:
        codereturn(s->val.returned);
//        printf(";\n");
        break;

        case sifK:
        codeif(s->val.iffy);
        printf("\n");
	break;

        case sforK:
        codeforloop(s->val.loop);
        printf("\n");
	break;

        case sswitchK:
        codeswitch(s->val.switchy);
        printf("\n");
	break;

        //1 means it's okay, 0 means it's not
        case sbreakK:
        printf("break;\n");
        break;

        case scontinueK:
        printf("continue;\n");
        break;

        case stype:
        codetypedec(s->val.tvar);
        //printf("\n");
        break;

        case svar:
        //PROBLEM IS RIGHT HERE
        codevardec(s->val.var);
        //printf("\n");
        break;

        case sblock:
        printf("{\n");
        codestatementlist(s->val.block);
        printf("\n}\n");
        break;

}
}

void codestatementlist(statementList *sl){
switch(sl->kind){
        case emptyStateListK:
        break;//do nothing

        case stateListK:
        codestatement(sl->val.stateListE.state);
        codestatementlist(sl->val.stateListE.stateList);
        break;
}
}

void codeblock(block *b){
	printf("{\n");
        codestatementlist(b->val.left);
	printf("\n}\n");
}

void printparamname(identifierList *i, char *t){
switch(i->kind){

        case singleidK:
        codetypeid(getPrimitive(symTable,t));
        printf("%s",i->val.singleE);
        break;

        case multipleK:
        codetypeid(getPrimitive(symTable,t));
        printf("%s, ",i->val.idListE.identifier);
        printparamname(i->val.idListE.idList,t);
        break;
}
}

void printparamtype(identifierList *i, type *t){
switch(i->kind){

	case singleidK:
	codetype(t,i->val.singleE,0);
	if(t->kind!=typestructtypeK && t->kind!=typedecarrayK && t->kind!=typesliceK){ 
	printf("%s",i->val.singleE);
	}
	break;

	case multipleK:
	codetype(t,i->val.idListE.identifier,0);
	printf("%s, ",i->val.idListE.identifier);
	printparamtype(i->val.idListE.idList,t);
	break;
}
}

void codeparam(param *p){
switch(p->kind){

	case onlyparam:
        if(p->val.onlyE.type->kind==typestructtypeK){
        //char *name=makename();
        identifierList *name=makeidListsingle("name");
        //codetype(v->val.typeE.idType,v->val.typeE.names->val.singleE);
        printparamtype(name,p->val.onlyE.type);
        //printf(" ");
        printf("%s;\n",name->val.singleE);
        printf("struct %s ",name->val.singleE);
        codeidentifierlist(p->val.onlyE.names);
        printf(";\n");
        }
        else if(p->val.onlyE.type->kind==typedecarrayK){
        printparamtype(p->val.onlyE.names,p->val.onlyE.type);
        printf(";\n");
        }	
	else{
	printparamtype(p->val.onlyE.names,p->val.onlyE.type);
	}
	break;

	case idparam:
	printparamname(p->val.idE.names,p->val.idE.type);
	break;

}
}

void codeparamlist(paramList *pl){
switch(pl->kind){

	case emptyParamListK:
	codeparam(pl->val.p);
	break;

	case fullParamListK:
	codeparam(pl->val.fullE.p);
	printf(", ");
	codeparamlist(pl->val.fullE.pl);
	break;

}
}

void codefuncdec(funcDec *f){
switch(f->kind){
        case typeful:
        codetype(f->val.typefulE.type,f->val.typefulE.identifier,0);
	printf("%s",f->val.typefulE.identifier);
        printf("(");
        codeparamlist(f->val.typefulE.pList);
        printf(")");
        codeblock(f->val.typefulE.Blocky);
        printf("\n");
        break;

        case typeless:
        if(!strcmp("main",f->val.typelessE.identifier)){
		printf("int ");
	}
	else{
		printf("void ");
	}
	printf("%s",f->val.typelessE.identifier);
        printf("(");
        codeparamlist(f->val.typelessE.pList);
        printf(")");
        codeblock(f->val.typelessE.Blocky);
        printf("\n");
        break;

        case nonoK:
        if(!strcmp("main",f->val.noparamnotype.identifier)){
                printf("int ");
        }
        else{
                printf("void ");
        }
        printf("%s",f->val.noparamnotype.identifier);
        printf("()");
        codeblock(f->val.noparamnotype.Blocky);
        printf("\n");
        break;

        case noK:
        codetype(f->val.notype.type,f->val.notype.identifier,0);
	printf("%s",f->val.notype.identifier);
        printf("()");
     //   codetype(f->val.notype.type,f->val.notype.identifier,0);
        codeblock(f->val.notype.Blocky);
        printf("\n");
        break;

        case typeIDK:
        codetypeid(getPrimitive(symTable,f->val.typeIDE.type));
	//printf("%s",f->val.typeIDE.type); 
	printf("%s",f->val.typeIDE.identifier);
        printf("(");
        codeparamlist(f->val.typeIDE.pList);
        printf(")");
        codeblock(f->val.typeIDE.Blocky);
        printf("\n");
        break;

        case noIDK:
//        printf("void ");
  	printf("%s ",f->val.noIDE.name);
        printf("%s",f->val.noIDE.identifier);
        printf("()");
	//printf("() %s",f->val.noIDE.name); //is this okay?
        codeblock(f->val.notype.Blocky);
        printf("\n");
        break;

}
}

void codetype(type *t, char *name, int init);

void dummyassignment(identifierList *i, expList *e, int t){
switch(i->kind){
	case singleidK:
	if(t==1){
		codetypetree(&e->val.expE->type,i->val.singleE);
	}
	printf("%s=",i->val.singleE);
	codeexp(e->val.expE);
//	printf("\n");
	break;

	case multipleK:
        if(t==1){
		codetypetree(&e->val.expListE.expression->type,i->val.idListE.identifier);
        }
	printf("%s=",i->val.idListE.identifier);
        codeexp(e->val.expListE.expression);
	printf(";\n");
	dummyassignment(i->val.idListE.idList,e->val.expListE.expressionList,t);
	break;
}
}

void codeidentifierlist(identifierList *i){
switch(i->kind){
        case singleidK:
        printf("%s",i->val.singleE);
        break;

        case multipleK:
        printf("%s, ",i->val.idListE.identifier);
        codeidentifierlist(i->val.idListE.idList);
        break;
}
}

void codetypeid(SymbolType t){
switch((int)t){
        case intTYPE:
        printf("int ");
        break;

        case floatTYPE:
        printf("float ");
        break;

        case boolTYPE:
        printf("int ");
        break;

        case runeTYPE:
        printf("char ");
        break;

        case stringTYPE:
        printf("char *");
        break;

        case sliceTYPE:
//        codetypetree(t->val.arrayType);
  //      printf("[]");
        break;

        case arrayTYPE:
//        codetypetree(t->val.arrayType);
//        printf("[]");
        break;

        case structTYPE:
//      codetypetree(t->val.structType);        
        break;

        case noTYPE:
        //printf("Something has gone wrong here");
        break;
}
}

void array(type *t,char *name,int init, int start){
switch(t->kind){
	case typeintK:
		printf("Array_int %s",name);
		if(init){
        		printf(";\ninitArray_int(&%s,%d)",name,start);
        	}
	break;

	case typefloatK:
                printf("Array_float %s",name);
                if(init){
                        printf(";\ninitArray_float(&%s,%d)",name,start);
                }
	break;

	case typeruneK:
                printf("Array_char %s",name);
                if(init){
                        printf(";\ninitArray_char(&%s,%d)",name,start);
                }
	break;

	case typeboolK:
                printf("Array_int %s",name);
                if(init){
                        printf(";\ninitArray_int(&%s,%d)",name,start);
                }
	break;

	case typestringK:
                printf("Array_string %s",name);
                if(init){
                        printf(";\ninitArray_string(&%s,%d)",name,start);
                }
	break;
}
}

void codetype(type *t, char *name, int init){
switch(t->kind){
        case typeintK:
        printf("int ");
        break;

        case typefloatK:
        printf("float ");
        break;

        case typestringK:
        printf("char *");
        break;

        case typeruneK:
        printf("char ");
        break;

        case typeboolK:
        printf("int ");
        break;

        case typesliceK:
        //codetype(t->val.typesliceE,name);
        //printf(" %s",name);
	//printf("[] ");
	//printf("Array %s",name);
	//if(init){
	//printf(";\ninitArray(&%s,1)",name);
	//}
	array(t->val.typesliceE,name,init,1);
	break;

        case typesliceIDK:
        //codetype(t->val.typesliceE,name,init);
        //printf(" %s",name);
        //printf("[] ");
	//array(t->val.typesliceIDE,name,init,1);
	break;

        case typedecarrayK:
//        codetype(t->val.typedecarrayE.right,name);
//	printf("%s",name);
//	printf("[");
  //      printf("%d",t->val.typedecarrayE.size);
    //    printf("] ");
	//printf("Array %s",name);
	//if(init){
	//printf(";\ninitArray(&%s,%d)",name,t->val.typedecarrayE.size);
        //}
	array(t->val.typedecarrayE.right,name,init,t->val.typedecarrayE.size);
	break;

        case typedecarrayIDK:
        printf("%s",t->val.typedecarrayIDE.right);
        printf(" [");
        printf("%d",t->val.typedecarrayIDE.size);
        printf("] ");
        break;

        case typeoctarrayK:
        codetype(t->val.typeoctarrayE.right,name,init);
	printf(" [");
        printf("%o",t->val.typeoctarrayE.size);
        printf("] ");
        break;

        case typeoctarrayIDK:
        printf("%s",t->val.typeoctarrayIDE.right);
        printf(" [");
        printf("%o",t->val.typeoctarrayIDE.size);
        printf("] ");
        break;

        case typehexarrayK:
        codetype(t->val.typehexarrayE.right,name,init);
        printf(" [");
        printf("%x",t->val.typehexarrayE.size);
        printf("] ");
        break;

        case typehexarrayIDK:
        printf("%s",t->val.typehexarrayIDE.right);
        printf(" [");
        printf("%x",t->val.typehexarrayIDE.size);
        printf("] ");
        break;

        case typestructtypeK:
        printf("typedef struct %s {\n",name);
	codestruct(t->val.t);
	printf("}");
	break;

        case typenoveltyK://don't actually use this
        //do shit here
        break;
}
}

char *makename(){
	char *returnThis="";
	char *name="name";
	sprintf(returnThis,"%d",namenum);
	namenum++;
	strcat(name,returnThis);
	return name;	
}

void codevar(var *v){
switch(v->kind){
        case typeK:
        if(v->val.typeE.idType->kind==typestructtypeK){
	//char *name=makename();
	char *name="name";
	//codetype(v->val.typeE.idType,v->val.typeE.names->val.singleE);
        codetype(v->val.typeE.idType,name,1);
	//printf(" ");
	printf("%s;\n",name);
	printf("struct %s ",name);
	codeidentifierlist(v->val.typeE.names);
	printf(";\n");
	}
	else if(v->val.typeE.idType->kind==typedecarrayK || v->val.typeE.idType->kind==typesliceK){
	codetype(v->val.typeE.idType,v->val.typeE.names->val.singleE,1);
	printf(";\n");
	}
	//else if(v->val.typeE.idType->kind==typesliceK){
	//codetype
	//}
	else{
	codetype(v->val.typeE.idType,"error message",1);
	codeidentifierlist(v->val.typeE.names);
	printf(";\n");
	}
        break;

        case veqK:
        dummyassignment(v->val.eqE.names,v->val.eqE.eqExp, 1);
        break;

        case vtypeEqK:
        //printf("in type eq case");
//	codetype(v->val.typeEqE.idType);
  //      printf(" ");
//	codeidentifierlist(v->val.typeEqE.names);
//	printf(";\n");
        dummyassignment(v->val.typeEqE.names,v->val.typeEqE.eqExp,1);
        break;

        case vidK:
	//printf("%s ",v->val.vidE.idType);
	//codetypeid(getPrimitive(symTable,v->val.vidE.idType));
	printf("%s ",v->val.vidE.idType);
	codeidentifierlist(v->val.typeE.names);
        printf(";\n");
	break;

	//PROBLEM HERE
        case vidEqK:
        //printf("%s=",v->val.vidEqE.idType);
        //codetypeid(getPrimitive(symTable,v->val.vidE.idType));
	//codeidentifierlist(v->val.vidEqE.names);
        printf("%s ",v->val.vidE.idType);
	dummyassignment(v->val.vidEqE.names,v->val.vidEqE.eqExp,0);
        break;
}
}

void codevarlist(varList *v){
switch(v->kind){
        case varK:
        codevar(v->val.variableE.variable);
        break;

        case varListK:
        codevar(v->val.varListE.variable);
        printf(";\n");
	codevarlist(v->val.varListE.variableList);
        break;
}
}

void codevardec(varDec *v){
switch(v->kind){
        case singleK:
        codevar(v->val.varE);
        printf(";\n");
        break;

        case distributedK:
        codevarlist(v->val.varListE);
        printf(";\n");
        break;
}
}

void codeparamlisttype(identifierList *i, type *t){
switch(i->kind){
	case singleidK:
	if(t->kind==typestructtypeK){
        //char *name=makename();
        identifierList *name=makeidListsingle("name");
        //codetype(v->val.typeE.idType,v->val.typeE.names->val.singleE);
        codetype(t,name->val.singleE,0);
        //printf(" ");
        printf("%s;\n",name->val.singleE);
        printf("struct %s ",name->val.singleE);
        codeidentifierlist(i);
        printf(";\n");
        }    
        else if(t->kind==typedecarrayK){
        codetype(t,i->val.singleE,0);
        printf(";\n");
        }
	else{
	codetype(t,i->val.singleE,0);
	printf("%s;\n",i->val.singleE);
	}
	break;

	case multipleK:
        if(t->kind==typestructtypeK){
        //char *name=makename();
        identifierList *name=makeidListsingle("name");
        //codetype(v->val.typeE.idType,v->val.typeE.names->val.singleE);
        codetype(t,name->val.idListE.identifier,0);
        //printf(" ");
        printf("%s;\n",name->val.idListE.identifier);
        printf("struct %s ",name->val.idListE.identifier);
        codeidentifierlist(i);
        printf(";\n");
        }
        else if(t->kind==typedecarrayK){
        codetype(t,i->val.idListE.identifier,0);
        printf(";\n");
        }
        else{
        codetype(t,i->val.idListE.identifier,0);
        printf("%s;\n",i->val.idListE.identifier);
        }
	codeparamlisttype(i->val.idListE.idList,t);
	break;
}
}

void codeparamlistid(identifierList *i, char *t){
switch(i->kind){
        case singleidK:
	//codetypeid(getPrimitive(symTable,t));
	printf("%s ",t);
	printf("%s;\n",i->val.singleE);
        //printf("%s %s;\n",codetypeid(t), i->val.singleE);
        break;

        case multipleK:
	//codetypeid(getPrimitive(symTable,t));
	printf("%s ",t);
	printf("%s;\n",i->val.idListE.identifier);
        //printf("%s %s;\n",codetypeid(t),i->val.idListE.identifier);
        codeparamlistid(i->val.idListE.idList,t);
        break;
}
}

void codeparamstruct(param *p){
switch(p->kind){
	case onlyparam:
	codeparamlisttype(p->val.onlyE.names,p->val.onlyE.type);
	break;

	case idparam:
	codeparamlistid(p->val.idE.names,p->val.idE.type);
	break;
}
}

void codestructlist(structList *s){
switch(s->kind){
	case singlestructK:
	codeparamstruct(s->val.singlestructE);
	break;

	case manystructK:
	codeparamstruct(s->val.manystructE.left);
	printf(";\n");
	codestructlist(s->val.manystructE.right);
	break;
}
}

void codestruct(structType *s){
switch(s->kind){
	case emptyStructTypeK:
	break;

	case fullStructTypeK:
	codestructlist(s->val.left);
	break;
}
}

void codetypeline(typeLine *t){
if(t->kind==singletypeK && t->val.singleE.right->kind==typestructtypeK){
	printf("typedef struct %s {\n",t->val.singleE.name);
	codestruct(t->val.singleE.right->val.t);
	printf("\n} %s;\n",t->val.singleE.name);
}
else if(t->kind==singletypeK){
	printf("typedef ");
	codetype(t->val.singleE.right,t->val.singleE.name,0);
	printf("%s",t->val.singleE.name);
	printf(";\n");
}
else if(t->kind==singleIDK){
	printf("typedef %s %s;\n",t->val.singleIDE.right,t->val.singleIDE.name); 
}
}

void codetypelinelist(typeLineList *t){
switch(t->kind){
	case tLineK:
	codetypeline(t->val.tLine);
	break;

	case tLineListK:
	codetypeline(t->val.tLineListE.tLine);
	codetypelinelist(t->val.tLineListE.tLineList);
	break;
}
}

void codetypedec(typeDec *t){
switch(t->kind){
	case singleDecK:
	codetypeline(t->val.singleDecE);
	break;

	case manyDecK:
	codetypelinelist(t->val.manyDecE);
	break;
}
}

void codedec(dec *d){
switch(d->kind){
        case varDecK:
        codevardec(d->val.varDecE);
        break;

        case typeDecK:
        codetypedec(d->val.typeDecE);
        break;

        case funcDecK:
        codefuncdec(d->val.funcDecE);
        break;
}
}

void codedeclist(decList *d){
	switch(d->kind){

	case emptyDecK:
	break; //do nothing

	case fullDecK:
	codedec(d->val.fullDecE.left);
	codedeclist(d->val.fullDecE.right);
	break;

}
}

void codepackage(package *p){
//what do here?
}

void codeprogram(program *p){
//printf("#include <stdio.h>\n#include \"golite.h\"\nvoid initArray(Array *a, int initialSize);\nvoid insertArray(Array *a, int element);\nvoid freeArray(Array *a);\n");
printf("#include <stdio.h>\n#include \"golite.h\"\n");
codepackage(p->val.progE.left);
codedeclist(p->val.progE.right);
codemain();
}
