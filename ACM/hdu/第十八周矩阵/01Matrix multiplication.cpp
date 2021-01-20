#include <stdio.h>
#include <string.h>
long long n, a[805][805], b[805][805], c[805][805];
int main() {
	while(~scanf("%d", &n)){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				a[i][j] = a[i][j] % 3;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &b[i][j]);
				b[i][j] = b[i][j] % 3;
			}
		}
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 3;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(j == n - 1)  printf("%d\n", c[i][j] % 3);
				else printf("%d ", c[i][j] % 3);
			}
		}
	}
	return 0;
}
