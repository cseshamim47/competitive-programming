#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 1e5+10;
vector<int> adj[N];

void solve()
{
    int n,m;
    cin >> n >> m; 
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vector<int> par(n+1,0);
    par[1] = -1;
    while(q.size())
    {
        int node = q.front();
        q.pop();

        for(auto child: adj[node])
        {
            if(par[child]) continue;
            par[child] = node;
            q.push(child);
        }
    }

    vector<int> path;
    
    for(int v = n; v != -1; v = par[v])
    {
        if(v == 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        path.push_back(v);
    }
    cout << path.size() << endl;
    reverse(path.begin(),path.end());
    for(auto x : path) cout << x << " ";cout << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}