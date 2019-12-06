#include<stdio.h>
#define MAX_ADDR_NUM 4

typedef int ElemType;

//���з���
typedef struct Empty_Table
{
	ElemType Start_Add;//��ʼ��ַ
	//ElemType End_Add;//������ַ
	ElemType Num;//���з������
	ElemType Size;//���з�����С
	bool status;//0���� 1ʹ��
}Empty_Table;
typedef struct Al_Size
{
	ElemType Start_Add;//��ʼ��ַ
	ElemType Size;//���з�����С
}Al_Size;
//��ҵ
typedef struct
{
	char Process_Name;//��ҵ��
	ElemType Mem_Size;//��ҵ��С
}My_Job;

typedef struct My_Node
{
	Empty_Table Empty_Size;
    My_Node *next;//���
	My_Node *prev;
}My_Node;

void Choose_Alg(My_Node *mylist,My_Job &job,Al_Size &al);//ѡ���㷨
void Init_List(My_Node *mylist);//��ʼ������
void Input_EmptyTable(My_Node *mylist);
void Print_EmptyTable(My_Node *mylist);
void Free(My_Node *mylist,My_Job &job,Al_Size &al);
void My_BF(My_Node *mylist,My_Job &job,Al_Size &al,int flag);
void My_WF(My_Node *mylist,My_Job &job,Al_Size &al,int flag);
void My_NF(My_Node *mylist,My_Node* p,My_Job &job,Al_Size &al,int flag);
void My_FF(My_Node* mylist, My_Job& job, Al_Size& al, int flag);
void Show(My_Node *mylist);
