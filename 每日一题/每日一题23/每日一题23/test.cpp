//#1Ԫ�ز���
#if 0
/*
��Ŀ����
��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
���磬ԭ����Ϊ[1,2,3,4,5,6]��������λ5��λ�ü������[6,1,2,3,4,5],���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á�
�����һ�����Ӷ�Ϊlog������㷨����������

����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣

����������
[6,1,2,3,4,5],6,6
���أ�0

���ֲ��ҵĽ��װ棬����˼·�Զ��ֲ���Ϊ���壬��һЩ����������
��Ŀ�и�������һ���Ź�������飬��������λ֮������һ���Ǳ�ĳԪ��Ϊ�ָ����������������
*/

#include<iostream>
#include<vector>
using namespace std;
int FindElement(vector<int>vec, int n, int x)
{
	int  left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		//vec[mid]==x;�ҵ���Ԫ�أ�ֱ�ӷ����±�
		if (vec[mid] == x)
		{
			return mid;
		}
		//vec[mid]<x�����¹滮��������
		else if (vec[mid] < x)
		{
			/*
			���ж�mid���ı�����
			vec[mid]<vec[left]��mid���ұ�����
			���жϲ���Ԫ����������
			x>vec[right]������Ԫ��һ����mid�����
			*/
			if (vec[mid] < vec[left] && x > vec[right])
			{
				right = mid - 1;
			}
			//�����������Ԫ�ؾ���mid���ұ�
			else
			{
				left = mid + 1;
			}
		}
		//vec[mid]>x;���¹滮��������
		else
		{
			/*
			���ж�mid���ı��������
			vec[mid]>vec[left]��mid�����һ���������
			���жϲ���Ԫ����������
			x<vec[left]������Ԫ��һ����mid���ұ�
			*/
			if (vec[mid] > vec[left] && x < vec[left])
			{
				left = mid + 1;
			}
			//������������ҵ�Ԫ��һ����mid�����
			else
			{
				right = mid - 1;
			}
		}
	}
}
int main()
{
	int n, x;
	cin >> n >> x;
	vector<int>vec(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}
	cout << FindElement(vec, n, x) << endl;
	return 0;
}
#endif

//#2�ַ�����
#if 0
/*
��Ŀ����
����һ���ַ�����������ַ����������ַ�����
��������:
ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
�������:
ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
ʾ��1
����
abcqweracb
���
abcqwer
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
		vector<int>vec(256, 0);
		for (int i = 0; i < str.size(); ++i)
		{
			if (vec[str[i] - '0'] == 0)
			{
				cout << str[i];
			}
			++vec[str[i] - '0'];
		}
		cout << endl;
	}
	return 0;
}
#endif