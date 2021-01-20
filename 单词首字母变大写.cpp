#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[100];
	int i,len,max;
	while(gets(str))
	{
		len=strlen(str);
		str[0]=str[0]-32;
		for(i=1;i<len;i++)
		{
			if(str[i-1]==32)
				str[i]=str[i]-32;
		}
		printf("%s\n",str);
	}
}
