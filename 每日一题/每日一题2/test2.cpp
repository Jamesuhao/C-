#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
//#1倒置字符串
/*
题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割
示例1 
输入
I like beijing.
输出
beijing. like I
*/
//解法一：
int main()
{
	string str;
	getline(cin, str);
	auto begin = str.begin();
	auto end = str.end();
	auto start = begin;
	reverse(str.begin(), str.end());
	while (begin != end)
	{
		++start;
		if (start == end ||*start == ' ')
		{
			reverse(begin, start);
			if (start == end)
				begin = start;
			else
				begin = start + 1;
		}
	}
	cout << str << endl;
	return 0;
}
//解法二：
int main()
{
	string str1, str2;
	cin >> str1;
	while (cin >> str2)
	{
		str1 = str1 + " " + str2;
	}
	cout << str1 << endl;
	return 0;
}


//#2排序子序列
/*
题目描述：牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,
牛牛想知道他最少可以把这个数组分为几段排序子序列.
 如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2

 输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。

输出描述:
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
示例1
输入
6
1 2 3 2 2 1
输出
2

解题思路：
1.本题要求求解排序子序列，主要需要理解“非递增、非递减”这个概念，不需要纠结这个概念。
非递减就是：a[i]<=a[i+1]，递减就是a[i]>a[i+1]，同理非递增就是a[i]>=a[i+1]，递增就是a[i]<a[i+1]。对于这个确定的概念没什么好讲的，不理解时上网查找补充该概念即可。
当理解排序子序列后，可以将这些数值画到一个坐标图纸中，本质就是去找这里面的非相邻波峰和波谷的个数，一个波峰会将不在排序子序列中的元素向左包含，碰到首元素、波谷停止包含。一个波谷会将不在排序子序列中的元素向右包含，碰到波峰、尾元素停止。非相邻的波峰波谷像道路种树一样，两棵树会将道路分成3部分，即会产生3个排序子序列，结果即为非相邻波峰和波谷的个数再加1。

总结来讲：
最终进行波峰/波谷求解判断的for循环中vector向量下标从1到n-2，统计非相邻波峰/波谷((a[i]>a[i-1]&&a[i]>a[i+1]) || (a[i]<a[i-1]&&a[i]<a[i+1]))的个数ret。
值得注意的是当上述循环最后一个波峰/波谷下标为n-3(倒数第三个元素)时，需要判断下标为n-2(倒数第2个元素)的数是否为波峰/波谷，如果是ret+=1
最后输出ret+1。

注意：
1.不考虑非相邻波峰波谷时会导致在特殊情况下重复计算，如序列1 2 1 2 1 2 1 2 1，其正确输出为5，但错误输出为8。
2.不考虑"值得注意情况时"会产生结果少1的错误答案。由于计算的是非相邻波峰波谷，中间会添加一个i++的操作，
即判断波峰波谷的元素总是第2 个、第4个，中间会跳出一个元素避免重复运算，由于第一个、最后一个元素没办法进行波峰波谷的计算，
当倒数第三个元素为波峰波谷时，进行i++操作，加上for循环内部i++不会判断最后一个元素而直接结束循环，
但后面3个元素不一定做到整体有序，无法整体构成一个排序子序列，需要判断倒数第二个元素是否为波峰波谷，
即若倒数第三元素为波峰，倒数第二元素为波谷时有效，反之亦然，此时需要将三个元素进行两两分解，会多一个子序列。
如果不考虑情况二的话，会在一定情况下产生排序子序列比正确答案少1的错误答案。
*/

int main()
{
	vector<int>vec;
	int num = 0;
	int ret = 1;
	cin >> num;
	vec.resize(num);
	for (int i = 0; i < num; ++i)
		cin >> vec[i];
	for (int i = 1; i < num - 1; ++i)
	{
		if ((vec[i - 1] > vec[i] && vec[i] < vec[i + 1])
			|| (vec[i - 1]<vec[i] && vec[i]>vec[i + 1]))
		{
			ret++;
			if (i != num - 3)
				i++;
		}
	}
	cout << ret << endl;
	return 0;
}