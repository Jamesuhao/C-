#if 0
#1����������н��Ϊ��Low����
void main()
{

	char c = ��a����

		if ('a' < c <= 'z') printf("Low��)��

		else printf("UP")��
}
ע�⣺��ϵ���������������

#2�����ĸ�ѡ��һ�����Խ�flag�ĵڶ���bit��0(A)
A flag &= ~2
B flag |= 2
C flag ^= 2
D flag >>= 2

#3����x = 9999������ֵΪ(A)
int func(int x) {
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);//������
}
	return count;
}
A 8
B 9
C 10
D 12
ע�⣺
�����ж�����1�ĸ�����Ϊ��λ��Ĵ���

#4�����ĸ��÷��ĸ��Ǵ����(C)
A int* a;
B extern const int array[256];  //extern�����ⲿ����
C const int& ra;//���ñ������븳��ֵ
D typedef void (*FUN)();

#5����func�Ķ������£����´�����vs��������Ϊ(D)
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
E ����ǿ����ֹ������
F �����������й�
ע�⣺�������ʱ���������Ǵ���������б�����ջ�ģ������ȶ�iִ�к���++,��ʱ�β�2����Ϊ0��iΪ1��
�ٶ�iִ��ǰ��++���β�1Ϊ2��
�������2��0��
#endif 