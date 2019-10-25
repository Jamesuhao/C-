#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using  namespace std;

#if 0
/*
=========》形参带默认值的函数
1.给默认值的时候从右向左给
2.相对于普通调用函数而言效率更高，传参时，会少mov指令
3，定义处可以给形参默认处，声明也可以给形参默认值，但每一个形参只能给一次
4.下列声明方式也是可以的
int sum(int a, int b = 20);
int sum(int a = 20, int b);
*/

int sum(int a = 10, int b = 20)
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = sum(a, b);
	cout << "ret:" << ret << endl;
	//ret = sum(a);
	//cout << "ret:" << ret << endl;
	ret = sum();
	cout << "ret:" << ret << endl;
	return 0;
}


/*
=========》inline内联函数 和 普通函数的区别？？？
1.inline内联函数：在编译过程中，就没有函数的调用开销了，
2.在函数的调用点直接把函数的代码进行展开处理，inline函数不会在符号表中在生成相应的函数符号
3.inline只是建议编译器把这个函数成内联函数，是否处理成inline由编译器决定
4.但是不是所有的inline都会编译器处理成内联函数：如递归
5.debug版本上，inline是不起作用的；inline只有在release版本下才能出现
*/
inline int sum(int a, int b)//普通函数调用会产生这些函数符号*.o  sum_int_int   .text
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = sum(a, b);
	//此处有标准的函数调用过程  参数压栈  函数栈帧的开辟和回退过程
	//有函数的调用的开销
	cout << "ret:" << ret << endl;
	return 0;
}


/*
=========》函数重载
1.为什么C++支持函数重载，C语言不支持函数重载？
(1).C++代码产生函数符号的时候，符号是由函数名+参数列表类型组成的
(2).C语言代码产生函数符号，符号由下划线+函数名
(3).编译器根据C++所产生的符号中参数的个数以及参数的类型来区分,而c语言不带参数列表，所以无法区分
2.什么是函数重载？函数重载需要注意些什么？
(1).一组函数，出现在同一个作用域，其中函数名相同，参数列表的个数或者类型不同，就称为函数重载。
(2).一组函数，函数名相同，参数列表也相同，仅仅是返回值不同，是不构成函数重载的。
3.C++和C语言之间如何互相调用？
C调用C++:无法直接调用(生成符号规则不同)。解决办法：把C++源码的声明括在extern"C"中。
C++调用C:无法直接调用(生成符号规则不同)。解决办法：把C函数声明括在extern "C"中。
#ifdef  __cplusplus
extern "C" {
#endif
	int sum(int a , int b )
	{
		return a + b;
	}
#ifdef  __cplusplus
}
#endif
extern "C"
int sum(int a, int b)
{
	return a + b;
}
4.const或者volatile的时候，是怎么影响形参类型的？
后续讲解。
面试题：请你解释一下，什么是多态？
静态(编译时期)的多态：函数重载、模板等
动态(运行时期)的多态：
*/
bool compare(int a, int b)
{
	cout << "compare_int_int" << endl;
	return a > b;
}
bool compare(double a, double b)
{
	cout << "compare_double_dounle" << endl;
	return a > b;
}
bool compare(const char* a,const char* b)
{
	cout << "compare_char*_char*" << endl;
	return strcmp(a, b) > 0;
}
int main()
{
	compare(10, 20);
	compare(10.0, 20.0);
	compare("aaa", "bbb");
	return 0;
}


