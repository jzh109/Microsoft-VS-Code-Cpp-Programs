#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_M 100

struct edge {
	int from, to;
	int cost;
}BIN[MAX_M * MAX_M];

int M, N;
int father[MAX_M];

void init () {
	for (int i = 1; i <= M; i++)
		father[i] = i;
}

int findx (int x) {
	if (x == father[x])	return x;
	return father[x] = findx (father[x]);
}

void merge (int x, int y) {
	int a = findx (x), b = findx (y);
	if (a == b)	return;
	father[a] = b;
}

bool cmp (edge x, edge y) {
	return x.cost < y.cost;
}

bool samex (int x, int y) {
	return findx (x) == findx (y);
}

int kr () {
	int res = 0;
	sort (BIN + 1, BIN + 1 + N, cmp);
	for (int i = 1; i <= N; i++) {
		if (samex (BIN[i].from, BIN[i].to))	continue;
		merge (BIN[i].from, BIN[i].to);
		res += BIN[i].cost;
	}
	return res;
}

int main () {
	while (scanf ("%d%d", &N, &M) == 2) {
		if (N == 0)	break;
		init ();
		for (int i = 1; i <= N; i++)
			scanf ("%d%d%d", &BIN[i].from, &BIN[i].to, &BIN[i].cost);
		int res = kr ();
		for (int i = 1; i <= M; i++)
			if (!samex (i, 1))
				res = -1;
		if (res == -1)
			printf ("?\n");
		else
			printf ("%d\n", res);
	}
	return 0;
}
