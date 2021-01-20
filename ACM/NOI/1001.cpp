#include <stdio.h>
int main(){
	float c;
	scanf("%f",&c);
	c=(c-32)*5.0/9.0;
	printf("%.4f\n",c);
	return 0;
}
