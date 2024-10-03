#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

const int MOD=1000000007;
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }

inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }

inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }

inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

inline int modInverse(int a) { return modPow(a, MOD-2); }

inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }


#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

int f(int n,vector<int> &dp)
{
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 3;
    if(dp[n] != -1) return dp[n];

    int way1 = f(n-1,dp);
    int way2 = modMul(f(n-2,dp),modMul(n-1,2));

    return dp[n] = modAdd(way1,way2);
}

void solve()
{
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0; i < k; i++)
    {
        int x,y;
        cin >> x >> y;
        if(x != y) cnt+=2;
        else cnt++;
    }

    n -= cnt;
    vector<int> dp(n+1,-1);
    cout << f(n,dp) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}