#include <bits/stdc++.h>
#define N 10005
using namespace std;
typedef struct bt{
    int data,cnt;
    bt *lc,*rc;
}bt;
bool isBST(bt* root);
bt* preInBuildTree(int pre[],int in[],int n);
bt* FindK(bt* root,int k);
int pre[N],in[N];
int main()  {
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    bt* tree=preInBuildTree(pre,in,n);
    bt* node=FindK(tree,n);
    cout<<node->data<<endl;
    return 0;
}
bt* preInBuildTree(int pre[],int in[],int n)    {
    if (n<=0)   return nullptr;
    int i=0;
    while (i<n&&pre[0]!=in[i])  i++;
    bt* nw=new bt;
    nw->data=pre[0];
    nw->cnt=n;
    nw->lc=preInBuildTree(pre+1,in,i);
    nw->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
    return nw;
}
bt* FindK(bt* root,int k) {
    if (root==nullptr||k<1||k>root->cnt)  return nullptr;
    if (root->lc==nullptr)  {       //��������
        if (k==1)   return root;    //����һ���ڵ�
        else    return FindK(root->rc,k-1);
    }
    if (root->lc->cnt==k-1) return root;        //���ڵ������ǵ�k��
    else if (root->lc->cnt<k-1) {   //������������ڵ���
        return FindK(root->rc,k-1-root->lc->cnt);
    }
    else    {   //���������ڵ�������k-1��
        return FindK(root->lc,k);
    }
}




