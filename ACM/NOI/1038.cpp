#include <map>
#include <stdio.h>
using namespace std;

int main(){
	map<int, int> a;
	int temp;
	a.clear();
	for(int i = 0; i < 25; i++){
		scanf("%d", &temp);
		a[temp]++;
	}
	for(map<int,int>::iterator it=a.begin();it!=a.end();it++){
		if((*it).second==1){
			printf("%d\n",(*it).first);
			break;
		}
	}
	return 0;
}
