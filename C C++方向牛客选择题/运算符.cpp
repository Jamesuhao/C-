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
#endif 