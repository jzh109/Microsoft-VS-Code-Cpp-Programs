#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10],b[10],i,j,k,min,n;
	printf("Enter the number of the numbers\n(It must be inferior to 10):");
	scanf("%d",&n);
	printf("Enter the series:");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				min=a[j];
				a[j]=a[j+1];
				a[j+1]=min;
			}
		}
	} 
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	system("pause");
}
