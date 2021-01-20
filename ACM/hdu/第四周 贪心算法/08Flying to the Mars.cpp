#include <map>
#include <stdio.h>
using namespace std;

int main() {
	map<int, int> people;
	int n;
	while(scanf("%d", &n) != EOF) {
		int res = -1, temp;
		people.clear();
		for(int i = 0; i < n; i++) {
			scanf("%d", &temp);
			people[temp]++;
			res = res > people[temp] ? res : people[temp];
		}
		printf("%d\n", res);
	}
	return 0;
}
