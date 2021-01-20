#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    string str;
    getline(cin, str);
    for (unsigned i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}