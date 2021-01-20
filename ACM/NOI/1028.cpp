#include <stdio.h>
int main(){
	unsigned m,n,c;
	scanf("%u%u",&m,&n);
	c=(m<n?m:n);
	for(int i=2;i<=c;i++){
		if(m%i==0&&n%i==0) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
