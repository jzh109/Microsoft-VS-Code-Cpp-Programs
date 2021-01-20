#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
	char str1[1000],str2[1000],sum[1000],a[1000],b[1000];
	int i,j,n,len1,len2,maxlen;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s %s",str1,str2);
			memset(sum,0,sizeof(sum));
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			len1=strlen(str1);
			len2=strlen(str2);
			for(j=0;j<len1;j++)
				a[len1-j-1]=str1[j]-'0';
			for(j=0;j<len2;j++)
				b[len2-j-1]=str2[j]-'0';
			maxlen=len1>=len2?len1:len2;
			for(j=0;j<maxlen;j++)
			{
				sum[j]+=a[j]+b[j];
				sum[j+1]+=sum[j]/10;
				sum[j]=sum[j]%10;
			}
			printf("Case %d:\n",i+1);
			printf("%s + %s = ",str1,str2);
			for(j=0;j<maxlen;j++)
				sum[j]=sum[j]+'0';
			for(j=0;j<maxlen;j++)
				printf("%c",sum[maxlen-j-1]);
			printf("\n");
			if(i!=n-1)
				printf("\n");
		}
	}
	system("pause"); 
	return 0;
} 
