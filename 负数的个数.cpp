#include <stdio.h>

int count_n(int b[],int n);		//ͳ�������и����ĸ��� 

int main()
{
	int i,n,b[10];
	for(0;i<10;i++)
		scanf("%d",&b[i]);		//�������� 
	n=count_n(b,10);			//���ظ��� 
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
