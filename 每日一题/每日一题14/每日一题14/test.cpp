//#1�������ڵ�����ת��
#if 0
/*
��Ŀ����
������������ڣ���������һ��ĵڼ��졣��
��ϸ������
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
��������:
�������У��ֱ����꣬�£���
�������:
�ɹ�:����outDay��������ĵڼ���;
ʧ��:����-1
ʾ��1
����
2012
12
31
���
366
*/
#include<iostream>
using namespace std;
int main()
{
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	cin >> year >> month >> day;
	int num = 0;
	for (int i = 1; i < month; ++i)
	{
		num += days[i];
	}
	num += day;
	if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		num += 1;
	}
	return num;
}
#endif
//#2���˵Ĵ���
#if 0
/*
һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)��
���һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ�
���������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
��������:
��һ������һ��������n(n �� 1000)
�ڶ���Ϊn����������xi(xi �� 1000)
�������:
������Բ��������˵Ĵ�����
ʾ��1
����
3
1 1 1
���
2
*/
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int arr[1000];
int num = 0;
int getnum(int vec[], int pos, long sum, long mulit)
{
	int count = 0;
	for (int i = pos; i < num; ++i)
	{
		sum += vec[i];
		mulit *= vec[i];
		if (sum > mulit)
		{
			count += 1 + getnum(vec, i + 1, sum, mulit);
		}
		else if (vec[i] == 1)
		{
			count += getnum(vec, i + 1, sum, mulit);
		}
		else
		{
			break;
		}
		sum -= vec[i];
		mulit /= vec[i];
		for (; i < num - 1 && vec[i] == vec[i + 1]; ++i)
		{  }
	}
	return count;
}
int main()
{
	int n = 0;
	while (cin >> num)
	{
		for (int i = 0; i < num; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr+num);
		cout << getnum(vec, 0, 0, 1) << endl;
	}
	return 0;
}
#endif