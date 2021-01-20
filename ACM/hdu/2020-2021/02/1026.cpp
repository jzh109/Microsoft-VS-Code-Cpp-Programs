#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int r1, r2, r3, m1, m2;
    string s;
    while (cin >> m1 >> m2)
    {
        cin >> s;
        r1 = r2 = r3 = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            switch (c)
            {
            case 'A':
                r1 = m1;
                break;
            case 'B':
                r2 = m2;
                break;
            case 'C':
                m1 = r3;
                break;
            case 'D':
                m2 = r3;
                break;
            case 'E':
                r3 = r1 + r2;
                break;
            case 'F':
                r3 = r1 - r2;
                break;
            }
        }
        cout << m1 << "," << m2 << endl;
    }
    return 0;
}