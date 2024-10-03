#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct node
{
    int cost,vertex;
    node(){}
	node(int cost,int vertex) {this->cost = cost; this->vertex = vertex;}

	bool operator < (const node &n) const {return cost > n.cost;}
};

const int N = 1e5+10;
vector<pair<int,int>> adj[N];
priority_queue<node> pq;
vector<int> wt(N,2e18);
vector<int> ways(N,0);
vector<int> min_flight(N,1e16);
vector<int> max_flight(N,0);
const int mod = 1e9+7;


void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        
    }

    // dijkstra 

    pq.push(node(0,1));
    ways[1] = 1;
    wt[1] = 0;
    min_flight[1] = 0;
    max_flight[1] = 0;
    while(pq.size())
    {
        auto [cost,parent] = pq.top();
        pq.pop();

      
        for(auto [parent_to_child_cost,child]: adj[parent])
        {
            if(cost + parent_to_child_cost < wt[child])
            {
                wt[child] = cost+parent_to_child_cost;
                ways[child] %= mod;
                ways[child] = ways[parent];  
                min_flight[child] = min_flight[parent]+1;
                max_flight[child] = max_flight[parent]+1;
                pq.push(node(wt[child],child)); 
            }else if(parent_to_child_cost+cost == wt[child])
            {
                max_flight[child] = max(max_flight[child],max_flight[parent]+1);
                min_flight[child] = min(min_flight[child],min_flight[parent]+1);
                ways[child] += ways[parent];

                ways[child] %= mod;
            }
        }
        
    }

    ways[n] %= mod;
    cout << wt[n] << " " << ways[n] << " " << min_flight[n] << " " << max_flight[n] << endl;
    

}

int32_t main()
{
    //    Bismillah
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}