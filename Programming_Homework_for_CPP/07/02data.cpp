#include <stdio.h>

typedef struct {
   int year;
   int month;
   int day;
}Date;

//judge if a year is a leap year
bool ifLeap(int a) {
	if(a % 100 == 0) {
		if(a % 400 == 0)    return true;
		else    return false;
	}
	else {
		if(a % 4 == 0)  return true;
		else    return false;
	}
}

//get the number of days in the month
int getDay(int a, bool judge) {
	switch(a) {
		case 1 :    return 31;
		case 2 : {
			if(judge)   return 29;
			return 28;
		}
		case 3 :    return 31;
		case 4 :    return 30;
		case 5 :    return 31;
		case 6 :    return 30;
		case 7 :    return 31;
		case 8 :    return 31;
		case 9 :    return 30;
		case 10 :   return 31;
		case 11 :   return 30;
		case 12 :   return 31;
	}
}

//calculate the days between two dates
int calculate(Date a, Date b) {
	int sum = 0;
	
	//if years and month are same
	if(a.year == b.year && a.month == b.month)  return b.day - a.day;
	
	//if the years are same but month are not same
	if(a.year == b.year) {
		bool ifleap = ifLeap(a.year);
		for(int i = a.month; i < b.month; i++) {
			if(i == a.month)    sum += (getDay(a.month, ifLeap(a.year)) - a.day);
			else	sum += getDay(i, ifleap);
		}
		sum += b.day;
	}
	
	//if the years and month are not same
	else {
		sum += (getDay(a.month, ifLeap(a.year)) - a.day);
		for(int i = a.year; i < b.year; i++){
			bool ifleap = ifLeap(i);
			if(i == a.year) {
				for(int j = a.month + 1; j <= 12; j++)
					sum += getDay(j, ifleap);
			}
			else {
				for(int j = 1; j <= 12; j++)    sum += getDay(j, ifleap);
			}
		}
		for(int j = 1; j < b.month; j++)
			sum += getDay(j, ifLeap(b.year));
		sum += b.day;
	}
	return sum;
}

int main(){
	Date from, to;
	scanf("%d%d%d%d%d%d",&from.year, &from.month, &from.day, &to.year, &to.month, &to.day);
	printf("%d\n", calculate(from, to));
	return 0;
}
