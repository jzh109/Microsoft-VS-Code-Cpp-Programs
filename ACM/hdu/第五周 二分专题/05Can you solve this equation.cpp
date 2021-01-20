#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
double equ(double x) {
	return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		double y = 0, low = 0, high = 100, mid = (low + high) / 2;
		scanf("%lf", &y);
		if(equ(0) > y ||equ(100) < y) {
			cout<<"No solution!"<<endl;
			continue;
		}
		while(fabs(equ(mid) - y) > eps) {
			if((equ(mid) - y) > 0) {
				high = mid;
				mid = (low + high) / 2;
			}
			else {
				low = mid;
				mid = (low + high) / 2;
			}
		}
		printf("%.4lf\n", mid);
	}
	return 0;
}
