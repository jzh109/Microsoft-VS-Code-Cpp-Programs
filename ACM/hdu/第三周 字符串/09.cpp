#include <stdio.h>
#include  <string.h>
int main(){
	int n,len;
	char a[51];
	bool judge;
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(a);
		len=strlen(a);
		for(int i=0;i<len;i++){
			if(a[0]>='0'&&a[0]<='9'){
				judge=false;
				break;
			}
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')||a[i]=='_')
			{	judge=true;continue;}
			judge=false;
			break;
		}
		if(judge==false)	printf("no\n");
		else	printf("yes\n");
	}
	return 0;
} 
