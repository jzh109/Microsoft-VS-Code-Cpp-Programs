#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const long MAX = 1e5 + 10;
const long INF = 0x3f3f3f3f;
struct Node {
	long a, b;
	bool operator < (Node other) const {
        return a < other.a;
	}
}node[MAX];

int main() {
	int n, t, Case = 1;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			long res = INF, val[MAX], temp = 0;
			memset(val, 0, sizeof(val));
			cin >> n;
			for(int i = 0; i < n; i++)  cin >> node[i].a >> node[i].b;
			sort(node, node + n);
			for(int i = n - 1; i >= 0; i--) {
				temp = temp > node[i].b ? temp : node[i].b;
				val[i] = temp;
			}
			for(int i = 0; i < n; i++) 	res = res < node[i].a + val[i + 1] ? res : node[i].a + val[i + 1];
			cout << "Case " << Case++ << ": " << res <<endl;
		}
	}
	return 0;
}
