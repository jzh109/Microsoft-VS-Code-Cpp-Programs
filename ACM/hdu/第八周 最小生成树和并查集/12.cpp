#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int len;
    char x;
    char y;
}BIN[10000];

int father[300];

int findx(int a){
    if(father[a]==a)
        return a;
    return father[a]=findx(father[a]);
}

int cmp(edge a,edge b){
    return a.len<b.len;
}

int main(){
    int n,j,k;
    char aa;
    while(cin>>n&&n){
        j=0;
        for(int i=1;i<n;i++){
            cin>>aa;
            cin>>k;
            for(int ii=0;ii<k;ii++){
                BIN[j].x=aa;
                cin>>BIN[j].y;
                cin>>BIN[j].len;
                j++;
            }
        }
        for(int i=0;i<27;i++)
            father[i+'A']=i+'A';
        sort(BIN,BIN+j,cmp);
        k=0;
        for(int i=0;i<j;i++){
            int x=findx(BIN[i].x);
            int y=findx(BIN[i].y);
            if(x!=y){
                k+=BIN[i].len;
                father[x]=y;

            }
        }
        cout<<k<<endl;
    }
    return 0;
}
