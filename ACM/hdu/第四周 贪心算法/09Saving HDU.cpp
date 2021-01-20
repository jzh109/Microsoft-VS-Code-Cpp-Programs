#include <bits/stdc++.h>
using namespace std;

struct Stone {
	int pi;
	int mi;
}stone[105];

bool cmp(Stone a, Stone b) {
	return a.pi > b.pi;
}

int main() {
	int n, v;
	while(scanf("%d", &v) != EOF && v) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)	scanf("%d%d", &stone[i].pi, &stone[i].mi);
		sort(stone, stone + n, cmp);
		int res = 0;
		for(int i = 0; i < n; i++) {
			if(v >= stone[i].mi) {
				res += stone[i].pi * stone[i].mi;
				 v -= stone[i].mi;
			}
			else {
				res += stone[i].pi * v;
				break;
            }
		}
		printf("%d\n", res);
	}
	return 0;
}
