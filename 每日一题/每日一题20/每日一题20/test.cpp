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
void Reverse(string& str)
{
	auto start = str.begin();
	auto end = str.end() - 1;
	while (start <= end)
	{
		swap(*start, *end);
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
asdfas 
werasdfaswer
输出
6
解题思路：
求最大公共子串，使用递推实现 假设 x(i): 字符串第i个字符 y(j): 字符串第j个字符 
vec[i][j]: 以x(i),y(j)结尾的最大子串长度 比如：x: "abcde" y:"bcdae"
vec[2][1]: 以x(2),y(1)结尾的最大子串长度 即：x遍历到"abc", y遍历到"bc", 都以字符'c'结尾时最大公共子串为"bc" 
故：当计算vec[i][j]时，首先看x(i),y(j)的值： 
(1）: x(i) == y(j)
当前两个字符串结尾的字符相等，vec[i][j] = vec[i-1][j-1] + 1 即个它的长度加1 
(2）: x(i) != y(j) 
当前两个字符串结尾的字符不相等，说明没有以这连个字符结尾的公共子串 即dp[i][j] = 0 
(3）: dp[0][j] 和 dp[i][0]表示以某个子串的第一个字符结尾，最大长度为1 如果x(0) == y(j) 或者 x(i) == y(0), 则长度为1，否则为0 
当dp中的所有元素计算完之后，从中找打最大的值输出
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
	for (int i = 0; i <= len1; ++i)
	{
		for (int j = 0; j <= len2; ++j)
		{
			//如果当前结尾的字符相等，则在vec[i-1][j-1]的基础上加1
			if (str1[i] == str2[j])
			{
				if (i >= 1 && j >= 1)
				{
					vec[i][j] = vec[i - 1][j - 1] + 1;
				}
				else//vec[i][0] or vec[0][j]
				{
					vec[i][j] = 1;
				}
			}
			//更新最大值
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