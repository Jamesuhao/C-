//#1�ַ�����ת
#if 0
/*
��Ŀ����
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
��������:
����N���ַ�
�������:
������ַ�����ת����ַ���
ʾ��1
����
abcd
���
dcba
*/
#include<iostream>
#include<string>
using namespace std;
void Swap(char& a, char& b)
{
	auto tmp = a;
	a = b;
	b = tmp;
}
void Reverse(string& str)
{
	auto start = str.begin();
	auto end = str.end() - 1;
	while (start != end)
	{
		Swap(*start, *end);
		++start;
		--end;
	}
	cout << str << endl;
}
int main()
{
	string str;
	while (cin >> str)
	{
		Reverse(str);
	}
	return 0;
}
#endif
//#2�����ִ�����
#if 0
/*
��Ŀ����
��Ŀ���⣺
���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд
��������:
���������ַ���
�������:
���һ������
ʾ��1
����
����
asdfas werasdfaswer
���
����
6
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Maxcount(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int max = 0;
	vector<vector<int>>vec(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			if (vec[i][j] > max)
			{
				max = vec[i][j];
			}
		}
	}
	return max;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << Maxcount(str1, str2) << endl;
	}
	return 0;
}
#endif