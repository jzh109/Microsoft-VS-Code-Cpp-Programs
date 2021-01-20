#include <cstdio>

long long fast(int a, int n){
	long long res = 1;
	while(n) {
		if(n & 1)   res = res * a;
		n >>= 1;
		a = a * a;
	}
	return res;
}

int main () {
	int n;
	scanf("%d", &n);
	printf("%lld\n", fast(2, n));
	return 0;
}
