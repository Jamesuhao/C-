//#1��������ʽ
#if 0
/*
��Ŀ����
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 
1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
��������:
�����һ��Ϊ�ַ�������n(n �� 100)
��������n��,ÿ��һ���ַ���,�ַ������Ⱦ�С��100������Сд��ĸ���
�������:
�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
������ݳ������ж������ֵ����������"lengths",
������ַ�ʽ���������"both"���������"none"
ʾ��1
����
3
a
aa
bbb
���
both
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n = 0, flag1 = 1, flag2 = 1;
	cin >> n;
	vector<string>vec(n);
	for (int i=0; i < n; ++i)
	{
		cin >> vec[i];
	}
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		if (vec[i] > vec[i + 1])
			flag1 = 0;
	}
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		if (vec[i].size() > vec[i + 1].size())
			flag2 = 0;
	}
	if (flag1 && flag2)
		cout << "both" << endl;
	else if (flag1 && !flag2)
		cout << "lexicographically" << endl;
	else if (flag2)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}
#endif

//#2��С������
#if 0
/*
��Ŀ����
������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
��������:
��������������A��B��
�������:
���A��B����С��������
ʾ��1
����
5 7
���
35
*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, i = 1;
	cin >> a >> b;
	while (1)
	{
		if ((a * i) % b == 0)
		{
			cout << a * i << endl;
			break;
		}
		else
			++i;
	}
	return 0;
}
#endif