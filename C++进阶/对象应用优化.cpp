#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//������Ż�
#if 0
//���󱳺���õĳ�Ա������
//ʾ��1��
class Test
{
public:
	Test(int ma=5, int mb=5) :_ma(ma), _mb(mb) { cout << "Test(int,int)" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test& t) :_ma(t._ma), _mb(t._mb) { cout << "Test(const Test&)" << endl; }
	Test& operator=(const Test& src)
	{
		_ma = src._ma;
		_mb = src._mb;
		cout << "operator=" << endl;
		return *this;
	}
private:
	int _ma;
	int _mb;
};
Test t1(10, 10);  //  1. Test(int,int) 
int main()
{
	Test t2(20, 20); //  3.Test(int,int)
	Test t3 = t2;  // 4. Test(const Test&)
	static Test t4 = Test(30, 30);  //5. Test(int,int)
	t2 = Test(40, 40);// 6. Test(int,int)->t2.operator=(Test&)->~Test()
	t2 = (Test)(50, 50);// 7. Test(int,int)->t2.operator(Test&)->~Test()
	t2 = 60;// 8. Test(int,int)->t2.operator=(Test&)->~Test()
	Test* p1 = new Test(70, 70);  //  9. Test(int,int)
	Test* p2 = new Test[2]; // 10. Test(int,int)  Test(int,int)
	Test* p3 = &Test(80, 90);  //  11.Test(int,int)  ~Test()
	const Test& p4 = Test(90, 90); //12. Test(int,int)
	delete p1;//  13.  ~Test()
	delete[]p2;// 14 .~Test() ~Test()
	return 0;
}
Test t5(100, 100);// 2. Test(int,int)
------------------------------------------------------------------
//ʾ��2
class Test
{
public:
	Test(int ma = 10) :_ma(ma) { cout << "Test(int)" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test& t) :_ma(t._ma) { cout << "Test(const Test&)" << endl; }
	Test& operator=(const Test& t)
	{
		cout << "operator=" << endl;
		_ma = t._ma;
		return *this;
	}
private:
	int _ma;
};
int main()
{
	Test t1;
	Test t2(t1);
	Test t3 = t1;
	//Test(20)����ʽ������ʱ����  �������ڣ����ڵ����
	/*
	C++���������ڶ�������Ż���
	����ʱ���������¶�����ʱ����Ͳ������ˣ�ֱ�ӹ����¶���Ϳ�����
	*/
	Test t4 = Test(20);  //  �ȼ���Test t4(20);
	cout << "-------------------------" << endl;

	t4 = t2;   //  t4.operator=(t2)
	//��ʽ������ʱ����
	t4 = Test(30);   //  t4.operator=(const Test &t)
	t4 = (Test)30;  //  int ->Test(int)  t4.operator=(Test(int))
	//��ʽʽ������ʱ����
	t4 = 30; // int ->Test(int)  t4.operator=(Test(int)) 
	cout << "-------------------------" << endl;
	Test* p = &Test(40); //����������䣬��ʱ����ͻᱻ�����ˣ�pָ�����һ���Ѿ�����������ʱ����
	const Test& ref = Test(50);
	cout << "-------------------------" << endl;

	return 0;
}  
//������ú���������õĳ�Ա����
//ʾ��1��
class Test
{
public:
	Test(int data = 10) :_ma(data) { cout << "Test(int)" << endl; }
	~Test() { cout << "~Test" << endl; }
	Test(const Test& t) :_ma(t._ma) { cout << "Test(const Test&" << endl; }
	void operator=(const Test& t)
	{
		cout << "operator=" << endl;
		_ma = t._ma;
	}
	int getData()const { return _ma;  }
private:
	int _ma;
};
//�˴����ܷ��ؾֲ�������ʱ�����ָ�������
Test GetObject(Test t)//3.Test(const Test&)
{
	int val = t.getData();
	Test tmp(val);//4.Test(int)
	return tmp;//5.Test(const Test&)
}
int main()
{
	Test t1;// 1. Test(int)
	Test t2;// 2. Test(int)
	t2 = GetObject(t1);
	return 0;
}
/*
�����Ż��Ĺ���
1.�����������ݹ����У��������������ô���(����һ��ʵ�� ->�βεĿ�������ĵ���������)����Ҫ��ֵ����
2.�������ض����ʱ��Ӧ�����ȷ���һ����ʱ���󣬶���Ҫ����һ��������Ķ���
3.���շ���ֵ�Ƕ���ĺ������õ�ʱ�����Ȱ���ʼ���ķ�ʽ���գ���Ҫ����ֵ�ķ�ʽ����(�������ʱ��)
*/
class Test
{
public:
	Test(int data = 10) :_ma(data) { cout << "Test(int)" << endl; }
	~Test() { cout << "~Test" << endl; }
	Test(const Test& t) :_ma(t._ma) { cout << "Test(const Test&" << endl; }
	void operator=(const Test& t)
	{
		cout << "operator=" << endl;
		_ma = t._ma;
	}
	int getData()const { return _ma; }
private:
	int _ma;
};
Test GetObject(Test &t)
{
	int val = t.getData();
	return Test(val);//���������Ż������´��������ʱ���󣬶���ֱ�ӹ���һ���¶���
}
int main()
{
	Test t1;
	Test t2 = GetObject(t1);//
	return 0;
}
#endif
//������ֵ����
#if 0
int main()
{
	/*
	��ֵ���ã����ڴ桢������
	��ֵ���ã�û����(��ʱ��)��û�ڴ�
	1.һ����ֵ���ñ�����������һ����ֵ��
	2.ʹ����ֵ���ð���ֵ���á�
	*/
	int a = 10;
	int& b = a;  // ��ֵ����
	//int&& c = a;//�޷�����ֵ�󶨵���ֵ����
	//int& c = 20;//��������ֵ���ð�һ����ֵ
	int const& c = 20;
	/*
	Ϊʲôʹ��const���ξͿ��Խ�� ��������ֵ���ð�һ����ֵ�����⣿
	int tmp=20;//�Ȳ���һ����ʱ��
	const int &c = tmp;//Ȼ���ٰ������ʱ���󶨵���ֵ������
	����c��ֵ�Ͳ����޸���
	*/
	int&& d = 20;//���԰�һ����ֵ�󶨵�һ����ֵ������
	/*
	��ֵ��������������һ����
	int tmp=20;//�Ȳ���һ����ʱ��
	const int &c = tmp;//Ȼ���ٰ������ʱ���󶨵���ֵ������
	���Ǵ�ʱd��ֵ�����ǿ����޸ĵ�
	*/
	CMyString&& e = CMyString("aaa");//ʹ����ֵ����

	//int&& f = d;  //һ����ֵ���ñ�����������һ����ֵ
	int& f = d;  //ʹ����ֵ���ð���ֵ����
	return 0;
}
#endif
//CMyString���� �Լ��Ż�
#if 0
class CMyString
{
public:
	CMyString(const char* str=nullptr)
	{
		cout << "CMystring(const char*)" << endl;
		if (str != nullptr)
		{
			mptr = new char[strlen(str) + 1];
			strcpy(mptr, str);
		}
		else
		{
			mptr = new char;
			*mptr = '\0';
		}
	}
	~CMyString()
	{
		cout << "~CMyString" << endl;
		delete[]mptr;
		mptr = nullptr;
	}
	//����ֵ���ò����Ŀ�������
	CMyString(const CMyString& str)
	{
		cout << "CMyString(const CMystring& str)" << endl;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
	}
	//�Ż�
	//����ֵ���ò����Ŀ�������   str���õľ���һ����ʱ����
	CMyString(CMyString&& str) 
	{
		cout << "CMyString(CMystring&& str)" << endl;
		mptr = str.mptr;
		str.mptr = nullptr;
	}
	//����ֵ���ò����ĸ�ֵ���غ���
	CMyString& operator=(const CMyString& str)
	{
		cout << "CMyString operator=(const CMyString&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
		return *this;
	}
	//����ֵ���ò����ĸ�ֵ���غ���  ���õ���һ����ʱ����
	CMyString& operator=(CMyString&& str)
	{
		cout << "CMyString operator=(CMyString&&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		mptr = str.mptr;
		str.mptr = nullptr;
		return *this;
	}
	const char* c_str()const { return mptr; }
private:
	char* mptr;
};
CMyString GetString(CMyString& str)
{
	const char* pstr = str.c_str();
	CMyString tmpStr(pstr);
	return tmpStr;  //������ʱ�������ڿ�������main����ջ֡�е���ʱ����
}
int main()
{
	CMyString str1("aaaaaaaaaaaaaaaaaaaaa");
	CMyString str2;
	str2 = GetString(str1);
	cout << str2.c_str() << endl;
	return 0;
}
/*
��������
�Ż�ǰ��
CMystring(const char*)
CMystring(const char*)
CMystring(const char*)
CMyString(const CMystring& str)===>Ϊmain����ջ֡�ϲ����¶���tmpStr����������ʱ����
~CMyString===>����tmpStr������������������ʱ����
CMyString operator=(const CMyString&) ===>main����ջ֡�ϵ���ʱ�����str2��ֵ
~CMyString===>main����ջ֡�ϵ���ʱ����
aaaaaaaaaaaaaaaaaaaaa
~CMyString
~CMyString
�Ż���
CMystring(const char*)
CMystring(const char*)
CMystring(const char*)
CMyString(CMystring&& str)===>ֱ�ӵ��ô������õĿ������캯���������ڴ濪�����ͷŵĲ���
~CMyString
CMyString operator=(CMyString&&)===>ֱ�ӵ��ô������õĸ�ֵ���غ����������ڴ濪�����ͷŵĲ���
~CMyString
aaaaaaaaaaaaaaaaaaaaa
~CMyString
~CMyString
*/
#endif
//CMyString��vector�ϵ�Ӧ��
class CMyString
{
public:
	CMyString(const char* str = nullptr)
	{
		cout << "CMystring(const char*)" << endl;
		if (str != nullptr)
		{
			mptr = new char[strlen(str) + 1];
			strcpy(mptr, str);
		}
		else
		{
			mptr = new char;
			*mptr = '\0';
		}
	}
	~CMyString()
	{
		cout << "~CMyString" << endl;
		delete[]mptr;
		mptr = nullptr;
	}
	//����ֵ���ò����Ŀ�������
	CMyString(const CMyString& str)
	{
		cout << "CMyString(const CMystring& str)" << endl;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
	}
	//����ֵ���ò����Ŀ�������
	CMyString(CMyString&& str)
	{
		cout << "CMyString(CMystring&& str)" << endl;
		mptr = str.mptr;
		str.mptr = nullptr;
	}
	//����ֵ���ò����ĸ�ֵ���غ���
	CMyString& operator=(const CMyString& str)
	{
		cout << "CMyString operator=(const CMyString&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		delete[]mptr;
		mptr = new char[strlen(str.mptr) + 1];
		strcpy(mptr, str.mptr);
		return *this;
	}
	//����ֵ���ò����ĸ�ֵ���غ���  ���õ���һ����ʱ����
	CMyString& operator=(CMyString&& str)
	{
		cout << "CMyString operator=(CMyString&&)" << endl;
		if (this == &str)
		{
			return *this;
		}
		mptr = str.mptr;
		str.mptr = nullptr;
		return *this;
	}
	const char* c_str()const { return mptr; }
private:
	char* mptr;
	friend CMyString operator+(const CMyString& lhs, const CMyString& rhs);
	friend ostream& operator<<(ostream& out, const CMyString& str);
};
CMyString operator+(const CMyString& lhs, const CMyString& rhs)
{
	//char* ptmp = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
	CMyString tmpStr;
	tmpStr.mptr = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
	strcpy(tmpStr.mptr, lhs.mptr);
	strcat(tmpStr.mptr, rhs.mptr);
	//delete[] ptmp;
	return tmpStr;
}
ostream& operator<<(ostream& out, const CMyString& str)
{
	out << str.mptr;
	return out;
}
int main()
{
	/*
	ʾ��1��
	CMyString str1 = "hello";
	CMyString str2 = "world";
	cout << "-----------------------------" << endl;
	CMyString str3 = str1 + str2;
	cout << "-----------------------------" << endl;
	cout<<str3<<endl;
	*/
	CMyString str1 = "aaa";
	vector<CMyString>vec;
	vec.reserve(10);
	cout << "-----------------------------" << endl;
	vec.push_back(str1);//push_back(str1)Ϊʲô���õ��Ǵ���ֵ���õĿ������캯����
	vec.push_back(CMyString("bbb"));
	cout << "-----------------------------" << endl;
	return 0;
}