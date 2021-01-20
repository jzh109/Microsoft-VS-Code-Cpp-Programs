#include <stdio.h>
#include <string.h>
int main(){
	char a[101];
	int len;
	scanf("%s",a);
	len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]>='A'&&a[i]<'X') a[i]+=3;
		else if(a[i]>='X'&&a[i]<='Z')   a[i]-=23;
		else if(a[i]>='a'&&a[i]<='x')   a[i]+=3;
		else if(a[i]>='x'&&a[i]<='z')   a[i]-=23;
	}
	printf("%s\n",a);
	return 0;
}
