#include <iostream>
using namespace std;
int main()
{
	int t,i,j,N,P[200];
	int s,d,temp,k,min;
	cin>>t;
	for(i=0;i<t;i++) {
		for(j=0;j<200;j++)
			P[j]=0;
		cin>>N;
		for(j=0;j<N;j++) {
			cin>>s>>d;
			s=(s-1)/2;
			d=(d-1)/2;
			if(s>d) {
				temp=s;
				s=d;
				d=temp;
			}
			for(k=s;k<=d;k++)
				P[k]++;
		}
		min=-1;
		for(j=0;j<200;j++)
			if(P[j]>min)
				min=P[j];
			cout<<min*10<<endl;
	}
	return 0;
}
