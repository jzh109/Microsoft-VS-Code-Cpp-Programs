#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&k);
		printf("%d\n",(k-1)/(n-1)+k);
	}
	return 0;
}
