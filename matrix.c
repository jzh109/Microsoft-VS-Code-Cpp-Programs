#include <stdio.h>
int main(){
	int n,i,j,a[11][11],b;
	char sign;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	while(scanf("%c",&sign)&&sign!='#'){
		if(sign=='+'){
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					scanf("%d",&b);
					a[i][j]+=b;
				}
		}
		else if(sign=='-'){
			for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					scanf("%d",&b);
					a[i][j]-=b;
				}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	return 0;
}
