//判定二叉树是否是完全二叉树
#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int pre[N],in[N];
queue<bt*> qb;
bt* preInBuildTree(int pre[],int in[],int n)    {
    if (n<=0)   return nullptr;
    int i=0;
    while (pre[0]!=in[i])   i++;
    bt* nw=new bt;
    nw->data=pre[0];
    nw->lc=preInBuildTree(pre+1,in,i);
    nw->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
    return nw;
}
bool levelTraversal(bt *rt)  {
    qb.push(rt);
    while (!qb.empty()) {
        bt* p=qb.front();qb.pop();
        if (p)  {
            printf("%d ",p->data);
            qb.push(p->lc);
            qb.push(p->rc);
        }
        else {
            while (!qb.empty()) {
                bt *p=qb.front();
                qb.pop();
                if (p)  return false;
            }
        }
    }
    return true;
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    bt* root=preInBuildTree(pre,in,n);
    bool jd=levelTraversal(root);
    printf("\n");
    if (jd) printf("Yes\n");
    else printf("No\n");
    return 0;
}





