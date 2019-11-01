#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
//#include<vector>
using  namespace std;

#if 0 
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
		, mimage(m)
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
	in >> src.mreal >> src.mimage;
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
	String a1 = "bbbbb";
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
可读可写的一种结构

迭代器可以透明的访问容器内部的元素的值：
我们无需关心容器底层中数据是以什么数据结构存储的，我们只需要关心这组数据的起始位置和结束位置，然后对迭代器进行递增访问即可

迭代器多使用于泛型算法：
1.泛型算法参数接收的都是迭代器!
2.泛型算法是一组全局的函数，是给所有的容器用的!
3.泛型算法，有一套方式，能够统一的遍历所有的容器的元素，我们所说的方式即迭代器。
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
		iterator(char* p = nullptr)
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
/*
类模板 == 》实现一个C++  STL的一个顺序容器 vector向量容器 + 空间配置器 + 迭代器
容器的空间配置器allocator：
做四件事：内存开辟 / 内存释放  对象构造 / 对象析构
迭代器：
1.定义实现迭代器(迭代器一般实现成容器嵌套类型):class  其底层存储的数据是什么类型迭代器的私有成员即为什么类型
2.实现容器的两个方法：begin()和end()
3.实现!=运算符的重载、前置++运算符的重载、*解引用运算符的重载
4.可以使用auto关键字或者类名::itreator定义容器的迭代器
5.遍历时可以使用foreach或者标准循环来遍历
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
	void push_back(const T& val)//向容器末尾添加元素
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
		//erase(it)；
		//verify(it._ptr,_last)//检查从删除位置至末尾位置是否有效
		//insert(it,val)
		//verify(it._ptr,_last)//检查从插入位置至末尾位置是否有效
		//检查将要删除的位置元素是否有效
		verify(_last - 1, _last);
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
	T& operator[](int index)
	{
		if (index < 0 || index >= size())
			throw"OuutOfRangeException";
		return _first[index];
	}
	//迭代器一般实现成容器嵌套类型
	class iterator
	{
	public:
		friend class vector<T, Alloc>;
		//构造函数
		iterator(vector<T, Alloc>* pvec = nullptr
			, T* ptr = nullptr)
			:_ptr(ptr)
			, _pVec(pvec)
		{
			Iterator_Base* itb =
				new Iterator_Base(this, _pVec->_head._next);
			_pVec->head._next = itb;
		}
		//!=运算符重载
		bool operator!=(const iterator& it)const
		{
			//检查迭代器的有效性
			if (_pVec == nullptr || _pVec != it._pVec)
			{
				throw"iterotar incompatable!";
			}
			return _ptr != it._ptr;
		}
		//前置++运算符重载
		void operator++()
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw"iterotar incompatable!";
			}
			_ptr++;
		}
		//*解引用运算符重载
		T& operator*()
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw"iterotar incompatable!";
			}
			return *_ptr;
		}
		const T& operator*()const
		{
			//检查迭代器的有效性
			if (_pVec == nullptr)
			{
				throw"iterotar incompatable!";
			}
			return *_ptr;
		}
	private:
		T* _ptr;
		//当前迭代器迭代的是那个对象
		vector<T, Alloc>* _pVec;
	};
	//需要给容器提供begin和end方法
	iterator begin() { return iterator(this, _first); }
	iterator end() { return iterator(this, _last); }
	//检查迭代器失效
	void verify(T* first, T* last)
	{
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head.next;
		while (it != nullptr)
		{
			if (it->_cur->_ptr >= first && it->_cur->_ptr <= last)
			{
				//迭代器失效，把iterator持有的容器指针置nullptr
				it->_next->_pVec = nullptr;
				//删除当前迭代器结点，继续判断后面的迭代器结点是否失效
				pre->_next = it->next;
				delete it;
				it->pre->_next;
			}
			else
			{
				pre = it;
				it = it->_next;
			}
		}
	}
	//自定义vector容器insert方法的实现
	iterator insert(iterator it, const T& v)
	{
		/*
		1.不考虑扩容
		2.不考虑it._ptr的合法性
		*/
		verify(it._ptr - 1, _last);
		T* p = _last;
		while (p > it._ptr)
		{
			_allocator.construct(p, *(p - 1));
			_allocator.destory(p - 1);
			p--;
		}
		_allocator.construct(p, val);
		_last++;
		return iterator(this, p);
	}
