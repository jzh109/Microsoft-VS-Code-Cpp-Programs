#include <iostream>
using namespace std;
int oneplus(int num, int numsys = 10)
{
    int res = 0;
    do
    {
        res += num % numsys;
        num = num / numsys;
    } while (num != 0);
    return res;
}
int main(void)
{
    int ten, twelve, sixteen;
    for (int i = 2991; i < 10000; i++)
    {
        ten = oneplus(i);
        twelve = oneplus(i, 12);
        sixteen = oneplus(i, 16);
        if (ten == twelve && twelve == sixteen)
        {
            cout << i << endl;
        }
    }
    return 0;
}