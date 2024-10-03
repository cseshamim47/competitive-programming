#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
// #define int long long

#ifdef SHAMIM_AHMED
#include <G:\Desktop Items\STATION\CPP\debug.h>
#else
#define debug(x...)
#define debug2(x...)
#define debug3(x...)
#endif

const int N = 1e6;
bool vis[N];
int color[N];
int res[N];
vector<int> adj[N];
string c;
int n, q;
int tour[N];
int inTime[N];
int outTime[N];
int t[N][19];
int lvl[N];

int timer = 0;
void dfs(int vertex, int parent)
{
    t[vertex][0] = parent;
    tour[timer] = vertex;
    inTime[vertex] = timer;
    timer++;
    vis[vertex] = true;
    if (c[vertex] == '1')
        color[vertex] = vertex;
    for (auto child : adj[vertex])
    {
        if (vis[child])
            continue;

        if (c[child] == '1')
        {
            color[child] = child;
        }
        else
        {
            color[child] = color[vertex];
        }

        lvl[child] = lvl[vertex] + 1;
        dfs(child, vertex);
    }
    tour[timer] = vertex;
    outTime[vertex] = timer;
    timer++;
}

int lg;
void lca_init()
{
    lg = log2(n);
    for (int u = 1; u <= n; u++)
    {
        for (int p = 1; p <= lg; p++)
        {
            t[u][p] = -1;
        }
    }
    for (int p = 1; p <= lg; p++)
    {
        for (int u = 1; u <= n; u++)
        {
            int nthPar = t[u][p - 1];
            if (nthPar != -1)
            {
                t[u][p] = t[nthPar][p - 1];
            }
        }
    }
}

int get_lca(int u, int v)
{
    if (lvl[u] > lvl[v])
        swap(u, v);
    int jump = lvl[v] - lvl[u];
    while (jump)
    {
        int _lg = log2(jump);
        v = t[v][_lg];
        jump -= (1 << _lg);
    }
    if (u == v)
        return u;

    for (int i = lg; i >= 0; i--)
    {
        if (t[u][i] != t[v][i])
        {
            u = t[u][i];
            v = t[v][i];
        }
    }
    return t[u][0];
}

int blk;
struct query
{
    int l, r, idx, lc;
    query() {}
    query(int l, int r, int idx, int lc)
    {
        this->l = l;
        this->r = r;
        this->idx = idx;
        this->lc = lc;
    }
    bool operator<(const query &q)
    {
        int a = l / blk;
        int b = q.l / blk;
        if (a == b)
        {
            if (a & 1)
                return r > q.r;
            else
                return r < q.r;
        }
        return a < b;
    }
    
} queries[N];

int nodeFreq[N];
int valFreq[N];

int ans = 0;
void add(int idx)
{
    int node = tour[idx];
    int col = color[node];
    // cout << "Add ";
    // debug(node,col);
    nodeFreq[node]++;
    if (nodeFreq[node] == 1)
    {
        valFreq[col]++;
        if (valFreq[col] == 1)
            ans++;
    }
    else if (nodeFreq[node] == 2)
    {
        valFreq[col]--;
        if (valFreq[col] == 0)
            ans--;
    }
}

void del(int idx)
{

    int node = tour[idx];
    int col = color[node];
    // cout << "del ";
    // debug(node,col);
    nodeFreq[node]--;
    if (nodeFreq[node] == 1)
    {
        valFreq[col]++;
        if (valFreq[col] == 1)
            ans++;
    }
    else if (nodeFreq[node] == 0)
    {
        valFreq[col]--;
        if (valFreq[col] == 0)
            ans--;
    }
}

void solve()
{
    cin >> n >> q;
    blk = sqrt(n);
    for (int u = 2; u <= n; u++)
    {
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> c;
    c = '#' + c;
    lvl[1] = 0;
    timer = 0;
    dfs(1, -1);
    lca_init();

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (inTime[u] > inTime[v])
            swap(u, v);
        int lca = get_lca(u, v);
        if (lca == u || lca == v)
        {
            int l = inTime[u];
            int r = inTime[v];
            queries[i] = query(l, r, i, 0);
        }
        else
        {
            int l = outTime[u];
            int r = inTime[v];
            queries[i] = query(l, r, i, lca);
        }
    }

    sort(queries, queries + q);

    int curL = 0;
    int curR = -1;
    // debug("k");
    ans = 0;
    for (int i = 0; i < q; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        int idx = queries[i].idx;
        int lca = queries[i].lc;
        // debug(l,r,idx);
        while (curR < r)
            add(++curR);
        while (curL > l)
            add(--curL);
        while (curR > r)
            del(curR--);
        while (curL < l)
            del(curL++);

        res[idx] = ans;
        if (lca != 0)
        {
            int col = color[lca];
            if (valFreq[col] == 0)
                res[idx]++;
        }
        // debug("ok");
    }

    for (int i = 0; i < q; i++)
    {
        cout << res[i] << endl;
    }

    while (curL <= curR)
    {
        int node = tour[curL];
        int col = color[node];
        nodeFreq[node] = 0;
        valFreq[col] = 0;
        curL++;
    }
    for (int u = 0; u <= n; u++)
    {
        adj[u].clear();
        vis[u] = false;
    }
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}