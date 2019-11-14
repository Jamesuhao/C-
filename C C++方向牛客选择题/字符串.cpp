#if 0

#1
在 32 位编译器上，设有定义
char* str1 = "Hello", str2[] = "Hello"; ，
则以下语句 printf("%d %d", sizeof(str1), sizeof(str2)); 的输出结果是（4，6）
注解：str1是一个指针，32位平台下任何类型的指针均为4个字节，64位为8个字节；
          str2为一个子符数组，sizeof求字符串长度时包含'\0'。

#2


#3

#endif