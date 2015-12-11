//Version 1.5
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "GoWeed.h"
#include "error.h"

void weedProgram(program *p){
	if(!strcmp(p->val.progE.left->val.packageE,"_")){
		//printf("Error - '_' may only appear on LH side of assignments");
		//exit(0);
		reportError("'_' may only appear on LH side of assignments",p->val.progE.left->lineno);
	}
	weeddeclist(p->val.progE.right);
}

void weeddeclist(decList *dl){
	switch(dl->kind){
		case emptyDecK:
		break;//

		case fullDecK:
		weeddec(dl->val.fullDecE.left);
		weeddeclist(dl->val.fullDecE.right); 
}
}

void weeddec(dec *d){
switch(d->kind){
        case varDecK:
        weedvardec(d->val.varDecE);
        break;

        case typeDecK:
//        weedtypedec(d->val.typeDecE);
        break;

        case funcDecK:
        weedfuncdec(d->val.funcDecE);
        break;
}
}

void weedvardec(varDec *v){
switch(v->kind){
        case singleK:
        weedvar(v->val.varE);
        break;

	case distributedK:
        weedvarlist(v->val.varListE);
        break;
}
}

void weedvarlist(varList *v){
switch(v->kind){
        case varK:
        weedvar(v->val.variableE.variable);
        break;

        case varListK:
        weedvar(v->val.varListE.variable);
        weedvarlist(v->val.varListE.variableList);
        break;
}
}

void weedvar(var *v){
switch(v->kind){
        case typeK:
        //prettytype(v->val.typeE.idType);
        break;

        case veqK:
        {
	//weedRHlist(v->val.eqE.eqExp);
        int x=weedidentifierlist(v->val.eqE.names);
        int y=weedexpList(v->val.eqE.eqExp,0);
        if(x!=y){
                //printf("Error - lists of different lengths in your variable declarations\n");
                //exit(0);
		reportError("lists of different lengths in your variable declarations",v->lineno);
        }
        }
        break;

        case vtypeEqK:
        {
	//weedRHlist(v->val.typeEqE.eqExp);
        int x=weedidentifierlist(v->val.typeEqE.names);
        //prettytype(v->val.typeEqE.idType);
        int y=weedexpList(v->val.typeEqE.eqExp,0);
        if(x!=y){
                //printf("Error - lists of different lengths in your variable declarations\n");
                //exit(0);
		reportError("lists of different lengths in your variable declarations",v->lineno);
        }
        }

        break;

        case vidK:
        break;

        case vidEqK:
        {
	//weedRHlist(v->val.vidEqE.eqExp);
        int x=weedidentifierlist(v->val.vidEqE.names);
        int y=weedexpList(v->val.vidEqE.eqExp,0);
        if(x!=y){
                //printf("Error - lists of different lengths in your variable declarations\n");
                //exit(0);
                reportError("lists of different lengths in your variable declarations",v->lineno);
        }
        }
        break;
}
}

void weedLH(exp *e){
	if(e->kind!=addOpK){
		//printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
		//exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",e->lineno);
	}
	if(e->val.addOpE->kind!=mulOpK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",e->lineno);
	}
	if(e->val.addOpE->val.mulOpE->kind!=factorK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",e->lineno);
	}
	factor *f=e->val.addOpE->val.mulOpE->val.factorE;
	if(f->kind!=idK&&f->kind!=arrayK&&f->kind!=estructK&&f->kind!=utimesK&&f->kind!=uampK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",e->lineno);
	}
}

void weedLHlist(expList *e){
	switch(e->kind){
		case ExpK:
			weedLH(e->val.expE);
		break;
		
		case expListK:
			weedLH(e->val.expListE.expression);
			weedLHlist(e->val.expListE.expressionList);
		break;
}
}

