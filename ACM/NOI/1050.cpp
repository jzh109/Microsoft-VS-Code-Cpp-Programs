#include <stdio.h>
#include <string.h>
int main() {
	int n, m, k, a[105][105], b[105][105], c[105][105] = {0};
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	//memset(c, 0, sizeof(c));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)  scanf("%d", &a[i][j]);
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < k; j++)  scanf("%d", &b[i][j]);
	}
	for(int t = 0; t < m; t++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) {
				c[i][j] += a[i][t] * b[t][j];
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++)  printf("%d ", c[i][j]);
		printf("\n");
	}
	return 0;
}
