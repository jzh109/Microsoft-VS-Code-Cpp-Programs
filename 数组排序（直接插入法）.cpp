#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10], b, n, i, j, k;
	printf("Enter the number of the numbers(It must be inferior to 10):");
	scanf("%d", &n);
	printf("Enter the series:");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		printf("%-4d", a[i]);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		b = a[i];
		for (j = 0; (a[j] > a[i]) && (j < i); j++)
			;
		for (k = i; k > j; k--)
			a[k] = a[k - 1];

		a[j] = b;
		for (int m = 0; m < n; m++)
			printf("%-4d", a[m]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("%-4d", a[i]);
	printf("\n");
	system("pause");
}
