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
#endif