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
vector<int> adj[N];
bool vis[N];
int discovery[N];
int low[N];
int d = 1;
bool articulation_point[N];
int inf = 1e18;

void dfs(int u, int parent)
{
    vis[u] = true;
    discovery[u] = low[u] = d++;
    int child = 0;
    for(auto v: adj[u])
    {
        if(v == parent) continue;
        if(vis[v])
        {
            low[u] = min(low[u],discovery[v]);
            continue;
        }
        child++;
        dfs(v,u);
        low[u] = min(low[u],low[v]);
        if(discovery[u] <= low[v] && parent != -1)
        {
            articulation_point[u] = true;
        }
    }

    if(parent == -1)
    {
        if(child > 1) articulation_point[u] = true;
    }
}

void reset(int n)
{
    for(int i = 0; i <= n; i++)
    {
        vis[i] = false;
        adj[i].clear();
        articulation_point[i] = false;
        discovery[i] = low[i] = inf;
        d = 1;
    }
}

void solve()
{
    int n;
    int cs = 0;
    while(cin >> n)
    {
        if(n == 0) return;
        if(cs > 0)  cout << endl;
        reset(n);
        map<string,int> mp;
        map<int,string> np;
        for(int i = 1; i <= n; i++)
        {
            string a;
            cin >> a;
            mp[a] = i;
            np[i] = a;
        }
        int k;
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            string u,v;
            cin >> u >> v;
            int uu = mp[u];
            int vv = mp[v];
            adj[uu].push_back(vv);
            adj[vv].push_back(uu);
            debug(uu,vv);
        }
        debug("ok");
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == false)
            dfs(i,-1);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(articulation_point[i]) cnt++;
        }
        cout << "City map #" << ++cs << ": ";
        cout << cnt << " camera(s) found" << endl;
        vector<string> res;
        for(int i = 1; i <= n; i++)
        {
            if(articulation_point[i]) 
            {
                res.push_back(np[i]);
                debug(i);
            }
        }
        sort(all(res));
        for(auto &x : res) cout << x << endl;

        


    }
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}