void weedRH(exp *e){
	if(e->kind==addOpK&&e->val.addOpE->kind==mulOpK&&e->val.addOpE->val.mulOpE->kind==factorK&&e->val.addOpE->val.mulOpE->val.factorE->kind==idK&&!strcmp(e->val.addOpE->val.mulOpE->val.factorE->val.idE,"_")){
		//printf("Error - '_' may only appear on left-hand side");
		//exit(0);
		reportError("'_' may only appear on left-hand side",e->lineno);
	}
}

void weedRHlist(expList *e){
switch(e->kind){
	case ExpK:
	weedRH(e->val.expE);
	break;

	case expListK:
	weedRH(e->val.expListE.expression);
	weedRHlist(e->val.expListE.expressionList);
	break;
}
}

void weedassignment(assignment *a){
switch(a->kind){
	case idListAssK:
	{
	weedLHlist(a->val.idListAssE.idList);
	//weedRHlist(a->val.idListAssE.expressionList);
	int x=weedexpList(a->val.idListAssE.idList,1);
	int y=weedexpList(a->val.idListAssE.expressionList,0);
	if(x!=y){
		//printf("Error - lists of different lengths in your variable declarations\n");
		//exit(0);
		reportError("Error - lists of different lengths in your variable declarations",a->lineno);
	}
	}
	break;

	case selfOpAssK:
	weedexp(a->val.opSelfAssE.identifier,0);
	break;
}
}
int weedidentifierlist(identifierList *i){
switch(i->kind){
        case singleidK:
        return 1;
        break;

        case multipleK:
        return 1+weedidentifierlist(i->val.idListE.idList);
        break;
}
}

void weedfuncdec(funcDec *f){
switch(f->kind){
        case typeful:
        weedblock(f->val.typefulE.Blocky,0);
        break;

        case typeless:
        weedblock(f->val.typelessE.Blocky,0);
        break;

        case nonoK:
        weedblock(f->val.noparamnotype.Blocky,0);
        break;

        case noK:
        weedblock(f->val.notype.Blocky,0);
        break;

        case typeIDK:
        weedblock(f->val.typeIDE.Blocky,0);
        break;

        case noIDK:
        weedblock(f->val.notype.Blocky,0);
        break;

}
}

void weedblock(block *b,int i){

switch(b->kind){
        case only:
        weedstatementlist(b->val.left,i);
        break;
}
}

void weedstatementlist(statementList *sl,int i){
switch(sl->kind){
        case emptyStateListK:
        break;//do nothing

        case stateListK:
        weedstatement(sl->val.stateListE.state,i);
        weedstatementlist(sl->val.stateListE.stateList,i);
        break;
}
}

void weedID(exp *e){
        if(e->kind!=addOpK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",    e->lineno);

        }
        if(e->val.addOpE->kind!=mulOpK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
        	reportError("left-hand side of assignments and like expressions must be an l-value",    e->lineno);
	}
        if(e->val.addOpE->val.mulOpE->kind!=factorK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",    e->lineno);

        }
        factor *f=e->val.addOpE->val.mulOpE->val.factorE;
        if(f->kind!=idK){
                //printf("Error - left-hand side of assignments and like expressions must be an l-value\n");
                //exit(0);
		reportError("left-hand side of assignments and like expressions must be an l-value",    e->lineno);

        }
}

void weedIDlist(expList *e){
        switch(e->kind){
                case ExpK:
                        weedID(e->val.expE);
                break;

                case expListK:
                        weedID(e->val.expListE.expression);
                        weedIDlist(e->val.expListE.expressionList);
                break;
}
}

void weedstatement(statement *s,int i){

switch(s->kind){
        case ssimpleK:
        weedsimplestatement(s->val.simple);
        break;

        case sprintK:
        break;

        case sreturnK:
        break;

        case sifK:
        weedif(s->val.iffy,i);
        break;

        case sforK:
        weedforloop(s->val.loop);
        break;

        case sswitchK:
        weedswitch(s->val.switchy);
        break;
        //1 means it's okay, 0 means it's not
        case sbreakK:
        if(i==0){
                //printf("Error - break appearing outside appropriate context\n");
                //exit(0);
		reportError("break appearing outside appropriate context",s->lineno);

        }
        break;

        case scontinueK:
        if(i==0){
                //printf("Error - break appearing outside appropriate context\n");
                //exit(0);
		reportError("continue appearing outside appropriate context",s->lineno);
        }
        break;

        case stype:
        break; //we don't weed type dec

        case svar:
        weedvardec(s->val.var);
        break;

	case sblock:
	weedstatementlist(s->val.block,i);
	break;

}
}

