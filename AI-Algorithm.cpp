#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAPMAXSIZE 100                   //地图面积最大为 100x100
#define MAXINT 8192                      //定义一个最大整数, 地图上任意两点距离不会超过它
#define STACKSIZE 65536                  //保存搜索节点的堆栈大小
#define tile_num(x, y) ((y)*map_w + (x)) //将 x,y 坐标转换为地图上块的编号
#define tile_x(n) ((n) % map_w)          //由块编号得出 x,y 坐标
#define tile_y(n) ((n) / map_w)          // 树结构, 比较特殊, 是从叶节点向根节点反向链接

typedef struct node *TREE;

struct node
{
    int h;
    int tile;
    TREE father;
};
typedef struct node2 *LINK;

struct node2
{
    TREE node;
    int f;
    LINK next;
};
LINK queue;
// 保存没有处理的行走方法的节点
TREE stack[STACKSIZE];
// 保存已经处理过的节点 (搜索完后释放)
int stacktop;
char map[][6] = {
    {'x', 'x', 'x', 'x', 'x', 'x'},
    {'x', 'e', ' ', ' ', ' ', 'x'},
    {'x', 'x', ' ', 'x', ' ', 'x'},
    {'x', 'x', ' ', ' ', ' ', 'x'},
    {'x', 'x', 'x', 'x', 's', 'x'},
    {'x', 'x', 'x', 'x', 'x', 'x'}}; //地图数据

int dis_map[MAPMAXSIZE][MAPMAXSIZE]; //保存搜索路径时,中间目标地最优解
int map_w, map_h;                    //地图宽和高
int start_x, start_y, end_x, end_y;  //地点,终点坐标

void gotoxy(int x, int y)
{
    HANDLE a;
    COORD zb;
    zb.X = x - 1;
    zb.Y = y - 1;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a, zb);
}

// 初始化队列
void init_queue()
{
    queue = (LINK)malloc(sizeof(*queue));
    queue->node = NULL;
    queue->f = -1;
    queue->next = (LINK)
        malloc(sizeof(*queue));
    queue->next->f = MAXINT;
    queue->next->node = NULL;
    queue->next->next = NULL;
}

// 待处理节点入队列, 依靠对目的地估价距离插入排序
void enter_queue(TREE node, int f)
{
    LINK p = queue, father, q;
    while (f > p->f)
    {
        father = p;
        p = p->next;
        assert(p);
    }
    q = (LINK)malloc(sizeof(*q));
    assert(queue);
    q->f = f, q->node = node, q->next = p;
    father->next = q;
}

// 将离目的地估计最近的方案出队列
TREE get_from_queue()
{
    TREE bestchoice = queue->next->node;
    LINK next = queue->next->next;

    free(queue->next);
    queue->next = next;
    stack[stacktop++] = bestchoice;
    assert(stacktop < STACKSIZE);
    return bestchoice;
}

// 释放栈顶节点
void pop_stack()
{
    free(stack[--stacktop]);
}

// 释放申请过的所有节点
void freetree()
{
    int i;
    LINK p;
    for (i = 0; i < stacktop; i++)
        free(stack);
    while (queue)
    {
        p = queue;
        free(p->node);
        queue = queue->next;
        free(p);
    }
}

// 估价函数,估价 x,y 到目的地的距离,估计值必须保证比实际值小
int judge(int x, int y)
{
    int distance;
    distance = abs(end_x - x) + abs(end_y - y);
    return distance;
}

// 尝试下一步移动到 x,y 可行否
int trytile(int x, int y, TREE father)
{
    TREE p = father;
    int h;
    if (map[y][x] == 'x')
        return 1;
    // 如果 (x,y) 处是障碍,失败
    while (p)
    {
        if (x == tile_x(p->tile) && y == tile_y(p->tile))
            return 1;
        //如果 (x,y) 曾经经过,失败
        p = p->father;
    }
    h = father->h + 1;
    if (h >= dis_map[y][x])
        return 1;
    // 如果曾经有更好的方案移动到 (x,y) 失败
    dis_map[y][x] = h;
    // 记录这次到 (x,y) 的距离为历史最佳距离
    // 将这步方案记入待处理队列
    p = (TREE)malloc(sizeof(*p));
    p->father = father;
    p->h = father->h + 1;
    p->tile = tile_num(x, y);
    enter_queue(p, p->h + judge(x, y));
    return 0;
}

