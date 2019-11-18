#pragma once
//ListNode节点
template<class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T&value=T())
		:_data(value)
		,_next(nullptr)
		,_prev(nullptr)
	{ }
};

//List迭代器
template<class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr>Self;
	//List迭代器的成员
	pNode _node;
	//构造函数
	ListIterator(pNode node)
		:_node(node)
	{ }
	// *运算符重载
	Ref operator*()
	{
		return _node->_data;
	}
	// -> 运算符重载
	Ptr operator->()
	{
		//return &(_node->_data);
		return &(operator*());
	}
	//前置++运算符重载
	Self operator++()
	{
		_node = _node->_next;
		return *this;
	}
	//后置++运算符重载
	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	//前置--运算符重载
	Self operator--()
	{
		_node = _node->_prev;
		return this;
	}
	//后置--运算符重载
	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
	//!=运算符重载
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	//==运算符重载
	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
};

//List
template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*>iterator;
	typedef ListIterator<const T, const T&, const T*>const_iterator;
	List()
	{
		GreatHead();
	}
	void GreatHead()
	{
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;
	}
	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}
	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}
	void Insert(iterator pos, const T& val)
	{
		pNode cur = pos._node;
		pNode newNode = new Node(val);
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = cur;
		cur->_prev = newNode;
	}
	void PushBack(const T& val)
	{
		Insert(end(), val);
	}
	void PushFront(const T& val)
	{
		Insert(begin(), val);
	}
	iterator Erase(iterator pos)
	{
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			cur = nullptr;
			prev->_next = next;
			next->_prev = prev;
			pos = iterator(next);
		}
		return pos;
	}
	void PopBack()
	{
		Erase(--end());
	}
	void PopFront()
	{
		Erase(begin());
	}
	bool Empty()
	{
		return _head = _head->_next;
	}
	void Clear()
	{
		if (!Empty())
		{
			auto it = begin();
			while (it != end())
			{
				it = Erase(it);
			}
		}
	}
	size_t Size()
	{
		size_t sz = 0;
		for (const auto& e : *this)
		{
			++sz;
		}
		return sz;
	}
	List(const List<T>& lst)
	{
		GreatHead();
		for (const auto& e : lst)
		{
			PushBack(e);
		}
	}
	~List()
	{
		Clear();
		if (_head)
		{
			delete _head;
			_head = nullptr;
		}
	}
	List<T>& operator=(List<T>& lst)
	{
		swap(_head, lst._head);
		return *this;
	}
	template<class InputIterator>
	List(InputIterator first, InputIterator last)
	{
		GreatHead();
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}

private:
	pNode _head;
};
