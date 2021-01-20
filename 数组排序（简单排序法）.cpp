#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10], i, j, k, x, n;
	printf("Enter the number of the numbers\n(It must be inferior to 10):");
	scanf("%d", &n);
	printf("Enter the series:");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int m = 0; m < n; m++)
		printf("%-2d", a[m]);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i; j < n; j++)
			if (a[j] > a[k])
				k = j;
		if (i != k)
		{
			x = a[i];
			a[i] = a[k];
			a[k] = x;
		}
		// for (int m = 0; m < n; m++)
		// 	printf("%-2d", a[m]);
		// printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("%-2d", a[i]);
	system("pause");
}
