#include <bits/stdc++.h>
using namespace std;

typedef struct NODE
{
    string a; //orgian
    string b; //sorted
} Node;

int main(int argc, char *argv[])
{
    string s;
    vector<Node> v;
    v.clear();
    while (cin >> s, s != "XXXXXX")
    {
        Node node;
        node.a = s;
        sort(s.begin(), s.end());
        node.b = s;
        v.push_back(node);
    }
    while (cin >> s, s != "XXXXXX")
    {
        sort(s.begin(), s.end());
        set<string> res;
        res.clear();
        for (Node n : v)
            if (n.b == s)
                res.insert(n.a);
        if (res.empty())
            cout << "NOT A VALID WORD" << endl;
        else
            for (string temp : res)
                cout << temp << endl;
        cout << "******" << endl;
    }
    return 0;
}