#include<iostream>
using namespace std;
#include"List.h"
struct Date
{
	int _year = 1997;
	int _month = 6;
	int _day = 5;
};
void testList1()
{
	List<int>lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	auto it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	//for (const auto &e : lst)
	//{
	//	cout << e << " ";
	//}
	cout << endl;
}
void testList2()
{
	List<Date>lst;
	lst.PushBack(Date());
	lst.PushBack(Date());
	for (auto e : lst)
	{
		cout << e._year << " " << e._month << " "<<e._day << endl;
	}
	auto it = lst.begin();
	while (it!=lst.end())
	{
		cout << it->_year << " " << it->_month << " " << it->_day << endl;
		++it;
	}
}
void tetsList3()
{
	List<int>lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	lst.PushBack(5);
	lst.PushBack(6);
	lst.PushBack(7);
	lst.PushBack(8);
	lst.PushBack(9);
	lst.PushBack(10);
	List<int>lst1(lst.begin(), lst.end());
	for (const auto &e : lst1)
	{
		cout << e << " ";
	}
	cout << endl;
	auto it = lst1.begin();
	while(it!=lst1.end())
	{
		if (*it % 2 == 0)
			it = lst.Erase(it);
		else
			++it; 
	}
	for (const auto& e : lst1)
	{
		cout << e << " "; 
	}
	cout << endl;
}
int main()
{
	//testList1();
	//testList2();
	tetsList3();
	return 0;
}