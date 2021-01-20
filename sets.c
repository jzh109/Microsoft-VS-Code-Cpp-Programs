#include <stdio.h>
int main(){
	int a[100],b[100],c[100],A,B,m=0,i,j;
	for(A=0;scanf("%d",&a[A])&&a[A]!=-1;A++);
	for(B=0;scanf("%d",&b[B])&&b[B]!=-1;B++);
	for(i=0;i<A;i++){
		int judge=1;
		for(j=0;j<B;j++){
			if(a[i]!=b[j])  continue;
			judge=0;
			break;
		}
		if(judge==1) c[m++]=a[i];
	}
	for(i=0;i<m;i++){
		if(i<m-1)   printf("%d ",c[i]);
		else    printf("%d\n",c[i]);
	}
	return 0;
}
