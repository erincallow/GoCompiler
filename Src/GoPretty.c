#include <stdio.h>
#include <stdlib.h>
#include "GoPretty.h"

//continue pptype-ing everything from here (came from if - finish this, then do for)
void prettycondition(condition *c, int i){
switch(c->kind){
	case condK:
	prettyexp(c->val.condE);

	//if(i==1){
	//printf("\n/*\n");
	//printf("The type of the above condition is:\n");
	//prettytypepp(c->val.condE);
	//printf("\n*/\n");
	//}

	break;
}
}

void prettysimplestatementtype(simpleStatement *s, int i);

void prettyselfop(selfOp *s){
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
	printf("&^=");
	break;
}
}

void prettystructtype(structType *s);

void prettytype(type *t){
switch(t->kind){
	case typeintK:
	printf("int");
	break;

	case typefloatK:
	printf("float64");
	break;

	case typestringK:
	printf("string");
	break;

	case typeruneK:
	printf("rune");
	break;

	case typeboolK:
	printf("bool");
	break;

	case typesliceK:
	printf("[] ");
	prettytype(t->val.typesliceE);
	break;

	case typesliceIDK:
	printf("[] %s",t->val.typesliceIDE);
	break;

	case typedecarrayK:
	printf("[");
	printf("%d",t->val.typedecarrayE.size);
	printf("] ");
	prettytype(t->val.typedecarrayE.right);
	break;

	case typedecarrayIDK:
	printf("[");
	printf("%d",t->val.typedecarrayIDE.size);
	printf("] ");
	printf("%s",t->val.typedecarrayIDE.right);
	break;

	case typeoctarrayK:
        printf("[");
        printf("%o",t->val.typeoctarrayE.size);
        printf("] ");
	prettytype(t->val.typeoctarrayE.right);
        break;

	case typeoctarrayIDK:
	printf("[");
	printf("%o",t->val.typeoctarrayIDE.size);
	printf("] ");
	printf("%s",t->val.typeoctarrayIDE.right);
	break;

	case typehexarrayK:
        printf("[");
        printf("%x",t->val.typehexarrayE.size);
        printf("] ");
	prettytype(t->val.typehexarrayE.right);
        break;

	case typehexarrayIDK:
	printf("[");
	printf("%x",t->val.typehexarrayIDE.size);
	printf("] ");
	printf("%s",t->val.typehexarrayIDE.right);
	break;

	case typestructtypeK:
	//printf("struct {\n");
	prettystructtype(t->val.t);
	break;

	case typenoveltyK://don't actually use this
	//do shit here
	break;
}
}

void prettyexpList(expList *e){
switch(e->kind){
	case ExpK:
	prettyexp(e->val.expE);
	break;

	case expListK:
	prettyexp(e->val.expE);
	printf(", ");
	prettyexpList(e->val.expListE.expressionList);
	break;
}
}

void prettyexp(exp *e){
switch(e->kind){
	case orK:
	prettyexp(e->val.orE.left);
	printf("||");
	prettyexp(e->val.orE.right);
	break;

	case andK:
	prettyexp(e->val.andE.left);
	printf("&&");
	prettyexp(e->val.orE.right);
	break;

	case eqK:
	prettyexp(e->val.eqE.left);
	printf("==");
	prettyexp(e->val.eqE.right);
	break;

	case neqK:
	prettyexp(e->val.neqE.left);
	printf("!=");
	prettyexp(e->val.neqE.right);
	break;

	case GTK:
	prettyexp(e->val.GTE.left);
	printf(">");
	prettyexp(e->val.GTE.right);
	break;
	
	case GEK:
	prettyexp(e->val.GEE.left);
	printf(">=");
	prettyexp(e->val.GEE.right);
	break;

        case LTK:
        prettyexp(e->val.LTE.left);
        printf("<");
        prettyexp(e->val.LTE.right);
        break;

        case LEK:
        prettyexp(e->val.LEE.left);
        printf(">=");
        prettyexp(e->val.LEE.right);
        break;

	case addOpK:
	prettyaddOp(e->val.addOpE);
	break;
}
}

