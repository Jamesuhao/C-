//#1计算糖果
#if 0
/*
题目描述
A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
输入描述 :
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。
输出描述 :
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 
如果不存在这样的整数A，B，C，则输出No
示例1
输入
1 - 2 3 4
输出
2 1 3
*/
#include<iostream>
using namespace std;
int main()
{
	int arr1[4];
	int arr2[3];
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr1[i];
	}
	if ((arr1[0] + arr1[2]) % 2 != 0 || (arr1[0] + arr1[2]) < 0 || (arr1[1] + arr1[3]) < 0)
	{
		cout << "No" << endl;
		return 0;
	}
	arr2[0] = (arr1[0] + arr1[2]) / 2;
	arr2[1] = arr2[0] - arr1[0];
	arr2[2] = arr1[3] - arr2[1];
	for (int i = 0; i < 3; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif

//#2进制转换

#if 0
/*
题目描述
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
输入
7 2
输出
111
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str1 = "0123456789ABCDEF";
	string str2;
	int a, b, flag = 1;
	cin >> a >> b;
	if (a < 0)
	{
		flag = 0;
		a = -a;
	}
	while (a)
	{
		str2 = str1[a % b];
		a /= b;
	}
	reverse(str2.begin(), str2.end());
	if (flag == 0)
		str2 = "-" + str2;
	cout << str2 << endl;
	return 0;
}
#endif