/*
==========>const修饰指针变量
1.如何理解const？
const修饰的变量不能够再作为左值!!!  初始化完成后值不能被修改

2.C和C++中const的区别是什么？
(1)C中const修饰的量，可以不用初始化，但是不叫常量，叫做常变量,其不能作为左值被修改，但是其内存中的值可以被修改。
(2)C++的const必须初始化，叫做常量。
(3)const的编译方式不同：
C中，const就是当作一个变量来编译生成指令的。
C++中，所有出现const常量的地方，都被常量的初始化值替换掉了，初始化值必须为立即数。
(4)考虑如下代码
int b = 20;
const int a = b;
此时a不再是常量，已经退化成常变量，因为初始化值不是立即数，是一个变量。

3.const修饰的常量经常出现的错误是：
(1)直接修改常量的值====》常量不能作为左值
(2)间接修改常量的值====》不能把常量的地址泄露给一个普通的指针或者普通的引用变量

4.const和一级指针的结合：修饰指向和所指的内存中的值
C++的语言规范：cosnt修饰的是离它最近的类型。
记忆方法：去掉const所修饰的类型即为不能改变的常量
(1)int const *p;\const int *p = &a; ===》*p=20//错误 p = &a;//正确
修饰*p，即指针所指内存单元中的值不能被改变，但指针指向可以被改变
即可以任意指向int类型的内存，但是不能通过指针间接修改所指内存单元中的值
(2)int *const p = &a; ===>p = &b//错误 *p = 20;//正确
修饰p，即指针的指向不能被修改，但是指针所指内存单元中的值可以被修改
即这个指针p现在是常量，不能再指向其他内存，但是可以通过指针解引用修改指针所指内存单元中的值
(3)const int *const p = &a; ===>p = &b//错误 *p=30;//错误
以上两种情况的结合，指针的指向和所指内存单元的值绝不能被修改

5.const和二级指针的结合
(1)const int* *q;修饰的是**q,所以*q和q是可以改变的
(2)int *cosnt *q;修饰的是*q,所以**q和q是可以改变的
(3)int **const q;修饰的是q,所以**q，*q是可以改变的
6.const和指针的类型转换公式：
int* <= const int*  是错误的！
cosnt int* <=== int*  是正确的！

int ** <= const int**  是错误的！
cosnt int** <= int**  是错误的！

int** <= int* const*  是错误的！
int* cosnt* <= int**  是正确的！
7.如果const右边没有接指针*d话，cosnt是不参与类型的
int* const p = &a;//int*<===int*  const后无指针*，不参与类型
*/
int main()
{
	int b = 20;
	const int a = b;//此时已经退化成常变量，因为初始化值不是立即数，是一个变量。
	const int a= 20;
	
	b = 30;//错误，被cosnt修饰的变量不能作为左值
	int arr[b] = {};
	int* p = (int*)&a;//已经把b内存中的值改掉了
	*p = 30;
	printf("%d %d %d\n", a, *p, *(&a));//在编译阶段const修饰的变量就已经被初始化的值替换了
	
	
	const int a = 10;
	int* p = &a;//错误，不能把常量的地址泄露给普通指针
	const int* p = &a;//正确

	int a = 0;
	int* p = &a;
	const int* *q = &p;//错误的，const int **<===int **
	/*
	const int * *q = &p;
	错误的原因：
	如果const int * *q = &p是正确的，则：
	    *q<=>p; //*q即为p的地址
	因为*q只能接收const int类型变量的地址：
	所以有定义：const int b = 20;
	对于*q来说，他的类型是const int*类型
	而&b的类型也是const int*类型，所有有如下代码:
		*q = &b <=> p = &b;//即把常量b的地址赋给了一个普通指针p，
	所以const int* *q=&p是错误的
	*/
	可以修改为：
	int a = 0;
	const int* p = &a;
	const int* *q = &p;
	或者
	int a = 0;
	int* p = &a;
	const int* const*q = &p;
	return 0;
} 


/*
========》C++的引用
1.左值引用和右值引用
(1)右值引用:int&& c = 20;专门用来引用右值类型，指令上，可以自动产生临时量，然后直接引用临时量c=40;
(2)右值引用变量本身是一个左值，只能用左值引用来引用它
(3)不能用一个右值引用变量来引用一个左值

2.引用是一种更安全的指针
3.指针和引用的区别
(1)引用时必须初始化的，指针可以不初始化
(2)定义一个引用变量和一个指针变量,其汇编指令是一模一样的，通过指针解引用修改指针指向的内存的值和通过引用变量修改所引用内存的值，其底层指令也是一模一样的
(3)引用只有一级引用，没有多级引用；指针可以有一级指针，也可以有多级指针
(4)在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占 4个字节) ;
(5)引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小; 
(6)访问实体方式不同，指针需要显式解引用，引用编译器自己处理 ;
*/
void swap1(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;

}
void swap2(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 10;
	int* p = &a;
	int& b = a;
	*p = 20;
	20 20 20
	cout << a << " " << *p << " " << b << endl;
	b = 30;
	30 30 30
	cout << a << " " << *p << " " << b << endl;
	int a = 10;
	int b = 30;
	swap1(&a, &b);
	cout << "a:" << a << "b:" << b << endl;
	swap2(a, b);
	cout << "a:" << a << "b:" << b << endl;
	int array[5] = {};
	int* p = array;
	定义一个引用变量，来引用数组
	int(&q)[5] = array;
	cout << sizeof(array) << endl;
	cout << sizeof(q) << endl;
	cout << sizeof(p) << endl;
	int a = 10;//a为左值。左值他有内存，有名字，值可以修改
	int& b = a;
	int& c = 20;//错误，20是右值：没内存，没名字
	const int& c = 20;//常引用，引用右值时要加const，c不能修改
	C++11提供了右值引用
	int&& d = 20;//右值引用
	d = 30;//d可以修改
	int& e = d;//一个右值引用变量，本身是一个左值
	右值引用和常引用汇编指令是一样的 
	return 0;
}


