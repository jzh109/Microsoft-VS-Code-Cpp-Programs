#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k=1,x[205][105];
	cin>>n;
	for(i=0;i<=2*n-1;i++)
	{
		if(i<n)
			if(i%2==1)for(j=0;j<=i;j++)x[i][j]=k++;
			else for(j=i;j>=0;j--)x[i][j]=k++;
		else
			if(i%2==1)for(j=0;j<=2*n-i-2;j++)x[i][j]=k++;
			else for(j=2*n-i-2;j>=0;j--)x[i][j]=k++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)cout<<x[j+i][j]<<" ";
		for(k=n-i;k<n;k++)cout<<x[i+k][j-1]<<" ";
		if(i<n-1)cout<<endl;
	}
	return 0;
}
