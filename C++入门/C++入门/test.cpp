#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using  namespace std;

#if 0
/*
=========���βδ�Ĭ��ֵ�ĺ���
1.��Ĭ��ֵ��ʱ����������
2.�������ͨ���ú�������Ч�ʸ��ߣ�����ʱ������movָ��
3�����崦���Ը��β�Ĭ�ϴ�������Ҳ���Ը��β�Ĭ��ֵ����ÿһ���β�ֻ�ܸ�һ��
4.����������ʽҲ�ǿ��Ե�
int sum(int a, int b = 20);
int sum(int a = 20, int b);
*/

int sum(int a = 10, int b = 20)
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = sum(a, b);
	cout << "ret:" << ret << endl;
	//ret = sum(a);
	//cout << "ret:" << ret << endl;
	ret = sum();
	cout << "ret:" << ret << endl;
	return 0;
}


/*
=========��inline�������� �� ��ͨ���������𣿣���
1.inline�����������ڱ�������У���û�к����ĵ��ÿ����ˣ�
2.�ں����ĵ��õ�ֱ�ӰѺ����Ĵ������չ������inline���������ڷ��ű�����������Ӧ�ĺ�������
3.inlineֻ�ǽ������������������������������Ƿ����inline�ɱ���������
4.���ǲ������е�inline��������������������������ݹ�
5.debug�汾�ϣ�inline�ǲ������õģ�inlineֻ����release�汾�²��ܳ���
*/
inline int sum(int a, int b)//��ͨ�������û������Щ��������*.o  sum_int_int   .text
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = sum(a, b);
	//�˴��б�׼�ĺ������ù���  ����ѹջ  ����ջ֡�Ŀ��ٺͻ��˹���
	//�к����ĵ��õĿ���
	cout << "ret:" << ret << endl;
	return 0;
}


/*
=========����������
1.ΪʲôC++֧�ֺ������أ�C���Բ�֧�ֺ������أ�
(1).C++��������������ŵ�ʱ�򣬷������ɺ�����+�����б�������ɵ�
(2).C���Դ�������������ţ��������»���+������
(3).����������C++�������ķ����в����ĸ����Լ�����������������,��c���Բ��������б������޷�����
2.ʲô�Ǻ������أ�����������Ҫע��Щʲô��
(1).һ�麯����������ͬһ�����������к�������ͬ�������б�ĸ����������Ͳ�ͬ���ͳ�Ϊ�������ء�
(2).һ�麯������������ͬ�������б�Ҳ��ͬ�������Ƿ���ֵ��ͬ���ǲ����ɺ������صġ�
3.C++��C����֮����λ�����ã�
C����C++:�޷�ֱ�ӵ���(���ɷ��Ź���ͬ)������취����C++Դ�����������extern"C"�С�
C++����C:�޷�ֱ�ӵ���(���ɷ��Ź���ͬ)������취����C������������extern "C"�С�
#ifdef  __cplusplus
extern "C" {
#endif
	int sum(int a , int b )
	{
		return a + b;
	}
#ifdef  __cplusplus
}
#endif
extern "C"
int sum(int a, int b)
{
	return a + b;
}
4.const����volatile��ʱ������ôӰ���β����͵ģ�
�������⡣
�����⣺�������һ�£�ʲô�Ƕ�̬��
��̬(����ʱ��)�Ķ�̬���������ء�ģ���
��̬(����ʱ��)�Ķ�̬��
*/
bool compare(int a, int b)
{
	cout << "compare_int_int" << endl;
	return a > b;
}
bool compare(double a, double b)
{
	cout << "compare_double_dounle" << endl;
	return a > b;
}
bool compare(const char* a,const char* b)
{
	cout << "compare_char*_char*" << endl;
	return strcmp(a, b) > 0;
}
int main()
{
	compare(10, 20);
	compare(10.0, 20.0);
	compare("aaa", "bbb");
	return 0;
}


