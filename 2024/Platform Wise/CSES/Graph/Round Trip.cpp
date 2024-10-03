#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int start_v;
int end_v;
const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];
int babama[N];

bool dfs(int vertex,int parent)
{
    vis[vertex] = true;
    for(auto child: adj[vertex])
    {
        if(vis[child] && child != parent)
        {
            start_v = child;
            end_v = vertex;
            return true;
        }
        
        if(vis[child]) continue;
        babama[child] = vertex;
        if(dfs(child,vertex)) return true;
    }
    return false;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i] && dfs(i,-1))
        {
            vector<int> path;
            path.push_back(start_v);
            for(int v = end_v; v != start_v; v = babama[v])
            {
                path.push_back(v);
            } 
            path.push_back(start_v);
            cout << path.size() << endl;
            for(auto x : path)
            {
                cout << x << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}