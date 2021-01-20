#include <bits/stdc++.h>
using namespace std;

struct node{
    double x,y;
}p[100005],p1[100005];

double Direction(node pi,node pj,node pk){//������
    return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

bool Segments_X(node p1,node p2,node p3,node p4){//�ж������߶��Ƿ��ཻ,�ཻ����true
    double d1,d2,d3,d4;
    d1=Direction(p3,p4,p1);
    d2=Direction(p3,p4,p2);
    d3=Direction(p1,p2,p3);
    d4=Direction(p1,p2,p4);
    if(d1*d2<=0&&d3*d4<=0) return true;
    return false;
}

int main(){
    int n;
    while(cin>>n&&n){
        for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p1[i].x,&p1[i].y);
        printf("Top sticks: ");
        for(int i=1;i<n;i++){
            int ok=1;
            for(int j=i+1;j<=n;j++){//֮�ж��ڸ��߶�֮�����µ��߶�(ľ��)
                if(Segments_X(p[i],p1[i],p[j],p1[j])){
                    ok=0; break;
                }
            }
            if(ok) printf("%d, ",i);
        }
        printf("%d.\n",n); //������һ��
    }
    return 0;
}
