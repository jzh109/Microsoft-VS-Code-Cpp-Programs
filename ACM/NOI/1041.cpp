#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 5005

struct Node {
	int num, val;
}node[MAX];

bool cmp(Node a, Node b){
	if(a.val != b.val)  return a.val > b.val;
	return a.num < b.num;
}

int main() {
	int n,m,line,num;
	const double eps = 1e-6;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)  scanf("%d%d", &node[i].num, &node[i].val);
	sort(node + 1, node + 1 + n, cmp);
	num = (int)(m * 1.5);
	line = node[num].val;
    for(; node[num + 1].val == line; num++);
	printf("%d %d\n", line, num);
	for(int i = 1; i <= num; i++)	printf("%d %d\n", node[i].num, node[i].val);
	return 0;
}
