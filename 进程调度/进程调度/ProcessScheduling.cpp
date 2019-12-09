#include"ProcessScheduling.h"
#include<iostream>
#include<vector>
using namespace std;

void choose_Alg(Node* mylist)
{
	cout << "**********进程调度**********" << endl;
	cout << "请选择算法:" << endl;
	cout << "0.退出" << endl;
	cout << "1.FCFS(先到先服务)算法" << endl;
	cout << "2.SJF(短作业优先)算法" << endl;
	cout << "3.RR(时间片轮转)算法" << endl;
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "您已经选择退出" << endl;
		return;
	case 1:
		FCFS(mylist,0);
		break;
	case 2:
		SJF(mylist,0);
		break;
	case 3:
		RR(mylist,0);
		break;
	}
}
void Init(Node* mylist)
{
	if (mylist == nullptr)
	{
		return;
	}
	mylist->next = nullptr;
}
void Input_Process(Node* mylist)
{
	int x;
	Node* p = mylist;
	Node* n = mylist;
	cout << "请输入进程个数：" << endl;
	cin >> x;
	for (int i = 0; i < x; ++i)
	{
		n = (Node*)malloc(sizeof(Node));
		if (n == nullptr)
		{
			return;
		}
		cout << "请输入第"<<i+1<<"个进程的到达时间和服务时间："<<endl;
		cin >> n->process.Arrive >> n->process.Serivece;
		n->process.num = i+1;
		p->next = n;
		p = p->next;
		p->next = nullptr;
	}
}
Node* copy(Node* mylist)
{
	Node* p = mylist->next;
	Node* n = mylist;
	Node* q = mylist;
	Node* r = q;
	while (p)
	{
		n = (Node*)malloc(sizeof(Node));
		if (n == nullptr)
		{
			return nullptr;
		}
		n->process.num = p->process.num;
		n->process.Arrive = p->process.Arrive;
		n->process.Serivece = p->process.Serivece;
		p = p->next;
		q->next = n;
		q = q->next;
		q->next = nullptr;
	}
	return r;
}
//FCFS按作业到达时间排序
void FCFS_Sort(Node* mylist)
{
	Node* p = mylist->next;
	int flag1 = 1;
	while (flag1)
	{
		int flag2 = 0;
		while (p->next)
		{
			if (p->process.Arrive > p->next->process.Arrive)
			{
				flag2 = 1;
				int tmp1 = p->process.Arrive;
				int tmp2 = p->process.Serivece;
				int tmp3 = p->process.num;
				p->process.Arrive = p->next->process.Arrive;
				p->process.Serivece = p->next->process.Serivece;
				p->process.num = p->next->process.num;
				p->next->process.Arrive = tmp1;
				p->next->process.Serivece = tmp2;
				p->next->process.num = tmp3;
			}
			p = p->next;
		}
		if (flag2 == 0)
		{
			flag1 = 0;
		}
		p = mylist->next;
	}
}
void FCFS(Node* mylist,int flag)
{
	cout << "*****FSFC调度算法*****" << endl;
	if (flag == 0)
	{
		Input_Process(mylist);
	}
	Node* q = copy(mylist); 
	FCFS_Sort(mylist);
	Node* p = mylist->next;
	p->process.Complete = p->process.Arrive + p->process.Serivece;
	while (p->next)
	{
		p->next->process.Complete = p->next->process.Serivece + p->process.Complete;
		p = p->next;
	}
	Print(mylist);
	int choose;
	cout << "请选择算法：" << endl;
	cout << "0.退出" << endl;
	cout << "1.SJF(短作业优先)算法" << endl;
	cout << "2.RR(时间片轮转)算法" << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "您已经选择退出" << endl;
		return;
	case 1:
		SJF(q,1);
		break;
	case 2:
		RR(q,1);
		break;
	}
}
void SJF_Sort(Node* mylist)
{
	Node* p = mylist;
	int flag1 = 1;
	while (flag1)
	{
		int flag2 = 0;
		while (p->next)
		{
			if (p->process.Serivece > p->next->process.Serivece)
			{
				flag2 = 1;
				int temp1 = p->process.num;
				int temp2 = p->process.Arrive;
				int temp3 = p->process.Serivece;
				p->process.num = p->next->process.num;
				p->process.Arrive = p->next->process.Arrive;
				p->process.Serivece = p->next->process.Serivece;
				p->next->process.num = temp1;
				p->next->process.Arrive = temp2;
				p->next->process.Serivece = temp3;
			}
			p = p->next;
		}
		if (flag2 == 0)
		{
			flag1 = 0;
		}
		p = mylist;
	}
}
void SJF(Node* mylist,int flag)
{
	cout << "*****SJF调度算法*****" << endl;
	if (flag == 0)
	{
		Input_Process(mylist);
	}
	Node* q = copy(mylist);
	FCFS_Sort(mylist);
	Node* p = mylist->next;
	p->process.Complete = p->process.Arrive + p->process.Serivece;
	SJF_Sort(p->next);
	while (p->next)
	{
		p->next->process.Complete = p->process.Complete + p->next->process.Serivece;
		p = p->next;
	}
	Print(mylist);
	int choose;
	cout << "请选择算法：" << endl;
	cout << "0.退出" << endl;
	cout << "1.FCFS(短作业优先)算法" << endl;
	cout << "2.RR(时间片轮转)算法" << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "您已经选择退出" << endl;
		return;
	case 1:
		FCFS(q, 1);
		break;
	case 2:
		RR(q,1);
		break;
	}
}
void RR(Node* mylist,int flag)
{
	if (flag == 0)
	{
		Input_Process(mylist);
	}
	Node* q = copy(mylist);
	int Timeslice = 0;
	cout << "请输入时间片大小：" << endl;
	cin >> Timeslice;
	Print(mylist);
	int choose;
	cin >> choose;
	cout << "请选择算法：" << endl;
	cout << "0.退出" << endl;
	cout << "1.FCFS(短作业优先)算法" << endl;
	cout << "2.SJF(时间片轮转)算法" << endl;
	switch (choose)
	{
	case 0:
		cout << "您已经选择退出" << endl;
		return;
	case 1:
		FCFS(q, 1);
		break;
	case 2:
		SJF(q, 1);
		break;
	}
}
void Print(Node* mylist)
{
	Node* p = mylist->next;
	cout << "每个进程在该算法下的到达时间、服务时间、完成时间如下表所示：" << endl;
	printf(" 进程编号\t 到达时间\t 服务时间\t 完成时间\n");
	while (p)
	{
		printf("\t%d\t\t%d\t\t%d\t\t%d\n", p->process.num,p->process.Arrive,p->process.Serivece,p->process.Complete);
		p = p->next;
	}
}
int main()
{
	Node mylist;
	Init(&mylist);
	choose_Alg(&mylist);
	return 0;
}
