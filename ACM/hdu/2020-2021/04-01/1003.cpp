#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b)
    {
        vector<int> v;
        v.clear();
        for (int i = a; i <= b; i++)
        {
            int x = i - i / 10 * 10;
            int y = (i - i / 100 * 100) / 10;
            int z = i / 100;
            if (x * x * x + y * y * y + z * z * z == i)
                v.push_back(i);
        }
        if (v.size() == 0)
        {
            cout << "no" << endl;
            continue;
        }
        for (int i = 0; i < v.size() - 1; i++)
            cout << v[i] << " ";
        cout << v[v.size() - 1] << endl;
    }
}