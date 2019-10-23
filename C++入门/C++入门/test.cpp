#include<iostream>
using  namespace::std;
/*
=========》形参带默认值的函数
1.给默认值的时候从右向左给
2.相对于普通调用函数而言效率更高，传参时，会少mov指令
3，定义处可以给形参默认处，声明也可以给形参默认值，但每一个形参只能给一次
4.下列声明方式也是可以的
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
=========》inline内联函数 和 普通函数的区别？？？
1.inline内联函数：在编译过程中，就没有函数的调用开销了，
2.在函数的调用点直接把函数的代码进行展开处理，inline函数不会在符号表中在生成相应的函数符号
3.inline只是建议编译器把这个函数成内联函数，是否处理成inline由编译器决定
4.但是不是所有的inline都会编译器处理成内联函数：如递归
5.debug版本上，inline是不起作用的；inline只有在release版本下才能出现
*/
//inline int sum(int a, int b)//普通函数调用会产生这些函数符号*.o  sum_int_int   .text
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = sum(a, b);
//	//此处有标准的函数调用过程  参数压栈  函数栈帧的开辟和回退过程
//	//有函数的调用的开销
//	cout << "ret:" << ret << endl;
//	return 0;
//}


/*
=========》函数重载
1.为什么C++支持函数重载，C语言不支持函数重载？
(1).C++代码产生函数符号的时候，符号是由函数名+参数列表类型组成的
(2).C语言代码产生函数符号，符号由下划线+函数名
(3).编译器根据C++所产生的符号中参数的个数以及参数的类型来区分,而c语言不带参数列表，所以无法区分
2.什么是函数重载？函数重载需要注意些什么？
(1).一组函数，出现在同一个作用域，其中函数名相同，参数列表的个数或者类型不同，就称为函数重载。
(2).一组函数，函数名相同，参数列表也相同，仅仅是返回值不同，是不构成函数重载的。
3.C++和C语言之间如何互相调用？
C调用C++:无法直接调用(生成符号规则不同)。解决办法：把C++源码的声明括在extern"C"中。
C++调用C:无法直接调用(生成符号规则不同)。解决办法：把C函数声明括在extern "C"中。
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
4.const或者volatile的时候，是怎么影响形参类型的？
后续讲解。
面试题：请你解释一下，什么是多态？
静态(编译时期)的多态：函数重载、模板等
动态(运行时期)的多态：
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
==========>const修饰指针变量
1.如何理解const？
const修饰的变量不能够再作为左值!!!  初始化完成后值不能被修改

2.C和C++中const的区别是什么？
(1)C中const修饰的量，可以不用初始化，但是不叫常量，叫做常变量,其不能作为左值被修改，但是其内存中的值可以被修改。
(2)C++的const必须初始化，叫做常量。
(3)const的编译方式不同：
C中，const就是当作一个变量来编译生成指令的。
C++中，所有出现const常量的地方，都被常量的初始化值替换掉了，初始化值必须为立即数。
(4)考虑如下代码
int b = 20;
const int a = b;
此时a不再是常量，已经退化成常变量，因为初始化值不是立即数，是一个变量。

3.const修饰的常量经常出现的错误是：
(1)直接修改常量的值====》常量不能作为左值
(2)间接修改常量的值====》不能把常量的地址泄露给一个普通的指针或者普通的引用变量

4.const和一级指针的结合：修饰指向和所指的内存中的值
C++的语言规范：cosnt修饰的是离它最近的类型。
记忆方法：去掉const所修饰的类型即为不能改变的常量
(1)int const *p;\const int *p = &a; ===》*p=20//错误 p = &a;//正确
修饰*p，即指针所指内存单元中的值不能被改变，但指针指向可以被改变
即可以任意指向int类型的内存，但是不能通过指针间接修改所指内存单元中的值
(2)int *const p = &a; ===>p = &b//错误 *p = 20;//正确
修饰p，即指针的指向不能被修改，但是指针所指内存单元中的值可以被修改
即这个指针p现在是常量，不能再指向其他内存，但是可以通过指针解引用修改指针所指内存单元中的值
(3)const int *const p = &a; ===>p = &b//错误 *p=30;//错误
以上两种情况的结合，指针的指向和所指内存单元的值绝不能被修改

5.const和二级指针的结合
(1)const int* *q;修饰的是**q,所以*q和q是可以改变的
(2)int *cosnt *q;修饰的是*q,所以**q和q是可以改变的
(3)int **const q;修饰的是q,所以**q，*q是可以改变的
6.const和指针的类型转换公式：
int* <= const int*  是错误的！
cosnt int* <=== int*  是正确的！

int ** <= const int**  是错误的！
cosnt int** <= int**  是错误的！

int** <= int* const*  是错误的！
int* cosnt* <= int**  是正确的！
7.如果const右边没有接指针*d话，cosnt是不参与类型的
int* const p = &a;//int*<===int*  const后无指针*，不参与类型
*/
//int main()
//{
	//int b = 20;
	//const int a = b;//此时已经退化成常变量，因为初始化值不是立即数，是一个变量。
	//const int a= 20;
	
	//b = 30;//错误，被cosnt修饰的变量不能作为左值
	//int arr[b] = {};
	//int* p = (int*)&a;//已经把b内存中的值改掉了
	//*p = 30;
	//printf("%d %d %d\n", a, *p, *(&a));//在编译阶段const修饰的变量就已经被初始化的值替换了
	
	
	//const int a = 10;
	//int* p = &a;//错误，不能把常量的地址泄露给普通指针
	//const int* p = &a;//正确

	//int a = 0;
	//int* p = &a;
	//const int* *q = &p;//错误的，const int **<===int **
	/*
	const int * *q = &p;
	错误的原因：
	如果const int * *q = &p是正确的，则：
	    *q<=>p; //*q即为p的地址
	因为*q只能接收const int类型变量的地址：
	所以有定义：const int b = 20;
	对于*q来说，他的类型是const int*类型
	而&b的类型也是const int*类型，所有有如下代码:
		*q = &b <=> p = &b;//即把常量b的地址赋给了一个普通指针p，
	所以const int* *q=&p是错误的
	*/
	//可以修改为：
	//int a = 0;
	//const int* p = &a;
	//const int* *q = &p;
	//或者
	//int a = 0;
	//int* p = &a;
	//const int* const*q = &p;
	//return 0;