/*
==========>const����ָ�����
1.������const��
const���εı������ܹ�����Ϊ��ֵ!!!  ��ʼ����ɺ�ֵ���ܱ��޸�

2.C��C++��const��������ʲô��
(1)C��const���ε��������Բ��ó�ʼ�������ǲ��г���������������,�䲻����Ϊ��ֵ���޸ģ��������ڴ��е�ֵ���Ա��޸ġ�
(2)C++��const�����ʼ��������������
(3)const�ı��뷽ʽ��ͬ��
C�У�const���ǵ���һ����������������ָ��ġ�
C++�У����г���const�����ĵط������������ĳ�ʼ��ֵ�滻���ˣ���ʼ��ֵ����Ϊ��������
(4)�������´���
int b = 20;
const int a = b;
��ʱa�����ǳ������Ѿ��˻��ɳ���������Ϊ��ʼ��ֵ��������������һ��������

3.const���εĳ����������ֵĴ����ǣ�
(1)ֱ���޸ĳ�����ֵ====������������Ϊ��ֵ
(2)����޸ĳ�����ֵ====�����ܰѳ����ĵ�ַй¶��һ����ͨ��ָ�������ͨ�����ñ���

4.const��һ��ָ��Ľ�ϣ�����ָ�����ָ���ڴ��е�ֵ
C++�����Թ淶��cosnt���ε���������������͡�
���䷽����ȥ��const�����ε����ͼ�Ϊ���ܸı�ĳ���
(1)int const *p;\const int *p = &a; ===��*p=20//���� p = &a;//��ȷ
����*p����ָ����ָ�ڴ浥Ԫ�е�ֵ���ܱ��ı䣬��ָ��ָ����Ա��ı�
����������ָ��int���͵��ڴ棬���ǲ���ͨ��ָ�����޸���ָ�ڴ浥Ԫ�е�ֵ
(2)int *const p = &a; ===>p = &b//���� *p = 20;//��ȷ
����p����ָ���ָ���ܱ��޸ģ�����ָ����ָ�ڴ浥Ԫ�е�ֵ���Ա��޸�
�����ָ��p�����ǳ�����������ָ�������ڴ棬���ǿ���ͨ��ָ��������޸�ָ����ָ�ڴ浥Ԫ�е�ֵ
(3)const int *const p = &a; ===>p = &b//���� *p=30;//����
������������Ľ�ϣ�ָ���ָ�����ָ�ڴ浥Ԫ��ֵ�����ܱ��޸�

5.const�Ͷ���ָ��Ľ��
(1)const int* *q;���ε���**q,����*q��q�ǿ��Ըı��
(2)int *cosnt *q;���ε���*q,����**q��q�ǿ��Ըı��
(3)int **const q;���ε���q,����**q��*q�ǿ��Ըı��
6.const��ָ�������ת����ʽ��
int* <= const int*  �Ǵ���ģ�
cosnt int* <=== int*  ����ȷ�ģ�

int ** <= const int**  �Ǵ���ģ�
cosnt int** <= int**  �Ǵ���ģ�

int** <= int* const*  �Ǵ���ģ�
int* cosnt* <= int**  ����ȷ�ģ�
7.���const�ұ�û�н�ָ��*d����cosnt�ǲ��������͵�
int* const p = &a;//int*<===int*  const����ָ��*������������
*/
int main()
{
	int b = 20;
	const int a = b;//��ʱ�Ѿ��˻��ɳ���������Ϊ��ʼ��ֵ��������������һ��������
	const int a= 20;
	
	b = 30;//���󣬱�cosnt���εı���������Ϊ��ֵ
	int arr[b] = {};
	int* p = (int*)&a;//�Ѿ���b�ڴ��е�ֵ�ĵ���
	*p = 30;
	printf("%d %d %d\n", a, *p, *(&a));//�ڱ���׶�const���εı������Ѿ�����ʼ����ֵ�滻��
	
	
	const int a = 10;
	int* p = &a;//���󣬲��ܰѳ����ĵ�ַй¶����ָͨ��
	const int* p = &a;//��ȷ

	int a = 0;
	int* p = &a;
	const int* *q = &p;//����ģ�const int **<===int **
	/*
	const int * *q = &p;
	�����ԭ��
	���const int * *q = &p����ȷ�ģ���
	    *q<=>p; //*q��Ϊp�ĵ�ַ
	��Ϊ*qֻ�ܽ���const int���ͱ����ĵ�ַ��
	�����ж��壺const int b = 20;
	����*q��˵������������const int*����
	��&b������Ҳ��const int*���ͣ����������´���:
		*q = &b <=> p = &b;//���ѳ���b�ĵ�ַ������һ����ָͨ��p��
	����const int* *q=&p�Ǵ����
	*/
	�����޸�Ϊ��
	int a = 0;
	const int* p = &a;
	const int* *q = &p;
	����
	int a = 0;
	int* p = &a;
	const int* const*q = &p;
	return 0;
} 


