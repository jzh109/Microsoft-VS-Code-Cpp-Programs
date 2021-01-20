#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n, n)
    {
        int temp;
        map<int, int> m;
        m.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if (it->second == 1)
            {
                cout << it->first << endl;
                break;
            }
        }
    }
}