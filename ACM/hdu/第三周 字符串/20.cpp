#include <iostream>
using namespace std;
int main()
{
	int n,i,j,k=0;
	char c;
	while(scanf("%c %d",&c,&n)!=EOF)
	{
		getchar();
		if(c!='@')
		{
			if(k>0)	printf("\n");
			k++;
			for(j=0;j<n;j++)
			{
				for(i=0;i<n-j-1;i++)
					printf(" ");
				printf("%c",c);
				if(j==0)
					printf("\n");
				else if(j!=n-1)
				{
					for(i=0;i<2*j-1;i++)
						printf(" ");
					printf("%c\n",c);
				}
				else
				{
				    for(i=0;i<2*n-2;i++)
				    	printf("%c",c);
				    printf("\n");
				}
			}
		}
		else	break;
	}
	return 0;
}
