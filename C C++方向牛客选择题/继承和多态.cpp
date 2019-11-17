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
#endif