void weedIsIDexp(exp *e){
        if(e->kind!=addOpK){
                //printf("Error - left-hand side of short variable declarations must be identifiers\n");
                //exit(0);
		reportError("Error - left-hand side of short variable declarations must be identifiers",e->lineno);
        }
        if(e->val.addOpE->kind!=mulOpK){
		//printf("Error - left-hand side of short variable declarations must be identifiers\n");
		//exit(0);
		reportError("Error - left-hand side of short variable declarations must be identifie    rs",e->lineno);
        }
        if(e->val.addOpE->val.mulOpE->kind!=factorK){
		//printf("Error - left-hand side of short variable declarations must be identifiers\n");
		//exit(0);
		reportError("Error - left-hand side of short variable declarations must be identifie    rs",e->lineno);
        }
        factor *f=e->val.addOpE->val.mulOpE->val.factorE;
        if(f->kind!=idK){
		//printf("Error - left-hand side of short variable declarations must be identifiers\n");
		//exit(0);
		reportError("Error - left-hand side of short variable declarations must be identifie    rs",e->lineno);
        }
}

void weedIsID(expList *e){
switch(e->kind){
	case ExpK:
	weedIsIDexp(e->val.expE);
	break;

	case expListK:
	weedIsIDexp(e->val.expListE.expression);
	weedIsID(e->val.expListE.expressionList);
	break;
}
}

void weedincdec(incDecStmt *i){
switch(i->kind){
	case incK:
	weedexp(i->val.up,0);
	break;	

	case ddecK:
	weedexp(i->val.down,0);
	break;
}
}

void weedsimplestatement(simpleStatement *s){
switch(s->kind){
        case emptyStmtK:
        break;

        case assignK:
        weedassignment(s->val.assignE);
        break;

        case incDecK:
	weedincdec(s->val.incDecE);
	break;

        case sstmtExpK:
        weedexp(s->val.stmtexp->val.expStmt,0);
	break;

        case shortK: //need to implement a constructor for shortK
        {
	
	int x=weedexpList(s->val.shortE.left,1);
        weedIsID(s->val.shortE.left);
	//weedRHlist(s->val.shortE.right);
	int y=weedexpList(s->val.shortE.right,0);
        if(x!=y){
                //printf("Error - the two sides of your short declaration aren't of equal length\n");
                //exit(0);
		reportError("the two sides of your short declaration aren't of equal length",s->lineno);
        }
        }
        break;
}
}

void weedif(ifStmt *i, int n){
switch(i->kind){
        case ifK:
        weedblock(i->val.ifES.stateList,n);
        break;

        case ifS:
        weedsimplestatement(i->val.ifE.Simple);
        weedblock(i->val.ifE.stateList,n);
        break;

        case ifelseK:
        weedblock(i->val.ifElseES.stateList1,n);
        weedblock(i->val.ifElseES.stateList2,n);
        break;

        case ifelseS:
        weedsimplestatement(i->val.ifelseE.Simple);
        weedblock(i->val.ifelseE.stateList1,n);
        weedblock(i->val.ifelseE.stateList2,n);
        break;

        case ifelseifK:
        weedblock(i->val.ifelseelseES.stateList1,n);
        weedif(i->val.ifelseelseES.recurse,n);
        break;

        case ifelseifS:
        weedsimplestatement(i->val.ifelseelseE.Simple);
        weedblock(i->val.ifelseelseE.stateList1,n);
        weedif(i->val.ifelseelseE.recurse,n);
        break;
}
}

