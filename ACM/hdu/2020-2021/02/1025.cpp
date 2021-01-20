#include <bits/stdc++.h>
using namespace std;

bool isCircle(int a)
{
    string s = to_string(a);
    int head = 0, tail = s.length() - 1;
    while (head <= tail)
    {
        if (s[head] != s[tail])
            return false;
        head++;
        tail--;
    }
    return true;
}

int add(int a)
{
    string s = to_string(a);
    reverse(s.begin(), s.end());
    istringstream stream(s);
    int b;
    stream >> b;
    return a + b;
}

int main(void)
{
    int a;
    while (cin >> a)
    {
        vector<int> v;
        v.clear();
        do
        {
            v.push_back(a);
            a = add(a);
        } while (!isCircle(a));
        v.push_back(a);
        cout << v.size() - 1 << endl;
        for (int i = 0; i < v.size() - 1; i++)
            cout << v[i] << "--->";
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}