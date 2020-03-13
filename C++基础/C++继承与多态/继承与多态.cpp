#include<iostream>
using namespace std;
/*
1.继承的本质和原理
2.派生类的构造过程
3.重载、覆盖、隐藏
4.静态绑定和动态绑定
5.多态  vfptr和vftable
6.抽象类的设计原理
7.多重继承以及问题
8.虚基类  vbptr和vftable
9.RTTI
10.C++四种类型强转
*/
//1.继承的本质和原理
/*
继承的本质：a.代码的复用
类和类之间的关系：
组合：一部分的关系
继承：同一种的关系

基类的成员的访问限定，在派生类中是不可能超过继承方式的
继承方式		基类的访问限定		派生类的访问限定		(main)外部的访问限定
public：		
						public					public						Y
						protected				protected					N
						private					不可见						N
protected	:	
						public					protected					N
						protected				protected					N
						private					不可见						N
private：
						public					private						N
						protected				private						N
						private					不可见						N
总结：
(1).外部只能访问对象public的成员，protected和private的成员无法直接访问
(2).在继承结构中，派生类从基类可以继承private的成员，但是派生类却无法直接访问
(3).protected和private的区别：
	在基类中定义的成员，想被派生类访问，但是不想被外部访问，那么在基类中，把相关成员定义成protected成员；
	如果派生类和外部都不打算访问，那么在基类中就把相关成员定义处private成员。

默认的继承方式是什么？
如果使用class定义派生类，默认继承方式就是private私有的
如果使用struct定义派生类，默认继承方式就是public公有的
*/

//2.派生类的构造过程
/*
派生类从基类可以继承来所有的成员(变量和方法)，除过构造函数和析构函数
(1)派生类怎么初始化从基类继承来的成员变量？
通过调用基类相应的构造函数来初始化

派生类的构造函数和析构函数，负责初始化和清理派生类的资源
派生类从基类继承来的成员，是由基类的构造函数和析构函数来负责的

派生类对象构造和析构的过程是：
1.派生类调用基类的构造函数，初始化从基类继承来的成员
2.调用派生类自己的构造函数，初始化派生类自己特有的成员
3.调用派生类自己的析构函数，释放派生类成员可能占用的外部资源(堆内存，文件）
4.派生类调用基类的析构函数，释放派生类内存中，从基类继承来的成员可能占用的外部资源(堆内存，文件）
*/
class Base
{
public:
	Base(int data)
		:ma(data) 
	{
		cout << "Base()" << endl;
	}
	~Base() { cout << "~Base()" << endl; }
protected:
	int ma;
};
class Derive :public Base
{
public:
	Derive(int data)
		:Base(data)
		, mb(data)
	{
		cout << "Derive()" << endl;
	}
	~Derive()
	{
		cout << "~Derive()" << endl;
	}
private:
	int mb;
};
int main()
{
	Derive(20);
	return 0;
}