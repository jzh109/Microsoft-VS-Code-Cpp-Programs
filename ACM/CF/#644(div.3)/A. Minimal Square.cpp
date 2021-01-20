#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	ll a,b,min,s,max;
	while(t--){
		cin>>a>>b;
		min=a<b?a:b;
		max=min==a?b:a;
		min*=2;
		s=max>min?max:min;
		cout<<s*s<<endl;
	}
	return 0;
}
