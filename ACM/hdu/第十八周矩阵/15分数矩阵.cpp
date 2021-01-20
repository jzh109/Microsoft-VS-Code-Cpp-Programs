#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin>>n, n) {
		double res = 0;
		for(int i = 1; i <= n; i++) {
			int cnt = i + 1;
			for(int j = 2; cnt <= n; j++, cnt++)
			res = res + 1.0 / (float) j;
		}
		printf("%.2lf\n", 2.0 * res + n);
	}
	return 0;
}
