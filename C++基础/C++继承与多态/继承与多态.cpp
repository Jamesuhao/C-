#include<iostream>
#include<typeinfo>
#include<string>
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
继承的本质：a.代码的复用   b.在基类中，提供统一的虚函数接口，让派生类进行重写，然后就可以使用多态了。
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
(1).外部只能访问对象的public成员，protected和private的成员无法直接访问
(2).在继承结构中，派生类从基类可以继承private的成员，但是派生类却无法直接访问
(3).protected和private的区别：
	在基类中定义的成员，想被派生类访问，但是不想被外部访问，那么在基类中，把相关成员定义成protected成员；
	如果派生类和外部都不打算访问，那么在基类中就把相关成员定义成private成员。

默认的继承方式是什么？
如果使用class定义派生类，默认继承方式就是private私有的
如果使用struct定义派生类，默认继承方式就是public公有的
*/

//2.派生类的构造过程
/*
派生类从基类可以继承所有的成员(变量和方法)
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
//3.重载、隐藏、覆盖(重写)
/*
(1)重载关系
a.一组函数要重载，必须要出在同一个作用域当中；而且函数名相同，参数列表不同。
(2)隐藏关系：指的是作用域的隐藏
a.在继承结构当中，派生类与基类有同名成员时，派生类的同名成员，把基类的同名成员给隐藏调用了。
b.派生类优先调用自己作用域的成员，不存在时，再去基类寻找。
(3)覆盖关系
a.如果派生类中的方法，和基类继承来的某个方法，返回值、函数名、参数列表都相同，
而且基类的这个方法是virtual虚函数，那么派生类的这个方法，自动处理成虚函数，
这两个方法称为覆盖(重写)关系，在派生类的虚函数表中，派生类的这个虚函数的地址将覆盖基类这个虚函数的地址
(4)把继承结构，也说成从上(基类) 到下(派生类)的结构
(5)在继承结构中，进行上下的类型转换，默认只支持从下到上的类型转换
基类对象				 ->   派生类对象				N
派生类对象			->		基类对象					Y
基类指针(引用)		->		派生类对象				N
派生类指针(引用)   ->	基类对象					Y
*/
//4.虚函数、静态绑定和动态绑定
/*
一个类添加了虚函数，对这个类产生的影响？
总结1：
a.如果类里面定义了虚函数，那么编译阶段，编译器给这个类类型产生一个唯一的vftable虚函数表,
虚函数表主要存储的内容就是RTTI指针(运行时的类型信息)和虚函数的地址。
b.当程序运行时，每一张虚函数表都会加载到内存.rodata区。
总结2：
a.一个类中定义了虚函数，那么这个类定义的对象，其运行时，内存开始部分，多存储一个虚函数指针vfptr，指向相应类型的虚函数表vftable。
b.一个类型定义的n个对象，他们的vfptr指向的都是同一张虚函数表。
总结3：
a.一个类里面虚函数的个数，不影响对象的内存大小，而影响的是虚函数表的大小。
总结4：
a.如果派生类中的方法，和基类继承来的某个方法，返回值、函数名、参数列表都相同，
而且基类的方法是virtual虚函数，那么派生类的这个方法，自动处理成虚函数。
静态绑定和动态绑定：
总结5：
静态绑定：编译时期函数的调用。
动态绑定：运行时期函数的调用。


问题一：哪些函数不能实现成虚函数？
虚函数依赖：
(1)虚函数能产生地址，存储在vftable当中。
(2)对象必须在(vfptr -> vftable -> 虚函数地址)
所以：
a.构造函数不能实现成虚函数，在构造函数中调用虚函数，也不会发生动态绑定。
b.static静态成员方法不能实现成虚函数，因为静态成员属于类级别的，不通过对象调用。

问题二：虚析构函数
析构函数调用的时候，对象是存在的。  
基类的析构函数如果是virtual虚函数，那么派生类的析构函数自动处理成virtual虚函数
在基类的指针(引用)指向堆上new出来的派生类对象的时候，delete pb(基类的指针)，
它调用析构函数的时候，必须发生动态绑定，否则会导致派生类的析构函数无法调用

问题三：是不是虚函数的调用一定就是动态绑定？
不是的，在类的构造函数中，调用虚函数，也是动态绑定(构造函数中调用其他函数(虚)，不会发生动态绑定。
如果用对象本身调用虚函数，则发生静态绑定。
如果用指针/引用调用虚函数，则发生动态绑定。
*/
/*
class Base
{
public:
	Base(int data = 0)
		:ma(data) 
	{
		//cout << "Base()" << endl;
	}
	//虚函数
	virtual void show() { cout << "Base::show()" << endl; }
	//虚函数
	//virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive :public Base
{
public:
	Derive(int data = 0)
		:Base(data)
		, mb(data)
	{
		//cout << "Derive()" << endl;
	}
	void show() { cout << "Derive::show()" << endl; }
private:
	int mb;
};
int main()
{
	Base b;
	Derive d;
	//静态绑定，用对象本身调用虚函数，是静态绑定
	b.show(); //虚函数 call Base::show
	d.show();//虚函数 call Base::show
	//动态绑定(必须由指针调用虚函数)
	Base* pb1 = &b;
	pb1->show();
	Base* pb2 = &d;
	pb2->show();
	//动态绑定(必须由引用调用虚函数)
	Base& rb1 = b;
	rb1.show();
	Base& rb2 = d;
	rb2.show();
	//动态绑定(虚函数通过指针或者引用变量调用，才会发生动态绑定)
	Derive* pd1 = &d;
	pd1->show();
	Derive& rd2 = d;
	rd2.show();
	Derive d(50);
	Base* pb = &d;
	
	pb->show  Base::show 如果发现show是普通函数，就进行静态绑定
	pb->show  Base::show 如果发现show是虚函数函数，就进行动态绑定
	
	//pb->show();//静态的绑定(静态指编译时期，绑定指函数的调用)
	//pb->show(10);//静态的绑定(静态指编译时期，绑定指函数的调用)
	//cout << sizeof(Base) << endl;//4
	//cout << sizeof(Derive) << endl;//8
	//cout << typeid(pb).name() << endl;//class Base*
	
	//pb的类型：Base->先看Base中有没有虚函数
	//如果Base没有虚函数，*pb识别的就是编译时期的类型  *pb=>Base类型
	//如果Base有虚函数，*pb识别的就是运行时期的类型->RTTI类型
	//pb指向的是派生类对象，所以*pb识别的就是派生类的虚函数表
	
	cout << typeid(*pb).name() << endl;//class Base
	return 0;
}
*/

