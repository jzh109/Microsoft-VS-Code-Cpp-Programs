/*#include <cstdio>
#include <string.h>
#include <algorithm>
int main(){
	int from,to,n,len,j;
	char a[1010];
	scanf("%d",&n);
	while(n--){
		memset(a,0,sizeof(a));
		getchar();
		gets(a);
		len=strlen(a);
		for(int i=0;i<len;i++){
			from=i;
			for(j=i;(a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z');j++);
			to=j;
			if(from!=to)	std::reverse(a+from,a+to);
			if(j!=len+1)	i=j;
		}
		printf("%s\n",a);
	}
	return 0;
}*/
#include <stdio.h>

int main()
{
	int n,i=0,s,sign;
	char a[1001],temp[100],c;
	scanf("%d",&n);
	getchar();	
	while(n--)
	{
		s=sign=0;
		c=getchar();
		while(c!='\n')
		{
			i=0;
			while(1)
			{
				if(c==' '&&sign==0) break;
				temp[i++]=c;
				c=getchar();
				if(c==' '||c=='\n') break;
			}
			if(sign==0&&c=='\n') break;
			for(i-=1;i>=sign;i--)
				a[s++]=temp[i];
			a[s++]=c;
			sign=1;
		}
		for(i=0;i<s;i++)
			printf("%c",a[i]);
	}
	return 0;
}
