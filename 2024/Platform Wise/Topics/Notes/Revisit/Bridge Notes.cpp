/* 
Any Edge on whoose removal the graph is broken down into two or more components is called a BRIDGE. 

প্রথমে আমাদের বের করতে হবে প্রতিটা নোড এর discovery time (D). 
Discovery time বের করার সময় আমরা ওই নোড এর low time (L) ও বের করবো। 

low time হচ্ছে কোন একটা নোড থেকে back edge দিয়ে সর্বনিম্ন যে নোড এর low time এ যাওয়া যায় সেই নোড এর low time. 

low time এটা বুঝায় যে, একটা নোড এর back edge দিয়েও ওই নোড এর discovery time এর কম সময়ে ওই নোড এ আসা যায়। 

দুইটা নোড u আর v ধরি। 
u হচ্ছে parent
v হচ্ছে child

যদি D[u] < L[v] হয় তাহলে u থেকে v এর edge টা ডিলিট করে দিলে ২ টা component তৈরি হবে। তাহলে u----v edge টা একটা ব্রিজ। 
*/


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


const int N = 1e5+1;
const int inf = 1e8;
vector<int> adj[N];
bool vis[N];
vector<int> discovery;// discovery time
vector<int> low;

vector<pair<int,int>> articulation_points;
int d = 1;
void dfs(int u, int parent)
{
    vis[u] = true;
    discovery[u] = d;
    low[u] = d;
    d++;

    for(auto v: adj[u])
    {
        if(v == parent) continue;
        if(vis[v])
        {
            low[u] = min(low[u],low[v]);
            continue;
        }
        dfs(v,u);
        low[u] = min(low[u],low[v]);
        if(discovery[u] < low[v])
        {
            articulation_points.push_back({u,v});
        }
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;

    { // resetting
        d = 1;
        articulation_points.clear();
        memset(vis,false,sizeof vis);
        discovery.clear();
        low.clear();
        discovery.resize(n+1,inf);
        low.resize(n+1,inf);
    }

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);
    debug(discovery);
    debug(low);
    for(auto [u,v]: articulation_points)
    {
        debug(u,v);
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}


/* 
12 14
1 2
1 4
2 3
3 4
4 5
5 6
6 7
6 9
7 8
8 9
8 10
10
11
10 12
11 12
*/