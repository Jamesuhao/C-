#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;
//0.��Ҫ
/*
1.�̳еı��ʺ�ԭ��
2.������Ĺ������
3.���ء����ǡ�����
4.��̬�󶨺Ͷ�̬��
5.��̬  vfptr��vftable
6.����������ԭ��
7.���ؼ̳��Լ�����
8.�����  vbptr��vftable
9.RTTI
10.C++��������ǿת
*/

//1.�̳еı��ʺ�ԭ��
/*
�̳еı��ʣ�a.����ĸ���   b.�ڻ����У��ṩͳһ���麯���ӿڣ��������������д��Ȼ��Ϳ���ʹ�ö�̬�ˡ�
�����֮��Ĺ�ϵ��
��ϣ�һ���ֵĹ�ϵ
�̳У�ͬһ�ֵĹ�ϵ

����ĳ�Ա�ķ����޶��������������ǲ����ܳ����̳з�ʽ��
�̳з�ʽ		����ķ����޶�		������ķ����޶�		(main)�ⲿ�ķ����޶�
public��		
						public					public						Y
						protected				protected					N
						private					���ɼ�						N
protected	:	
						public					protected					N
						protected				protected					N
						private					���ɼ�						N
private��
						public					private						N
						protected				private						N
						private					���ɼ�						N
�ܽ᣺
(1).�ⲿֻ�ܷ��ʶ����public��Ա��protected��private�ĳ�Ա�޷�ֱ�ӷ���
(2).�ڼ̳нṹ�У�������ӻ�����Լ̳�private�ĳ�Ա������������ȴ�޷�ֱ�ӷ���
(3).protected��private������
	�ڻ����ж���ĳ�Ա���뱻��������ʣ����ǲ��뱻�ⲿ���ʣ���ô�ڻ����У�����س�Ա�����protected��Ա��
	�����������ⲿ����������ʣ���ô�ڻ����оͰ���س�Ա�����private��Ա��

Ĭ�ϵļ̳з�ʽ��ʲô��
���ʹ��class���������࣬Ĭ�ϼ̳з�ʽ����private˽�е�
���ʹ��struct���������࣬Ĭ�ϼ̳з�ʽ����public���е�
*/

//2.������Ĺ������
/*
������ӻ�����Լ̳����еĳ�Ա(�����ͷ���)
(1)��������ô��ʼ���ӻ���̳����ĳ�Ա������
ͨ�����û�����Ӧ�Ĺ��캯������ʼ��

������Ĺ��캯�������������������ʼ�����������������Դ
������ӻ���̳����ĳ�Ա�����ɻ���Ĺ��캯�������������������

�����������������Ĺ����ǣ�
1.��������û���Ĺ��캯������ʼ���ӻ���̳����ĳ�Ա
2.�����������Լ��Ĺ��캯������ʼ���������Լ����еĳ�Ա
3.�����������Լ��������������ͷ��������Ա����ռ�õ��ⲿ��Դ(���ڴ棬�ļ���
4.��������û���������������ͷ��������ڴ��У��ӻ���̳����ĳ�Ա����ռ�õ��ⲿ��Դ(���ڴ棬�ļ���
*/

//3.���ء����ء�����(��д)
/*
(1)���ع�ϵ
a.һ�麯��Ҫ���أ�����Ҫ����ͬһ���������У����Һ�������ͬ�������б�ͬ��
(2)���ع�ϵ��ָ���������������
a.�ڼ̳нṹ���У��������������ͬ����Աʱ���������ͬ����Ա���ѻ����ͬ����Ա�����ص����ˡ�
b.���������ȵ����Լ�������ĳ�Ա��������ʱ����ȥ����Ѱ�ҡ�
(3)���ǹ�ϵ
a.����������еķ������ͻ���̳�����ĳ������������ֵ���������������б���ͬ��
���һ�������������virtual�麯������ô�����������������Զ�������麯����
������������Ϊ����(��д)��ϵ������������麯�����У������������麯���ĵ�ַ�����ǻ�������麯���ĵ�ַ
(4)�Ѽ̳нṹ��Ҳ˵�ɴ���(����) ����(������)�Ľṹ
(5)�ڼ̳нṹ�У��������µ�����ת����Ĭ��ֻ֧�ִ��µ��ϵ�����ת��
�������				 ->   ���������				N
���������			->		�������					Y
����ָ��(����)		->		���������				N
������ָ��(����)   ->	�������					Y
*/

