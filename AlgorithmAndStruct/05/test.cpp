#include <bits/stdc++.h>
using namespace std;

/*采用邻接矩阵表示图的广度优先遍历*/
void BFS_AM(AMGraph &G, char v0)
{
    /*从v0元素开始访问图*/

    int u, i, v, w;
    v = LocateVex(G, v0); //找到v0对应的下标
    printf("%c ", v0);    //打印v0
    visited[v] = 1;       //顶点v0已被访问
    q.push(v0);           //将v0入队

    while (!q.empty())
    {
        u = q.front();       //将队头元素u出队，开始访问u的所有邻接点
        v = LocateVex(G, u); //得到顶点u的对应下标
        q.pop();             //将顶点u出队
        for (i = 0; i < G.vexnum; i++)
        {
            w = G.vexs[i];
            if (G.arcs[v][i] && !visited[i]) //顶点u和w间有边，且顶点w未被访问
            {
                printf("%c ", w); //打印顶点w
                q.push(w);        //将顶点w入队
                visited[i] = 1;   //顶点w已被访问
            }
        }
    }
}

int main(int argc, char *argv[])
{
}