void prettyaddOp(addOp *e){
switch(e->kind){
	case plusK:
	prettyaddOp(e->val.plusE.left);
	printf("+");
	prettyaddOp(e->val.plusE.right);
	break;

	case minusK:
	prettyaddOp(e->val.minusE.left);
	printf("-");
	prettyaddOp(e->val.minusE.right);
	break;
	
	case pipeK:
	prettyaddOp(e->val.pipeE.left);
	printf("|");
	prettyaddOp(e->val.pipeE.right);
	break;

	case caratK:
	prettyaddOp(e->val.caratE.left);
	printf("^");
	prettyaddOp(e->val.caratE.right);
	break;

	case mulOpK:
	prettymulOp(e->val.mulOpE);
	break;
}
}

void prettymulOp(mulOp *e){
switch(e->kind){
        case timesK:
        prettymulOp(e->val.timesE.left);
        printf("*");
        prettymulOp(e->val.timesE.right);
        break;

        case divK:
        prettymulOp(e->val.divE.left);
        printf("/");
        prettymulOp(e->val.divE.right);
        break;

        case modK:
        prettymulOp(e->val.modE.left);
        printf("%%");
        prettymulOp(e->val.modE.right);
        break;

        case coutK:
        prettymulOp(e->val.coutE.left);
        printf("<<");
        prettymulOp(e->val.coutE.right);
        break;

        case cinK:
        prettymulOp(e->val.cinE.left);
        printf(">>");
        prettymulOp(e->val.cinE.right);
        break;

        case ampK:
        prettymulOp(e->val.ampE.left);
        printf("&");
        prettymulOp(e->val.ampE.right);
        break;

        case ampcaratK:
        prettymulOp(e->val.ampcaratE.left);
        printf("&^");
        prettymulOp(e->val.ampcaratE.right);
        break;

        case factorK:
        prettyfactor(e->val.factorE);
        break;

}
}

void prettyfactor(factor *e){
switch(e->kind){
	case parenK:
	printf("(");
	prettyexp(e->val.parenE);
	printf(")");
	break;

	case uplusK:
	printf("+");
	prettyfactor(e->val.uplusE);
	break;
	
	case uminusK:
	printf("-");
	prettyfactor(e->val.uminusE);
	break;

	case notK:
	printf("!");
	prettyfactor(e->val.notE);
	break;

	case ucaratK:
	printf("^");
	prettyfactor(e->val.ucaratE);
	break;

	case utimesK:
	printf("*");
	prettyfactor(e->val.utimesE);
	break;

	case uampK:
	printf("&");
	prettyfactor(e->val.uampE);
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
	prettytype(e->val.castE.left);
	printf("(");
	prettyexp(e->val.castE.right);
	printf(")");
	break;

	case funccallK:
	prettyfactor(e->val.funccallE.name);
	printf("(");
	prettyexpList(e->val.funccallE.right);
	printf(")");
	break;

	case funccallemptyK:
	prettyfactor(e->val.funccallemptyE);
	printf("()");
	break;

	case appendK:
	printf("append(%s,",e->val.appendE.name);
	prettyexp(e->val.appendE.right);
	printf(")");
	break;

	case trueK:
	printf("true");
	break;

	case falseK:
	printf("false");
	break;

	case arrayK:
	prettyfactor(e->val.arrayE.left);
	printf("[");
	prettyexp(e->val.arrayE.right);
	printf("]");
	break;

	case estructK:
	prettyfactor(e->val.structE.left);
	printf(".%s",e->val.structE.right);
	break;
}
}

void prettystmtexp(stmtExp *s, int i){
switch(s->kind){
	case stmtExpK:
	prettyexp(s->val.expStmt);

	if(i==1){
	printf("\n/*\n");
	printf("This is the type of the expression in the above statement expression:\n");
	prettytypepp(s->val.expStmt);
	printf("\n*/\n");
	}
	break;
}
}

void prettycase(caseFall *c, int i){
switch(c->kind){
	case caseX:
	printf("case ");
	prettyexpList(c->val.caseE.left);
	printf(":\n");
	if(i==1){
	printf("\n/*\n");
	printf("These are the types of the above list of cases:\n");
	prettytypelistpp(c->val.caseE.left);

	printf("\n*/\n");
	}
	prettystatementlist(c->val.caseE.right, i);
	break;

	case defaultX:
	printf("default: \n");
	prettystatementlist(c->val.defaultE, i);
	break;
}
}


