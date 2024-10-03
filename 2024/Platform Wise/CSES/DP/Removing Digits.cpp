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
int dp[1000005];
int f(int n)
{
    // debug(n);
    if(n < 0) return 1e7;
    if(n == 0) return 0;
    int &d = dp[n];
    if(d != -1) return d;
    int cn = n;
    int res = 1e7;
    while(cn)
    {
        if(n-cn%10 != n)
        res = min(res,f(n-cn%10)+1);
        cn/=10;
    }

    return d = res;
}

void solve()
{
    int n;
    cin >> n;

    cout << f(n) << endl;
}

int32_t main()
{
    //    Bismillah
    memset(dp,-1,sizeof dp);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}