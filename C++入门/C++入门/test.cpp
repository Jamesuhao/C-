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
	//右值引用和常引用汇编指令是一样的 
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
拷贝构造函数的调用情景：
1.在一个对象以值传递的方式传入函数体时；
2.一个对象以值传递的方式从函数返回时；
3.一个对象用于给另外一个对象进行初始化（常称为赋值初始化）时被自动调用。
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
	int _rear;//队尾
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

/*
//C++模板中，所有的模板参数的生命周期只是类或者函数的左括号到右括号
====》C++函数模板
模板的意义：对类型也可以进行参数化了
函数原型：int sum(int a,int b){ return a+b; }
理解重点：
==>函数模板:是不进行编译的，因为类型还不知道
==>模板的实例化:函数调用点进行实例化
模板的实例化：生成模板函数
在函数调用点，编译器用用户指定的类型，从原模版实例化一份函数代码出来
一种参数类型只实例化一次，后续直接使用实例化后的模板函数代码即可
==>模板函数:才是要被编译器所编译的

==>模板类型参数:用typename/class进行定义，一般多用typename

==>模板的实参推演:可以根据用户传入的实参类型，来推导出模板类型参数的具体类型
==>模板的特列化(专用化):特殊(不是编译器提供的，而是用户提供的)的实例化。

==>函数模板、模板的特例化、非模板函数的重载关系

注意：
函数模板不能在一个文件中定义，在另外一个文件中使用的，因为在函数模板是不进行编译的，在连接时使用文件会生成*UND*符号，却找不到其定义
模板代码调用之前，一定要看到模板定义的地方，这样的话，模板才能进行正常的实例化，产生能够被编译器编译的代码
所以，模板代码都是放在头文件当中的，然后再源文件中直接#include包含

如果在两个文件中定义的解决办法：告诉编译器，在调用文件中进行指定类型的模板实例化
示例:
tmplate bool compare<int>(int,int);
tmplate bool compare<double>(double,double);
只是了解，不建议这样去做
*/
//函数模板
template<typename T>//定义一个模板参数列表
bool compare(T a, T b)//compare是一个函数模板，函数模板体是不进行编译的
{
	cout << "compare template" << endl;
	return a > b;
}
//针对compare函数模板，提供const char*类型的特例化版本
template<>
bool compare<const char*>(const char* a, const char* b)
{
	cout << "compare<const char*>"<<endl;
	return strcmp(a, b) > 0;
}
//非模板函数 - 普通函数
bool compare(const char* a, const char* b)
{
	cout << "normal compare" << endl;
	return strcmp(a, b) > 0;
}
int main()
{
	//函数的调用点:要进行模板的实例化
	//模板名+参数列表==>从函数模板实例化一份函数代码
	compare<int>(10, 20);
	//bool compare<int>(int a,int b)
	//{
	//		return a>b;
	//}

	compare<double>(10.5, 20.5);//函数的调用点
	//bool compare<double>(double a, double b)
	//{
	//	return a > b;
	//}

	//如未指定类型，则进行函数模板实参推演
	//T: int 
	compare(20, 30);
	 
	//compare<int>(30, 40.5);//会将double类型强转为int类型

	//函数模板实参推演 T:cosnt char *
	//对于某些类型来说，依赖编译器默认实例化的模板代码，代码处理逻辑是错误的
	//所以需要进行模板的特例化
	compare<const char*>("aaa", "bbb");//调用函数模板实例化模板函数
	//bool compare<const char*>(const char* a, const char* b)
	//{
	//	return a > b;
	//}
	compare("aaa", "bbb");//编译器优先把compare处理成函数名字，没有普通函数时，才去找compare模板

	return 0;
}

