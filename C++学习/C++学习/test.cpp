#if 0
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*
========>ֻ���ڶ��ϴ�������:
1.����Ϳ�������˽�л�
2.�ṩһ�����е�static�ӿڴ�������
3.��������ֻ�����������첻ʵ��
*/

class HeapOnly
{
public:
	static HeapOnly* getHeapOnly()
	{
		return new HeapOnly;
	}
private:
	HeapOnly();
	//��������ֻ�����������첻ʵ�ֻ���������delete����
	//HeapOnly(const HeapOnly& h) = delete;
	HeapOnly(const HeapOnly& h);
};
int main()
{
	HeapOnly* pa = HeapOnly::getHeapOnly();
	HeapOnly copy(*pa);
	return 0;
}

/*
=======>ֻ��ջ�ϴ�������
��ʽһ��
1.����˽�л�
2.�ṩһ�����е�static�ӿڴ�������
��ʽ����
������operator new����������˽�л�
*/
class StackOnly
{
public:
	static StackOnly getStackOnly()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};
class StackOnly1
{
private:
	void* operator new(size_t size);
};
int main()
{
	//StackOnly s = StackOnly::getStackOnly();
	StackOnly1 s;
	//StackOnly1* ps = new  StackOnly1;
	return 0;
}
/*
����ģʽ��
======>����ģʽ��
����˵�����㽫���ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������
�����ڵ�һ��ʹ��֮ǰ���Ѿ�����
1.���캯��˽�л�
2.�ṩһ����̬�Ĺ��нӿڷ��ض���
3.Ҫ����һ��static�����Ա
4.��������ֻ�����������첻ʵ��
===>����ģʽ
1.���캯��˽�л�
2.�ṩһ����̬�Ĺ��нӿڷ��ض���
3.Ҫ����һ��staticָ��
4.��������ֻ�����������첻ʵ��
5.�̰߳�ȫ��˫���
*/
//����ģʽ
//class Singleton
//{
//public:
//	static Singleton* getInstance()
//	{
//		return &_instance;
//	}
//private:
//	Singleton()
//	{
//		cout << "Singleton()" << endl;
//	}
//	Singleton(const Singleton& h);
//	static Singleton _instance;
//};
//Singleton Singleton::_instance;
//int main()
//{
// //ps��ps�ĵ�ַ��һ����
//	Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	return 0;
//}

//����ģʽ��
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (_pInstance == nullptr)
		{
			_mtx.lock();
			if (_pInstance == nullptr)
				_pInstance = new Singleton;
			_mtx.unlock();
		}
		return _pInstance;
	}
private:
	Singleton()
	{
		cout << "Singleton" << endl;
	}
	Singleton(const Singleton& h);
	static Singleton* _pInstance;
	static mutex _mtx;
};
Singleton* Singleton::_pInstance = nullptr;
mutex Singleton::_mtx;
int main()
{
	Singleton* ps = Singleton::getInstance();
	Singleton* ps1 = Singleton::getInstance();
	return 0;
}
#endif


//#include<iostream>
//#include<stack>
//using namespace std;
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x)
//		:val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{ }
//};
//class Solution
//{
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//	{
//		if (p->val == q->val)
//			return p;
//		stack<int>s1;
//		stack<int>s2;
//		TreeNode* Left = root;
//		TreeNode* Right = root;
//		while (Left != nullptr)
//		{
//			if (Left->left && Left->val != p->val)
//			{
//				s1.push(Left->val);
//				Left = Left->left;
//			}
//		}
//		while (Right != nullptr)
//		{
//
//		}
//	}
//};
//
//class Solution {
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		stack<TreeNode*> s, temp;
//		TreeNode* cur = root, * last = NULL;
//		while (cur || !s.empty())
//		{
//			if (cur)
//			{
//				s.push(cur);
//				cur = cur->left;
//			}
//			else
//			{
//				cur = s.top();
//				if (cur->right && cur->right != last)
//				{
//					cur = cur->right;
//					s.push(cur);
//					cur = cur->left;
//				}
//				else
//				{
//					if (temp.empty() && (cur == p || cur == q))
//						temp = s;
//					else if (!temp.empty() && (cur == p || cur == q)) break;
//					s.pop();
//					last = cur;
//					cur = NULL;
//				}
//			}
//		}
//		int temp_len = temp.size();
//		int s_len = s.size();
//		if (temp_len > s_len)
//		{
//			int i = temp_len - s_len;
//			while (i) { temp.pop(); i--; };
//			while (s_len)
//			{
//				if (temp.top() == s.top()) return temp.top();
//				else
//				{
//					temp.pop();
//							s.pop();
//						}
//					}
//				}
//				else
//				{
//					int i = s_len - temp_len;
//					while (i) { s.pop(); i--; };
//					while (temp_len)
//					{
//						if (temp.top() == s.top()) return temp.top();
//						else
//						{
//							temp.pop();
//							s.pop();
//						}
//					}
//				}
//				return NULL;
//			}
//		};