void weedforloop(forLoop *f){
switch(f->kind){
        case stateListLoopK:
        weedblock(f->val.stateListLoopE.stateList,1);
        break;

        case condLoopK:
        weedblock(f->val.condLoopE.stateList,1);
        break;

        case idCondLoopK:
        weedsimplestatement(f->val.idCondLoopE.simpleState1);
        if(f->val.idCondLoopE.simpleState2->kind==shortK){
                //printf("Error - short variable declaration in post statement of for loop\n");
                //exit(0);
		reportError("short variable declaration in post statement of for loop",f->lineno);
        }
        else{
        weedsimplestatement(f->val.idCondLoopE.simpleState2);
        }
        weedblock(f->val.idCondLoopE.stateList,1);
        break;

	case nocondK:
	weedsimplestatement(f->val.nocondE.simpleState1);
	if(f->val.nocondE.simpleState2->kind==shortK){
		//printf("Error - short variable declaration in post statement of for loop\n");
		//exit(0);
		reportError("short variable declaration in post statement of for loop",f->lineno);
	}
	else{
	weedsimplestatement(f->val.nocondE.simpleState2);
	}
	weedblock(f->val.nocondE.stateList,1);
	break;
}
}

void weedswitch(switchStmt *s){
int x=0;
switch(s->kind){
        case leftright:
        weedsimplestatement(s->val.leftrightE.simple);
        x+=weedcaselist(s->val.leftrightE.cases);
        break;

        case right:
        x=+weedcaselist(s->val.rightE.cases);
        break;

        case left:
        weedsimplestatement(s->val.leftE.simple);
        x=+weedcaselist(s->val.leftE.cases);
        break;

        case none:
        x=+weedcaselist(s->val.noneE.cases);
        break;
}
if(x>1){
printf("Error - there is a switch statement with more than one default\n");
exit(0);
}
}

int weedcaselist(caseList *cl){
int x=0;
switch(cl->kind){
        case emptyCase:
        x=0;
        break;//do nothing

        case fullCase:
        x+=weedcase(cl->val.caseX.casey);
        x+=weedcaselist(cl->val.caseX.right);
        break;
}
return x;
}

int weedcase(caseFall *c){
switch(c->kind){
        case caseX:
        weedstatementlist(c->val.caseE.right,1);
        return 0;
        break;

        case defaultX:
        weedstatementlist(c->val.defaultE,0);//I changed 1 to 0 here in order to disallow break/continue in the context of a default case
        return 1;
        break;
}
}

void weedfactor(factor *f, int i){
	if(f->kind==idK && !strcmp(f->val.idE,"_") && i==0){
		//printf("Error - '_' only allowed on left-hand side of assignments and like statements");
		//exit(0);
		reportError("'_' only allowed on left-hand side of assignments and like statemets",f->lineno);
	}
switch(f->kind){

	case uplusK:
	case uminusK:
	case notK:
	case ucaratK:
	case uampK:
	case idK:
	case decK:
	case octK:
	case floatK:
	case hexK:
	case runeK:
	case interpretedK:
	case rawK:
	case trueK:
	case falseK:
	//case utimesK:
	break;

	case utimesK:
	if(i==0){
		//printf("Apparently we don't allow *factor on RH side of assignments and the like");
		//exit(0);
		reportError("Apparently we don't allow *factor on RH side of assignments and the like",f->lineno);
	}

	case castK:
	weedexp(f->val.castE.right,i);
	break;

	case funccallK:
	weedfactor(f->val.funccallE.name,i);
	weedexpList(f->val.funccallE.right,i);
	break;

	case funccallemptyK:
	weedfactor(f->val.funccallemptyE,i);
	break;

	case appendK:
	if(!strcmp(f->val.appendE.name,"_")){
		//printf("Error - '_' may appear only on LH side of assignments");
		//exit(0);
		reportError("'_' may appear only on LH side of assignments",f->lineno);
	}
	weedexp(f->val.appendE.right,i);
	break;

	case parenK:
	weedexp(f->val.parenE,i);
	break;

	case arrayK:
	weedfactor(f->val.arrayE.left,i);
	weedexp(f->val.arrayE.right,i);
	break;

	case estructK:
	weedfactor(f->val.structE.left,i);
	if(!strcmp(f->val.structE.right,"_")){
		//printf("Error - '_' may appear only on LH side of assignments");
		//exit(0);
		reportError("'_' may appear only on LH side of assignments",f->lineno);
	}
	break;

}
}

