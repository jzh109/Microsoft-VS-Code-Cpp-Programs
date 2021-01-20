#include <iostream>
using namespace std;
int main()
{
    int n, a[121] = {0};
    a[0] = 1;
    for (int i = 1; i <= 120; i++)
        for (int j = 0; j < 121; j++)
            if (a[j] != 0 && i + j < 121)
                a[i + j] += a[j];
    while (scanf("%d", &n) != EOF)
        cout << a[n] << endl;
    return 0;
}