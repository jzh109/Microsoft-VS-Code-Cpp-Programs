#include<iostream>
using namespace std ;
int main()
{
	float a;
	cin>>a;
	if (a<=0.5)
		cout<<"3";
	else
		cout<<(a-0.5)/0.2+3;
	return 0;
}
