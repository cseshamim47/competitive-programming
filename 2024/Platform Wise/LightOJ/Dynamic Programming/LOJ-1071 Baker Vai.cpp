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

int a[101][101];
int dp[101][101][101];
int vis[101][101][101];
int n,m;
bool isSame(int x1, int y1, int x2, int y2)
{
    if((x1 == x2 && y1 == y2) || x1 == n || x2 == n || y1 == m || y2 == m ) return true;

    return false;
}

int cs = 0;
int f(int x1, int y1, int x2, int y2)
{
    if(isSame(x1,y1,x2,y2))
    {
        return 0;
    }
   

    int &v = vis[x1][y1][x2];
    int &d = dp[x1][y1][x2];
    if(v == cs) return d;
    v = cs;
    

    int dd = 0;
    int rr = 0;
    int dr = 0;
    int rd = 0;

    int sum = a[x1][y1]+a[x2][y2];
    dd = sum + f(x1+1,y1,x2+1,y2);

    rr = sum + f(x1,y1+1,x2,y2+1);

    dr = sum + f(x1+1,y1,x2,y2+1);

    rd = sum + f(x1,y1+1,x2+1,y2);

    return d = max({dd,rr,dr,rd});
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
   

    cout << "Case " << ++cs << ": ";
    cout << a[0][0]+f(1,0,0,1)+a[n-1][m-1] << endl;
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    memset(vis,0,sizeof vis);
    int t = 1;
    cin >> t;
    while(t--) solve();
}