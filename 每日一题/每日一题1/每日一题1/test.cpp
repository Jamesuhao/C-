#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
/*
#1：组队竞赛
链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b
来源：牛客网
牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
  例如:
  一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
  一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
  一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
  为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
  如样例所示:
  如果牛牛把6个队员划分到两个队伍
  如果方案为:
  team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
  而如果方案为:
  team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
  没有比总和为10更大的方案,所以输出10.
输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
输出描述:
输出一个整数表示所有队伍的水平值总和最大值.
示例1
输入
2
5 2 8 5 1 5
输出
10
解题思路：
先排序                   
比如排完序 1 2 3 4 5 6 7 8 9 这九个数
组队思路是这样的：
第一个以及最后两个组一队 1 8 9   
剩下 2 3 4 5 6 7                   
第一个及最后两个组一队2 6 7                   
剩下3 4 5                   
就是第一个和最后两个 再把已经组队的删掉 然后在循环 第一个以及最后两个
那么中位数可以看到是 8 6 4                   
找到中位数在整个排序后的素组和下标的规则是 data[data.length-(2*(i+1))]                  
再加在一起                   
最重要的是 result一定要是long的 一定 一定 int会越界
*/
int main()
{
	int n;
	long long ret = 0;
	cin >> n;
	vector<int>vec(3 * n);
	for (int i = 0; i < 3*n; ++i)
		cin >> vec[i];
	for (int i = 1; i <= n; ++i)
	{
		ret += vec[3 * n - i * 2];
	}
	cout << ret << endl;
	return 0;
}


/*
#2：删除公共字符
题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串
示例1
输入：
They are students.
aeiou
输出：
Thy r stdnts.
解题思路：
开辟一个大小为256的数组空间，在该数组中将字符串2的所有字符以其acsll值为下标的位置全部置为1
在该数组中将字符串1的所有字符以其acsll值为下标的位置中为0的字符输出即可
*/
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	auto it1 = str1.begin();
	auto it2 = str2.begin();
	int tmp[256] = { 0 };
	for (; it2 != str2.end(); ++it2)
	{
		tmp[*it2] = 1;
	}
	for (; it1 != str1.end(); ++it1)
	{
		if (tmp[*it1] == 0)
			cout << *it1;
	}
	cout << endl;
	return 0;
}
#endif