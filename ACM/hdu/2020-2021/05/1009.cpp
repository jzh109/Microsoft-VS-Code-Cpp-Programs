#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        string s;
        bool j = true;
        getline(cin, s);
        if (!(isalpha(s[0]) || s[0] == '_'))
        {
            cout << "no" << endl;
            continue;
        }
        for (int i = 1; i < s.length(); i++)
        {
            if (!(isdigit(s[i]) || isalpha(s[i]) || s[i] == '_'))
            {
                cout << "no" << endl;
                j = false;
                break;
            }
        }
        if (!j)
            continue;
        cout << "yes" << endl;
    }
    return 0;
}