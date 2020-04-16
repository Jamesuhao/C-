/*
����ָ�룺��Դ���Զ��ͷ�(����ջ�ϵĶ������������Զ��������ص�)
�������ü���������ָ�룺auto_ptr��scoped_ptr��unique_ptr
�����ü���������ָ�룺shared_ptr��weak_ptr
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<functional>
using namespace std;
#if 0
int main()
{
	//�������ü���������ָ�룺auto_ptr��scoped_ptr��unique_ptr
	/*
	auto_ptr��C++������
	�ײ��ֹǳ�����ķ������ڿ������캯���е���release����
	release������
	_Ty* _Tmp = _Myptr;
	_Myptr    = nullptr;
	return _Tmp;
	��Զ�����һ������ָ�������Դ��ǰ�������ָ�붼���ó���nullptr
	���Ƽ�ʹ��auto_ptr
	�����о�����ʹ��auto_ptr�������ڵ��õ�������������ʱ��ԭ�ȵ�auto_ptr�ײ��ָ���ȫ������Ϊnullptr�ˣ��ڷ���ԭ��������auto_ptrʱ�ͻ����
	auto_ptr<int>ptr1(new int);
	auto_ptr<int>ptr2(ptr1);
	*ptr2 = 20;
	cout << *ptr1 << endl;//ptr1�Ѿ���������


	scoped_prt��C++11
	�ѿ������캯���͸�ֵ��������غ���ֱ��ɾ�����ˣ�
	scoped_ptr<const scoped_ptr<T>&)=delete;
	scoped_ptr<T>& operator=(const scoped_ptr<T>&)=delete;
	ֻ��ʹ�õ����������ʹ�ÿ�������͸�ֵ���������ͻᱨ��


	unique_ptr��
	Ҳ�ǰѿ������캯���͸�ֵ��������غ���ɾ������
	unique_ptr(const unique_ptr<T>&)=delete;
	unique_ptr<T>& operator=(const unique_ptr<T>&)=delete;
	�����ṩ�˽�����ֵ���õĿ������캯���͸�ֵ��������غ���
	unique_ptr<const unique_ptr<T>&&);
	unique_ptr<T>& operator=(const unique_ptr<T>&&);

	˼���⣺�����Ĵ����ܷ����У�
	template<typename T>
	unique_ptr<T> getSmartPtr()
	{
		unique_ptr<T>ptr(new T());
		return ptr;
	}
	unique_ptr<int>ptr1=getSmartPtr<int>();
	������ȫ���Եģ���Ϊunique_ptr�ṩ�˽�����ֵ���õĿ������캯���͸�ֵ��������غ���
	����getSmartPtr<int>()����Ҫ���ÿ������캯������һ����ʱ������Ϊ�����ʱ������һ����ֵ
	������Ѱ�ҵ��ý�����ֵ���õĿ������캯�������û�У��Ż�Ѱ�ҵ�����ͨ�Ŀ������캯��
	unique_ptr<int>p1(new int());
	//unique_ptr<int>p2(p1);�������캯���Ѿ���ɾ��
	//std::move =>c++11 �ƶ����� std::move(p)�õ���ǰ��������ֵ����
	unique_ptr<int>p2(std::move(p1));
	*p1 = 20;
	*/

	//�����ü���������ָ��shared_ptr��weakptr
	/*
	���ü�������ÿһ��������Դ��ƥ��һ�����ü���
	������ָ��������Դ��ʱ�����ü���+1
	������ָ�벻������Դ��ʱ�����ü���-1
	������Ϊ0���Ż��ͷ���Դ
	�����ü���������ָ��ĺô����������ָ����Թ���ͬһ����Դ
	shared_ptr��ǿ����ָ��  ���Ըı���Դ�����ü���
	weak_ptr��������ָ��   ����ı���Դ�����ü���
	������ָ�벻�ṩoperator*()��operator->()��ֻ���𵽹۲���Դ�����ã�����ʹ����Դ
	weak_ptr => shared_ptr =>��Դ(�ڴ�)
	*/

	return 0;
}
#endif

#if 0
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T* ptr = nullptr)
		:mptr(ptr){ }
	~CSmartPtr() { delete mptr; mptr = nullptr; }
	T& operator*() { return *mptr; }
	T* operator->() { return mptr; }
private:
	T* mptr;    //ָ����Դ��ָ��
};
/*
�����⣺
����ָ���ܷ����ڶ��ϣ�
CSmartPtr<int>*p=new CSmartPtr<int>(new int);delete p;
����
*/
int main()
{
	CSmartPtr<int>ptr1(new int);
	*ptr1 = 20;
	class Test
	{
	public:
		void test() { cout << "call Test::test" << endl; }
	};
	CSmartPtr<Test>ptr2(new Test());
	ptr2->test();
	return 0;
}
#endif

