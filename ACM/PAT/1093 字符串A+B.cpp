#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    string out;
    bool find;
    getline(cin, a);
    getline(cin, b);
    a += b;
    for (int i = 0; i < a.length(); i++)
    {
        find = false;
        for (int j = 0; j < out.length(); j++)
        {
            if (out[j] == a[i])
            {
                find = true;
                break;
            }
        }
        if (!find)
            out.append(1, a[i]);
    }
    cout << out << endl;
    return 0;
}
