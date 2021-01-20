#include <stdio.h>
#include <stdlib.h> 

main()
{
	int a=0,b=0,i=0,x;
	while(i<10)
	{
		i++;
		printf("Enter result(1=pass,2=fail):");
		scanf("%d",&x);
		if(x==1)
			a++;
		else
			b++;
	}
	printf("Passed%d, Failed%d\n",a,b);
	if(a>=8)
		printf("EXCELLENT CLASS\n");
	else
		printf("DEVELOPING CLASS\n");
	system("pause");
	return 0;
}
