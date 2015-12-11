%{
//Version 2.0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
char* last; //need to write parser so we can include y.tab.h so that this will be recognized
extern int lineno;
%}

DIGIT [0-9]
HEX [0-9a-f]
%%

\/\/(.)*	
"/""*"([^*]|"*"[^/])*"*""/"

"<<"            {
last="COUT";
return COUT;
}
">>"            {
last="CIN";
return CIN;
}
"&^"            {
last="AMPCARAT";
return AMPCARAT;
}
"+="            {
last="SELFPLUS";
return SELFPLUS;
}
"-="            {
last="SELFMINUS";
return SELFMINUS;
}
"*="            {
last="SELFTIMES";
return SELFTIMES;
}
"/="            {
last="SELFDIV";
return SELFDIV;
}
"%="            {
last="SELFMOD";
return SELFMOD;
}
"&="            {
last="AMPEQUALS";
return AMPEQUALS;
}
"|="            {
last="PIPEEQUALS";
return PIPEEQUALS;
}
"^="            {
last="CARATEQUALS";
return CARATEQUALS;
}
"<<="           {
last="COUTEQUALS";
return COUTEQUALS;
}
">>="           {
last="CINEQUALS";
return CINEQUALS;
}
"&^="           {
last="WTF";
return WTF;
}
"&&"            {
last="AND";
return AND;
}
"||"            {
last="OR";
return OR;
}
"<-"            {
last="REDIRECT";
return REDIRECT;
}
"++"            {
last="INCREMENT";
return INCREMENT;
}
"--"            {
last="DECREMENT";
return DECREMENT;
}
"=="            {
last="DOESEQUALS";
return DOESEQUALS;
}
break		{
last="BREAK";
return BREAK;
}
case		{
last="CASE";
return CASE;
}
chan		{
last="CHAN";
return CHAN;
}
const		{
last="CONST";
return CONST;
}
continue	{
last="CONTINUE";
return CONTINUE;
}
default		{
last="DEFAULT";
return DEFAULT;
}
defer		{
last="DEFER";
return DEFER;
}
else		{
last="ELSE";
return ELSE;
}
fallthrough	{
last="FALLTHROUGH";
return FALLTHROUGH;
}
for		{
last="FOR";
return FOR;
}
func		{
last="FUNC";
return FUNC;
}
go		{
last="GO";
return GO;
}
goto		{
last="GOTO";
return GOTO;
}
if		{
last="IF";
return IF;
}
import		{
last="IMPORT";
return IMPORT;
}
interface	{
last="INTERFACE";
return INTERFACE;
}
map		{
last="MAP";
return MAP;
}
package		{
last="PACKAGE";
return PACKAGE;
}
range		{
last="RANGE";
return RANGE;
}
return		{
last="RETURN";
return RETURN;
}
select		{
last="SELECT";
return SELECT;
}
struct		{
last="STRUCT";
return STRUCT;
}
switch		{
last="SWITCH";
return SWITCH;
}
type		{
last="TYPE";
return TYPE;
}
var		{
last="VAR";

return VAR;
}
int		{
last="INT";
return INT;
}
print		{
last="PRINT";
return PRINT;
}
float64		{
last="FLOAT";
return FLOAT;
}
println		{
last="PRINTLN";

return PRINTLN;
}
bool		{
last="BOOL";
return BOOL;
}
append		{
last="APPEND";
return APPEND;
}
rune		{
last="RUNE";
return RUNE;
}

string		{
last="STRING";
return STRING;
}
[ \t\r]+
\n		{
lineno++;
if((last!=NULL)&&(!strcmp(last,"TRUE")||!strcmp(last,"FALSE")||!strcmp(last,"INT")||!strcmp(last,"FLOAT")||!strcmp(last,"BOOL")||!strcmp(last,"STRING")||!strcmp(last,"RUNE")||!strcmp(last,"tIDENTIFIER")||!strcmp(last,"tDEC")||!strcmp(last,"tOCT")||!strcmp(last,"tHEX")||!strcmp(last,"tRUNE")||!strcmp(last,"RAWSTRING")||!strcmp(last,"INTERPRETEDSTRING")||!strcmp(last,"tFLOAT")||!strcmp(last,"BREAK")||!strcmp(last,"CONTINUE")||!strcmp(last,"FALLTHROUGH")||!strcmp(last,"RETURN")||!strcmp(last,"INCREMENT")||!strcmp(last,"DECREMENT")||!strcmp(last,"RIGHTPAREN")||!strcmp(last,"RIGHTSQUARE")||!strcmp(last,"RIGHTBRACE"))){
last="NEWLINE";
return SEMICOLON;
}
last="NEWLINE";
}
true		{
last="TRUE";
return TRUE;
}
false		{
last="FALSE";
return FALSE;
}
"+"		{
last="PLUS";
return PLUS;
}
"-"		{
last="MINUS";
return MINUS;
}
"*"		{
last="TIMES";
return TIMES;
}
"/"		{
last="DIV";
return DIV;
}
"%"		{
last="MOD";
return MOD;
}
"&"		{
last="AMP";
return AMP;
}
"|"		{
last="PIPE";
return PIPE;
}
"^"		{
last="CARAT";
return CARAT;
}
"<"		{
last="LT";
return LT;
}
">"		{
last="GT";
return GT;
}
"="		{
last="EQUALS";
return EQUALS;
}
"!"		{
last="NOT";
return NOT;
}
"!="		{
last="NEQ";
return NEQ;
}
"<="		{
last="LE";
return LE;
}
">="		{
last="GE";
return GE;
}
":="		{
last="COMPAT";
return COMPAT;
}
"..."		{
last="ELLIPSIS";
return ELLIPSIS;
}
"("		{
last="LEFTPAREN";
return LEFTPAREN;
}
")"		{
last="RIGHTPAREN";
return RIGHTPAREN;
}
"["		{
last="LEFTSQUARE";
return LEFTSQUARE;
}
"]"		{
last="RIGHTSQUARE";
return RIGHTSQUARE;
}
"{"		{
last="LEFTBRACE";
return LEFTBRACE;
}
"}"		{
last="RIGHTBRACE";
return RIGHTBRACE;
}
","		{
last="COMMA";
return COMMA;
}
";"		{
last="SEMICOLON";

return SEMICOLON;
}
"."		{
last="PERIOD";
return PERIOD;
}
":"		{
last="FULLCOLON";
return FULLCOLON;
}
\'\\a\'		{
//last="ESCAPEA";
//return ESCAPEA;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}
\'\\b\'		{
//last="ESCAPEB";
//return ESCAPEB;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}
\'\\f\'		{
//last="ESCAPEF";
//return ESCAPEF;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}
\'\\v\'		{
//last="ESCAPEV";
//return ESCAPEV;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}

