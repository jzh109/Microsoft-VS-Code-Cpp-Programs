#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Point{
	double x,y;
}points[MAX],p;

int N;
const double pi=acos(-1.0),eps=1e-8;

double dis(Point a,Point b){
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

double coss(Point a,Point b,Point c){
	double ang=(pow(dis(a,c),2)+pow(dis(b,c),2)-pow(dis(a,b),2))/(2*dis(a,c)*dis(b,c));
	return ang;
}

int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&points[i].x,&points[i].y);
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			double ang=0;
			scanf("%lf%lf",&p.x,&p.y);
			if(fabs(coss(points[n-1],points[0],p)+1)<=eps){
				printf("No\n");
				continue;
			}
			bool judge=false;
			for(int j=1;j<n;j++)
				if(fabs(coss(points[j-1],points[j],p)+1)<=eps){
					printf("No\n");
					judge=true;
					break;
				}
			if(judge==true) continue;
			for(int j=1;j<n;j++)
				ang+=acos(coss(points[j-1],points[j],p));
			ang+=acos(coss(points[n-1],points[0],p));
			if(fabs(ang-2*pi)<=eps)   printf("Yes\n");
			else    printf("No\n");
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
double a[101],b[101];
int pnpoly(int nvert, double *vertx, double *verty, double testx, double testy)///nvert顶点数，vertx顶点x坐标数组，verty顶点y坐标数组,testx,testy判断坐标
{
    int i, j, c = 0;
    for (i = 0, j = nvert-1; i < nvert; j = i++)
        if (((verty[i]>testy) != (verty[j]>testy)) &&(testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
            c = !c;
    return c;
}

int main()
{
    int n;
    double p1,p2;
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; ++i) scanf ("%lf%lf", &a[i], &b[i]);
        int m;
        scanf ("%d", &m);
        while (m--)
        {
            scanf ("%lf%lf", &p1, &p2);
            if (pnpoly(n,a,b,p1,p2)) printf ("Yes\n");
            else printf ("No\n");
        }
    }
    return 0;
}
