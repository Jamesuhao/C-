#if 0
#1
��������˵���Ͷ�����䣺
union uti{ int n; double g; char ch[9]; } struct srt { float xy; union uti uv; }aa; 
�����ڴ���룬�����aa��ռ�ڴ���ֽ�����(24)��
ע�⣺����int��float��4�ֽڣ�double��8�ֽڣ�char��1�ֽڡ� 
union����������Ա����ռ䣬Ӧ����char��9�ݣ�ռ9�ֽڣ�Ȼ����8�ֽ�Ϊ��λ���룬����utiʵ��ռ16�ֽڡ� 
struct srt�У�����4 + 16��20�ֽڣ�ͬ����8�ֽڶ��룬����Ӧ����24

#2��32λcpu��ѡ��ȱʡ���������£������½ṹ�嶨�壺
struct A {
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};
��sizeof��struct A����ֵΪ��16��
ע�⣺
��Ϊλ�Σ�a��b��ռ31��bitλ������a��b��ռ4���ֽڣ�
b��c֮�ʹ���32��bitλ������b��c��ռ4���ֽڣ�indexΪchar���ͣ�1�ֽڶ��룬ռһ���ֽڣ�
����4�ֽڶ��룬��ռ16���ֽ�

#3���������ṹ�壬��#pragma pack(4)��#pragma pack(8)������£��ṹ��Ĵ�С�ֱ���(16,16,16,24)
struct One {
	double d;
	char c;
	int i;
}
struct Two {
	char c;
	double d;
	int i;
ע�⣺
#pragma pack(4):
One   0~7 8 12~15     8�ֽڶ���   ��16���ֽ�
Two   1 4~11 12~15   8�ֽڶ���   ��16���ֽ�
#pragma pack(8)
One   0~7 8 12~15     8�ֽڶ���  ��16���ֽ�
Two   1 8~15 16~19   8�ֽڶ���  ��24���ֽ�

#4��һ�����½ṹ�壬������64λ����������sizeof(struct A)������Ĵ�С�Ƕ��٣�(24)
struct A {
	long a1;
	short a2;
	int a3;
	int* a4;
};
ע�⣺
64λ��������
ָ�룺8���ֽ�
long��8���ֽ�
unsigned long��8���ֽ�
32λ�������£�
ָ�룺4���ֽ�
long��4���ֽ�
unsigned long��4���ֽ�
a1:0~7 a2:8~11 a3:12~15 a4:16~19 8�ֽڶ��룺��ռ24���ֽ�

#4��һ��64λ����ϵͳ�£������½ṹ�壬����fool()�����ִ�н��Ϊ��A��
struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}
A 1��0��0
B 1��1��0
C 0��1��1
D 0��0��1
ע�⣺
1�ֽ�     uint8_t
2�ֽ�     uint16_t
4�ֽ�     uint32_t
8�ֽ�     uint64_t
��Ϊvalue��4�ֽڶ��룬����idռ�ĸ��ֽڣ�valueռ4���ֽڣ�timestampռ8���ֽ�
С�ˣ�idΪ1 valueΪ0 timpstampΪ0
#endif