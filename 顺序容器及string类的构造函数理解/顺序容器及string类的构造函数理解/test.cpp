#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
using namespace std;
void TestString()
{
	string s1; //构造一个空字符串，长度为零个字符
	string s2("adasdasdawdas");//复制s指向的以空终止的字符序列（C字符串）。
	string s3(s2); //构造s0的副本。
	string s4(s2, 8, 3);//复制从字符位置8开始并跨越3个字符的s2部分（如果s2太短或len是string :: npos(因len为无符号，所以nops是-1)，则复制到str的结尾）。
	string s5("hello world", 5);//从s指向的字符数组中复制前n个字符
	string s6a(5, 'a');//用字符的n个连续副本填充字符串。
	string s6b(5, 97);//用字符c的n个连续副本填充字符串。'a'的ASCll值为97
	string s7(s2.begin(), s2.end());//以相同顺序复制[first，last）范围内的字符序列。
}
void TestVector()
{
	vector<int>first;//构造一个没有元素的空容器。
	vector<int>second(4, 100);//构造一个包含n个元素的容器。每个元素都是val的副本（如果未提供，则为0）。
	vector<int>third(second);//用相同的顺序构造一个容器，其中包含second中每个元素的副本。
	vector<int>fouth(second.begin(), second.end());// 构造一个包含范围为[first，last）的元素的容器，每个元素均以相同的顺序从该范围内的相应元素中按位置构造而成。
	//迭代器构造函数也可以用于数组构造
	int arr[] = { 1,2,3,4,5 };
	vector<int>fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//构造数组
}
void TestList()
{
	list<int>first;//构造一个没有元素的空容器。
	list<int>second(4, 100);//构造一个包含n个元素的容器。每个元素都是val的副本（如果未提供，则为0）。
	list<int>third(second);//用相同的顺序构造一个容器，其中包含second中每个元素的副本。
	list<int>fouth(second.begin(), second.end());// 构造一个包含范围为[first，last）的元素的容器，每个元素均以相同的顺序从该范围内的相应元素中按位置构造而成。
	//迭代器构造函数也可以用于数组构造
	int arr[] = { 1,2,3,4,5 };
	list<int>fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//构造数组

}
void TestDeque()
{
	deque<int>first;//构造一个没有元素的空容器。
	deque<int>second(4, 100);//构造一个包含n个元素的容器。每个元素都是val的副本（如果未提供，则为0）。
	deque<int>third(second);//用相同的顺序构造一个容器，其中包含second中每个元素的副本。
	deque<int>fouth(second.begin(), second.end());// 构造一个包含范围为[first，last）的元素的容器，每个元素均以相同的顺序从该范围内的相应元素中按位置构造而成。
	//迭代器构造函数也可以用于数组构造
	int arr[] = { 1,2,3,4,5 };
	deque<int>fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//构造数组
}
int main()
{
	TestString();
	TestVector();
	TestList();
	TestDeque();
	return 0;
}