#include<assert.h>
#include<iostream>
#include<string>
using namespace std;
/*
单向虚幻链表的应用场景：约瑟夫环问题。
约瑟夫环是一个数学的应用问题：已知n个人(以编号1，2，3...n分别表示)围坐在一张圆桌周围，从编号为k的人开始报数，
数到m的那个人出列，它的下一个人又从1开始报数，数到m的那个人出列，一次规律重复下去，直到圆桌周围的人全部出列，
输出人的出列顺序。
*/
//#1:带头节点的单向循环链表解决约瑟夫环的问题
/*
解题思路：
初始时头要指向头(循环)，初始化prev和cur都指向第一个节点；
先让cur指向第k个人，让prev指向cur的前一个结点；
从第k个人开始报数，每次都是报m个数结束的人出列；
循环进行报数，每次报数之前，检查cur一定要指向一个有效的人，不能是头节点;
报数m的过程中，循环次数为m-1，从1开始循环(因为cur已经指向第k个人了）;
然后进行出列，删除cur节点，并更新cur和cur的值，以便下一次报数，当头节点的指针域存储的是自己的地址时，则表示链表为空，说明所有人都出列了，直接return即可;
*/
//结构体实现
#if 0
typedef int SLTDatatype;
typedef struct SListNode
{
	SLTDatatype _data;
	struct  SListNode* _next;
}SListNode;
typedef struct SList
{
	struct SListNode* _head;
}SList;
SListNode* BuySListNode(SList* plist, SLTDatatype x)
{
	SListNode* newnode = new SListNode;
	newnode->_data = x;
	newnode->_next = plist->_head;
	return newnode;
}
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = new SListNode;
	plist->_head->_data = 0;
	plist->_head->_next = plist->_head;
}
void insertTail(SList* plist, int val)
{
	SListNode* last = plist->_head;
	while (last->_next != plist->_head)
		last = last->_next;
	last->_next = BuySListNode(plist, val);
}
void show(SList* plist, int p, int k, int m)
{
	SListNode* prev = plist->_head;
	SListNode* cur = plist->_head->_next;
	//先让cur指向第k个人
	while (k-- > 1)
	{
		prev = cur;
		cur = cur->_next;
	}
	//循环进行报数，然后出列
	for (; p > 0; --p)
	{
		if (plist->_head->_next == plist->_head)
			return;
		//报数之前，检查一个cur,一定要指向一个有效的人
		if (cur == plist->_head)
		{
			prev = cur;
			cur = cur->_next;
		}
		//报数m的过程
		for (int i = 1; i < m; ++i)
		{
			prev = cur;
			cur = cur->_next;
			if (cur == plist->_head)
			{
				prev = cur;
				cur = cur->_next;
			}
		}
		//删除cur节点
		cout << cur->_data << " 出列！" << endl;
		prev->_next = cur->_next;
		cur = cur->_next;
	}
}
void test()
{
	int pnum, knum, mnum;
	cout << "输入人的个数：" << endl;
	cin >> pnum;
	cout << "输入每次开始报数的人的序号：" << endl;
	cin >> knum;
	cout << "输入每次报数的次数：" << endl;
	cin >> mnum;
	SList s1;
	SListInit(&s1);
	for (int i = 1; i <= pnum; ++i)
		insertTail(&s1, i);
	show(&s1, pnum, knum, mnum);
}
int main()
{
	test();
	return 0;
}


