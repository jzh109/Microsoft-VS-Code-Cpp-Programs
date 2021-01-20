#include <stdio.h>
#include <algorithm>

struct Node{
	int chn, mth, egl, sum, id;
	bool operator <(Node other)const{
		if(sum != other.sum)    return sum > other.sum;
		else if(chn != other.chn)   return chn > other.chn;
		else    return id < other.id;
	}
}node[305];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &node[i].chn, &node[i].mth, &node[i].egl);
		node[i].sum = node[i].chn + node[i].mth + node[i].egl;
		node[i].id = i + 1;
	}
	std::sort(node, node + n);
	for(int  i = 0; i < 5; i++) printf("%d %d\n", node[i].id, node[i].sum);
	return 0;
}
