#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif
int n;
int a[16][16];
vector<int> v(16);
int dp[42768];
int vis[42768];

int cs;
int f(int mask)
{
    int dead = __builtin_popcount(mask);
    if(dead == n) return 0;

    int &visited = vis[mask];
    int &d = dp[mask];
    if(visited == cs) return d;
    visited = cs;

    vector<int> max_gun(n,1);
    for(int i = 0; i < n; i++)
    {
        if((mask & (1 << i)))
        {
            for(int j = 0; j < n; j++)
            {
                max_gun[j] = max(max_gun[j],a[i][j]);
            }
        }
    }
    int res = 1e15;
    for(int i = 0; i < n; i++)
    {
        if((mask & (1 << i)) == 0)
        {
            int health = v[i];
            int power = max_gun[i];
            int cnt = (health+power-1)/power + f((mask | (1 << i)));
            res = min(res,cnt);
        }
    }
    return d = res;
}

void solve()
{
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch-'0';
        }
    }

    cout << "Case " << ++cs << ": ";
    cout << f(0) << endl;

    
}

/* 


 */

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    memset(vis,0,sizeof vis);
    memset(dp,0,sizeof dp);
    int t = 1;
    cin >> t;
    while(t--) solve();
}