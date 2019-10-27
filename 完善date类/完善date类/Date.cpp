#include"Date.h"
//构造
Date::Date(int year, int month, int day)
{	
	if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > _getMonthDays(year, month))
	{
		_year = 1;
		_month =1;
		_day = 1;
		cout << "日期非法，重置为默认值：1-1-1" << endl;
	}
	else
	{
		_year = year;
		_month = month;
		_day = day;
	}
}
//拷贝构造
Date::Date(const Date& d)
	: _year(d._year)
	, _month(d._month)
	, _day(d._day) {}
// =
Date& Date::operator=(const Date& d)
{
	if (this == &d)
		return *this;
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
// +
Date Date::operator+(int days)
{
	Date tmp(*this);
	//调用+=的写法
	//tmp+=days;
	//return tmp;
	//自我实现的写法
	tmp._day += days;
	while (tmp._day >= _getMonthDays(tmp._year, tmp._month))
	{
		int getMonthDays = _getMonthDays(tmp._year, tmp._month);
		if (tmp._month == 12)
		{
			tmp._year += 1;
			tmp._month = 1;
		}
		else
			tmp._month += 1;
		tmp._day = tmp._day - getMonthDays;
	}
	return tmp;//为什么会去调用拷贝构造函数？
}
// -
Date Date::operator-(int days)
{
	Date tmp(*this);
	tmp -= days;
	return tmp;
	//tmp._day -= days;
	//while (tmp._day <= 0)
	//{
	//	if (tmp._month == 1)
	//	{
	//		tmp._year -= 1;
	//		tmp._month = 12;
	//	}
	//	else
	//		tmp._month -= 1;
	//	tmp._day = tmp._day+ _getMonthDays(tmp._year, tmp._month);
	//}
	//return tmp;
}
// 两个日期相减
int Date:: operator-(const Date& d)
{
	Date minDate(*this);
	Date maxDate(d);
	if (minDate>maxDate)
	{
		minDate = maxDate;
		maxDate = *this;
	}
	int count = 0;
	while (maxDate > minDate)
	{
		++minDate;
		++count;
	}
	return count;
}
//前置++
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}
//后置++
Date Date:: operator++(int)
{
	Date tmp(*this);
	*this = *this + 1;
	return tmp;
}
//前置--
Date& Date:: operator--()
{
	*this = *this - 1;
	return *this;
}
//后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this = *this - 1;
	return tmp;
}
// -=
Date& Date::operator-=(int days)
{
	if (days < 0)
		return *this += (-days);
	_day -= days;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_year --;
			_month = 12;
		}
		_day = _day + _getMonthDays(_year, _month);
	}
	return *this;
}
// +=
Date& Date::operator+=(int days)
{
	if (days < 0)
		return *this -= (-days);
	_day += days;
	while (_day >= _getMonthDays(_year, _month))
	{
		int getMonthDays=_getMonthDays(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
		_day -= getMonthDays;
	}
	return *this;
}
// >
bool Date::operator>(const Date& d)const
{
	if ((_year > d._year) || 
		(_year == d._year && _month > d._month) ||
		(_year == d._year && _month == d._month && _day > d._year))
		return true;
	return false;
}
// >=
bool Date::operator>=(const Date& d)const
{
	//if ((_year >= d._year) ||
	//	(_year == d._year && _month >= d._month) ||
	//	(_year == d._year && _month == d._month && _day >= d._year))
	//	return true;
	//return false;
	return *this > d || *this == d;
}
// <
bool Date::operator<(const Date& d)const
{
	//if ((_year < d._year) ||
	//	(_year == d._year && _month < d._month) ||
	//	(_year == d._year && _month == d._month && _day < d._year))
	//	return true;
	//return false;
	return !(*this >= d);
}
// <=
bool Date::operator<=(const Date& d)const
{
	//if ((_year <= d._year) ||
	//	(_year == d._year && _month <= d._month) ||
	//	(_year == d._year && _month == d._month && _day <= d._year))
	//	return true;
	//return false;
	return !(*this > d);
}
// ==
bool Date::operator==(const Date& d)const
{
	if (_year == d._year && _month == d._month && _day == d._year)
		return true;
	return false;
}
// !=
bool Date::operator!=(const Date& d)const
{
	//if (_year == d._year && _month == d._month && _day == d._year)
	//	return false;
	//return true;
	return !(*this == d);
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}


int main()
{
	Date d(2019, 2, 1);
	Date d1(2019, 3, 1);
	//d =d- 62;
	//d.Print();
	cout << d - d1 << endl;
	cout << d1 - d << endl;
	//d++;
	//d.Print();
	//Date d2 = d1 - 100;
	//d2.Print();
	//Date d3 = d2 + 100;
	//d3.Print();
	//d3 += 100;
	//d3.Print();
	//d3 -= 100;
	//d3.Print();
	//d1 += 40;
	//d1.Print();
	//d1 -= 40;
	//d1.Print();
	return 0;
}