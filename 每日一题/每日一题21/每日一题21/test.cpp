//#1ϴ��
#if 0
/*
��Ŀ����
ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡� ������Ҫϴ2n���ƣ�
���ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š����ȣ����ǰ���2n���Ʒֳ����ѣ�
�������ŵ�1�ŵ���n�ţ��ϰ�ѣ����������ŵ�n+1�ŵ���2n�ţ��°�ѣ���
���žͿ�ʼϴ�ƵĹ��̣��ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ�
���ŷ������ֵĵ����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ�
���Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬
��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮��
���ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
��������:
��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1 �� n,k �� 100)��
������һ����2n����a1,a2,...,a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�
�������:
����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�
ʾ��1
����
3 
3 1 
1 2 3 4 5 6 
3 2 
1 2 3 4 5 6 
2 2 
1 1 1 1
���
����
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sort(vector<int>& vec)
{
	vector<int>tmp;
	int size = vec.size();
	int n = size / 2;
	int j = 1;
	while (n)
	{
		tmp.push_back(vec[size - j]);
		tmp.push_back(vec[size / 2] - j);
		--n;
		++j;
	}
	for (int i = 0; i < tmp.size() / 2; ++i)
	{
		swap(tmp[i], tmp[tmp.size() - 1 - i]);
	}
	return tmp;
}
int main()
{
	int time;
	cin >> time;
	int n, k;
	while (time)
	{
		cin >> n >> k;
		vector<int>vec(2 * n);
		for (int i = 0; i < 2 * n; ++i)
		{
			cin >> vec[i];
		}
		while (k)
		{
			vec = sort(vec);
			--k;
		}
		for (int i = 0; i < vec.size(); ++i)
		{
			if (i != vec.size() - 1)
			{
				cout << vec[i] << " ";
			}
			else
			{
				cout << vec[i];
			}
		}
		cout << endl;
		--time;
	}
	return 0;
}
#endif

//#2MP3����λ��
#if 0
/*
��Ŀ��Ϣ��
https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&&tqId=21287&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/
#endif