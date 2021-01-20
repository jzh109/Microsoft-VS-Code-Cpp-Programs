#include <stdio.h>
#include <string.h>

unsigned f(unsigned x, unsigned* a) {
	if(x < 10)  return x;
	return a[0]*f(x-1,a)+a[1]*f(x-2,a)+a[2]*f(x-3,a)
		+a[3]*f(x-4,a)+a[4]*f(x-5,a)+a[5]*f(x-6,a)
		+a[6]*f(x-7,a)+a[7]*f(x-8,a)+a[8]*f(x-9,a)+a[9]*f(x-10,a);
}

int main() {
	unsigned m, k, a[12];
	while(~scanf("%d%d", &k, &m)) {
		for(int i = 0; i < 10; i++) scanf("%d", &a[i]);
		unsigned res = f(k, a);
		printf("%d\n", res % m);
	}
	return 0;
}
