#include <bits/stdc++.h>
#define MAX 10000007
#define MIN -10000007
#define N 10005
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
bool isBST(bt* root);
bt* preInBuildTree(int pre[],int in[],int n);
bool inOrderJudgeBST(bt* root);
int pre[N],in[N];
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&pre[i]);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    bt* tree=preInBuildTree(pre,in,n);
    cout<<inOrderJudgeBST(tree)<<endl;
    return 0;
}
bool isBST(bt* root)    {       //��д�ģ���֪��Ϊʲô���о�ͦ���ģ�����Ҳ����
    if (root==nullptr) return true;
    int td[4]={-1,0,MAX};
    td[1]=root->data;
    if (root->lc)   td[0]=root->lc->data;
    if (root->rc)   td[2]=root->rc->data;
    bool jd=(td[0]<td[1])&&(td[1]<td[2]);
    return isBST(root->lc)&&isBST(root->rc)&&jd;
}
int predt=MIN;      //�����㷨���õ���
bool inOrderJudgeBST(bt* root)  {       //�������ϵģ������������ʵ�֣���ȫ��������������������ǵ���/�ݼ�����
    bool bl,br;
    if (root==nullptr)  return true;
    else {
        bl=inOrderJudgeBST(root->lc);
        if (!bl||root->data<predt)  return false;
        predt=root->data;
        br=inOrderJudgeBST(root->rc);
        return br;
    }
}
bt* preInBuildTree(int pre[],int in[],int n)    {
    if (n<=0)   return nullptr;
    int i=0;
    while (i<n&&pre[0]!=in[i])  i++;
    bt* nw=new bt;
    nw->data=pre[0];
    nw->lc=preInBuildTree(pre+1,in,i);
    nw->rc=preInBuildTree(pre+i+1,in+i+1,n-i-1);
    return nw;
}
