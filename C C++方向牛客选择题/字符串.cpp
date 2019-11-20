#if 0
#1
在 32 位编译器上，设有定义
char* str1 = "Hello", str2[] = "Hello"; ，
则以下语句 printf("%d %d", sizeof(str1), sizeof(str2)); 的输出结果是（4，6）
注解：str1是一个指针，32位平台下任何类型的指针均为4个字节，64位为8个字节；
          str2为一个子符数组，sizeof求字符串长度时包含'\0'。

#2
以下程序的运行结果是（B）
int main(void)
{
	printf("%s , %5.3s\n", "computer", "computer");
	return 0;
}
A computer, puter
B computer, com
C computer, computer
D computer, compu.ter
注解：
% m.ns 输出占m列，但只取字符串中左端n个字符。这n个字符输出在m列的右侧，左补空格。
%ms输出占m列，如果字符串长度比设定长度大就按字符串实际长度输出
                           如果字符串长度比设定长度小就按右对齐输出字符串，左端补0

#3下列程序的打印结果是 (D)
int main()
{
	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s", str);
}
A xyabcAB
B abcABz
C ABabcz
D xycdBCD
E 运行出错
注解：
strcat函数的功能是从第二个参数所指向的字符串位置开始拼接到第一个参数所指向的字符串的位置处，并返回第一个参数所指向的字符串的位置。

#4执行下面语句后的输出为(A)
int I = 1;
if (I <= 0)
printf("****\n");
else
printf("%%%%\n");
A % %
B ****
C 有语法错，不能正确执行
D %%%%
注解：
%是一个转义字符，%%相当于一个%，与/同理。

#5以下程序的输出结果为：D
#include <iostream.h>
void main()
{
	int x = 3, y = 3;
	switch (x % 2) 
	{
	case 1:
		switch (y)
		{
		case 0:cout << "first";
		case 1:cout << "second"; break;
		default: cout << "hello";
		}
	case 2:cout << "third";
	}
}
A second third
B hello
C first second
D hellothird
注解：
1.default在switch开头：
（1）若所有case都不满足条件，则执行default，并执行default语句之后的case语句，直到break或结束，
（2）若有case满足，则执行满足case以及case后的所有case以及default,直到break结束。
2.default在switch中间：若所有case都不满足条件，同上，直接执行default语句，并执行default语句之后的case语句，直到break或结束 
3.default在switch末尾：若所有case语句都不满足条件，则执行default语句，结束；若有case满足，则执行case语句直到遇到break或switch语句结束

#endif


