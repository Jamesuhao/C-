//#1小易的升级之路
# if 0
/*
题目描述
小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.
在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 
如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,
并且使得自己的能力值增加bi;如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.
那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
输入描述:
对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值.
第二行n个整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力
输出描述:
对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值
示例1
输入
3 50
50 105 200
5 20
30 20 15 40 100
输出
110
205
题目分析：
初始能力值：a
当前能力值：c
怪物防御力：bi
c>=bi   c=c+bi
c<bi     c=c+(c和bi的最大公约数)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//求最大公约数
int Bigcommondivisor(int x, int y)
{
	if (x < y)
	{
		swap(x, y);
	}
	while (y)
	{
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}
int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int>vec(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
			//当前能力值>=怪物防御力
			if (a >= vec[i])
			{
				a += vec[i];
			}
			//当前能力值<怪物防御力
			else
			{
				a += Bigcommondivisor(a, vec[i]);
			}
		}
		cout << a << endl;
	}
	return 0;
}

//#2找出字符串中第一个只出现一次的字符
/*
找出字符串中第一个只出现一次的字符
输入描述:
输入一个非空字符串
输出描述:
输出第一个只出现一次的字符，如果不存在输出-1
示例1
输入
asdfasdfo
输出
o
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
		bool flag = 1;
		vector<int>vec(26, 0);
		for (int i = 0; i < str.size(); ++i)
		{
			++vec[str[i] - 'a'];
		}
		for (int i = 0; i < str.size(); ++i)
		{
			if (vec[str[i] - 'a'] == 1)
			{
				cout << str[i] << endl;
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << "-1" << endl;
		}
	}
	return 0;
}
#endif