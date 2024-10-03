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

int n;
int a[16][16];
int dp[(1 << 16)];

int f(int mask)
{
    int m = __builtin_popcount(mask); 
    if(m == n)
    {
        return 0;
    }   
    int &d = dp[mask];
    if(d != -1) return d;

    int res = 0;
    for(int w = 0; w < n; w++)
    {
        if((mask & (1 << w))) continue;
        res = max(res, a[m][w]+f(mask|(1 << w)));
    }
    return d = res;
}

int cs;
void solve()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    fill(dp,dp+(1 << n),-1);
    cout << "Case " << ++cs << ": ";
    cout << f(0) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}