/*
===========》const与一级指针、引用的结合应用
解题思路：把const与一级指针、引用结合的表达式还原成指针去判断
*/
int main()
{
	//写一句代码，在内存的0x0018ff44处写一个4字节的10
	int*&& p = (int*)0x0018ff44;
	int* const& p = (int*)0x0018ff44;
	
	int a = 10;
	int* p = &a;
	int*& q = p;
	return 0;
}


/*
======》new和delete
1.new和malloc的区别
2.delete和free的区别
new不仅可以做内存开辟，还可以做内存的初始化操作
malloc开辟内存失败，是通过返回值和nullptr作比较；而new开辟内存失败是通过抛出bad_alloc类型的异常来判断
malloc和free，都是C的库函数
new和delete都是运算符
3.new有多少种
int *p1=new int(20);//抛出异常的new
int *p2=new (nothrow) int;//不抛出异常的new
const int *p3=new cosnt int(40);//在堆上开辟一个常量空间并初始化为40
int *p4=new(某地址) int(50);定位new
*/
int main()
{
	int* p = new int(20);//开辟变量
	delete p;//释放

	int* q1 = new int[20];//开辟一个大小为20整形数组，不做初始化
	int* q2 = new int[20]();//辟一个大小为20整形数组,并将每一个元素初始化为0；
	delete[]q1;//释放
	delete[]q1;//释放

	//定位new
	int data = 0;
	int* p4 = new(&data)int(50);
	cout << "data:" << data << endl;
	return 0;
}


/*
==========》C++ OPP面向对象
C:各种各样的函数的定义
C++:类===>实体的抽象类型
实体(属性、行为)--->ADT(抽象数据类型)
  |                  |
对象     <---    (实例化)类(属性->成员变量  行为->成员方法)
OOP语言的四大特征：
抽象  
封装/隐藏：通过访问限定符:public,private,protected
继承  
多态
*/
const int NAME_LEN = 20;
class CGoods   //==>商品的抽象数据类型  类型不占空间   实例化的对象占空间
{
public://给外部提供公有的成员方法，来访问私有的属性
	//做商品数据初始化用
	void init(const char* name, double price, int amount);
	//打印商品信息
	void show();
	//给成员变量提供一组getXXX或setXXX的方法  类体内实现的方法，自动处理成内联函数
	void setName(char* name){strcpy(_name, name);}

	void setPrice(double price){_price = price;}
	void setAmount(int amount){_amount = amount;}

	const char* getName(){return _name;}
	double getPrince(){return _price;}
	int getAmount() {return _amount; }
private://属性一般都是私有的成员变量
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
类外定义成员方法
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << _name << endl;
	cout << "price:" << _price << endl;
	cout << "anount:" << _amount << endl;
}
int main()
{
	/*
	类可以实例化无数个对象
	每一个对象都有自己的成员变量
	但是他们共享一套成员方法
	对象内存大小：对象的内存的大小只和成员变量有关

	=========》this指针的作用
	调用show()后如何知道处理哪个对象？
	init(name,price,amount)===>怎么知道把信息初始化给哪一个对象？
	类的成员方法一经编译，所有的方法参数，都会加一个this指针，接受调用该成员方法的对象的地址
	this指针的作用：区分调用成员函数的对象
	*/
	CGoods good;//类的实例化
	//实际调用中
	//init(&good1,"面包",10.0,200)
	good.init("面包", 10.0, 200);
	//show(&good1)
	good.show();

	good.setPrice(20.5);
	good.setAmount(100);
	good.show();

	CGoods good1;
	good1.init("空调",10000.0,50);//类的实例化
	good1.show();
	return 0;
}

