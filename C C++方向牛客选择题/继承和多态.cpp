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

#4�������غͶ�̬��ȷ����(B)������
A �����������඼����ͬ�ķ���, ����������ͬ, ��������󸳸������, ��������̳��ڸ���, ����ʹ�ø���ָ�� ���ø��෽��ʱ, ʵ�ʵ��õ�������ķ���
B ѡ��ȫ��������ȷ
C ���غͶ�̬��C++����������о����õ��ķ���, ��ֻ��ʵ������ķ���ʱ�Ż�ʹ��
D
class A{
void test(float a) { cout << "1"; }
};
class B :public A {
	void test(int b) { cout << "2"; }
};
A* a = new A;
B* b = new B;
a = b;
a.test(1.1);
�����1

#5���г�������н����(A)������
#include<iostream>
using namespace std;
class B0//����BO����
{
public://�ⲿ�ӿ�
virtual void display()//���Ա����
{
cout << "B0::display0" << endl;
}
};
class B1 :public B0//��������
{
public:
	void display() { cout << "B1::display0" << endl; }
};
class D1 : public B1//��������
{
public:
	void display() { cout << "D1::display0" << endl; }
};
void fun(B0 ptr)//��ͨ����
{
	ptr.display();
}
int main()//������
{
	B0 b0;//������������ָ��
	B1 b1;//�������������
	D1 d1;//�������������
	fun(b0);//���û���B0������Ա
	fun(b1);//����������B1������Ա
	fun(d1);//����������D1������Ա
}
A B0::display0 B0::display0 B0::display0
B B0::display0 B0::display0 D1::display0
C B0::display0 B1::display0 D1::display0
D B0::display0 B1::display0 B1::display0

#6�ڹ�������������£��������ж���ĳ�Ա����ֻ�ܷ���ԭ�����(C)������
A ���г�Ա��˽�г�Ա
B ˽�г�Ա�ͱ�����Ա
C ���г�Ա�ͱ�����Ա
D ˽�г�Ա, ������Ա�͹��г�Ա

#7���³�����������(C)
class A
{
public:
	A() :m_iVal(0) { test(); }
	virtual void func() { std::cout << m_iVal << �� ��; }
	void test() { func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B() { test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << �� ��;
	}
};
int main(int argc, char* argv[])
{
	A* p = new B;
	p->test();
	return 0;
}
A 1 0
B 0 1
C 0 1 2
D 2 1 0
E ����Ԥ��
F ���϶�����

#8��C++��������һ��������Ϊ����̳�֮���ת��(C)???
A static_cast
B reinterpret_cast
C dynamic_cast
D const_cas
#endif