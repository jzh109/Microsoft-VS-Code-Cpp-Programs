#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[10000],temp;
	int i,j,len,n,t,s;
	while(printf("Input lines:"),scanf("%d",&t)!=EOF)
	{
		for(s=0;s<t;s++)
		{
			printf("Input strings:");
			scanf("%s",str);
			len=strlen(str);
			for(i=65;i<91;i++)
			{
				n=0;
				for(j=0;j<len;j++)
				{
					temp=str[j];
					if(temp==i)
						n++;
				}
				if(n==0)
					continue;
				else if(n==1)
					printf("%c",i);
				else
					printf("%d%c",n,i);
			}
			printf("\n");
		}
	}
	return 0;
} 
