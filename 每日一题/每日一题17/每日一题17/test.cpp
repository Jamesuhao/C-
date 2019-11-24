//#1杨辉三角的变形问题
#if 0
/*
题目描述
			1

		 1  1  1

	  1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

以上三角形的数阵，第一行只有一个数1，
以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。
输入n(n <= 1000000000)
输入描述:
输入一个int整数
输出描述:
输出返回的int值
示例1
输入
4
输出
3
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>> vec(n, vector<int>(m, 0));
		vec[0][n - 1] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				vec[i][j] = vec[i - 1][j] + vec[i - 1][j - 1] + vec[i - 1][j + 1];
			}
		}
		int i = 0;
		for (i = 0; i < m; ++i)
		{
			if (vec[n - 1][i] % 2 == 0 && vec[n - 1][i] != 0)
			{
				cout << i + 1 << endl;
				break;
			}
		}
		if (i == m)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
#endif

//#2
#if 0
/*
题目描述
请设计一个算法完成两个超长正整数的加法。
输入描述:
输入两个字符串数字
输出描述 :
输出相加后的结果，string型
示例1
输入
99999999999999999999999999999999999999999999999999
1
输出
100000000000000000000000000000000000000000000000000
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		while (str1.size() > str2.size())
		{
			str2 = "0" + str2;
		}
		while (str1.size() < str2.size())
		{
			str1 = "0" + str1;
		}
		int tmp = 0, carry = 0;
		for (int i = str1.size() - 1; i >= 0; --i)
		{
			tmp = str1[i] - '0' + str2[0] - '0' + carry;
			str1[i] = tmp % 10 + '0';
			if (tmp / 10)
			{
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		if (carry)
		{
			str1 = "0" + str1;
		}
		cout << str1 << endl;
	}
	return 0;
}
#endif