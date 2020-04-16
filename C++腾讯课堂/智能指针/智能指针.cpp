/*
智能指针：资源的自动释放(利用栈上的对象出作用域会自动析构的特点)
不带引用计数的智能指针：auto_ptr，scoped_ptr，unique_ptr
带引用计数的智能指针：shared_ptr，weak_ptr
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<thread>
#include<functional>
using namespace std;
#if 0
int main()
{
	//不带引用计数的智能指针：auto_ptr、scoped_ptr、unique_ptr
	/*
	auto_ptr：C++库里面
	底层防止浅拷贝的方法：在拷贝构造函数中调用release方法
	release方法：
	_Ty* _Tmp = _Myptr;
	_Myptr    = nullptr;
	return _Tmp;
	永远让最后一个智能指针管理资源，前面的智能指针都被置成了nullptr
	不推荐使用auto_ptr
	容器中尽量不使用auto_ptr，否则在调用的容器拷贝构造时，原先的auto_ptr底层的指针就全部被置为nullptr了，在访问原先容器的auto_ptr时就会出错。
	auto_ptr<int>ptr1(new int);
	auto_ptr<int>ptr2(ptr1);
	*ptr2 = 20;
	cout << *ptr1 << endl;//ptr1已经不存在了


	scoped_prt：C++11
	把拷贝构造函数和赋值运算符重载函数直接删除掉了：
	scoped_ptr<const scoped_ptr<T>&)=delete;
	scoped_ptr<T>& operator=(const scoped_ptr<T>&)=delete;
	只能使用单个对象，如果使用拷贝构造和赋值，编译器就会报错


	unique_ptr：
	也是把拷贝构造函数和赋值运算符重载函数删除掉了
	unique_ptr(const unique_ptr<T>&)=delete;
	unique_ptr<T>& operator=(const unique_ptr<T>&)=delete;
	但是提供了接收右值引用的拷贝构造函数和赋值运算符重载函数
	unique_ptr<const unique_ptr<T>&&);
	unique_ptr<T>& operator=(const unique_ptr<T>&&);

	思考题：这样的代码能否运行？
	template<typename T>
	unique_ptr<T> getSmartPtr()
	{
		unique_ptr<T>ptr(new T());
		return ptr;
	}
	unique_ptr<int>ptr1=getSmartPtr<int>();
	答案是完全可以的，因为unique_ptr提供了接收右值引用的拷贝构造函数和赋值运算符重载函数
	调用getSmartPtr<int>()后，需要调用拷贝构造函数产生一个临时对象，因为这个临时对象是一个右值
	会优先寻找调用接收右值引用的拷贝构造函数，如果没有，才会寻找调用普通的拷贝构造函数
	unique_ptr<int>p1(new int());
	//unique_ptr<int>p2(p1);拷贝构造函数已经被删除
	//std::move =>c++11 移动语义 std::move(p)得到当前变量的右值类型
	unique_ptr<int>p2(std::move(p1));
	*p1 = 20;
	*/

	//带引用计数的智能指针shared_ptr、weakptr
	/*
	引用计数：给每一个对象资源，匹配一个引用计数
	当智能指针引用资源的时候，引用计数+1
	当智能指针不引用资源的时候，引用计数-1
	当计数为0，才会释放资源
	带引用计数的智能指针的好处：多个智能指针可以管理同一个资源
	shared_ptr：强智能指针  可以改变资源的引用计数
	weak_ptr：弱智能指针   不会改变资源的引用计数
	弱智能指针不提供operator*()和operator->()，只能起到观察资源的作用，不能使用资源
	weak_ptr => shared_ptr =>资源(内存)
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
	T* mptr;    //指向资源的指针
};
/*
面试题：
智能指针能否定义在堆上？
CSmartPtr<int>*p=new CSmartPtr<int>(new int);delete p;
不能
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

//对资源进行引用计数的类
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
	void addRef()//增加资源的引用计数
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
	T* mptr;    //指向资源的指针
	RefCnt<T>* mpRefCnt;//指向对资源进行引用计数对象的指针
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

//强弱智能指针循环引(交叉引用)用会造成什么问题？怎么解决？
#if 0
/*
问题：造成new出来的资源无法释放
解决：定义对象的时候，用强智能指针；引用对象的时候，使用弱智能指针
*/
class B;
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl;; }
	void testA() { cout << "非常好用的方法" << endl; }
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
		//如果需要调用资源的方法：
		shared_ptr<A>ps = _ptra.lock();//提升方法，把_ptra由弱智能指针提升到强智能指针
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

//多线程访问共享对象的线程安全问题
#if 0
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	void testA() { cout << "非常好用的方法！" << endl; }
};
//子线程
/*
void handler01(A *q)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	//q访问A对象的时候，需要先观察A对象是否存货
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
		cout << "A对象已经析构，不能在访问" << endl;
	}
}
//main线程
int main()
{
	{
		shared_ptr<A> p(new A());
		thread t1(handler02, weak_ptr<A>(p));
		t1.detach();
		std::this_thread::sleep_for(std::chrono::seconds(20));
	}
	std::this_thread::sleep_for(std::chrono::seconds(20));
	//t1.join();//阻塞等待子线程结束
	return 0;
}
#endif

//智能指针的删除器 deletor
#if 0
/*
智能指针：能够保证资源绝对的释放
unique_ptr  shared_ptr
~unique_ptr(){是一个函数对象的调用=>deletor(ptr);}
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
	//自己定义析构函数类
	unique_ptr<int,MyDeletor<int>>ptr1(new int[100]);//delete []ptr;
	unique_ptr<FILE, MyFileDeletor<FILE>>ptr2(fopen("data.txt", "w"));
	
	//采用lambda表达式 =》函数对象 function
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