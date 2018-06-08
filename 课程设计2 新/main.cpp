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
BinaryNode * GetLastCommonAncestor(BinaryNode * root, BinaryNode * node1, BinaryNode * node2)
{
	BinaryNode * temp;
	while (node1 != NULL)
	{
		node1 = node1->_parent;
		temp = node2;
		while (temp != NULL)
		{
			if (node1 == temp->_parent)
				return node1;
			temp = temp->_parent;
		}
	}
}
void Test()
{
	BinaryNode* root = new BinaryNode(1);
	BinaryNode* cur = root;
	queue<BinaryNode*> q;
	BinaryNode* top = NULL;
	q.push(root);
	for (int i = 2; i <= 7; i++)
	{
		if (!q.empty())
		{
			top = q.front();
			if (cur == top->_left)
			{
				cur = new BinaryNode(i);
				top->_right = cur;
				cur->_parent = top;
				q.pop();
			}
			else
			{
				cur = new BinaryNode(i);
				top->_left = cur;
				cur->_parent = top;
			}
			q.push(cur);
		}
	}
	BinaryNode* node1 = root->_left->_left;
	BinaryNode* node2 = root->_left->_right;
	BinaryNode* ancestor = GetLastCommonAncestor(root, node1, node2);
	if (ancestor)
		cout << ancestor->_value << endl;
	else
		cout << "没有公共祖先" << endl;
}

int main()
{
    Test();
    return 0;
}