void prettycaselist(caseList *cl, int i){
switch(cl->kind){
	case emptyCase:
	break;//do nothing

	case fullCase:
	prettycase(cl->val.caseX.casey, i);
	prettycaselist(cl->val.caseX.right, i);
	break;
}
}

void prettyswitch(switchStmt *s, int i){
switch(s->kind){
	case leftright:
	printf("switch ");
	prettysimplestatement(s->val.leftrightE.simple, 0);
	prettyexp(s->val.leftrightE.e);
	printf("{\n");
	prettycaselist(s->val.leftrightE.cases, i);
	printf("}\n");
	
	if(i==1){
	printf("\n/*\n The type for the expression in the switch is: \n");
        prettytypepp(s->val.leftrightE.e);
	printf("\n*/\n");
	}
	prettysimplestatementtype(s->val.leftrightE.simple,i);
	break;

	case right:
	printf("switch ");
	prettyexp(s->val.rightE.e);
	printf(" {\n");
	prettycaselist(s->val.rightE.cases, i);
	printf("}\n");
	break;

        if(i==1){
        printf("\n/*\n The type for the expression in the switch is: \n");
        prettytypepp(s->val.rightE.e);
        printf("\n*/\n");
        }

	case left:
	printf("switch ");
	prettysimplestatement(s->val.leftE.simple, 0);
	printf("; {\n");
	prettycaselist(s->val.leftE.cases, i);
	printf("}\n");
        prettysimplestatementtype(s->val.leftE.simple,i);
	break;

	case none:
	printf("switch {\n");
	prettycaselist(s->val.noneE.cases, i);
	printf("}\n");
	break;
}
}

void prettyforloop(forLoop *f, int i){
switch(f->kind){
	case stateListLoopK:
	printf("for ");
	prettyblock(f->val.stateListLoopE.stateList, i);
	printf("\n");
	break;

	case condLoopK:
	printf("for ");
	prettycondition(f->val.condLoopE.cond, 0);
	prettyblock(f->val.condLoopE.stateList, i);
	printf("\n");

	if(i==1){
        printf("\n/*\n");
        printf("The type of the loop condition is:\n");
        prettytypepp(f->val.condLoopE.cond->val.condE);
        printf("\n*/\n");
        }
	
	break;

	case idCondLoopK:
	printf("for ");
	prettysimplestatement(f->val.idCondLoopE.simpleState1, 0);
	printf(";");
	prettycondition(f->val.idCondLoopE.cond, 0);
	printf(";");
	prettysimplestatement(f->val.idCondLoopE.simpleState2, 0);
	prettyblock(f->val.idCondLoopE.stateList, i);
	printf("\n");

	if(i==1){
        prettysimplestatementtype(f->val.idCondLoopE.simpleState1,i);
	printf("\n/*\n");
        printf("The type of the loop condition is:\n");
        //prettytypepp(f->val.condLoopE.cond->val.condE);
        printf("\n*/\n");
	prettysimplestatementtype(f->val.idCondLoopE.simpleState2,i);
        }

	break;

	case nocondK:
        printf("for ");
        prettysimplestatement(f->val.nocondE.simpleState1, 0);
        printf(";");
        printf(";");
        prettysimplestatement(f->val.nocondE.simpleState2, 0);
        prettyblock(f->val.nocondE.stateList, i);
        printf("\n");

	if(i==1){
	prettysimplestatementtype(f->val.nocondE.simpleState1,i);
	prettysimplestatementtype(f->val.nocondE.simpleState2,i);
	}

	break;

}
}

