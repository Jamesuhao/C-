//#1�ַ������ҳ�����������ִ�
#if 0
/*
��Ŀ����
����һ���ַ���str������ַ���str�е�����������ִ�
��������:
�������������1������������һ���ַ���str�����Ȳ�����255��
�������:
��һ�������str��������������ִ���
ʾ��1
����
abcd12345ed125ss123456789
���
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

//#2�����г��ִ�������һ�������
#if 0
/*
��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
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

//#3���ַ������ҳ�����������ִ�
#if 0
/*
��Ŀ����
�������
���123058789����������ֵ9
���54761����������ֵ5
��������:
����һ���ַ�����
�������:
����ַ�������������ַ��������ĳ��ȡ��������ͬ���ȵĴ�����Ҫһ�����������ǳ��Ȼ���һ���ĳ���
ʾ��1
����
abcd12345ed125ss123058789
���
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