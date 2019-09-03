#include <bits/stdc++.h>
#define INF 100000005
#define N 5005
using namespace std;

int d[N],g[N][N];
bool used[N][N];

void dijkstra(int r);

int main()  {
    fill(d,d+N,INF);
    fill(g[0],g[0]+N*N,INF);
    int n,root;
    cin>>n>>m;
    cin>>root;
    for (int i=0;i<m;i++)   {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
    }
    dijkstra(root);
    return 0;
}

void dijkstra(int r)    {
    d[r]=0;
    while (true)    {
        int v=-1;
        for (int u=1;u<=n;u++)   {
            if (!used[u]&&(v==-1||(d[u]>d[v]))
                v=u;
        }
        if (v==-1)  break;
        used[v]=true;
        for (int u=1;u<=n;u++)
            d[u]=min(d[u],d[v]+g[v][u]);
    }
}





