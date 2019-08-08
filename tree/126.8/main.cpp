#include <bits/stdc++.h>
#define N 1005
using namespace std;
int post[N],in[N];
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
//后序中序建树
bt* postInBuildTree(int post[],int in[],int n)  {
    if (n<=0)   return nullptr;
    int i=0;
    while (post[n-1]!=in[i])    i++;
    bt* nw=new bt;
    nw->data=post[n-1];
    nw->lc=postInBuildTree(post,in,i);
    nw->rc=postInBuildTree(post+i,in+i+1,n-i-1);
    return nw;
}
void postOrderTraversal(bt* root)   {
    stack<bt*> bs;
    bt *p=root,*r=nullptr;
    while (p||!bs.empty())  {
        if (p)  {
            bs.push(p);
            p=p->lc;
        }
        else{
            p=bs.top();
            if (p->rc&&p->rc!=r)    {
                p=p->rc;
                bs.push(p);
                p=p->lc;
            }
            else {
                bs.pop();
                printf("%d ",p->data);
                r=p;
                p=nullptr;
            }
        }
    }
    printf("\n");
}
//第8题，计算度为2的节点数
int calNodeNum(bt* rt)    {
    int ans=0;
    queue<bt*> qb;
    qb.push(rt);
    while (!qb.empty())  {
        bt* p=qb.front();qb.pop();
        if (p->lc&&p->rc)   ans++;
    }
    return ans;
}
//第9题，交换树中的左右子树
void exchangeTree(bt* rt)    {
    queue<bt*> qb;
    qb.push(rt);
    while (!qb.empty())  {
        bt* p=qb.front();qb.pop();
        if (p)  {
            qb.push(p->lc);
            qb.push(p->rc);
            bt* tp=p->lc;
            p->lc=p->rc;
            p->rc=tp;
        }
    }
}
void inOrderTraversal(bt* root)  {
    if (!root)  return;
    inOrderTraversal(root->lc);
    printf("%d ",root->data);
    inOrderTraversal(root->rc);
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    bt* root=postInBuildTree(post,in,n);
    cout<<"OK"<<endl;
//    int ans=calNodeNum(root);
//    printf("%d\n",ans);
    exchangeTree(root);
    postOrderTraversal(root);
    inOrderTraversal(root);
    printf("\n");
    return 0;
}
