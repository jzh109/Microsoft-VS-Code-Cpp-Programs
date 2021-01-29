#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        int n = 0;
        string s;
        getline(cin, s);
        for (char c : s)
            if (isdigit(c))
                n++;
        cout << n << endl;
    }
    return 0;
}