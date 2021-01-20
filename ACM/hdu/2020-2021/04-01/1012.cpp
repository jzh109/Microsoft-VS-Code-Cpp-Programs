#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, string> m;
    m["A#"] = "Bb";
    m["C#"] = "Db";
    m["D#"] = "Eb";
    m["F#"] = "Gb";
    m["G#"] = "Ab";
    m["Bb"] = "A#";
    m["Db"] = "C#";
    m["Eb"] = "D#";
    m["Gb"] = "F#";
    m["Ab"] = "G#";
    string a, b;
    int i = 1;
    while (cin >> a >> b)
    {
        a = m[a];
        if (a == "")
            cout << "Case " << i++ << ": UNIQUE" << endl;
        else
            cout << "Case " << i++ << ": " << a << " " << b << endl;
    }
    return 0;
}
