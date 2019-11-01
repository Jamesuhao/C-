#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
//#include<vector>
using  namespace std;

#if 0 
/*
C++����������أ�ʹ�������������ֵúͱ�������������һ��
template<typename T>
T sum(T a,T b)
{
	return a+b;  //a.operator+(b)
}
1.�����������������ʱ�򣬻���ö������������غ���(���ȵ��ó�Ա����)��
���û�г�Ա����������ȫ���������Һ��ʵ���������غ���
������
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
	//ָ����������ô��CComplex�����ļӷ�����
	CComplex operator+(const CComplex& src)
	{
		//CComplex comp;
		//comp.mreal = this->mreal + src.mreal;
		//comp.mimage = this->mimage+ src.mimage;
		//return comp;

		//��������ĵ��Ż�
		return CComplex(this->mreal + src.mreal,
			this->mimage + src.mimage);
	}
	CComplex operator++(int)
	{
		//CComplex  ptmp = *this;
		//mreal += 1;
		//mimage += 1;
		//return ptmp;

		//��������ĵ��Ż�
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
	//comp1.operator+(comp2) �ӷ���������غ���
	CComplex comp3 = comp1 + comp2;
	comp3.show();
	CComplex comp4 = comp1 + 20;//comp1.operator+(20) int->CComplex==>CCompelx(int)
	comp4.show();
	//��Ҫ�ṩһ��ȫ�ֵ�+���������  operator+(30,comp1)
	CComplex comp5 = 30 + comp1;
	comp5.show();

	//CCompelx operator++(int)
	comp5 = comp1++;//++ --��Ŀ����� operator++(int)  int��ʾ����++
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
	cout << comp2 << endl; //������Ϣ�����

	return 0;
}

/*
string��

*/
#include<string>
//ģʽʵ��String��
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
	//�ɶ���д
	char& operator[](int index) { return _pstr[index]; }
	//��������ã�ֻ������
	char& operator[](int index)const { return _pstr[index]; }
