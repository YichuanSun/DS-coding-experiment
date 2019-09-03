#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int c[maxn],G[maxn][maxn],topo[maxn],t,n,m;
bool dfs(int u);    //����ѵĴ���
bool toposort();    //����ѵĴ���
int indegree[maxn];
vector<int> vi;
bool topologicalSort();
int main()  {
    int a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        G[a][b]=1;
    }
    toposort();
    for (int i=0;i<n;i++)   printf("%d%c",topo[i],(i==n-1?'\n':' '));
    return 0;
}
bool dfs(int u)
{
    c[u] = -1; //���ʱ�־
    for(int v = 1; v <= n; v++)
        if(G[u][v])
        {
            if(c[v]<0)  //�����ʱv�ѱ����ʹ�
                return false; //�������򻷣�ʧ���˳�
            else if(!c[v] && !dfs(v))
                return false;
        }
    c[u] = 1;
    topo[--t]=u;
    return true;
}
bool toposort()
{
    t = n;
    memset(c, 0, sizeof(c));
    for(int u = 1; u <= n; u++)
        if(!c[u])
            if(!dfs(u))
                return false;
    return true;
}

bool topologicalSort()  {
    stack<int> si;
    for (int i=1;i<=n;i++)
        if (indegree[i]==0) //��ά��һ��������飬��¼ÿ���ڵ�����
            si.push(i);
    int cnt=0;
    while (!si.empty()) {
        int y=si.top();
        si.pop();
        printf("%d%c",y,cnt==n-1?'\n':' ');
        for (int k=0;k<(int)vi[y].size();k++)   {
            indegree[vi[y][k]]--;
            if (indegree[vi[y][k]]==0)  si.push(vi[y][k]);
        }
        cnt++;
    }
    if (cnt<n)  return false;
    else return true;
}
