#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
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
		//构造函数
		iterator(T* ptr = nullptr)
			:_ptr(ptr)
		{ }
		//！=运算符重载
		bool operator!=(const iterator& it)const
		{
			return _ptr != it._ptr;
		}
		//前置++运算符重载
		void operator++()
		{
			_ptr++;
		}
		//*解引用运算符重载
		T& operator*() { return *_ptr; }
		const T& operator*()const { return *_ptr; }
	private:
		T* _ptr;
	};
	//需要给容器提供begin和end方法
	iterator begin() { return iterator(_first); }
	iterator end() { return iterator(_last); }

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
#endif

