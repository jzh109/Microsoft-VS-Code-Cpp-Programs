#include <stdio.h>
#include <math.h>
int main(){
	int n,x=0;
	scanf("%d",&n);
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0)  x+=2;
		if(i==sqrt(n))  x--;
	}
	printf("%d\n",x);
	return 0;
}
