#if 0
//#1���������ַ���a,b�е�������Ӵ�
/*
��Ŀ����
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
��������:
���������ַ���
�������:
�����ظ����ֵ��ַ�
ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw
���
jklmnop
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int start = 0;
		int count = 0;
		if (len1 > len2)
		{
			swap(str1, str2);
		}
		vector<vector<int>>vec(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					vec[i][j] = vec[i - 1][j - 1]+1;
				}
				if (vec[i][j] > count)
				{
					count = vec[i][j];
					start = i - count;
				}
			}
		}
		cout << str1.substr(start, count) << endl;
	}
}
#endif 
//#2��ˮƿ����
#if 0
/*
��Ŀ����
������һ��������:
ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��
С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ��
�������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�
Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣
���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
�������� :
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1 <= n <= 100����
��ʾС�����ϵĿ���ˮƿ����n = 0��ʾ�����������ĳ���Ӧ��������һ�С�
������� :
����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��
ʾ��1
����
3
10
81
0
���
1
5
40
*/
#include<iostream>
using  namespace std;
int calculateNum(int number)
{
	//��ʾ���ɻ�����ˮ��
	int sum = 0;
	while (number > 1)
	{
		//��ǰ��ƿ���ɶһ�����ˮ��
		sum += number/ 3;
		//���¿�ƿ��
		number = number % 3 + number / 3;
		//����ƿ��ʣ��2ƿ�������ɶһ�һƿ��ˮ
		if (number == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}
int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << calculateNum(num) << endl;
	}
	return 0;
}
#endif