//4.�麯������̬�󶨺Ͷ�̬��
/*
һ����������麯����������������Ӱ�죿
�ܽ�1��
a.��������涨�����麯������ô����׶Σ�����������������Ͳ���һ��Ψһ��vftable�麯����,
�麯������Ҫ�洢�����ݾ���RTTIָ��(����ʱ��������Ϣ)���麯���ĵ�ַ��
b.����������ʱ��ÿһ���麯��������ص��ڴ�.rodata����
�ܽ�2��
a.һ�����ж������麯������ô����ඨ��Ķ���������ʱ���ڴ濪ʼ���֣���洢һ���麯��ָ��vfptr��ָ����Ӧ���͵��麯����vftable��
b.һ�����Ͷ����n���������ǵ�vfptrָ��Ķ���ͬһ���麯����
�ܽ�3��
a.һ���������麯���ĸ�������Ӱ�������ڴ��С����Ӱ������麯����Ĵ�С��
�ܽ�4��
a.����������еķ������ͻ���̳�����ĳ������������ֵ���������������б���ͬ��
���һ���ķ�����virtual�麯������ô�����������������Զ�������麯����
��̬�󶨺Ͷ�̬�󶨣�
�ܽ�5��
��̬�󶨣�����ʱ�ں����ĵ��á�
��̬�󶨣�����ʱ�ں����ĵ��á�


����һ����Щ��������ʵ�ֳ��麯����
�麯��������
(1)�麯���ܲ�����ַ���洢��vftable���С�
(2)���������(vfptr -> vftable -> �麯����ַ)
���ԣ�
a.���캯������ʵ�ֳ��麯�����ڹ��캯���е����麯����Ҳ���ᷢ����̬�󶨡�
b.static��̬��Ա��������ʵ�ֳ��麯������Ϊ��̬��Ա�����༶��ģ���ͨ��������á�

�����������������
�����������õ�ʱ�򣬶����Ǵ��ڵġ�  
������������������virtual�麯������ô����������������Զ������virtual�麯��
�ڻ����ָ��(����)ָ�����new����������������ʱ��delete pb(�����ָ��)��
����������������ʱ�򣬱��뷢����̬�󶨣�����ᵼ������������������޷�����

���������ǲ����麯���ĵ���һ�����Ƕ�̬�󶨣�
���ǵģ�����Ĺ��캯���У������麯����Ҳ�Ƕ�̬��(���캯���е�����������(��)�����ᷢ����̬�󶨡�
����ö���������麯����������̬�󶨡�
�����ָ��/���õ����麯����������̬�󶨡�
*/
/*
class Base
{
public:
	Base(int data = 0)
		:ma(data) 
	{
		//cout << "Base()" << endl;
	}
	//�麯��
	virtual void show() { cout << "Base::show()" << endl; }
	//�麯��
	//virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive :public Base
{
public:
	Derive(int data = 0)
		:Base(data)
		, mb(data)
	{
		//cout << "Derive()" << endl;
	}
	void show() { cout << "Derive::show()" << endl; }
private:
	int mb;
};
int main()
{
	Base b;
	Derive d;
	//��̬�󶨣��ö���������麯�����Ǿ�̬��
	b.show(); //�麯�� call Base::show
	d.show();//�麯�� call Base::show
	//��̬��(������ָ������麯��)
	Base* pb1 = &b;
	pb1->show();
	Base* pb2 = &d;
	pb2->show();
	//��̬��(���������õ����麯��)
	Base& rb1 = b;
	rb1.show();
	Base& rb2 = d;
	rb2.show();
	//��̬��(�麯��ͨ��ָ��������ñ������ã��Żᷢ����̬��)
	Derive* pd1 = &d;
	pd1->show();
	Derive& rd2 = d;
	rd2.show();
	Derive d(50);
	Base* pb = &d;
	
	pb->show  Base::show �������show����ͨ�������ͽ��о�̬��
	pb->show  Base::show �������show���麯���������ͽ��ж�̬��
	
	//pb->show();//��̬�İ�(��ָ̬����ʱ�ڣ���ָ�����ĵ���)
	//pb->show(10);//��̬�İ�(��ָ̬����ʱ�ڣ���ָ�����ĵ���)
	//cout << sizeof(Base) << endl;//4
	//cout << sizeof(Derive) << endl;//8
	//cout << typeid(pb).name() << endl;//class Base*
	
	//pb�����ͣ�Base->�ȿ�Base����û���麯��
	//���Baseû���麯����*pbʶ��ľ��Ǳ���ʱ�ڵ�����  *pb=>Base����
	//���Base���麯����*pbʶ��ľ�������ʱ�ڵ�����->RTTI����
	//pbָ������������������*pbʶ��ľ�����������麯����
	
	cout << typeid(*pb).name() << endl;//class Base
	return 0;
}
*/

