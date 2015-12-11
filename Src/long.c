#include <stdio.h>
int fact(int n){
	if(n==1){
	return 1;

}
else {
	return n*fact(n-1);

}



}

void main(){
	int a;
 a=1;

	int i;
 i=0;

	while(a<2000000000){
	i=fact(5);
	a+=1;

}


	printf("%d",i);

}

