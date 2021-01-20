#include <stdio.h>
#include <string.h>

int main() {
	int n, a, b, x, y;
	bool findx = false;
	scanf("%d", &n);
	for(a = 1; a < 10; a++) {
		for(b = 1; b < 10; b++) {
			x = a * 10 + b;
			y = b * 10 + a;
			if(x * y == n) {
				findx = true;
				break;
			}
		}
		if(findx)   break;
	}
	if(findx)   printf("%d%d\n",a,b);
	else    printf("No Answer\n");
	return 0;
}
