#include <stdio.h>
#include <stdlib.h> 

main()
{
	printf("请输入小写字母："); 
	char a;
	a=getchar();
	a=a-32;
	printf("其大写字母为：%c\n",a);
	system("pause");
 } 
