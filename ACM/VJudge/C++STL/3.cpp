#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Person
{
    string name;
    string age;
    bool operator<(Person &other)
    {
        return age > other.age;
    }
} person[10005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin.get();
        for (int i = 0; i < n; i++)
        {
            person[i].name.clear();
            person[i].age.clear();
            string line, age;
            getline(cin, line);
            int len = line.size();
            for (int j = 0; j < 4; j++)
            {
                age += line[len - 1 - j];
            }
            reverse(age.begin(), age.end());
            person[i].age = age;
            line[len - 5] = '\0';
            int k = 0;
            while (line[k] != 0)
            {
                person[i].name += line[k];
                k++;
            }
        }
        sort(person, person + n);
        for (int i = 0; i < n; i++)
        {
            cout << person[i].name << endl;
        }
    }
    system("pause");
    return 0;
}