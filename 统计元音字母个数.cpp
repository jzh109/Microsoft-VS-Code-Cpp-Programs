#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,i,len,j;
	char str[100];
	int suma,sume,sumi,sumo,sumu;
	while(scanf("%d",&t)!=EOF)
	{
		getchar();
		for(j=0;j<t;j++)
		{
			suma=0;
			sume=0;
			sumi=0;
			sumo=0;
			sumu=0;
			gets(str);
			len=strlen(str);
			for(i=0;i<len;i++)
			{
				if(str[i]=='a')
					suma++;
				else if(str[i]=='e')
					sume++;
				else if(str[i]=='i')
					sumi++;
				else if(str[i]=='o')
					sumo++;
				else if(str[i]=='u')
					sumu++;
			}
			printf("a:%d\n",suma);
			printf("e:%d\n",sume);
			printf("i:%d\n",sumi);
			printf("o:%d\n",sumo);
			printf("u:%d\n",sumu);
			if(j!=t-1)
				printf("\n");
		}
	}
	return 0;
}
