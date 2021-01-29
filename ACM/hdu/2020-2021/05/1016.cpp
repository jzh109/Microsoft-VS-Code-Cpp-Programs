#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s, ss;
    map<string, string> dic;
    dic.clear();
    cin >> s;
    while (cin >> s, s != "END")
    {
        cin >> ss;
        dic[ss] = s;
    }
    cin >> s;
    getchar();
    while (true)
    {
        getline(cin, s);
        if (s == "END")
            break;
        int from = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!isalpha(s[i]))
            {
                string temp = s.substr(from, i - from);
                string temp1 = dic[s.substr(from, i - from)];
                if (dic[s.substr(from, i - from)] != "")
                    cout << dic[s.substr(from, i - from)];
                else
                    cout << s.substr(from, i - from);
                while (!isalpha(s[i]) && i < s.length())
                {
                    cout << s[i];
                    i++;
                    from = i;
                }
            }
        }
        cout << endl;
    }
    return 0;
}