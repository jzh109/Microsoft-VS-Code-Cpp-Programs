#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

struct Point{
	int x,y;
}points[MAX],res[MAX],pmin;

int cross(Point a,Point b,Point c){
    return (a.x-c.x)*(b.y-c.y) - (b.x-c.x)*(a.y-c.y);
}

int cmp(Point a,Point b){
	if(atan2(a.y,a.x)!=atan2(b.y,b.x))
		return atan2(a.y,a.x)<atan2(b.y,b.x);
	return a.x<b.y;
}

int convex(int n){
    sort(points,points+n,cmp);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1 && cross(res[m-1],points[i],res[m-2])<=0)
            m--;
        res[m++] = points[i];
    }
    res;
    return m;
}

int main(){
	int t,n,sumx,sumy;
	double x,y;
	cin>>t;
	while(t--){
		cin>>n;
		sumx=sumy=0;
		for(int i=0;i<n;i++)
			cin>>points[i].x>>points[i].y;
		int k=convex(n);
		for(int i=0;i<k;i++){
			sumx+=res[i].x;
			sumy+=res[i].y;
		}
		x=sumx/k;
		y=sumy/k;
		printf("%.2f %.2f\n",x,y);
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
int main()
{
    double x0,y0,x1,y1,x2,y2;
    int n,m;
    scanf( "%d",&n );
    for( int i=1; i<=n; i++ )
    {
       double sx=0,sy=0,s=0;
       scanf( "%d",&m );
       scanf( "%lf%lf%lf%lf",&x0,&y0,&x1,&y1 );
       for( int j=2;j<m; j++ )
       {
             scanf("%lf%lf",&x2,&y2);
             double S=0.5*( ( x1-x0 )*( y2-y0 )-( x2-x0 )*( y1-y0 ) );//Ê¸Á¿Ãæ»ý
             sx+=S*( x0+x1+x2 );
             sy+=S*( y0+y1+y2 );
             s+=S;
             x1=x2;
             y1=y2;
       }
       printf( "%.2lf %.2lf\n",sx/( 3*s ),sy/( 3*s ) );
    }
    return 0;
}
