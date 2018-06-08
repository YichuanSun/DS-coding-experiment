#include <bits/stdc++.h>
using namespace std;
struct BinaryNode
{
	BinaryNode* _left;
	BinaryNode* _right;
	BinaryNode* _parent;
	int _value;
	BinaryNode(const int& value)
		:_value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};
int Hight(BinaryNode* root, BinaryNode* node)
{
	int len = 0;
	for (; node != NULL; node = node->_parent)
		len++;

	return len;
}
BinaryNode* GetLastCommonAncestor(BinaryNode* root, BinaryNode* node1, BinaryNode* node2)
{

	if (root == NULL || node1 == NULL || node2==NULL)
		return NULL;

	int len1 = Hight(root,node1);
	int len2 = Hight(root,node2);


	for (; len1 > len2; len1--)
		node1 = node1->_parent;
	for (; len2 > len1; len2--)
		node2 = node2->_parent;

	while (node1 && node2 && node1 != node2)
	{
		node1 = node1->_parent;
		node2 = node2->_parent;
	}

	if (node1 == node2)
		return node1;
	else
		return NULL;
}

void Test()
{
    int n,temp;
    cin>>n;
    cin>>temp;
	BinaryNode* root = new BinaryNode(temp);
	BinaryNode* cur = root;
	queue<BinaryNode*> q;
	BinaryNode* top = NULL;
	q.push(root);
	for (int i = 2; i <= n; i++)
	{
		if (!q.empty())
		{
			top = q.front();
			cin>>temp;
			if (cur == top->_left)
			{
				cur = new BinaryNode(temp);
				top->_right = cur;
				cur->_parent = top;
				q.pop();
			}
			else
			{
				cur = new BinaryNode(temp);
				top->_left = cur;
				cur->_parent = top;
			}
			q.push(cur);
		}
	}
	cin>>
	BinaryNode* node1 = root->_left->_left;
	BinaryNode* node2 = root->_right->_left;
	BinaryNode* ancestor = GetLastCommonAncestor(root, node1, node2);
	if (ancestor)
		cout << ancestor->_value << endl;
	else
		cout << "没有公共祖先" << endl;
}

int main()
{
    Test();
    int n;
    return 0;
}
