#include <stdio.h>
int main(){
	int a,sum,t;
	while(scanf("%d",&t)!=EOF){
		sum=0;
		while(t--){
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
