//#1不要二
#if 0
/*
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。
每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
输入描述:
每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000)
输出描述:
输出一个最多可以放的蛋糕数
示例1
输入
3 2
输出
4
*/
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int c = a * b / 2;
	if (b % 4 == 0)
		cout << c << endl;
	else
		cout << c + 1 << endl;
	return 0;
}
#endif

//#2把字符串转换成整数
#if 0
/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
	1a33
输出
2147483647
	0
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string str)
	{
		int flag = 1;
		int ret = 0;
		int size = (str.size() < 10) ? str.size() : str.size() - 1;
		int i = 0;
		for (i = 0; i < size; ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				ret = ret * 10 + str[i] - '0';
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				if (str[i] == '-')
					flag = -1;
			}
			else
				return 0;
		}
		if (str.size() > 9)
		{
			if ((flag == 1 && str[i] - '0' > 7) || (flag == -1 && str[i] - '0' > 8))
			{
				return 0;
			}
			ret = ret * 10 + str[i] - '0';
		}
		return ret * flag;
	}
};
#endif
