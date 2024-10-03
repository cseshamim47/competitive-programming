#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


int cs;
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[102];
    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({1,0});
    vector<int> weight(n+1,1e8);
    weight[1] = 0;
    while(pq.size())
    {
        auto [node,wt] = pq.top();
        pq.pop();
        // debug(node,wt);

        if(wt > weight[node]) continue;

        for(auto [child,cwt]: adj[node])
        {
            if(wt+cwt < weight[child])
            {
                weight[child] = wt+cwt;
                pq.push({child,weight[child]});
            }
        }
    }  

    cout << "Case " << ++cs << ": ";
    if(weight[n] == 1e8)
    {
        cout << "Impossible" << endl;
    }else 
    {
        cout << weight[n] << endl;
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