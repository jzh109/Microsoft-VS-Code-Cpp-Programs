#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, fr, to, temp;
	int a[205];
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			int max = -1;
			scanf("%d", &n);
			for(int i = 0; i < 205; i++)  a[i] = 0;
			for(int i = 0; i < n; i++) {
				scanf("%d %d", &fr, &to);
				if(fr > to) {
					temp = fr;
					fr = to;
					to = temp;
				}
				fr = (fr - 1) / 2;
				to = (to - 1) / 2;
				for(int j = fr; j <= to; j++)	a[j]++;
			}
			for(int i = 0; i < 205; i++) 	max = max > a[i] ? max : a[i];
			printf("%d\n", max * 10);
		}
	}
	return 0;
}