//5.�������̬��
/*
��̬(����ʱ��)�Ķ�̬���������ء�ģ��(����ģ�����ģ��)
�������أ�
bool compare(int,int);
bool compare(double,double);
compare(10,20)��call compare_int_int �ڱ���׶ξ�ȷ���õ��õĺ����汾
compare(10.5,20.5)��call compare_double_double �ڱ���׶ξ�ȷ���õ��õĺ����汾
ģ�壺
template<typename T>
bool compare(T a,T b){}
compare(10,20)��     =>  int  ����׶�ʵ����һ��compare<int>
compare(10.5,20.5)��=>double ����׶�ʵ����һ��compare<double>
��̬(����ʱ��)�Ķ�̬��
�ڼ̳нṹ�У�����ָ��(����)ָ�����������ͨ����ָ��(����)����ͬ�����Ƿ�����
����ָ��ָ���Ǹ���������󣬾ͻ�����ĸ����������ĸ��Ƿ�������Ϊ��̬��
��Ϊ��̬�ײ���ͨ����̬����ʵ�ֵģ�����ָ��(����)ָ���ĸ����������
�ͻ������������������麯��ָ�룬�������������������麯������ȡ����������ͬ�����Ƿ��������ʸö����ͬ�����Ƿ���

//����Ļ���
class Animal
{
public:
	Animal(string name) :_name(name) {}
	virtual void bark() {};
protected:
	string _name;
};
//�����Ƕ���ʵ����
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��wang wang!" << endl; }
};
class Pig :public Animal
{
public:
	Pig(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��heng heng!" << endl; }
};
//�����һ��bark  API�ӿ��޷�������������Ҫ���"��-��"ԭ��
/*
����������ԭ��
��-��ԭ�򣺶��޸Ĺرգ�����չ����
void bark(Cat cat)
{
	cat.bark();
}
void bark(Dog dog)
{
	dog.bark();
}
void bark(Pig pig)
{
	pig.bark();
}
void bark(Animal* p)
{
	p->bark();//Animal::bark�麯����������̬��
	//p->cat   Cat vftable &Cat::bark
	//p->dog Dog vftable &Dog::bark
	//p->pig   Pig vftable &Pig::bark
}
int main()
{
	Cat cat("����");
	Dog dog("����");
	Pig pig("����");

	//bark(cat);
	//bark(dog);
	//bark(pig);
	bark(&cat);
	bark(&dog);
	bark(&pig);
	return 0;
}
*/

//6.����������ԭ��
#if 0
/*
ӵ�д��麯�����࣬���������ࡣ
ע�⣺�����಻����ʵ���������ˣ����ǿ��Զ���ָ������ñ�����
����һ�����������ͨ����ʲô����
�������һ���ʲô����Ƴɳ����ࣿ
һ��ѻ���ʵ�ֳɳ����࣬�ѻ���ķ���ʵ�ֳɴ��麯��
*/
//ʾ��1������Ļ��࣬����Animal��������Animal����ĳ��ʵ�������
//1.string _name;�����еĶ���ʵ����ͨ���̳�Animalֱ�Ӹ��ø�����
//2.�����е������ౣ��ͳһ�ĸ���/��д�ӿ�
/*
class Animal
{
public:
	Animal(string name) :_name(name) {}
	virtual void bark()  = 0;//���麯��
protected:
	string _name;
};
//�����Ƕ���ʵ����
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��wang wang!" << endl; }
};
class Pig :public Animal
{
public:
	Pig(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��heng heng!" << endl; }
};
void bark(Animal* p)
{
	p->bark();//Animal::bark�麯����������̬��
}
*/
//ʾ��2�������Ļ���
class Car//������
{
public:
	Car(string name,double oil) :_name(name),_oil(oil) {}
	double getLeftMiles()//��ȡ����ʣ�����������ܵĹ�����
	{
		return _oil * getMilesPerGallon();//�����˶�̬��
	}
	string getName()const
	{
		return _name;
	}
protected:
	string _name;
	double _oil;
	virtual double getMilesPerGallon() = 0;//���麯��
};
class Bnze :public Car
{
public:
	Bnze(string name, double oil) :Car(name, oil) {  }
	double getMilesPerGallon() { return 20.0; }
};
class Audi :public Car
{
public:
	Audi(string name, double oil) :Car(name, oil) {  }
	double getMilesPerGallon() { return 18.0; }
};
class BMW :public Car
{
public:
	BMW(string name, double oil) :Car(name, oil) {  }
	double getMilesPerGallon() { return 19.0; }
};
//���ⲿ�ṩһ��ͳһ�Ļ�ȡ����ʣ��·������API
void showCarLeftMiles(Car& car)
{
	cout << car.getName() << "  left miles��" << car.getLeftMiles() << "������" << endl;
}
int main()
{
	/*
	Cat cat("����");
	Dog dog("����");
	Pig pig("����");

	bark(&cat);
	bark(&dog);
	bark(&pig);
	*/
	Bnze b1("����",20.0);
	Audi a("�µ�",20.0);
	BMW b2("����",20.0);

	showCarLeftMiles(b1);
	showCarLeftMiles(a);
	showCarLeftMiles(b2);
	return 0;
}
#endif

