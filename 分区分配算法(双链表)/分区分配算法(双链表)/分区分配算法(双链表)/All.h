#include<stdio.h>
#define MAX_ADDR_NUM 4

typedef int ElemType;

//空闲分区
typedef struct Empty_Table
{
	ElemType Start_Add;//起始地址
	//ElemType End_Add;//结束地址
	ElemType Num;//空闲分区编号
	ElemType Size;//空闲分区大小
	bool status;//0空闲 1使用
}Empty_Table;
typedef struct Al_Size
{
	ElemType Start_Add;//起始地址
	ElemType Size;//空闲分区大小
}Al_Size;
//作业
typedef struct
{
	char Process_Name;//作业名
	ElemType Mem_Size;//作业大小
}My_Job;

typedef struct My_Node
{
	Empty_Table Empty_Size;
    My_Node *next;//后继
	My_Node *prev;
}My_Node;

void Choose_Alg(My_Node *mylist,My_Job &job,Al_Size &al);//选择算法
void Init_List(My_Node *mylist);//初始化链表
void Input_EmptyTable(My_Node *mylist);
void Print_EmptyTable(My_Node *mylist);
void Free(My_Node *mylist,My_Job &job,Al_Size &al);
void My_BF(My_Node *mylist,My_Job &job,Al_Size &al,int flag);
void My_WF(My_Node *mylist,My_Job &job,Al_Size &al,int flag);
void My_NF(My_Node *mylist,My_Node* p,My_Job &job,Al_Size &al,int flag);
void My_FF(My_Node* mylist, My_Job& job, Al_Size& al, int flag);
void Show(My_Node *mylist);
