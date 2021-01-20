#include <stdio.h>
int main(){
	int n,s=0;
	scanf("%d",&n);
	do{
		while (n){
	    	s+=n%10;
	    	n/=10;
    	}
    	n=s;
		s=0;
	} while (n>=10);
	printf("%d",n);
	return 0;
}
