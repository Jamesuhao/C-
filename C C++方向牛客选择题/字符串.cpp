#if 0
#1
�� 32 λ�������ϣ����ж���
char* str1 = "Hello", str2[] = "Hello"; ��
��������� printf("%d %d", sizeof(str1), sizeof(str2)); ���������ǣ�4��6��
ע�⣺str1��һ��ָ�룬32λƽ̨���κ����͵�ָ���Ϊ4���ֽڣ�64λΪ8���ֽڣ�
          str2Ϊһ���ӷ����飬sizeof���ַ�������ʱ����'\0'��

#2
���³�������н���ǣ�B��
int main(void)
{
	printf("%s , %5.3s\n", "computer", "computer");
	return 0;
}
A computer, puter
B computer, com
C computer, computer
D computer, compu.ter
ע�⣺
% m.ns ���ռm�У���ֻȡ�ַ��������n���ַ�����n���ַ������m�е��Ҳ࣬�󲹿ո�
%ms���ռm�У�����ַ������ȱ��趨���ȴ�Ͱ��ַ���ʵ�ʳ������
                           ����ַ������ȱ��趨����С�Ͱ��Ҷ�������ַ�������˲�0

#3���г���Ĵ�ӡ����� (D)
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
E ���г���
ע�⣺
strcat�����Ĺ����Ǵӵڶ���������ָ����ַ���λ�ÿ�ʼƴ�ӵ���һ��������ָ����ַ�����λ�ô��������ص�һ��������ָ����ַ�����λ�á�

#4ִ��������������Ϊ(A)
int I = 1;
if (I <= 0)
printf("****\n");
else
printf("%%%%\n");
A % %
B ****
C ���﷨��������ȷִ��
D %%%%
ע�⣺
%��һ��ת���ַ���%%�൱��һ��%����/ͬ��

#5���³����������Ϊ��D
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
ע�⣺
1.default��switch��ͷ��
��1��������case����������������ִ��default����ִ��default���֮���case��䣬ֱ��break�������
��2������case���㣬��ִ������case�Լ�case�������case�Լ�default,ֱ��break������
2.default��switch�м䣺������case��������������ͬ�ϣ�ֱ��ִ��default��䣬��ִ��default���֮���case��䣬ֱ��break����� 
3.default��switchĩβ��������case��䶼��������������ִ��default��䣬����������case���㣬��ִ��case���ֱ������break��switch������

#endif


