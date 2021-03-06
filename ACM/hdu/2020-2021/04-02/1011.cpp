#include <iostream>
using namespace std;

int main()
{
    int a, b, n;
    while (cin >> a >> b >> n)
    {
        if (!a && !b && !n)
            break;
        int arr[48];
        arr[1] = 1;
        arr[2] = 1;
        for (int i = 3; i < 48; i++)
            arr[i] = (a * arr[i - 1] + b * arr[i - 2]) % 7;
        cout << arr[n % 48] << endl;
    }
    return 0;
}
