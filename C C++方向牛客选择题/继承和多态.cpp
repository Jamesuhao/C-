#if 0
#1�����й�thisָ��ʹ�÷�����������ȷ���ǣ�D��������
A ��֤���ౣ����Ա�������п��Ա�����
B ��֤����˽�г�Ա�������п��Ա�����
C ��֤���๲�г�Ա�������п��Ա�����
D ��֤ÿ������ӵ���Լ������ݳ�Ա������������Щ���ݵĴ���

#2��������У�������ÿ������캯�����ǣ�B��������
A ��һ������ȥ��ʼ��ͬһ�������һ���¶���ʱ
B �����һ������ֵ���������һ������ʱ
C �������βζ��󣬵��ú��������βκ�ʵ�ν��ʱ
D �����ķ���ֵ����Ķ��󣬺���ִ�з��ص���ʱ

#3���������������ʲô (A)������
#include<iostream>
using namespace std;
class A {
public:
	A(char* s)
	{
		cout << s << endl;
	}
	~A() {}
};
class B :virtual public A
{
public:
	B(char* s1, char* s2) :A(s1) {
		cout << s2 << endl;
	}
};
class C :virtual public A
{
public:
	C(char* s1, char* s2) :A(s1) {
		cout << s2 << endl;
	}
};
class D :public B, public C
{
public:
	D(char* s1, char* s2, char* s3, char* s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
A.class A class B class C class D
B.class D class B class C class A
C.class D class C class B class A
D.class A class C class B class D
#endif