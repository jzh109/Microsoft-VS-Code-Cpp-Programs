#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,j,n,len,t;
	char str[10000],temp;
	while(scanf("%d",&t)!=EOF)
	{
		for(j=0;j<t;j++)
		{
			n=0;
			scanf("%s",str);
			len=strlen(str);
			for(i=0;i<len;i++)
			{
				temp=str[i];
				if(temp>=48&&temp<=57)
					n++;
			}
			printf("%d\n",n);
		}
	}
	return 0;
}
