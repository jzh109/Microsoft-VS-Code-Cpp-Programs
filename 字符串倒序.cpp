#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char str[20],temp;
	gets(str);
	int i,len;
	len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
	puts(str);
	return 0;
	system("pause");
}
