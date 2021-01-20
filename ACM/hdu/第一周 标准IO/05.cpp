#include <stdio.h>
int main(){
	int n,t,a,sum;
	while(scanf("%d",&t)!=EOF){
		while(t--&&scanf("%d",&n)){
			sum=0;
			while(n--){
				scanf("%d",&a);
				sum+=a;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
