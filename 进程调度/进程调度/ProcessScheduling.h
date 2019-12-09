#pragma once
#include<stdio.h>

typedef struct Process
{
	int num;//进程编号
	int Arrive;//到达时间
	int Serivece;//服务时间
	int Complete;//完成时间
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

