#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10],i,j,k,min,n;
	printf("Enter the number of the numbers\n(It must be inferior to 10):");
	scanf("%d",&n);
	printf("Enter the series:");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]); 														// �������� 
	for(i=0;i<n;i++)															//���⣺i<n-1ʱ����һ��δ���� 
	{																			//���⣺�������һ��Ϊ��Сֵʱ�������һ��Ϊ0 
		min=a[0];
		for(j=0;j<n-i;j++)    													//���⣺û��=ʱ��һ����0 
			if(a[j]<=min) 
			{
				min=a[j];
				k=j;
			}																	//ȷ����Сֵ���k 
			else 
				continue;
		for(j=k;j<n-i;j++)
		{
			min=a[j];
			a[j]=a[j+1];
			a[j+1]=min;
		}																		//һ��һ�λ ����� 
		
	}
	for(i=0;i<n;i++)
		printf("%-4d",a[i]);
	system("pause");
}
