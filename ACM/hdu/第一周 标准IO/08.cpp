#include<stdio.h>
int main(){
	int a,sum,n,t;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			sum=0;
			scanf("%d",&t);
			while(t--){
				scanf("%d",&a);
				sum+=a; 
			}
			printf("%d\n",sum);
			if(i!=n-1)	printf("\n");
		}
	}
	return 0;
}
