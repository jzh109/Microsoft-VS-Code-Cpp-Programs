#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

int main()
{
    map<double, double> m;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "End with \"0 0\"." << endl;
    cout << "GP(top 5.0) SS" << endl;
    m.clear();
    double a, b, suma = 0.0, sumb = 0.0;
    while (scanf("%lf%lf", &a, &b) && (a || b))
    {
        m.insert(pair<double, double>(a, b));
    }
    for (map<double, double>::iterator it = m.begin(); it != m.end(); it++)
    {
        suma += (it->first * it->second);
        sumb += it->first;
    }
    cout << "Your GPA is: " << suma / sumb << endl;
    system("pause");
    return 0;
}