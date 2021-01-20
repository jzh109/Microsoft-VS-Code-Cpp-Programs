#include <stdio.h>
int main(){
	int a[6][6],test;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			test = a[i][j];
			for(int m=1;m<=5;m++){
				if((test>=a[i][m]&&test<=a[m][j])&&m==5){
					printf("%d %d %d\n",i,j,a[i][j]);
					return 0;
				}
				else    break;
			}
		}
	}
	printf("not found\n");
	return 0;
}
