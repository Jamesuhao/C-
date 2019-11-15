//#1
#if 0
/*
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值
测试样例：
1,2
返回：3
*/
#include<iostream>
using namespace std;
int add(int a, int b)
{
	if (b == 0)
		return a;
	int sum = a ^ b;
	int carry = (a & b) << 1;
	return add(sum, carry);
}
#endif

//#2
#if 0
/*
题目描述
请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，
即：只能往右和往下走，不能往左和往上走。
输入描述:
输入两个正整数
输出描述:
返回结果
示例1
输入
2
2
输出
6
*/
#include<iostream>
using namespace std;
int number(int n, int m)
{
	if (n > 1 && m > 1)
		return number(n - 1, m) + number(n, m - 1);
	else if ((n == 1 && m >= 1) || (n >= 1 && m == 1))
		return n + m;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << number(a, b) << endl;
	return 0;
}
#endif