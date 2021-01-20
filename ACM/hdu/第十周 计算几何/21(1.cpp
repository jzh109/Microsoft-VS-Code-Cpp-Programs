/*#include <bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
}points[1000000],res[1000000];

bool cmp(Point a,Point b){
	if(atan2(a.y,a.x)!=atan2(b.y,b.x))  return atan2(a.y,a.x)<atan2(b.y,b.x);
	return a.x<b.x;
}

int cross(Point a,Point b,Point c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

double square(Point a,Point b,Point c){
	double s;
	s=a.x*b.y-a.y*b.x+b.x*c.y-b.y*c.x+c.x*a.y-c.y*a.x;
	return fabs(s);
}

int convex(int n){
	int m=0;
	sort(points,points+n,cmp);
	for(int i=0;i<n;i++){
		while(m>1&&cross(res[m-1],points[i],res[m-2])<=0)   m--;
		res[m++]=points[i];
	}
	return m;
}

double maxsquare(int m){
	int a=0,b,c;
	double max=0,temp;
	for(a=0;a<m-2;a++)
		for(b=a+1;b<m-1;b++)
			for(c=b+1;c<m;c++){
				temp=square(res[a],res[b],res[c]);
				max=max>temp?max:temp;
			}
	return max/2;
}

int main(){
	int n,m;
	double s;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d",&points[i].x,&points[i].y);
		m=convex(n);
		s=maxsquare(m);
		printf("%.2f\n",s);
	}
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
}p[1000100];
int n;

int ans[1000100],st[1000100],cnt,stop;

bool cmp(Point a,Point b){
	if(atan2(a.y,a.x)!=atan2(b.y,b.x))  return atan2(a.y,a.x)<atan2(b.y,b.x);
	return a.x<b.x;
}

int cross(Point a,Point b,Point c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

void slove(){
    cnt=stop=0;
    st[stop++]=0; st[stop++]=1;
    for(int i=2;i<n;i++){
        while(stop>1&&cross(p[i],p[st[stop-1]],p[st[stop-2]])>=0) stop--;
        st[stop++]=i;
    }
    for(int i=0;i<stop;i++)
    ans[cnt++]=st[i];
    stop=0; st[stop++]=n-1; st[stop++]=n-2;
    for(int i=n-3;i>=0;i--){
        while(stop>1&&cross(p[i],p[st[stop-1]],p[st[stop-2]])>=0) stop--;
        st[stop++]=i;
    }
    for(int i=1;i<stop-1;i++)
    ans[cnt++]=st[i];
}

double square(Point a,Point b,Point c){
	double s;
	s=a.x*b.y-a.y*b.x+b.x*c.y-b.y*c.x+c.x*a.y-c.y*a.x;
	return fabs(s)/2;
}

double Area(){
    int q; int j;
    double anst=0;
    for(int i=0;i<cnt;i++){
        j=(i+1)%cnt;
        q=(j+1)%cnt;
        while(square(p[ans[i]],p[ans[j]],p[ans[q]])<=square(p[ans[i]],p[ans[j]],p[ans[(q+1)%cnt]])&&q!=i)
        	q=(q+1)%cnt;    //枚举了当前最远的K点
        anst=max(anst,square(p[ans[i]],p[ans[j]],p[ans[q]]));
        if(q==i)	continue;
        while(j!=i&&q!=i){
            anst=max(anst,square(p[ans[i]],p[ans[j]],p[ans[q]]));
            while(square(p[ans[i]],p[ans[j]],p[ans[q]])<=square(p[ans[i]],p[ans[j]],p[ans[(q+1)%cnt]])&&q!=i)
            	q=(q+1)%cnt;
            j=(j+1)%cnt;
        }

    }
    return anst;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmp);
        slove();
        double anst=0;
        anst=max(anst,Area());
        printf("%.2lf\n",anst);
    }
    return 0;
}
