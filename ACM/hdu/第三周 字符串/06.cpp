#include <iostream>
using namespace std;
int main()
{
	int t,i,n,j,s;
	char c;
	while(scanf("%d",&t)!=EOF)
	{
		for(s=0;s<t;s++)
		{
			getchar();
			scanf("%c%d",&c,&n);
			for(i=0;i<n/6+1;i++)
				printf(" ");
			for(i=0;i<(n-3)-(n-3)/2;i++)
				printf("%c",c);
			printf("\n");
			for(i=0;i<(n-3)/2;i++)
			{
				for(j=0;j<n/6+1;j++)
				    printf("%c",c);
				for(j=0;j<(n-3)-(n-3)/2;j++)
					printf(" ");
				for(j=0;j<n/6+1;j++)
					printf("%c",c);
				printf("\n");
			}
			for(i=0;i<n/6+1;i++)
				printf(" ");
			for(i=0;i<(n-3)-(n-3)/2;i++)
				printf("%c",c);
			printf("\n");
			for(i=0;i<(n-3)-(n-3)/2;i++)
			{
				for(j=0;j<n/6+1;j++)
					printf("%c",c);
				for(j=0;j<(n-3)-(n-3)/2;j++)
					printf(" ");
				for(j=0;j<n/6+1;j++)
					printf("%c",c);
				printf("\n");
			}
			for(i=0;i<n/6+1;i++)
				printf(" ");
			for(i=0;i<(n-3)-(n-3)/2;i++)
				printf("%c",c);
			printf("\n");
			if(s!=t-1) 
				printf("\n");
		}
	}
	return 0;
}
