#include <math.h>
#include <stdio.h>
int main()
{
    int x, y;
    while (1)
    {
        scanf("%d%d", &x, &y);
        if (x == 0 && y == 0)
            return 0;
        else
        {
            int n = x;
            int ok = 1;
            for (; n <= y; n++)
            {
                int m = n * n + n + 41;
                int p;
                for (p = 2; p <= sqrt(m); p++)
                {
                    int z;
                    z = m % p;
                    if (z == 0)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok)
                printf("OK\n");
            else
                printf("Sorry\n");
        }
    }
}