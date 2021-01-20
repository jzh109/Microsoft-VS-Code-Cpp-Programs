#include <iostream>
using namespace std;
int main()
{
	int m,sum,a;
	while(scanf("%d",&m)!=EOF)
	{
		sum=0;
		while(m--)
		{
			scanf("%d",&a);
			sum+=a;
		}
		cout<<sum<<endl;
	}
	return 0;
}
