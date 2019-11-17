#if 0
#1
若有以下说明和定义语句：
union uti{ int n; double g; char ch[9]; } struct srt { float xy; union uti uv; }aa; 
考虑内存对齐，则变量aa所占内存的字节数是(24)。
注解：首先int，float是4字节，double是8字节，char是1字节。 
union里面以最大成员计算空间，应该是char［9］，占9字节，然后以8字节为单位对齐，所以uti实际占16字节。 
struct srt中，就是4 + 16＝20字节，同样以8字节对齐，所以应该是24

#2在32位cpu上选择缺省对齐的情况下，有如下结构体定义：
struct A {
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};
则sizeof（struct A）的值为（16）
注解：
此为位段，a、b共占31个bit位，所以a和b共占4个字节；
b、c之和大于32个bit位，所以b和c各占4个字节，index为char类型，1字节对齐，占一个字节；
整体4字节对齐，攻占16个字节
#endif