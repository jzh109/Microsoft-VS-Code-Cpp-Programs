#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	if(n == 0)  printf("0\n");
	else if(n & 1)   printf("%lld\n", (n + 1) / 2);
	else    printf("%lld\n", (n + 1) / 2 + 1);
	return 0;
}
