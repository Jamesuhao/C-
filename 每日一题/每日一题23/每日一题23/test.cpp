//#1元素查找
#if 0
/*
题目描述
有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],现在对于移位后的数组，需要查找某个元素的位置。
请设计一个复杂度为log级别的算法完成这个任务。

给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。

测试样例：
[6,1,2,3,4,5],6,6
返回：0

二分查找的进阶版，大体思路以二分查找为主体，加一些限制条件。
题目中给出这是一个排过序的数组，所以在移位之后，数组一定是被某元素为分割成两个递增的序列
*/

#include<iostream>
#include<vector>
using namespace std;
int FindElement(vector<int>vec, int n, int x)
{
	int  left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		//vec[mid]==x;找到该元素，直接返回下标
		if (vec[mid] == x)
		{
			return mid;
		}
		//vec[mid]<x；重新规划查找区间
		else if (vec[mid] < x)
		{
			/*
			先判断mid的哪边有序
			vec[mid]<vec[left]：mid的右边有序
			再判断查找元素所在区间
			x>vec[right]：查找元素一定在mid的左边
			*/
			if (vec[mid] < vec[left] && x > vec[right])
			{
				right = mid - 1;
			}
			//其余情况查找元素均在mid的右边
			else
			{
				left = mid + 1;
			}
		}
		//vec[mid]>x;重新规划查找区间
		else
		{
			/*
			先判断mid的哪边是有序的
			vec[mid]>vec[left]：mid的左边一定是有序的
			再判断查找元素所在区间
			x<vec[left]：查找元素一定在mid的右边
			*/
			if (vec[mid] > vec[left] && x < vec[left])
			{
				left = mid + 1;
			}
			//其余情况所查找的元素一定在mid的左边
			else
			{
				right = mid - 1;
			}
		}
	}
}
int main()
{
	int n, x;
	cin >> n >> x;
	vector<int>vec(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}
	cout << FindElement(vec, n, x) << endl;
	return 0;
}
#endif

//#2字符集合
#if 0
/*
题目描述
输入一个字符串，求出该字符串包含的字符集合
输入描述:
每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
输出描述:
每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
示例1
输入
abcqweracb
输出
abcqwer
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		vector<int>vec(256, 0);
		for (int i = 0; i < str.size(); ++i)
		{
			if (vec[str[i] - '0'] == 0)
			{
				cout << str[i];
			}
			++vec[str[i] - '0'];
		}
		cout << endl;
	}
	return 0;
}
#endif