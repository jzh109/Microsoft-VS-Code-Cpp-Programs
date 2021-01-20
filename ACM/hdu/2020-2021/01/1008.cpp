#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        map<int, int> m;
        m.clear();
        int temp, res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            m[temp]++;
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            res = max(res, it->second);
        printf("%d\n", res);
    }
    return 0;
}