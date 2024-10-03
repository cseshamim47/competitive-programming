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

const int N = 22;
int n;
int a[N][4];
int dp[N][4];

int f(int pos,int prev)
{
    if(pos == n+1) return 0;
    int &d = dp[pos][prev];
    if(d != -1) return d;
    int res = 1e8;
    for(int j = 1; j <= 3; j++)
    {
        if(prev == j) continue;

        res = min(res,a[pos][j]+f(pos+1,j));
    }
    return d = res;
}

int cs;
void solve()
{
    cin >> n;
    memset(dp,-1,sizeof dp);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Case " << ++cs << ": ";
    cout << f(1,0) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}