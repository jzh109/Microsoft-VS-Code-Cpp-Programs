#include <cstdio>
using namespace std;

int main()
{
    int n, temp;
    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            res += temp;
        }
        printf("%d\n", res);
    }
}