/*
========��C++������
1.��ֵ���ú���ֵ����
(1)��ֵ����:int&& c = 20;ר������������ֵ���ͣ�ָ���ϣ������Զ�������ʱ����Ȼ��ֱ��������ʱ��c=40;
(2)��ֵ���ñ���������һ����ֵ��ֻ������ֵ������������
(3)������һ����ֵ���ñ���������һ����ֵ

2.������һ�ָ���ȫ��ָ��
3.ָ������õ�����
(1)����ʱ�����ʼ���ģ�ָ����Բ���ʼ��
(2)����һ�����ñ�����һ��ָ�����,����ָ����һģһ���ģ�ͨ��ָ��������޸�ָ��ָ����ڴ��ֵ��ͨ�����ñ����޸��������ڴ��ֵ����ײ�ָ��Ҳ��һģһ����
(3)����ֻ��һ�����ã�û�ж༶���ã�ָ�������һ��ָ�룬Ҳ�����ж༶ָ��
(4)��sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ���(32λƽ̨��ռ 4���ֽ�) ;
(5)�����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ�����ƫ��һ�����͵Ĵ�С; 
(6)����ʵ�巽ʽ��ͬ��ָ����Ҫ��ʽ�����ã����ñ������Լ����� ;
*/
void swap1(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;

}
void swap2(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 10;
	int* p = &a;
	int& b = a;
	*p = 20;
	20 20 20
	cout << a << " " << *p << " " << b << endl;
	b = 30;
	30 30 30
	cout << a << " " << *p << " " << b << endl;
	int a = 10;
	int b = 30;
	swap1(&a, &b);
	cout << "a:" << a << "b:" << b << endl;
	swap2(a, b);
	cout << "a:" << a << "b:" << b << endl;
	int array[5] = {};
	int* p = array;
	����һ�����ñ���������������
	int(&q)[5] = array;
	cout << sizeof(array) << endl;
	cout << sizeof(q) << endl;
	cout << sizeof(p) << endl;
	int a = 10;//aΪ��ֵ����ֵ�����ڴ棬�����֣�ֵ�����޸�
	int& b = a;
	int& c = 20;//����20����ֵ��û�ڴ棬û����
	const int& c = 20;//�����ã�������ֵʱҪ��const��c�����޸�
	C++11�ṩ����ֵ����
	int&& d = 20;//��ֵ����
	d = 30;//d�����޸�
	int& e = d;//һ����ֵ���ñ�����������һ����ֵ
	//��ֵ���úͳ����û��ָ����һ���� 
	return 0;
}


/*
===========��const��һ��ָ�롢���õĽ��Ӧ��
����˼·����const��һ��ָ�롢���ý�ϵı��ʽ��ԭ��ָ��ȥ�ж�
*/
int main()
{
	//дһ����룬���ڴ��0x0018ff44��дһ��4�ֽڵ�10
	int*&& p = (int*)0x0018ff44;
	int* const& p = (int*)0x0018ff44;
	
	int a = 10;
	int* p = &a;
	int*& q = p;
	return 0;
}


