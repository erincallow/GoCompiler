#include <stdio.h>
#include "golite.h"
void main(){
	int a=8;
	float b=2.000000;
	char *c="lah";
	char d='a';
	int e=1;
	printf("%d\n",e||e);
printf("%d\n",e&&!e);
printf("%d\n",c=="a");
printf("%d\n",a<2);
printf("%d\n",b>=3.000000);
printf("%d\n",c>"la");
printf("%d\n",d>='b');
printf("%s\n",concatenate("a","b"));
printf("%d\n",a-2);
printf("%d\n",2*3);
printf("%d\n",2%5);
printf("%d\n",2|2);
printf("%d\n",3&a);
printf("%d\n",1<<2);
printf("%d\n",3<<2);
printf("%d\n",~(2|a));
printf("%d\n",a^a);
	printf("%d\n",+2);
printf("%f\n",+2.000000);
printf("%c\n",+'x');
	printf("%d\n",-2);
printf("%f\n",-2.000000);
printf("%c\n",-'x');
	printf("%d\n",~2);
printf("%c\n",~'x');
	printf("%d\n",!1);
printf("%d\n",!0);

}

