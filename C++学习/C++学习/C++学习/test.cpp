#if 0
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*
========>只能在堆上创建对象:
1.构造和拷贝构造私有化
2.提供一个公有的static接口创建对象
3.防拷贝：只声明拷贝构造不实现
*/

class HeapOnly
{
public:
	static HeapOnly* getHeapOnly()
	{
		return new HeapOnly;
	}
private:
	HeapOnly();
	//防拷贝：只声明拷贝构造不实现或者声明成delete函数
	//HeapOnly(const HeapOnly& h) = delete;
	HeapOnly(const HeapOnly& h);
};
int main()
{
	HeapOnly* pa = HeapOnly::getHeapOnly();
	HeapOnly copy(*pa);
	return 0;
}

/*
=======>只在栈上创建对象
方式一：
1.构造私有化
2.提供一个公有的static接口创建对象
方式二：
禁掉其operator new函数，将其私有化
*/
class StackOnly
{
public:
	static StackOnly getStackOnly()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};
class StackOnly1
{
private:
	void* operator new(size_t size);
};
int main()
{
	//StackOnly s = StackOnly::getStackOnly();
	StackOnly1 s;
	//StackOnly1* ps = new  StackOnly1;
	return 0;
}
/*
单例模式：
======>饿汉模式：
就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象
对象在第一次使用之前，已经存在
1.构造函数私有化
2.提供一个静态的公有接口返回对象
3.要定义一个static自身成员
4.防拷贝：只声明拷贝构造不实现
===>懒汉模式
1.构造函数私有化
2.提供一个静态的公有接口返回对象
3.要定义一个static指针
4.防拷贝：只声明拷贝构造不实现
5.线程安全：双检查
*/
//饿汉模式
//class Singleton
//{
//public:
//	static Singleton* getInstance()
//	{
//		return &_instance;
//	}
//private:
//	Singleton()
//	{
//		cout << "Singleton()" << endl;
//	}
//	Singleton(const Singleton& h);
//	static Singleton _instance;
//};
//Singleton Singleton::_instance;
//int main()
//{
// //ps和ps的地址是一样的
//	Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	return 0;
//}

//懒汉模式：
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (_pInstance == nullptr)
		{
			_mtx.lock();
			if (_pInstance == nullptr)
				_pInstance = new Singleton;
			_mtx.unlock();
		}
		return _pInstance;
	}
private:
	Singleton()
	{
		cout << "Singleton" << endl;
	}
	Singleton(const Singleton& h);
	static Singleton* _pInstance;
	static mutex _mtx;
};
Singleton* Singleton::_pInstance = nullptr;
mutex Singleton::_mtx;
int main()
{
	Singleton* ps = Singleton::getInstance();
	Singleton* ps1 = Singleton::getInstance();
	return 0;
}
#endif
