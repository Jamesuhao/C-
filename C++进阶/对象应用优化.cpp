#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//对象的优化
#if 0
//对象背后调用的成员方法：
//示例1：
class Test
{
public:
	Test(int ma=5, int mb=5) :_ma(ma), _mb(mb) { cout << "Test(int,int)" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test& t) :_ma(t._ma), _mb(t._mb) { cout << "Test(const Test&)" << endl; }
	Test& operator=(const Test& src)
	{
		_ma = src._ma;
		_mb = src._mb;
		cout << "operator=" << endl;
		return *this;
	}
private:
	int _ma;
	int _mb;
};
Test t1(10, 10);  //  1. Test(int,int) 
int main()
{
	Test t2(20, 20); //  3.Test(int,int)
	Test t3 = t2;  // 4. Test(const Test&)
	static Test t4 = Test(30, 30);  //5. Test(int,int)
	t2 = Test(40, 40);// 6. Test(int,int)->t2.operator=(Test&)->~Test()
	t2 = (Test)(50, 50);// 7. Test(int,int)->t2.operator(Test&)->~Test()
	t2 = 60;// 8. Test(int,int)->t2.operator=(Test&)->~Test()
	Test* p1 = new Test(70, 70);  //  9. Test(int,int)
	Test* p2 = new Test[2]; // 10. Test(int,int)  Test(int,int)
	Test* p3 = &Test(80, 90);  //  11.Test(int,int)  ~Test()
	const Test& p4 = Test(90, 90); //12. Test(int,int)
	delete p1;//  13.  ~Test()
	delete[]p2;// 14 .~Test() ~Test()
	return 0;
}
Test t5(100, 100);// 2. Test(int,int)
------------------------------------------------------------------
//示例2
class Test
{
public:
	Test(int ma = 10) :_ma(ma) { cout << "Test(int)" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test& t) :_ma(t._ma) { cout << "Test(const Test&)" << endl; }
	Test& operator=(const Test& t)
	{
		cout << "operator=" << endl;
		_ma = t._ma;
		return *this;
	}
private:
	int _ma;
};
int main()
{
	Test t1;
	Test t2(t1);
	Test t3 = t1;
	//Test(20)：显式生成临时对象  生存周期：所在的语句
	/*
	C++编译器对于对象构造的优化：
	用临时对象生成新对象，临时对象就不产生了，直接构造新对象就可以了
	*/
	Test t4 = Test(20);  //  等价于Test t4(20);
	cout << "-------------------------" << endl;

	t4 = t2;   //  t4.operator=(t2)
	//显式生成临时对象
	t4 = Test(30);   //  t4.operator=(const Test &t)
	t4 = (Test)30;  //  int ->Test(int)  t4.operator=(Test(int))
	//隐式式生成临时对象
	t4 = 30; // int ->Test(int)  t4.operator=(Test(int)) 
	cout << "-------------------------" << endl;
	Test* p = &Test(40); //出了这条语句，临时对象就会被析构了，p指向的是一个已经被析构的临时对象
	const Test& ref = Test(50);
	cout << "-------------------------" << endl;

	return 0;
}  
//对象调用函数背后调用的成员方法
//示例1：
class Test
{
public:
	Test(int data = 10) :_ma(data) { cout << "Test(int)" << endl; }
	~Test() { cout << "~Test" << endl; }
	Test(const Test& t) :_ma(t._ma) { cout << "Test(const Test&" << endl; }
	void operator=(const Test& t)
	{
		cout << "operator=" << endl;
		_ma = t._ma;
	}
	int getData()const { return _ma;  }
private:
	int _ma;
};
//此处不能返回局部对象、临时对象的指针或引用
Test GetObject(Test t)//3.Test(const Test&)
{
	int val = t.getData();
	Test tmp(val);//4.Test(int)
	return tmp;//5.Test(const Test&)
}
int main()
{
	Test t1;// 1. Test(int)
	Test t2;// 2. Test(int)
	t2 = GetObject(t1);
	return 0;
}
/*
对象优化的规则：
1.函数参数传递过程中，对象优先用引用传递(少了一次实参 ->形参的拷贝构造的调用与析构)，不要按值传递
2.函数返回对象的时候，应该优先返回一个临时对象，而不要返回一个定义过的对象
3.接收返回值是对象的函数调用的时候，优先按初始化的方式接收，不要按赋值的方式接收(会产生临时量)
*/
class Test
{
public:
	Test(int data = 10) :_ma(data) { cout << "Test(int)" << endl; }
	~Test() { cout << "~Test" << endl; }
	Test(const Test& t) :_ma(t._ma) { cout << "Test(const Test&" << endl; }
	void operator=(const Test& t)
	{
		cout << "operator=" << endl;
		_ma = t._ma;
	}
	int getData()const { return _ma; }
private:
	int _ma;
};
Test GetObject(Test &t)
{
	int val = t.getData();
	return Test(val);//编译器会优化，不会拷贝构造临时对象，而是直接构造一个新对象
}
int main()
{
	Test t1;
	Test t2 = GetObject(t1);//
	return 0;
}
#endif
//回忆右值引用
#if 0
int main()
{
	/*
	左值引用：有内存、有名字
	右值引用：没名字(临时量)、没内存
	1.一个右值引用变量，本身是一个左值。
	2.使用左值引用绑定右值引用。
	*/
	int a = 10;
	int& b = a;  // 左值引用
	//int&& c = a;//无法将左值绑定到右值引用
	//int& c = 20;//不能用左值引用绑定一个右值
	int const& c = 20;
	/*
	为什么使用const修饰就可以解决 不能用左值引用绑定一个右值的问题？
	int tmp=20;//先产生一个临时量
	const int &c = tmp;//然后再把这个临时量绑定到左值引用上
	但是c的值就不能修改了
	*/
	int&& d = 20;//可以把一个右值绑定到一个右值引用上
	/*
	右值引用与上述过程一样，
	int tmp=20;//先产生一个临时量
	const int &c = tmp;//然后再把这个临时量绑定到左值引用上
	但是此时d的值依旧是可以修改的
	*/
	CMyString&& e = CMyString("aaa");//使用右值引用

	//int&& f = d;  //一个右值引用变量，本身是一个左值
	int& f = d;  //使用左值引用绑定右值引用
	return 0;
}
#endif
//CMyString问题 以及优化
#if 0
class CMyString
{
public:
	CMyString(const char* str=nullptr)
	{
		cout << "CMystring(const char*)" << endl;
		if (str != nullptr)
		{
			mptr = new char[strlen(str) + 1];
			strcpy(mptr, str);
		}
		else
		{
			mptr = new char;
			*mptr = '\0';
		}
	}
	~CMyString()
	{
		cout << "~CMyString" << endl;
		delete[]mptr;
		mptr = nullptr;
	}
	//带左值引用参数的拷贝构造
	CMyString(const CMyString& str)
	{
		cout << "CMyString(const CMystring& str)" << endl;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
	}
	//优化
	//带右值引用参数的拷贝构造   str引用的就是一个临时对象
	CMyString(CMyString&& str) 
	{
		cout << "CMyString(CMystring&& str)" << endl;
		mptr = str.mptr;
		str.mptr = nullptr;
	}
	//带左值引用参数的赋值重载函数
	CMyString& operator=(const CMyString& str)
	{
		cout << "CMyString operator=(const CMyString&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
		return *this;
	}
	//带右值引用参数的赋值重载函数  引用的是一个临时对象
	CMyString& operator=(CMyString&& str)
	{
		cout << "CMyString operator=(CMyString&&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		mptr = str.mptr;
		str.mptr = nullptr;
		return *this;
	}
	const char* c_str()const { return mptr; }
private:
	char* mptr;
};
CMyString GetString(CMyString& str)
{
	const char* pstr = str.c_str();
	CMyString tmpStr(pstr);
	return tmpStr;  //产生临时对象，用于拷贝构造main函数栈帧中的临时对象
}
int main()
{
	CMyString str1("aaaaaaaaaaaaaaaaaaaaa");
	CMyString str2;
	str2 = GetString(str1);
	cout << str2.c_str() << endl;
	return 0;
}
/*
输出结果：
优化前：
CMystring(const char*)
CMystring(const char*)
CMystring(const char*)
CMyString(const CMystring& str)===>为main函数栈帧上产生新对象，tmpStr拷贝构造临时对象
~CMyString===>析构tmpStr拷贝构造所产生的临时对象
CMyString operator=(const CMyString&) ===>main函数栈帧上的临时对象给str2赋值
~CMyString===>main函数栈帧上的临时对象
aaaaaaaaaaaaaaaaaaaaa
~CMyString
~CMyString
优化后：
CMystring(const char*)
CMystring(const char*)
CMystring(const char*)
CMyString(CMystring&& str)===>直接调用带有引用的拷贝构造函数，避免内存开辟与释放的操作
~CMyString
CMyString operator=(CMyString&&)===>直接调用带有引用的赋值重载函数，避免内存开辟与释放的操作
~CMyString
aaaaaaaaaaaaaaaaaaaaa
~CMyString
~CMyString
*/
#endif
//CMyString在vector上的应用
class CMyString
{
public:
	CMyString(const char* str = nullptr)
	{
		cout << "CMystring(const char*)" << endl;
		if (str != nullptr)
		{
			mptr = new char[strlen(str) + 1];
			strcpy(mptr, str);
		}
		else
		{
			mptr = new char;
			*mptr = '\0';
		}
	}
	~CMyString()
	{
		cout << "~CMyString" << endl;
		delete[]mptr;
		mptr = nullptr;
	}
	//带左值引用参数的拷贝构造
	CMyString(const CMyString& str)
	{
		cout << "CMyString(const CMystring& str)" << endl;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
	}
	//带右值引用参数的拷贝构造
	CMyString(CMyString&& str)
	{
		cout << "CMyString(CMystring&& str)" << endl;
		mptr = str.mptr;
		str.mptr = nullptr;
	}
	//带左值引用参数的赋值重载函数
	CMyString& operator=(const CMyString& str)
	{
		cout << "CMyString operator=(const CMyString&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
		return *this;
	}
	//带右值引用参数的赋值重载函数  引用的是一个临时对象
	CMyString& operator=(CMyString&& str)
	{
		cout << "CMyString operator=(CMyString&&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		mptr = str.mptr;
		str.mptr = nullptr;
		return *this;
	}
	const char* c_str()const { return mptr; }
private:
	char* mptr;
	friend CMyString operator+(const CMyString& lhs, const CMyString& rhs);
	friend ostream& operator<<(ostream& out, const CMyString& str);
};
CMyString operator+(const CMyString& lhs, const CMyString& rhs)
{
	//char* ptmp = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
	CMyString tmpStr;
	tmpStr.mptr = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
	strcpy(tmpStr.mptr, lhs.mptr);
	strcat(tmpStr.mptr, rhs.mptr);
	//delete[] ptmp;
	return tmpStr;
}
ostream& operator<<(ostream& out, const CMyString& str)
{
	out << str.mptr;
	return out;
}
int main()
{
	/*
	示例1：
	CMyString str1 = "hello";
	CMyString str2 = "world";
	cout << "-----------------------------" << endl;
	CMyString str3 = str1 + str2;
	cout << "-----------------------------" << endl;
	cout<<str3<<endl;
	*/
	CMyString str1 = "aaa";
	vector<CMyString>vec;
	vec.reserve(10);
	cout << "-----------------------------" << endl;
	vec.push_back(str1);//push_back(str1)为什么调用的是带左值引用的拷贝构造函数？
	vec.push_back(CMyString("bbb"));
	cout << "-----------------------------" << endl;
	return 0;
}