#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    while (getline(cin, s), s != "")
    {
        for (char c : s)
        {
            if (isalpha(c))
                putchar(tolower(c));
            else
                putchar(c);
        }
        cout << endl;
    }
    return 0;
}