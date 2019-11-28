//#1字符串反转
#if 0
/*
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符
输出描述:
输出该字符串反转后的字符串
示例1
输入
abcd
输出
dcba
*/
#include<iostream>
#include<string>
using namespace std;
void Swap(char& a, char& b)
{
	auto tmp = a;
	a = b;
	b = tmp;
}
void Reverse(string& str)
{
	auto start = str.begin();
	auto end = str.end() - 1;
	while (start != end)
	{
		Swap(*start, *end);
		++start;
		--end;
	}
	cout << str << endl;
}
int main()
{
	string str;
	while (cin >> str)
	{
		Reverse(str);
	}
	return 0;
}
#endif
//#2公共字串计算
#if 0
/*
题目描述
题目标题：
计算两个字符串的最大公共字串的长度，字符不区分大小写
输入描述:
输入两个字符串
输出描述:
输出一个整数
示例1
输入
复制
asdfas werasdfaswer
输出
复制
6
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Maxcount(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int max = 0;
	vector<vector<int>>vec(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			if (vec[i][j] > max)
			{
				max = vec[i][j];
			}
		}
	}
	return max;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << Maxcount(str1, str2) << endl;
	}
	return 0;
}
#endif