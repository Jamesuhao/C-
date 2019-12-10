#include"ProcessScheduling.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void choose_Alg(Node* mylist, Node* m_mylist)
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
		FCFS(mylist,0,m_mylist);
		break;
	case 2:
		SJF(mylist,0, m_mylist);
		break;
	case 3:
		RR(mylist,0, m_mylist);
		break;
	}
}
void Init(Node* mylist, Node* m_mylist)
{
	if (mylist == nullptr||m_mylist==nullptr)
	{
		return;
	}
	mylist->next = nullptr;
	m_mylist->next = nullptr;
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
		n->process.Complete = 0;
		n->process.serivece = n->process.Serivece;
		p->next = n;
		p = p->next;
		p->next = nullptr;
	}
}
Node* copy(Node* mylist,Node* m_mylist)
{
	Node* p = mylist->next;
	Node* n;
	Node* q = m_mylist;
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
		n->process.Complete = p->process.Complete;
		n->process.serivece = p->process.serivece;
		p = p->next;
		q->next = n;
		q = q->next;
		q->next = nullptr;
	}
	return m_mylist;
}
//FCFS����ҵ����ʱ������
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
void FCFS(Node* mylist,int flag, Node* m_mylist)
{
	cout << "*****FSFC�����㷨*****" << endl;
	if (flag == 0)
	{
		Input_Process(mylist);
	}
	Node* q = copy(mylist,m_mylist);
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
	cout << "��ѡ���㷨��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.SJF(����ҵ����)�㷨" << endl;
	cout << "2.RR(ʱ��Ƭ��ת)�㷨" << endl;
	cout << "3.������������" << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "���Ѿ�ѡ���˳�" << endl;
		return;
	case 1:
		SJF(q,1,m_mylist);
		break;
	case 2:
		RR(q,1, m_mylist);
		break;
	case 3:
		choose_Alg(mylist, m_mylist);
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
void SJF(Node* mylist,int flag,Node* m_mylist)
{
	cout << "*****SJF�����㷨*****" << endl;
	if (flag == 0)
	{
		Input_Process(mylist);
	}
	Node* q = copy(mylist, m_mylist);
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
	cout << "��ѡ���㷨��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.FCFS(����ҵ����)�㷨" << endl;
	cout << "2.RR(ʱ��Ƭ��ת)�㷨" << endl;
	cout << "3.������������" << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "���Ѿ�ѡ���˳�" << endl;
		return;
	case 1:
		FCFS(q, 1, m_mylist);
		break;
	case 2:
		RR(q,1, m_mylist);
		break;
	case 3:
		choose_Alg(mylist, m_mylist);
		break;
	}
}
void RR(Node* mylist,int flag,Node* m_mylist)
{
	if (flag == 0)
	{
		Input_Process(mylist);
	}
	Node* q = copy(mylist, m_mylist);
	int Timeslice = 0;
	queue<Node*>que;
	cout << "������ʱ��Ƭ��С��" << endl;
	cin >> Timeslice;
	FCFS_Sort(mylist);
	Node* p = mylist->next;
	que.push(p);
	int count = 0;
	while (!que.empty())
	{
		//count:���н����ѷ����ʱ��
		//Timeslice:��ʾʱ��Ƭ
		que.front()->process.serivece = que.front()->process.serivece  - Timeslice;
		while (p->next != nullptr && p->next->process.Arrive <= (que.front()->process.Arrive + Timeslice + count))
		{
			que.push(p->next);
			p = p->next;
		}
		if (que.front()->process.serivece == -1)
		{
			count += 1;
		}
		else
		{
			count += 2;
		}
		if (que.front()->process.serivece <= 0)
		{
			que.front()->process.Complete += count;
			que.pop();
		}
		else
		{
			que.push(que.front());
			que.pop();
		}
	}
	Print(mylist);
	int choose=0;
	cout << "��ѡ���㷨��" << endl;
	cout << "0.�˳�" << endl;
	cout << "1.FCFS(����ҵ����)�㷨" << endl;
	cout << "2.SJF(ʱ��Ƭ��ת)�㷨" << endl;
	cout << "3.������������" << endl;
	cin >> choose;
	switch (choose)
	{
	case 0:
		cout << "���Ѿ�ѡ���˳�" << endl;
		return;
	case 1:
		FCFS(q, 1, m_mylist);
		break;
	case 2:
		SJF(q, 1, m_mylist);
		break;
	case 3:
		choose_Alg(mylist, m_mylist);
		break;
	}
}
void Print(Node* mylist)
{
	Node* p = mylist->next;
	cout << "ÿ�������ڸ��㷨�µĵ���ʱ�䡢����ʱ�䡢���ʱ�����±���ʾ��" << endl;
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
	Node m_mylist;
	Init(&mylist, &m_mylist);
	choose_Alg(&mylist,&m_mylist);
	return 0;
}
