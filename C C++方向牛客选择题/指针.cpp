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
#endif