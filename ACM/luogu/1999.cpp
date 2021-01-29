#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int up = 1, down = 1;
    bool a = false;
    cin >> n;
    while (--n)
    {
        if (up == 1 && !a)
        {
            a = true;
            down++;
        }
        else if (down == 1 && a)
        {
            a = false;
            up++;
        }
        else if (!a)
        {
            up--;
            down++;
        }
        else
        {
            up++;
            down--;
        }
    }
    cout << up << "/" << down << endl;
    return 0;
}