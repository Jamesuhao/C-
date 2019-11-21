//#1计算日期到天数转换
#if 0
/*
题目描述
根据输入的日期，计算是这一年的第几天。。
详细描述：
输入某年某月某日，判断这一天是这一年的第几天？
输入描述:
输入三行，分别是年，月，日
输出描述:
成功:返回outDay输出计算后的第几天;
失败:返回-1
示例1
输入
2012
12
31
输出
366
*/
#include<iostream>
using namespace std;
int main()
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	cin >> year >> month >> day;
	int num = 0;
	for (int i = 1; i < month; ++i)
	{
		num += days[i];
	}
	num += day;
	if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		num += 1;
	}
	return num;
}
#endif
//#2幸运的袋子
#if 0
/*
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。
如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。
现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)
输出描述:
输出可以产生的幸运的袋子数
示例1
输入
3
1 1 1
输出
2
*/
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int arr[1000];
int num = 0;
int getnum(int vec[], int pos, long sum, long mulit)
{
	int count = 0;
	for (int i = pos; i < num; ++i)
	{
		sum += vec[i];
		mulit *= vec[i];
		if (sum > mulit)
		{
			count += 1 + getnum(vec, i + 1, sum, mulit);
		}
		else if (vec[i] == 1)
		{
			count += getnum(vec, i + 1, sum, mulit);
		}
		else
		{
			break;
		}
		sum -= vec[i];
		mulit /= vec[i];
		for (; i < num - 1 && vec[i] == vec[i + 1]; ++i)
		{  }
	}
	return count;
}
int main()
{
	int n = 0;
	while (cin >> num)
	{
		for (int i = 0; i < num; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr+num);
		cout << getnum(vec, 0, 0, 1) << endl;
	}
	return 0;
}
#endif