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

const int N = 2e5+100;
bool vis[N];
vector<int> adj[N];
int d = 1;
int dt[N];
int low[N];
int inf = 1e8;
int comp_size[N];
vector<pair<int,int>> bridge;
void dfs(int u, int parent)
{
    vis[u] = true;
    dt[u] = d;
    low[u] = d;
    d++;

    for(auto v: adj[u])
    {
        if(v == parent) continue;
        if(vis[v])
        {
            low[u] = min(low[u],low[v]);
            continue;
        }

        dfs(v,u);
        comp_size[u] += comp_size[v]; 
        low[u] = min(low[u],low[v]);

        if(dt[u] < low[v])
        {
            bridge.push_back({u,v});
        }
    }
}

void reset(int n)
{
    for(int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        dt[i] = inf;
        low[i] = inf;
        d = 1;
        comp_size[i] = 1;
    }
    bridge.clear();
}

void solve()
{
    int n,m;
    cin >> n >> m;
    reset(n);
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);
    int ans = (n*(n-1))/2;
    for(auto [u,v]: bridge)
    {
        int a = n-comp_size[v];
        int b = n-a;
        ans = min(ans,((a*(a-1))/2)+((b*(b-1)))/2);
    }

    cout << ans << endl;

    
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}