#if 0
#1
在 c++ 语言中，对函数参数默认值描述正确的是（D）
A 函数参数的默认值只能设定一个  //重载
B 一个函数的参数若有多个，则参数默认值的设定可以不连续  //必须从右向左依次给出默认值
C 函数参数必须设定默认值 
D 在设定了参数的默认值后，该参数后面定义的所有参数都必须设定默认值

#2当一个类对象的生命周期结束后，关于调用析构函数的描述正确的是:（C）???
A 如果派生类没有定义析构函数，则只调用基类的析构函数
B 如果基类没有定义析构函数，则只调用派生类的析构函数
C 先调用派生类的析构函数，后调用基类的析构函数
D 先调用基类的析构函数，后调用派生类的析构函数

#3关于内联函数说法错误的是:C
A 不是任何一个函数都可定义成内联函数
B 内联函数的函数体内不能含有复杂的结构控制语句
C 递归函数可以被用来作为内联函数 //内联函数只能是函数体简单、调用次数较多的函数
D 内联函数一般适合于只有1~5行语句的小函数

#4若要对data类中重载的加法运算符成员函数进行声明，下列选项中正确的是(A)
A Data operator+(Data);
B Data operator(Data); //没有运算符
C operator+(Data, Data);//没有返回值
D Data + (Data); //没有重载的关键字

#5有如下BigNumber类的函数，已知b1, b2是BigNumber的两个对象, 则下列表达式中错误的是 (D)???
BigNumber　operator + (BigNumber　b)
{
	return　BigNumber(n + b.n);
}
A 3 + 3
B b1 + 3
C b1 + b2
D 3 + b1

#6假定有类AB，有相应的构造函数定义，能正确执行
AB a(4), b(5), c[3], * p[2] = { &a,&b };
语句，请问执行完此语句后共调用该类的构造函数次数为(A)
A 5
B 4
C 3
D 9
注解：a(4),      1次
		  b(5),      1次
		  c[3],      3次
		  *p[2],    0次
因为*p[2]是一个指针数组，里面存储的是指针，不是对象，所以不调用构造函数。

#7下面的输出可能是什么？(C)
class Printer {
public:
	Printer(std::string name) { std::cout << name; }
};
class Container {
public:
	Container() : b("b"), a("a") {}
	Printer a;
	Printer b;
};
int main() {
	Container c;
	return 0;
}
A 可能是 "ab" 或 "ba"。 依赖于具体的实现
B 一直都是 "ba"
C 一直都是 "ab"
注解：
成员变量初始化顺序与其构造函数初始化列表中的顺序无关，是按照其在类中声明的顺序进行初始化的，所以先初始化Printer a，在初始化
Printer b;

#8以下函数中，和其他函数不属于一类的是(C)
A fwrite:       将数据块写入流
B putc:         将字符写入流
C pwrite:      与ios对象关联的单词表的索引。
D putchar:   输出字符
E getline:     输入字符串
F scanf:        输入格式化数据

#9下列代码试图打印数字1 - 9的全排列组合, 其中run函数中缺失的部分应该依次为：C  ？？？
#include "stdio.h"
#define N 9
int x[N];
int count = 0;
void dump() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}
void run(int n) {
	int i;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (i = ___; i < N; i++) {
		swap(___, i);
		run(n + 1);
		swap(___, i);
	}
}
int main() {
	int i;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0);
	printf("* Total: %d\n", count);
}
A n + 1, n, n + 1
B n + 1, n, n
C n, n, n
D n, n + 1, n + 1
E n + 1, n + 1, n + 1
F n, n, n + 1

#10若PAT是一个类，则程序运行时，语句“PAT(*ad)[3]; ”调用PAT的构造函数的次数是C
A 2
B 3
C 0
D 1
注解:ad是一个指针，指针不调用构造函数

#11代码生成阶段的主要任务是(C)
A 把高级语言翻译成机器语言
B 把高级语言翻译成汇编语言
C 把中间代码变换成依赖具体机器的目标代码
D 把汇编语言翻译成机器语言
注解：
源代码－－ > 预处理－－ > 编译－－ > 优化－－ > 汇编－－ > 链接-- > 可执行文件
汇编阶段把 汇编语言代码 / 中间代码 翻译成目标机器指令。对于被翻译系统处理的每一个C语言源程序，
都将最终经过这一处理而得到相应的目标文件。（代码生成阶段）
#endif
