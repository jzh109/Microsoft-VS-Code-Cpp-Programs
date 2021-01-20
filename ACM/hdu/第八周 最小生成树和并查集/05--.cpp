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
        for(x=0;x<n;x++){//�����ݴ���ṹ�壬������Լ����Ż�
            for(y=0;y<n;y++){
                cin>>BIN[j].len;
                BIN[j].x=x;
                BIN[j].y=y;
                j++;
            }
        }
        sort(BIN,BIN+j,cmp); //����·���ȴ�С��������
        for(int i=0;i<n;i++) //���鼯��ʼ��
            father[i]=i;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>x>>y;
            x=findx(x-1);//���Ҷ���
            y=findx(y-1);//���Ҷ���
            if(x!=y)//�ж��Ƿ���ͨ
                father[x]=father[y];//û����ͨ���ϲ�
        }
        sum=0;
        for(int i=0;i<j;i++)
        {
            if(BIN[i].len>0)
            {

                x=findx(BIN[i].x);//���Ҷ��� 
                y=findx(BIN[i].y);//���Ҷ��� 
                if(x!=y)//�ж��Ƿ���ͨ 
                {
                    sum+=BIN[i].len;//�洢��·���� 
                    father[x]=father[y]; //�ϲ� 
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
