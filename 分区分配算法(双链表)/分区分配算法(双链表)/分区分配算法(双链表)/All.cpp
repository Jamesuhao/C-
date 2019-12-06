#include<stdio.h>
#include<stdlib.h>
#include"All.h"
#include<iostream>
using namespace std;

//选择算法
void Choose_Alg(My_Node *mylist,My_Job &job,Al_Size &al)
{
	int choose = 0;
	printf("**************请选择**************\n\n");
	printf("1、最佳适应算法(BF)\n");
	printf("2、最坏适应算法(WF)\n");
	printf("3、首次适应算法(FF)\n");
	printf("4、循环首次适应算法(NF)\n");
	printf("0、退出\n");
	printf("\n请输入：");
	cin >> choose;
	switch (choose)
	{
		case 0:
			printf("你已经选择退出！\n\n");
			break;
		//最佳适应算法
		case 1:
			My_BF(mylist,job,al,0);
			break;
		//最坏适应算法
		case 2:
			My_WF(mylist,job,al,0);
			break;
		//首次适应算法
		case 3:
			My_FF(mylist, job, al,0);
			break;
		//循环首次适应算法
		case 4:
			My_NF(mylist, mylist,job, al, 0);
			break;
	default:
		//输入错误
		printf("\nInput Error!  Please input again!\n");
		//重新输入
		Choose_Alg(mylist,job,al);
		break;
	}
}
//回收分区
void Choose_Free(My_Node *mylist,My_Job &job,Al_Size &al)
{
	int choose = 0;
	printf("\t\t**************请选择**************\n\n");
	printf("\t\t1、回收上一道作业分配内存\n");
	printf("\t\t2、继续为作业分配内存\n");
	printf("\t\t0、退出\n");
	printf("\n请输入：");
	cin >> choose;
	switch (choose)
	{
		case 0:
			printf("你已经选择退出！\n\n");
			break;
		//回收上一道作业分配内存
		case 1:
			Free(mylist,job,al);
			break;
		//继续分配内存
		case 2:
			Choose_Alg(mylist,job,al);
			break;
		default:
			printf("\nInput Error!  Please input again!\n");
			Choose_Alg(mylist,job,al);
			break;
	}
}
//初始化链表
void Init_List(My_Node *mylist)
{
	if(mylist == NULL) return;
	mylist->next = mylist;
	mylist->Empty_Size.Size = -1;
}
//分区分配
void Input_EmptyTable(My_Node *mylist)
{
	int x = 0;
	My_Node *p = mylist;
	My_Node *n = mylist->next;	
	printf("请输入分区个数：");
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		//分配空间
		n = (My_Node*)malloc(sizeof(My_Node));
		//如果空间分配失败，直接返回
		if (n == NULL)
		{
			return;
		}
		printf("\n请输入第%d个空白分区的起始地址，分区大小：", i);
		cin >> n->Empty_Size.Start_Add >> n->Empty_Size.Size;
		n->Empty_Size.Num = i;
		n->Empty_Size.status = true;
		n->next = mylist;
		p->next = n;
		p = p->next;
	}
}
//输入作业
void Get_Job(My_Job &job)
{
	printf("\n请输入作业名和作业大小：");
	cin >> job.Process_Name >> job.Mem_Size;
	printf("\n作业名：%c  作业大小：%d\n\n",job.Process_Name,job.Mem_Size);
}
//最佳适应算法按分区大小由小到大排序
void Sort_BF(My_Node *mylist)
{
	My_Node *p = mylist;
	My_Node *end = mylist;
	while(mylist->next != end)
	{
		while(p->next != end)
		{
			//当前分区大小小于后继分区大小时，两个互换
			if(p->Empty_Size.Size > p->next->Empty_Size.Size)
			{
				//tmp:保存当前分区大小
				int tmp1 = p->Empty_Size.Size;
				//tmp2：保存当前分区起始地址
				int tmp2 = p->Empty_Size.Start_Add;
				//开始交换
				p->Empty_Size.Size = p->next->Empty_Size.Size;
				p->Empty_Size.Start_Add = p->next->Empty_Size.Start_Add;
				p->next->Empty_Size.Size = tmp1;
				p->next->Empty_Size.Start_Add = tmp2;
			
			}			
			p = p->next;
		}
		end  = p;
		p = mylist;
	}
}

