#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef int elemType;
typedef struct bt{
    elemType data;
    bt *lc,*rc;
}bt;
int le[N],de[N];        //le是层次序列，de是度的序列
queue<bt*> fi,nfi;
bt* buildTree(int le[],int de[],int n) {
    if (n<=0)   return nullptr;
    int k=0;
    nfi.push(le[k++]);
    int last=0;
    while (!nfi.empty())    {
        for (;k<de[nfi.front()];k++)
            nfi.push(le[k]);
        fi.push(nfi.front());
        nfi.pop();
    }
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf("%d",&le[i]);
    for (int i=0;i<n;i++)   scanf("%d",&de[i]);
    bt* root=
    return 0;
}
