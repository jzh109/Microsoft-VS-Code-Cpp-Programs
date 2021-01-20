#include <stdio.h>
int main(){
	double a,b,x;
	int k;
	scanf("%lf%lf",&a,&b);
	for(k=1;a>=b*k;k++);
	x=a-(b*--k);
	printf("%.2f",x);
	return 0;
}
