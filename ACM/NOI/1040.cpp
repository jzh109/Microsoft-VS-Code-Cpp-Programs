#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if(a < b)   swap(a, b);
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long res = gcd(a, b);
	if(res == 1) printf("No\n");
	else if(a % (b / res) == 0)	printf("Yes\n");
	else    printf("No\n");
	return 0;
}
