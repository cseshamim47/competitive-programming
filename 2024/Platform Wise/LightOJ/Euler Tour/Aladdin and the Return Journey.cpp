#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 30'000+123;
vector<int> adj[N];
int timer = 1;
vector<int> inTime(N,0);
vector<int> outTime(N,0);
vector<int> tour(2*N,0);
int LCA[N][100];
int level[N];
int n;
int maxN;

void dfs(int vertex, int parent)
{
    LCA[vertex][0] = parent;
    tour[timer] = vertex;
    inTime[vertex] = timer;
    timer++;
    for(auto child : adj[vertex])
    {
        if(child == parent) continue;
        level[child] = level[vertex] + 1;
        dfs(child,vertex);
    }
    tour[timer] = vertex;
    outTime[vertex] = timer;
    timer++;
}

void init() // Build --> O(Nlog(N))
{
    maxN = log2(n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxN; j++)
        {
            LCA[i][j] = -1;
        }
    }

    for(int j = 1; j <= maxN; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            int prevNthParent = LCA[i][j-1]; /// 2^j-1 th parent of i 
            if(prevNthParent == -1) continue;
            LCA[i][j] = LCA[prevNthParent][j-1];  
            // i tomo node er jth parent         
        }
    }
}

int getLCA(int u, int v) /// binary lifting -> O(Log(N));
{

    int a = level[u];
    int b = level[v];
    if(a < b)
    {
        swap(a,b);
        swap(u,v);
    }

    int climb = a-b;
    while(climb > 0)
    {
        int maxPow = log2(climb);
        climb -= (1<<maxPow);
        u = LCA[u][maxPow];
    }
    
    if(u == v) return u;

    for(int j = maxN; j >= 0; j--)
    {
        if(LCA[u][j] != -1 && LCA[u][j] != LCA[v][j])
        {
            u = LCA[u][j];
            v = LCA[v][j];
        }
    }

    return LCA[u][0];
}

  /// Segment Tree Start
const int MX = (30'000+123)*2;
int arr[MX];
int Tree[MX*4];

void initSegTree(int node, int b, int e)  // O(n) --> 2n nodes
{
    if(b==e)
    {
        Tree[node] = arr[b];
        return;
    }
    int Left = node*2; 
    int Right = (node*2)+1; 
    int mid = (b+e)/2;
    initSegTree(Left,b,mid);
    initSegTree(Right,mid+1,e);
    Tree[node] = Tree[Left] + Tree[Right];
}

int query(int node, int b, int e, int l, int r) // O(4*Log(n))
{
    if(l > e || r < b) return 0;
    if(l<=b && e<=r)
    {
        return Tree[node];
    }

    int Left = node*2;
    int Right = (node*2)+1;
    int mid = (b+e)/2;
    int leftTreeVal = query(Left,b,mid,l,r);
    int rightTreeVal = query(Right,mid+1,e,l,r);
    return leftTreeVal+rightTreeVal;
}

void update(int node, int b, int e, int i, int val) // O(LogN)
{
    if(i > e || i < b) return;
    if(b>=i && e<=i)
    {
        Tree[node] = val;
        return;
    }

    int Left = node*2;
    int Right = (node*2)+1;
    int mid = (b+e)/2;
    update(Left,b,mid,i,val);
    update(Right,mid+1,e,i,val);
    Tree[node] = Tree[Left] + Tree[Right];
}
/// Segment Tree end

int cs;

void solve()
{

    cin >>n;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        adj[i].clear();
        level[i] = 0;
    }   
    timer = 1;

    for(int i = 1; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,-1);
    init();
    
    vector<int> c(n+1,0);
    for(int i = 1; i < timer; i++)
    {
        if(c[tour[i]] == 0)
        arr[i] = v[tour[i]];
        else arr[i] = -v[tour[i]];
        c[tour[i]]=1;
    }
    initSegTree(1,1,timer);
    int q;
    cin >> q;
    cout << "Case " << ++cs << ":\n";
    while(q--)
    {
        int t,a,b;
        cin >> t >> a >> b;
        if(t == 0)
        {
            int root = getLCA(a,b);
            int ans = query(1,1,timer,inTime[root],inTime[a]);
            ans += query(1,1,timer,inTime[root],inTime[b]);
            ans -= query(1,1,timer,inTime[root],inTime[root]);

            cout << ans << endl;
        }else 
        {
            update(1,1,timer,inTime[a],b);
            update(1,1,timer,outTime[a],-b);
        }
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