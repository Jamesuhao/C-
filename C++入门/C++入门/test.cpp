#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
using  namespace std;
/*
=========���βδ�Ĭ��ֵ�ĺ���
1.��Ĭ��ֵ��ʱ����������
2.�������ͨ���ú�������Ч�ʸ��ߣ�����ʱ������movָ��
3�����崦���Ը��β�Ĭ�ϴ�������Ҳ���Ը��β�Ĭ��ֵ����ÿһ���β�ֻ�ܸ�һ��
4.����������ʽҲ�ǿ��Ե�
int sum(int a, int b = 20);
int sum(int a = 20, int b);
*/

//int sum(int a = 10, int b = 20)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = sum(a, b);
//	cout << "ret:" << ret << endl;
//	//ret = sum(a);
//	//cout << "ret:" << ret << endl;
//	ret = sum();
//	cout << "ret:" << ret << endl;
//	return 0;
//}


/*
=========��inline�������� �� ��ͨ���������𣿣���
1.inline�����������ڱ�������У���û�к����ĵ��ÿ����ˣ�
2.�ں����ĵ��õ�ֱ�ӰѺ����Ĵ������չ������inline���������ڷ��ű�����������Ӧ�ĺ�������
3.inlineֻ�ǽ������������������������������Ƿ����inline�ɱ���������
4.���ǲ������е�inline��������������������������ݹ�
5.debug�汾�ϣ�inline�ǲ������õģ�inlineֻ����release�汾�²��ܳ���
*/
//inline int sum(int a, int b)//��ͨ�������û������Щ��������*.o  sum_int_int   .text
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = sum(a, b);
//	//�˴��б�׼�ĺ������ù���  ����ѹջ  ����ջ֡�Ŀ��ٺͻ��˹���
//	//�к����ĵ��õĿ���
//	cout << "ret:" << ret << endl;
//	return 0;
//}


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
//bool compare(int a, int b)
//{
//	cout << "compare_int_int" << endl;
//	return a > b;
//}
//bool compare(double a, double b)
//{
//	cout << "compare_double_dounle" << endl;
//	return a > b;
//}
//bool compare(const char* a,const char* b)
//{
//	cout << "compare_char*_char*" << endl;
//	return strcmp(a, b) > 0;
//}
//int main()
//{
//	compare(10, 20);
//	compare(10.0, 20.0);
//	compare("aaa", "bbb");
//	return 0;
//}


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
//int main()
//{
	//int b = 20;
	//const int a = b;//��ʱ�Ѿ��˻��ɳ���������Ϊ��ʼ��ֵ��������������һ��������
	//const int a= 20;
	
	//b = 30;//���󣬱�cosnt���εı���������Ϊ��ֵ
	//int arr[b] = {};
	//int* p = (int*)&a;//�Ѿ���b�ڴ��е�ֵ�ĵ���
	//*p = 30;
	//printf("%d %d %d\n", a, *p, *(&a));//�ڱ���׶�const���εı������Ѿ�����ʼ����ֵ�滻��
	
	
	//const int a = 10;
	//int* p = &a;//���󣬲��ܰѳ����ĵ�ַй¶����ָͨ��
	//const int* p = &a;//��ȷ

	//int a = 0;
	//int* p = &a;
	//const int* *q = &p;//����ģ�const int **<===int **
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
	//�����޸�Ϊ��
	//int a = 0;
	//const int* p = &a;
	//const int* *q = &p;
	//����
	//int a = 0;
	//int* p = &a;
	//const int* const*q = &p;
	//return 0;
//} 


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
//void swap1(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//
//}
//void swap2(int &a, int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
	//int a = 10;
	//int* p = &a;
	//int& b = a;
	//*p = 20;
	//20 20 20
	//cout << a << " " << *p << " " << b << endl;
	//b = 30;
	//30 30 30
	//cout << a << " " << *p << " " << b << endl;
	//int a = 10;
	//int b = 30;
	//swap1(&a, &b);
	//cout << "a:" << a << "b:" << b << endl;
	//swap2(a, b);
	//cout << "a:" << a << "b:" << b << endl;
	//int array[5] = {};
	//int* p = array;
	//����һ�����ñ���������������
	//int(&q)[5] = array;
	//cout << sizeof(array) << endl;
	//cout << sizeof(q) << endl;
	//cout << sizeof(p) << endl;
	//int a = 10;//aΪ��ֵ����ֵ�����ڴ棬�����֣�ֵ�����޸�
	//int& b = a;
	//int& c = 20;//����20����ֵ��û�ڴ棬û����
	//const int& c = 20;//�����ã�������ֵʱҪ��const��c�����޸�
	//C++11�ṩ����ֵ����
	//int&& d = 20;//��ֵ����
	//d = 30;//d�����޸�
	//int& e = d;//һ����ֵ���ñ�����������һ����ֵ
	//��ֵ���úͳ����û��ָ����һ���� 
	//return 0;
