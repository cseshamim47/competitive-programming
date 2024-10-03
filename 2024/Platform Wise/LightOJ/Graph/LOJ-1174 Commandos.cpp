#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

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

const int N = 122;
int lvl[2][N];
bool vis[N];
vector<int> adj[N];

void bfs(int source,int t)
{
    memset(vis,false,sizeof vis);
    queue<int> q;
    q.push(source);
    vis[source] = true;
    lvl[t][source] = 0;

    while(q.size())
    {
        auto parent = q.front();
        q.pop();

        for(auto child: adj[parent])
        {
            if(vis[child]) continue;
            lvl[t][child] = lvl[t][parent]+1;
            q.push(child);
            vis[child] = true;
        }
    }
}

int cs;
void solve()
{
    int n,r;
    cin >> n >> r;
    

    for(int i = 0; i < n; i++)
    {
        adj[i].clear();
        lvl[0][i] = lvl[1][i] = 0;
        vis[i] = false;
    }

    for(int i = 0; i < r; i++)
    {
        int a ,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s,d;
    cin >> s >> d;

    bfs(s,0);
    bfs(d,1);

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans,lvl[0][i]+lvl[1][i]);
    }   

    

    cout << "Case " << ++cs << ": ";
    cout << ans << endl;

}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) solve();
}