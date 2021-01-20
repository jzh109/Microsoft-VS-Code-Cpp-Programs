#include <iostream>
#include <vector>
using namespace std;

void BSearch(int *a, int n, int res)
{
    int head = 0, tail = n - 1;
    int mid = (head + tail) / 2;
    vector<int> v;
    bool find = false;
    while (head <= tail)
    {
        //cout << a[mid] << endl;
        v.push_back(a[mid]);
        if (a[mid] == res)
        {
            cout << mid << endl;
            find = true;
            break;
        }
        else if (a[mid] > res)
            tail = mid - 1;
        else
            head = mid + 1;
        mid = (head + tail) / 2;
    }
    //cout << mid << endl;
    if (!find)
        cout << "no" << endl;
    for (int t : v)
    {
        if (t != *(v.end() - 1))
            cout << t << ",";
        else
            cout << t << endl;
    }
}

void destory(int *a)
{
    delete a;
}

int main(int argc, char *argv[])
{
    int n, res;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        getchar();
    }
    cin >> res;
    BSearch(a, n, res);
    destory(a);
    return 0;
}
