#include <stdio.h>
#include <string.h>
int main()
{
	while(1){
		char a[10];
		int len,d=0;
		gets(a);
		len=strlen(a);
		for(int i=0;i<len;i++)
		{
			int e=1;
			if(a[i]>='0'&&a[i]<='9')
			{
				for(int j=0;j<len-1-i;j++)
					e*=16;
				d+=(a[i]-'0')*e;
			}
			if(a[i]>='A'&&a[i]<='F')
			{
				for(int j=0;j<len-1-i;j++)
					e*=16;
				d+=(a[i]-'A'+10)*e;
			}
		}
		printf("%d\n",d);
	}
}
