#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main () {
	int k, n, t, a[35], b[35];
	cin>>t;
	while(t--){
		cin>>n>>k;
		int res = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int i = 0; i < n; i++)  cin>>a[i];
		for(int i = 0; i < n; i++)  cin>>b[i];
		for(int i = 0; i < k; i++){
			sort(a + i, a + n);
			sort(b + i, b + n, cmp);
			if(a[i] < b[i]) a[i] = b[i];
		}
		for(int i = 0; i < n; i++)  res += a[i];
		cout<<res<<endl;
	}
	return 0;
}
