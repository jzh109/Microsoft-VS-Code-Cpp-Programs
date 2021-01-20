#include <stdio.h>
#define ll long long

const ll INF = 0x3f3f3f3f;
struct Node{
	int le, t, w, h, ri;
}node[10005];

ll diff(int n, int k){
	ll delta = 0, temp;
	for(int i = 0; i < n; i++) {
		if(node[i].le <= k && node[i].ri >= k) {
			temp = (2 * k - node[i].le - node[i].ri) * node[i].h;
			delta += temp;
		}
	}
	return delta;
}

int main(){
	int r, n, res, k, min = INF;
	scanf("%d%d", &r, &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &node[i].le, &node[i].t, &node[i].w, &node[i].h);
		node[i].ri = node[i].le + node[i].w;
	}
	k = r;
	while(k >= 0) {
		ll temp = diff(n, k);
		if(temp >= 0) {
			res = temp < min ? k : res;
			min = temp < min ? temp : min;
		}
		k--;
	}
	printf("%d\n", res);
	return 0;
}

/*#include<cstdio>
#include<cstdlib>

using namespace std;

struct node
{
    int x,y,xr,h;
    long long s;
} a[10010];

int R,n;
long long lone=1;

long long diff(int mid)
{
    long long s1=0,s2=0;

    for (int i=0;i<=n;i++)
    {
        if (a[i].xr<=mid) s1+= a[i].s;
        else if (a[i].x>=mid) s2+=a[i].s;
        else
        {
            s1+=lone*(mid-a[i].x)*a[i].h;
            s2+=lone*(a[i].xr-mid)*a[i].h;
        }
    }
    return s1-s2;  // left - right
}
int main()
{
   int l,r,mid;
    int maxx=-1;

    scanf("%d",&R);
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
    {
        int  x,y,w,h;
        scanf("%d%d%d%d",&x,&y,&w,&h);
        a[i].x=x; a[i].y=y; a[i].xr=x+w; a[i].h=h; a[i].s=lone*w*h;
        if (x+w>maxx) maxx=x+w;
    }
    l=0;r=R;
    while (l+1<r)
    {
        mid=(l+r)/2;
        long long  sum=diff(mid);
        if (sum>0) r=mid;
        else if (sum<=0) l=mid;
    }
    long long  zuo,you;
    int  ans;
    zuo=diff(l);
    you=diff(r);
//    if (abs(zuo)>=abs(you)) ans=r;  else ans=l;
	if (you==0) ans=r;
		else
	         if (zuo==0) ans=l;
		         else ans=r;
    if (ans==maxx) ans=R;
    printf("%d\n",ans);
// printf("%d  %d\n",r,maxx);
   return 0;
} */
