#include <stdio.h>
int a;
int recurse(int n){
	if(n==1){
	return 2;

}
else {
	for(int i=0;i<n;i++){
	;

}


	return recurse(n-1);

}



}

void main(){
	printf("%d\n",recurse(150000));

}

