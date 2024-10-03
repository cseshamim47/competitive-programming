#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "-> " << #x <<" "; _print(x); cerr << endl;
#define debug2(x,y) cerr << "-> " << #x <<" = " << x << ", " << #y << " = " << y << endl;
#else
#define debug(x)
#define debug2(x,y)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int N = 1e5+10;
vector<int> adj[N];
int height[N];
int lvl[N];
bool vis[N];

void dfs(int parent)
{
    height[parent] = 1;
    vis[parent] = true;
    for(auto child: adj[parent])
    {
        if(vis[child]) continue;
        lvl[child] = 1 + lvl[parent];
        dfs(child);
        height[parent] += height[child];  
    }
}

int cs;
void solve()
{
    int n,m;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        lvl[i] = height[i] = vis[i] = 0;
        adj[i].clear();
    }
    
    for(int i = 1; i < n; i++)
    {
        int a,b;
        cin >> a  >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    int cnt = 0;
    for(int i = 2; i <= n; i++)
    {
        debug(i);
        debug2(height[i],lvl[i]);
        cnt += (n-height[i]-lvl[i]);
    }

    cout << "Case " << ++cs << ": ";
    cout << n-1 << " " << cnt/2 << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}