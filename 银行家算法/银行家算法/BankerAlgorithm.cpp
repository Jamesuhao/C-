#include<iostream>
#include<vector>
using namespace std;

//ProcessNum: 表示进程个数
//ResourceNum: 表示资源种类个数
int  ProcessNum, ResourceNum;
//输入函数：进行矩阵的初始化
void  init(vector<int>& Avaliable, vector<vector<int>>& Max, vector<vector<int>>& Allocation, vector<vector<int>>& Need, vector<int>SS);
//银行家算法
void BM(vector<int>& Avaliable,  vector<vector<int>>& Allocation, vector<vector<int>>& Need, vector<int>& SS);

//安全性算法
bool SM(vector<int>& Avaliable, vector<vector<int>>& Need, vector<vector<int>>& Allocation, vector<int>& SS);
//打印一维矩阵
void Print1(vector<int>&vec);
//打印二维矩阵
void Print2(vector<vector<int>>&vec);

//初始化矩阵
void  init(vector<int>&Avaliable, vector<vector<int>>&Max, vector<vector<int>>&Allocation, vector<vector<int>>&Need,vector<int>SS)
{
	//对Avaliable矩阵进行初始化
	printf("请输入系统当前可提供的每一类资源的个数：\n");
	for (int i = 0; i < ResourceNum; ++i)
	{
		cin >> Avaliable[i];
	}
	//对Allocation矩阵进行初始化
	printf("请输入每一个进程已分配到每类资源的个数：\n");
	for (int i = 0; i < ProcessNum; ++i)
	{
		for (int j = 0; j < ResourceNum; ++j)
		{
			cin >> Allocation[i][j];
		}
	}
	//对Need矩阵进行初始化
	printf("请输入每一个进程仍需每类资源的个数：\n");
	for (int i = 0; i < ProcessNum; ++i)
	{
		for (int j = 0; j < ResourceNum; ++j)
		{
			cin >> Need[i][j];
		}
	}
	//Max矩阵：表示每一个进程对于每一类资源的最大需求
	//Max[i][j]=Allocation[i][j]+Need[i][j]
	for (int i = 0; i < ProcessNum; ++i)
	{
		for (int j = 0; j < ResourceNum; ++j)
		{
			Max[i][j] = Allocation[i][j] + Need[i][j];
		}
	}
}
//银行家算法
void BM(vector<int>&Avaliable, vector<vector<int>>&Allocation, vector<vector<int>>&Need, vector<int>& SS)
{
	cout << "请输入请求分配资源的进程号：";
	int num = 0, n = 0;
	cin >> num;
	cout << "请输入所需各类资源的个数" << endl;
	//Request：存储进程i的请求资源序列
	vector<int>Request(ResourceNum, 0);
	for (int i = 0; i < ResourceNum; ++i)
	{
		cin >> Request[i];
	}
	n = num - 1;
	cout << "试分配前系统可提供的每一类资源的个数：" << endl;
	Print1(Avaliable);
	cout << "试分配前每一个进程已分配到每类资源的个数：" << endl;
	Print2(Allocation);
	cout << "试分配前每一个进程仍需每类资源的个数：" << endl;
	Print2(Need);
	for (int i = 0; i < ResourceNum; ++i)
	{
		//1.满足Request[i] <= Need[n][i]：转2
		if (Request[i] <= Need[n][i])
		{
			//2.满足Request[i] <= Avaliable[i]
			if (Request[i] <= Avaliable[i])
			{
				//试分配
				Need[n][i] = Need[n][i] - Request[i];
				Allocation[n][i] = Allocation[n][i] + Request[i];
				Avaliable[i] = Avaliable[i] - Request[i];
			}
			//不满足2.Request[i] <= Avaliable[i]：阻塞
			else
			{
				cout << "可用资源暂不能满足P"<<n<<"请求资源需要，"<<"P"<<n<<"阻塞等待" << endl;
				for (int j = 0; j < i; ++j)
				{
					Need[n][j] = Need[n][j] + Request[j];
					Allocation[n][j] = Allocation[n][j] - Request[j];
					Avaliable[j] = Avaliable[j] + Request[j];
				}
				int choose = 0;
				cout << "请选择功能：" << endl;
				cout << "1.退出" << endl;
				cout << "2.继续进行资源申请" << endl;
				cin >> choose;
				switch (choose)
				{
				case 1:
					cout << "您已经选择退出！" << endl;
					return;
				case 2:
					BM(Avaliable, Allocation, Need, SS);
					break;
				}
			}
		}
		//不满足1.Request[i] <= Need[n][i]：出错
		else
		{
			cout << "错误：所请求资源大于自身所需资源！" << endl;
			int choose = 0;
			cout << "请选择功能：" << endl;
			cout << "1.退出" << endl;
			cout << "2.继续进行资源申请" << endl;
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "您已经选择退出！" << endl;
				return;
			case 2:
				BM(Avaliable, Allocation, Need, SS);
				break;
			}
		}
	}
	cout << "试分配后系统可提供的每一类资源的个数：" << endl;
	Print1(Avaliable);
	cout << "试分配后每一个进程已分配到每类资源的个数：" << endl;
	Print2(Allocation);
	cout << "试分配后每一个进程仍需每类资源的个数：" << endl;
	Print2(Need);
	if (SM(Avaliable, Need, Allocation, SS))
	{
		cout << "该状态下是安全的，可以分配，该状态下的安全序列为：" << endl;
		for (int i = 0; i < ProcessNum; ++i)
		{
			cout << SS[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "该状态下是不安全的，不能分配。" << endl;
		for (int i = 0; i < ResourceNum; ++i)
		{
			//状态不安全，归还资源
			Need[n][i] = Need[n][i] + Request[i];
			Allocation[n][i] = Allocation[n][i] - Request[i];
			Avaliable[i] = Avaliable[i] + Request[i];
		}
		cout << "系统当前可提供的每一类资源的个数：" << endl;
		Print1(Avaliable);
		cout << "每一个进程已分配到每类资源的个数：" << endl;
		Print2(Allocation);
		cout << "每一个进程仍需每类资源的个数：" << endl;
		Print2(Need);
	}
	int choose = 0;
	cout << "请选择功能：" << endl;
	cout << "1.退出" << endl;
	cout << "2.继续进行资源申请" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "您已经选择退出！" << endl;
		return;
	case 2:
		BM(Avaliable, Allocation, Need, SS);
		break;
	}
}
//安全性算法
bool SM(vector<int>&Avaliable, vector<vector<int>>&Need, vector<vector<int>>&Allocation,vector<int>&SS)
{
	vector<int>Work = Avaliable;
	vector<char>Finish(ProcessNum, 'F');
	//Security sequence--->SS 安全序列
	int i = 0, j = 0, s = 0;
	while (i < ProcessNum)
	{
		if (Finish[i] == 'F') 
		{
			//满足条件释放资源，并从头开始扫描进程集合
			while (j < ResourceNum && Need[i][j] <= Work[j])
			{
				j++;
			}
			//当j=ResourceNum，表示当前进程所需的每一个资源都满足当前系统可分配的资源
			if (j ==ResourceNum)
			{
				//释放但前进程资源
				for (int k = 0; k < ResourceNum; k++)
				{
					Work[k]  += Allocation[i][k];
				}
				Finish[i] = 'T'; //将其标志位置为T
				SS[s++] = i;  //保存安全序列
				i = -1; //将i置为-1，从头重新开始遍历
			}
		}
		j = 0; 
		i++;
	}
	//遍历进程集合，如果有进程不满足，返回false
	for (int i = 0; i <ProcessNum; ++i)
	{
		if (Finish[i] == 'F')
		{
			return false;
		}
	}
	return true;     //返回'true'个数
}
//打印一维矩阵
void Print1(vector<int>&vec)
{
	for (int i = 0; i < ResourceNum; ++i)
	{
		cout << "    R" << i + 1;
	}
	cout << endl;
	for (int i = 0; i < ResourceNum; ++i)
	{
		cout << "     " << vec[i];
	}
	cout << endl;
}
//打印二维矩阵
void Print2(vector<vector<int>>&vec)
{
	for (int i = 0; i < ResourceNum; ++i)
	{
		cout << "    R" << i + 1;
	}
	cout << endl;
	for (int i = 0; i < ProcessNum; ++i)
	{
		cout << "P" << i ;
		for (int j = 0; j < ResourceNum; ++j)
		{
			cout << "   " << vec[i][j] << "  ";
		}
		cout << endl;
	}
}
void test()
{
	cout << "**********银行家算法**********"<< endl;
	printf("请输入进程个数以及资源种类数：");
	cin >> ProcessNum >> ResourceNum;
	vector<int>SS(ProcessNum, 0);//储存安全序列
	vector<int>Avaliable(ResourceNum, 0);//Avaliable：表示某类资源的可用数目
	vector<vector<int>>Max(ProcessNum, vector<int>(ResourceNum, 0));//表示某进程对于某资源的最大需求
	vector<vector<int>>Allocation(ProcessNum, vector<int>(ResourceNum, 0));//表示某进程已分配某资源的个数
	vector<vector<int>>Need(ProcessNum, vector<int>(ResourceNum, 0));//表示某进程尚需某资源的个数
	init(Avaliable, Max, Allocation, Need,SS);//初始化函数
	if (SM(Avaliable, Need, Allocation, SS))
	{
		cout << "该状态下是安全的，可以分配，该状态下的安全序列为：" << endl;
		for (int i = 0; i < ProcessNum; ++i)
		{
			cout << SS[i] << " ";
		}
		cout << endl;
		BM(Avaliable, Allocation, Need, SS);
	}
	else
	{
		cout << "该状态下是不安全的，不能分配。" << endl;
	}
	return;
}
int main()
{
	test();
	return 0;
}