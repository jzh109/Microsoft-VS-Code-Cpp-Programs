/*#include <bits/stdc++.h>
using namespace std;
#define MAX 280005

struct edge{
	unsigned long from,to;
	unsigned long amount;
}BIN[MAX];

struct fathe{
	int fat;
	int poi;
}father[MAX];

int N=1,M;

void init(){
	for(int i=1;i<=N;i++){
		father[i].fat = i;
		father[i].poi = i;
	}
}

int findx(int x){
	if(father[x].fat == x)  return x;
	return father[x].fat = findx(father[x].fat);
}

void merge(int x,int y){
	int a=findx(x),b=findx(y);
	if(a == b)  return;
	father[a].fat = b;
}

bool cmp(fathe a,fathe b){
	return a.fat < b.fat;
}

int main(){
	FILE* fpin = fopen("in.txt","r");
	while(~fscanf(fpin,"%u,%u,%u",&BIN[N].from, &BIN[N].to, &BIN[N].amount))    N++;
	init();												father;
	for(int i=1;i<=N;i++)
		merge(BIN[i].from,BIN[i].to);
	sort(father+1,father+1+N,cmp);
		int k=1,count=1;
	while(count<=N){
		while(father[count].fat==k){
			printf("%d ",father[count++].poi);
		}
		k++;

		printf("\n");
	}
	//for(int point=1;point<=N;point++)
	return 0;
}*/
#include <bits/stdc++.h>
#include <bits/stl_map.h>
#include <map>
using namespace std;

int main()
{
    int count_v = 10000; //¶¥µãÊý
    int count_e = 40000; //±ßÊý

    map<int, unordered_set<int>> mp;
    unordered_set<int> st_temp;
    for (int i = 0; i < count_v; i++)
        mp.insert(pair<int, unordered_set<int>>(i, st_temp));

    for (int i = 0; i < count_e; i++)
    {
        int from = rand() % count_v;
        int to = rand() % count_v;
        while (from == to || mp[from].find(to) != mp[from].end())
        {
            from = rand() % count_v;
            to = rand() % count_v;
        }
        mp[from].insert(to);
    }
    ofstream outfile("test_data_test.txt");
    for (auto iter = mp.begin(); iter != mp.end(); ++iter)
    {
        for (auto iter1 = iter->second.begin(); iter1 != iter->second.end(); ++iter1)
        {
            outfile << iter->first << "," << *iter1 << ",100" << endl;
        }
    }
}
