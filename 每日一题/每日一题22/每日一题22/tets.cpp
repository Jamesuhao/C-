//#1С�׵�����֮·
# if 0
/*
��Ŀ����
С�׾���������������Ϸ.��һ��,������һ�������������Ϸ,���Ľ�ɫ�ĳ�ʼ����ֵΪ a.
�ڽ�������һ��ʱ����,��������������n������,ÿ������ķ�����Ϊb1,b2,b3...bn. 
��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc,��ô���������ɴ�ܹ���,
����ʹ���Լ�������ֵ����bi;���bi����c,����Ҳ�ܴ�ܹ���,����������ֵֻ������bi ��c�����Լ��.
��ô��������,��һϵ�еĶ�����,С�׵���������ֵΪ����?
��������:
����ÿ������,��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
�ڶ���n������,b1,b2...bn(1��bi��n)��ʾÿ������ķ�����
�������:
����ÿ������,���һ��.ÿ�н�����һ������,��ʾС�׵���������ֵ
ʾ��1
����
3 50
50 105 200
5 20
30 20 15 40 100
���
110
205
��Ŀ������
��ʼ����ֵ��a
��ǰ����ֵ��c
�����������bi
c>=bi   c=c+bi
c<bi     c=c+(c��bi�����Լ��)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//�����Լ��
int Bigcommondivisor(int x, int y)
{
	if (x < y)
	{
		swap(x, y);
	}
	while (y)
	{
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}
int main()
{
	int n, a;
	while (cin >> n >> a)
	{
		vector<int>vec(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
			//��ǰ����ֵ>=���������
			if (a >= vec[i])
			{
				a += vec[i];
			}
			//��ǰ����ֵ<���������
			else
			{
				a += Bigcommondivisor(a, vec[i]);
			}
		}
		cout << a << endl;
	}
	return 0;
}

//#2�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
/*
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
��������:
����һ���ǿ��ַ���
�������:
�����һ��ֻ����һ�ε��ַ���������������-1
ʾ��1
����
asdfasdfo
���
o
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		bool flag = 1;
		vector<int>vec(26, 0);
		for (int i = 0; i < str.size(); ++i)
		{
			++vec[str[i] - 'a'];
		}
		for (int i = 0; i < str.size(); ++i)
		{
			if (vec[str[i] - 'a'] == 1)
			{
				cout << str[i] << endl;
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << "-1" << endl;
		}
	}
	return 0;
}
#endif