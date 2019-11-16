#include<assert.h>
#include<iostream>
#include<string>
using namespace std;
/*
������������Ӧ�ó�����Լɪ�����⡣
Լɪ����һ����ѧ��Ӧ�����⣺��֪n����(�Ա��1��2��3...n�ֱ��ʾ)Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ������
����m���Ǹ��˳��У�������һ�����ִ�1��ʼ����������m���Ǹ��˳��У�һ�ι����ظ���ȥ��ֱ��Բ����Χ����ȫ�����У�
����˵ĳ���˳��
*/
//#1:��ͷ�ڵ�ĵ���ѭ��������Լɪ�򻷵�����
/*
����˼·��
��ʼʱͷҪָ��ͷ(ѭ��)����ʼ��prev��cur��ָ���һ���ڵ㣻
����curָ���k���ˣ���prevָ��cur��ǰһ����㣻
�ӵ�k���˿�ʼ������ÿ�ζ��Ǳ�m�����������˳��У�
ѭ�����б�����ÿ�α���֮ǰ�����curһ��Ҫָ��һ����Ч���ˣ�������ͷ�ڵ�;
����m�Ĺ����У�ѭ������Ϊm-1����1��ʼѭ��(��Ϊcur�Ѿ�ָ���k�����ˣ�;
Ȼ����г��У�ɾ��cur�ڵ㣬������cur��cur��ֵ���Ա���һ�α�������ͷ�ڵ��ָ����洢�����Լ��ĵ�ַʱ�����ʾ����Ϊ�գ�˵�������˶������ˣ�ֱ��return����;
*/
//�ṹ��ʵ��
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
	//����curָ���k����
	while (k-- > 1)
	{
		prev = cur;
		cur = cur->_next;
	}
	//ѭ�����б�����Ȼ�����
	for (; p > 0; --p)
	{
		if (plist->_head->_next == plist->_head)
			return;
		//����֮ǰ�����һ��cur,һ��Ҫָ��һ����Ч����
		if (cur == plist->_head)
		{
			prev = cur;
			cur = cur->_next;
		}
		//����m�Ĺ���
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
		//ɾ��cur�ڵ�
		cout << cur->_data << " ���У�" << endl;
		prev->_next = cur->_next;
		cur = cur->_next;
	}
}
void test()
{
	int pnum, knum, mnum;
	cout << "�����˵ĸ�����" << endl;
	cin >> pnum;
	cout << "����ÿ�ο�ʼ�������˵���ţ�" << endl;
	cin >> knum;
	cout << "����ÿ�α����Ĵ�����" << endl;
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


//���ʵ��
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
		//��curָ���k����
		while (k-->1)
		{
			prev = cur;
			cur = cur->_next;
		}
		//ѭ�����б�����Ȼ�����
		while (_head->_next != _head)
		{
			//����ǰ�����cur��curһ��Ҫָ��һ����Ч����
			if (cur == _head)
			{
				prev = cur;
				cur = cur->_next;
			}
			//�����Ĺ���
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
			cout << cur->_data << " ����!" << endl;
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
	cout << "�����˵ĸ�����" << endl;
	cin >> pnum;
	cout << "����ÿ�ο�ʼ�������˵���ţ�" << endl;
	cin >> knum;
	cout << "����ÿ�α����Ĵ�����" << endl;
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

//����ͷ���ĵ���ѭ��������Լɪ������
/*
����˼·��
��Ϊ������ͷ�ˣ�Ҫ�ж������Ƿ�Ϊ�գ����Ϊ�գ�Ҫ����һ���µĽڵ㣬�������½ڵ��ָ����ָ���Լ���
��ʼ��prevָ�����һ���ڵ㣬cur��ָ���һ���ڵ㣻
����curָ���k���ˣ���prevָ��cur��ǰһ����㣻
�ӵ�k���˿�ʼ������ÿ�ζ��Ǳ�m�����������˳��У�
ѭ�����б�����
����m�Ĺ����У�ѭ������Ϊm-1����1��ʼѭ��(��Ϊcur�Ѿ�ָ���k�����ˣ�;
Ȼ����г��У�ɾ��cur�ڵ㣬������prev��cur��ֵ���Ա���һ�α�������cur��prev���ʱ�����ʾ����ֻʣһ���ڵ㣬˵��ֻʣ���һ���ˣ�ֱ�ӳ��У�����������Ϊnullptr����;
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
		//��Ϊ��ʼʱcur�ǵ�һ���ڵ㣬��ôprev�������һ���ڵ�
		while (prev->_next != _first)
			prev = prev->_next;
		//��curָ���k����
		while (k-- > 1)
		{
			prev = cur;
			cur = cur->_next;
		}
		//ѭ�����б�����Ȼ�����
		while (cur!=prev)//��cur==prevʱ����ʾֻʣ�����һ���ڵ�
		{
			//�����Ĺ���
			for (int i = 1; i < m; ++i)
			{
				prev = cur;
				cur = cur->_next;
			}
			cout << cur->_data << " ����!" << endl;
			prev->_next = cur->_next;
			cur = prev->_next;
		}
		cout << cur->_data << " ����!" << endl;
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
	SListNode* _first;//ָ������ĵ�һ���ڵ�
};
void test()
{
	int pnum, knum, mnum;
	cout << "�����˵ĸ�����" << endl;
	cin >> pnum;
	cout << "����ÿ�ο�ʼ�������˵���ţ�" << endl;
	cin >> knum;
	cout << "����ÿ�α����Ĵ�����" << endl;
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