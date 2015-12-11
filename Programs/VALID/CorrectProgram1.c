#include <stdio.h>
int plusminus(int a, int b, int c){
	int result;

	if(c){
	result=a+b;

}
else {
	result=a-b;

}


	return result;

}

void main(){
	int printThis=plusminus(5, 10, 1);
	printf("%d\n",printThis);
	printThis=plusminus(5, 10, 0);
	printf("%d\n",printThis);

}