//最佳适应算法
void My_BF(My_Node* mylist, My_Job& job, Al_Size& al, int flag)
{
	if (flag==0)
	{
		Input_EmptyTable(mylist);
	}
	Sort_BF(mylist);
	Get_Job(job);
	printf("分配前的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配前的空白分区链：\n");
	Show(mylist);
	My_Node *p = mylist->next;
	while(p != mylist)
	{
		if(p->Empty_Size.Size >= job.Mem_Size)
		{
			al.Start_Add = p->Empty_Size.Start_Add;
			al.Size = job.Mem_Size;
			p->Empty_Size.Size -= job.Mem_Size;
			p->Empty_Size.Start_Add += job.Mem_Size;
			break;
		}
		p = p->next;
	}
	printf("分配后的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配后的空白分区链：\n");
	Show(mylist);
	printf("\t\t**************请选择**************\n\n");
	printf("\t\t0、退出\n");
	printf("\t\t1、继续为作业分配内存\n");
	printf("\t\t2、重新选择算法\n");
	printf("\t\t3、回收上一道作业的内存\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("你已经选择退出！\n\n");
		break;
		//继续为作业分配内存
	case 1:
		My_BF(mylist, job, al,1);
		break;
		//重新选择算法
	case 2:
		Choose_Alg(mylist, job, al);
		break;
	case 3:
		Free(mylist, job, al);
	default:
		printf("\nInput Error!  Please input again!\n");
		Choose_Alg(mylist, job, al);
		break;
	}
}

//最坏适应算法按分区大小由大到小排序
void Sort_WF(My_Node *mylist)
{
	My_Node* p = mylist->next;
	My_Node *end = mylist;
	while(mylist->next != end)
	{
		while(p->next != end)
		{
			if(p->Empty_Size.Size < p->next->Empty_Size.Size)
			{
				//tmp:保存当前分区大小
				int tmp1 = p->Empty_Size.Size;
				//tmp2：保存当前分区起始地址
				int tmp2 = p->Empty_Size.Start_Add;
				//开始交换
				p->Empty_Size.Size = p->next->Empty_Size.Size;
				p->Empty_Size.Start_Add = p->next->Empty_Size.Start_Add;
				p->next->Empty_Size.Size = tmp1;
				p->next->Empty_Size.Start_Add = tmp2;
			}			
			p = p->next;
		}
		end  = p;
		p = mylist->next;
	}
}

//最坏适应算法
void My_WF(My_Node *mylist,My_Job &job,Al_Size &al,int flag)
{
	if (flag == 0)
	{
		Input_EmptyTable(mylist);
	}
	Sort_WF(mylist);
	Get_Job(job);
	printf("分配前的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配前的空白分区链：\n");
	Show(mylist);
	My_Node *p = mylist->next;
	while(p != mylist)
	{
		if(p->Empty_Size.Size >= job.Mem_Size)
		{
			al.Start_Add = p->Empty_Size.Start_Add;
			al.Size = job.Mem_Size;
			p->Empty_Size.Size -= job.Mem_Size;
			p->Empty_Size.Start_Add += job.Mem_Size;
			break;
		}
		p = p->next;
	}
	printf("分配后的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配后的空白分区链：\n");
	Show(mylist);
	printf("\t\t**************请选择**************\n\n");
	printf("\t\t1、继续为作业分配内存\n");
	printf("\t\t2、重新选择算法\n");
	printf("\t\t3、回收上一道作业的内存\n");
	printf("\t\t0、退出\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("你已经选择退出！\n\n");
		break;
		//继续为作业分配内存
	case 1:
		My_WF(mylist, job, al, 1);
		break;
		//重新选择算法
	case 2:
		Choose_Alg(mylist, job, al);
		break;
	case 3:
		Free(mylist, job, al);
	default:
		printf("\nInput Error!  Please input again!\n");
		Choose_Alg(mylist, job, al);
		break;
	}
}

