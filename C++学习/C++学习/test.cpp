#if 0
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

/*
========>只能在堆上创建对象:
1.构造和拷贝构造私有化
2.提供一个公有的static接口创建对象
3.防拷贝：只声明拷贝构造不实现
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
	//防拷贝：只声明拷贝构造不实现或者声明成delete函数
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
=======>只在栈上创建对象
方式一：
1.构造私有化
2.提供一个公有的static接口创建对象
方式二：
禁掉其operator new函数，将其私有化
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
单例模式：
======>饿汉模式：
就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象
对象在第一次使用之前，已经存在
1.构造函数私有化
2.提供一个静态的公有接口返回对象
3.要定义一个static自身成员
4.防拷贝：只声明拷贝构造不实现
===>懒汉模式
1.构造函数私有化
2.提供一个静态的公有接口返回对象
3.要定义一个static指针
4.防拷贝：只声明拷贝构造不实现
5.线程安全：双检查
*/
//饿汉模式
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
// //ps和ps的地址是一样的
//	Singleton* ps = Singleton::getInstance();
//	Singleton* ps1 = Singleton::getInstance();
//	return 0;
//}

//懒汉模式：
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

