#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
	int n, j = 0;
	char a[1005];
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	gets(a);
	for(int i = 0; i < strlen(a); i++)  a[i] -= '0';
	for(int i = strlen(a) - 1; i >=0 ; i--, j++) {
		if(a[j] == 0 && i) continue;
		if(i == 1 && a[strlen(a) - 1] == 0) printf("%d*%d^%d\n", a[j], n, i);
		else if(i)	printf("%d*%d^%d+", a[j], n, i);
		else    printf("%d*%d^%d\n", a[j], n, i);
	}
	return 0;
}
