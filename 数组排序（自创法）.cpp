#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10],i,j,k,min,n;
	printf("Enter the number of the numbers\n(It must be inferior to 10):");
	scanf("%d",&n);
	printf("Enter the series:");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]); 														// 输入数组 
	for(i=0;i<n;i++)															//问题：i<n-1时，第一项未排序 
	{																			//问题：当输入第一项为最小值时，输出第一项为0 
		min=a[0];
		for(j=0;j<n-i;j++)    													//问题：没有=时有一项是0 
			if(a[j]<=min) 
			{
				min=a[j];
				k=j;
			}																	//确定最小值序号k 
			else 
				continue;
		for(j=k;j<n-i;j++)
		{
			min=a[j];
			a[j]=a[j+1];
			a[j+1]=min;
		}																		//一项一项换位 到最后 
		
	}
	for(i=0;i<n;i++)
		printf("%-4d",a[i]);
	system("pause");
}