//类的实现
class Josephus
{
public:
	Josephus()
	{
		_head = new SListNode(0, nullptr);
		_head->_next = _head;
	}
	void InsertTail(int val)
	{
		SListNode* last = _head;
		while (last->_next != _head)
			last = last->_next;
		last->_next = new SListNode(val, _head);
	}
	void show(int k, int m)
	{
		SListNode* prev = _head;
		SListNode* cur = _head->_next;
		//让cur指向第k个人
		while (k-->1)
		{
			prev = cur;
			cur = cur->_next;
		}
		//循环进行报数，然后出列
		while (_head->_next != _head)
		{
			//报数前，检查cur，cur一定要指向一个有效的人
			if (cur == _head)
			{
				prev = cur;
				cur = cur->_next;
			}
			//报数的过程
			for (int i = 1; i < m; ++i)
			{
				prev = cur;
				cur = cur->_next;
				if (cur == _head)
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			cout << cur->_data << " 出列!" << endl;
			prev->_next = cur->_next;
			cur = prev->_next;
		}
	}
	class SListNode
	{
	public:
		int _data;
		SListNode* _next;
		SListNode(int data, SListNode* next)
			:_data(data)
			, _next(next)
		{ }
	};
	SListNode* _head;
};
void test()
{
	int pnum, knum, mnum;
	cout << "输入人的个数：" << endl;
	cin >> pnum;
	cout << "输入每次开始报数的人的序号：" << endl;
	cin >> knum;
	cout << "输入每次报数的次数：" << endl;
	cin >> mnum;
	Josephus* j = new Josephus();
	for (int i=1; i <= pnum; ++i)
		j->InsertTail(i);
	j->show(knum, mnum);
}
int main()
{
	test();
	return 0;
}

//不带头结点的单向循环链表解决约瑟夫环问题
/*
解题思路：
因为链表不带头了，要判断链表是否为空，如果为空，要生成一个新的节点，并且让新节点的指针域指向自己；
初始化prev指向最后一个节点，cur都指向第一个节点；
先让cur指向第k个人，让prev指向cur的前一个结点；
从第k个人开始报数，每次都是报m个数结束的人出列；
循环进行报数；
报数m的过程中，循环次数为m-1，从1开始循环(因为cur已经指向第k个人了）;
然后进行出列，删除cur节点，并更新prev和cur的值，以便下一次报数，当cur和prev相等时，则表示链表只剩一个节点，说明只剩最后一个人，直接出列，并把链表置为nullptr即可;
*/
class Josephus
{
public:
	Josephus()
	{
		_first = nullptr;
	}
	void InsertTail(int val)
	{
		if (_first == nullptr)
		{
			_first = new SListNode(val, nullptr);
			_first->_next = _first;
		}
		else
		{
			SListNode* last = _first;
			while (last->_next != _first)
				last = last->_next;
			last->_next = new SListNode(val, _first);
		}
	}
	void show(int k, int m)
	{
		SListNode* prev = _first;
		SListNode* cur = _first;
		//因为初始时cur是第一个节点，那么prev就是最后一个节点
		while (prev->_next != _first)
			prev = prev->_next;
		//让cur指向第k个人
		while (k-- > 1)
		{
			prev = cur;
			cur = cur->_next;
		}
		//循环进行报数，然后出列
		while (cur!=prev)//当cur==prev时，表示只剩下最后一个节点
		{
			//报数的过程
			for (int i = 1; i < m; ++i)
			{
				prev = cur;
				cur = cur->_next;
			}
			cout << cur->_data << " 出列!" << endl;
			prev->_next = cur->_next;
			cur = prev->_next;
		}
		cout << cur->_data << " 出列!" << endl;
		_first = nullptr;
	}
	class SListNode
	{
	public:
		int _data;
		SListNode* _next;
		SListNode(int data, SListNode* next)
			:_data(data)
			, _next(next)
		{ }
	};
	SListNode* _first;//指向链表的第一个节点
};
void test()
{
	int pnum, knum, mnum;
	cout << "输入人的个数：" << endl;
	cin >> pnum;
	cout << "输入每次开始报数的人的序号：" << endl;
	cin >> knum;
	cout << "输入每次报数的次数：" << endl;
	cin >> mnum;
	Josephus* j = new Josephus();
	for (int i = 1; i <= pnum; ++i)
		j->InsertTail(i);
	j->show(knum, mnum);
}
int main()
{
	test();
	return 0;
}
#endif