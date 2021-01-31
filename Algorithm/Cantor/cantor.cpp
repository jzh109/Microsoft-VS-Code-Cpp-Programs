#include <bits/stdc++.h>
using namespace std;

int cantor(int n)
{
    const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; //阶乘预处理
    stringstream ss;
    ss << n;
    string s = ss.str();
    int num = s.length(), x = 0, temp;
    for (int i = 0; i < num; i++)
    {
        temp = 0;
        for (int j = i + 1; j < num; j++)
            if (s[i] > s[j])
                temp++;
        x += temp * factorial[num - i - 1];
    }
    return x + 1;
}

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;
    cout << cantor(n) << endl;

    return 0;
}