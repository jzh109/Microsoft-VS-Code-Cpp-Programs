#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a[10][10],b[10][10],c[10][10],i,j,k,m,s,n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cout<<"Input the matrix A row and column and matrix B column with a space between each:";
	scanf("%d %d %d",&m,&s,&n);
	cout<<"Input matrix A(one space between two numbers):"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<s;j++)
			scanf("%d",&a[i][j]);
	}
	cout<<"Input matrix B(one space between two numbers):"<<endl;
	for(i=0;i<s;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<s;k++)
				c[i][j]=a[i][k]*b[k][j];
		}
	}
	cout<<"Matrix A multiply matrix B is:"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
}
