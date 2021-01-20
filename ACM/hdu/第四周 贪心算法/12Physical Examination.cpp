#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 5;
const int MOD = 365 * 24 * 60 * 60;
struct Node {
	long long a, b;
}node[MAX];

bool cmp(Node x, Node y) {
	return x.a * y.b <= y.a * x.b;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF && n) {
		long long res = 0;
		for(int i = 0; i < n; i++)  scanf("%lld%lld", &node[i].a, &node[i].b);
		sort(node, node + n, cmp);
		for(int i = 0; i < n; i++)  res += node[i].a % MOD + res * node[i].b % MOD;
		printf("%lld\n", res % MOD);
	}
	return 0;
}
