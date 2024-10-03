#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];

void dfs(int v)
{
    vis[v] = true;
    for(auto child: adj[v])
    {
        if(vis[child]) continue;
        dfs(child);
    }
}


void solve()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == false)
        {
            v.push_back(i);
            dfs(i);
        }
    }
    cout << v.size()-1 << endl;
    for(int i = 1; i < v.size(); i++)
    {
        cout << v[0] << " " << v[i] << endl;
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