#include <stdio.h>
#include <math.h>

const double m = sqrt(2) + sqrt(3);

int fast(int a, long n) {
	int res = 1;
	while(n) {
		if(n & 1)   res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res % 1024;
}

int main() {
	long n, t;
	scanf("%ld", &t);
	while(t--){
		scanf("%ld", &n);
		printf("%d\n", fast(m, 2 * n));
	}	
	return 0;
}
