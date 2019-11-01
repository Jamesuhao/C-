#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using  namespace std;

/*
C++模板中，所有的模板参数的生命周期只是类或者函数的左括号到右括号
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
	cout << "compare<const char*>" << endl;
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
类模板 ==> 实例化 ==>模板类
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
		, _size(size)
	{ }
	~SeqStack()
	{
		delete[]_pstack;
		_pstack = nullptr;
	}
	SeqStack(const SeqStack<T>& stack)
		:_top(stack._top)
		, _size(stack._size)
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
void SeqStack<T>::push(const T& val)//入栈操作
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
	Queue(int size = 10)
		:_pQueue(new T[size])
		, _rear(0)
		, _front(0)
		, _size(size)
	{ }
	~Queue()
	{
		delete[]_pQueue;
		_pQueue = nullptr;
	}
	Queue(const Queue<T>& Queue)
		:_front(Queue._front)
		, _rear(Queue._rear)
		, _size(Queue._size)
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
template<typename T, typename Alloc = Allocator<T>>
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
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
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
#endif

