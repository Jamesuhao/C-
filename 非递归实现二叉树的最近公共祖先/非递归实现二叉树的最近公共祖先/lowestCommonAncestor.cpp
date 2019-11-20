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
//寻找路径：前序遍历
void GetNodePath(TreeNode* pRoot, TreeNode* pNode, stack<TreeNode*>& path)
{
	//如果根节点与目标节点相同，压栈，直接返回
	if (pNode == pRoot)
	{
		path.push(pRoot);
		return;
	}
	//当前节点
	TreeNode* cur = pRoot;
	//标记是否访问
	TreeNode* last = nullptr;
	//循环遍历
	while (cur || !path.empty())
	{
		//当前节点不为空
		if (cur)
		{
			//将当前节点入栈
			path.push(cur);
			//如果当前节点等于目标节点，循环终止
			if (cur == pNode)
			{
				break;
			}
			//遍历左子树
			cur = cur->left;
		}
		//当前节点为空
		else
		{
			//获取栈顶元素，回到根节点
			cur = path.top();
			//当前节点的右子树存在且右子树不为空时，访问右子树
			if (cur->right && cur->right != last)
			{
				//访问右子树
				cur = cur->right;
				//将当前节点压栈
				path.push(cur);
				////如果当前节点等于目标节点，循环终止
				if (cur == pNode)
				{
					break;
				}
				//访问当前节点的左子树
				cur = cur->left;
			}
			//当前节点的右子树不存在或已被访问
			else
			{
				//出栈
				path.pop();
				//更新标记
				last = cur;
				//当前节点左子树不是目标节点并且右子树为空或者已被访问也不是目标节点，
				//所以将当前节点出栈后将当前节点置为空，不在访问，避免死循环
				cur = nullptr;
			}
		}
	}
}
//进行出栈比较，寻找公共祖先，第一个相等的栈顶元素即为公共祖先
TreeNode* GetLastCommonNode(stack<TreeNode*>path1, stack<TreeNode*>& path2)
{
	//两个栈均不为空时循环比较
	while (!path1.empty() && !path2.empty())
	{
		//如果两个栈的栈顶元素相同，则为最近公共最先，并且出栈
		if (path1.top() == path2.top())
			return path1.top();
		//如果不相同，进行出栈
		else
		{
			//如果栈1元素多余栈2元素，先出栈1
			if (path1.size() > path2.size())
			{
				path1.pop();
			}
			//如果栈2元素多余1元素，先出栈2
			else if (path1.size() < path2.size())
			{
				path2.pop();
			}
			//两者相同，同时出
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