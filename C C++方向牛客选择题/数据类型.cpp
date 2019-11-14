#if 0
#1下面程序输出结果为：无限循环
#include <stdio.h>
int main()
{
	int i, n = 0;
	float x = 1, y1 = 2.1 / 1.9, y2 = 1.9 / 2.1;
	for (i = 1; i < 22; i++)
		x = x * y1;
	while (x != 1.0)
	{
		x = x * y2; n++;
	}
	printf("%d\n", n);
	return 0;
}
注解：浮点类型的数据是不能进行精确比较的。

#2以下关于 typedef 正确的描述是（A B D ）
用typedef可以定义各种类型名，但不能定义变量
用typedef只是将已存在的类型用一个新的名称代替
用typedef可以增加新类型
使用typedef便于程序的通用
注解：C++Primer中说到：使用关键字typedef可以定义类型别名。
         含有typedef的声明语句定义的不再是变量而是类型别名。
         使用类型别名可以让复杂的类型名字变得简单明了、易于理解和使用，还有助于程序员清楚地知道使用该类型的真是目的。
         还可以使用关键字using定义类型别名。

#3
#endif 