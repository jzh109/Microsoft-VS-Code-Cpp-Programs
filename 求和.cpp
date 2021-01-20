#include <stdio.h>
#include <stdlib.h>

main()
{
	int sum=0,a;
	LOOP:
		printf("Enter a number:");
		scanf("%d",&a);
		sum+=a;
	if(a!=0) goto LOOP;
	else printf("SUM is:%d",sum);
	system("pause");
}