/*
==>模板非类型参数:
必须是整数类型(整数或者地址/引用都可以)，都是常量，只能使用，而不能修改
*/
template<typename T, int SIZE>//该例中int SIZE就是一个非类型参数，只能传常量
void sort(T* arr)
{
	for (int i = 0; i < SIZE - 1; ++i)
	{
		for (int j = 0; j < SIZE - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	}
}
int main()
{
	int arr[] = { 12,5,7,89,32,21,35 };
	const int size = sizeof(arr) / sizeof(arr[0]);
	sort<int, size>(arr);//函数模板的实例化
	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

/*
=========》理解类模板
类模板 ==> 实例化 ==>类模板
可以有默认的类型参数
*/
//类模板
template<typename T>
//template<typename T=int> //带默认类型参数的类模板
//实例化时可以不传参数类型
class SeqStack//模板名称
{
public:
	//模板名+类型参数列表====》类名称
	//类模板中，构造函数和析构函数可以省略其类型参数列表
	//其他出现模板的地方都加上类型参数列表
	SeqStack(int size = 10)
		:_pstack(new T[size])
		, _top(0)
		,_size(size)
	{ }
	~SeqStack()
	{
		delete[]_pstack;
		_pstack = nullptr;
	}
	SeqStack(const SeqStack<T>& stack)
		:_top(stack._top)
		,_size(stack._size)
	{
		_pstack = new T[_size];
		//不要用memcopy进行拷贝：会发生浅拷贝
		for (int i = 0; i < _top; ++i)
		{
			_pstack[i] = stack._pstack[i];
		}
	}
	SeqStack<T>& operator=(const SeqStack<T>& stack)
	{
		if (this == &stack)
			return *this;
		delete[]_pstack;

		_top = stack._top;
		_size = stack._size;
		_pstack = new T[_size];
		for (int i = 0; i < _top; ++i)
		{
			_pstack[i] = stack._pstack[i];
		}
		return *this;
	}
	void push(const T& val);
	void pop()
	{
		if (empty() == 0)
			--_top;
	}
	T top()const//对于只读操作接口，将其写为const成员，因为const成员变量不能访问普通成员方法，但是const成员方法普通成员变量可以访问
	{
		if (empty())
			throw "stack is empty!";//抛出异常也代表函数逻辑结束
		return _pstack[_top - 1];
	}
	bool full()const { return _top == _size; }//栈满
	bool empty()const { return _top == 0; }//栈空
private:
	T* _pstack;
	int _top;
	int _size;

	//顺序栈数组底层按2倍的方式扩容
	void expand()
	{
		T* ptmp = new T[_size * 2];
		for (int i = 0; i < _top; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
template<typename T>//上一个参数作用域结束，需要重新定义
void SeqStack<T>:: push(const T& val)//入栈操作
{
	if (full())
		expand();
	_pstack[_top++] = val;
}
int main()
{
	//类模板选择性实例化：要用什么实例化什么
	//实例化后会生成模板类
	//即：class SeqStack<int>{ };
	SeqStack<int>s1;
	s1.push(20);
	s1.push(78);
	s1.push(32);
	s1.push(15);
	s1.pop();
	cout << s1.top() << endl;
	return 0;
}

//使用类模板写循环队列
template<typename T>
class Queue
{
public:
	Queue(int size=10)
		:_pQueue(new T[size])
	    ,_rear(0)
		,_front(0)
		,_size(size)
	{ }
	~Queue()
	{
		delete[]_pQueue;
		_pQueue = nullptr;
	}
	Queue(const Queue<T>& Queue)
		:_front(Queue._front)
		,_rear(Queue._rear)
		,_size(Queue._size)
	{
		_pQueue = new T[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQueue[i] = Queue._pQueue[i];
		}
	}
	Queue<T>& operator=(const Queue<T>& Queue)
	{
		if (this == &Queue)
			return *this;
		delete[]_pQueue;
		_front = Queue._front;
		_rear = Queue._size;
		_size = Queue._size;
		_pQueue = new T[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQueue[i] = Queue._pQueue[i];
		}
	}
	void push(const T& val)
	{
		if (full())
			resize();
		_pQueue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	void pop()
	{
		if (empty() == 0)
			_front = (_front + 1) % _size;
	}
	T front()const
	{
		if (empty())
			throw "Queue is empty";
		return _pQueue[_front];
	}
	bool empty()const
	{
		return _rear == _front;
	}
	bool full()const
	{
		return (_rear + 1) % _size == _front;
	}
private:
	T* _pQueue;
	int _front;
	int _rear;
	int _size;
	void resize()
	{
		T* ptmp = new T[_size * 2];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			ptmp[index++] = _pQueue[i];
		}
		delete[]_pQueue;
		_pQueue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};
int main()
{
	Queue<int> q1;
	q1.push(12);
	q1.push(20);
	q1.push(30);
	q1.push(40);
	q1.push(13);
	cout << q1.front() << endl;
	q1.pop();
	cout << q1.front() << endl;
	q1.pop();
	cout << q1.front() << endl;
	q1.pop();
	cout << q1.front() << endl;
	q1.pop();
	cout << q1.front() << endl;
	q1.pop();
	cout << q1.front() << endl;
	return 0;
}


/*
类模板==》实现一个C++  STL的一个顺序容器 vector向量容器+空间配置器
容器的空间配置器allocator：
做四件事：内存开辟/内存释放  对象构造/对象析构

*/
//定义容器的空间配置器，和C++标准库的allocator实现一样
template<typename T>
struct Allocator
{
	T* allocate(size_t size)//负责内存开辟
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//负责内存释放
	{
		free(p);
	}
	void construct(T* p, const T& val)//负责对象构造
	{
		new (p) T(val);//定位new
	}
	void destory(T* p)//负责对象析构
	{
		p->~T();//~T代表了T类型的析构函数
	}
};
/*
容器底层内存开辟，内存释放，对象构造和析构都通过allocator空间配置器实现
*/
template<typename T,typename Alloc=Allocator<T>>
class vector
{
public:
	vector(int size = 10)
		//:_allocator(alloc);
	{
		//需要把内存开辟和对象构造分开处理
		//_first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		//析构容器有效的元素，然后释放_first指向的堆内存
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)//把_first指针指向的数组的有效元素进行析构操作
		{
			_allocator.destory(p);
		}
		_allocator.deallocate(_first);//释放堆上的数组内存
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		//_first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == &rhs)
			return *this;
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destory(p);
		}
		_allocator.deallocator(_first);
		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;

		//_first = new T[size];
		for (int i = 0; i < len; ++i)
		{
			//_first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}

		_end = _first + size;
		_last = _first + len;
		return *this;
	}
	void push_back(const T& val)//向容器末尾添加参数
	{
		if (full())
			expand();
		//*_last++ = val;
		//_last指针指向的内存构造一个值为val的对象
		_allocator.construct(_last, val);
		_last++;
	}
	void pop_back()//从末尾删除元素
	{
		if (empty())
			return;
		//--_last;
		//不仅要把_last指针--，还需要析构删除的元素
		--_last;
		_allocator.destory(_last);
	}
	T back()const//返回容器最后一个有效元素的值
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _last == _first; }
	int size()const { return _last - _first; }
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有效元素的后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间配置器对象
	void expand()//容器的二倍扩容操作
	{
		int size = _end - _first;
		//T* ptmp = new T[size * 2];
		T* ptmp = _allocator.allocate(2 * size);
		for (int i = 0; i < size; ++i)
		{
			//ptmp[i] = _first[i];
			_allocator.construct(ptmp + i, _first[i]);
		}
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)
		{
			_allocator.destory(p);
		}
		_allocator.deallocate(_first);
		_first = ptmp;
		_last = _first + size;
		_end = _first + size * 2;
	}
};
class Test
{
public:
	Test(){ cout << "Test()" << endl;}
	~Test(){ cout << "~Test()" << endl;}
	Test(const Test&) { cout << "Test(const Test&)" << endl; }
};
int main()
{
	//vector<int>vec;
	//for (int i = 0; i < 20; ++i)
	//{
	//	vec.push_back(rand() % 100);
	//}
	//vec.pop_back();
	//while (!vec.empty())
	//{
	//	cout << vec.back() << " ";
	//	vec.pop_back();
	//}
	//cout << endl;
	Test t1, t2, t3;
	cout << "------------------------------" << endl;
	vector<Test>vec;
	vec.push_back(t1);
	vec.push_back(t2);
	vec.push_back(t3);
	cout << "------------------------------" << endl;
	vec.pop_back();//只需要析构对象，要把对象的析构和内存的释放分开
	cout << "------------------------------" << endl;
	return 0;
}


/*
C++的运算符重载：使对象的运算符表现得和编译器内置类型一样
template<typename T>
T sum(T a,T b)
{
	return a+b;  //a.operator+(b)
}
1.编译器做对象运算的时候，会调用对象的运算符重载函数(优先调用成员方法)，
如果没有成员方法，就在全局作用域找合适的运算符重载函数
复数类
*/
class CComplex
{
public:
	CComplex(int r = 0, int m = 0)
		:mreal(r)
		,mimage(m)
	{ }
	CComplex(const CComplex& src)
		:mreal(src.mreal)
		, mimage(src.mimage)
	{ }
	//指导编译器怎么做CComplex类对象的加法操作
	CComplex operator+(const CComplex& src)
	{
		//CComplex comp;
		//comp.mreal = this->mreal + src.mreal;
		//comp.mimage = this->mimage+ src.mimage;
		//return comp;

		//上述代码的的优化
		return CComplex(this->mreal + src.mreal, 
			this->mimage + src.mimage);
	}
	CComplex operator++(int)
	{
		//CComplex  ptmp = *this;
		//mreal += 1;
		//mimage += 1;
		//return ptmp;

		//上述代码的的优化
		return CComplex(mreal++, mimage++);
	}
	CComplex& operator++()
	{
		mreal += 1;
		mimage += 1;
		return *this;
	}
	void  operator+=(const CComplex& src)
	{
		this->mreal += src.mreal;
		this->mimage += src.mimage;
	}
	void show()
	{
		cout << "real:" << mreal << "  mimage:" << mimage << endl;
	}
private:
	int mreal;
	int mimage;
	friend CComplex operator+(const CComplex& lhs, const CComplex& rhs);
	friend ostream& operator<<(ostream& out, const CComplex& src);
	friend istream& operator>>(istream& in, CComplex& src);
};
CComplex operator+(const CComplex& lhs, const CComplex& rhs)
{
	return CComplex(lhs.mreal + rhs.mreal, 
		lhs.mimage + rhs.mimage);
}
ostream& operator<<(ostream& out, const CComplex& src)
{
	out << "mreal:" << src.mreal << "  mimage:" << src.mimage << endl;
	return out;
}
istream& operator>>(istream& in, CComplex& src)
{
	in >> src.mreal>> src.mimage;
	return in;
}
int main()
{
	CComplex comp1(10, 10);
	CComplex comp2(20, 20);
	//comp1.operator+(comp2) 加法运算符重载函数
	CComplex comp3 = comp1 + comp2;
	comp3.show();
	CComplex comp4 = comp1 + 20;//comp1.operator+(20) int->CComplex==>CCompelx(int)
	comp4.show();
	//需要提供一个全局的+运算符重载  operator+(30,comp1)
	CComplex comp5 = 30 + comp1;
	comp5.show();

	//CCompelx operator++(int)
	comp5 = comp1++;//++ --单目运算符 operator++(int)  int表示后置++
	comp1.show();
	comp5.show();
	//CComplex operator++(int)
	comp5 = ++comp1;
	comp1.show();
	comp5.show();

	comp1 += comp2;
	comp1.show();
	comp2.show();
	cin >> comp1 >> comp4;
	cout << comp4 << endl;
	cout << comp1 << endl;
	cout << comp2 << endl; //对象信息的输出
	
	return 0;
} 
 
/*
string类

*/
#include<string>
//模式实现String类
class String
{
public:
	String(const char* p = nullptr)
	{
		cout << "String()" << endl;
		if (p != nullptr)
		{
			_pstr = new char[strlen(p) + 1];
			strcpy(_pstr, p);
		}
		else
		{
			_pstr = new char[1];
			*_pstr = '\0';
		}
	}
	~String()
	{
		cout << "~String()" << endl;
		delete[]_pstr;
		_pstr = nullptr;
	}
	String(const String &str)
	{
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
	}
	String& operator=(const String& str)
	{
		if (this == &str)
			return*this;
		delete[]_pstr;
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
		return *this;
	}
	bool operator>(const String& str)const
	{
		return strcmp(_pstr, str._pstr) > 0;
	}
	bool operator<(const String& str)const
	{
		return strcmp(_pstr, str._pstr) < 0;
	}
	bool operator==(const String& str)const
	{
		return strcmp(_pstr, str._pstr) == 0;
	}
	int length()const { return strlen(_pstr); }
	const char* c_str() const  { return _pstr; }
	//可读可写
	char& operator[](int index) { return _pstr[index]; }
	//常对象调用，只读不改
	char& operator[](int index)const { return _pstr[index]; }
private:
	char* _pstr;
	friend String operator+(const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);
};
String operator+(const String& lhs, const String& rhs)
{
	//效率较低
	//char* ptmp = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	//strcpy(ptmp, lhs._pstr);
	//strcat(ptmp,rhs._pstr);
	//String tmp(ptmp);
	//delete[]ptmp;
	//return tmp;

	//优化
	String tmp;
	tmp._pstr = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	strcpy(tmp._pstr, lhs._pstr);
	strcat(tmp._pstr, rhs._pstr);
	return tmp._pstr;
	//在优化：
	//后续补充
}
ostream& operator<<(ostream& out, const String& str)
{
	out << str._pstr;
	return out;
}
istream& operator>>(istream& in, String& str)
{
	in >> str._pstr;
	return in;
}
int main()
{
	String a1="bbbbb";
	String a2 = "aaaa";
	String a3 = a1 + a2;
	cout << a3 << endl;
	//char buff[1024] = { 0 };
	//strcpy(buff, a3.c_str());
	//cout << "buff: " << buff << endl;
	//cin >> a3;
	//cout << a3 << endl;
	return 0;
}


/*
======》字符串对象的迭代器iterator实现:是容器的一种嵌套使用
容器中有两种方法：
1.begin():返回底层数据结构中首元素的迭代器
2.end():返回底层数据结构中末尾元素后继位置的迭代器

迭代器的功能：
提供一种统一的方式，来透明的遍历容器。

迭代器可以透明的访问容器内部的元素的值：
我们无需关心容器底层中数据是以什么数据结构存储的，我们只需要关心这组数据的起始位置和结束位置，然后对迭代器进行递增访问即可

迭代器多使用于泛型算法：
1.泛型算法参数接收的都是迭代器!
2.泛型算法是一组全局的函数，是给所有的容器用的!
3.泛型算法，有一套方式，能够统一的遍历所有的容器的元素，我们所说的方法即迭代器。
*/
class String
{
public:
	String(const char* p = nullptr)
	{
		cout << "String()" << endl;
		if (p != nullptr)
		{
			_pstr = new char[strlen(p) + 1];
			strcpy(_pstr, p);
		}
		else
		{
			_pstr = new char[1];
			*_pstr = '\0';
		}
	}
	~String()
	{
		cout << "~String()" << endl;
		delete[]_pstr;
		_pstr = nullptr;
	}
	String(const String& str)
	{
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
	}
	String& operator=(const String& str)
	{
		if (this == &str)
			return*this;
		delete[]_pstr;
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
		return *this;
	}
	bool operator>(const String& str)const
	{
		return strcmp(_pstr, str._pstr) > 0;
	}
	bool operator<(const String& str)const
	{
		return strcmp(_pstr, str._pstr) < 0;
	}
	bool operator==(const String& str)const
	{
		return strcmp(_pstr, str._pstr) == 0;
	}
	int length()const { return strlen(_pstr); }
	const char* c_str() const { return _pstr; }
	//可读可写
	char& operator[](int index) { return _pstr[index]; }
	//常对象调用，只读不改
	char& operator[](int index)const { return _pstr[index]; }

	//给String字符串类型提供迭代器的实现
	class iterator
	{
	public:
		iterator(char*p=nullptr)
			:_p(p)
		{ }
		bool operator!=(const iterator& it)
		{
			return _p != it._p;
		}
		void operator++()
		{
			++_p;
		}
		char& operator*() { return *_p; }
	private:
		char* _p;
	};
	//begin()返回的是容器底层首元素的迭代器的表示
	iterator begin() { return iterator(_pstr); }
	//end()返回的是容器末尾元素后继位置的迭代器的表示
	iterator end() { return iterator(_pstr + length()); }
private:
	char* _pstr;
	friend String operator+(const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);
};
String operator+(const String& lhs, const String& rhs)
{
	String tmp;
	tmp._pstr = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	strcpy(tmp._pstr, lhs._pstr);
	strcat(tmp._pstr, rhs._pstr);
	return tmp._pstr;
}
ostream& operator<<(ostream& out, const String& str)
{
	out << str._pstr;
	return out;
}
istream& operator>>(istream& in, String& str)
{
	in >> str._pstr;
	return in;
}
int main()
{
	String str1 = "hello world!";//str1叫容器吗？底层放了一组char类型的字符
	//容器的迭代器类型
	String::iterator it = str1.begin();
	//也可以使用auto关键字来定义
	//auto it = str1.begin();
	for (; it != str1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//c++11:以foreach的方式来遍历容器的内部元素==>底层还是通过迭代器进行遍历的，去掉begin和end方法后就无法遍历了
	for (char ch : str1)
	{
		cout << ch << " ";
	}
	cout << endl;
	return 0;
}
#endif 
