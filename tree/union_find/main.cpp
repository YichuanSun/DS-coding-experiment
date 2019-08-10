#include <bits/stdc++.h>
#define N 1005
using namespace std;
int pa[N],rk[N];
void initial(int a[],int n)   {
    for (int i=0;i<n;i++)   {a[i]=i;rk[i]=0;}
}
int Find(int a[],int x) {
    while(a[x]!=x)  a[x]=a[a[x]];       //³¢ÊÔÂ·¾¶Ñ¹Ëõ
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
bool same(int a[],int p,int q){return Find(a,p)==Find(a,q);}
int main()  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)   scanf ("%d",&pa[i]);
    while (1)   {
        int is,ts,td,ans;
        printf("Please input an instruction:\t");
        scanf("%d",&is);
        switch(is)  {
            case 1: {scanf("%d",&ts);ans=Find(pa,ts);printf("%d\n",ans);}break;     //find
            case 2: {scanf("%d%d",&ts,&td);Union(pa,ts,td);}break;    //Union
            case 3: td=N;break;
        }
        if (td==N)  break;
    }
    return 0;
}





