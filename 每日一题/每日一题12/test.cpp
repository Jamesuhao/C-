//#1二进制插入
#if 0
/*
题目描述：
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，
且m的二进制位数小于等于i-j+1。
测试样例：
1024，19，2，6
返回：1100
*/
#include<iostream>
using namespace std;
int main()
{
	int n, m, i, j;
	cin >> n >> m >> i >> j;
	return (m << i) | n;
}
#endif

//#2查找组成一个偶数最近的两个素数
#if 0
/*
题目描述：
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数
输出描述:
输出两个素数
示例1
输入
20
输出
7
13
*/
#include<iostream>
using namespace std;
bool isPrimary(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int input = 0;
	while (cin >> input)
	{
		for (int i = input / 2; i > 2; --i)
		{
			if (isPrimary(i) && isPrimary(input - i))
			{
				cout << i << endl;
				cout << input - i << endl;
				break;
			}
		}
	}
	return 0;
}
#endif