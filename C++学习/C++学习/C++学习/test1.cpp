#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
char* Strstr(char* dest, char* src)
{
	char* pdest = dest;
	char* psrc = src;
	while (*pdest)
	{
		if (*pdest == *psrc)
		{
			char* mdest = pdest;
			char* msrc = psrc;
			while (*mdest && *msrc)
			{
				if (*mdest != *msrc)
					break;
				msrc++;
			}
			if (*msrc == '\0')
			{
				return pdest;
			}
		}
		++pdest;
	}
	return nullptr;
}
class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	//构造
	String(const char* str ="")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	String(const String& str)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}
	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	String& operator=(String  str)
	{
		Swap(str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	//访问
	char& operator[](size_t pos) //非const成员函数  可读可写
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& operator[](size_t pos)const //const成员函数  只读
	{
		assert(pos < _size);
		return _str[pos];
	}
	//迭代器
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	const_iterator begin()const
	{
		return _str;
	}
	const_iterator end()const
	{
		return _str + _size;
	}
	const_iterator cbegin()const//只读
	{
		return _str;
	}
	const_iterator cend()const//只读
	{
		return _str + _size;
	}
	//容量
	size_t Size()const
	{
		return _size;
	}
	const char* c_str()const
	{
		return _str;
	}
	size_t Capacity()const
	{
		return _capacity;
	}
	void resize(size_t sz, char c = '\0')
	{
		//sz>_capacity：增容，内容赋值
		if (sz > _capacity)
		{
			reserve(sz);
		}
		//_size<sz<=_capacity：内容赋值
		if (_size < sz)
		{
			memset(_str + _size, c, sz - _size);
		}
		//sz<=_size
		_size = sz;
		_str[_size] = '\0';
	}
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
		}
	}
	//修改
	void push_back(char c)//尾插一个字符
	{
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newcapacity);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}
	void Append(const char* str)//尾插一个字符串
	{
		int sz = strlen(str);
		if (_size + sz > _capacity)
		{
			reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size = _size + sz;
	}
	String& operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	String& operator+=(const String& str)
	{
		Append(str._str);
		return *this;
	}
	void insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newcapacity);
		}
		size_t end = _size + 1;
		//移动元素   移动终止条件不能写end>=pos 否则会造成头插死循环
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		++_size;
	}
	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int sz = strlen(str);
		if (_size + sz > _capacity)
		{
			reserve(_size + sz);
		}
		size_t end = _size + sz;
		while (end>pos+sz-1)
		{
			_str[end] = _str[end - sz];
			--end;
		}
		int i = 0;
		while (*str != '\0')
		{
			_str[pos + i] = *str++;
			++i;
		}
		_size += sz;
	}
	void erase(size_t pos, int len)
	{
		assert(pos < _size);
		if (pos >= len)
		{
			_size = pos;
			_str[_size] = '\0';
			return;
		}
		size_t start = pos + len;
		while (start <= _size)
		{
			_str[start - len] = _str[start];
			++start;
		}
		_size -= len;
	}
	size_t find(const char* str, size_t pos = 0)
	{
		char* start = strstr(_str + pos, str);
		if (start == nullptr)
			return npos;
		else
			return start - _str;
	}
	size_t find(char ch, size_t pos = 0)
	{
		for (int i = pos; i < _size; ++i)
		{
			if (ch == _str[i])
			{
				return i;
			}
		}
		return npos;
	}
	friend ostream& operator<<(ostream& out, const String& str);
private:
	static const size_t npos;
	char* _str;
	int _size;
	int _capacity;

};
size_t npos = -1;
ostream& operator<<(ostream& out, const String& str)
{
	for (const auto  ch : str)
	{
		cout << ch << " ";
	}
	return out;
}
int main()
{
	String str1 = "abcd\0\0end";
	cout << str1 << endl;
}