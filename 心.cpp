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
" ************* *************\n");  //ǰ���ŵĹ����Բ�ǿ  ����ֱ����ʾ�ͺ���    
	for(i=0;i<3;i++)//��ʾ�м�����  
	{  
		for(j=0;j<29;j++)  
			printf("*");  
		printf("\n");  
	}    
	for(i=0;i<7;i++)//��ʾ�ʵݼ����ƹ��ɵ��м�7��  
	{  
		for(j=0;j<2*(i+1)-1;j++)  
			printf(" ");  
		for(j=0;j<27-i*4;j++)  
			printf("*");  
		printf("\n");  
	}    
	for(i=0;i<14;i++)//���һ���Ǻ�*������Ĺ����ѽ���  ���Զ�����ʾ  
		printf(" ");  
	printf("*\n");   
	system("pause");
} 

