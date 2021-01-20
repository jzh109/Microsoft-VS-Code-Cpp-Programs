#include <stdio.h>

int main(){
	int n, m, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(n == 1) {
			printf("0\n");
			continue;
		}
		else if(n == 2) {
			printf("%d\n", m);
		}
		else {
			printf("%d\n", 2 * m);
		}
	}
	return 0;
}
