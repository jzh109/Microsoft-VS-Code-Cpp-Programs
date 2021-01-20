#include <stdio.h>
int main(){
	int x,y,z,sum,les;
	scanf("%d%d%d",&x,&y,&z);
	if((x+y>z)&&(x+z>y)&&(y+z>x)){
		if((x==y)&&(y==z))  printf("Equilateral\n");
		else if((x*x+y*y==z*z)||(x*x+z*z==y*y)||(y*y+z*z==x*x)) printf("Right\n");
		else    printf("General\n");
	}
	else    printf("NO\n");
	return 0;
}