void prettyif(ifStmt *i, int n){
switch(i->kind){
	case ifK:
	printf("if ");
	prettycondition(i->val.ifES.ifCond, n);
	prettyblock(i->val.ifES.stateList, n);
	printf("\n");
	
	if(n==1){
        printf("\n/*\n");
        printf("The type of the if condition is:\n");
        prettytypepp(i->val.ifES.ifCond->val.condE);
        printf("\n*/\n");
        }

	break;

	case ifS:
	printf("if ");
	prettysimplestatement(i->val.ifE.Simple, 0);
	printf(" ; ");
	prettycondition(i->val.ifE.ifCond, n);
	prettyblock(i->val.ifE.stateList, n);
	printf("\n");

        prettysimplestatementtype(i->val.ifE.Simple,n);	
	if(n==1){
        printf("\n/*\n");
        printf("The type of the if condition is:\n");
        prettytypepp(i->val.ifE.ifCond->val.condE);
        printf("\n*/\n");
        }
	
	break;

	case ifelseK:
	printf("if ");
	prettycondition(i->val.ifElseES.ifCond, n);
	prettyblock(i->val.ifElseES.stateList1, n);
	printf("else ");
	prettyblock(i->val.ifElseES.stateList2, n);
	printf("\n");
	
        if(n==1){
        printf("\n/*\n");
        printf("The type of the if condition is:\n");
        prettytypepp(i->val.ifElseES.ifCond->val.condE);
        printf("\n*/\n");
        }

	break;

	case ifelseS:
	printf("if ");
	prettysimplestatement(i->val.ifelseE.Simple, 0);
	printf(" ; ");
	prettycondition(i->val.ifelseE.ifCond, n);
	prettyblock(i->val.ifelseE.stateList1, n);
	printf("else ");
	prettyblock(i->val.ifelseE.stateList2, n);
	printf("\n");
	
        prettysimplestatementtype(i->val.ifelseE.Simple,n);
        if(n==1){
        printf("\n/*\n");
        printf("The type of the if condition is:\n");
        prettytypepp(i->val.ifelseE.ifCond->val.condE);
        printf("\n*/\n");
        }

	break;

	case ifelseifK:
	printf("if ");
	prettycondition(i->val.ifelseelseES.ifCond, n);
	prettyblock(i->val.ifelseelseES.stateList1, n);
	printf("else ");
	prettyif(i->val.ifelseelseES.recurse, n);
	
        if(n==1){
        printf("\n/*\n");
        printf("The type of the if condition is:\n");
        prettytypepp(i->val.ifelseelseES.ifCond->val.condE);
        printf("\n*/\n");
        }

	break;

	case ifelseifS:
	printf("if ");
	prettysimplestatement(i->val.ifelseelseE.Simple, 0);
	printf(" ; ");
	prettycondition(i->val.ifelseelseE.ifCond, n);
	prettyblock(i->val.ifelseelseE.stateList1, n);
	printf("else ");
	prettyif(i->val.ifelseelseE.recurse, n);

        prettysimplestatementtype(i->val.ifelseelseE.Simple,n);	
        if(n==1){
        printf("\n/*\n");
        printf("The type of the if condition is:\n");
        prettytypepp(i->val.ifelseelseE.ifCond->val.condE);
        printf("\n*/\n");
        }

	break;
}
}

void prettyreturn(returning *r, int i){
switch(r->kind){
	case returnK:
	printf("return");
	break;

	case returnExpK:
	printf("return ");
	prettyexp(r->val.returnExpE.expression);

	if(i==1){
		printf("\n/*\n");
		printf("The type in this return statement is:\n");
		prettytypepp(r->val.returnExpE.expression);
		printf("\n*/\n");
	}
	break;
}
}

void prettyprint(print *p, int i){
switch(p->kind){
	case printK:
	printf("print(");
	prettyexpList(p->val.printE.expressionList);
	printf(")");
	if(i==1){
	printf("\n/*\n");
	printf("The type of the expression(s) in this print statement is/are:\n");
	prettytypelistpp(p->val.printE.expressionList);
	printf("\n*/\n");
	}
	break;

	case printlnK:
	printf("println(");
	prettyexpList(p->val.printlnE.expressionList);
	printf(")");
	
        if(i==1){
        printf("\n/*\n");
        printf("The type of the expression(s) in this println statement is/are:\n");
        prettytypelistpp(p->val.printlnE.expressionList);
        printf("\n*/\n");
        }

	break;

	case printemptyK:
	printf("print()");
	break;

	case printlnemptyK:
	printf("println()");
	break;
}
}

void prettyincdec(incDecStmt *id, int i){
switch(id->kind){
	case incK:
	prettyexp(id->val.up);
	printf("++");
	
        if(i==1){
                        printf("\n/*\n");
                        printf("The type of this increment statement  is:\n");
                        prettytypepp(id->val.up);
                        printf("\n*/\n");
                } 

	break;

	case ddecK:
	prettyexp(id->val.down);
	printf("--");
	
        if(i==1){
                        printf("\n/*\n");
			printf("The type of this decrement statement  is:\n");
                        prettytypepp(id->val.down);
                        printf("\n*/\n");
                } 
	break;
}
}

