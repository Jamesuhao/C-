//#1查找两个字符串a,b中的最长公共子串
/*
题目描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int start = 0;
		int count = 0;
		if (len1 > len2)
		{
			swap(str1, str2);
		}
		vector<vector<int>>vec(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					vec[i][j] = vec[i - 1][j - 1]+1;
				}
				if (vec[i][j] > count)
				{
					count = vec[i][j];
					start = i - count;
				}
			}
		}
		cout << str1.substr(start, count) << endl;
	}
}