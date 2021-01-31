#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef struct NODE
{
    int s[9];                //表示当前图的结构，形式与sample input相同
    int current, cantor_val; //cur表示当前x的索引号(从0开始)，n表示当前node的康托展开值
    int f, g, h;             //f代价，g为实际代价，h为预估代价（曼哈顿距离）

    bool operator<(const NODE &a) const //重载操作符
    {
        return f == a.f ? g > a.g : f > a.f;
    }
} Node;

const char dir[] = "dulr";                                         //next_position[]一一对应
const int next_position[][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; //与dir[]一一对应
const int maxn = 363000;
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; //0-9的阶乘
bool vis[maxn] = {false};
int pre[maxn] = {0};
char path[maxn] = {0};

int cantor(const int s[])
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++)
            if (s[j] < s[i])
                cnt++;
        sum += cnt * fac[9 - i - 1];
    }
    return sum;
}
int getval(const int s[]) //曼哈顿距离
{
    int val = 0;
    int x, y, tx, ty;
    for (int i = 0; i < 9; i++)
    {
        x = i / 3; //转换成二维坐标
        y = i % 3; //当前格坐标（位置坐标）
        tx = (s[i] - 1) / 3;
        ty = (s[i] - 1) % 3; //最终坐标

        val += abs(x - tx) + abs(y - ty); //该状态节点与最终态的全部曼哈顿距离
    }
    return val;
}

void printans(int n)
{
    if (pre[n])
    {
        printans(pre[n]); //递归调用显示路径
        printf("%c", path[n]);
    }
}
void AStar(Node start)
{
    memset(vis, false, sizeof(vis));
    priority_queue<Node> q;
    q.push(start);
    vis[start.cantor_val] = true;
    pre[start.cantor_val] = 0; //创建printans递归终点
    const int ans = 0;
    while (!q.empty()) //BFS
    {
        Node now = q.top();
        q.pop();
        if (now.cantor_val == ans) //已经到达最终态{1,2,3,4,5,6,7,8,9(x)}，康托展开值为0
        {
            printans(ans);
            printf("\n");
            return;
        }
        int x = now.current / 3, y = now.current % 3; //当前x的坐标
        for (int p = 0; p < 4; p++)
        {
            int tx = next_position[p][0] + x, ty = next_position[p][1] + y;
            if (tx < 0 || ty < 0 || tx > 2 || ty > 2) //判断是否越界
                continue;

            Node temp = now;
            temp.current = tx * 3 + ty;                      //更新x索引号
            swap(temp.s[now.current], temp.s[temp.current]); //交换图中x的位置
            temp.cantor_val = cantor(temp.s);                //计算更新之后的康托展开值

            if (vis[temp.cantor_val]) //如果曾将到达过此状态（根据康托展开值）
                continue;             //跳过

            vis[temp.cantor_val] = true;           //此状态已经被搜索过
            pre[temp.cantor_val] = now.cantor_val; //记录上一个状态节点
            path[temp.cantor_val] = dir[p];        //记录操作

            temp.g++;                 //实际代价自增
            temp.h = getval(temp.s);  //更新状态之后的曼哈顿距离
            temp.f = temp.g + temp.h; //更新状态的代价

            q.push(temp); //BFS
        }
    }
}
int main(int argc, char *argv[])
{
    char ch;
    Node *start = new Node;
    while (scanf(" %c", &ch) != EOF)
    {
        if (ch == 'x')
            ch = '9', start->current = 0;
        start->s[0] = ch - '0';
        for (int i = 1; i < 9; i++)
        {
            scanf(" %c", &ch);
            if (ch == 'x')
                ch = '9', start->current = i;
            start->s[i] = ch - '0';
        } //读入数据，记录初始状态下x的索引号

        start->cantor_val = cantor(start->s);
        start->g = 0;
        start->h = getval(start->s);
        start->f = start->g + start->h;

        int cnt = 0;
        for (int i = 0; i < 8; i++)
        {
            if (start->s[i] != 9)
                for (int j = i + 1; j < 9; j++)
                    if (start->s[j] < start->s[i])
                        cnt++;
        } //判断是否可解，可利用特殊情况得出不可解的条件（cnt为奇数）

        if (cnt & 1)
            printf("unsolvable\n");
        else
            AStar(*start);
    }
    return 0;
}