//}


/*
===========��const��һ��ָ�롢���õĽ��Ӧ��
����˼·����const��һ��ָ�롢���ý�ϵı��ʽ��ԭ��ָ��ȥ�ж�
*/
//int main()
//{
//	//дһ����룬���ڴ��0x0018ff44��дһ��4�ֽڵ�10
//	int*&& p = (int*)0x0018ff44;
//	//int* const& p = (int*)0x0018ff44;
//	
//	//int a = 10;
//	//int* p = &a;
//	//int*& q = p;
//	return 0;
//}


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
//int main()
//{
//	//int* p = new int(20);//���ٱ���
//	//delete p;//�ͷ�
//
//	//int* q1 = new int[20];//����һ����СΪ20�������飬������ʼ��
//	//int* q2 = new int[20]();//��һ����СΪ20��������,����ÿһ��Ԫ�س�ʼ��Ϊ0��
//	//delete[]q1;//�ͷ�
//	//delete[]q1;//�ͷ�
//
//	//��λnew
//	int data = 0;
//	int* p4 = new(&data)int(50);
//	cout << "data:" << data << endl;
//	return 0;
//}


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
//const int NAME_LEN = 20;
//class CGoods   //==>��Ʒ�ĳ�����������  ���Ͳ�ռ�ռ�   ʵ�����Ķ���ռ�ռ�
//{
//public://���ⲿ�ṩ���еĳ�Ա������������˽�е�����
//	//����Ʒ���ݳ�ʼ����
//	void init(const char* name, double price, int amount);
//	//��ӡ��Ʒ��Ϣ
//	void show();
//	//����Ա�����ṩһ��getXXX��setXXX�ķ���  ������ʵ�ֵķ������Զ��������������
//	void setName(char* name){strcpy(_name, name);}
//
//	void setPrice(double price){_price = price;}
//	void setAmount(int amount){_amount = amount;}
//
//	const char* getName(){return _name;}
//	double getPrince(){return _price;}
//	int getAmount() {return _amount; }
//private://����һ�㶼��˽�еĳ�Ա����
//	char _name[NAME_LEN];
//	double _price;
//	int _amount;
//};
//���ⶨ���Ա����
//void CGoods::init(const char* name, double price, int amount)
//{
//	strcpy(_name, name);
//	_price = price;
//	_amount = amount;
//}
//void CGoods::show()
//{
//	cout << "name:" << _name << endl;
//	cout << "price:" << _price << endl;
//	cout << "anount:" << _amount << endl;
//}
//int main()
//{
	/*
	�����ʵ��������������
	ÿһ���������Լ��ĳ�Ա����
	�������ǹ���һ�׳�Ա����
	�����ڴ��С��������ڴ�Ĵ�Сֻ�ͳ�Ա�����й�

	����show()�����֪�������ĸ�����
	init(name,price,amount)===>��ô֪������Ϣ��ʼ������һ������
	��ĳ�Ա����һ�����룬���еķ��������������һ��thisָ�룬���ܵ��øó�Ա�����Ķ���ĵ�ַ
	thisָ������ã����ֵ��ó�Ա�����Ķ���
	*/
//	CGoods good;//���ʵ����
//	//ʵ�ʵ�����
//	//init(&good1,"���",10.0,200)
//	good.init("���", 10.0, 200);
//	//show(&good1)
//	good.show();
//
//	good.setPrice(20.5);
//	good.setAmount(100);
//	good.show();
//
//	CGoods good1;
//	good1.init("�յ�",10000.0,50);//���ʵ����
//	good1.show();
//	return 0;
//}

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
	SeqStack* ps = new SeqStack(60);//�ڶ��Ͽ��٣���malloc�����ڴ棬Ȼ����ö����캯��SeqStack()�������ڴ���Ҫ�����Լ��ֶ��ͷš�
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