//#1�����������
#if 0
/*
��Ŀ����
��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š�
��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�
����������
2��3
���أ�1
����˼·��
˼·�������������ӽڵ��븸�ڵ�֮��Ĺ�ϵΪroot = child / 2
���������ϵ�����a ��= b���������еĽϴ�������2�� ���ѭ��֪��a == b��
����ԭ���������������������
*/
#include<iostream>
using namespace std;
int getC(int a, int b)
{
	if (a == 1 || b == 1)
		return 1;
	while (a != b)
	{
		if (a > b)
			a /= 2;
		else
			b /= 2;
	}
	return a;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << getC(a, b) << endl;
	return 0;
}
#endif
//#2���������bit��
#if 0
/*
��Ŀ����
����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
����: һ��byte�͵�����
���: ��
����: ��Ӧ�Ķ�����������1�����������
��������:
����һ��byte����
�������:
���ת�ɶ�����֮������1�ĸ���
ʾ��1
����
3
���
2
*/
#include<iostream>
#include<vector>
using namespace std;
int num(vector<int>&vec,int n)
{
	int count = 1;
	int count1 = 1;
	int i = 0;
	for (i = 0; n != 0; ++i)
	{
		vec[i] = n % 2;
		n /= 2;
	}
	for (; i > 0; --i)
	{
		if (vec[i] == 1 && vec[i] == vec[i - 1])
		{
			++count;
			if (count > count1)
				count1 = count;
		}
		else
			count = 1;
	}
	return count1;
}
int main()
{
	int m = 0;
	while (cin >> m)
	{
		vector<int>vec(32);
		cout << num(vec, m) << endl;
	}
	return 0;
}
#endif