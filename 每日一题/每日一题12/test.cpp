//#1�����Ʋ���
#if 0
/*
��Ŀ������
������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬
��m�Ķ�����λ��С�ڵ���i-j+1��
����������
1024��19��2��6
���أ�1100
*/
#include<iostream>
using namespace std;
int main()
{
	int n, m, i, j;
	cin >> n >> m >> i >> j;
	return (m << i) | n;
}
#endif

//#2�������һ��ż���������������
#if 0
/*
��Ŀ������
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
����ĿҪ��������ָ��ż��������������ֵ��С��������
��������:
����һ��ż��
�������:
�����������
ʾ��1
����
20
���
7
13
*/
#include<iostream>
using namespace std;
bool isPrimary(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int input = 0;
	while (cin >> input)
	{
		for (int i = input / 2; i > 2; --i)
		{
			if (isPrimary(i) && isPrimary(input - i))
			{
				cout << i << endl;
				cout << input - i << endl;
				break;
			}
		}
	}
	return 0;
}
#endif