#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n, count = 0, a[51];
	while(scanf("%d%d", &m, &n) != EOF && m && n) {
		int max = m * n, res = 0;
		for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
		sort(a, a + n);
		for(int i = n - 1; i >= 0; i--) {
			if(a[i] >= max) {
				res++;
				max--;
			}
			else {
				max -= 2;
			}
		}
		printf("Case %d: %d\n", ++count, res);
	}
	return 0;
}
