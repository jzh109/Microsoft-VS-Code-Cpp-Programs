#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        string a1, b1, user, ans, a, b, temp;
        bool get = false;
        char e;
        getline(cin, a1);
        do
        {
            getline(cin, temp);
            user += temp + '\n';
            getline(cin, b1);
        } while (b1 != "END");
        getline(cin, a1);
        do
        {

            getline(cin, temp);
            ans += temp + '\n';
            getline(cin, b1);
        } while (b1 != "END");
        for (int i = 0; i < user.size(); i++)
        {
            if (user[i] != '\t' && user[i] != '\n' && user[i] != ' ')
            {
                a += user[i];
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] != '\t' && ans[i] != '\n' && ans[i] != ' ')
            {
                b += ans[i];
            }
        }
        int len = a.size() > b.size() ? a.size() : b.size();
        for (int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
            {
                cout << "Wrong Answer" << endl;
                get = true;
                break;
            }
        }
        if (get)
            continue;
        len = user.size() > ans.size() ? user.size() : ans.size();
        for (int i = 0; i < len; i++)
        {
            if (user[i] != ans[i])
            {
                cout << "Presentation Error" << endl;
                get = true;
                break;
            }
        }
        if (get)
            continue;
        cout << "Accept" << endl;
    }
    return 0;
}