#include <bits/stdc++.h>
using namespace std;

struct Node{
	char a[105];
	bool operator <(Node other)const{
		return strlen(a)<strlen(other.a);
	}
}node[1005];

int main(){
	int m,n;
	char temp[100],a;
	set<string> s;
	while(cin>>n>>m){
		getchar();
		int count=0;
		s.clear();
		for(int i=0;i<m;i++,count++){
			int j=0;
			memset(temp,0,sizeof(temp));
			while((a=getchar())!=' '&&a!='\n'){
				temp[j++]=a;
				count++;
			}
			s.insert(temp);
		}
		if(--count>n){
			int j=0,num=0,x=0;
			for(set<string>::iterator it=s.begin();it!=s.end();it++){
				strcpy(node[j++].a, (*it).c_str());
			}
			sort(node,node+m);
			for(int i=0;i<m;i++){
				x+=strlen(node[i].a);
				if(x>n)break;
				x++,num++;

			}
			cout<<num<<"\n";
			continue;
		}
		cout<<s.size()<<"\n";
	}
	return 0;
}
