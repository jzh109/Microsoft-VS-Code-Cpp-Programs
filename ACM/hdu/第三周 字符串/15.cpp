#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1},N = 4e5;
int fac[]={1,1,2,6,24,120,720,5040,40320};
vector<char> path[N];
bool vis[N];
struct node{
    int a[9],loc,cantor;
    vector<char> path;
};

int Cantor(int *s,int n){///¿µÍÐÕ¹¿ª
    int sum=0;
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=i+1;j<9;j++)
            if(s[j]<s[i])num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum+1;
}

char dir[] = "durl";

void bfs()
{
    memset(vis,0, sizeof(vis));
    queue<node> q; node cur,nxt;
    for(int i = 0; i < 8; ++i) cur.a[i] = i+1;
    cur.a[8] = 0; cur.loc = 8;
    cur.cantor = 46234;//12356780 hash
    q.push(cur);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int tx = cur.loc/3+dx[i];
            int ty = cur.loc%3+dy[i];
            int tz = tx*3 + ty;
            if(tz >= 0 && tx < 3 && ty >= 0 && ty < 3  && tx >= 0){
                nxt = cur;
                nxt.loc = tz;
                nxt.a[cur.loc] = nxt.a[nxt.loc];
                nxt.a[nxt.loc] = 0;
                nxt.cantor = Cantor(nxt.a,9);
                if(!vis[nxt.cantor]){
                    vis[nxt.cantor] = true;
                    nxt.path.push_back(dir[i]);
                    q.push(nxt);
                    path[nxt.cantor] = nxt.path;
                }
            }
        }
    }
}

int main()
{
    char x;
    bfs();
    while(~scanf(" %c",&x))
    {
        node cur;
        if(x=='x') cur.a[0] = 0;
        else cur.a[0] = x-'0';
        for(int i = 1; i <= 8; ++i){
            scanf(" %c",&x);
            if(x=='x') cur.a[i] = 0;
            else cur.a[i] = x-'0';
        }
        cur.cantor = Cantor(cur.a,9);
        if(vis[cur.cantor]==0) printf("unsolvable");
        else {
            for(int i = path[cur.cantor].size()-1; i >= 0; --i)
                printf("%c",path[cur.cantor][i]);
        };
        puts("");
    }
    return 0;
}
