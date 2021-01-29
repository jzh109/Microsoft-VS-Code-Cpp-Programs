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
        getline(cin, s);
        int from = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + from, s.begin() + i);
                from = i + 1;
            }
        }
        reverse(s.begin() + from, s.end());
        cout << s << endl;
    }
    return 0;
}