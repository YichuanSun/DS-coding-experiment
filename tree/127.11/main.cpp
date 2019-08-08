#include <bits/stdc++.h>
using namespace std;
typedef struct bt{
    int data;
    bt *lc,*rc;
}bt;
void deleteTree(bt* root)   {
    if (root)   {
        deleteTree(root->lc);
        deleteTree(root->rc);
        free(root);
    }
}
void levelTraversal(bt* root)   {
    queue<bt*> qb;
    bt* p=root;
    qb.push(p);
    while (!qb.empty()) {
        p=qb.front();qb.pop();
        if (p&&p->data==x)  deleteTree(p);
        else if (p) {qb.push(p->lc);qb.push(p->rc);}
    }
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    return 0;
}
