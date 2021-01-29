#include <bits/stdc++.h>
using namespace std;

int a = 0;

int main(int argc, char *argv[])
{
    if (a == 5)
        return 0;
    a++;
    main(argc, argv);
    cout << a << endl;
    return 0;
}