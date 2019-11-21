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
整体4字节对齐，共占16个字节

#3下面两个结构体，在#pragma pack(4)和#pragma pack(8)的情况下，结构体的大小分别是(16,16,16,24)
struct One {
	double d;
	char c;
	int i;
}
struct Two {
	char c;
	double d;
	int i;
注解：
#pragma pack(4):
One   0~7 8 12~15     8字节对齐   共16个字节
Two   1 4~11 12~15   8字节对齐   共16个字节
#pragma pack(8)
One   0~7 8 12~15     8字节对齐  共16个字节
Two   1 8~15 16~19   8字节对齐  共24个字节

#4有一个如下结构体，请问在64位编译器下用sizeof(struct A)计算出的大小是多少？(24)
struct A {
	long a1;
	short a2;
	int a3;
	int* a4;
};
注解：
64位编译器：
指针：8个字节
long：8个字节
unsigned long：8个字节
32位编译器下：
指针：4个字节
long：4个字节
unsigned long：4个字节
a1:0~7 a2:8~11 a3:12~15 a4:16~19 8字节对齐：共占24个字节

#4在一个64位操作系统下，有如下结构体，上述fool()程序的执行结果为（A）
struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}
A 1，0，0
B 1，1，0
C 0，1，1
D 0，0，1
注解：
1字节     uint8_t
2字节     uint16_t
4字节     uint32_t
8字节     uint64_t
因为value是4字节对齐，所以id占四个字节，value占4个字节，timestamp占8个字节
小端，id为1 value为0 timpstamp为0
#endif