/*
======��new��delete
1.new��malloc������
2.delete��free������
new�����������ڴ濪�٣����������ڴ�ĳ�ʼ������
malloc�����ڴ�ʧ�ܣ���ͨ������ֵ��nullptr���Ƚϣ���new�����ڴ�ʧ����ͨ���׳�bad_alloc���͵��쳣���ж�
malloc��free������C�Ŀ⺯��
new��delete���������
3.new�ж�����
int *p1=new int(20);//�׳��쳣��new
int *p2=new (nothrow) int;//���׳��쳣��new
const int *p3=new cosnt int(40);//�ڶ��Ͽ���һ�������ռ䲢��ʼ��Ϊ40
int *p4=new(ĳ��ַ) int(50);��λnew
*/
int main()
{
	int* p = new int(20);//���ٱ���
	delete p;//�ͷ�

	int* q1 = new int[20];//����һ����СΪ20�������飬������ʼ��
	int* q2 = new int[20]();//��һ����СΪ20��������,����ÿһ��Ԫ�س�ʼ��Ϊ0��
	delete[]q1;//�ͷ�
	delete[]q1;//�ͷ�

	//��λnew
	int data = 0;
	int* p4 = new(&data)int(50);
	cout << "data:" << data << endl;
	return 0;
}


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
public://���ⲿ�ṩ���еĳ�Ա������������˽�е�����
	//����Ʒ���ݳ�ʼ����
	void init(const char* name, double price, int amount);
	//��ӡ��Ʒ��Ϣ
	void show();
	//����Ա�����ṩһ��getXXX��setXXX�ķ���  ������ʵ�ֵķ������Զ��������������
	void setName(char* name){strcpy(_name, name);}

	void setPrice(double price){_price = price;}
	void setAmount(int amount){_amount = amount;}

	const char* getName(){return _name;}
	double getPrince(){return _price;}
	int getAmount() {return _amount; }
private://����һ�㶼��˽�еĳ�Ա����
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
���ⶨ���Ա����
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
	good1.init("�յ�",10000.0,50);//���ʵ����
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
	CGoods(const char* n, int a, double p,int y,int m,int d)
		:_date(y,m,d),//CDate _date(y,m,d)
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
	Test(int data = 10):mb(data),ma(mb){}
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

/*
//C++ģ���У����е�ģ���������������ֻ������ߺ����������ŵ�������
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
	cout << "compare<const char*>"<<endl;
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
��ģ�� ==> ʵ���� ==>��ģ��
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
		,_size(size)
	{ }
	~SeqStack()
	{
		delete[]_pstack;
		_pstack = nullptr;
	}
	SeqStack(const SeqStack<T>& stack)
		:_top(stack._top)
		,_size(stack._size)
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
void SeqStack<T>:: push(const T& val)//��ջ����
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
	Queue(int size=10)
		:_pQueue(new T[size])
	    ,_rear(0)
		,_front(0)
		,_size(size)
	{ }
	~Queue()
	{
		delete[]_pQueue;
		_pQueue = nullptr;
	}
	Queue(const Queue<T>& Queue)
		:_front(Queue._front)
		,_rear(Queue._rear)
		,_size(Queue._size)
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
template<typename T,typename Alloc=Allocator<T>>
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
	Test(){ cout << "Test()" << endl;}
	~Test(){ cout << "~Test()" << endl;}
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
		,mimage(m)
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
	in >> src.mreal>> src.mimage;
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
	String(const String &str)
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
	const char* c_str() const  { return _pstr; }
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
	String a1="bbbbb";
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

����������͸���ķ��������ڲ���Ԫ�ص�ֵ��
����������������ײ�����������ʲô���ݽṹ�洢�ģ�����ֻ��Ҫ�����������ݵ���ʼλ�úͽ���λ�ã�Ȼ��Ե��������е������ʼ���

��������ʹ���ڷ����㷨��
1.�����㷨�������յĶ��ǵ�����!
2.�����㷨��һ��ȫ�ֵĺ������Ǹ����е������õ�!
3.�����㷨����һ�׷�ʽ���ܹ�ͳһ�ı������е�������Ԫ�أ�������˵�ķ�������������
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
		iterator(char*p=nullptr)
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
#endif 
