//this file taken directly from the old JOOS project

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"

int errors=0;

void reportError(char *s, int lineno){
errors++;
fclose(stdout); //this line is necessary because of how main prints to files
//freopen("result","w",stdout);
fprintf(stderr,"Invalid: %s at line %i\n",s,lineno);
//fclose(stdout);
exit(0);
}

void reportStrError(char *s, char *name, int lineno){
errors++;
fclose(stdout); //this line is necessary because of how main prints to files
//freopen("result","w",stdout);
fprintf(stderr,"Invalid: %s %s at line %i\n",s,name,lineno);
exit(0);
}
