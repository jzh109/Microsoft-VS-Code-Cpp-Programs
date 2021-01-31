#include <bits/stdc++.h>
using namespace std;

int anti_cantor(int n, vector<int> v)
{
    const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; //阶乘预处理
    int num = v.size();
    stringstream ss;
    string s;
    n--;
    for (int i = 0; i < num; i++)
    {
        int temp = n / factorial[num - i - 1];
        n %= factorial[num - 1 - i];
        ss << v[temp];
        s = ss.str();
        v.erase(v.begin() + temp);
    }
    return atoi(ss.str().c_str());
}

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, temp;
    vector<int> vec;
    vec.clear();

    cout << "input index: ";
    cin >> n;
    cout << "input set, end with -1:" << endl;
    while (cin >> temp, temp != -1)
        vec.push_back(temp);
    sort(vec.begin(), vec.end());

    cout << anti_cantor(n, vec) << endl;
    return 0;
}