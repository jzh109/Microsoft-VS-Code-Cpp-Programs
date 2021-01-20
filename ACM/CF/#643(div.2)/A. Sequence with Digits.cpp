#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxDigit(ll a, int max){
	int temp;
	if(a%10==a) return max>a?max:a;
	temp = a%10;
	temp = maxDigit(a/10,temp);
	return temp>max?temp:max;
}

int minDigit(ll a, int min){
	int temp;
	if(a%10==a) return min<a?min:a;
	temp=a%10;
	temp = minDigit(a/10, temp);
	return temp<min?temp:min;
}

/*ll f1(ll n, ll k){
	if(k==1)    return n;
	ll res = f(n,k-1);
	int min=minDigit(res,10);
	int max=maxDigit(res,-1);
	return res + min*max;
}*/

ll f(ll n, ll k){
	ll res=0,temp=0;
	int min,max;
	res=n;
 	for(ll i=1;i<k;i++){
		min=minDigit(res,10);
		max=maxDigit(res,-1);
		if(min==0)break;            //注意判断是否有0，有的话直接跳出
		res+=min*max;
	}
	return res;
}

int main(){
	ll n,k;
	int t;
	cin>>t;
	while(t--){
		int min,max;
		cin>>n>>k;
		cout<<f(n,k)<<endl;;
	}
	return 0;
}
