#include <stdio.h>
#include <string.h>
#include <iostream>

double signal (double a, char sign, double b) {
	switch (sign) {
		case '+':   return a + b;
		case '-':   return a - b;
		case '*':   return a * b;
		case '/':   return a / b;
	}
}

double calculate (char* sign, double* num, int count) {
	double res = 0, temp;
	for (int i = 0; i < count; i++) {
		if (sign[i] == '*' || sign[i] == '/') {
			num[i + 1] = signal (num[i - 1], sign[i], num[i + 1]);
			num[i - 1] = 0;
			sign[i] = 0;
		}
	}
	for (int i = 0; i < count; i++) {
		if (sign[i] == '+' || sign[i] == '-' ) {
			temp = signal (num[i - 1], sign[i], num[i + 1]);
			sign[i] = 0;
			num[i + 1] = temp;
			num[i - 1] = 0;
		}
	}
	for (int i = 0; i <= count; i++) {
		res += num[i];
	}
	return res;
}

int main () {
	char sign[20];
	double num[40];
	int count = 1;
	memset (sign, 0, sizeof (sign));
	memset (num, 0, sizeof (num));
	std::cin>>num[0];
	while (std::cin>>sign[count++], sign[count - 1] != '=') {
		std::cin>>num[count++];
	}
	sign[count - 1] = '+';
	num[count] = 0;
	std::cout<<calculate (sign, num, count)<<std::endl;
	return 0;
}
