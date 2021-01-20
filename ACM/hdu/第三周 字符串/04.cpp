#include <stdio.h>
#include <string.h>
int main()
{
	char a[220],b[220][220];
	int n,i,j,t;
	while(~scanf("%d",&n)&&n)
	{
		getchar();
		gets(a);
		t=strlen(a);
		int m=t/n,k=0;
		for(i=0;i<m;i++)
		{
			if(i%2==0)
				for(j=0;j<n;j++)
				{
					b[i][j]=a[k];
					k++;
				}		
			else
				for(j=n-1;j>=0;j--)
				{
					b[i][j]=a[k];
					k++;
				}	
		}
		for(j=0;j<n;j++)
			for(i=0;i<m;i++)
				printf("%c",b[i][j]);
		printf("\n");	
	} 
	return 0;
}
