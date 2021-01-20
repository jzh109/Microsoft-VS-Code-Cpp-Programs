#include <stdio.h>

long long fast(int a, int n){
	long long res = 1;
	while(n){
		if(n & 1)   res = res * a % 10;
		n >>= 1;
		a = a * a % 10;
	}
	return res;
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%lld\n", fast(a, b));
	return 0;
}
