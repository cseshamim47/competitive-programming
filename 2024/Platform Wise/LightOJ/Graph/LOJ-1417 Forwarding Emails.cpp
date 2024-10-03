#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifndef ONLINE_JUDGE
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


const int N = 50000+10;
vector<int> adj[3][N];
vector<pair<int,int>> edges;
stack<int> stk;
vector<int> cnt(N);
vector<int> mini(N);
vector<int> mp(N);

bool vis[3][N];
int mn;

void dfs(int vertex,int t)
{
    if(t < 2)
    {
        mn = min(vertex,mn);
        
    }

    vis[t][vertex] = true;
    for(auto child: adj[t][vertex])
    {
        if(vis[t][child]) continue;
        dfs(child,t);
    }
    stk.push(vertex);
    if(t < 2) return;

    int mx = cnt[vertex];
    mn = 1e8;
    for(auto child: adj[t][vertex])
    {
        if(cnt[child]+cnt[vertex] >= mx)
        {
            mx = cnt[child]+cnt[vertex];
        }
    }
    cnt[vertex] = mx;
}


int cs;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            vis[j][i] = false;
            adj[j][i].clear();
        }
        cnt[i] = 0;
        mini[i] = 0;
        mp[i] = 0;
    }
    while(stk.size()) stk.pop();
    edges.clear();
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
        edges.push_back({a,b});
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[0][i] == false)
        {
            dfs(i,0);
        }
    }   
    vector<int> s; 
    while(stk.size())
    {
        s.push_back(stk.top());
        stk.pop();
    }
    debug(s);
    for(int i = 1; i <= n; i++) mp[i] = i,cnt[i] = 1;
    for(int i = 0; i < n; i++)
    {
        int v = s[i];
        if(vis[1][v] == false)
        {
            mn = 1e8;
            dfs(v,1);
            cnt[mn] = stk.size();
            debug(v);
            debug2(mn,cnt[mn]);
            while(stk.size())
            {
                debug2(v,stk.top());
                mp[stk.top()] = mn;
                stk.pop();
            }
        }
    }

    set<int> st;
    for(int i = 0; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        debug2(u,mp[u]);
        debug2(v,mp[v]);
        u = mp[u];
        v = mp[v];
        st.insert(u);
        st.insert(v);
        if(u != v)
        {
            adj[2][u].push_back(v);
        } 
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[2][i] == false)
        {
            dfs(i,2);
        }
    }

    int mx = 0;
    int v = 0;

    for(auto x : st)
    {
        debug(x);
        if(cnt[x] == mx)
        {
            debug(cnt[x]);
            v = min(v,x);
        }
        if(cnt[x] > mx)
        {
            debug(cnt[x]);
            mx = cnt[x];
            v = x;
        }
    }

    debug2(cnt[1],cnt[3]);

    cout << "Case " << ++cs << ": ";
    cout << v << endl;


}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}