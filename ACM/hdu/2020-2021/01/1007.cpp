// #include <stdio.h>
// int main()
// {
//     int n, m[30010], p, i, j, len;
//     while (~scanf("%d", &n))
//     {
//         for (len = 0, i = 0; i < n; i++)
//         {
//             scanf("%d", &m[len]);
//             for (j = 0; j < len; j++)
//                 if (m[len] < m[j])
//                     break;
//             m[j] = m[len];
//             if (j == len)
//                 len++;
//         }
//         printf("%d\n", len);
//     }
//     return 0;
// }

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[105];
int main()
{
    int n;
    while (cin >> n)
    {
        int x;
        int cnt = 1;
        bool flag = false;
        cin >> a[0];
        for (int i = 1; i < n; i++)
        {
            flag = false;
            cin >> x;
            for (int j = 0; j < cnt; j++)
            {
                if (a[j] > x)
                {
                    a[j] = x;
                    //a[j]以后能发射的最大高度
                    flag = true;
                    break;
                }
            }
            if (!flag) //没有找到，选新系统
                a[cnt++] = x;
        }
        cout << cnt << endl;
    }
    return 0;
}