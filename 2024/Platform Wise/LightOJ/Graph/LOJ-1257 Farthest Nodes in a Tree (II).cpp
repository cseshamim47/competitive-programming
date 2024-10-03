#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


const int N = 30001;
bool vis[3][N];
int cost[3][N];
vector<pair<int,int>> adj[N];

int mx = 0;
int mxCost = 0;
void bfs(int source, int t)
{
    vis[t][source] = true;
    queue<int> q;
    q.push(source);
    while(q.size())
    {
        int parent = q.front();
        q.pop();

        for(auto [child,weight]: adj[parent])
        {
            if(vis[t][child] == false)
            {
                vis[t][child] = true;
                cost[t][child] = cost[t][parent] + weight;
                if(cost[t][child] > mxCost)
                {
                    mxCost = cost[t][child];
                    mx = child;
                }
                q.push(child);
            }
        }
    }
}


int cs;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            vis[j][i] = false;
            cost[j][i] = 0;
        }
        adj[i].clear();
    }
    for(int i = 0; i < n-1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    mx = mxCost = 0;
    bfs(0,0);
    mxCost = 0;
    bfs(mx,1);
    mxCost = 0;
    // cout << mx << endl;
    bfs(mx,2);

    cout << "Case " << ++cs << ":\n";
    for(int i = 0; i < n; i++)
    {
        cout << max(cost[1][i],cost[2][i]) << endl;
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