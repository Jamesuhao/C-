#if 0
#1
若有以下说明和定义语句：
union uti{ int n; double g; char ch[9]; } struct srt { float xy; union uti uv; }aa; 
考虑内存对齐，则变量aa所占内存的字节数是(24)
注解：首先int，float是4字节，double是8字节，char是1字节。 
union里面以最大成员计算空间，应该是char［9］，占9字节，然后以8字节为单位对齐，所以uti实际占16字节。 
struct srt中，就是4 + 16＝20字节，同样以8字节对齐，所以应该是24
#endif