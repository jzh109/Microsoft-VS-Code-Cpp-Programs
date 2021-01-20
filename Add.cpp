#include <stdio.h>
#include <stdlib.h>

void init(int a[], int n)
{
    int i;
    for (i = n; i < 30; i++)
        a[i] = 1;
}

int main()
{
    int n, a[30], count, col = 0, i, k = 0;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1=1\n");
        return 0;
    }
    count = n;
    init(a, 0);
    while (count != 1)
    {
        while (a[1] != 1 && count >= 2)
        {
            a[0]++;
            a[1]--;
        }
        do
        {
            printf("%d=", n);
            for (i = count - 1; i >= 0; i--)
            {
                if (i != 0)
                {
                    printf("%d+", a[i]);
                }
                else
                {
                    printf("%d", a[i]);
                }
            }
            if (col != 3)
            {
                col = (++col % 4);
                printf(";");
            }
            else
            {
                col = (++col % 4);
                printf("\n");
            }
            if (a[0] - 1 > a[1])
            {
                a[1]++;
                a[0]--;
            }
            else
                break;
        } while (1);
        a[0]++;
        init(a, ++k);
        count--;
    }
    printf("%d=%d\n", n, n);
    system("pause");
    return 0;
}