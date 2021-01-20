#include <stdio.h>
int main(){
	int a,x=20;
	for(int i=0;i<3;i++){
		scanf("%d",&a);
		x-=a;
	}
	printf("%d\n",x);
	return 0;
}
