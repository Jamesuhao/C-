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
#endif
#include<iostream>
using namespace std;

int main()
{
}