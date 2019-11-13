//#1�Ϸ����������ж�
#if 0
/*
��Ŀ����
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
����������
"(()())",6
���أ�true
����������
"()a()()",7
���أ�false
����������
"()(()()",7
���أ�false
*/
#include<iostream>
#include<string>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		if (n % 2 != 0)
			return false;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] != '(' && A[i] != ')')
				return false;
			else if (A[i] == '(')
				++count;
			else
				--count;
		}
		if (count == 0)
			return true;
		return false;
	}
};
#endif

//#2Fibonacci����
#if 0
/*
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
��������:
����Ϊһ��������N(1 �� N �� 1,000,000)
�������:
���һ����С�Ĳ�����ΪFibonacci��"
ʾ��1
����
15
���
2
*/
#include<iostream>
using namespace std;
int main()
{
	int N;
	int f1 = 0;
	int f2 = 1;
	int f3 = 1;
	cin >> N;
	while (f3 < N)
	{
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	f1 = N - f1;
	f2 = f2 - N;
	f3 = f1 > f2 ? f2 : f1;
	cout << f3 << endl;
}
#endif