//#1字符串中找出连续最长的数字串
#if 0
/*
题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入
abcd12345ed125ss123456789
输出
123456789
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	getline(cin, str1);
	int count = 1;
	int len = 0;
	auto it = str1.begin() + 1;
	auto it1 = str1.begin();
	for (; it != str1.end()-1; ++it)
	{
		if ((*it + 1) == *(it + 1))
		{
			++count;
			if (count > len)
			{
				len = count;
				it1 = it + 1 - len;
			}
		}
		else
		{
			count = 1;
		}
	}
	for (auto ch=it1+1; ch != it1+len+1; ++ch)
	{
		cout << *ch;
	}
	cout << endl;
	return 0;
}
#endif

//#2数组中出现次数超过一半的数字
#if 0
/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int count = 1;
		int size = 1;
		auto it1 = numbers.begin();
		auto it2 = numbers.begin();
		sort(numbers.begin(), numbers.end());
		for (; it1 != numbers.end() - 1; ++it1)
		{
			if (*it1 == *(it1 + 1))
			{
				++count;
				if (count > size)
				{
					it2 = it1;
					size = count;
				}
			}
			else
				count = 1;
		}
		if (size > numbers.size() / 2)
		{
			return *it2;
		}
		else
		{
			return 0;
		}
	}
};
int main()
{
	Solution sou;
	vector<int>vec;
	for (int i = 0; i < 1; i++)
	{
		int a = 0;
		cin >> a;
		 vec.push_back(a);
	}
	cout << sou.MoreThanHalfNum_Solution(vec) << endl;
}
#endif

//#3在字符串中找出连续最长的数字串
#if 0
/*
题目描述
样例输出
输出123058789，函数返回值9
输出54761，函数返回值5
输入描述:
输入一个字符串。
输出描述:
输出字符串中最长的数字字符串和它的长度。如果有相同长度的串，则要一块儿输出，但是长度还是一串的长度
示例1
输入
abcd12345ed125ss123058789
输出
123058789,9
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int count = 0;
	int len = 0;
	auto it2 = str.begin();
	if (*it2 == '\0')
	{
		cout << *it2 << " " << "0" << endl;
		return 0;
	}
	auto it1 = str.begin() ;
	for (; it1 != str.end(); ++it1)
	{
		if (*it1 >= '0' && *it1 <= '9')
		{
			count++;
			if (count > len)
			{
				len = count;
				it2 = it1 + 1 - len;
			}
		}
		else
		{
			count = 0;
		}
	}
	if (len == 0)
	{
		*it2 = '\0';
		cout << *it2 << " " << "0" << endl;
	}
	auto ch = it2 ;
	for (; ch != it2  + len; ++ch)
	{
		cout << *ch;
	}
	cout <<","<< len << endl;
	return 0;
}
#endif