#include <bits/stdc++.h>
#define N 1005
#define Maxsize 10005       //�տ�ʼ���������10^6�������в��������ֲ��������ǲ���̫��
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
int post[N],in[N],cnt=0;
bt* postInBuildTree(int in[],int post[],int n)   {      //����������
    if (n<=0)   return nullptr;
    int i=0;
    while (post[n-1]!=in[i])    i++;
    bt* nw=new bt;
    nw->data=post[n-1];
    nw->lc=postInBuildTree(in,post,i);
    nw->rc=postInBuildTree(in+i+1,post+i,n-i-1);
    return nw;
}
int btDepth(bt* T)  {       //˳�����ʵ��
    if (!T) return 0;
    int ft=-1,re=-1,ori=-1;
    int last=0,level=0;
    bt *Q[Maxsize];
    Q[++re]=T;      //˳��������:Q[++rear]=T;
    bt* p;
    while (ft<re)  {
        p=Q[++ft];
        if (p->lc)  Q[++re]=p->lc;
        if (p->rc)  Q[++re]=p->rc;
        if (ft==last)   {
            cout<<"Round "<<++cnt<<" :\t"<<ft-ori<<endl;     //��ʱ������ǵ�ǰ��Ľڵ���
            ori=ft;
            level++;
            last=re;
        }
    }
    return level;
}
int STLbtDepth(bt* T)   {   //STLʵ�ֵ���ʵ��������
    if (!T) return 0;
    int level=0;
    queue<bt*> qb;
    qb.push(T);
    bt *last=T,*ft,*re;
    while (!qb.empty()) {
        ft=qb.front();qb.pop();
        if (ft->lc)  qb.push(ft->lc);
        if (ft->rc) qb.push(ft->rc);
        re=qb.back();
        if (ft==last)   {
            last=re;
            level++;
        }
    }
    return level;
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&in[i]);
    for (int i=0;i<n;i++)   scanf("%d",&post[i]);
    bt *root=postInBuildTree(in,post,n);
    //int ans=btDepth(root);
    int ans=STLbtDepth(root);
    printf("%d\n",ans);
    return 0;
}
