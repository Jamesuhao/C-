#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using  namespace std;
/*
==========��C++ OPP�������
C:���ָ����ĺ����Ķ���
C++:��===>ʵ��ĳ�������
ʵ��(���ԡ���Ϊ)--->ADT(������������)
  |                  |
����     <---    (ʵ����)��(����->��Ա����  ��Ϊ->��Ա����)
OOP���Ե��Ĵ�������
����
��װ/���أ�ͨ�������޶���:public,private,protected
�̳�
��̬
*/
const int NAME_LEN = 20;
class CGoods   //==>��Ʒ�ĳ�����������  ���Ͳ�ռ�ռ�   ʵ�����Ķ���ռ�ռ�
{
public:
	//���ⲿ�ṩ���еĳ�Ա������������˽�е�����
	//����Ʒ���ݳ�ʼ����
	void init(const char* name, double price, int amount);
	//��ӡ��Ʒ��Ϣ
	void show();
	//����Ա�����ṩһ��getXXX��setXXX�ķ���  ������ʵ�ֵķ������Զ��������������
	void setName(char* name) { strcpy(_name, name); }

	void setPrice(double price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }

	const char* getName() { return _name; }
	double getPrince() { return _price; }
	int getAmount() { return _amount; }
private:	//����һ�㶼��˽�еĳ�Ա����
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
//���ⶨ���Ա����
void CGoods::init(const char* name, double price, int amount)
{
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
void CGoods::show()
{
	cout << "name:" << _name << endl;
	cout << "price:" << _price << endl;
	cout << "anount:" << _amount << endl;
}
int main()
{
	/*
	�����ʵ��������������
	ÿһ���������Լ��ĳ�Ա����
	�������ǹ���һ�׳�Ա����
	�����ڴ��С��������ڴ�Ĵ�Сֻ�ͳ�Ա�����й�

	=========��thisָ�������
	����show()�����֪�������ĸ�����
	init(name,price,amount)===>��ô֪������Ϣ��ʼ������һ������
	��ĳ�Ա����һ�����룬���еķ��������������һ��thisָ�룬���ܵ��øó�Ա�����Ķ���ĵ�ַ
	thisָ������ã����ֵ��ó�Ա�����Ķ���
	*/
	CGoods good;//���ʵ����
	//ʵ�ʵ�����
	//init(&good1,"���",10.0,200)
	good.init("���", 10.0, 200);
	//show(&good1)
	good.show();

	good.setPrice(20.5);
	good.setAmount(100);
	good.show();

	CGoods good1;
	good1.init("�յ�", 10000.0, 50);//���ʵ����
	good1.show();
	return 0;
}

/*
=======>���캯������������
���ֺ�����һ��������û�з���ֵ
��ͬ�Ķ���
ջ�Ϻ�.data�ε��ڴ�ϵͳ���Զ������������� �ȹ���ĺ������������������
���Ͽ��ٵ��ڴ���Ҫ�ֶ�delete  ϵͳ�����Զ�������������
OOPʵ��һ��˳��ջ
*/
class SeqStack
{
public:
	//���캯��
	SeqStack(int size = 10)//��������һ��������ж�����캯��
	{
		cout << this << " SeqStack()" << endl;//����Ƿ���ù��캯��
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//�Լ���д��ʼ������,��Ҫ��ʽ����
	//void init(int size = 10)
	//{
	//	_pstack = new int[size];
	//	_top = -1;
	//	_size = size;
	//}
	//���������������Լ����ã����ǲ�����
	~SeqStack()//����������ÿһ����ֻ����һ������
	{
		cout << this << " ~SeqStack()" << endl;//����Ƿ������������
		delete[]_pstack;
		_pstack = nullptr;
	}
	//�Լ�д���ͷ���Դ��������Ҫ��ʽ����
	//void release()
	//{
	//	delete[]_pstack;
	//	_pstack = nullptr;
	//}
	void push(int val)
	{
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty()
	{
		return _top == -1;
	}
	bool full()
	{
		return _top == _size - 1;
	}
private:
	int* _pstack;//��̬�������飬�洢˳��ջ��Ԫ��
	int _top;//ָ��ջ��Ԫ�ص�λ��
	int _size;//�������ݺ���ܴ�С
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
SeqStack s2;//��.data����
int main()
{
	//�������
	//1.�����ڴ�
	//2.���ù��캯��
	SeqStack s;//��ջ��
	SeqStack s1(50);//��ջ��
	SeqStack* ps = new SeqStack(60);//�ڶ��Ͽ��٣��ײ�ʵ������malloc�����ڴ棬Ȼ����ö����캯��SeqStack()�������ڴ���Ҫ�����Լ��ֶ��ͷš�
	//s.init(5);//�����Ա��ʼ������
	for (int i = 0; i < 15; i++)
	{
		s.push(rand() % 100);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	//s.release();//�ͷŶ����Ա����ռ�õ��ⲿ���ڴ�(�ⲿ��Դ)
	cout << endl;

	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << endl;
	delete ps;//�ȵ���ps->~SeqStack(),Ȼ��free(ps)
	return 0;//��������ʱ�Զ�������������
}


/*
=========������������ǳ����
ǳ����������Ĭ�ϵĿ������������ڴ�����ݿ�����
�������ռ���ⲿ��Դ����ôǳ������������⣡����
�������캯���ĵ����龰��
1.��һ��������ֵ���ݵķ�ʽ���뺯����ʱ��
2.һ��������ֵ���ݵķ�ʽ�Ӻ�������ʱ��
3.һ���������ڸ�����һ��������г�ʼ��������Ϊ��ֵ��ʼ����ʱ���Զ����á�
*/
class SeqStack
{
public:
	//���캯��
	SeqStack(int size = 10)//��������һ��������ж�����캯��
	{
		cout << this << " SeqStack()" << endl;//����Ƿ���ù��캯��
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	//�Զ��忽�����캯��<=====�����ǳ������������
	SeqStack(const SeqStack& src)
	{
		/*
		ǳ������
		_pstack=src._pastack;
		_top = src._top;
		_size = src._size;
		*/
		//���
		cout << "SeqStack(const SeqStack& src)" << endl;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i)
		{
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	}
	//���������������Լ����ã����ǲ�����
	~SeqStack()//����������ÿһ����ֻ����һ������
	{
		cout << this << " ~SeqStack()" << endl;//����Ƿ������������
		delete[]_pstack;
		_pstack = nullptr;
	}
	//��ֵ���������
	SeqStack& operator=(const SeqStack& src)
	{
		cout << "operator=" << endl;
		//��ֹ�Ը�ֵ
		if (this == &src)
			return *this;
		//��Ҫ���ͷŵ�ǰ����ռ�õ��ⲿ��Դ
		delete[]_pstack;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i)
		{
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
		return *this;
	}
	void push(int val)
	{
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop()
	{
		if (empty())
			return;
		--_top;
	}
	int top()
	{
		return _pstack[_top];
	}
	bool empty()
	{
		return _top == -1;
	}
	bool full()
	{
		return _top == _size - 1;
	}
private:
	int* _pstack;//��̬�������飬�洢˳��ջ��Ԫ��
	int _top;//ָ��ջ��Ԫ�ص�λ��
	int _size;//�������ݺ���ܴ�С
	void resize()
	{
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
int main()
{
	SeqStack s;//û���ṩ�κι��캯����ʱ�򣬱��������Լ�����һ��Ĭ�Ϲ���
	SeqStack s1(10);
	//#1��#2��һ����  ���ǳ�ʼ������  ���õĶ��ǿ������캯�� �����ڴ濽��
	SeqStack s2 = s1;//#1
	//SeqStack s2(s1);//#2

	SeqStack s3;
	//��ֵ��������û�������µĶ���
	//s2.operator=(s1);
	//void operator=(const SeqStack& src)
	s1 = s1;//
	return 0;
}


/*
��������͸�ֵ����ʵ����
1.string����
2.ѭ������Queue
*/
//1.������C/C++��д���������
//��д��String�Ĺ��캯�������������͸�ֵ����
class String
{
public:
	String(const char* str = nullptr);//��ͨ���캯��
	String(const String& other);//�������캯��
	~String();//��������
	String& operator=(const String& other);//��ֵ����
private:
	char* m_data;//���ڱ����ַ���
};
//��ͨ���캯��
String::String(const char* str)
{
	if (str != nullptr)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}
//�������캯��
String::String(const String& other)
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}
//��������
String::~String()
{
	delete[]m_data;
	m_data = nullptr;
}
//��ֵ����:����String&��Ϊ��֧��������ֵ����
String& String::operator=(const String& other)
{
	//1.��ֹ�Ը�ֵ
	if (this == &other)
		return *this;
	//2.�ͷŵ�ǰ����ռ�õ��ⲿ��Դ
	delete[]m_data;
	//3.�����µ���Դ�����Ҹ�������
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	//���ر����������
	return *this;
}
int main()
{
	//���ô�const char*�����Ĺ��캯��
	String str1;
	String str2("hello");
	String str3 = "world";
	//���ÿ������캯��
	String str4 = str3;
	String str5(str3);
	//���ø�ֵ���غ���
	str3 = str1 = str2;
	return 0;
}

//2.ѭ������
class Queue
{
public:
	Queue(int size = 20)
	{
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}
	Queue(const Queue& src)
	{
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
	}
	Queue& operator=(const Queue& src)
	{
		//1.����Ը�ֵ
		if (this == &src)
			return *this;
		//2.�ͷ�ԭ�пռ�
		delete[]_pQue;
		//3.���ٿռ䲢���и�ֵ
		_size = src._size;
		_front = src._front;
		_rear = src._rear;
		_pQue = new int[_size];
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			_pQue[i] = src._pQue[i];
		}
		//4.���ر����������
		return *this;
	}
	~Queue()
	{
		delete[]_pQue;
		_pQue = nullptr;
	}
	void push(int val)//���
	{
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	void pop()//����
	{
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}
	int front()//��ȡ��ͷԪ��
	{
		return _pQue[_front];
	}
	bool full()
	{
		return (_rear + 1) % _size == _front;
	}
	bool empty()
	{
		return _front == _rear;
	}
private:
	int* _pQue;//������е�����ռ�
	int _front;//��ͷ
	int _rear;//��β
	int _size;//�������ݵ��ܴ�С

	void resize()
	{
		int* ptmp = new int[2 * _size];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size)
		{
			ptmp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};
int main()
{
	Queue queue;
	for (int i = 0; i < 20; ++i)
	{
		queue.push(rand() % 100);
	}
	while (!queue.empty())
	{
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;
	Queue queue1 = queue;
	Queue queue2;
	queue2 = queue1;

	return 0;
}

/*
========�����캯���ĳ�ʼ���б�:����ָ����ǰ�����Ա�����ĳ�ʼ����ʽ
CDate��Ϣ��CGoods��Ʒ����Ϣ��һ����
*/
class CDate
{
public:
	CDate(int y, int m, int d)//�Զ�����һ�����캯������ʱ�������Ͳ����Զ�����Ĭ�Ϲ��캯��
	{
		_year = y;
		_month = m;
		_day = d;
	}
	void show()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class CGoods
{
public:
	CGoods(const char* n, int a, double p, int y, int m, int d)
		:_date(y, m, d),//CDate _date(y,m,d)
		_amount(a),//�൱��int amount = a;
		_price(p)//#1���캯���ĳ�ʼ���б�
	{
		//#2��ǰ�����͹��캯����
		strcpy(_name, n);
		_amount = a;//�൱��int _amount;_amount=a;
	}
	void show()
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;//��Ա����  �������ɣ�1.�����ڴ�2.���ù��캯��
};
int  main()
{
	CGoods good("��Ʒ", 100, 35.0, 2019, 5, 12);
	good.show();
	return 0;
}


class Test
{
public:
	Test(int data = 10) :mb(data), ma(mb) {}
	void show()
	{
		cout << "ma:" << ma << " mb:" << mb << endl;
	}
private:
	//��Ա�����ĳ�ʼ�������Ƕ����˳���йأ��͹��캯����ʼ���б��г��ֵ��Ⱥ�˳���޹ء�
	//int ma;//��ʱma���ᱻ��ʼ��Ϊ0xCCCCCCCC����Ϊ��Windows VS�»�����ٵ�ջ֡��ʼ��Ϊ0xCCCCCCCC����-858993460
	int mb;//mb=10
	int ma;//ma=10
};
int main()
{
	Test t;
	t.show();
	return 0;
}



/*
======>��ĸ��ֳ�Ա--->��Ա����/����
��ͨ��Ա������=======>�����������һ��this�βα���
1.�������������
2.���ø÷���ʱ����Ҫ����һ������(���������޷����õ� ʵ�Σ�cosnt CGoods*   �βΣ�CGoods *this
3.����������ʶ����˽�г�Ա����

static��̬��Ա������=====>��������this�β�,�������ж��������Ϣ
1.�������������
2.��������������������
3.����������ʶ����˽�г�Ա�������ڲ���������ĳ�Ա(ֻ�ܵ���������static��̬��Ա)

const����Ա������=======>const CGoods* this
1.�������������
2.����������һ��������ͨ������߶��󶼿���
3.����������ʶ����˽�г�Ա����ֻ�ܶ�������д
*/
class CDate
{
public:
	CDate(int y, int m, int d)
	{
		_year = y;
		_month = m;
		_day = d;
	}

	void show()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class CGoods
{
public:
	CGoods(const char* n, int a, double p, int y, int m, int d)
		:_date(y, m, d)
		, _amount(a)
		, _price(p)
	{
		strcpy(_name, n);
		_count++;
	}
	//��ͨ�ĳ�Ա����
	void show()//��ӡ��Ʒ��˽����Ϣ
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}

	//��̬�ĳ�Ա������û��thisָ��
	static void showCGoodCount()//��ӡ������Ʒ�������Ϣ
	{
		cout << "������Ʒ�����������ǣ�" << _count << endl;
	}

	//����Ա����  ֻҪ��ֻ�������ĳ�Ա������һ��ʵ�ֳ�const����Ա����
	void show()const//��ӡ��Ʒ��˽����Ϣ
	{
		cout << "name:" << _name << endl;
		cout << "amount:" << _amount << endl;
		cout << "price:" << _price << endl;
		_date.show();
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;
	//static����ı��������ڶ���,���������༶���
	static int _count;//������������¼��Ʒ�����������
};
//static��Ա����һ��Ҫ��������ж��岢��ʼ��
int CGoods::_count = 0;
int main()
{
	CGoods good1("��Ʒ1", 100, 35.0, 2019, 5, 12);
	good1.show();

	CGoods good2("��Ʒ2", 100, 35.0, 2019, 5, 12);
	good2.show();

	CGoods good3("��Ʒ3", 100, 35.0, 2019, 5, 12);
	good3.show();

	CGoods good4("��Ʒ4", 100, 35.0, 2019, 5, 12);
	good4.show();

	//ͳ��������Ʒ��������
	CGoods::showCGoodCount();

	const CGoods good5("������Ʒ5", 100, 35.0, 2019, 5, 12);
	good5.show();//CGoods::show(&good5)  const CGoods*   -->const CGoods  *this

	return 0;
}


/*
========��ָ�����Ա(��Ա�����ͳ�Ա����)��ָ��
1.ָ���Ա������ָ��
ͨ������ȥ����
2.ָ����ͨ��Ա������ָ��
Ҳ��Ҫ�����ڶ������
3.ָ��static��Ա������static��Ա������ָ��
����Ҫ�����ڶ���ֱ�ӿ��Է���
����Ҫͨ������
*/
class Test
{
public:
	void func()
	{
		cout << "call Test :: func" << endl;
	}
	static void static_func()
	{
		cout << "Test :: static_func" << endl;
	}
	int ma;
	static int mb;
};
int Test::mb;
int main()
{
	Test t1;
	Test* t2 = new Test();
	//ָ���Ա������ָ��
	int Test::* p1 = &Test::ma;
	t1.*p1 = 20;
	cout << t1.*p1 << endl;
	t2->ma = 30;
	cout << t2->ma << endl;

	//ָ��static��̬��Ա������ָ��
	int* p2 = &Test::mb;
	*p2 = 40;
	cout << *p2 << endl;

	//ָ���Ա������ָ��
	//Ҳ��Ҫ�����ڶ����
	void (Test:: * pfunc)() = &Test::func;
	(t1.*pfunc)();
	(t2->*pfunc)();

	//ָ�����static��Ա������ָ�룺
	void(*pfunc1)() = &Test::static_func;
	(*pfunc1)();

	delete t2;
	return 0;
}
#endif