#include<iostream>
#include<vector>
using namespace std;

//ProcessNum: ��ʾ���̸���
//ResourceNum: ��ʾ��Դ�������
int  ProcessNum, ResourceNum;
//���뺯�������о���ĳ�ʼ��
void  init(vector<int>& Avaliable, vector<vector<int>>& Max, vector<vector<int>>& Allocation, vector<vector<int>>& Need, vector<int>SS);
//���м��㷨
void BM(vector<int>& Avaliable,  vector<vector<int>>& Allocation, vector<vector<int>>& Need, vector<int>& SS);

//��ȫ���㷨
bool SM(vector<int>& Avaliable, vector<vector<int>>& Need, vector<vector<int>>& Allocation, vector<int>& SS);
//��ӡһά����
void Print1(vector<int>&vec);
//��ӡ��ά����
void Print2(vector<vector<int>>&vec);

//��ʼ������
void  init(vector<int>&Avaliable, vector<vector<int>>&Max, vector<vector<int>>&Allocation, vector<vector<int>>&Need,vector<int>SS)
{
	//��Avaliable������г�ʼ��
	printf("������ϵͳ��ǰ���ṩ��ÿһ����Դ�ĸ�����\n");
	for (int i = 0; i < ResourceNum; ++i)
	{
		cin >> Avaliable[i];
	}
	//��Allocation������г�ʼ��
	printf("������ÿһ�������ѷ��䵽ÿ����Դ�ĸ�����\n");
	for (int i = 0; i < ProcessNum; ++i)
	{
		for (int j = 0; j < ResourceNum; ++j)
		{
			cin >> Allocation[i][j];
		}
	}
	//��Need������г�ʼ��
	printf("������ÿһ����������ÿ����Դ�ĸ�����\n");
	for (int i = 0; i < ProcessNum; ++i)
	{
		for (int j = 0; j < ResourceNum; ++j)
		{
			cin >> Need[i][j];
		}
	}
	//Max���󣺱�ʾÿһ�����̶���ÿһ����Դ���������
	//Max[i][j]=Allocation[i][j]+Need[i][j]
	for (int i = 0; i < ProcessNum; ++i)
	{
		for (int j = 0; j < ResourceNum; ++j)
		{
			Max[i][j] = Allocation[i][j] + Need[i][j];
		}
	}
}
//���м��㷨
void BM(vector<int>&Avaliable, vector<vector<int>>&Allocation, vector<vector<int>>&Need, vector<int>& SS)
{
	cout << "���������������Դ�Ľ��̺ţ�";
	int num = 0, n = 0;
	cin >> num;
	cout << "���������������Դ�ĸ���" << endl;
	//Request���洢����i��������Դ����
	vector<int>Request(ResourceNum, 0);
	for (int i = 0; i < ResourceNum; ++i)
	{
		cin >> Request[i];
	}
	n = num - 1;
	cout << "�Է���ǰϵͳ���ṩ��ÿһ����Դ�ĸ�����" << endl;
	Print1(Avaliable);
	cout << "�Է���ǰÿһ�������ѷ��䵽ÿ����Դ�ĸ�����" << endl;
	Print2(Allocation);
	cout << "�Է���ǰÿһ����������ÿ����Դ�ĸ�����" << endl;
	Print2(Need);
	for (int i = 0; i < ResourceNum; ++i)
	{
		//1.����Request[i] <= Need[n][i]��ת2
		if (Request[i] <= Need[n][i])
		{
			//2.����Request[i] <= Avaliable[i]
			if (Request[i] <= Avaliable[i])
			{
				//�Է���
				Need[n][i] = Need[n][i] - Request[i];
				Allocation[n][i] = Allocation[n][i] + Request[i];
				Avaliable[i] = Avaliable[i] - Request[i];
			}
			//������2.Request[i] <= Avaliable[i]������
			else
			{
				cout << "������Դ�ݲ�������P"<<n<<"������Դ��Ҫ��"<<"P"<<n<<"�����ȴ�" << endl;
				for (int j = 0; j < i; ++j)
				{
					Need[n][j] = Need[n][j] + Request[j];
					Allocation[n][j] = Allocation[n][j] - Request[j];
					Avaliable[j] = Avaliable[j] + Request[j];
				}
				int choose = 0;
				cout << "��ѡ���ܣ�" << endl;
				cout << "1.�˳�" << endl;
				cout << "2.����������Դ����" << endl;
				cin >> choose;
				switch (choose)
				{
				case 1:
					cout << "���Ѿ�ѡ���˳���" << endl;
					return;
				case 2:
					BM(Avaliable, Allocation, Need, SS);
					break;
				}
			}
		}
		//������1.Request[i] <= Need[n][i]������
		else
		{
			cout << "������������Դ��������������Դ��" << endl;
			int choose = 0;
			cout << "��ѡ���ܣ�" << endl;
			cout << "1.�˳�" << endl;
			cout << "2.����������Դ����" << endl;
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "���Ѿ�ѡ���˳���" << endl;
				return;
			case 2:
				BM(Avaliable, Allocation, Need, SS);
				break;
			}
		}
	}
	cout << "�Է����ϵͳ���ṩ��ÿһ����Դ�ĸ�����" << endl;
	Print1(Avaliable);
	cout << "�Է����ÿһ�������ѷ��䵽ÿ����Դ�ĸ�����" << endl;
	Print2(Allocation);
	cout << "�Է����ÿһ����������ÿ����Դ�ĸ�����" << endl;
	Print2(Need);
	if (SM(Avaliable, Need, Allocation, SS))
	{
		cout << "��״̬���ǰ�ȫ�ģ����Է��䣬��״̬�µİ�ȫ����Ϊ��" << endl;
		for (int i = 0; i < ProcessNum; ++i)
		{
			cout << SS[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "��״̬���ǲ���ȫ�ģ����ܷ��䡣" << endl;
		for (int i = 0; i < ResourceNum; ++i)
		{
			//״̬����ȫ���黹��Դ
			Need[n][i] = Need[n][i] + Request[i];
			Allocation[n][i] = Allocation[n][i] - Request[i];
			Avaliable[i] = Avaliable[i] + Request[i];
		}
		cout << "ϵͳ��ǰ���ṩ��ÿһ����Դ�ĸ�����" << endl;
		Print1(Avaliable);
		cout << "ÿһ�������ѷ��䵽ÿ����Դ�ĸ�����" << endl;
		Print2(Allocation);
		cout << "ÿһ����������ÿ����Դ�ĸ�����" << endl;
		Print2(Need);
	}
	int choose = 0;
	cout << "��ѡ���ܣ�" << endl;
	cout << "1.�˳�" << endl;
	cout << "2.����������Դ����" << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "���Ѿ�ѡ���˳���" << endl;
		return;
	case 2:
		BM(Avaliable, Allocation, Need, SS);
		break;
	}
}
//��ȫ���㷨
bool SM(vector<int>&Avaliable, vector<vector<int>>&Need, vector<vector<int>>&Allocation,vector<int>&SS)
{
	vector<int>Work = Avaliable;
	vector<char>Finish(ProcessNum, 'F');
	//Security sequence--->SS ��ȫ����
	int i = 0, j = 0, s = 0;
	while (i < ProcessNum)
	{
		if (Finish[i] == 'F') 
		{
			//���������ͷ���Դ������ͷ��ʼɨ����̼���
			while (j < ResourceNum && Need[i][j] <= Work[j])
			{
				j++;
			}
			//��j=ResourceNum����ʾ��ǰ���������ÿһ����Դ�����㵱ǰϵͳ�ɷ������Դ
			if (j ==ResourceNum)
			{
				//�ͷŵ�ǰ������Դ
				for (int k = 0; k < ResourceNum; k++)
				{
					Work[k]  += Allocation[i][k];
				}
				Finish[i] = 'T'; //�����־λ��ΪT
				SS[s++] = i;  //���氲ȫ����
				i = -1; //��i��Ϊ-1����ͷ���¿�ʼ����
			}
		}
		j = 0; 
		i++;
	}
	//�������̼��ϣ�����н��̲����㣬����false
	for (int i = 0; i <ProcessNum; ++i)
	{
		if (Finish[i] == 'F')
		{
			return false;
		}
	}
	return true;     //����'true'����
}
//��ӡһά����
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
//��ӡ��ά����
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
	cout << "**********���м��㷨**********"<< endl;
	printf("��������̸����Լ���Դ��������");
	cin >> ProcessNum >> ResourceNum;
	vector<int>SS(ProcessNum, 0);//���氲ȫ����
	vector<int>Avaliable(ResourceNum, 0);//Avaliable����ʾĳ����Դ�Ŀ�����Ŀ
	vector<vector<int>>Max(ProcessNum, vector<int>(ResourceNum, 0));//��ʾĳ���̶���ĳ��Դ���������
	vector<vector<int>>Allocation(ProcessNum, vector<int>(ResourceNum, 0));//��ʾĳ�����ѷ���ĳ��Դ�ĸ���
	vector<vector<int>>Need(ProcessNum, vector<int>(ResourceNum, 0));//��ʾĳ��������ĳ��Դ�ĸ���
	init(Avaliable, Max, Allocation, Need,SS);//��ʼ������
	if (SM(Avaliable, Need, Allocation, SS))
	{
		cout << "��״̬���ǰ�ȫ�ģ����Է��䣬��״̬�µİ�ȫ����Ϊ��" << endl;
		for (int i = 0; i < ProcessNum; ++i)
		{
			cout << SS[i] << " ";
		}
		cout << endl;
		BM(Avaliable, Allocation, Need, SS);
	}
	else
	{
		cout << "��״̬���ǲ���ȫ�ģ����ܷ��䡣" << endl;
	}
	return;
}
int main()
{
	test();
	return 0;
}