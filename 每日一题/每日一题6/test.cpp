//#1��Ҫ��
#if 0
/*
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��
ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
��������:
ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)
�������:
���һ�������Էŵĵ�����
ʾ��1
����
3 2
���
4
*/
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int c = a * b / 2;
	if (b % 4 == 0)
		cout << c << endl;
	else
		cout << c + 1 << endl;
	return 0;
}
#endif

//#2���ַ���ת��������
#if 0
/*
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
��������:
����һ���ַ���,����������ĸ����,����Ϊ��
�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
ʾ��1
����
+2147483647
	1a33
���
2147483647
	0
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string str)
	{
		int flag = 1;
		int ret = 0;
		int size = (str.size() < 10) ? str.size() : str.size() - 1;
		int i = 0;
		for (i = 0; i < size; ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				ret = ret * 10 + str[i] - '0';
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				if (str[i] == '-')
					flag = -1;
			}
			else
				return 0;
		}
		if (str.size() > 9)
		{
			if ((flag == 1 && str[i] - '0' > 7) || (flag == -1 && str[i] - '0' > 8))
			{
				return 0;
			}
			ret = ret * 10 + str[i] - '0';
		}
		return ret * flag;
	}
};
#endif
