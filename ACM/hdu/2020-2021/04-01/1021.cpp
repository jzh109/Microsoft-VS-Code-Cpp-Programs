#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    while (cin >> in)
    {
        getchar();
        if (in == "ENDOFINPUT")
            break;
        getline(cin, in);
        int n = in.length();
        for (int i = 0; i < n; i++)
            if (in[i] >= 'A' && in[i] <= 'Z')
                in[i] = in[i] - 5 >= 'A' ? in[i] - 5 : in[i] + 21;
        cout << in << endl;
        cin >> in;
    }
}