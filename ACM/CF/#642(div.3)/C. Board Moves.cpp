#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fi(ll n) {
	ll res = 0;
	for(ll i = 1; i <= n; i++) {
		res += (i - 1) * (2 * i - 2);
	}
	return res;
}

int main () {
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		n = (n + 1) / 2;
		ll res = fi(n);
		printf("%lld\n", res * 4);
	}
	return 0;
}