//5.如何理解多态？
/*
静态(编译时期)的多态：函数重载、模板(函数模板和类模板)
函数重载：
bool compare(int,int);
bool compare(double,double);
compare(10,20)；call compare_int_int 在编译阶段就确定好调用的函数版本
compare(10.5,20.5)；call compare_double_double 在编译阶段就确定好调用的函数版本
模板：
template<typename T>
bool compare(T a,T b){}
compare(10,20)；     =>  int  编译阶段实例化一个compare<int>
compare(10.5,20.5)；=>double 编译阶段实例化一个compare<double>
动态(运行时器)的多态：
在继承结构中，基类指针(引用)指向派生类对象，通过该指针(引用)调用同名覆盖方法。
基类指针指向那个派生类对象，就会调用哪个派生类对象的覆盖方法，称为多态。
因为多态底层是通过动态绑定来实现的，基类指针(引用)指向哪个派生类对象，
就会访问这个派生类对象的虚函数指针，进而访问这个派生类的虚函数表，获取这个派生类的同名覆盖方法，访问该对象的同名覆盖方法

//动物的基类
class Animal
{
public:
	Animal(string name) :_name(name) {}
	virtual void bark() {};
protected:
	string _name;
};
//以下是动物实体类
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark：miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark：wang wang!" << endl; }
};
class Pig :public Animal
{
public:
	Pig(string name) :Animal(name) {}
	void bark() { cout << _name << "bark：heng heng!" << endl; }
};
//下面的一组bark  API接口无法左到我们软件设计要求的"开-闭"原则
/*
软件设计六大原则：
开-闭原则：对修改关闭，对扩展开放
void bark(Cat cat)
{
	cat.bark();
}
void bark(Dog dog)
{
	dog.bark();
}
void bark(Pig pig)
{
	pig.bark();
}
void bark(Animal* p)
{
	p->bark();//Animal::bark虚函数，发生动态绑定
	//p->cat   Cat vftable &Cat::bark
	//p->dog Dog vftable &Dog::bark
	//p->pig   Pig vftable &Pig::bark
}
int main()
{
	Cat cat("喵咪");
	Dog dog("二哈");
	Pig pig("佩奇");

	//bark(cat);
	//bark(dog);
	//bark(pig);
	bark(&cat);
	bark(&dog);
	bark(&pig);
	return 0;
}
*/
//6.抽象类的设计原理
/*
拥有纯虚函数的类，叫做抽象类。
注意：抽象类不能再实例化对象了，但是可以定义指针和引用变量。
问题一：抽象类和普通类有什么区别？
问题二：一般把什么类设计成抽象类？
一般把基类实现成抽象类，把基类的方法实现成纯虚函数
*/
//示例1：动物的基类，定义Animal并不是让Animal抽象某个实体的类型
//1.string _name;让所有的动物实体类通过继承Animal直接复用该属性
//2.给所有的派生类保留统一的覆盖/重写接口
/*
class Animal
{
public:
	Animal(string name) :_name(name) {}
	virtual void bark()  = 0;//纯虚函数
protected:
	string _name;
};
//以下是动物实体类
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark：miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark：wang wang!" << endl; }
};
class Pig :public Animal
{
public:
	Pig(string name) :Animal(name) {}
	void bark() { cout << _name << "bark：heng heng!" << endl; }
};
void bark(Animal* p)
{
	p->bark();//Animal::bark虚函数，发生动态绑定
}
*/
//示例2：汽车的基类
class Car//抽象类
{
public:
	Car(string name,double oil) :_name(name),_oil(oil) {}
	double getLeftMiles()//获取汽车剩余油量还能跑的公里数
	{
		return _oil * getMilesPerGallon();//发生了动态绑定
	}
	string getName()const
	{
		return _name;
	}
protected:
	string _name;
	double _oil;
	virtual double getMilesPerGallon() = 0;//纯虚函数
};
class Bnze :public Car
{
public:
	Bnze(string name, double oil) :Car(name, oil) {  }
	double getMilesPerGallon() { return 20.0; }
};
class Audi :public Car
{
public:
	Audi(string name, double oil) :Car(name, oil) {  }
	double getMilesPerGallon() { return 18.0; }
};
class BMW :public Car
{
public:
	BMW(string name, double oil) :Car(name, oil) {  }
	double getMilesPerGallon() { return 19.0; }
};
//给外部提供一个统一的获取汽车剩余路程数的API
void showCarLeftMiles(Car& car)
{
	cout << car.getName() << "  left miles：" << car.getLeftMiles() << "公里数" << endl;
}
int main()
{
	/*
	Cat cat("喵咪");
	Dog dog("二哈");
	Pig pig("佩奇");

	bark(&cat);
	bark(&dog);
	bark(&pig);
	*/
	Bnze b1("奔驰",20.0);
	Audi a("奥迪",20.0);
	BMW b2("宝马",20.0);

	showCarLeftMiles(b1);
	showCarLeftMiles(a);
	showCarLeftMiles(b2);
	return 0;
}



				