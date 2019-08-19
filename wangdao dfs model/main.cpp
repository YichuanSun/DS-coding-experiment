#include <bits/stdc++.h>
#define N 1005
#define MX 10000007
using namespace std;
int g[N][N],d[N],n,m,u,a,b;
bool visited[N];
void BFS_MIN_Distance(int u);   //u is the beginner
int main()  {
    cin>>n>>m>>u;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a][b]=1;
    }
    BFS_MIN_Distance(u);
    return 0;
}

void BFS_MIN_Distance(int u)    {
    fill(d,d+N,MX);
    visited[u]=true;
    d[u]=0;
    queue<int> q;
    q.push(u);
    while (!q.empty())  {
        q.pop();
        for (int i=0;i<n;i++)   {
            if (!visited[i])    {
                visited[i]=true;
                d[i]=d[u]+1;
                q.push(i);
            }
        }
    }
}
