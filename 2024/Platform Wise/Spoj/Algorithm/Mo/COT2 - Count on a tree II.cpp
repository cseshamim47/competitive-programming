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

int n,m;
const int N = 40001;
vector<int> adj[N];
int t[16][N];
bool vis[N];
int inTime[N];
int outTime[N];
int weight[N];
vector<int> level(N,0);
int curTime = 0;
vector<int> tour;
void dfs(int u,int parent)
{
    t[0][u] = parent;
    tour.push_back(u);
    inTime[u] = curTime++;
    vis[u] = true;
    for(auto v: adj[u])
    {
        if(vis[v]) continue;
        level[v] = level[u]+1;
        dfs(v,u);
    }
    tour.push_back(u);
    outTime[u] = curTime++;
}

int _log2;
void init_lca()
{
    _log2 = log2(n);
    for(int p = 1; p <= _log2; p++)
    {
        for(int node = 1; node <= n; node++)
        {
            t[p][node] = -1;
        }
    }
    for(int p = 1; p <= _log2; p++)
    {
        for(int node = 1; node <= n; node++)
        {
            int prev_nth_parent = t[p-1][node];
            if(prev_nth_parent == -1) continue;
            t[p][node] = t[p-1][prev_nth_parent];
        }
    }
}
int get_lca(int u,int v)
{
    if(level[u] > level[v]) swap(u,v);
    int need_to_jump = level[v]-level[u];
    while(need_to_jump)
    {
        int lg = log2(need_to_jump);
        v = t[lg][v];
        need_to_jump -= (1 << lg);
    }
    if(u == v) return u;
    
    for(int p = _log2; p >= 0; p--)
    {
        if(t[p][u] == t[p][v]) continue;
        u = t[p][u];
        v = t[p][v];
    }

    return t[0][u];
}

int k;
struct query{
    int l,r,type,idx;
    bool operator<(query &q)
    {   
        if(l/k == q.l/k)
        {
            if((l/k)%2 == 0)
            {
                return r > q.r;
            }else 
            {
                return r < q.r;
            }
        }else 
        {
            return l < q.l;
        }
    }
}queries[100001];

vector<int> freq(40001,0),node_cnt(40001,0);
int cnt = 0;

void add(int idx)
{
    int node = tour[idx];
    node_cnt[node]++;
    if(node_cnt[node] == 1)
    {
        freq[weight[node]]++;
        if(freq[weight[node]] == 1) cnt++;
    }else if(node_cnt[node] == 2)
    {
        freq[weight[node]]--;
        if(freq[weight[node]] == 0) cnt--;
    }
}

void remove(int idx)
{
    int node = tour[idx];
    node_cnt[node]--;
    if(node_cnt[node] == 1)
    {
        freq[weight[node]]++;
        if(freq[weight[node]] == 1) cnt++;
    }else if(node_cnt[node] == 0)
    {
        freq[weight[node]]--;
        if(freq[weight[node]] == 0) cnt--;
    }
}


void solve()
{
    cin >> n >> m;
    vector<pair<int,int>> wt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> wt[i].first;
        wt[i].second = i+1;
    }
    sort(all(wt));

    int prev = -1;
    int compress = 0;
    for(int i = 0; i < n; i++)
    {
        auto [val,idx] = wt[i];
       
        if(prev == -1 || prev != val)
        {
            weight[idx] = ++compress; 
            prev = val;
        }else
        {
            weight[idx] = compress;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    init_lca();
    
    k = sqrt(tour.size());

    
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        if(inTime[u] > inTime[v]) swap(u,v);
        int lca = get_lca(u,v);
        if(lca == u) 
        {
            queries[i].l = inTime[u];
            queries[i].r = inTime[v];
            queries[i].type = 0;
        }else 
        {
            queries[i].l = outTime[u];
            queries[i].r = inTime[v];
            queries[i].type = lca;
        }
        queries[i].idx = i; 
    }
    cnt = 0;

    sort(queries,queries+m);

    vector<int> res(m,0);
    int curR = -1, curL = 0;
    for(int i = 0; i < m; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        int idx = queries[i].idx;
        int lca = queries[i].type;

        while(curL > l) add(--curL);
        while(curR < r) add(++curR);
        while(curL < l) remove(curL++);
        while(curR > r) remove(curR--);

        if(lca)
        {
            if(freq[weight[lca]] == 0) 
            {
                res[idx] = cnt+1;
                continue;
            }
        }

        res[idx] = cnt;
    }

    for(auto x : res) 
    {
        cout << x << endl;
    }


}
/* 
8 6
105 2 9 3 8 5 7 7
1 2
1 3
1 4
3 5
3 6
3 7
4 8

1 8
2 4
3 7
7 4
5 7
2 5
 */

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}