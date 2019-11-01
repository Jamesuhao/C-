#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using  namespace std;

/*
C++ģ���У����е�ģ���������������ֻ������ߺ����������ŵ�������
====��C++����ģ��
ģ������壺������Ҳ���Խ��в�������
����ԭ�ͣ�int sum(int a,int b){ return a+b; }
����ص㣺
==>����ģ��:�ǲ����б���ģ���Ϊ���ͻ���֪��
==>ģ���ʵ����:�������õ����ʵ����
ģ���ʵ����������ģ�庯��
�ں������õ㣬���������û�ָ�������ͣ���ԭģ��ʵ����һ�ݺ����������
һ�ֲ�������ֻʵ����һ�Σ�����ֱ��ʹ��ʵ�������ģ�庯�����뼴��
==>ģ�庯��:����Ҫ���������������

==>ģ�����Ͳ���:��typename/class���ж��壬һ�����typename

==>ģ���ʵ������:���Ը����û������ʵ�����ͣ����Ƶ���ģ�����Ͳ����ľ�������
==>ģ������л�(ר�û�):����(���Ǳ������ṩ�ģ������û��ṩ��)��ʵ������

==>����ģ�塢ģ�������������ģ�庯�������ع�ϵ

ע�⣺
����ģ�岻����һ���ļ��ж��壬������һ���ļ���ʹ�õģ���Ϊ�ں���ģ���ǲ����б���ģ�������ʱʹ���ļ�������*UND*���ţ�ȴ�Ҳ����䶨��
ģ��������֮ǰ��һ��Ҫ����ģ�嶨��ĵط��������Ļ���ģ����ܽ���������ʵ�����������ܹ�������������Ĵ���
���ԣ�ģ����붼�Ƿ���ͷ�ļ����еģ�Ȼ����Դ�ļ���ֱ��#include����

����������ļ��ж���Ľ���취�����߱��������ڵ����ļ��н���ָ�����͵�ģ��ʵ����
ʾ��:
tmplate bool compare<int>(int,int);
tmplate bool compare<double>(double,double);
ֻ���˽⣬����������ȥ��
*/
//����ģ��
template<typename T>//����һ��ģ������б�
bool compare(T a, T b)//compare��һ������ģ�壬����ģ�����ǲ����б����
{
	cout << "compare template" << endl;
	return a > b;
}
//���compare����ģ�壬�ṩconst char*���͵��������汾
template<>
bool compare<const char*>(const char* a, const char* b)
{
	cout << "compare<const char*>" << endl;
	return strcmp(a, b) > 0;
}
//��ģ�庯�� - ��ͨ����
bool compare(const char* a, const char* b)
{
	cout << "normal compare" << endl;
	return strcmp(a, b) > 0;
}
int main()
{
	//�����ĵ��õ�:Ҫ����ģ���ʵ����
	//ģ����+�����б�==>�Ӻ���ģ��ʵ����һ�ݺ�������
	compare<int>(10, 20);
	//bool compare<int>(int a,int b)
	//{
	//		return a>b;
	//}

	compare<double>(10.5, 20.5);//�����ĵ��õ�
	//bool compare<double>(double a, double b)
	//{
	//	return a > b;
	//}

	//��δָ�����ͣ�����к���ģ��ʵ������
	//T: int 
	compare(20, 30);
	//compare<int>(30, 40.5);//�Ὣdouble����ǿתΪint����

	//����ģ��ʵ������ T:cosnt char *
	//����ĳЩ������˵������������Ĭ��ʵ������ģ����룬���봦���߼��Ǵ����
	//������Ҫ����ģ���������
	compare<const char*>("aaa", "bbb");//���ú���ģ��ʵ����ģ�庯��
	//bool compare<const char*>(const char* a, const char* b)
	//{
	//	return a > b;
	//}
	compare("aaa", "bbb");//���������Ȱ�compare����ɺ������֣�û����ͨ����ʱ����ȥ��compareģ��

	return 0;
}

