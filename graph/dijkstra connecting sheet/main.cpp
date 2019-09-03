#include <bits/stdc++.h>
#define N 5005
using namespace std;

typedef struct edge{
    int to,cost;
    edge(int a,int b) : to(a),cost(b) {}
}edge;
vector<edge> vve[N];
struct cmp{
    bool operator () (edge e1,edge e2)  const {
        return e1.cost>e2.cost;
    }
};
priority_queue<edge,vector<edge>,cmp> pq;
int n,m,root,a,b,c;

int main()  {
    cin>>root;
    for (int i=0;i<m;i++)   {
        cin>>a>>b>>c;
        vve[a].push_back(edge(b,c));
    }
    dijkstra(n);
    return 0;
}

void dijkstra(int n)    {

}
