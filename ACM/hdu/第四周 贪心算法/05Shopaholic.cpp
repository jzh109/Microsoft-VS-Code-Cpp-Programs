#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int a[20005], n, t;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &n);
			for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			sort(a, a + n);
			reverse(a, a + n);
			int res = 0;
			for(int  i = 0; i < n; i++) {
				if(i % 3 == 2) {
					res += a[i];
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
