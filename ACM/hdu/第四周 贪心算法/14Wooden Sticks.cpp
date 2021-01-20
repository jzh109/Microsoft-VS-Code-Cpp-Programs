#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 50010;
struct Node {
	int w, l;
	bool operator < (Node &other) const {
		if(w != other.w)	return w < other.w;
		return l < other.l;
	}
}node[MAX];

int main() {
	int n, t;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			int done[MAX], res = 0;
			memset(done, 0, sizeof(done));
			scanf("%d", &n);
			for(int i = 0; i < n; i++)  scanf("%d%d", &node[i].l, &node[i].w);
			sort(node, node + n);
			for(int i = 0; i < n; i++) {
				if(done[i]) continue;
				int temp = node[i].l;
				for(int j = i + 1; j < n; j++) {
					if(done[j]) continue;
					if(temp <= node[j].l) {
						temp = node[j].l;
						done[j] = 1;
					}
				}
				res++;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
