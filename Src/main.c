#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "GoSymbol.h"
#include "GoType.h"
#include "GoTree.h"
#include "GoPretty.h"
#include "GoWeed.h"
#include "GoCode.h"

int lineno;
void yyparse();
program *theprogram;
SymbolTable *symTable;
int main(int argc, char **argv){
        yyparse();
        weedProgram(theprogram);
        bool pptype=(argc>2&&!strcmp(argv[2],"-pptype")) || (argc>3&&!strcmp(argv[3],"-pptype"));
        bool dumpsymtab=(argc>2&&!strcmp(argv[2],"-dumpsymtab")) || (argc>3&&!strcmp(argv[3],"-dumpsymtab"));
        
	if(pptype&&dumpsymtab){
//      printf("Flag found!");
		//printf("argv[4] is %s\n",argv[4]);
		freopen(argv[4],"w",stdout);
	        mainTypeProgram(theprogram,1);
		fclose(stdout);
	        freopen(argv[1],"w",stdout);
	        prettyprogram(theprogram,1); //print out types
        	fclose(stdout);

        	freopen(argv[5],"w",stdout);
        	codeprogram(theprogram);
        	fclose(stdout);
}
        else if(pptype){
        	mainTypeProgram(theprogram,0);
                freopen(argv[1],"w",stdout);
		prettyprogram(theprogram,1); //don't print out types
		fclose(stdout);
	
	        freopen(argv[3],"w",stdout);
        	codeprogram(theprogram);
        	fclose(stdout);
}
        else if(dumpsymtab){
                //printf("argv[4] is %s\n",argv[4]);
		freopen(argv[3],"w",stdout);
	        mainTypeProgram(theprogram,1);
		fclose(stdout);
                freopen(argv[1],"w",stdout);
        	prettyprogram(theprogram,0);
		fclose(stdout);

		freopen(argv[4],"w",stdout);
        	codeprogram(theprogram);
        	fclose(stdout);


        }
        else{
		mainTypeProgram(theprogram,0);
                freopen(argv[1],"w",stdout);
		prettyprogram(theprogram,0);
		fclose(stdout);

	        freopen(argv[2],"w",stdout);
        	codeprogram(theprogram);
        	fclose(stdout);

        }
        fprintf(stderr,"VALID\n");
}
