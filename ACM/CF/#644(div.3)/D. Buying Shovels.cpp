#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(k>=n)	cout<<1<<endl;
		else{
			for (int i=min(n/2+1,k);i>0;i--){
				if(n%i==0){
					cout<<n/i<<endl;
					break;
				}
				else	i=n/(n/i+1)+1;
			}
		}
	}
	return 0;
}
