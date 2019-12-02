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
void Reverse(string& str)
{
	auto start = str.begin();
	auto end = str.end() - 1;
	while (start <= end)
	{
		swap(*start, *end);
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
asdfas 
werasdfaswer
���
6
����˼·��
����󹫹��Ӵ���ʹ�õ���ʵ�� ���� x(i): �ַ�����i���ַ� y(j): �ַ�����j���ַ� 
vec[i][j]: ��x(i),y(j)��β������Ӵ����� ���磺x: "abcde" y:"bcdae"
vec[2][1]: ��x(2),y(1)��β������Ӵ����� ����x������"abc", y������"bc", �����ַ�'c'��βʱ��󹫹��Ӵ�Ϊ"bc" 
�ʣ�������vec[i][j]ʱ�����ȿ�x(i),y(j)��ֵ�� 
(1��: x(i) == y(j)
��ǰ�����ַ�����β���ַ���ȣ�vec[i][j] = vec[i-1][j-1] + 1 �������ĳ��ȼ�1 
(2��: x(i) != y(j) 
��ǰ�����ַ�����β���ַ�����ȣ�˵��û�����������ַ���β�Ĺ����Ӵ� ��dp[i][j] = 0 
(3��: dp[0][j] �� dp[i][0]��ʾ��ĳ���Ӵ��ĵ�һ���ַ���β����󳤶�Ϊ1 ���x(0) == y(j) ���� x(i) == y(0), �򳤶�Ϊ1������Ϊ0 
��dp�е�����Ԫ�ؼ�����֮�󣬴����Ҵ�����ֵ���
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
	for (int i = 0; i <= len1; ++i)
	{
		for (int j = 0; j <= len2; ++j)
		{
			//�����ǰ��β���ַ���ȣ�����vec[i-1][j-1]�Ļ����ϼ�1
			if (str1[i] == str2[j])
			{
				if (i >= 1 && j >= 1)
				{
					vec[i][j] = vec[i - 1][j - 1] + 1;
				}
				else//vec[i][0] or vec[0][j]
				{
					vec[i][j] = 1;
				}
			}
			//�������ֵ
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