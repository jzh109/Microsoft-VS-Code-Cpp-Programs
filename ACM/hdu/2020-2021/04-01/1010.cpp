#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char s[10005] = {0};
    while (cin >> s)
    {
        sort(s, s + strlen(s));
        for (int i = 0; i < strlen(s) - 1; i++)
            cout << s[i] << " ";
        cout << s[strlen(s) - 1] << endl;
    }
}