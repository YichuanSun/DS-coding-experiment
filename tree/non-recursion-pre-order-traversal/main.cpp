#include <bits/stdc++.h>
using namespace std;
stack<BiTree*> bs;
int main()  {
    return 0;
}

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
