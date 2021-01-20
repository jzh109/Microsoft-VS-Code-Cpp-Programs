#include <stdio.h>
int main(){
	int a,t,sum;
	while(scanf("%d",&t)!=EOF){
		sum=0;
		if(t==0)	break;
		while(t--){
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
