#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node{
	int from, to, cost;
	bool operator < (Node other) const {
		return cost < other.cost;
	}
}node[100005];

int father[100005], n, m;

void init() {
	for(int i = 1; i <= n; i++) father[i] = i;
}

int findx(int x) {
	if(father[x] == x)  return x;
	return father[x] = findx(father[x]);
}

void merge(int a, int b) {
	int x = findx(a), y = findx(b);
	if(x == y)  return;
	father[x] = y;
}

int kr() {
	int res = -1;
	sort(node + 1, node + 1 + m);
	for(int i = 1; i <= m; i++) {
		if(findx(node[i].from) == findx(node[i].to))    continue;
		res = node[i].cost > res ? node[i].cost : res;
		merge(node[i].from, node[i].to);
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &node[i].from, &node[i].to, &node[i].cost);
	int res = kr();
	int temp = findx(1);
	for(int i = 2; i <= n; i++) {
		if(findx(i) != temp) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", res);
	return 0;
}
