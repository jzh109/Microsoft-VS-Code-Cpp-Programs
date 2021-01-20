#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[100],max;
	int len,i;
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		max=str[0];
		for(i=0;i<len;i++)
		{
			if(str[i]>=max)
				max=str[i];
		}
		for(i=0;i<len;i++)
		{
			if(str[i]==max)
				printf("%c(max)",str[i]);
			else
				printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
} 
