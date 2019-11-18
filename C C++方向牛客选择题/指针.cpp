#if 0
#1下列程序的运行结果为：1 2 15
#include<stdio.h>
void main()
{
	short* p, * q;
	short arr[15] = { 0 };
	p = q = arr;
	p++;
	printf("%d,", p - q);
	printf("%d,", (char*)p - (char*)q);
	printf("%d", sizeof(arr) / sizeof(*arr));
}
注解：指针自增、自减每次移动的偏移量是指针所指向对象的字节大小，所以p++与q的偏移量是2个字节。
指针相减的值是指针地址的偏移除以指针每次移位的大小；
1)p - q = 1; 偏移量为2个字节，每次移动2个字节，所以为1
2)(char*)p - (char*)q，指针的偏移没变，但是每次指针移位是按照（char * ）类型移动，即每次移动1个字节，所以是2
3）数字每次元素2个字节，所以sizeof(arr)为30，sizeof(*arr)为2。

#2指针可以做减法、比较、指向同一块内存空间，但是不能相加，因为相加是没有意义的

#3以下关于C++的描述中哪一个是正确的(C)
A 任何指针都必须指向一个实例
B 子类指针不可以指向父类实例
C 任何引用都必须指向一个实例
D 引用所指向的实例不可能无效

#4下面关于"指针"的描述不正确的是(A)
A 当使用free释放掉一个指针内容后, 指针变量的值被置为NULL   //free只负责释放空间
B 32位系统下任何类型指针的长度都是4个字节
C 指针的数据类型声明的是指针实际指向内容的数据类型
D 野指针是指向未分配或者已经释放的内存地址

#5以下程序的输出结果为(A)
#include <iostream>
using namespace std;
void func(char** m) {
	++m;
	cout << *m << endl;
}
int main() {
	static char* a[] = { "morning", "afternoon", "evening" };
	char** p;
	p = a;
	func(p);
	return 0;
A afternoon
B 字符o的起始地址
C 字符o
D 字符a的起始地址
#endif
