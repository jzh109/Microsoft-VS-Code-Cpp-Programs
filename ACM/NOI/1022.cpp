#include <stdio.h>
int main(){
	int a,sum=0,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		sum+=a;
	}
	printf("%.2f\n",(float)sum/n);
	return 0;
}
