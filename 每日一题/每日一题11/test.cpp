//#1最近公共最先
#if 0
/*
题目描述
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
测试样例：
2，3
返回：1
解题思路：
思路：满二叉树的子节点与父节点之间的关系为root = child / 2
利用这个关系，如果a ！= b，就让其中的较大数除以2， 如此循环知道a == b，
即是原来两个数的最近公共祖先
*/
#include<iostream>
using namespace std;
int getC(int a, int b)
{
	if (a == 1 || b == 1)
		return 1;
	while (a != b)
	{
		if (a > b)
			a /= 2;
		else
			b /= 2;
	}
	return a;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << getC(a, b) << endl;
	return 0;
}
#endif
//#2求最大连续bit数
#if 0
/*
题目描述
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
输入: 一个byte型的数字
输出: 无
返回: 对应的二进制数字中1的最大连续数
输入描述:
输入一个byte数字
输出描述:
输出转成二进制之后连续1的个数
示例1
输入
3
输出
2
*/
#include<iostream>
#include<vector>
using namespace std;
int num(vector<int>&vec,int n)
{
	int count = 1;
	int count1 = 1;
	int i = 0;
	for (i = 0; n != 0; ++i)
	{
		vec[i] = n % 2;
		n /= 2;
	}
	for (; i > 0; --i)
	{
		if (vec[i] == 1 && vec[i] == vec[i - 1])
		{
			++count;
			if (count > count1)
				count1 = count;
		}
		else
			count = 1;
	}
	return count1;
}
int main()
{
	int m = 0;
	while (cin >> m)
	{
		vector<int>vec(32);
		cout << num(vec, m) << endl;
	}
	return 0;
}
#endif