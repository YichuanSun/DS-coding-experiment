#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int pre[N],in[N],tar;
bt* preInBuildTree(int pre[],int in[],int n)    {
    if (n<=0)   return nullptr;
    int i=0;
    while (pre[0]!=in[i])   i++;
    bt *root=new bt;
    root->data=pre[0];
    root->lc=preInBuildTree(pre+1,in,i);
    root->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
    return root;
}
void non_Recursion_PostOrderTraversal(bt* root) {
    stack<bt*> bs;
    bt *p=root,*r=nullptr;
    while (p||!bs.empty())  {
        if (p)  {
            bs.push(p);
            p=p->lc;
        }
        else {
            p=bs.top();
            if (p->rc&&p->rc!=r)    {
                p=p->rc;
                bs.push(p);
                p=p->lc;
            }
            else {
                bs.pop();
                //printf("%d ",p->data);
                if (p->data==tar)   {
                    stack<bt*> ts;
                    while (!bs.empty()) {ts.push(bs.top());bs.pop();}
                    while (!ts.empty()) {printf("%d ",ts.top()->data);ts.pop();}
                    return;
                }
                r=p;
                p=nullptr;
            }
        }
    }
}
void postOrderTraversal(bt* root)   {
    if (!root)  return;
    postOrderTraversal(root->lc);
    postOrderTraversal(root->rc);
    printf("%d ",root->data);
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    scanf("%d",&tar);
    bt* root=preInBuildTree(pre,in,n);
    //non_Recursion_PostOrderTraversal(root);
    postOrderTraversal(root);
    printf("\n");
    return 0;
}
