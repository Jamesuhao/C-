#if 0
#1关于虚函数的描述正确的是(B)？？？
A 派生类的虚函数与基类的虚函数具有不同的参数个数和类型
B 内联函数不能是虚函数
C 派生类必须重新定义基类的虚函数
D 虚函数可以是一个static型的函数

#2以下关于纯虚函数的说法, 正确的是(A)？？？
A 声明纯虚函数的类不能实例化
B 声明纯虚函数的类成虚基类
C 子类必须实现基类的
D 纯虚函数必须是空函数

#3关于函数的描述正确的是(D)？？？
A 虚函数是一个static型的函数
B 派生类的虚函数与基类的虚函数具有不同的参数个数和类型
C 虚函数是一个非成员函数
D 基类中说明了虚函数后，派生类中起对应的函数可以不必说明为虚函数

#4当一个类的某个函数被说明为virtual，则在该类的所有派生类中的同原型函数(D) ???
A 只有 被重新说明时才识虚函数
B 只有被重新说明为virtual时才是虚函数
C 都不是虚函数
D 都是虚函数

#5代码执行后，a、b的分别为多少？(A)？？？
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

#6有如下C++代码：？？？
struct A {
	void foo() { printf("foo"); }
	virtual void bar() { printf("bar"); }
	A() { bar(); }
};
struct B :A {
	void foo() { printf("b_foo"); }
	void bar() { printf("b_bar"); }
};
那么：
A* p = new B;
p->foo();
p->bar();
输出为：A
A barfoob_bar
B foobarb_bar
C barfoob_foo
D foobarb_fpp
#endif