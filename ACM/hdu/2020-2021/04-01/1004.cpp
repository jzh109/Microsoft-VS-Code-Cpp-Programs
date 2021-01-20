#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    map<string, int> m;
    int n, maxx = -1;
    while (cin >> n, n)
    {
        m.clear();
        maxx = -1;
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            m[temp]++;
            maxx = max(maxx, m[temp]);
        }
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if (it->second == maxx)
            {
                cout << it->first << endl;
                break;
            }
        }
    }
}