//#1ͳ�ƻ���
#if 0
/*
��Ŀ����
�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ���
* ����ĸ��b��֮��: "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2
��������:
ÿ���������ݹ����С�
��һ��Ϊ�ַ���A
�ڶ���Ϊ�ַ���B
�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
�������:
���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
ʾ��1
����
aba
b
���
2
*/
#include<iostream>
#include<string>
using namespace std;
bool a(const string& str)
{
	auto start = str.begin();
	auto end = str.end() - 1;
	while (start <= end)
	{
		if (*start == *end)
		{
			++start;
			--end;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	string str1, str2, tmp;
	int count = 0;
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.size() + 1; ++i)
	{
		tmp = str1;
		tmp.insert(i, str2);
		if (a(tmp))
			count++;
	}
	cout << count << endl;
	return 0;
}
#endif

//#2��������
#if 0
/*
��Ŀ����
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
��������:
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���
������� :
���������������к�����ֵ��
ʾ��1
����
3 - 1 2 1
���
3
*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;
	int sum = 0;
	int result = INT_MIN;
	vector<int>vec(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> vec[i];
	}
	for (int i = 0; i < size; ++i)
	{
		sum += vec[i];
		if (sum > result)
			result = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << result << endl;
	return 0;
}
#endif