#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string str1, str2;
    char a, b;
    int numa = 0, numb = 0, resa = 0, resb = 0;
    cin >> str1 >> a >> str2 >> b;
    for (int i = 0; i < str1.length(); i++)
        if (str1[i] == a)
            numa++;
    for (int i = 0; i < str2.length(); i++)
        if (str2[i] == b)
            numb++;
    for (size_t i = 0; i < numa && numa != 0; i++)
    {
        resa *= 10;
        resa += 1;
    }
    for (size_t i = 0; i < numb && numb != 0; i++)
    {
        resb *= 10;
        resb += 1;
    }
    cout << (resa * (a - '0') + resb * (b - '0')) << endl;
    return 0;
}
