//#1
#if 0
/*
���дһ��������������������ӡ�����ʹ��+�����������������
��������int A��B���뷵��A��B��ֵ
����������
1,2
���أ�3
*/
#include<iostream>
using namespace std;
int add(int a, int b)
{
	if (b == 0)
		return a;
	int sum = a ^ b;
	int carry = (a & b) << 1;
	return add(sum, carry);
}
#endif

//#2
#if 0
/*
��Ŀ����
���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·��
����ֻ�����Һ������ߣ���������������ߡ�
��������:
��������������
�������:
���ؽ��
ʾ��1
����
2
2
���
6
*/
#include<iostream>
using namespace std;
int number(int n, int m)
{
	if (n > 1 && m > 1)
		return number(n - 1, m) + number(n, m - 1);
	else if ((n == 1 && m >= 1) || (n >= 1 && m == 1))
		return n + m;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << number(a, b) << endl;
	return 0;
}
#endif