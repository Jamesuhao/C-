#if 0
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
#endif 
//#2汽水瓶问题
#if 0
/*
题目描述
有这样一道智力题:
某商店规定：三个空汽水瓶可以换一瓶汽水。
小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，
方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
输入描述 :
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1 <= n <= 100），
表示小张手上的空汽水瓶数。n = 0表示输入结束，你的程序不应当处理这一行。
输出描述 :
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
示例1
输入
3
10
81
0
输出
1
5
40
*/
#include<iostream>
using  namespace std;
int calculateNum(int number)
{
	//表示共可换的汽水数
	int sum = 0;
	while (number > 1)
	{
		//当前空瓶数可兑换的汽水数
		sum += number/ 3;
		//更新空瓶数
		number = number % 3 + number / 3;
		//当空瓶数剩余2瓶数，仅可兑换一瓶汽水
		if (number == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}
int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << calculateNum(num) << endl;
	}
	return 0;
}
#endif