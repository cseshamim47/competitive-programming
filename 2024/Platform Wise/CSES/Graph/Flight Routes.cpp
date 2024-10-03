#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N = 1e5+10;
vector<pair<int,int>> adj[N];

int cs;
void solve()
{
    int n,r,k;

    cin >> n >> r >> k;
    
    for(int i = 0; i < r; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        // adj[b].push_back({a,w});
        
    }

    /// dijkstra

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,1}); 

    vector<int> s;

    vector<int> vis(n+1,0);

    while(pq.size())
    {
        int vertex = pq.top().second;
        int v_cost = pq.top().first;
        pq.pop();

        vis[vertex]++;

        if(vis[vertex] > k) continue;

        for(auto [child, c_cost]: adj[vertex])
        {
            if(vis[child] < k)
            {
                pq.push({c_cost+v_cost, child});
            }

            if(child == n)
            {
                s.push_back(c_cost+v_cost);
            }
        } 
    }


    sort(s.begin(),s.end());
    for(int i = 0; i < k; i++) 
    {
        cout << s[i] << " ";
    }
    cout << endl;

}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}

/* 
6 10
1 2 1
1 3 2
1 4 3
1 5 4
2 3 5
2 4 6
3 4 7 
3 5 8
3 6 9
5 6 10

 */