//7.�̳ж�̬������
/*1.
class Animal
{
public:
	Animal(string name) :_name(name) {}
	virtual void bark() = 0;
protected:
	string _name;
};
class Cat :public Animal
{
public:
	Cat(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��miao miao!" << endl; }
};
class Dog :public Animal
{
public:
	Dog(string name) :Animal(name) {}
	void bark() { cout << _name << "bark��wang wang!" << endl; }
};
int main()
{
	Animal* p1 = new Cat("�ӷ�è");//vfprt -> Dog  vftable
	Animal* p2 = new Dog("����");//vfptr -> Cat vftable

	int* p11 = (int*)p1;
	int* p22= (int*)p2;
	int tmp = p11[0]; //p11[0]���ʵľ���Cat��ǰ�ĸ��ֽ�
	p11[0] = p22[0];//p22[0]���ʵľ���Dog��ǰ�ĸ��ֽ�
	p22[0] = tmp;
	
	p1->bark();//p1->Cat vfptr  -> Dog vftable bark
	p2->bark();//p2->Dog vfptr  -> Cat vftable bark

	delete p1;
	delete p2;
	return 0;
}
*/
/*
2
class Base
{
public:
	virtual void show(int i = 10)
	{
		cout << "call Base ::show i��" << i << endl;
	}
};
class Derive :public Base
{
public:
	void show(int i = 20)
	{
		cout << "call Derive::show i��" << i << endl;
	}
};
int main()
{
	Base* p = new Derive();
	
	//push 0Ah=>�������ã�����ѹջ���ڱ���ʱ�ھ�ȷ���õ�
	//mov eax,dword ptr[p]
	//mov ecx,dword ptr[eax]
	//call ecx;
	
	p->show();
	delete p;
	return 0;
}
*/
/*
3
class Base
{
public:
	virtual void show()
	{
		cout << "call Base ::show i��" << endl;
	}
};
class Derive :public Base
{
private:
	void show()
	{
		cout << "call Derive::show i��" << endl;
	}
};
int main()
{
	Base* p = new Derive();
	//��Ա�����ķ���Ȩ�����ڱ���׶ξ�ȷ����
	p->show();  //�����ܵ��õ�Derive::show��������ʱ�ڲ�ȷ����
	delete p;
	return 0;
}
*/
/*4
class Base
{
public:
	Base()
	{
		cout << "call Base()" << endl;
		clear();
	}
	void clear()
	{
		memset(this, 0, sizeof(*this));
	}
	virtual void show()
	{
		cout << "call Base::show()" << endl;
	}
};
class Derive :public Base
{
public:
	Derive()
	{
		cout << "call Derive()" << endl;
	}
	void show()
	{
		cout << "call Derive::show()" << endl;
	}
};
int main()
{
	//pb1���������⣬������ڹ��캯���е�clear
	Base* pb1 = new Base();
	pb1->show();//��̬��
	delete pb1;
	//pb2����û������
	Base* pb2 = new Derive();
	pb2->show();//��̬��
	delete pb2;

	return 0;
}
*/

