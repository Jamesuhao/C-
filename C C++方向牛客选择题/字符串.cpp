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
#3

#endif
#include<iostream>
using namespace std;

int main()
{

}