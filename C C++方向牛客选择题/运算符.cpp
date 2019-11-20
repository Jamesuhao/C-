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
#endif 