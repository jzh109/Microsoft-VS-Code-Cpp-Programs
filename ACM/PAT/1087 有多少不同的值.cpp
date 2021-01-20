#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    set<int> s;
    s.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp = i / 2 + i / 3 + i / 5;
        s.insert(temp);
    }
    cout << s.size() << endl;
    return 0;
}