/*
=======>构造函数和析构函数
名字和类名一样，并且没有返回值
不同的对象：
栈上和.data段的内存系统会自动调用析构函数 先构造的后析构，后构造的先析构
堆上开辟的内存需要手动delete  系统不会自动调用析构函数
OOP实现一个顺序栈
*/
class SeqStack
{
public:
	//构造函数
	SeqStack(int size = 10)//带参数，一个类可以有多个构造函数
	{
		cout << this << " SeqStack()" << endl;//检查是否调用构造函数
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//自己的写初始化函数,需要显式调用
	//void init(int size = 10)
	//{
	//	_pstack = new int[size];
	//	_top = -1;
	//	_size = size;
	//}
	//析构函数：可以自己调用，但是不建议
	~SeqStack()//不带参数，每一个类只能有一个析构
	{
		cout << this << " ~SeqStack()" << endl;//检查是否调用析构函数
		delete[]_pstack;
		_pstack = nullptr;
	}
	//自己写的释放资源函数，需要显式调用
	//void release()
	//{
	//	delete[]_pstack;
	//	_pstack = nullptr;
	//}
	void push(int val)
	{
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty()
	{
		return _top == -1;
	}
	bool full()
	{
		return _top == _size - 1;
	}
private:
	int* _pstack;//动态开辟数组，存储顺序栈的元素
	int _top;//指向栈顶元素的位置
	int _size;//数组扩容后的总大小
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
SeqStack s2;//在.data段上
int main()
{
	//定义对象：
	//1.开辟内存
	//2.调用构造函数
	SeqStack s;//在栈上
	SeqStack s1(50);//在栈上
	SeqStack* ps = new SeqStack(60);//在堆上开辟，底层实现是先malloc开辟内存，然后调用对象构造函数SeqStack()，堆上内存需要我们自己手动释放。
	//s.init(5);//对象成员初始化操作
	for (int i = 0; i < 15; i++)
	{
		s.push(rand() % 100);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	//s.release();//释放对象成员变量占用的外部堆内存(外部资源)
	cout << endl;

	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << endl;
	delete ps;//先调用ps->~SeqStack(),然后free(ps)
	return 0;//出作用域时自动调用析构函数
}


/*
=========》对象的深拷贝和浅拷贝
浅拷贝：对象默认的拷贝构造是做内存的数据拷贝。
如果对象占用外部资源，那么浅拷贝会出现问题！！！
*/
class SeqStack
{
public:
	//构造函数
	SeqStack(int size = 10)//带参数，一个类可以有多个构造函数
	{
		cout << this << " SeqStack()" << endl;//检查是否调用构造函数
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//自定义拷贝构造函数<=====对象的浅拷贝出现问题
	SeqStack(const SeqStack& src)
	{
		/*
		浅拷贝：
		_pstack=src._pastack;
		_top = src._top;
		_size = src._size;
		*/
		//深拷贝
		cout << "SeqStack(const SeqStack& src)" << endl;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i)
		{
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	}
	//析构函数：可以自己调用，但是不建议
	~SeqStack()//不带参数，每一个类只能有一个析构
	{
		cout << this << " ~SeqStack()" << endl;//检查是否调用析构函数
		delete[]_pstack;
		_pstack = nullptr;
	}
	//赋值运算符重载
	SeqStack& operator=(const SeqStack& src)
	{
		cout << "operator=" << endl;
		//防止自赋值
		if (this == &src)
			return *this;
		//需要先释放当前对象占用的外部资源
		delete[]_pstack;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i)
		{
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
		return *this;
	}
	void push(int val)
	{
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty()
	{
		return _top == -1;
	}
	bool full()
	{
		return _top == _size - 1;
	}
private:
	int* _pstack;//动态开辟数组，存储顺序栈的元素
	int _top;//指向栈顶元素的位置
	int _size;//数组扩容后的总大小
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
int main()
{
	SeqStack s;//没有提供任何构造函数的时候，编译器会自己生成一个默认构造
	SeqStack s1(10);
	//#1和#2是一样的  都是初始化对象  调用的都是拷贝构造函数 都是内存拷贝
	SeqStack s2 = s1;//#1
	//SeqStack s2(s1);//#2

	SeqStack s3;
	//赋值操作，并没有生成新的对象
	//s2.operator=(s1);
	//void operator=(const SeqStack& src)
	s1 = s1;//
	return 0;
}


/*
拷贝构造和赋值重载实例：
1.string类型
2.循环队列Queue
*/
//1.出处：C/C++编写高质量编程
//编写类String的构造函数、析构函数和赋值函数
class String 
{
public:
	String(const char* str = nullptr);//普通构造函数
	String(const String& other);//拷贝构造函数
	~String();//析构函数
	String& operator=(const String& other);//赋值函数
private:
	char* m_data;//用于保存字符串
};
//普通构造函数
String::String(const char* str)
{
	if (str != nullptr)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}
//拷贝构造函数
String::String(const String& other)
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}
//析构函数
String::~String()
{
	delete[]m_data;
	m_data = nullptr;
}
//赋值函数:返回String&是为了支持连续赋值操作
String& String::operator=(const String& other)
{
	//1.防止自赋值
	if (this == &other)
		return *this;
	//2.释放当前对象占用的外部资源
	delete[]m_data;
	//3.分配新的资源，并且复制内容
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	//返回本对象的引用
	return *this;
}
int main()
{
	//调用带const char*参数的构造函数
	String str1;
	String str2("hello");
	String str3 = "world";
	//调用拷贝构造函数
	String str4 = str3;
	String str5(str3);
	//调用赋值重载函数
	str3 = str1 = str2;
	return 0;
}

//2.循环队列
class Queue
{
public:
	Queue(int size = 20)
	{
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}
	Queue(const Queue& src)
	{
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
	}
	Queue& operator=(const Queue& src)
	{
		//1.检查自赋值
		if (this == &src)
			return *this;
		//2.释放原有空间
		delete[]_pQue;
		//3.开辟空间并进行赋值
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
		//4.返回本对象的引用
		return *this;
	}
	~Queue()
	{
		delete[]_pQue;
		_pQue = nullptr;
	}
	void push(int val)//入队
	{
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	void pop()//出队
	{
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}
	int front()//获取队头元素
	{
		return _pQue[_front];
	}
	bool full()
	{
		return (_rear + 1) % _size == _front;
	}
	bool empty()
	{
		return _front == _rear;
	}
private:
	int* _pQue;//申请队列的数组空间
	int _front;//队头
	int _rear;//队尾4
	int _size;//队列扩容的总大小
	
	void resize()
	{
		int* ptmp = new int[2 * _size];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			ptmp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};
int main()
{
	Queue queue;
	for (int i = 0; i < 20; ++i)
	{
		queue.push(rand() % 100);
	}
	while (!queue.empty())
	{
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;
	Queue queue1 = queue;
	Queue queue2;
	queue2 = queue1;

	return 0;
}

/*
========》构造函数的初始化列表:可以指定当前对象成员变量的初始化方式
CDate信息是CGoods商品中信息的一部分


*/
class CDate
{
public:
	CDate(int y, int m, int d)//自定义了一个构造函数，此时编译器就不会自动生成默认构造函数
	{
		_year = y;
		_month = m;
		_day = d;
	}
	void show()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class CGoods
{
public:
	CGoods(const char* n, int a, double p,int y,int m,int d)
		:_date(y,m,d),//CDate _date(y,m,d)
		_amount(a),//相当于int amount = a;
		_price(p)//#1构造函数的初始化列表
	{
		//#2当前类类型构造函数体
		strcpy(_name, n);
		_amount = a;//相当于int _amount;_amount=a;
	}
	void show()
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;//成员对象  对象生成：1.分配内存2.调用构造函数
};
int  main()
{
	CGoods good("商品", 100, 35.0, 2019, 5, 12);
	good.show();
	return 0;
}


class Test
{
public:
	Test(int data = 10):mb(data),ma(mb){}
	void show()
	{
		cout << "ma:" << ma << " mb:" << mb << endl;
	}
private:
	//成员变量的初始化和它们定义的顺序有关，和构造函数初始化列表中出现的先后顺序无关。
	//int ma;//此时ma将会被初始化为0xCCCCCCCC，因为在Windows VS下会给开辟的栈帧初始化为0xCCCCCCCC，即-858993460
	int mb;//mb=10
	int ma;//ma=10
};
int main()
{
	Test t;
	t.show();
	return 0;
}



/*
======>类的各种成员--->成员方法/变量
普通成员方法：=======>编译器会添加一个this形参变量
1.属于类的作用域
2.调用该方法时，需要依赖一个对象(常对象是无法调用的 实参：cosnt CGoods*   形参：CGoods *this
3.可以任意访问对象的私有成员变量

static静态成员方法：=====>不会生成this形参,修饰所有对象共享的信息
1.属于类的作用域
2.用类名作用域来调方法
3.可以任意访问对象的私有成员，仅限于不依赖对象的成员(只能调用其他的static静态成员)

const常成员方法：=======>const CGoods* this
1.属于类的作用域
2.调用依赖于一个对象，普通对象或者对象都可以
3.可以任意访问对象的私有成员，但只能读，不能写
*/
class CDate
{
public:
	CDate(int y, int m, int d) 
	{
		_year = y;
		_month = m;
		_day = d;
	}

	void show()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class CGoods
{
public:
	CGoods(const char* n, int a, double p, int y, int m, int d)
		:_date(y, m, d)
		, _amount(a)
		, _price(p)
	{
		strcpy(_name, n);
		_count++;
	}
	//普通的成员方法
	void show()//打印商品的私有信息
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	} 

	//静态的成员方法：没有this指针
	static void showCGoodCount()//打印所有商品共享的信息
	{
		cout << "所有商品的种类数量是：" << _count << endl;
	}

	//常成员方法  只要是只读操作的成员方法，一律实现成const常成员方法
	void show()const//打印商品的私有信息
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;
	//static定义的变量不属于对象,而是属于类级别的
	static int _count;//声明，用来记录商品对象的总数量
};
//static成员变量一定要在类外进行定义并初始化
int CGoods::_count = 0;
int main()
{
	CGoods good1("商品1", 100, 35.0, 2019, 5, 12);
	good1.show();

	CGoods good2("商品2", 100, 35.0, 2019, 5, 12);
	good2.show();

	CGoods good3("商品3", 100, 35.0, 2019, 5, 12);
	good3.show();

	CGoods good4("商品4", 100, 35.0, 2019, 5, 12);
	good4.show();

	//统计所有商品的总数量
	CGoods::showCGoodCount();

	const CGoods good5("非卖商品5", 100, 35.0, 2019, 5, 12);
	good5.show();//CGoods::show(&good5)  const CGoods*   -->const CGoods  *this

	return 0;
}


/*
========》指向类成员(成员变量和成员方法)的指针
1.指向成员变量的指针
通过对象去访问
2.指向普通成员方法的指针
也是要依赖于对象访问
3.指向static成员方法或static成员变量的指针
不需要依赖于对象，直接可以访问
不需要通过对象
*/
class Test
{
public:
	void func()
	{
		cout << "call Test :: func" << endl;
	}
	static void static_func()
	{
		cout << "Test :: static_func" << endl;
	}
	int ma;
	static int mb;
};
int Test::mb;
int main()
{
	Test t1;
	Test* t2 = new Test();
	//指向成员变量的指针
	int Test::* p1 = &Test::ma;
	t1.*p1 = 20;
	cout << t1.*p1 << endl;
	t2->ma = 30;
	cout << t2->ma << endl;
	
	//指向static静态成员变量的指针
	int* p2 = &Test::mb;
	*p2 = 40;
	cout << *p2 << endl; 

	//指向成员方法的指针
	//也是要依赖于对象的
	void (Test:: * pfunc)() = &Test::func;
	(t1.*pfunc)();
	(t2->*pfunc)();

	//指向类的static成员方法的指针：
	void(*pfunc1)() = &Test::static_func;
	(*pfunc1)();

	delete t2;
	return 0;
}
#endif
