#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


struct kurskals{
    int u,v,wt;

    kurskals(){}
    kurskals(int u, int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    bool operator < (const kurskals &n) const {return wt < n.wt;}
};


const int N = 50009;
int Size[N];
int parent[N];
void dsu_init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        Size[i] = 1;
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

    if(Size[pu] > Size[pv])
    {
        parent[pv] = pu;
        Size[pu] += Size[pv];
    }else 
    {
        parent[pu] = pv;
        Size[pv] += Size[pu];
    }
    return true;
}


vector<pair<int,int>> adj[N];

int lca[17][N];
int lca_weight[17][N];
bool vis[N];
int level[N];

void dfs(int vertex,int parent,int wt)
{
    // cout << vertex << " " ;
    lca_weight[0][vertex] = wt; 
    lca[0][vertex] = parent; 
    vis[vertex] = true; 

    for(auto [child,wt]: adj[vertex])
    {
        if(vis[child]) continue;

        level[child] = level[vertex] + 1;
        dfs(child,vertex,wt);
    }
}

void lca_init(int n)
{
    int lg = log2(n);

    for(int p = 1; p <= lg; p++)
    {
        for(int u = 1; u <= n; u++)
        {
            lca[p][u] = -1;
            lca_weight[p][u] = 0;
        }
    }

    for(int p = 1; p <= lg; p++)
    {
        for(int u = 1; u <= n; u++)
        {
            int parent = lca[p-1][u];

            if(parent == -1) continue;

            lca[p][u] = lca[p-1][parent];
            lca_weight[p][u] = max(lca_weight[p-1][parent],lca_weight[p-1][u]);
        }
    }

    // for(int u = 1; u <= n; u++)
    // {
    //     debug(u,lca[0][u]);
    //     debug(lca_weight[0][u]);
    // }
}

int get_lca(int u, int v)
{
    if(u == v) return 0;
    int lu = level[u];
    int lv = level[v];

    // if(u == 15 && v == 5)
    // {
    //     debug(lu,lv);
    // }

    if(lu > lv)
    {
        swap(lu,lv);
        swap(u,v);
    }

    int jump = lv-lu;
    int res = 0;

    while(jump)
    {
        int lg = log2(jump);
        jump -= (1 << lg);

        res = max(res,lca_weight[lg][v]);
        v = lca[lg][v];
    }

    if(u == v) return res;

    for(int p = 16; p >= 0; p--)
    {
        if(lca[p][u] == lca[p][v]) continue;
        res = max(lca_weight[p][u],res);
        res = max(lca_weight[p][v],res);
        u = lca[p][u];
        v = lca[p][v];
    }
    res = max(lca_weight[0][u],res);
    res = max(lca_weight[0][v],res);

    return res;
}

void clr()
{
    for(int i = 0; i < N; i++)
    {
        adj[i].clear();
        vis[i] = false;
        level[i] = 0;
    }
}

int cs;
void solve()
{
    int n,m;
    cin >> n >> m;

    clr();

    vector<kurskals> edges;

    for(int i = 0; i < m; i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(kurskals(u,v,wt));
    }

    sort(all(edges));

    dsu_init(n); // dsu

    for(int i = 0; i < m; i++)
    {
        auto x = edges[i];
        int u = x.u;
        int v = x.v;
        int wt = x.wt;
        if(merge(u,v))
        {
            // cerr << u << " " << v << " " << wt << endl;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }   
    }

    dfs(1,-1,0);

    // debug(level[15]);
    // debug(level[5]);

    // for(int u = 1; u <= n; u++)
    // {
    //     debug(u,level[u]);
    // }
    // return;

    lca_init(n);

    int q;
    cin >> q;
    cout << "Case " << ++cs << ":\n";
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        cout << get_lca(u,v) << endl;
    }




}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}