//首次适应算法按地址递增排序
void Sort(My_Node* mylist)
{
	My_Node* p = mylist->next;
	My_Node* end = mylist;
	while (mylist->next != end)
	{
		while (p->next != end)
		{
			if (p->Empty_Size.Start_Add > p->next->Empty_Size.Start_Add)
			{
				int tmp1 = p->Empty_Size.Size;
				int tmp2 = p->Empty_Size.Start_Add;
				//开始交换
				p->Empty_Size.Size = p->next->Empty_Size.Size;
				p->Empty_Size.Start_Add = p->next->Empty_Size.Start_Add;
				p->next->Empty_Size.Size = tmp1;
				p->next->Empty_Size.Start_Add = tmp2;
			}
			p = p->next;
		}
		end = p;
		p = mylist->next;
	}
}
//首次适应算法
void My_FF(My_Node* mylist, My_Job& job, Al_Size& al,int flag)
{
	if (flag == 0)
	{
		Input_EmptyTable(mylist);
		Sort(mylist);
	}
	Get_Job(job);
	printf("分配前的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配前的空白分区链：\n");
	Show(mylist);
	My_Node* p = mylist->next;
	while (p != mylist)
	{
		if (p->Empty_Size.Size >= job.Mem_Size)
		{
			al.Start_Add = p->Empty_Size.Start_Add;
			al.Size = job.Mem_Size;
			p->Empty_Size.Size -= job.Mem_Size;
			p->Empty_Size.Start_Add += job.Mem_Size;
			p = p->next;
			break;
		}
		p = p->next;
	}
	printf("分配后的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配后的空白分区链：\n");
	Show(mylist);
	printf("\t\t\t**************请选择**************\n\n");
	printf("\t\t1、继续为作业分配内存\n");
	printf("\t\t2、重新选择算法\n");
	printf("\t\t3、回收上一道作业的内存\n");
	printf("\t\t0、退出\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("你已经选择退出！\n\n");
		break;
		//继续为作业分配内存
	case 1:
		My_FF(mylist, job, al, 1);
		break;
		//重新选择算法
	case 2:
		Choose_Alg(mylist, job, al);
		break;
	case 3:
		Free(mylist, job, al);
	default:
		printf("\nInput Error!  Please input again!\n");
		Choose_Alg(mylist, job, al);
		break;
	}
}
//首次循环适应算法
void My_NF(My_Node *mylist, My_Node* p, My_Job &job,Al_Size &al,int flag)
{
	if (flag == 0)
	{
		Input_EmptyTable(mylist);
		Sort(mylist);
		p = mylist->next;
	}
	My_Node* q = p;
	Get_Job(job);
	printf("分配前的空白分区表：\n");
	Print_EmptyTable(mylist);
	printf("分配前的空白分区链：\n");
	Show(mylist);
	int count = 0;
	while(p->next != q)
	{
		
		if(p->Empty_Size.Size >= job.Mem_Size)
		{
			al.Start_Add = p->Empty_Size.Start_Add;
			al.Size = job.Mem_Size;
			p->Empty_Size.Size -= job.Mem_Size;
			p->Empty_Size.Start_Add += job.Mem_Size;
			p = p->next;
			count++;
			break;
		}
		p = p->next;
	}
	if (!count)
	{
		printf("暂无满足作业大小的分区！\n");
		p = q;
	}
	else
	{
		printf("分配后的空白分区表：\n");
		Print_EmptyTable(mylist);
		printf("分配后的空白分区链：\n");
		Show(mylist);
	}
	printf("\t\t\t**************请选择**************\n\n");
	printf("\t\t1、继续为作业分配内存\n");
	printf("\t\t2、重新选择算法\n");
	printf("\t\t3、回收上一道作业的内存\n");
	printf("\t\t0、退出\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("你已经选择退出！\n\n");
		break;
		//继续为作业分配内存
	case 1:
		My_NF(mylist,p, job, al, 1);
		break;
		//重新选择算法
	case 2:
		Choose_Alg(mylist, job, al);
		break;
	case 3:
		Free(mylist, job, al);
	default:
		printf("\nInput Error!  Please input again!\n");
		Choose_Alg(mylist, job, al);
		break;
	}
}

//回收
void Free(My_Node *mylist,My_Job &job,Al_Size &al)
{
	My_Node *p = mylist->next;
	while(p != mylist)
	{
		if(al.Start_Add == (p->Empty_Size.Start_Add - al.Size))
		{
			p->Empty_Size.Size += al.Size;
			p->Empty_Size.Start_Add -= al.Size;
		}
		p = p->next;
	}
	Print_EmptyTable(mylist);
}
//输出分区表
void Print_EmptyTable(My_Node *mylist)
{
	My_Node *p = mylist->next;
	printf("\t\t区号\t大小\t起址\n");
	while(p != mylist)
	{
		if (p->Empty_Size.Size != 0)
		{
			printf("\t\t%d\t%d\t%d\n", p->Empty_Size.Num, p->Empty_Size.Size, p->Empty_Size.Start_Add);
		}
		p = p->next;
	}
}
//输出分区链
void Show(My_Node *mylist)
{
	My_Node *p = mylist->next;
	while(p != mylist)
	{		
		if (p->Empty_Size.Size != 0)
		{
			printf("%d", p->Empty_Size.Size);
			if (p->next != mylist)
				printf("--->");
		}
		p = p->next;
	}
	printf("\n");
}