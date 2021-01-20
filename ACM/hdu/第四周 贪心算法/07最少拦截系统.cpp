#include <stdio.h>
#include <string.h>

int main() {
	int n, a[30005], b[30005];
	const int INF = 0x3f3f3f;
	while(scanf("%d", &n) != EOF) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int res = 0, count = 0;
		for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
		for(int i = 0; i < n; i++) {
			int minh = INF, index = -1;
			for(int j = 0; j < count; j++) {
				if(b[j] >= a[i] && minh > b[j] - a[i]) {
					minh = b[j] - a[i];
					index = j;
				}
			}
			if(index == -1) {
				count++;
				b[count - 1] = a[i];
				res++;
			}
			else {
				b[index] = a[i];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
