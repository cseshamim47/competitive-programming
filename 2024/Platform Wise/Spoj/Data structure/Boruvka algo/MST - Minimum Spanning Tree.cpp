#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifndef ONLINE_JUDGE
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


struct Edge
{
    int u,v,cost;
    Edge(){}
    Edge(int u, int v, int cost) {
        this->u = u;
        this->v = v;
        this->cost = cost;
    }
};


vector<int> size,parent;
vector<Edge> min_edge;

void init(int n)
{
    size.resize(n+1);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++)
    {
        size[i] = 1;
        parent[i] = i;
    }
}

int find(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

bool merge(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    if(pu == pv) return false;

    if(size[pu] >= size[pv])
    {
        parent[pv] = pu;
        size[pu] += size[pv];
    }else 
    {
        parent[pu] = pv;
        size[pv] += size[pu];
    }
    return true;
}


void solve()
{
    int n,m;
    cin >> n >> m;
    init(n);
    min_edge.resize(n+1);
    vector<Edge> edges;
    for(int i = 0; i < m; i++)
    {
        int u,v,cost;
        cin >> u >> v >> cost;
        edges.push_back(Edge(u,v,cost));
    }
    int comp = n;
    int tot_cost = 0;
    while(comp > 1)
    {
        for(int i = 0; i <= n; i++) min_edge[i].cost = -1;

        for(int i = 0; i < m; i++)
        {
            auto [u,v,cost] = edges[i];
            int pu = find(u);
            int pv = find(v);

            if(pu == pv) continue;
            
            if(min_edge[pu].cost == -1 || min_edge[pu].cost > cost)
            {
                min_edge[pu].cost = cost;
                min_edge[pu].u = u;
                min_edge[pu].v = v;
            }

            if(min_edge[pv].cost == -1 || min_edge[pv].cost > cost)
            {
                min_edge[pv].cost = cost;
                min_edge[pv].u = u;
                min_edge[pv].v = v;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            if(min_edge[i].cost == -1) continue;

            auto [u,v,cost] = min_edge[i];
            
            if(merge(u,v))
            {
                tot_cost += cost;
                comp--;
            }
        }
    }
    cout << tot_cost << endl;

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}