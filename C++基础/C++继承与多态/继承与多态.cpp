#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;
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



				