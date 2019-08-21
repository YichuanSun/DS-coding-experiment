#include <bits/stdc++.h>
#define N 1005
using namespace std;
vector<int> g[N];
stack<int> si;
bool used[N];
void visit(int t);
void DFS_Non_RC(vector<int> g[],int b);
int main()  {
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)   {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS_Non_RC(g,1);
    return 0;
}

void DFS_Non_RC(vector<int> g[],int b)    {
    si.push(b);
    used[b]=1;
    while (!si.empty()) {
        int nw=si.top();
        visit(nw);
        si.pop();
        for (int i=0;i<(int)g[nw].size();i++)   {
            if (!used[g[nw][i]])    {
                si.push(g[nw][i]);
                used[g[nw][i]]=1;
            }
        }
    }
}

void visit(int t)   {cout<<t<<' ';}