//����Դ�������ü�������
#if 0
template<typename T>
class RefCnt
{
public:
	RefCnt(T* ptr = nullptr)
		:mptr(ptr)
		, mcount(0)
	{
		if (mptr != nullptr)
		{
			mcount = 1;
		}
	}
	void addRef()//������Դ�����ü���
	{
		mcount++;
	}
	int deleRef() { return --mcount; }
private:
	T* mptr;
	int mcount;
};
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T* ptr = nullptr)
		:mptr(ptr)
	{
		mpRefCnt = new RefCnt<T>(mptr);
	}
	~CSmartPtr() 
	{ 
		if (0 == mpRefCnt->deleRef())
		{
			delete mptr;
			mptr = nullptr;
		}
	}
	CSmartPtr(const CSmartPtr<T>& src)
		:mptr(src.mptr)
		, mpRefCnt(src.mpRefCnt)
	{
		if (mptr != nullptr)
		{
			mpRefCnt->addRef();
		}
	}
	CSmartPtr<T>& operator=(const CSmartPtr<T>& src)
	{
		if (this == &src)
		{
			return*this;
		}
		if (0 == mpRefCnt->deleRef())
		{
			delete mptr;
		}
		mptr = src.mptr;
		mpRefCnt = src.mpRefCnt;
		mpRefCnt->addRef();
		return *this;
	}

	T& operator*() { return *mptr; }
	T* operator->() { return mptr; }
private:
	T* mptr;    //ָ����Դ��ָ��
	RefCnt<T>* mpRefCnt;//ָ�����Դ�������ü��������ָ��
};
int main()
{
	CSmartPtr<int>ptr1(new int);
	CSmartPtr<int>ptr2(ptr1);
	CSmartPtr<int>ptr3;
	ptr3 = ptr2;
	*ptr1 = 20;
	cout << *ptr2 << " " << *ptr3 << endl;
	return 0;
}
#endif

//ǿ������ָ��ѭ����(��������)�û����ʲô���⣿��ô�����
#if 0
/*
���⣺���new��������Դ�޷��ͷ�
�������������ʱ����ǿ����ָ�룻���ö����ʱ��ʹ��������ָ��
*/
class B;
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl;; }
	void testA() { cout << "�ǳ����õķ���" << endl; }
	//shared_ptr<B>_ptrb;
	weak_ptr<B>_ptrb;
};
class B
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl;; }
	//shared_ptr<A>_ptrb;
	weak_ptr<A>_ptra;
	void func()
	{
		//_ptra->testA();
		//�����Ҫ������Դ�ķ�����
		shared_ptr<A>ps = _ptra.lock();//������������_ptra��������ָ��������ǿ����ָ��
		if (ps != nullptr)
		{
			ps->testA();
		}
	}
};
int main()
{
	shared_ptr<A>pa(new A());
	shared_ptr<B>pb(new B());
	pa->_ptrb = pb;
	pb->_ptra = pa;
	cout << pa.use_count() << endl;
	cout << pb.use_count() << endl;
	pb->func();
	return 0;
}
#endif

//���̷߳��ʹ��������̰߳�ȫ����
#if 0
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	void testA() { cout << "�ǳ����õķ�����" << endl; }
};
//���߳�
/*
void handler01(A *q)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	//q����A�����ʱ����Ҫ�ȹ۲�A�����Ƿ���
	q->testA();
}
*/
void handler02(weak_ptr<A> pw)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	shared_ptr<A>sp = pw.lock();
	if (sp != nullptr)
	{
		sp->testA();
	}
	else
	{
		cout << "A�����Ѿ������������ڷ���" << endl;
	}
}
//main�߳�
int main()
{
	{
		shared_ptr<A> p(new A());
		thread t1(handler02, weak_ptr<A>(p));
		t1.detach();
		std::this_thread::sleep_for(std::chrono::seconds(20));
	}
	std::this_thread::sleep_for(std::chrono::seconds(20));
	//t1.join();//�����ȴ����߳̽���
	return 0;
}
#endif

//����ָ���ɾ���� deletor
#if 0
/*
����ָ�룺�ܹ���֤��Դ���Ե��ͷ�
unique_ptr  shared_ptr
~unique_ptr(){��һ����������ĵ���=>deletor(ptr);}
template<typename T>
class default_delete
{
public:
	void operator()(T*ptr)
	{
		delete ptr;
	}
};
*/
template<typename T>
class MyDeletor
{
public:
	void operator()(T* ptr)const
	{
		cout << "call MyDeletot.operator()" << endl;
		delete[]ptr;
	}
};
template<typename T>
class MyFileDeletor
{
public:
	void operator()(T* ptr)const
	{
		cout << "call MyFileDeletor.operator()" << endl;
		fclose(ptr);
	}
};
int main()
{
	//�Լ���������������
	unique_ptr<int,MyDeletor<int>>ptr1(new int[100]);//delete []ptr;
	unique_ptr<FILE, MyFileDeletor<FILE>>ptr2(fopen("data.txt", "w"));
	
	//����lambda���ʽ =���������� function
	unique_ptr<int, function<void(int*)>>ptr3(new int[100],
		[](int* p)->void {
			cout << "call lambda release new int[100]" << endl;
			delete[]p;
		}
	);
	unique_ptr<FILE, function<void(FILE*)>>ptr4(fopen("data.txt", "w"),
		[](FILE* p)->void {
			cout << "call lambda release new fopen" << endl;
			fclose(p);
		}
	);
	return 0;
}
#endif