\'\\n\'		{
//last="ESCAPEN";
//return ESCAPEN;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}

\'\\t\'         {
//last="ESCAPET";
//return ESCAPET;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}

\'\\r\'         {
//last="ESCAPER";
//return ESCAPER;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}


\'\\\\'		{
//last="ESCAPESLASH";
//return ESCAPESLASH;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}
\'\\\'\'		{
//last="ESCAPEAPOSTROPHE";
//return ESCAPEAPOSTROPHE;
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}

\'\\\"\'	{
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}

0(x|X)[1-9a-fA-F]{HEX}*	{
yylval.intconst=strtol(yytext,NULL,16);
last="tHEX";
return tHEX;
}

0[1-7][0-7]*		{
yylval.intconst=strtol(yytext,NULL,8);
last="tOCT";
return tOCT;
}

0|([1-9]{DIGIT}*)	{
yylval.intconst = atoi(yytext);
last="tDEC";
return tDEC;
}

\"([^"]|\\\")*\"  		{
char *francium=malloc(strlen(yytext)+1);
int i;
char *temp=yytext;
for(i=0;i<strlen(yytext);i++){
	if(yytext[i]=='\\'){
		if(i+1>strlen(temp)-1){ //apparently this is okay
			printf("Error: final character of string is slash");
			//francium=strcat(francium,&yytext[i]);
			exit(0);
		}
		switch(temp[i+1]){
			case 'a':
			strcat(francium,"\a");
			i++;
			break;
			case 'b':
			strcat(francium,"\b");
			i++;
			break;
			case '\"':
                        strcat(francium,"\""); //from 1 slash to 3
                        i++;
                        break;
			case 'f':
			strcat(francium,"\f");
			i++;
			break;
			case 'v':
			strcat(francium,"\v");
			i++;
			break;
			case 'n':
			strcat(francium,"\n");
			i++;
			break;
			case 'r':
			strcat(francium,"\r");
			i++;
			break;
			case 't':
			strcat(francium,"\t");
			i++;
			break;
			case '\\':
			strcat(francium,"\\");
			i++;
			break;
			case '\'':
			strcat(francium,"\'");
			i++;
			break;
			
			default:
			printf("Error: '\\' appears but no escape");
			exit(0);
			break;
		}
	                //        int j;
                        //for(j=0;j<strlen(temp)-1;j++){
                          //      temp[j]=temp[j+1];
                        //}
	}
	else{
//		if(&yytext[i]!=NULL){
			//printf("%c",temp[i]);
			strncat(francium,temp,1);
			int j;
			for(j=0;j<strlen(temp)-1;j++){
				temp[j]=temp[j+1];
			}
			//strcat(francium,&yytext[i]);
			//strcat(francium,"a");
//		}
	}
}
//strcat(francium, &yytext[strlen(yytext)-1]);
//strcat(francium,&temp[0]);
//strcat(francium,"\"");
yylval.stringconst=(char *) malloc(strlen(francium)+1); //replace yytext with francium
sprintf(yylval.stringconst,"%s",francium);
last="INTERPRETEDSTRING";
return INTERPRETEDSTRING;
}

\'.\'			{
yylval.charconst=yytext[1];
last="tRUNE";
return tRUNE;
}
\`[^\`]*\`	{
yylval.stringconst=(char *) malloc(strlen(yytext)+1);
sprintf(yylval.stringconst,"%s",yytext);
last="RAWSTRING";
return RAWSTRING;
}
[a-zA-Z_][a-zA-Z0-9_]*	{

yylval.stringconst=(char *) malloc(strlen(yytext)+1);

sprintf(yylval.stringconst,"%s",yytext);

last="tIDENTIFIER";

return tIDENTIFIER;
}

(0|[1-9]{DIGIT}*".")|("."{DIGIT}{DIGIT}*)|((0|[1-9]{DIGIT}*)"."{DIGIT}{DIGIT}*)	{
yylval.floatconst=atof(yytext);
last="tFLOAT";
return tFLOAT;
}

.		{//not sure if last token needs to be invalid but uhhh whatever
fprintf(stderr,"Error: invalid token after %s",last);
exit(0);
}
%%