void prettyassignment(assignment *a, int i){
switch(a->kind){
	//have a special function that prints out the types
	//customize message by doing it in situ
	case idListAssK:
	{
		prettyexpList(a->val.idListAssE.idList);
		printf(" = ");
		prettyexpList(a->val.idListAssE.expressionList);
		if(i==1){
			printf("\n/*\n");
			printf("The types for the left-hand side of the above assignment are:\n");
			prettytypelistpp(a->val.idListAssE.idList);
			printf("The types for the right-hand side of the abo     ve assignment are:\n");
			prettytypelistpp(a->val.idListAssE.idList);
			printf("\n*/\n");
		}
	}
	break;

	case selfOpAssK:
	prettyexp(a->val.opSelfAssE.identifier);
	prettyselfop(a->val.opSelfAssE.selfOperator);
	prettyexp(a->val.opSelfAssE.expression);
	if(i==1){
        		printf("\n/*\n");
                        printf("The type for the left-hand side of the above assignment are:\n");
                        prettytypepp(a->val.opSelfAssE.identifier);
                        printf("The type for the right-hand side of the abo     ve assignment are:\n");
                        prettytypepp(a->val.opSelfAssE.expression);
                	printf("\n*/\n");
		}  
	break;
}
}

void prettytypepptype(TYPETREE *t);

void prettytypestruct(TYPETREELIST *t){
	//switch(t->kind){

	//case emptytree:
	//break;

	//case typetreetree:
	prettytypepptype(t->val.typetreelist.tytree);
	prettytypestruct(t->val.typetreelist.tytreelist);
	//break;
}

void prettytypepptype(TYPETREE *t){
	if((t->type < 9) || (t->idType != NULL)){
        if(t->idType == NULL){ 
	//printf("%d",t->type);
	switch(t->type){

                case 0:
                printf("integer");
                break;
                case 1:
                printf("float");
                break;
                case 2:
                printf("boolean");
                break;
                case 3:
                printf("rune");
                break;
                case 4:
                printf("string");
                break;
                case 5:
                printf("slice of "); //what do I do here?
                //prettytypeppf(e->val.addOpE->val.mulOpE->val.factorE->val.arrayE);                
                prettytypepptype(t->val.arrayType);
                break;
                case 6:
                printf("array of "); //what do I do here
                prettytypepptype(t->val.arrayType);
                //prettytypeppf(e->val.addOpE->val.mulOpE->val.factorE->val.arrayE);
                break;
                case 7:
                printf("struct of ");
                //prettytypestruct(t->val.structType);
                //prettytypeppf(e->val.addOpE->val.mulOpE->val.factorE->val.structE);
                break;
		case 8:
		printf("no type");
		break;
                }
        }
        else{
                printf("%s",t->idType);
        }
	}

}

void prettytypepp(exp *e){
	if((e->type.idType!=NULL) || (e->type.type <9)){
	if(e->type.idType==NULL){
	switch(e->type.type){

		case 0:
		printf("integer");
		break;
                case 1:
		printf("float");
                break;
                case 2:
		printf("boolean");
                break;
                case 3:
		printf("rune");
                break;
                case 4:
		printf("string");
                break;
                case 5:
		printf("slice of "); //what do I do here?
		//prettytypeppf(e->val.addOpE->val.mulOpE->val.factorE->val.arrayE);                
		prettytypepptype(e->type.val.arrayType);
		break;
                case 6:
		printf("array of "); //what do I do here
                prettytypepptype(e->type.val.arrayType);
                //prettytypeppf(e->val.addOpE->val.mulOpE->val.factorE->val.arrayE);
		break;
                case 7:
		printf("struct of ");
                prettytypestruct(e->type.val.structType);
		//prettytypeppf(e->val.addOpE->val.mulOpE->val.factorE->val.structE);
                break;
		case 8:
		break;
		}
	}
	else{
		printf("%s",e->type.idType);
	}
	}
	//printf("%d",e->type);
}

