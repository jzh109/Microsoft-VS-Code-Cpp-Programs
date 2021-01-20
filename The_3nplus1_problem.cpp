#include <bits/stdc++.h>
#include <windows.h>
#include <iostream>
using namespace std;

void SetColor(unsigned short ForeColor=3,unsigned short BackGroundColor=0){
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor);
}

int main()
{
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetColor();
	cout<<"Hello World"<<endl;
	SetColor(00,10);
	cout<<"Hello World"<<endl;
	cout<<"Hello World"<<endl;
	
}

