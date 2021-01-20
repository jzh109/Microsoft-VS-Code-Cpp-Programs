#include <bits/stdc++.h>
using namespace std;

bool judge(int a)
{
    return a > 0 && (a & (a - 1)) == 0;
}

int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        vector<int> v;
        cin >> a;
        if (judge(a))
        {
            cout << "No number can be output !" << endl;
            continue;
        }
        do
        {
            if (a & 1)
            {
                v.push_back(a);
                a = a * 3 + 1;
            }
            else
                a >>= 1;
        } while (!judge(a));
        for (int i = 0; i < v.size() - 1; i++)
            cout << v[i] << " ";
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}