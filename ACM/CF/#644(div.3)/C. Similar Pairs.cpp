#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,a[1005],n,b[1005],c[1005];
	cin>>t;
	while(t--){
		bool find=false;
		cin>>n;
		for(int i=1;i<=n;i++)    cin>>a[i];
		sort(a+1,a+n+1);
		int x=1,y=1;
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				b[x++]=a[i];
			}
			else    c[y++]=a[i];
		}
		x--;
		y--;
		if(x%2==0)  {
			cout<<"YES"<<endl;
			continue;
		}
		else{
			for(int i=1;i<=x;i++){
				for(int j=1;j<=y;j++){
					if(b[i]-c[j]==1||c[j]-b[i]==1){
						cout<<"YES"<<endl;
						find=true;
						break;
					}
				}
				if(find)break;
			}
			if(find)continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}
