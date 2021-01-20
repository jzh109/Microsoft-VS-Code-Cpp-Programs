#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int father[100000];

struct edge{
    int len,x,y;
}BIN[10000];

bool cmp(edge a,edge b){
    return a.len<b.len;
}

int findx(int x){
    if(father[x]==x)	return x;
    return father[x]=findx(father[x]);
}

int main(){
    int n,j,k,sum,x,y;
    while(cin>>n)
    {
        j=0;
        for(x=0;x<n;x++){//将数据存入结构体，此项还可以继续优化
            for(y=0;y<n;y++){
                cin>>BIN[j].len;
                BIN[j].x=x;
                BIN[j].y=y;
                j++;
            }
        }
        sort(BIN,BIN+j,cmp); //将道路长度从小到大排序
        for(int i=0;i<n;i++) //并查集初始化
            father[i]=i;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>x>>y;
            x=findx(x-1);//查找顶点
            y=findx(y-1);//查找顶点
            if(x!=y)//判断是否连通
                father[x]=father[y];//没有连通，合并
        }
        sum=0;
        for(int i=0;i<j;i++)
        {
            if(BIN[i].len>0)
            {

                x=findx(BIN[i].x);//查找顶点 
                y=findx(BIN[i].y);//查找顶点 
                if(x!=y)//判断是否连通 
                {
                    sum+=BIN[i].len;//存储道路长度 
                    father[x]=father[y]; //合并 
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
