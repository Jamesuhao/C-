#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
using namespace std;
void TestString()
{
	string s1; //����һ�����ַ���������Ϊ����ַ�
	string s2("adasdasdawdas");//����sָ����Կ���ֹ���ַ����У�C�ַ�������
	string s3(s2); //����s0�ĸ�����
	string s4(s2, 8, 3);//���ƴ��ַ�λ��8��ʼ����Խ3���ַ���s2���֣����s2̫�̻�len��string :: npos(��lenΪ�޷��ţ�����nops��-1)�����Ƶ�str�Ľ�β����
	string s5("hello world", 5);//��sָ����ַ������и���ǰn���ַ�
	string s6a(5, 'a');//���ַ���n��������������ַ�����
	string s6b(5, 97);//���ַ�c��n��������������ַ�����'a'��ASCllֵΪ97
	string s7(s2.begin(), s2.end());//����ͬ˳����[first��last����Χ�ڵ��ַ����С�
}
void TestVector()
{
	vector<int>first;//����һ��û��Ԫ�صĿ�������
	vector<int>second(4, 100);//����һ������n��Ԫ�ص�������ÿ��Ԫ�ض���val�ĸ��������δ�ṩ����Ϊ0����
	vector<int>third(second);//����ͬ��˳����һ�����������а���second��ÿ��Ԫ�صĸ�����
	vector<int>fouth(second.begin(), second.end());// ����һ��������ΧΪ[first��last����Ԫ�ص�������ÿ��Ԫ�ؾ�����ͬ��˳��Ӹ÷�Χ�ڵ���ӦԪ���а�λ�ù�����ɡ�
	//���������캯��Ҳ�����������鹹��
	int arr[] = { 1,2,3,4,5 };
	vector<int>fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//��������
}
void TestList()
{
	list<int>first;//����һ��û��Ԫ�صĿ�������
	list<int>second(4, 100);//����һ������n��Ԫ�ص�������ÿ��Ԫ�ض���val�ĸ��������δ�ṩ����Ϊ0����
	list<int>third(second);//����ͬ��˳����һ�����������а���second��ÿ��Ԫ�صĸ�����
	list<int>fouth(second.begin(), second.end());// ����һ��������ΧΪ[first��last����Ԫ�ص�������ÿ��Ԫ�ؾ�����ͬ��˳��Ӹ÷�Χ�ڵ���ӦԪ���а�λ�ù�����ɡ�
	//���������캯��Ҳ�����������鹹��
	int arr[] = { 1,2,3,4,5 };
	list<int>fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//��������

}
void TestDeque()
{
	deque<int>first;//����һ��û��Ԫ�صĿ�������
	deque<int>second(4, 100);//����һ������n��Ԫ�ص�������ÿ��Ԫ�ض���val�ĸ��������δ�ṩ����Ϊ0����
	deque<int>third(second);//����ͬ��˳����һ�����������а���second��ÿ��Ԫ�صĸ�����
	deque<int>fouth(second.begin(), second.end());// ����һ��������ΧΪ[first��last����Ԫ�ص�������ÿ��Ԫ�ؾ�����ͬ��˳��Ӹ÷�Χ�ڵ���ӦԪ���а�λ�ù�����ɡ�
	//���������캯��Ҳ�����������鹹��
	int arr[] = { 1,2,3,4,5 };
	deque<int>fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//��������
}
int main()
{
	TestString();
	TestVector();
	TestList();
	TestDeque();
	return 0;
}