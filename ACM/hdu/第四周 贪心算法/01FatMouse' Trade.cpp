#include <stdio.h>
#include <algorithm>
#define MAX 1005

struct Room {
	double food;
	double JavaBeam;
	double agv;
}room[MAX];

bool cmp(Room a, Room b) {
	return a.agv > b.agv;
}

int main() {
	int n, m;
	while(scanf("%d%d", &m, &n) != EOF){
		double res = 0;
		if(m == -1 && n == -1)  break;
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf", &room[i].JavaBeam, &room[i].food);
			room[i].agv = room[i].JavaBeam / room[i].food;
		}
		std::sort(room, room + n, cmp);
		for(int i = 0; i < n; i++) {
			if(m >= room[i].food) {
				res += room[i].JavaBeam;
				m -= room[i].food;
			}
			else {
				res += (room[i].agv * m);
				break;
			}
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
