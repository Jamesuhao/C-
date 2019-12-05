#include<stdio.h>
#include<stdlib.h>
#include"All.h"
#include<iostream>
using namespace std;

int main()
{
	My_Node mylist;
	My_Job myjob;
	Al_Size al;
	Init_List(&mylist);
	Choose_Alg(&mylist, myjob, al);
}