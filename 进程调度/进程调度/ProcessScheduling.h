#pragma once
#include<stdio.h>

typedef struct Process
{
	int num;//���̱��
	int Arrive;//����ʱ��
	int Serivece;//����ʱ��
	int Complete;//���ʱ��
}Process;
typedef struct Node
{
	Process process;
	Node* next;
}Node;
void choose_Alg(Node* mylist);
void Init(Node* mylist);
void Input_Process(Node* mylist);
Node* copy(Node* mylist);
void Sort(Node* mylist);
void FCFS(Node* mylist);
void SJF(Node* mylist);
void RR(Node* mylist);
void Print(Node* mylist);

