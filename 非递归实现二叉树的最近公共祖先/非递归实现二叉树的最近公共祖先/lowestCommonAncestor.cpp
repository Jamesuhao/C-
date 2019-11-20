#include<iostream>
#include<stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{ }
};
//Ѱ��·����ǰ�����
void GetNodePath(TreeNode* pRoot, TreeNode* pNode, stack<TreeNode*>& path)
{
	//������ڵ���Ŀ��ڵ���ͬ��ѹջ��ֱ�ӷ���
	if (pNode == pRoot)
	{
		path.push(pRoot);
		return;
	}
	//��ǰ�ڵ�
	TreeNode* cur = pRoot;
	//����Ƿ����
	TreeNode* last = nullptr;
	//ѭ������
	while (cur || !path.empty())
	{
		//��ǰ�ڵ㲻Ϊ��
		if (cur)
		{
			//����ǰ�ڵ���ջ
			path.push(cur);
			//�����ǰ�ڵ����Ŀ��ڵ㣬ѭ����ֹ
			if (cur == pNode)
			{
				break;
			}
			//����������
			cur = cur->left;
		}
		//��ǰ�ڵ�Ϊ��
		else
		{
			//��ȡջ��Ԫ�أ��ص����ڵ�
			cur = path.top();
			//��ǰ�ڵ����������������������Ϊ��ʱ������������
			if (cur->right && cur->right != last)
			{
				//����������
				cur = cur->right;
				//����ǰ�ڵ�ѹջ
				path.push(cur);
				////�����ǰ�ڵ����Ŀ��ڵ㣬ѭ����ֹ
				if (cur == pNode)
				{
					break;
				}
				//���ʵ�ǰ�ڵ��������
				cur = cur->left;
			}
			//��ǰ�ڵ�������������ڻ��ѱ�����
			else
			{
				//��ջ
				path.pop();
				//���±��
				last = cur;
				//��ǰ�ڵ�����������Ŀ��ڵ㲢��������Ϊ�ջ����ѱ�����Ҳ����Ŀ��ڵ㣬
				//���Խ���ǰ�ڵ��ջ�󽫵�ǰ�ڵ���Ϊ�գ����ڷ��ʣ�������ѭ��
				cur = nullptr;
			}
		}
	}
}
//���г�ջ�Ƚϣ�Ѱ�ҹ������ȣ���һ����ȵ�ջ��Ԫ�ؼ�Ϊ��������
TreeNode* GetLastCommonNode(stack<TreeNode*>path1, stack<TreeNode*>& path2)
{
	//����ջ����Ϊ��ʱѭ���Ƚ�
	while (!path1.empty() && !path2.empty())
	{
		//�������ջ��ջ��Ԫ����ͬ����Ϊ����������ȣ����ҳ�ջ
		if (path1.top() == path2.top())
			return path1.top();
		//�������ͬ�����г�ջ
		else
		{
			//���ջ1Ԫ�ض���ջ2Ԫ�أ��ȳ�ջ1
			if (path1.size() > path2.size())
			{
				path1.pop();
			}
			//���ջ2Ԫ�ض���1Ԫ�أ��ȳ�ջ2
			else if (path1.size() < path2.size())
			{
				path2.pop();
			}
			//������ͬ��ͬʱ��
			else
			{
				path1.pop();
				path2.pop();
			}
		}
	}
	return nullptr;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr || p == nullptr || q == nullptr)
	{
		return nullptr;
	}
	stack<TreeNode*>s1;
	GetNodePath(root, p, s1);
	stack<TreeNode*>s2;
	GetNodePath(root, q, s2);
	return GetLastCommonNode(s1, s2);
}