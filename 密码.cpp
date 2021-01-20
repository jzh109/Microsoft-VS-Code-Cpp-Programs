#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int len,i,j,k=0,t,s=0;
	char str[50];
	while(scanf("%d",&t)!=EOF)
	{
		for(j=0;j<t;j++)
		{
			getchar();
			gets(str);
			len=strlen(str);
			if(len<8||len>16)
				printf("NO\n");
			for(int cas=0;cas<4;cas++)
			{
				for(i=s;i<len;i++)
				{	s++;
					if(str[i]>64&&str[i]<90)
					{
						k++;
						break;
					}
					else if(str[i]>96&&str[i]<122)
					{
						k++;
						break;
					}
					else if(str[i]>47&&str[i]<58)
					{
						k++;
						break;
					}
					else if(str[i]==35||str[i]==36||str[i]==37||str[i]==33||str[i]==126||str[i]==64||str[i]==94)
					{
						k++;
						break;
					}
				}
			}
			if(k>2)
				printf("YES\n");
			else
				printf("NO\n"); 
		}
	}
}
