#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word;
    int count = 0;
    while (cin >> word)
    {
        if (word == "<br>")
        {
            cout << endl;
            count = 0;
        }
        else if (word == "<hr>")
        {
            if (!count)
                cout << "--------------------------------------------------------------------------------" << endl;
            else
            {
                cout << endl
                     << "--------------------------------------------------------------------------------" << endl;
            }
            count = 0;
        }
        else
        {
            if (!count)
            {
                count = word.size();
                cout << word;
            }
            else if (count + word.size() + 1 > 80)
            {
                cout << endl
                     << word;
                count = word.size();
            }
            else
            {
                cout << " " << word;
                count += word.size() + 1;
            }
        }
    }
    cout << endl;
    return 0;
}