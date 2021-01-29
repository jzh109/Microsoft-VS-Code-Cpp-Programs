#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, temp;
    set<int> s;
    set<int> res;
    vector<int> v;
    v.clear();
    s.clear();
    res.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
        s.insert(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            s.insert(v[i] + v[j]);
            if (s.size() == n)
                res.insert(v[i] + v[j]);
            else
                s.erase(v[i] + v[j]);
        }
    }
    cout << res.size() << endl;
    return 0;
}