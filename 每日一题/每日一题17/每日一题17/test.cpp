//#1������ǵı�������
#if 0
/*
��Ŀ����
			1

		 1  1  1

	  1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

���������ε����󣬵�һ��ֻ��һ����1��
����ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��
����n(n <= 1000000000)
��������:
����һ��int����
�������:
������ص�intֵ
ʾ��1
����
4
���
3
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>> vec(n, vector<int>(m, 0));
		vec[0][n - 1] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				vec[i][j] = vec[i - 1][j] + vec[i - 1][j - 1] + vec[i - 1][j + 1];
			}
		}
		int i = 0;
		for (i = 0; i < m; ++i)
		{
			if (vec[n - 1][i] % 2 == 0 && vec[n - 1][i] != 0)
			{
				cout << i + 1 << endl;
				break;
			}
		}
		if (i == m)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
#endif

//#2
#if 0
/*
��Ŀ����
�����һ���㷨������������������ļӷ���
��������:
���������ַ�������
������� :
�����Ӻ�Ľ����string��
ʾ��1
����
99999999999999999999999999999999999999999999999999
1
���
100000000000000000000000000000000000000000000000000
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		while (str1.size() > str2.size())
		{
			str2 = "0" + str2;
		}
		while (str1.size() < str2.size())
		{
			str1 = "0" + str1;
		}
		int tmp = 0, carry = 0;
		for (int i = str1.size() - 1; i >= 0; --i)
		{
			tmp = str1[i] - '0' + str2[0] - '0' + carry;
			str1[i] = tmp % 10 + '0';
			if (tmp / 10)
			{
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		if (carry)
		{
			str1 = "0" + str1;
		}
		cout << str1 << endl;
	}
	return 0;
}
#endif