private:
	char* _pstr;
	friend String operator+(const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);
};
String operator+(const String& lhs, const String& rhs)
{
	//Ч�ʽϵ�
	//char* ptmp = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	//strcpy(ptmp, lhs._pstr);
	//strcat(ptmp,rhs._pstr);
	//String tmp(ptmp);
	//delete[]ptmp;
	//return tmp;

	//�Ż�
	String tmp;
	tmp._pstr = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	strcpy(tmp._pstr, lhs._pstr);
	strcat(tmp._pstr, rhs._pstr);
	return tmp._pstr;
	//���Ż���
	//��������
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
======���ַ�������ĵ�����iteratorʵ��:��������һ��Ƕ��ʹ��
�����������ַ�����
1.begin():���صײ����ݽṹ����Ԫ�صĵ�����
2.end():���صײ����ݽṹ��ĩβԪ�غ��λ�õĵ�����

�������Ĺ��ܣ�
�ṩһ��ͳһ�ķ�ʽ����͸���ı���������
�ɶ���д��һ�ֽṹ

����������͸���ķ��������ڲ���Ԫ�ص�ֵ��
����������������ײ�����������ʲô���ݽṹ�洢�ģ�����ֻ��Ҫ�����������ݵ���ʼλ�úͽ���λ�ã�Ȼ��Ե��������е������ʼ���

��������ʹ���ڷ����㷨��
1.�����㷨�������յĶ��ǵ�����!
2.�����㷨��һ��ȫ�ֵĺ������Ǹ����е������õ�!
3.�����㷨����һ�׷�ʽ���ܹ�ͳһ�ı������е�������Ԫ�أ�������˵�ķ�ʽ����������
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
	//�ɶ���д
	char& operator[](int index) { return _pstr[index]; }
	//��������ã�ֻ������
	char& operator[](int index)const { return _pstr[index]; }

	//��String�ַ��������ṩ��������ʵ��
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
	//begin()���ص��������ײ���Ԫ�صĵ������ı�ʾ
	iterator begin() { return iterator(_pstr); }
	//end()���ص�������ĩβԪ�غ��λ�õĵ������ı�ʾ
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
	String str1 = "hello world!";//str1�������𣿵ײ����һ��char���͵��ַ�
	//�����ĵ���������
	String::iterator it = str1.begin();
	//Ҳ����ʹ��auto�ؼ���������
	//auto it = str1.begin();
	for (; it != str1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//c++11:��foreach�ķ�ʽ�������������ڲ�Ԫ��==>�ײ㻹��ͨ�����������б����ģ�ȥ��begin��end��������޷�������
	for (char ch : str1)
	{
		cout << ch << " ";
	}
	cout << endl;
	return 0;
}
/*
��ģ�� == ��ʵ��һ��C++  STL��һ��˳������ vector�������� + �ռ������� + ������
�����Ŀռ�������allocator��
���ļ��£��ڴ濪�� / �ڴ��ͷ�  ������ / ��������
��������
1.����ʵ�ֵ�����(������һ��ʵ�ֳ�����Ƕ������):class  ��ײ�洢��������ʲô���͵�������˽�г�Ա��Ϊʲô����
2.ʵ������������������begin()��end()
3.ʵ��!=����������ء�ǰ��++����������ء�*�����������������
4.����ʹ��auto�ؼ��ֻ�������::itreator���������ĵ�����
5.����ʱ����ʹ��foreach���߱�׼ѭ��������
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
	void push_back(const T& val)//������ĩβ���Ԫ��
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
		//erase(it)��
		//verify(it._ptr,_last)//����ɾ��λ����ĩβλ���Ƿ���Ч
		//insert(it,val)
		//verify(it._ptr,_last)//���Ӳ���λ����ĩβλ���Ƿ���Ч
		//��齫Ҫɾ����λ��Ԫ���Ƿ���Ч
		verify(_last - 1, _last);
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
	T& operator[](int index)
	{
		if (index < 0 || index >= size())
			throw"OuutOfRangeException";
		return _first[index];
	}
	//������һ��ʵ�ֳ�����Ƕ������
	class iterator
	{
	public:
		friend class vector<T, Alloc>;
		//���캯��
		iterator(vector<T, Alloc>* pvec = nullptr
			, T* ptr = nullptr)
			:_ptr(ptr)
			, _pVec(pvec)
		{
			Iterator_Base* itb =
				new Iterator_Base(this, _pVec->_head._next);
			_pVec->head._next = itb;
		}
		//!=���������
		bool operator!=(const iterator& it)const
		{
			//������������Ч��
			if (_pVec == nullptr || _pVec != it._pVec)
			{
				throw"iterotar incompatable!";
			}
			return _ptr != it._ptr;
		}
		//ǰ��++���������
		void operator++()
		{
			//������������Ч��
			if (_pVec == nullptr)
			{
				throw"iterotar incompatable!";
			}
			_ptr++;
		}
		//*���������������
		T& operator*()
		{
			//������������Ч��
			if (_pVec == nullptr)
			{
				throw"iterotar incompatable!";
			}
			return *_ptr;
		}
		const T& operator*()const
		{
			//������������Ч��
			if (_pVec == nullptr)
			{
				throw"iterotar incompatable!";
			}
			return *_ptr;
		}
	private:
		T* _ptr;
		//��ǰ���������������Ǹ�����
		vector<T, Alloc>* _pVec;
	};
	//��Ҫ�������ṩbegin��end����
	iterator begin() { return iterator(this, _first); }
	iterator end() { return iterator(this, _last); }
	//��������ʧЧ
	void verify(T* first, T* last)
	{
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head.next;
		while (it != nullptr)
		{
			if (it->_cur->_ptr >= first && it->_cur->_ptr <= last)
			{
				//������ʧЧ����iterator���е�����ָ����nullptr
				it->_next->_pVec = nullptr;
				//ɾ����ǰ��������㣬�����жϺ���ĵ���������Ƿ�ʧЧ
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
	//�Զ���vector����insert������ʵ��
	iterator insert(iterator it, const T& v)
	{
		/*
		1.����������
		2.������it._ptr�ĺϷ���
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
	T* _first;//ָ��������ʼ��λ��
	T* _last;//ָ����������ЧԪ�صĺ��λ��
	T* _end;//ָ������ռ�ĺ��λ��
	Alloc _allocator;//���������Ŀռ�����������
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
int main()
{
	vector<int>vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	//���еײ����ݽṹΪ���Ե�ʱ���ſ�ʹ�����ַ�������
	int size = vec.size();
	for (int i = 0; i < size; ++i)
		cout << vec[i] << " ";
	cout << endl;

	//����������  ͨ�õ�
	//Ҳ��д�ɣ�
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
======����������ʧЧ����:ʹ�ÿ��еĵ�������������������
1.������Ϊʲô��ʧЧ��
===>a����һ�ε���erase�Ժ󣬵�������ʧЧ��
������ɾ��������ĳһλ�õ�Ԫ�غ󣬵���������ɾ��λ�õ�������ĩβλ��ȫ��ʧЧ
===>b����һ�ε���insert�󣬵�������ʧЧ��
������Ϊ��������ĳһλ������Ԫ�غ󣬵�������������λ�õ�������ĩβλ��ȫ��ʧЧ
      ��������Ȼ��Ч��     ������ȫ��ʧЧ
��Ԫ��         ��>    �����/ɾ����     ��>ĩβԪ��    
===>c������������Ԫ��ʱ����ҪΪ����������ʱ�����ݺ�ԭ��������ȫ��ʧЧ
������Ϊ���������ݺ󣬾�Ҫ���¿����ڴ������ݣ���ԭ��������ȫ��ʧЧ
        ԭ�����������е�������ȫ��ʧЧ��
��Ԫ��          ��>   �����/ɾ����     ��>ĩβԪ��
===>d����ͬ�����ĵ������ǲ��ܽ��бȽ������

2.������ʧЧ���Ժ��������ô�����
�Բ���/ɾ����ĵ��������и��²���
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
	//����1����vec���������е�ż��ȫ��ɾ��
	auto it = vec.begin();
	//ʧЧ
	for (; it != vec.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			vec.erase(it);
		}
	}
	//�������
	while (it != vec.end())
	{
		//������ʧЧ����1����һ�ε���erase�Ժ󣬵�������ʧЧ��
		if (*it % 2 == 0)
		{
			it = vec.erase(it);//���µ�����
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
	//����2����vec���������е�ż��ǰ�����һ��С��ż��ֵ1������
	auto it = vec.begin();
	for (; it != vec.end(); ++it)
	{
		//������ʧЧ����2���������ڵ�һ�ε���insert�󣬵�������ʧЧ��
		if (*it % 2 == 0)
		{
			//ʧЧ
			//vec.insert(it, *it - 1);
			//������
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
�ڴ�� ���̳� �̳߳� ���ӳ� �����
=======��new��delete����ʵ�ֵĶ����Ӧ��


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
	//����һ��QueueItem�Ķ����(n��QueueItem��㣩
	struct QueueItem
	{
		QueueItem(T data = T())
			:_data(data)
			, _next(nullptr)
		{ }
		//��QueueItem�ṩ�Զ����ڴ����
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
	QueueItem* _front;//ָ���ͷ���
	QueueItem* _rear;//ָ���β���
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