#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, u, d;
	while(scanf("%d%d%d", &n, &u, &d) != EOF && n && u && d) {
		bool rest = false;
		int min = 0;
		while(n > 0) {
			if(rest) {
				n += d;
				min++;
				rest = !rest;
			}
			else {
				n -= u;
				min++;
				rest = !rest;
			}
		}
		printf("%d\n", min);
	}
	return 0;
}
