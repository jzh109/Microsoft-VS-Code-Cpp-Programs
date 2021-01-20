#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define MAX 505

int maps[MAX][MAX], rights[MAX], n, k;
set<int> color;
bool used[MAX * MAX];

bool findx(int x, int cou) {
	for (int i = 0; i < n; i++) {
		if(maps[x][i] == cou && !used[i]) {
			used[i] = true;
			if(rights[i] == -1 || findx(rights[i], cou)) {
				rights[i] = x;
				return true;
			}
		}
	}
	return false;
}

int dfs(int x) {
	int res = 0;
	memset(rights, -1, sizeof(rights));
	for(int i = 0; i < n; i++) {
		memset(used, 0, sizeof(used));
		if(findx(i, x)) res++;
	}
	return res;
}

int main() {
	while(cin>>n>>k && n && k){
		color.clear();
		memset(maps, 0, sizeof(maps));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++){
				cin>>maps[i][j];
				color.insert(maps[i][j]);
			}
		}
		bool first = true, find = true;
		for(set<int>::iterator it = color.begin(); it != color.end(); it++) {
			if(dfs(*it) > k) {
				find = false;
				if(first) {
					printf("%d", *it);
					first = false;
				}
				else    printf(" %d", *it);
			}
		}
		if(find)    cout<<"-1";
		cout<<endl;
		
	}
	return 0;
}
