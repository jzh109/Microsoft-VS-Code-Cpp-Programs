#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    string a;
    map<string, int> b;
    while (true)
    {
        getline(cin, a);
        if (a != "")
            for (int i = 1; i <= a.length(); i++)
                b[a.substr(0, i)]++;
        else
            break;
    }
    while (cin >> a)
        cout << b[a] << endl;
    return 0;
}