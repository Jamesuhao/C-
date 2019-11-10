//#1统计回文
#if 0
/*
题目描述
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。
你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后: "abba" 是回文
* 在字母‘b’之后: "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2
输入描述:
每组输入数据共两行。
第一行为字符串A
第二行为字符串B
字符串长度均小于100且只包含小写字母
输出描述:
输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
示例1
输入
aba
b
输出
2
*/
#include<iostream>
#include<string>
using namespace std;
bool a(const string& str)
{
	auto start = str.begin();
	auto end = str.end() - 1;
	while (start <= end)
	{
		if (*start == *end)
		{
			++start;
			--end;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	string str1, str2, tmp;
	int count = 0;
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.size() + 1; ++i)
	{
		tmp = str1;
		tmp.insert(i, str2);
		if (a(tmp))
			count++;
	}
	cout << count << endl;
	return 0;
}
#endif

//#2连续最大和
#if 0
/*
题目描述
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素, 每个整数都在32位int范围内。以空格分隔。
输出描述 :
所有连续子数组中和最大的值。
示例1
输入
3 - 1 2 1
输出
3
*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;
	int sum = 0;
	int result = INT_MIN;
	vector<int>vec(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> vec[i];
	}
	for (int i = 0; i < size; ++i)
	{
		sum += vec[i];
		if (sum > result)
			result = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << result << endl;
	return 0;
}
#endif