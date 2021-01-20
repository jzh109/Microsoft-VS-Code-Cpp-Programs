#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t, n, from, to;
    cin >> t;
    while (t--)
    {
        map<int, int> m;
        m.clear();
        int res = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> from >> to;
            if (from > to)
                swap(from, to);
            for (int j = (from + 1) / 2; j <= (to + 1) / 2; j++)
                m[j]++;
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            res = max(it->second, res);
        printf("%d\n", res * 10);
    }
}