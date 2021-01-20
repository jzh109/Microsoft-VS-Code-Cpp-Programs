#include <iostream>
#include <stack>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

char s[55];

int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while (T--)
    {
        stack<char> st;
        scanf("%d", &n);
        scanf("%s", s);
        int len = strlen(s);
        int cnt = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (!st.empty())
                st.pop(), cnt++;
        }
        printf("%d\n", (len - cnt * 2) / 2);
    }
}