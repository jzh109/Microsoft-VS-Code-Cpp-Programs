/*#include <stdio.h>													//	TLE
int main(){
	int t,n,s[100001],from,to,sum,temp;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&t);
			for(int j=0;j<t;j++)	scanf("%d",&s[j]);
			sum=0;
			for(int a=0;a<t;a++){
				temp=s[a];
				for(int b=a;b<t;b++){
					if(b==a)	continue;
					temp+=s[b];
					if(sum<temp){
						sum=temp;
						from=a+1;
						to=b+1;
					}
				}
			}
			printf("Case %d:\n",i);
			printf("%d %d %d\n",sum,from,to);
			if(i!=n)	printf("\n");
		}
	}
	return 0;
} */
#include <stdio.h>
#include<string.h>
#define N 100010

int main()
{
	int dp[N];
	int t;
	scanf("%d",&t);
	for(int cas = 1; cas <= t; cas++)
	{
		memset(dp,0,sizeof(dp));
		int n, temp = 1,st = 1, en = 1; 
		int  thisSum = 0, maxSum = -1001;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			scanf("%d",&dp[i]);
		for(int j = 1; j <= n; j++)
		{
			thisSum += dp[j];
			if(thisSum>maxSum)
			{
				st = temp;
				en = j;
				maxSum = thisSum;
			}
			if(thisSum<0)
			{
				thisSum = 0;
				temp = j+1;
			}
		}
		printf("Case %d:\n%d %d %d\n",cas,maxSum,st,en);
		if(cas<t)
		printf("\n");
	}
	return 0;
}
