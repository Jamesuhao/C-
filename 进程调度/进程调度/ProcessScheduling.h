#pragma once
#include<stdio.h>

typedef struct Process
{
	int num;//���̱��
	int Arrive;//����ʱ��
	int Serivece;//����ʱ��
	int Complete;//���ʱ��
	int serivece;
}Process;
typedef struct Node
{
	Process process;
	Node* next;
}Node;
void choose_Alg(Node* mylist,Node* m_mylist);
void Init(Node* mylist, Node* m_mylist);
void Input_Process(Node* mylist);
Node* copy(Node* mylist, Node* m_mylist);
void FCFS_Sort(Node* mylist);
void FCFS(Node* mylist, int flag, Node* m_mylist);
void SJF_Sort(Node* mylist);
void SJF(Node* mylist, int flag, Node* m_mylist);
void RR(Node* mylist, int flag, Node* m_mylist);
void Print(Node* mylist);

