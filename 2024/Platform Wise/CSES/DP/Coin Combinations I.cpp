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

const int MOD=1000000007;
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }

inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }

inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }

inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

inline int modInverse(int a) { return modPow(a, MOD-2); }

inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }

int dp[1000090];
int f(int target, vector<int> &c)
{
    if(target < 0) return 0;
    if(target == 0) return 1;
    int &d = dp[target];
    if(d != -1) return d;

    int res = 0;
    for(int i = 0; i < c.size(); ++i)
    {
        res = modAdd(f(target-c[i],c),res);
    }
    return d = res;
}

void solve()
{
    int n,x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int ans = f(x,c);
    normal(ans);
    cout << ans  << endl;
    
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    memset(dp,-1,sizeof dp);
    // cin >> t;
    while(t--) solve();
}