//} 


/*
========》C++的引用
1.左值引用和右值引用
(1)右值引用:int&& c = 20;专门用来引用右值类型，指令上，可以自动产生临时量，然后直接引用临时量c=40;
(2)右值引用变量本身是一个左值，只能用左值引用来引用它
(3)不能用一个右值引用变量来引用一个左值

2.引用是一种更安全的指针
3.指针和引用的区别
(1)引用时必须初始化的，指针可以不初始化
(2)定义一个引用变量和一个指针变量,其汇编指令是一模一样的，通过指针解引用修改指针指向的内存的值和通过引用变量修改所引用内存的值，其底层指令也是一模一样的
(3)引用只有一级引用，没有多级引用；指针可以有一级指针，也可以有多级指针
(4)在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占 4个字节) ;
(5)引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小; 
(6)访问实体方式不同，指针需要显式解引用，引用编译器自己处理 ;
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
	//定义一个引用变量，来引用数组
	//int(&q)[5] = array;
	//cout << sizeof(array) << endl;
	//cout << sizeof(q) << endl;
	//cout << sizeof(p) << endl;
	//int a = 10;//a为左值。左值他有内存，有名字，值可以修改
	//int& b = a;
	//int& c = 20;//错误，20是右值：没内存，没名字
	//const int& c = 20;//常引用，引用右值时要加const，c不能修改
	//C++11提供了右值引用
	//int&& d = 20;//右值引用
	//d = 30;//d可以修改
	//int& e = d;//一个右值引用变量，本身是一个左值
	//右值引用和常引用汇编指令是一样的 
	//return 0;
//}


/*
===========》const与一级指针、引用的结合应用
解题思路：把const与一级指针、引用结合的表达式还原成指针去判断
*/
int main()
{
	//写一句代码，在内存的0x0018ff44处写一个4字节的10
	int*&& p = (int*)0x0018ff44;
	//int* const& p = (int*)0x0018ff44;
	
	//int a = 10;
	//int* p = &a;
	//int*& q = p;
	return 0;
}