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