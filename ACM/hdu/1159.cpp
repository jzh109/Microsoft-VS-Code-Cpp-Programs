#include <stdio.h>
#include <string.h>
int main()
{
	while(1)
	{
		char a[100],b[100];
		int n=0,temp=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s%s",a,b);
		for(int i=0;i<strlen(a);i++)
		{
			for(int j=temp;j<strlen(b);j++)
			{
				if(a[i]==b[j])
				{
					temp=j+1;
					n++;
					break;
				}
			}
		}
		printf("%d\n",n);
	}
	return 0;
} 
