#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n,temp,m,a[1005];
	cin>>t;
	while(t--){
		ll min=0x3f3f3f3f;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			m=a[i]-a[i-1];
			if(min>m){
				min=m;
			}
		}
		cout<<min<<endl;
	}
	return 0;
}
