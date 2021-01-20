#include <stdio.h>

int main () {
	int max, min, temp, a, b, mul;
	
	scanf ("%d %d", &a, &b);
	max = a > b ? a: b;
	min = a < b ? a: b;
	mul = a * b;
	
	while (max % min ) {
		temp = min;
		min = max % min;
		max = temp;
	}
	
	printf ("GCD of them is %d\nLCM of them is %d\n", min, mul / min);
	
	return 0;
}
