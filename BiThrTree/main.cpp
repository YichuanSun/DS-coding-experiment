//王道上中序线索化线索树的实现
#include <bits/stdc++.h>
using namespace std;

typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;      //tag=0，表示指示左/右孩子；tag=1，表示指示前驱/后继
}ThreadNode,*ThreadTree;

int main()  {
    return 0;
}
//中序线索化算法的递归部分
void InThread(ThreadTree &p,ThreadTree &pre)    {
    if (p!=nullptr) {
        InThread(p->lchild,pre);
        if (p!=nullptr) {
            p->lchild=pre;
            p->ltag=1;
        }
        if (pre!=nullptr&&pre->rchild==nullptr){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}
//中序线索化主算法
void CreatInThread(ThreadTree T)    {
    ThreadTree pre=nullptr;
    if (T!=nullptr) {
        InThread(T,pre);
        pre->rchild=nullptr;
        pre->rtag=1;
    }
}

//求中序线索二叉树中中序序列下的第一个节点
ThreadNode *Firstnode(ThreadNode *p)    {
    while (p->ltag==0)  p=p->lchild;
    return p;
}
//中序线索二叉树中节点在中序序列下的后继节点
ThreadNode *Nextnode(ThreadNode *p) {
    if (p->rtag==0) return Firstnode(p->rchild);
    else return p->rchild;
}
//中序遍历线索二叉树
void Inorder(ThreadNode *T) {
    for (ThreadNode *p=Firstnode(T);p!=nullptr;p=Nextnode(p))
        visit(p);
}