void weedmulop(mulOp *m,int i){
switch(m->kind){
	case timesK:
	weedmulop(m->val.timesE.left,i);
	weedmulop(m->val.timesE.right,i);
	break;

        case divK:
        weedmulop(m->val.divE.left,i);
        weedmulop(m->val.divE.right,i);
        break;

        case modK:
        weedmulop(m->val.modE.left,i);
        weedmulop(m->val.modE.right,i);
        break;

        case coutK:
        weedmulop(m->val.coutE.left,i);
        weedmulop(m->val.coutE.right,i);
        break;

        case cinK:
        weedmulop(m->val.cinE.left,i);
        weedmulop(m->val.cinE.right,i);
        break;

        case ampK:
        weedmulop(m->val.ampE.left,i);
        weedmulop(m->val.ampE.right,i);
        break;

        case ampcaratK:
        weedmulop(m->val.ampcaratE.left,i);
        weedmulop(m->val.ampcaratE.right,i);
        break;

	case factorK:
	weedfactor(m->val.factorE,i);
}
}

void weedaddop(addOp *a, int i){
switch(a->kind){

	case plusK:
	weedaddop(a->val.plusE.left,i);
	weedaddop(a->val.plusE.right,i);
	break;

        case minusK:
        weedaddop(a->val.minusE.left,i);
        weedaddop(a->val.minusE.right,i);
        break;

	case pipeK:
        weedaddop(a->val.pipeE.left,i);
        weedaddop(a->val.pipeE.right,i);
        break;

        case caratK:
        weedaddop(a->val.caratE.left,i);
        weedaddop(a->val.caratE.right,i);
        break;

	case mulOpK:
	weedmulop(a->val.mulOpE,i);
	break;
}
}

void weedexp(exp *e, int i){
	if(e->kind==addOpK && e->val.addOpE->kind==mulOpK && e->val.addOpE->val.mulOpE->kind==factorK && e->val.addOpE->val.mulOpE->val.factorE->kind==idK && !strcmp(e->val.addOpE->val.mulOpE->val.factorE->val.idE,"_") && i==0) {
	//printf("Error  - '_' may only appear on left-hand side of assignments");
	//exit(0);
	reportError("'_' may only appear on left-hand side of assignments",e->lineno);
}
switch(e->kind){
	case orK:
	weedexp(e->val.orE.left,i);
	weedexp(e->val.orE.right,i);
	break;

        case andK:
        weedexp(e->val.andE.left,i);
        weedexp(e->val.andE.right,i);
        break;

	case eqK:
        weedexp(e->val.eqE.left,i);
        weedexp(e->val.eqE.right,i);
        break;

        case neqK:
        weedexp(e->val.neqE.left,i);
        weedexp(e->val.neqE.right,i);
        break;

        case GTK:
        weedexp(e->val.GTE.left,i);
        weedexp(e->val.GTE.right,i);
        break;

        case GEK:
        weedexp(e->val.GEE.left,i);
        weedexp(e->val.GEE.right,i);
        break;

        case LTK:
        weedexp(e->val.LTE.left,i);
        weedexp(e->val.LTE.right,i);
        break;

        case LEK:
        weedexp(e->val.LEE.left,i);
        weedexp(e->val.LEE.right,i);
        break;

	case addOpK:
	weedaddop(e->val.addOpE,i);
	break;
}
}

int weedexpList(expList *e, int i){
switch(e->kind){
        case ExpK:
	weedexp(e->val.expE,i);
        return 1;
        break;

        case expListK:
        return 1+weedexpList(e->val.expListE.expressionList,i);
        break;
}
}
