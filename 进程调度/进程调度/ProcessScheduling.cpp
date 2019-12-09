#include"ProcessScheduling.h"
#include<iostream>
#include<vector>
using namespace std;

void choose_Alg(Node* mylist)
{
	cout << "**********���̵���**********" << endl;
	cout << "��ѡ���㷨:" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.FCFS(�ȵ��ȷ���)�㷨" << endl;
	cout << "2.SJF(����ҵ����)�㷨" << endl;
	cout << "3.RR(ʱ��Ƭ��ת)�㷨" << endl;
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "���Ѿ�ѡ���˳�" << endl;
		return;
	case 1:
		FCFS(mylist);
		break;
	case 2:
		SJF(mylist);
		break;
	case 3:
		RR(mylist);
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
	cout << "��������̸�����" << endl;
	cin >> x;
	for (int i = 0; i < x; ++i)
	{
		n = (Node*)malloc(sizeof(Node));
		if (n == nullptr)
		{
			return;
		}
		cout << "�������"<<i+1<<"�����̵ĵ���ʱ��ͷ���ʱ�䣺"<<endl;
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
//FCFS����ҵ����ʱ������
void Sort(Node* mylist)
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
				int tmp2 = p->process.Arrive;
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
void FCFS(Node* mylist)
{
	cout << "*****FSFC�����㷨*****" << endl;
	Input_Process(mylist);
	Node* q = copy(mylist); 
	Sort(mylist);
	Node* p = mylist->next;
	p->process.Complete = p->process.Arrive + p->process.Serivece;
	while (p->next)
	{
		p->next->process.Complete = p->next->process.Serivece + p->process.Complete;
		p = p->next;
	}
	Print(mylist);
	int choose;
	cout << "��ѡ���㷨��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.SJF(����ҵ����)�㷨" << endl;
	cout << "2.RR(ʱ��Ƭ��ת)�㷨" << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "���Ѿ�ѡ���˳�" << endl;
		return;
	case 1:
		SJF(q);
		break;
	case 2:
		RR(q);
		break;
	}
}
void SJF(Node* mylist)
{

}
void RR(Node* mylist)
{

}
void Print(Node* mylist)
{
	Node* p = mylist->next;
	printf(" ���̱��\t ����ʱ��\t ����ʱ��\t ���ʱ��\n");
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
