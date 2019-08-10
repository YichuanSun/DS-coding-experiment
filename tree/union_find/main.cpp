#include <bits/stdc++.h>
#define N 1005
using namespace std;
int pa[N],rk[N];
void initial(int a[],int n)   {
    for (int i=0;i<n;i++)   {a[i]=i;rk[i]=0;}
}
void Find(int a[],int x) {
    while(a[x]!=x)  x=a[x];
    return x;
}
void Union(int a[],int p,int q) {
    p=Find(a,p);
    q=Find(a,q);
    if (p==q)   return;
    if (rk[p]<=rk[q])    {
        a[p]=q;
        if (rk[p]==rk[q])   rk[q]++;
    }
    else a[q]=p;
}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf ("%d",&pa[i]);
    return 0;
}
