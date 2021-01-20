#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> m;
    int n, k;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    cin >> k;
    while (--k > 0)
    {
        int a;
        cin >> a;
        cout << m[a] << " ";
    }
    int a;
    cin >> a;
    cout << m[a];
    cout << endl;
    return 0;
}