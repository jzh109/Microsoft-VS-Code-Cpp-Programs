#include <stdio.h>
int main(){
	int max=-1,min=101,n,m=0;
	for(int i=0;i<10;i++){
		scanf("%d",&n);
		max=max>n?max:n;
		min=min<n?min:n;
		m+=n;
	}
	printf("%.3f\n",(float)(m-max-min)/8.0);
	return 0;
}
