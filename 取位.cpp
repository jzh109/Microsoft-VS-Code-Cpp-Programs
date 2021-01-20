#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int a;
	scanf("%d",&a);
	a=a>>4;
	a=a&15;
	printf("%d\n",a);
	system("pause");
 } 
