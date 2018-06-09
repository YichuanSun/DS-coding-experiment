#include <bits/stdc++.h>
using namespace std;
int cnt=1;
struct BinaryNode       //二叉树节点结构体
{
	BinaryNode* _left;
	BinaryNode* _right;
	//BinaryNode* _parent;        //保存父节点
	int _value;
	BinaryNode(const int& value)        //构造函数
		:_value(value), _left(NULL), _right(NULL)
	{}
};

BinaryNode* GetParent(BinaryNode* root, BinaryNode* node1, BinaryNode* node2)
{
	if (root == NULL || node1 == NULL || node2 == NULL)
		return NULL;

	if (node1 == root || node2 == root)
		return root;
	BinaryNode* cur = NULL;
	BinaryNode* left_lca = GetParent(root->_left, node1, node2);
	BinaryNode* right_lca = GetParent(root->_right, node1, node2);
	if (left_lca && right_lca)
		return root;
	if (left_lca == NULL)
		return right_lca;
	else
		return left_lca;
}
void Search(BinaryNode* p,BinaryNode* &q,int key)       //树节点数据的搜索
{
    if(p!=NULL)
    {
        if (p->_value==-1)  return;
        if(p->_value==key)
            q=p;
        else
        {
            Search(p->_left,q,key);
            Search(p->_right,q,key);
        }
    }
}
int main()
{
    int n,temp;
    cin>>n;
    cin>>temp;
	BinaryNode* root = new BinaryNode(temp);
	BinaryNode* cur = root;
	queue<BinaryNode*> q;       //实现树的层序遍历建树
	BinaryNode* top = NULL;
	q.push(root);
	for (int i = 2; i <= n; i++)
	{
		if (!q.empty())
		{
			top = q.front();
			cin>>temp;
			if (top->_value==-1)    {
                q.pop();
                continue;
			}
			if (cur == top->_left)
			{
				cur = new BinaryNode(temp);
				top->_right = cur;
				//cur->_parent = top;
				q.pop();
			}
			else
			{
				cur = new BinaryNode(temp);
				top->_left = cur;
				//cur->_parent = top;
			}
			q.push(cur);
		}
	}
	int m1,m2;
	cin>>m1>>m2;        //输入目标节点
	BinaryNode* node1;
	BinaryNode* node2;
    Search(root,node1,m1);
    Search(root,node2,m2);      //返回指向目标节点的指针
    BinaryNode* ancestor = GetParent(root, node1, node2);
	if (ancestor)
		cout << ancestor->_value << endl;
	else
		cout << "没有公共祖先" << endl;
}
