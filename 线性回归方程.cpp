#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

float sum_xy(float x[], float y[], int n);
float sum_k2(float k[], int n);
float k_bar(float k[], int n);
float fb(float sumxy, float sumx2, float xbar, float ybar, int n);
float fr(float sumxy, float sumx2, float sumy2, float xbar, float ybar, int n);

int main()
{
	float x[100] = {0}, y[100] = {0}, sumxy, sumx2, sumy2, xbar, ybar, a, b, r, xi;
	int n, i;
	cout << "Please input the number of statics(beneath 100):";
	cin >> n;
	cout << "Please input x's(two numbers are separated by one break):" << endl;
	for (i = 0; i < n; i++)
		scanf("%f", &x[i]);
	cout << "Please input y's(two numbers are separated by one break):" << endl;
	for (i = 0; i < n; i++)
		scanf("%f", &y[i]);
	fflush(stdin);
	sumxy = sum_xy(x, y, n);
	sumx2 = sum_k2(x, n);
	sumy2 = sum_k2(y, n);
	xbar = k_bar(x, n);
	ybar = k_bar(y, n);
	if ((sumx2 - n * xbar * xbar) != 0)
	{
		r = fr(sumxy, sumx2, sumy2, xbar, ybar, n);
		if (r >= 0.75 || r <= -0.75)
		{
			b = fb(sumxy, sumx2, xbar, ybar, n);
			a = ybar - b * xbar;
			cout << "--------------------------------------------" << endl;
			printf("SUMx[i]y[i]=%f\nSUMx[i]^2=%f\nb=%f\na=%f\nr=%f\n", sumxy, sumx2, b, a, r);
			cout << "The equation is:y=";
			printf("%f", b);
			cout << "*x+";
			printf("%f\n", a);
			cout << "You may input an x to calculate its exceptational y:";
			cin >> xi;
			cout << "The exceptational y is ";
			printf("%f\n", b * xi + a);
		}
		else
		{
			cout << "--------------------------------------------" << endl;
			printf("-0.75<r=%f<0.75\n", r);
			cout << "Statics donot have strong linear correlation.\n"
				 << endl;
		}
	}
	else
		cout << "ERROR!The b doesnot exist!" << endl;
	system("pause");
	return 0;
}

float sum_xy(float x[], float y[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i] * y[i];
	return sum;
}

float sum_k2(float k[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += k[i] * k[i];
	return sum;
}

float k_bar(float k[], int n)
{
	float bar, sum = 0;
	for (int i = 0; i < n; i++)
		sum += k[i];
	bar = sum / n;
	return bar;
}

float fb(float sumxy, float sumx2, float xbar, float ybar, int n)
{
	float re;
	re = (sumxy - n * xbar * ybar) / (sumx2 - n * xbar * xbar);
	return re;
}

float fr(float sumxy, float sumx2, float sumy2, float xbar, float ybar, int n)
{
	float r;
	r = (sumxy - n * xbar * ybar) / sqrt((sumx2 - n * xbar * xbar) * (sumy2 - n * ybar * ybar));
	return r;
}
