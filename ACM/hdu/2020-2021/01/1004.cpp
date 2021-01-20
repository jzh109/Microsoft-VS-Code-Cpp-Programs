#include <bits/stdc++.h>
using namespace std;

typedef struct SubjectType
{
    int deadline;
    int mark;
    bool isSelected;
} subject;

bool cmp(SubjectType a, SubjectType b)
{
    if (a.mark != b.mark)
        return a.mark > b.mark;
    return a.deadline < b.deadline;
}

int main()
{
    int dataCount, subjectCount;
    int i, j, k, flag[1001];
    subject arr[1001];
    scanf("%d", &dataCount);
    while (dataCount--)
    {
        memset(flag, 0, sizeof(flag));
        scanf("%d", &subjectCount);
        arr[0].deadline = 0;
        arr[0].mark = 0;
        arr[0].isSelected = false;
        for (i = 1; i <= subjectCount; i++)
        {
            scanf("%d", &arr[i].deadline);
            if (arr[i].deadline > flag[0])
                flag[0] = arr[i].deadline;
        }
        for (i = 1; i <= subjectCount; i++)
        {
            scanf("%d", &arr[i].mark);
            arr[i].isSelected = false;
        }
        sort(arr + 1, arr + subjectCount + 1, cmp);
        for (i = 1; i <= subjectCount; i++)
        {
            j = arr[i].deadline;
            while (j >= 1)
            {
                if (flag[j] != 0)
                    j--;
                else
                    break;
            }
            if (j == 0)
                continue;
            flag[j] = i;
        }
        for (i = 1; i <= flag[0]; i++)
        {
            arr[flag[i]].isSelected = true;
        }
        int sum;
        sum = 0;
        for (i = 1; i <= subjectCount; i++)
        {
            if (!arr[i].isSelected)
                sum += arr[i].mark;
        }
        printf("%d\n", sum);
    }
    return 0;
}