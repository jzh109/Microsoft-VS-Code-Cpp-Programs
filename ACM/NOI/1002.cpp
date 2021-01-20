#include <stdio.h>
#include <math.h>
int main(){
	float x,y,z,s,c;
	scanf("%f%f%f",&x,&y,&z);
	c=(x+y+z)/2.0;
	s=sqrt((c-x)*(c-y)*(c-z)*c);
	printf("%.4f\n",s);
	return 0;
}