//8.��������̳�
#if 0
/*
virtual:
1.���γ�Ա��ʽ���麯��
2.�������μ̳з�ʽ������̳�
����ࣺ����̳е��࣬��������ࡣ
*/
class A
{
public:
	virtual void func() { cout << "call A::func" << endl; }
	void operator delete(void* ptr)
	{
		cout << "operator delete p��" << ptr << endl;
		free(ptr);
	}
private:
	int ma;
};
class B :virtual public A
{
public:
	void func() { cout << "call B::func" << endl; }
	void* operator new(size_t size)
	{
		void* p = malloc(size);
		cout << "operator new p :" << p << endl;
		return p;
	}
private:
	int mb;
};
/*
�����̳У�
A a��4���ֽ�
B b��8���ֽ�
��̳У�
A a��4���ֽ�
B b��12���ֽ�
*/
int main()
{
	
	B b;
	A* p = &b;
	//����ָ��ָ�������������Զָ������������л��ಿ�ֵ���ʼ��ַ
	//A* p = newb;//B::vftable
	cout << "main p:" << p << endl;
	p->func();
	//delete p;
	return 0;
}
#endif

//9.C++�Ķ�̳У��������������ĸ���
#if 0
/*
���μ̳е����⣺ʹ���������ж�ݼ�ӻ��������
ʹ����̳У�������μ̳е����⡣
ע�⣺
1.�ĸ�������ݻᱻ��ݼ̳У���ʹ�ĸ���Ϊ�����
2.ֻҪ�Ƕ��������ļ̳У���Ҫʹ��virtual
3.���������У�Ҫ���������Ĺ��캯������������Ա���г�ʼ����
*/
class A
{
public:
	A(int data) :ma(data) { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
protected:
	int ma;
};
class B :virtual public A
{
public:
	B(int data) :A(data), mb(data) { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
protected:
	int mb;
};
class C :virtual public A
{
public:
	C(int data) :A(data), mc(data) { cout << "C()" << endl; }
	~C() { cout << "~C()" << endl; }
protected:
	int mc;
};
class D :public B,public C
{
public:
	D(int data) :A(data), B(data), C(data), md(data) { cout << "D()" << endl; }
	~D(){ cout << "~D()" << endl; }
protected:
	int md;
};
int main()
{
	D d(10);
	return 0;
}
#endif

//10.C++����������ת��
#if 0
/*
1.const_cast��ȥ���������Ե�һ������ת����ֻ�ܵ��������޶��������ܸ��Ļ������͡�
���磺
const int a = 10;//�����޶��� const, �������� int 
char* p2 = const_cast<char*>(&a);//ֻ�ܵ��������޶�����ȥ�������ԣ����ܸ��Ļ�������intΪchar
2.static_cast���ṩ��������Ϊ��ȫ������ת��
3.reinterpret_cast��������C����ǿ������ת��
4.dynamic_cast����Ҫ���ڼ̳нṹ�У�����֧��RTTI����ʶ�������ת��
*/
class Base
{
public:
	virtual void func() = 0;
};
class Derive1 :public Base
{
public:
	void func() { cout << "call Derive1::func()" << endl; }
};
class Derive2 :public Base
{
public:
	void func() { cout << "call Derive2::func()" << endl; }
	//Derive2ʵ���¹��ܵ�API�ӿں���
	void derive02func() { cout << "call Derive2::derive02func()" << endl; }
};
void showFunc(Base* p)
{
	/*
	���⣺
	���ָ��ָ��Ĳ���Derive2�Ķ������������߼�������ָ���͵��麯����
	�����Derive2�Ķ���͸��Ĺ��ܣ�ʹ�����Derive2���е�derive02func()������ô����
	*/
	//dynamic_cast����pָ���Ƿ�ָ�����һ��Derive2���͵Ķ���
	//p->vfptr->vftable RTTI��Ϣ
	//����ǣ�dynamic_castת�����ͳɹ�������Deriver2����ĵ�ַ����pd2�����򷵻�nullptr
	Derive2* pd2 = dynamic_cast<Derive2*>(p);
	if (pd2 != nullptr)
	{
		pd2->derive02func();
	}
	else
	{
		p->func();//��̬��  
	}
}
int main()
{
	/*
	1.const_cast<�����������ָ��int*��������int&����>��������ȥ���������Եĳ���
	const int a = 10;
	int* p1 = (int*)&a;
	int* p2 = const_cast<int*>(&a);
	*/
	/*
	2.static_cast��֧�ֻ����������֮����໥ת��
	//��ȷ
	int a = 10;
	char b = static_cast<int>(a);
	//����
	int* p = nullptr;
	short* pb = static_cast<short*>(p);
	*/
	Derive1 d1;
	Derive2 d2;
	showFunc(&d1);
	showFunc(&d2);
	return 0;
}
#endif