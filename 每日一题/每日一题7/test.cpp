//#1合法序列括号判断
#if 0
/*
题目描述
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false
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

//#2Fibonacci数列
#if 0
/*
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入描述:
输入为一个正整数N(1 ≤ N ≤ 1,000,000)
输出描述:
输出一个最小的步数变为Fibonacci数"
示例1
输入
15
输出
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