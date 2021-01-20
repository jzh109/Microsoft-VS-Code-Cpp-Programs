#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[1005] = {-1}, n;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, num = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    bool positive = true, find = false;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 10 == 0)
            a1 += a[i];
        else if (a[i] % 5 == 1)
        {
            find = true;
            if (positive)
            {
                a2 = a2 + a[i];
                positive = false;
            }
            else
            {
                a2 = a2 - a[i];
                positive = true;
            }
        }
        else if (a[i] % 5 == 2)
            a3++;
        else if (a[i] % 5 == 3)
        {
            a4 += a[i];
            num++;
        }
        else if (a[i] % 5 == 4)
            pq.push(a[i]);
    }
    if (a1 != 0)
        cout << a1 << " ";
    else
        cout << "N ";
    if (a2 != 0 || find) //交错数列的和可能为0
        cout << a2 << " ";
    else
        cout << "N ";
    if (a3 != 0)
        cout << a3 << " ";
    else
        cout << "N ";
    if (a4 != 0 && num != 0)
        printf("%.1f ", (double)a4 / num);
    else
        cout << "N ";
    if (!pq.empty())
        cout << pq.top() << endl;
    else
        cout << "N" << endl;
    return 0;
}
