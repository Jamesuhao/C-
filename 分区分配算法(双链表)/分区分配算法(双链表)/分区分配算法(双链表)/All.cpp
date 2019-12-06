#include<stdio.h>
#include<stdlib.h>
#include"All.h"
#include<iostream>
using namespace std;

//ѡ���㷨
void Choose_Alg(My_Node *mylist,My_Job &job,Al_Size &al)
{
	int choose = 0;
	printf("**************��ѡ��**************\n\n");
	printf("1�������Ӧ�㷨(BF)\n");
	printf("2�����Ӧ�㷨(WF)\n");
	printf("3���״���Ӧ�㷨(FF)\n");
	printf("4��ѭ���״���Ӧ�㷨(NF)\n");
	printf("0���˳�\n");
	printf("\n�����룺");
	cin >> choose;
	switch (choose)
	{
		case 0:
			printf("���Ѿ�ѡ���˳���\n\n");
			break;
		//�����Ӧ�㷨
		case 1:
			My_BF(mylist,job,al,0);
			break;
		//���Ӧ�㷨
		case 2:
			My_WF(mylist,job,al,0);
			break;
		//�״���Ӧ�㷨
		case 3:
			My_FF(mylist, job, al,0);
			break;
		//ѭ���״���Ӧ�㷨
		case 4:
			My_NF(mylist, mylist,job, al, 0);
			break;
	default:
		//�������
		printf("\nInput Error!  Please input again!\n");
		//��������
		Choose_Alg(mylist,job,al);
		break;
	}
}
//���շ���
void Choose_Free(My_Node *mylist,My_Job &job,Al_Size &al)
{
	int choose = 0;
	printf("\t\t**************��ѡ��**************\n\n");
	printf("\t\t1��������һ����ҵ�����ڴ�\n");
	printf("\t\t2������Ϊ��ҵ�����ڴ�\n");
	printf("\t\t0���˳�\n");
	printf("\n�����룺");
	cin >> choose;
	switch (choose)
	{
		case 0:
			printf("���Ѿ�ѡ���˳���\n\n");
			break;
		//������һ����ҵ�����ڴ�
		case 1:
			Free(mylist,job,al);
			break;
		//���������ڴ�
		case 2:
			Choose_Alg(mylist,job,al);
			break;
		default:
			printf("\nInput Error!  Please input again!\n");
			Choose_Alg(mylist,job,al);
			break;
	}
}
//��ʼ������
void Init_List(My_Node *mylist)
{
	if(mylist == NULL) return;
	mylist->next = mylist;
	mylist->Empty_Size.Size = -1;
}
//��������
void Input_EmptyTable(My_Node *mylist)
{
	int x = 0;
	My_Node *p = mylist;
	My_Node *n = mylist->next;	
	printf("���������������");
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		//����ռ�
		n = (My_Node*)malloc(sizeof(My_Node));
		//����ռ����ʧ�ܣ�ֱ�ӷ���
		if (n == NULL)
		{
			return;
		}
		printf("\n�������%d���հ׷�������ʼ��ַ��������С��", i);
		cin >> n->Empty_Size.Start_Add >> n->Empty_Size.Size;
		n->Empty_Size.Num = i;
		n->Empty_Size.status = true;
		n->next = mylist;
		p->next = n;
		p = p->next;
	}
}
//������ҵ
void Get_Job(My_Job &job)
{
	printf("\n��������ҵ������ҵ��С��");
	cin >> job.Process_Name >> job.Mem_Size;
	printf("\n��ҵ����%c  ��ҵ��С��%d\n\n",job.Process_Name,job.Mem_Size);
}
//�����Ӧ�㷨��������С��С��������
void Sort_BF(My_Node *mylist)
{
	My_Node *p = mylist;
	My_Node *end = mylist;
	while(mylist->next != end)
	{
		while(p->next != end)
		{
			//��ǰ������СС�ں�̷�����Сʱ����������
			if(p->Empty_Size.Size > p->next->Empty_Size.Size)
			{
				//tmp:���浱ǰ������С
				int tmp1 = p->Empty_Size.Size;
				//tmp2�����浱ǰ������ʼ��ַ
				int tmp2 = p->Empty_Size.Start_Add;
				//��ʼ����
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

//�����Ӧ�㷨
void My_BF(My_Node* mylist, My_Job& job, Al_Size& al, int flag)
{
	if (flag==0)
	{
		Input_EmptyTable(mylist);
	}
	Sort_BF(mylist);
	Get_Job(job);
	printf("����ǰ�Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("����ǰ�Ŀհ׷�������\n");
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
	printf("�����Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("�����Ŀհ׷�������\n");
	Show(mylist);
	printf("\t\t**************��ѡ��**************\n\n");
	printf("\t\t0���˳�\n");
	printf("\t\t1������Ϊ��ҵ�����ڴ�\n");
	printf("\t\t2������ѡ���㷨\n");
	printf("\t\t3��������һ����ҵ���ڴ�\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("���Ѿ�ѡ���˳���\n\n");
		break;
		//����Ϊ��ҵ�����ڴ�
	case 1:
		My_BF(mylist, job, al,1);
		break;
		//����ѡ���㷨
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

//���Ӧ�㷨��������С�ɴ�С����
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
				//tmp:���浱ǰ������С
				int tmp1 = p->Empty_Size.Size;
				//tmp2�����浱ǰ������ʼ��ַ
				int tmp2 = p->Empty_Size.Start_Add;
				//��ʼ����
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

//���Ӧ�㷨
void My_WF(My_Node *mylist,My_Job &job,Al_Size &al,int flag)
{
	if (flag == 0)
	{
		Input_EmptyTable(mylist);
	}
	Sort_WF(mylist);
	Get_Job(job);
	printf("����ǰ�Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("����ǰ�Ŀհ׷�������\n");
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
	printf("�����Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("�����Ŀհ׷�������\n");
	Show(mylist);
	printf("\t\t**************��ѡ��**************\n\n");
	printf("\t\t1������Ϊ��ҵ�����ڴ�\n");
	printf("\t\t2������ѡ���㷨\n");
	printf("\t\t3��������һ����ҵ���ڴ�\n");
	printf("\t\t0���˳�\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("���Ѿ�ѡ���˳���\n\n");
		break;
		//����Ϊ��ҵ�����ڴ�
	case 1:
		My_WF(mylist, job, al, 1);
		break;
		//����ѡ���㷨
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

//�״���Ӧ�㷨����ַ��������
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
				//��ʼ����
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
//�״���Ӧ�㷨
void My_FF(My_Node* mylist, My_Job& job, Al_Size& al,int flag)
{
	if (flag == 0)
	{
		Input_EmptyTable(mylist);
		Sort(mylist);
	}
	Get_Job(job);
	printf("����ǰ�Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("����ǰ�Ŀհ׷�������\n");
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
	printf("�����Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("�����Ŀհ׷�������\n");
	Show(mylist);
	printf("\t\t\t**************��ѡ��**************\n\n");
	printf("\t\t1������Ϊ��ҵ�����ڴ�\n");
	printf("\t\t2������ѡ���㷨\n");
	printf("\t\t3��������һ����ҵ���ڴ�\n");
	printf("\t\t0���˳�\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("���Ѿ�ѡ���˳���\n\n");
		break;
		//����Ϊ��ҵ�����ڴ�
	case 1:
		My_FF(mylist, job, al, 1);
		break;
		//����ѡ���㷨
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
//�״�ѭ����Ӧ�㷨
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
	printf("����ǰ�Ŀհ׷�����\n");
	Print_EmptyTable(mylist);
	printf("����ǰ�Ŀհ׷�������\n");
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
		printf("����������ҵ��С�ķ�����\n");
		p = q;
	}
	else
	{
		printf("�����Ŀհ׷�����\n");
		Print_EmptyTable(mylist);
		printf("�����Ŀհ׷�������\n");
		Show(mylist);
	}
	printf("\t\t\t**************��ѡ��**************\n\n");
	printf("\t\t1������Ϊ��ҵ�����ڴ�\n");
	printf("\t\t2������ѡ���㷨\n");
	printf("\t\t3��������һ����ҵ���ڴ�\n");
	printf("\t\t0���˳�\n");
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		printf("���Ѿ�ѡ���˳���\n\n");
		break;
		//����Ϊ��ҵ�����ڴ�
	case 1:
		My_NF(mylist,p, job, al, 1);
		break;
		//����ѡ���㷨
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

//����
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
//���������
void Print_EmptyTable(My_Node *mylist)
{
	My_Node *p = mylist->next;
	printf("\t\t����\t��С\t��ַ\n");
	while(p != mylist)
	{
		if (p->Empty_Size.Size != 0)
		{
			printf("\t\t%d\t%d\t%d\n", p->Empty_Size.Num, p->Empty_Size.Size, p->Empty_Size.Start_Add);
		}
		p = p->next;
	}
}
//���������
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