#if 0
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*
========>ֻ���ڶ��ϴ�������:
1.����Ϳ�������˽�л�
2.�ṩһ�����е�static�ӿڴ�������
3.��������ֻ�����������첻ʵ��
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
	//��������ֻ�����������첻ʵ�ֻ���������delete����
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
=======>ֻ��ջ�ϴ�������
��ʽһ��
1.����˽�л�
2.�ṩһ�����е�static�ӿڴ�������
��ʽ����
������operator new����������˽�л�
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
����ģʽ��
======>����ģʽ��
����˵�����㽫���ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������
�����ڵ�һ��ʹ��֮ǰ���Ѿ�����
1.���캯��˽�л�
2.�ṩһ����̬�Ĺ��нӿڷ��ض���
3.Ҫ����һ��static�����Ա
4.��������ֻ�����������첻ʵ��
===>����ģʽ
1.���캯��˽�л�
2.�ṩһ����̬�Ĺ��нӿڷ��ض���
3.Ҫ����һ��staticָ��
4.��������ֻ�����������첻ʵ��
5.�̰߳�ȫ��˫���
*/
//����ģʽ
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
// //ps��ps�ĵ�ַ��һ����
//	Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	return 0;
//}

//����ģʽ��
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
