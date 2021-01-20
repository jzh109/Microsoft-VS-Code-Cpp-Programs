#include <stdio.h>
int main(){
	int a,min=1000000,max=-1,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		max=max>=a?max:a;
		min=min<=a?min:a;
	}
	printf("%d\n",max-min);
	return 0;
}
