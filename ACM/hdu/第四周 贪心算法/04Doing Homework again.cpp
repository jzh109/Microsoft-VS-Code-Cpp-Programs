/*#include <bits/stdc++.h>
using namespace std;

struct Work {
	int endtime;
	int much;
}work[1005];

bool cmp(Work a, Work b) {
	return a.much > b.much;
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		int score = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)	scanf("%d", &work[i].endtime);
		for(int i = 1; i <= n; i++) scanf("%d", &work[i].much);
		sort(work + 1, work + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			if(i > work[i].endtime + 1) 	score += work[i].much;              //WA
		}
		printf("%d\n", score);
	}
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

struct Work {
	int deadline;
	int value;
}work[1005];

bool cmp(Work a, Work b) {
	return a.value > b.value;
}

int main() {
	int t, n;
	bool busy[1005];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)  scanf("%d", &work[i].deadline);
		for(int i = 0; i < n; i++)  scanf("%d", &work[i].value);
		for(int i = 0; i < n; i++)  busy[i] = false;
		sort(work, work + n, cmp);
		int res = 0;
		for(int i = 0; i < n; i++) {
			for(int j = work[i].deadline; j >= 1; j--) {
				if(!busy[j]) {
					busy[j] = true;
					break;
				}
				if(j == 1) {
					res += work[i].value;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
