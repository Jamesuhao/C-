//#1统计每个月兔子的总数
#if 0
/*
题目描述
有一只兔子，
从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，
假如兔子都不死，问每个月的兔子总数为多少？
输入描述:
输入int型表示month
输出描述:
输出兔子总数int型
示例1
输入
9
输出
34
*/
#include<iostream>
using namespace std;
int main()
{
	int month = 0;
	while (cin >> month)
	{
		int num = 0;
		int first = 1;
		int second = 1;
		for (int i = 3; i <= month; ++i)
		{
			num = first + second;
			first = second;
			second = num;
		}
		cout << num << endl;
	}
	return 0;
}
#endif

//#2字符串通配符
#if 0
/*
通配符：
通配符是一类键盘字符。
当查找文件夹时；当不知道真正字符或者不想键入完整名字时，常常使用通配符代替一个或多个真正字符。
通配符包括星号“*”和问号“？”
(1)星号（*）
可以使用星号代替零个、单个或多个字符。
如果正在查找以AEW开头的一个文件，但不记得文件名其余部分，可以输入AEW*，
查找以AEW开头的所有文件类型的文件，如AEWT.txt、AEWU.EXE、AEWI.dll等。
要缩小范围可以输入AEW*.txt，查找以AEW开头的所有文件类型并.txt为扩展名的文件如AEWIP.txt、AEWDF.txt。
(2)问号（？）
可以使用问号代替一个字符。
如果输入love?，查找以love开头的一个字符结尾文件类型的文件，如lovey、lovei等。
要缩小范围可以输入love?.doc，查找以love开头的一个字符结尾文件类型并.doc为扩展名的文件如lovey.doc、loveh.doc。

星号表示匹配的数量不受限制，而问号的匹配字符数则受到限制。
这个技巧主要用于英文搜索中，如输入““computer*”，就可以找到“computer、computers、computerised、computerized”等单词，
而输入“comp?ter”，则只能找到“computer、compater、competer”等单词。
*/
/*
题目描述
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。
现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符
输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
输出描述:
返回匹配的结果，正确输出true，错误输出false
示例1
输入
te?t*.*
txt12.xls
输出
false
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2))
	{
		auto it1 = str1.begin();
		auto it2 = str2.begin();
		while (it1 != str1.end() && it2 != str2.end())
		{
			//两个字符串当前位置字符不相同并且通配符表达式不等于'*'或者'?'时，
			//输出false
			if ((*it1 != *it2) && (*it1 != '?') && (*it1 != '*'))
			{
				cout << "false" << endl;
				break;
			}
			//两个字符串当前位置字符不相同并且通配符表达式等于'*'，
			//如果下一个位置两个字符不同并且通配符表达式不等于'?'时
			//输出false
			else if ((*it1 != *it2)
				&& (*it1 == '*')
				&& (*(it1 + 1) != *(it2 + 1)
					&& *(it1 + 1) != '?'))
			{
				cout << "false" << endl;
				break;
			}
			++it1;
			++it2;
		}
		//当通配符表达式走到最后时，则说明两字符串匹配
		//输出true
		if (it1 == str1.end())
		{
			cout << "true" << endl;
		}
	}
	return 0;
}
#endif