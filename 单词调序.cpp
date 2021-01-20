#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[1000],temp;
	int t,len,i,j;
	while(scanf("%d",&t)!=EOF)
	{
		for(j=0;j<t;j++)
		{
			scanf("%s",str);
			len=strlen(str);
			for(i=0;i<len/2;i++)
			{
				temp=str[i];
				str[i]=str[len-i-1];
				str[len-i-1]=temp;
			}
			printf("%s",str);
			if(str[len-1]!=46&&str[len-1]!=33&&str[len-1]!=63)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
} 
