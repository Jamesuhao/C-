#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();    
	Date operator++(int);    
	Date& operator--();    
	Date operator--(int);    
	Date& operator-=(int day);
	Date& operator+=(int day);
	bool operator>(const Date& d)const;    
	bool operator>=(const Date& d)const;    
	bool operator<(const Date& d)const;    
	bool operator<=(const Date& d)const;    
	bool operator==(const Date& d)const;    
	bool operator!=(const Date& d)const;
	void Print();
private:
	int _year;
	int _month;
	int _day;
	int _getMonthDays(int year, int month)
	{
		static int const _monthDay[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		return _monthDay[month];
	}
};
