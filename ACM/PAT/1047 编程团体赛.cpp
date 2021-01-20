#include <bits/stdc++.h>
using namespace std;

typedef struct TEAM
{
    int team;
    int score = 0;
    bool operator<(const TEAM &a) const
    {
        return score > a.score;
    }
} Team;

int main(int argc, char const *argv[])
{
    int n, cnt = 0;
    bool find;
    Team team[10005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        find = false;
        int temp;
        cin >> temp;
        for (int j = 0; j < cnt; j++)
        {
            if (team[j].team == temp)
            {
                find = true;
                cin >> temp;
                cin >> temp;
                team[j].score += temp;
                break;
            }
        }
        if (!find)
        {
            team[cnt].team = temp;
            cin >> temp;
            cin >> temp;
            team[cnt].score += temp;
            cnt++;
        }
    }
    sort(team, team + cnt);
    cout << team[0].team << " " << team[0].score << endl;
    return 0;
}
