#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n, n)
    {
        map<int, int> m;
        m.clear();
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            m[temp]++;
        }
        int r;
        cin >> r;
        cout << m[r] << endl;
    }
    return 0;
}