#include <stdio.h>

struct edge{
	int x;
	int num=0;
}a[10001];

int main(){
	int k=0,n=0,temp=0,max=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++,k++){
		scanf("%d",&temp);
		if(k == 0)  a[0].x = temp;
		for(int j=0;j<k;j++){
			if(a[j].x == temp){
				a[j].num++;
				k--;
			}
			else	a[k].x = temp;
		}
	}
	k--;    temp=0;
	for(int i=0;i<k;i++){
		if(a[i].num>a[max].num)    max = i;
	}
	for(int i=0;i<k;i++){
		if(a[i].num == a[max].num)    temp++;;
	}
	if(temp == 1)	printf("%d\n",a[max].x);
	else    printf("%d\n",a[0].x);
	return 0;
}
