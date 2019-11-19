#if 0
#1下列有关this指针使用方法的叙述正确的是（D）？？？
A 保证基类保护成员在子类中可以被访问
B 保证基类私有成员在子类中可以被访问
C 保证基类共有成员在子类中可以被访问
D 保证每个对象拥有自己的数据成员，但共享处理这些数据的代码

#2下列情况中，不会调用拷贝构造函数的是（B）？？？
A 用一个对象去初始化同一个类的另一个新对象时
B 将类的一个对象赋值给该类的另一个对象时
C 函数的形参对象，调用函数进行形参和实参结合时
D 函数的返回值是类的对象，函数执行返回调用时

#3下面程序输出结果是什么 (A)？？？
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

#4关于重载和多态正确的是(B)？？？
A 如果父类和子类都有相同的方法, 参数个数不同, 将子类对象赋给父类后, 由于子类继承于父类, 所以使用父类指针 调用父类方法时, 实际调用的是子类的方法
B 选项全部都不正确
C 重载和多态在C++面向对象编程中经常用到的方法, 都只在实现子类的方法时才会使用
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
结果是1

#5下列程序的运行结果是(A)？？？
#include<iostream>
using namespace std;
class B0//基类BO声明
{
public://外部接口
virtual void display()//虚成员函数
{
cout << "B0::display0" << endl;
}
};
class B1 :public B0//公有派生
{
public:
	void display() { cout << "B1::display0" << endl; }
};
class D1 : public B1//公有派生
{
public:
	void display() { cout << "D1::display0" << endl; }
};
void fun(B0 ptr)//普通函数
{
	ptr.display();
}
int main()//主函数
{
	B0 b0;//声明基类对象和指针
	B1 b1;//声明派生类对象
	D1 d1;//声明派生类对象
	fun(b0);//调用基类B0函数成员
	fun(b1);//调用派生类B1函数成员
	fun(d1);//调用派生类D1函数成员
}
A B0::display0 B0::display0 B0::display0
B B0::display0 B0::display0 D1::display0
C B0::display0 B1::display0 D1::display0
D B0::display0 B1::display0 B1::display0

#6在公有派生的情况下，派生类中定义的成员函数只能访问原基类的(C)？？？
A 公有成员和私有成员
B 私有成员和保护成员
C 公有成员和保护成员
D 私有成员, 保护成员和公有成员

#7以下程序输出结果是(C)
class A
{
public:
	A() :m_iVal(0) { test(); }
	virtual void func() { std::cout << m_iVal << ‘ ’; }
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
		std::cout << m_iVal << ‘ ’;
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
E 不可预期
F 以上都不对

#8在C++，下列哪一个可以做为对象继承之间的转换(C)???
A static_cast
B reinterpret_cast
C dynamic_cast
D const_cas
#endif