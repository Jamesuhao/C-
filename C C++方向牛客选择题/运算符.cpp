#if 0
#1下面程序运行结果为（Low）。
void main()
{

	char c = ’a’；

		if ('a' < c <= 'z') printf("Low”)；

		else printf("UP")；
}
注解：关系运算符具有左结合性

#2以下哪个选项一定可以将flag的第二个bit置0(A)
A flag &= ~2
B flag |= 2
C flag ^= 2
D flag >>= 2

#3输入x = 9999，返回值为(A)
int func(int x) {
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);//与运算
}
	return count;
}
A 8
B 9
C 10
D 12
注解：
该数中二进制1的个数即为按位与的次数

#4下列哪个用法哪个是错误的(C)
A int* a;
B extern const int array[256];  //extern引用外部变量
C const int& ra;//引用变量必须赋初值
D typedef void (*FUN)();

#5函数func的定义如下：以下代码在vs中输出结果为(D)
void func(const int& v1, const int& v2)
{
	std::cout << v1 << ' ';
	std::cout << v2 << ' ';
}
int main(int argc, char* argv[])
{
	int i = 0;
	func(++i, i++);
	return 0;
}
A 0 1
B 1 2
C 2 1
D 2 0
E 程序强制终止并报错
F 结果与编译器有关
注解：程序编译时函数参数是从右向左进行编译入栈的，所以先对i执行后置++,此时形参2依旧为0，i为1，
再对i执行前置++，形参1为2；
所以输出2，0。
#endif 