#include <stdio.h>
int main(){
	int x, y, z, sum;
	scanf("%d%d%d",&x,&y,&z);
	sum=x+y+z;
	printf("%d\n%.2f\n", sum, (float)sum/3);
}