// 路径寻找主函数
void findpath(int *path)
{
    //printf("%d,%d,%d,%d",start_x,start_y,end_x,end_y);
    TREE root;
    int i, j;
    stacktop = 0;
    for (i = 0; i < map_h; i++)
        for (j = 0; j < map_w; j++)
            dis_map[i][j] = MAXINT;
    init_queue();
    root = (TREE)malloc(sizeof(*root));
    root->tile = tile_num(start_x, start_y);
    root->h = 0;
    root->father = NULL;
    enter_queue(root, judge(start_x, start_y));
    for (;;)
    {
        int x, y, child;
        TREE p;
        root = get_from_queue();
        if (root == NULL)
        {
            *path = -1;
            return;
        }
        x = tile_x(root->tile);
        y = tile_y(root->tile);
        if (x == end_x && y == end_y)
            break;
        // 达到目的地成功返回
        child = trytile(x, y - 1, root);
        //尝试向上移动
        child &= trytile(x, y + 1, root);
        //尝试向下移动
        child &= trytile(x - 1, y, root);
        //尝试向左移动
        child &= trytile(x + 1, y, root);
        //尝试向右移动
        if (child != 0)
            pop_stack();
        // 如果四个方向均不能移动,释放这个死节点
    } // 回溯树，将求出的最佳路径保存在 path[] 中
    for (i = 0; root; i++)
    {
        path[i] = root->tile;
        root = root->father;
        //printf("pathis %d",path[i]);
    }
    path[i] = -1;
    freetree();
}

void printpath(int *path)
{
    int i;
    //printf("-44444444444444");
    for (i = 0; path[i] >= 0; i++)
    {
        gotoxy(tile_x(path[i]) + 1, tile_y(path[i]) + 1);
        printf("-");
        Sleep(2000);
    }
    printf("\n");
    printf("\n");
    printf("走迷宫完成");
}

void readmap()
{
    printf("走迷宫，s是起始点 e是终点  按任意键开始");
    getchar();
    //FILE *f;
    int i, j;
    //f=fopen("2.c","r");
    //assert(f);
    //scanf("%d%d",&map_w,&map_h);
    map_w = map_h = 6;
    for (i = 0; i < map_h; i++)
        //fgets(&map[i][0],map_w+1,f);
        //fclose(f);
        start_x = -1, end_x = -1;
    for (i = 0; i < map_h; i++)
        for (j = 0; j < map_w; j++)
        {
            if (map[i][j] == 's')
                map[i][j] = ' ', start_x = j, start_y = i;
            if (map[i][j] == 'e')
                map[i][j] = ' ', end_x = j, end_y = i;
        }
    assert(start_x >= 0 && end_x >= 0);
    //printf("%d,%d,%d,%d",start_x,start_y,end_x,end_y);
}

void showmap()
{
    int i, j;
    system("cls");
    for (i = 0; i < map_h; i++)
    {
        gotoxy(1, i + 1);
        for (j = 0; j < map_w; j++)
            if (map[i][j] != ' ')
                printf("x");
            else
                printf(" ");
    }
    gotoxy(end_x + 1, end_y + 1);
    printf("e");
    gotoxy(start_x + 1, start_y + 1);
    printf("s");
}

int main()
{
    system("title 晓博 A*算法试验程序");
    //设置cmd窗口标题
    printf("…………欢迎使用晓博 A*算法试验程序，Designed by 1wangxiaobo@163.com 河南财经政法大学…………");
    int path[MAXINT];
    readmap();
    showmap();
    Sleep(2000);
    findpath(path);
    printpath(path);
    getchar();
    system("pause");
    return 0;
}