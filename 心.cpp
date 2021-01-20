#include <stdio.h>
#include <stdlib.h>
void star();

int main()
{
	star();
	return 0;
}

void star(void)  
{  
	int i,j;    
	printf("     ******       ******\n"  "   **********   **********\n"  \
" ************* *************\n");  //前三排的规律性不强  所以直接显示就好了    
	for(i=0;i<3;i++)//显示中间三排  
	{  
		for(j=0;j<29;j++)  
			printf("*");  
		printf("\n");  
	}    
	for(i=0;i<7;i++)//显示呈递减趋势规律的中间7排  
	{  
		for(j=0;j<2*(i+1)-1;j++)  
			printf(" ");  
		for(j=0;j<27-i*4;j++)  
			printf("*");  
		printf("\n");  
	}    
	for(i=0;i<14;i++)//最后一个星号*与上面的规律脱节了  所以独立显示  
		printf(" ");  
	printf("*\n");   
	system("pause");
} 

