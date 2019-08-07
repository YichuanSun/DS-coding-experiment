#include <bits/stdc++.h>
#define N 1005
using namespace std;

struct BiTree{
    int data;
    BiTree *lc=nullptr,*rc=nullptr;
};
stack<BiTree*> bs;
int n,pre[N],in[N],post[N];
void postOrderTraversal(BiTree* t);     //非递归实现后序遍历
void preOrderTraversal(BiTree* T);
BiTree* preInTree(int pre[],int prel,int prer,int in[],int inl,int inr);    //这是网上的麻烦套路
BiTree* preInTree2(int pre[],int in[],int n)  { //这是笔记上的我的方法
    if (n<=0)   return nullptr;
    int i=0;
    while (in[i]!=pre[0])   i++;
    BiTree* nw=new BiTree;
    nw->data=in[i];
    nw->lc=preInTree2(pre+1,in,i);
    nw->rc=preInTree2(pre+i+1,in+i+1,n-i-1);
    return nw;
}
BiTree* postInTree(int post[],int in[],int root);       //后序中序建树
void pt(BiTree* ts) {
    if (!ts)    return;
    pt(ts->lc);
    pt(ts->rc);
    printf("%d ",ts->data);
}

int main()  {
    scanf("%d",&n);
    //for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    //BiTree* root=preInTree(pre,0,n-1,in,0,n-1);
    //BiTree* root1=preInTree2(pre,in,n);
    BiTree* root2=postInTree(post,in,n);
    //postOrderTraversal(root1);
    pt(root2);
    preOrderTraversal(root2);
    return 0;
}
//非递归实现后序遍历
void postOrderTraversal(BiTree* t)   {
    BiTree *p=t,*r=nullptr;
    while (p||!bs.empty())  {
        if (p)  {
            bs.push(p);
            p=p->lc;
        }
        else    {
            p=bs.top();
            if (p->rc&&p->rc!=r)    {
                p=p->rc;
                bs.push(p);
                p=p->lc;
            }
            else {
                p=bs.top();bs.pop();
                printf("%d ",p->data);
                r=p;p=nullptr;
            }
        }
    }
}
//网上找的方法，参数特别多
BiTree* preInTree(int pre[],int prel,int prer,int in[],int inl,int inr) {
    if (prel>prer)    return nullptr;
    BiTree *nw=new BiTree;
    int i=inl;
    while (pre[prel]!=in[i])   i++;
    cout<<"This time is "<<i<<" and data is "<<pre[prel]<<endl;
    nw->data=pre[prel];
    nw->lc=preInTree(pre,prel+1,prel+i-inl,in,inl,i-1);
    nw->rc=preInTree(pre,prel+i-inl+1,prer,in,i+1,inr);
    return nw;
}

BiTree* postInTree(int post[],int in[],int n)  {
    if (n<=0)   return nullptr;
    int i=0;
    while (post[n-1]!=in[i])    i++;
    BiTree* nw=new BiTree;
    nw->data=in[i];
    nw->lc=postInTree(post,in,i);
    nw->rc=postInTree(post+i,in+i+1,n-i-1);
    return nw;
}

//Node* buildTree(int n,int post[],int inorder[]) {
//    if (n<=0)   return NULL;
//    int i=0;
//    while (inorder[i]!=post[n-1])   i++;
//    Node *newnode=new Node;
//    newnode->data=inorder[i];
//    newnode->ln=buildTree(i,post,inorder);
//    newnode->rn=buildTree(n-i-1,post+i,inorder+i+1);
//    return newnode;
//}

void preOrderTraversal(BiTree* T)    {
    BiTree* p=T;
    while (p||!bs.empty())    {
        if (p)  {
            printf("%d ",p->data);
            bs.push(p);
            p=p->lc;
        }
        else {
            p=bs.top();bs.pop();
            p=p->rc;
        }
    }
}
