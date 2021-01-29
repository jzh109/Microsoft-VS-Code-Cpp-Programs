#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    string temp;
    while (cin >> n)
    {
        map<string, int> ma;
        ma.clear();
        for (int i = 0; i < n; i++)
            cin >> temp;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, res = 1;
            for (int j = 0; j < n; j++)
            {
                cin >> a >> temp;
                ma[temp] += a;
            }
            for (map<string, int>::iterator it = ma.begin(); it != ma.end(); it++)
                if (it->second > ma["memory"])
                    res++;
            cout << res << endl;
        }
    }
    return 0;
}