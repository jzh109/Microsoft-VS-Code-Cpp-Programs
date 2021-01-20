#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m[10] = {0};
    bool flag = false;
    for (int i = 0; i < 10; i++)
        cin >> m[i];
    for (int i = 1; i < 10; i++)
        if (m[i] != 0)
        {
            cout << i;
            m[i]--;
            flag = true;
            break;
        }
    if (!flag)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < m[i]; j++)
            cout << i;
    cout << endl;
    return 0;
}