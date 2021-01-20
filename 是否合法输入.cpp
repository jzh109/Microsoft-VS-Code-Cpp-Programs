#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,i,j,len;
	char str[50];
	while(scanf("%d",&t)!=EOF)
	{
		loop:
		for(j=0;j<t;j++)
		{
			scanf("%s",str);
			if(str[0]>=48&&str[0]<=57)
			{
				printf("no\n");
				goto loop;
			}
			len=strlen(str); 
			for(i=0;i<len;i++)
			{
				if(str[i]==32)
				{ 
					printf("no\n");
					break;
				} 
				else
				{
					printf("yes\n");
					break;
				}
			}goto loop;
		}
	}
	return 0;
}
