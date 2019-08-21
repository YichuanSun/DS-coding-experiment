#include <bits/stdc++.h>
#define N 1005
using namespace std;
int used[N];
int path[N],d;
vector<int> g[N];
void FindPaths(vector<int> g[],int u,int v,int path[],int d);   //局部变量传参版
void FP(vector<int> g[],int u,int v);   //全局变量版
int main()  {
    int n,m,a,b,u,v;
    //int d=0,path[N];
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>u>>v;
    //FindPaths(g,u,v,path,d);
    FP(g,u,v);
    return 0;
}

void FindPaths(vector<int> g[],int u,int v,int path[],int d)    {
    path[d++]=u;
    used[u]=1;
    if (u==v)
        for (int i=0;i<d;i++)
            printf("%d%c",path[i],i==d-1?'\n':' ');
    for (int i=0;i<(int)g[u].size();i++)
        if (!used[g[u][i]])
            FindPaths(g,g[u][i],v,path,d);
    used[u]=0;
}

void FP(vector<int> g[],int u,int v)    {
    path[d++]=u;
    used[u]=1;
    if (u==v)
        for (int i=0;i<d;i++)
            printf("%d%c",path[i],i==d-1?'\n':' ');
    for (int i=0;i<(int)g[u].size();i++)
        if (!used[g[u][i]])
            FindPaths(g,g[u][i],v,path,d);
    used[u]=0;
    d--;
}
