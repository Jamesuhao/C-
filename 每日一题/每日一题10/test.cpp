//#1井字棋
#if 0
/*
题目描述
对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true
*/
#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board)
	{
		if (board[0][0] + board[1][1] + board[2][2] == 3)
			return true;
		if (board[2][2] + board[1][1] + board[0][0] == 3)
			return true;
		for (int i = 0; i < 3; ++i)
		{
			if (board[i][0] + board[i][1] + board[i][2] == 3)
				return true;
			if (board[0][i] + board[1][i] + board[2][i] == 3)
				return true;
		}
		return false;
	}
};
#endif

//#2密码强度等级
#if 0
/*
题目描述
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
一、密码长度:
5 分: 小于等于4 个字符
10 分: 5 到7 字符
25 分: 大于等于8 个字符
二、字母:
0 分: 没有字母
10 分: 全都是小（大）写字母
20 分: 大小写混合字母
三、数字:
0 分: 没有数字
10 分: 1 个数字
20 分: 大于1 个数字
四、符号:
0 分: 没有符号
10 分: 1 个符号
25 分: 大于1 个符号
五、奖励:
2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号
最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0:  非常弱
对应输出为：
VERY_WEAK,
WEAK,
AVERAGE,
STRONG,
VERY_STRONG,
SECURE,
VERY_SECURE
请根据输入的密码字符串，进行安全评定。
注：
字母：a-z, A-Z
数字：-9
符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
!"#$%&'()*+,-./     (ASCII码：x21~0x2F)
:;<=>?@				 (ASCII码：x3A~0x40)
[\]^_`					 (ASCII码：x5B~0x60)
{|}~					     (ASCII码：x7B~0x7E)
根据规则评定的安全等级。
输入描述:
输入一个string的密码
输出描述 :
输出密码等级
示例1
输入
38$@NoNoNo
输出
VERY_SECURE
*/
#include<iostream>
#include<string>
using namespace std;
int length(string& str1)
{
	int count = 0;
	if (str1.size() <= 4)
		count = 5;
	else if (str1.size() >= 5 && str1.size() <= 7)
		count = 10;
	else
		count = 25;
	return count;
}
int num(int flag1)
{
	int count = 0;
	if (flag1 == 1)
		count += 10;
	else if (flag1 > 1)
		count += 20;
	return count;
}
int fuhao(int flag4)
{
	int count = 0;
	if (flag4 == 1)
		count += 10;
	else if (flag4 > 1)
		count += 25;
	return count;
}
int reward(int flag1, int flag2, int flag3, int flag4)
{
	int count = 0;
	if (flag1 >= 1 && flag2 == 1 && flag3 == 1 && flag4 >= 1)
		count += 5;
	else if ((flag1 >= 1 && flag2 == 1 && flag3 == 0 && flag4 >= 1) ||
		(flag1 >= 1 && flag2 == 0 && flag3 == 1 && flag4 >= 1))
		count += 3;
	else if ((flag1 >= 1 && flag2 == 1 && flag3 == 0) ||
		(flag1 >= 1 && flag2 == 0 && flag3 == 1))
		count += 2;
	return count;
}
void Print(int count)
{
	if (count >= 90)
		cout << "VERY_WEAK" << endl;
	else if (count >= 80 && count < 90)
		cout << "WEAK" << endl;
	else if (count >= 70 && count < 80)
		cout << "AVERAGE" << endl;
	else if (count >= 60 && count < 70)
		cout << "STRONG" << endl;
	else if (count >= 50 && count < 60)
		cout << "VERY_STRONG" << endl;
	else if (count >= 25 && count < 50)
		cout << "SECURE" << endl;
	else
		cout << "VERY_SECURE" << endl;
}
int main()
{
	//33-126
	string str1;
	cin >> str1;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int flag4 = 0;
	int count = 0;
	auto it = str1.begin();
	while (it != str1.end())
	{
		if (*it >= '0' &&  *it <= '9')
			flag1 += 1;
		if (*it >= 'A' && *it <= 'Z')
			flag2 = 1;
		if (*it >= 'a' && *it <= 'z')
			flag3 = 1;
		if ((*it >= '!' && *it <= '/') || (*it >= ':' && *it <= '@') || (*it >= '[' && *it <= '`')
			|| (*it >= '{' && *it <= '~'))
			flag4 += 1;
	}
	count = length(str1);
	count += num(flag1);
	if ((flag2 == 1 && flag3 == 0) || (flag2 == 0 && flag3 == 1))
		count += 10;
	else if (flag2 == 1 && flag3 == 1)
		count += 2;
	count += fuhao(flag4);
	count += reward(flag1, flag2, flag3, flag4);
	Print(count);
	return 0;
}
#endif