#include <bits/stdc++.h>
using namespace std;
#define endl "\n"



const int N = 20004;
int vis[N];
vector<int> adj[N];


int inTime[N];

bool dfs(int vertex) /// I'm actually detecting cycle in directed graph here
{
    bool cycle = false;
    inTime[vertex] = 1;
    vis[vertex] = true;
    for(auto child: adj[vertex])
    {
        if(vis[child] && inTime[child]) 
        {
            
            return cycle = true;
        }

        if(vis[child]) continue;

        if(cycle == false) 
        cycle |= dfs(child);
    }
    inTime[vertex] = 0;
    return cycle;
}

int cs;
void solve()
{

    for(int i = 0; i < N; i++)
    {
        vis[i] = 0;
        adj[i].clear();
    }


    int n;
    cin >> n;
    
    map<string,int> mp;
    int v = 1;
    for(int i = 0; i < n; i++)
    {
        string a,b;
        cin >> a >> b;
        if(mp.count(a) == 0) mp[a] = v++;
        if(mp.count(b) == 0) mp[b] = v++;
        adj[mp[a]].push_back(mp[b]);
    }

    cout << "Case " << ++cs << ": ";
    bool ok = true;

    for(int i = 1; i < v; i++)
    {
        if(vis[i] == false)
        {
            if(dfs(i))
            {
                ok = false;
                break;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}