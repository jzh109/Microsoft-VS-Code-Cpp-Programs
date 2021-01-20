#include <stdio.h>
#include <string.h>
//#include <algorithm>
int main(){
	int n,len,temp,t;
	char a[10010];
	scanf("%d",&n);
	while(n--){
		memset(a,0,sizeof(a));
		t=0;
		temp=0;
		scanf("%s",a);
		len=strlen(a);
		//std::sort(a,a+len);
		for(int i=0;i<len+1;i++){
			if(a[i]==a[t])	temp++;
			else{
				if(temp==1)	printf("%c",a[t]);
				else
					printf("%d%c",temp,a[t]);
				t=i;
				temp=1;//
			}			
		}
		printf("\n");
	}
	return 0;
}
