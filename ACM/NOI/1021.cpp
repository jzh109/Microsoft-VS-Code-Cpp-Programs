#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
	double a,b;		
	cin>>a;
	if(a<=100000)	b=a*0.1;
	else if(a<200000)	b=(a-100000)*0.075+10000;
    else if(a<400000)	b=(a-200000)*0.05+17500;
    else if(a<600000)	b=(a-400000)*0.03+27500;
    else if(a<1000000)	b=(a-600000)*0.015+33500;
    else if(a>=1000000)	b=(a-1000000)*0.01+39500;
    printf("%.3f",b);
	return 0;
}
