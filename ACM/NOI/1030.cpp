#include <stdio.h>
int main(){
	long long a,n=1;
	scanf("%lld",&a);
	if(a==1){
		printf("1\n");
		return 0;
	}
	while(1){
		if(a%2==0)  a=a/2;
		else    a=3*a+1;
		n++;
		if(a==1){
			printf("%d\n",n);
			return 0;
		}
	}
}
