#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    char res[105] = {0};
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
        {
            string temp;
            cin >> temp;
            if (temp[2] == 'T')
            {
                res[cnt++] = temp[0] - 16;
            }
        }
    res[cnt] = 0;
    cout << res << endl;
    return 0;
}
