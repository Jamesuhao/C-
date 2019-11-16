//#1������
#if 0
/*
��Ŀ����
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ����ӡ�
����������
[[1,0,1],[1,-1,-1],[1,-1,0]]
���أ�true
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

//#2����ǿ�ȵȼ�
#if 0
/*
��Ŀ����
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
һ�����볤��:
5 ��: С�ڵ���4 ���ַ�
10 ��: 5 ��7 �ַ�
25 ��: ���ڵ���8 ���ַ�
������ĸ:
0 ��: û����ĸ
10 ��: ȫ����С����д��ĸ
20 ��: ��Сд�����ĸ
��������:
0 ��: û������
10 ��: 1 ������
20 ��: ����1 ������
�ġ�����:
0 ��: û�з���
10 ��: 1 ������
25 ��: ����1 ������
�塢����:
2 ��: ��ĸ������
3 ��: ��ĸ�����ֺͷ���
5 ��: ��Сд��ĸ�����ֺͷ���
�������ֱ�׼:
>= 90: �ǳ���ȫ
>= 80: ��ȫ��Secure��
>= 70: �ǳ�ǿ
>= 60: ǿ��Strong��
>= 50: һ�㣨Average��
>= 25: ����Weak��
>= 0:  �ǳ���
��Ӧ���Ϊ��
VERY_WEAK,
WEAK,
AVERAGE,
STRONG,
VERY_STRONG,
SECURE,
VERY_SECURE
���������������ַ��������а�ȫ������
ע��
��ĸ��a-z, A-Z
���֣�-9
���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
!"#$%&'()*+,-./     (ASCII�룺x21~0x2F)
:;<=>?@				 (ASCII�룺x3A~0x40)
[\]^_`					 (ASCII�룺x5B~0x60)
{|}~					     (ASCII�룺x7B~0x7E)
���ݹ��������İ�ȫ�ȼ���
��������:
����һ��string������
������� :
�������ȼ�
ʾ��1
����
38$@NoNoNo
���
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