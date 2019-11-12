#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		, _end(nullptr)
		, _eos(nullptr)
	{ }
	void PushBack(const T& val)
	{
		//考虑容量
		if (_end == _eos)
		{
			size_t newC = (_start == nullptr) ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		*_end = val;
		++_end;
	}
	size_t Capacity()
	{
		return (_eos - _start);
	}
	size_t Capacity()const
	{
		return (_eos - _start);
	}
	void Reserve(size_t n)
	{
		int size = Size();
		if (n > Capacity())
		{
			//开空间
			T* tmp = new T[n];
			//拷贝
			//浅拷贝：容易造成二次释放
			//memcpy(tmp, _start, sizeof(T) * size);
			//深拷贝
			for (int i = 0; i < size; ++i)
			{
				tmp[i] = _start[i];//调T类型的赋值运算符重载函数
			}
			//释放
			delete[]_start;
			//更新成员变量的指向
			_start = tmp;
			_end = _start + size;
			_eos = _start + n;
		}
	}
	size_t Size()
	{
		return _end - _start;
	}
	const size_t Size()const
	{
		return _end - _start;
	}
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}
	const T& operator[](size_t pos)const
	{
		assert(pos < Size());
		return _start[pos];
	}
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _end;
	}
	const_iterator begin()const
	{
		return _start;
	}
	const_iterator end()const
	{
		return _end;
	}
	void Insert(iterator pos, const T& val)
	{
		int len = pos - _start;
		assert(pos >= begin() && pos <= end());
		if (_end == _eos)
		{
			size_t newC = (_start == nullptr) ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		pos = _start + len;
		//元素移动
		iterator end = _end;
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_end;
	}
	iterator Erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator begin = pos;
		//元素的移动
		while (begin < _end - 1)
		{
			*begin = *(begin + 1);
			++begin;
		}
		--_end;
		return pos;
	}
	void PopBack()
	{
		Erase(end() - 1);
	}
	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			_end = _start + n;
		}
		else
		{
			if (n > Capacity())
				Reserve(n);
			//赋值：[_end ~ _start+n)
			while (_end != _start + n)
			{
				*_end = val;
				++_end;
			}
		}
	}
	template <typename InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _end(nullptr)
		, _eos(nullptr)
	{
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}
	Vector(const Vector<T>& vec)
		:_start(new T[vec.Size())
		, _end(_start + vec.Size())
		, _eos(_start + vec.Capacity())
	{
		for (int i = 0; i < vec.Size(); ++i)
		{
			_start[i] = _vec[i];
		}
	}
	Vector<T>& operator=(const Vector<T> vec)
	{
		Swap(vec);
		return *this;
	}
	void Swap(Vector < T & vec)
	{
		swap(_start, vec._start);
		swap(_end, vec._end);
		swap(_eos, vec._eos);
	}
	~Vector()
	{
		if (_start)
		{
			delete[]_start;
			_start = _end = _eos = nullptr;
		}
	}
private:
	iterator _start;//指向第一个元素的位置
	iterator _end;//指向最后一个元素的下一个位置
	iterator _eos;//指向所开空间的末尾
};
template<typename T>
void PrintVec(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.Size();++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
template<typename T>
void PrintVecIterator(const Vector<T>& vec)
{
	auto  it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
	}
	cout << endl;
}
void Testvec1()
{
	Vector<int>vec;
	vec.PushBack(1);
	vec.PushBack(2);
	vec.PushBack(3);
	vec.PushBack(4);
	PrintVec(vec);
}
void TestVec2()
{
	Vector<string>vec;
	vec.PushBack("1");
	vec.PushBack("2");
	vec.PushBack("3");
	vec.PushBack("4");
	PrintVecIterator(vec);
}
void TestVec3()
{
	Vector<int>vec;
	vec.PushBack(1);
	vec.PushBack(2);
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(5);
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it % 2 == 0)
		{
			it=vec.Erase(it);
		}
		else
			++it;
	}
}
void TestVec4()
{
	int arr[] = { 1,2,3,4,5,6 };
	Vector<int>vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	string str("abcdefghi");
	Vector<char>vec2(str.begin(), str.end());

	Vector<char>vec3(vec2.begin(), vec2.end());
}
int main()
{
	//Testvec1(); 
	//TestVec2();
	//TestVec3();
	TestVec4();
	return 0;
}