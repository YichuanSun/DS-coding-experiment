//������������������������ʵ��
#include <bits/stdc++.h>
using namespace std;

typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;      //tag=0����ʾָʾ��/�Һ��ӣ�tag=1����ʾָʾǰ��/���
}ThreadNode,*ThreadTree;

int main()  {
    return 0;
}
//�����������㷨�ĵݹ鲿��
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
//�������������㷨
void CreatInThread(ThreadTree T)    {
    ThreadTree pre=nullptr;
    if (T!=nullptr) {
        InThread(T,pre);
        pre->rchild=nullptr;
        pre->rtag=1;
    }
}

//���������������������������µĵ�һ���ڵ�
ThreadNode *Firstnode(ThreadNode *p)    {
    while (p->ltag==0)  p=p->lchild;
    return p;
}
//���������������нڵ������������µĺ�̽ڵ�
ThreadNode *Nextnode(ThreadNode *p) {
    if (p->rtag==0) return Firstnode(p->rchild);
    else return p->rchild;
}
//�����������������
void Inorder(ThreadNode *T) {
    for (ThreadNode *p=Firstnode(T);p!=nullptr;p=Nextnode(p))
        visit(p);
}
