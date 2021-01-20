#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

struct Floor {
	long long w, s;
}flo[MAX];

bool cmp(Floor a, Floor b) {
	return a.w + a.s < b.w + b.s;
}

int main() {
	long long t, n;
	while(cin >> n) {
		long long sumw = 0, res = -1;
		for(long long i = 0; i < n; i++) 	scanf("%d%d", &flo[i].w, &flo[i].s);
		sort(flo, flo + n, cmp);
		for(long long i = 0; i < n; i++) {
			res = max(res, sumw - flo[i].s < 0 ? 0 : sumw - flo[i].s);
			sumw += flo[i].w;
		}
		cout << res << endl;
	}
	return 0;
}
