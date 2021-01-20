#include <iostream>
using namespace std;

int main()
{
    int a;
    while (cin >> a)
    {
        if (a > 100 || a < 0)
            cout << "Score is error!" << endl;
        else if (a >= 90)
            cout << "A" << endl;
        else if (a >= 80)
            cout << "B" << endl;
        else if (a >= 70)
            cout << "C" << endl;
        else if (a >= 60)
            cout << "D" << endl;
        else
            cout << "E" << endl;
    }
}