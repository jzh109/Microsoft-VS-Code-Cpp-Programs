#include <stdio.h>
#include <string.h>

struct edge{
	char name[50];
	char num[50];
}a[51];

void Sort(edge b[],int n){
	edge c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(b[j].name,b[j+1].name) >= 0){
				c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
			}
		}
	}
}

void Show(edge b[],int n){
	for(int i=0;i<n;i++)
		printf("  %10s  %10s\n",b[i].name,b[i].num);
}

int main(){
	int n;
	char b[50][50],c[50][50];
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	if(n>50)    return 0;
	for(int i=0;i<n;i++)
		scanf("%s%s",b[i],c[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++)
			a[i].name[j]=b[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++)
			a[i].num[j]=c[i][j];
	}
	Sort(a,n);
	Show(a,n);
	return 0;
}
