#include <iostream>
using namespace std;
int main()
{
	int n,m,a[1000],temp;
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(int i=0;i<m;i++)
			cin>>a[i];
		for(int i=1;i<m;i++)
		{
			for(int j=i;j>0;j--)
			{
				if(a[j]>a[j-1])
				{
					temp=a[j-1];
					a[j-1]=a[j];
					a[j]=temp;
				}
			}
		}
		while(m--)
		{
			if(m)
				cout<<a[m]<<" ";
			else
				cout<<a[m]<<endl;
		}
	}
	return 0;
} 
