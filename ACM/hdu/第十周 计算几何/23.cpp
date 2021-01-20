#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const double PI = acos(-1.0);

struct point{
    int x,y;
};

point points[MAXN];
point res[MAXN];
point pmin;

int cmp(point a,point b){
    if(atan2(a.y,a.x) != atan2(b.y,b.x))
        return atan2(a.y,a.x) < atan2(b.y,b.x);
    return a.x < b.x;
}

double getLen(point a,point b){
    return sqrt(pow(1.0*a.x-b.x,2.0) + pow(1.0*a.y - b.y,2.0));
}

int cross(point a,point b,point c){
    return (a.x-c.x)*(b.y-c.y) - (b.x-c.x)*(a.y-c.y);
}

int convex(int n){
    sort(points,points+n,cmp);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1 && cross(res[m-1],points[i],res[m-2])<=0)
            m--;
        res[m++] = points[i];
    }
    return m;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>points[i].x>>points[i].y;
  		pmin.x = points[0].x;
        pmin.y = points[0].y;
        for(int i=1;i<n;i++){
            if(pmin.y>points[i].y){
                pmin.y = points[i].y;
                pmin.x = points[i].x;
            }
            else if(pmin.y == points[i].y)
                pmin.x = points[i].x;
        }
        for(int i=0;i<n;i++){
            points[i].x -= pmin.x;
            points[i].y -= pmin.y;
        }															//移动原点
        int k = convex(n);											//k是凸包中的点数
        double sum = 0;
        for(int i=1;i<k;i++)
            sum += getLen(res[i],res[i-1]);//直边长度
        sum += getLen(res[k-1],res[0]);
        sum += 2*PI*m;
        printf("%.0lf\n",sum);
        if(T!=0)
            printf("\n");
    }
    return 0;
}
