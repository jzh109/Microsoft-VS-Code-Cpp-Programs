#include <stdio.h>
#include <math.h>
int main(){
	float r,x,p,y;
	scanf("%f%f%f",&r,&x,&p);
	y=x*pow((100+r)/100,p);
	printf("%.2f\n",y);
	return 0;
}
