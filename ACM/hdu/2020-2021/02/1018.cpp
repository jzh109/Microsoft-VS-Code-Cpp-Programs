#include <stdio.h>
#include <stdlib.h>

int ifisleap(int year);
int main()
{
    int year, month, day;
    int sum;
    int i;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d-%d-%d", &year, &month, &day);
        sum = 0;
        if ((month == 2) && (day == 29))
        {
            if (!ifisleap(year + 18))
                sum = -1;
            else
            {
                for (i = 1; i <= 17; i++)
                {
                    if (ifisleap(year + i))
                        sum = sum + 366;
                    else
                        sum = sum + 365;
                }
                sum = sum + 366;
            }
        }
        else
        {
            for (i = 1; i <= 17; i++)
            {
                if (ifisleap(year + i))
                    sum = sum + 366;
                else
                    sum = sum + 365;
            }
            if (month >= 3)
            {
                if (ifisleap(year + 18))
                    sum = sum + 366;
                else
                    sum = sum + 365;
            }
            else
            {
                if (ifisleap(year))
                    sum = sum + 366;
                else
                    sum = sum + 365;
            }
        }
        printf("%d\n", sum);
    }

    getchar();
    getchar();
    return 0;
}
int ifisleap(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    else
        return 0;
}