#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x[20],y[20];
	double s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	x[n]=x[0];
	y[n]=y[0];
	for(int i=0;i<n;i++)
        s+=(x[i]*y[i+1]-x[i+1]*y[i]);
    printf("%.2lf\n",fabs(s/2));
    return 0;
}
