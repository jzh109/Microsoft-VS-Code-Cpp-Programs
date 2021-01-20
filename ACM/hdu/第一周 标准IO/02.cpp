#include <stdio.h>
int main(){
	int a,b,t;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d",&a,&b);
			printf("%d\n",a+b);
		}
	}
	return 0;
} 
