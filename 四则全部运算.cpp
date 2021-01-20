#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a,b,c,d,e,f;
	printf("请输入两个整数：");
	scanf("%f%f",&e,&f);
	a=e+f;
	b=e-f;
	c=e*f;
	d=e/f;
	printf("这两个数的和、差、积、商分别为：%.0f,%.0f,%.0f,%f\n",a,b,c,d);
	system("pause");
}