void prettytypelistpp(expList *e){
	switch(e->kind){
		case ExpK:
		prettytypepp(e->val.expE);
		break;

		case expListK:
		prettytypepp(e->val.expListE.expression);
		printf(", ");
		prettytypelistpp(e->val.expListE.expressionList);
		break;
}
}

void prettysimplestatementtype(simpleStatement *s, int i){
if(i==1){
	switch(s->kind){
		case emptyStmtK:
		break;

		case assignK:
			switch(s->val.assignE->kind){
                        case idListAssK:
			printf("\n/*\n");
                        printf("The types for the left-hand side of the loop assignment are:\n");
                        prettytypelistpp(s->val.assignE->val.idListAssE.idList);
                        printf("The types for the right-hand side of the loop assignment are:\n");
                        prettytypelistpp(s->val.assignE->val.idListAssE.idList);
                        printf("\n*/\n");
			break;

			case selfOpAssK:
			printf("\n/*\n");
                        printf("The type for the left-hand side of the loop assignment are:\n");
                        prettytypepp(s->val.assignE->val.opSelfAssE.identifier);
                        printf("The type for the right-hand side of the loop assignment are:\n");
                        prettytypepp(s->val.assignE->val.opSelfAssE.expression);
                        printf("\n*/\n");
			break;
}
		break;

		case incDecK:
			switch(s->val.incDecE->kind){
        		case incK:
                        printf("\n/*\n");
                        printf("The type of this loop increment statement  is:\n");
                        prettytypepp(s->val.incDecE->val.up);
                        printf("\n*/\n");
                	break;

        		case ddecK:
                        printf("\n/*\n");
                        printf("The type of this loop statement  is:\n");
                        prettytypepp(s->val.incDecE->val.down);
                        printf("\n*/\n");
        		break;

}


		break;

		case sstmtExpK:

        	printf("\n/*\n");
        	printf("This is the type of the expression in the above statement expression:\n");
        	prettytypepp(s->val.stmtexp->val.expStmt);
        	printf("\n*/\n");

		break;

		case shortK:

        	printf("\n/*\n");
        	printf("The types on the right-hand side of this short variable declaration are:\n");
        	prettytypelistpp(s->val.shortE.right);
        	printf("\n*/\n");

		break;


}
}
}

void prettysimplestatement(simpleStatement *s, int i){
switch(s->kind){
	case emptyStmtK:
	//printf(";");
	break;

	case assignK:
	prettyassignment(s->val.assignE, i);
	break;

	case incDecK:
	prettyincdec(s->val.incDecE, i);
	break;

	case sstmtExpK:
	prettystmtexp(s->val.stmtexp, i);
	break;

	//deal with this for pptype later
	case shortK: //need to implement a constructor for shortK
        {prettyexpList(s->val.shortE.left);
	printf(":= ");
        prettyexpList(s->val.shortE.right);
        if(i==1){

	printf("\n/*\n");
	printf("The types on the right-hand side of this short variable declaration are:\n");
	prettytypelistpp(s->val.shortE.right);
	printf("\n*/\n");

	}
	}
	break;
}
}

void prettystatement(statement *s, int i){
printf("\t");
switch(s->kind){
	case ssimpleK:
	prettysimplestatement(s->val.simple, i);
	printf("\n");
	break;

	case sprintK:
	prettyprint(s->val.print, i);
        printf("\n");
	break;

	case sreturnK:
	prettyreturn(s->val.returned, i);
        printf("\n");	
	break;

	case sifK:
	prettyif(s->val.iffy, i);
	break;
	
	case sforK:
	prettyforloop(s->val.loop, i);
	break;

	case sswitchK:
	prettyswitch(s->val.switchy, i);
	break;

	//1 means it's okay, 0 means it's not
	case sbreakK:
	printf("break\n");
	break;

	case scontinueK:
        printf("continue\n");
	break;

        case stype:
        prettytypedec(s->val.tvar);
        printf("\n");
	break;

        case svar:
        //PROBLEM IS RIGHT HERE
	prettyvardec(s->val.var, i);
        printf("\n");
	break;

	case sblock:
	printf("{\n");
	prettystatementlist(s->val.block, i);
	printf("\n}\n");
	break;

}
}

