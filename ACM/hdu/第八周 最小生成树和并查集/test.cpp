#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
struct road{
	int status,cost;
}BIN[5]={10,1,6,2,9,3,7,4,8,5};
bool cmp(road x,road y){
	//if (x.status > y.status)
		return true;
	//else if (x.status == y.status)
	//	return x.cost < y.cost;
	//else
	//	return false;
}
int main()
{
	/*queue<int>q;
	//q.push("Coding codes now!");
	//q.push("What the f**k!");
	//q.pop();
	q.push(1);
	q.push(6);
	q.push(4); 
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	cout<<q.size()<<endl;
	//cout<<q.top().x<<endl;*/
	
	sort(BIN,BIN+5,cmp);
	for(int i=0;i<5;i++){
		cout<<BIN[i].cost<<" "<<BIN[i].status<<endl;
	}
	int a[5]={3,2,1,2,5};
	sort(a,a+5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
