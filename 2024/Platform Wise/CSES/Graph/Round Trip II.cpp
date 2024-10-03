#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int start_v;
int end_v;
const int N = 1e5+10;
vector<int> adj[N];
int vis[N];
int babama[N];

bool dfs(int v)
{
    
    vis[v] = 1;
    for(auto c : adj[v])
    {
        if(vis[c] == 1)
        {
            start_v = c;
            end_v = v;
            return true;
        }

        if(vis[c] == 0)
        {
            babama[c] = v; 
            if(dfs(c)) return true;
        }
    }
    vis[v] = 2;
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
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0 && dfs(i))
        {
            vector<int> path;
            path.push_back(start_v);
            for(int i = end_v; i != start_v; i = babama[i])
            {
                path.push_back(i);
            }
            path.push_back(start_v);
            reverse(path.begin(),path.end());

            cout << path.size() << endl;
            for(auto x : path) cout << x << " ";
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