void prettystatementlist(statementList *sl, int i){
switch(sl->kind){
	case emptyStateListK:
	break;//do nothing

	case stateListK:
	prettystatement(sl->val.stateListE.state, i);
	prettystatementlist(sl->val.stateListE.stateList, i);
	break;
}
}

void prettyblock(block *b, int i){
switch(b->kind){
	case only:
	printf("{\n");
	prettystatementlist(b->val.left, i);
	printf("\n}");
	break;
}
}

void prettyparam(param *p){
switch(p->kind){
	case onlyparam:
	prettyidentifierlist(p->val.onlyE.names);
	prettytype(p->val.onlyE.type);
	break;

	case idparam:
	prettyidentifierlist(p->val.idE.names);
	printf("%s",p->val.idE.type);
	break;
}
}

void prettyparamlist(paramList *pl){
switch(pl->kind){
	case emptyParamListK:
	prettyparam(pl->val.p);
	break;//do nothing

	case fullParamListK:
	prettyparam(pl->val.fullE.p);
	printf(", ");
	prettyparamlist(pl->val.fullE.pl);
	break;
}
}

void prettyfuncdec(funcDec *f, int i){
switch(f->kind){
	case typeful:
	printf("func ");
	printf("%s",f->val.typefulE.identifier);
	printf("(");
	prettyparamlist(f->val.typefulE.pList);
	printf(")");
	prettytype(f->val.typefulE.type);
	prettyblock(f->val.typefulE.Blocky, i);
	printf("\n");
	break;

	case typeless:
	printf("func ");
	printf("%s",f->val.typelessE.identifier);
	printf("(");
	prettyparamlist(f->val.typelessE.pList);
	printf(")");
	prettyblock(f->val.typelessE.Blocky, i);
	printf("\n");
	break;

	case nonoK:
	printf("func ");
	printf("%s",f->val.noparamnotype.identifier);
	printf("()");
	prettyblock(f->val.noparamnotype.Blocky, i);
	printf("\n");
	break;

	case noK:
	printf("func ");
	printf("%s",f->val.notype.identifier);
	printf("()");
	prettytype(f->val.notype.type);
	prettyblock(f->val.notype.Blocky, i);
	printf("\n");
	break;

	case typeIDK:
	printf("func ");
	printf("%s",f->val.typeIDE.identifier);
	printf("(");
	prettyparamlist(f->val.typeIDE.pList);
	printf(")");
	printf("%s ",f->val.typeIDE.type);
	prettyblock(f->val.typeIDE.Blocky, i);
	printf("\n");
	break;

	case noIDK:
	printf("func ");
	printf("%s",f->val.noIDE.identifier);
	printf("() %s",f->val.noIDE.name);
	prettyblock(f->val.notype.Blocky, i);
	printf("\n");
	break;

}
}

void prettystructlist(structList *s);

void prettystructtype(structType *s){
switch(s->kind){
	case fullStructTypeK:
	printf("struct {\n");
	prettystructlist(s->val.left);
	printf("\n}");
	break;

	case emptyStructTypeK:
	printf("struct {\n}");
	break;	
}
}

void prettystructlist(structList *s){
switch(s->kind){
	case singlestructK:
	prettyparam(s->val.singlestructE);
	break;
	
	case manystructK:
	prettyparam(s->val.manystructE.left);
	printf("\n");
	prettystructlist(s->val.manystructE.right);
	break;
}
}

void prettytypeline(typeLine *t){
switch(t->kind){
	case singletypeK:
	printf("%s ",t->val.singleE.name);
	prettytype(t->val.singleE.right);
	printf("\n");
	break;

	case structK:
	//printf("%s struct {\n",t->val.structE.structname);
	printf("%s ",t->val.structE.structname);
	prettystructlist(t->val.structE.right);
	printf("\n}\n");
	break;

	case singleIDK:
	printf("%s %s",t->val.singleIDE.name,t->val.singleIDE.right);
	break;

	case structIDK:
	printf("%s struct {\n",t->val.structIDE.structname);
	prettyparamlist(t->val.structIDE.right);
	printf("}\n");
	break;

	case emptyType:
	printf("%s struct {\n}",t->val.name);
	break;

	case structTypeK:
	printf("%s",t->val.structTypeE.left);
	prettystructtype(t->val.structTypeE.right);
	printf("\n");
	break;

}
}

