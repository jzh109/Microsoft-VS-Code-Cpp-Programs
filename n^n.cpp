#include <iostream>
using namespace std;
int main()
{
	int n,i,r;
	while(scanf("%d",&n)!=EOF)
	{
		r=1;
		for(i=0;i<n;i++)
		{
			r=r*n;
			//r=r%10;
		}
		cout<<r<<endl;
	}
}
