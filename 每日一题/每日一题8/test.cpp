//#1两种排序方式
#if 0
/*
题目描述
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
如果根据长度排列而不是字典序排列输出"lengths",
如果两种方式都符合输出"both"，否则输出"none"
示例1
输入
3
a
aa
bbb
输出
both
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n = 0, flag1 = 1, flag2 = 1;
	cin >> n;
	vector<string>vec(n);
	for (int i=0; i < n; ++i)
	{
		cin >> vec[i];
	}
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		if (vec[i] > vec[i + 1])
			flag1 = 0;
	}
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		if (vec[i].size() > vec[i + 1].size())
			flag2 = 0;
	}
	if (flag1 && flag2)
		cout << "both" << endl;
	else if (flag1 && !flag2)
		cout << "lexicographically" << endl;
	else if (flag2)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}
#endif

//#2最小公倍数
#if 0
/*
题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
输入描述:
输入两个正整数A和B。
输出描述:
输出A和B的最小公倍数。
示例1
输入
5 7
输出
35
*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, i = 1;
	cin >> a >> b;
	while (1)
	{
		if ((a * i) % b == 0)
		{
			cout << a * i << endl;
			break;
		}
		else
			++i;
	}
	return 0;
}
#endif