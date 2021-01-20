#include <iostream>
using namespace std;
int main()
{
    int n,m,sum,a;
    cin>>n;
    while(n--)
    {
        cin>>m;
        sum=0;
        while(m--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        if(n!=0)
        	cout<<sum<<"\n"<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}
