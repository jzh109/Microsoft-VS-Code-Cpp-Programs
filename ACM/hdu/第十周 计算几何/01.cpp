#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
const double eps=1e-8;
const double pi=acos(-1);
int sgn(double x){
    if(fabs(x)<eps) return 0;
    if(x<eps) return -1;
    else return 1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){
        x=_x,y=_y;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point &b)const{
        return x*b.x+y*b.y;
    }
};
double distancePoint(Point a,Point b){//求两点间的距离
    return sqrt((a-b)*(a-b));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        double R;
        scanf("%d%lf",&n,&R);
        Point o1=Point(0,0);
        double res=2*pi*R;
        for(int i=1;i<=n;i++){
            double x1,y1,r;
            scanf("%lf%lf%lf",&x1,&y1,&r);
            Point o2=Point(x1,y1);
            double o1o2=distancePoint(o1,o2);
            if(sgn(o1o2-(r+R))>=0||sgn(o1o2-(R-r))<0) continue;//内含、外切和不相交的情况忽略
            if(sgn(o1o2-(R-r))==0){
                res+=2*pi*r;
                continue;
            }
            double xita1=(R*R+o1o2*o1o2-r*r)/(2*R*o1o2);//余弦距离求两个圆心角
            double xita2=(r*r+o1o2*o1o2-R*R)/(2*r*o1o2);
            xita1=2*acos(xita1);
            xita2=2*acos(xita2);
            res+=r*xita2;
            res-=R*xita1;
        }
        printf("%.8f\n",res);
    }
}