private:
	T* _first;//指向数组起始的位置
	T* _last;//指向数组中有效元素的后继位置
	T* _end;//指向数组空间的后继位置
	Alloc _allocator;//定义容器的空间配置器对象
	struct Iterator_Base
	{
		Iterator_Base(iterator* c = nullptr, Iterator_Base *n= nullptr)
			:_cur(c)
			, _next(n)
		{ }
		iterator* _cur;
		Iterator_Base* _next;
	};
	Iterator_Base _head;
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
int main()
{
	vector<int>vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	//仅有底层数据结构为线性的时，才可使用这种方法遍历
	int size = vec.size();
	for (int i = 0; i < size; ++i)
		cout << vec[i] << " ";
	cout << endl;

	//迭代器遍历  通用的
	//也可写成：
	auto it = vec.begin();
	//vector<int>::iterator it = vec.begin();

	for (; it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

/*
======》迭代器的失效问题:使用库中的迭代器来引出问题所在
1.迭代器为什么会失效？
===>a：第一次调用erase以后，迭代器就失效了
当我们删除迭代器某一位置的元素后，迭代器即从删除位置到迭代器末尾位置全部失效
===>b：第一次调用insert后，迭代器就失效了
当我们为迭代器在某一位置增加元素后，迭代器即从增加位置到迭代器末尾位置全部失效
      迭代器依然有效果     迭代器全部失效
首元素         —>    插入点/删除点     —>末尾元素    
===>c：当我们增加元素时，需要为迭代器扩容时，扩容后，原迭代器则全部失效
当我们为迭代器扩容后，就要重新开辟内存存放数据，则原迭代器将全部失效
        原来容器的所有迭代器就全部失效了
首元素          —>   插入点/删除点     —>末尾元素
===>d：不同容器的迭代器是不能进行比较运算的

2.迭代器失效了以后，问题该怎么解决？
对插入/删除点的迭代器进行更新操作
*/
int main()
{
	vector<int>vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//问题1：把vec容器中所有的偶数全部删除
	auto it = vec.begin();
	//失效
	for (; it != vec.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			vec.erase(it);
		}
	}
	//解决问题
	while (it != vec.end())
	{
		//迭代器失效问题1：第一次调用erase以后，迭代器就失效了
		if (*it % 2 == 0)
		{
			it = vec.erase(it);//更新迭代器
		}
		else
		{
			++it;
		}
	}
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//问题2：给vec容器中所有的偶数前面添加一个小于偶数值1的数字
	auto it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		//迭代器失效问题2：迭代器在第一次调用insert后，迭代器就失效了
		if (*it % 2 == 0)
		{
			//失效
			//vec.insert(it, *it - 1);
			//问题解决
			it = vec.insert(it, *it - 1);
			++it;
		}
	}
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
#endif
/*
内存池 进程池 线程池 连接池 对象池
=======》new、delete重载实现的对象池应用


*/
template<typename T>
class Queue
{
public:
	Queue()
	{
		_front = _rear = new QueueItem();
	}
	~Queue()
	{
		QueueItem* cur = _front;
		while (cur != nullptr)
		{
			_front = _front->_next;
			delete cur;
			cur = _front;
		}
	}
	void push(const T& val)
	{
		QueueItem* item = new QueueItem(val);
		_rear->_next = item;
		_rear = item;
	}
	void pop()
	{
		if (empty())
			return;
		QueueItem* first = _front->_next;
		_front->_next = first->_next;
		if (_front->_next == nullptr)
			_rear = _front;
		delete first;
	}
	T front()const
	{
		return _front->_next->_data;
	}
	bool empty()const { return _rear == _front; }
private: 
	//产生一个QueueItem的对象池(n个QueueItem结点）
	struct QueueItem
	{
		QueueItem(T data = T())
			:_data(data)
			, _next(nullptr)
		{ }
		//给QueueItem提供自定义内存管理
		void* operator new(size_t size)
		{
			if (_itemPool == nullptr)
			{
				_itemPool = (QueueItem*)new char[POOL_ITEM_SIZE * sizeof(QueueItem)];
				QueueItem * p = _itemPool;
				for (; p < _itemPool + POOL_ITEM_SIZE1 - 1; ++p)
				{
					p->_next = p + 1;

				}
				p->_next = nullptr;
			}
			QueueItem* p = _itemPool;
			_itemPool = _itemPool->_next;
			return p;
		}
		void operator delete(void* ptr)
		{
			QueueItem* p = (QueueItem*)ptr;
			p->_next = _itemPool;
			_itemPool = p;
		}
		T _data;
		QueueItem* _next;
		static QueueItem* _itemPool;
		static const int POOL_ITEM_SIZE = 100000;
	};
	QueueItem* _front;//指向队头结点
	QueueItem* _rear;//指向队尾结点
};
template<typename T>
typename Queue<T>::QueueItem* Queue<T>::QueueItem::_itemPool = nullptr;
int main()
{
	Queue<int>que;
	for (int i = 0; i < 100000; ++i)
	{
		que.push(i);
		que.pop();
	}
	cout << que.empty() << endl;
	return 0;
}