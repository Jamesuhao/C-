#if 0
#1�����麯����������ȷ����(B)������
A ��������麯���������麯�����в�ͬ�Ĳ�������������
B ���������������麯��
C ������������¶��������麯��
D �麯��������һ��static�͵ĺ���

#2���¹��ڴ��麯����˵��, ��ȷ����(A)������
A �������麯�����಻��ʵ����
B �������麯������������
C �������ʵ�ֻ����
D ���麯�������ǿպ���

#3���ں�����������ȷ����(D)������
A �麯����һ��static�͵ĺ���
B ��������麯���������麯�����в�ͬ�Ĳ�������������
C �麯����һ���ǳ�Ա����
D ������˵�����麯���������������Ӧ�ĺ������Բ���˵��Ϊ�麯��

#4��һ�����ĳ��������˵��Ϊvirtual�����ڸ���������������е�ͬԭ�ͺ���(D) ???
A ֻ�� ������˵��ʱ��ʶ�麯��
B ֻ�б�����˵��Ϊvirtualʱ�����麯��
C �������麯��
D �����麯��

#5����ִ�к�a��b�ķֱ�Ϊ���٣�(A)������
class Test{
public:
	int a;
	int b;
	virtual void fun() {}
	Test(int temp1 = 0, int temp2 = 0)
	{
		a = temp1;
		b = temp2;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
};
int main()
{
	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;
	*(pInt + 1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	return 0;
}

#6������C++���룺������
struct A {
	void foo() { printf("foo"); }
	virtual void bar() { printf("bar"); }
	A() { bar(); }
};
struct B :A {
	void foo() { printf("b_foo"); }
	void bar() { printf("b_bar"); }
};
��ô��
A* p = new B;
p->foo();
p->bar();
���Ϊ��A
A barfoob_bar
B foobarb_bar
C barfoob_foo
D foobarb_fpp

#7���³���������Ϊ��B ������
class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}
	virtual void test()
	{
		func();
	}
};
class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[])
{
	B* p = new B;
	p->test();
	return 0;
}
A A->0
B B->1
C A->1
D B->0
E �������
F ���϶�����

#8���³����������Ϊ��B ������
class A
{
public:
	void foo()
	{
		printf("1");
	}
	virtual void fun()
	{
		printf("2");
	}
};
class B : public A
{
public:
	void foo()
	{
		printf("3");
	}
	void fun()
	{
		printf("4");
	}
};
int main(void)
{
	A a;
	B b;
	A* p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A* ptr = (A*)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}
A 121434
B 121414
C 121232
D 123434
#endif