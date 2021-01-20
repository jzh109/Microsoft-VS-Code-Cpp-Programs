#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>
#define N 505
using namespace std;
__int64 num[N * N];
int mybinary_search(int len, int target)
{
    int L, R, mid = 0;
    L = 0;
    R = len - 1;
    while (L <= R)
    {
        mid = (L + R) >> 1;
        if (num[mid] > target)
            R = mid - 1;
        else if (num[mid] < target)
            L = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int i, j, k, l, n, m, query, cnt1, cnt2;
    int a, b, c, flag;
    int aa[505], bb[505], cc[505];
    cnt2 = 0;
    while (scanf("%d%d%d", &l, &m, &n) != EOF)
    {
        cnt1 = 0;
        for (i = 0; i < l; i++)
            scanf("%d", &aa[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &bb[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &cc[i]);
        for (i = 0; i < l; i++)
            for (j = 0; j < m; j++)
                num[cnt1++] = aa[i] + bb[j];
        sort(num, num + cnt1);
        sort(cc, cc + n);
        scanf("%d", &k);
        printf("Case %d:\n", ++cnt2);
        while (k--)
        {
            scanf("%d", &query);
            flag = 0;
            if (query < num[0] + cc[0] || query > num[cnt1 - 1] + cc[n - 1])
            {
                printf("NO\n");
                continue;
            }
            for (j = 0; j < n; j++)
            {
                if (mybinary_search(cnt1, query - cc[j]) != -1)
                {
                    printf("YES\n");
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                printf("NO\n");
        }
    }

    return 0;
}