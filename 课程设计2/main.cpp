#include <bits/stdc++.h>
using namespace std;
const int SIZE=1005;
char a[SIZE];
typedef struct BinTree  *PtoBT;
typedef struct BinTree{
    int data;
    PtoBT left=nullptr;
    PtoBT right=nullptr;
}BinTree;
void createBinTree(PtoBT &root,char da[],int n,int& index) {
    if (index>=n)   return;
    int e=da[index++];
    if (e=='#')    root=nullptr;
    else if (root==nullptr)  {
        root=new BinTree;
        root->data=e;
        createBinTree(root->left,da,n,index);
        createBinTree(root->right,da,n,index);
    }
}
void printBinTree(PtoBT root)   {
    if(root)    {
        cout<<root->data;
        cout<<' ';
        printBinTree(root->left);
        printBinTree(root->right);
    }
}
int main()  {
    //ios::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    cout<<"Victory"<<' ';
    int n,cnt=0;
    cin>>n;     //n为节点个数
    for (int i=0;i<n;i++)   cin>>a[i];
    PtoBT root1;
    createBinTree(root1,a,n,cnt);
    printBinTree(root1);
    return 0;
}