/*
==>ģ������Ͳ���:
��������������(�������ߵ�ַ/���ö�����)�����ǳ�����ֻ��ʹ�ã��������޸�
*/
template<typename T, int SIZE>//������int SIZE����һ�������Ͳ�����ֻ�ܴ�����
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
	sort<int, size>(arr);//����ģ���ʵ����
	for (int val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

/*
=========�������ģ��
��ģ�� ==> ʵ���� ==>ģ����
������Ĭ�ϵ����Ͳ���
*/
//��ģ��
template<typename T>
//template<typename T=int> //��Ĭ�����Ͳ�������ģ��
//ʵ����ʱ���Բ�����������
class SeqStack//ģ������
{
public:
	//ģ����+���Ͳ����б�====��������
	//��ģ���У����캯����������������ʡ�������Ͳ����б�
	//��������ģ��ĵط����������Ͳ����б�
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
		//��Ҫ��memcopy���п������ᷢ��ǳ����
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
	T top()const//����ֻ�������ӿڣ�����дΪconst��Ա����Ϊconst��Ա�������ܷ�����ͨ��Ա����������const��Ա������ͨ��Ա�������Է���
	{
		if (empty())
			throw "stack is empty!";//�׳��쳣Ҳ�������߼�����
		return _pstack[_top - 1];
	}
	bool full()const { return _top == _size; }//ջ��
	bool empty()const { return _top == 0; }//ջ��
private:
	T* _pstack;
	int _top;
	int _size;

	//˳��ջ����ײ㰴2���ķ�ʽ����
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
template<typename T>//��һ�������������������Ҫ���¶���
void SeqStack<T>::push(const T& val)//��ջ����
{
	if (full())
		expand();
	_pstack[_top++] = val;
}
int main()
{
	//��ģ��ѡ����ʵ������Ҫ��ʲôʵ����ʲô
	//ʵ�����������ģ����
	//����class SeqStack<int>{ };
	SeqStack<int>s1;
	s1.push(20);
	s1.push(78);
	s1.push(32);
	s1.push(15);
	s1.pop();
	cout << s1.top() << endl;
	return 0;
}

//ʹ����ģ��дѭ������
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
��ģ��==��ʵ��һ��C++  STL��һ��˳������ vector��������+�ռ�������
�����Ŀռ�������allocator��
���ļ��£��ڴ濪��/�ڴ��ͷ�  ������/��������

*/
//���������Ŀռ�����������C++��׼���allocatorʵ��һ��
template<typename T>
struct Allocator
{
	T* allocate(size_t size)//�����ڴ濪��
	{
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p)//�����ڴ��ͷ�
	{
		free(p);
	}
	void construct(T* p, const T& val)//���������
	{
		new (p) T(val);//��λnew
	}
	void destory(T* p)//�����������
	{
		p->~T();//~T������T���͵���������
	}
};
/*
�����ײ��ڴ濪�٣��ڴ��ͷţ��������������ͨ��allocator�ռ�������ʵ��
*/
template<typename T, typename Alloc = Allocator<T>>
class vector
{
public:
	vector(int size = 10)
		//:_allocator(alloc);
	{
		//��Ҫ���ڴ濪�ٺͶ�����ֿ�����
		//_first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		//����������Ч��Ԫ�أ�Ȼ���ͷ�_firstָ��Ķ��ڴ�
		//delete[]_first;
		for (T* p = _first; p != _last; ++p)//��_firstָ��ָ����������ЧԪ�ؽ�����������
		{
			_allocator.destory(p);
		}
		_allocator.deallocate(_first);//�ͷŶ��ϵ������ڴ�
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
	void push_back(const T& val)//������ĩβ��Ӳ���
	{
		if (full())
			expand();
		//*_last++ = val;
		//_lastָ��ָ����ڴ湹��һ��ֵΪval�Ķ���
		_allocator.construct(_last, val);
		_last++;
	}
	void pop_back()//��ĩβɾ��Ԫ��
	{
		if (empty())
			return;
		//--_last;
		//����Ҫ��_lastָ��--������Ҫ����ɾ����Ԫ��
		--_last;
		_allocator.destory(_last);
	}
	T back()const//�����������һ����ЧԪ�ص�ֵ
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _last == _first; }
	int size()const { return _last - _first; }
private:
	T* _first;//ָ��������ʼ��λ��
	T* _last;//ָ����������ЧԪ�صĺ��λ��
	T* _end;//ָ������ռ�ĺ��λ��
	Alloc _allocator;//���������Ŀռ�����������
	void expand()//�����Ķ������ݲ���
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
	vec.pop_back();//ֻ��Ҫ��������Ҫ�Ѷ�����������ڴ���ͷŷֿ�
	cout << "------------------------------" << endl;
	return 0;
}
#endif