void prettytypelinelist(typeLineList *tl){
switch(tl->kind){
	case tLineK:
	prettytypeline(tl->val.tLine);
	break;

	case tLineListK:
	prettytypeline(tl->val.tLineListE.tLine);
	printf("\n");
	prettytypelinelist(tl->val.tLineListE.tLineList);
	break;
}
}

void prettytypedec(typeDec *t){
switch(t->kind){
	case singleDecK:
	printf("type ");
	prettytypeline(t->val.singleDecE);
	break;

	case manyDecK:
	printf("type (\n");
	prettytypelinelist(t->val.manyDecE);
	printf("\n)\n");
	break;
}
}

void prettyidentifierlist(identifierList *i){
switch(i->kind){
	case singleidK:
	printf("%s ",i->val.singleE);
	break;

	case multipleK:
	printf("%s, ",i->val.idListE.identifier);
	prettyidentifierlist(i->val.idListE.idList);
	break;
}
}

void prettyvar(var *v, int i){
switch(v->kind){
	case typeK:
	prettyidentifierlist(v->val.typeE.names);
	prettytype(v->val.typeE.idType);
	break;

	case veqK:
	{
        prettyidentifierlist(v->val.eqE.names);
        printf("=");
        prettyexpList(v->val.eqE.eqExp);
        
	if(i==1){
	printf("\n/*\n The type(s) of the right-hand side of the above variable declaration is/are:\n");
	prettytypelistpp(v->val.eqE.eqExp);
	printf("\n*/\n");
	}

	}
	break;

	case vtypeEqK:
	{
        prettyidentifierlist(v->val.typeEqE.names);
        prettytype(v->val.typeEqE.idType);
        printf("=");
        prettyexpList(v->val.typeEqE.eqExp);
        
	if(i==1){
        printf("\n/*\n The type(s) of the right-hand side of the above variable declaration is/are:\n");
        prettytypelistpp(v->val.typeEqE.eqExp);
        printf("\n*/\n");
        }


	}

	break;

	case vidK:
	prettyidentifierlist(v->val.typeE.names);
	printf("%s",v->val.vidE.idType);
	break;

	case vidEqK:
	{
	prettyidentifierlist(v->val.vidEqE.names);
	printf("%s=",v->val.vidEqE.idType);
	prettyexpList(v->val.vidEqE.eqExp);
	
        if(i==1){
        printf("\n/*\n The type(s) of the right-hand side of the above variable declaration is/are:\n");
        prettytypelistpp(v->val.vidEqE.eqExp);
        printf("\n*/\n");
        }

	}
	break;
}
}

void prettyvarlist(varList *v, int i){
switch(v->kind){
	case varK:
	printf(" ");
	prettyvar(v->val.variableE.variable, i);
	break;

	case varListK:
	prettyvar(v->val.varListE.variable, i);
	printf("\n");
	prettyvarlist(v->val.varListE.variableList, i);
	break;
}
}

void prettyvardec(varDec *v, int i){
switch(v->kind){
	case singleK:
	printf("var ");
	prettyvar(v->val.varE, i);
	printf(";\n");
	break;

	case distributedK:
	printf("var (\n");
	prettyvarlist(v->val.varListE, i);
	printf("\n)\n");
	break;
}
}

void prettydec(dec *d, int i){
switch(d->kind){
	case varDecK:
	prettyvardec(d->val.varDecE,i);
	break;

	case typeDecK:
	prettytypedec(d->val.typeDecE);
	break;

	case funcDecK:
	prettyfuncdec(d->val.funcDecE, i);
	break;
}
}

void prettydeclist(decList *dl, int i){
switch(dl->kind){
	case emptyDecK:
	break;//do nothing
	
	case fullDecK:
	prettydec(dl->val.fullDecE.left, i);
	printf("\n");
	prettydeclist(dl->val.fullDecE.right, i);
	break;
}
}

void prettypackage(package *p){
switch(p->kind){
	case packageK:
	printf("package %s\n",p->val.packageE);
	break;
}
}

void prettyprogram(program *p, int i){
switch(p->kind){
	case progK:
	prettypackage(p->val.progE.left);
	prettydeclist(p->val.progE.right, i);
	break;
}
}
