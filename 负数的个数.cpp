#include <stdio.h>

int count_n(int b[],int n);		//统计数组中负数的个数 

int main()
{
	int i,n,b[10];
	for(0;i<10;i++)
		scanf("%d",&b[i]);		//输入数组 
	n=count_n(b,10);			//返回个数 
	printf("%d",n);
} 
int count_n(int b[],int n)
{
	int i,k=0;
	for(i=0;i<10;i++)
	{
		if(b[i]<0)
			k++;
	}
	return k;
}
