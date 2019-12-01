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

#9�����B�̳���A��A::x()������Ϊ�麯����B::x()������A::x()������������������ĸ�x()�����ᱻ����(B)������
A A::x()
B B::x()
C A::x() B::x()
D B::x() A::x()

#10����һ��C++����������(C) ???
#include "stdio.h"
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived : public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main(void)
{
	Derived Obj;
	Base* pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));
	printf("%d,", pObj->Bar(100));
}
A 100�� - 100
B 100��50
C 200�� - 100
D 200��50

#11�ٶ�CSomething��һ���ִ࣬��������Щ���֮���ڴ��ﴴ����(6)��CSomething����
CSomething a();
CSomething b(2);
CSomething c[3] = new CSomething(0);
CSomething& ra = b;
CSomething d = b;
CSomething* pA = c;
CSomething* p = new CSomething(4);
ע�⣺
CSomething a()��// û�д����������ﲻ��ʹ��Ĭ�Ϲ��캯�������Ƕ�����һ����
CSomething b(2);//ʹ��һ�������Ĺ��캯����������һ������
CSomething c[3];//ʹ���޲ι��캯����������3������
CSomething& ra = b;//ra����b��û�д����¶���
CSomething d = b;//ʹ�ÿ������캯����������һ���µĶ���d��
CSomething* pA = c;//����ָ�룬ָ�����c��û�й����¶���
CSomething* p = new CSomething(4);//�½�һ������

#12������δ�������ʱ�����ʲô����(B) ???
class A
{
public:
	void f()
	{
		printf("A\n");
	}
};
class B : public A
{
public:
	virtual void f()
	{
		printf("B\n");
	}
};
int main()
{
	A* a = new B;
	a->f();
	delete a;
	return 0;

}
A û�����⣬���B
B ������Ԥ�ڵ����A
C ������ȷ
D ���ϴ𰸶�����ȷ

#13������δ�����ӡ��ʲô(A)???
class A
{
public:
	A()
	{
		printf("A ");
	}
	~A()
	{
		printf("deA ");
	}
};
class B
{
public:
	B()
	{
		printf("B ");
	}
	~B()
	{
		printf("deB ");
	}
};
class C : public A, public B
{
public:
	C()
	{
		printf("C ");
	}
	~C()
	{
		printf("deC ");
	}
};
int main()
{
	A* a = new C();
	delete a;
	return 0;
}
A A B C deA
B C A B deA
C A B C deC
D C A B deC

#14���¹���STL�������У�C��ġ�
A STL�������̲߳���ȫ��
B ����������ʱ��vector�ڲ��ڴ���չ��ʽ�Ƿ���
C std::sort���ȶ�����
D std::bitset����һ��STL����
E std::stackĬ������dequeʵ�ֵ�
F std::string�п��Դ洢�����\0���ַ�
ע�⣺
sort()�������ȶ�����sort����Ҫ�õ��˿�������O(nlogn),��������O(n2)�Ͷ�����O(nlogn����

#14����������ʲô(C)        ������
#include <iostream>
using namespace std;
class A
{
public:
	void print()
	{
		cout << "A:print()";
	}
};
class B : private A
{
public:
	void print()
	{
		cout << "B:print()";
	}
};
class C : public B
{
public:
	void print()
	{
		A::print();
	}
};
int main()
{
	C b;
	b.print();
}
A A : print()
B B : print()
C �������
#endif