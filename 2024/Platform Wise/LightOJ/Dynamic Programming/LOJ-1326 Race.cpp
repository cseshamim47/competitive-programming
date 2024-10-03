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

const int MOD=10056;
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }

inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }

inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }

inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

inline int modInverse(int a) { return modPow(a, MOD-2); }

inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }

const int N = 1e3+5;
int ncr[1001][1001];


int nCr(int n, int r)
{
    if(n < r) return 0;
    if(r == 0 || r == n) return 1;
    if(ncr[n][r] != -1) return ncr[n][r];
    return ncr[n][r] = modAdd(nCr(n-1,r-1),nCr(n-1,r));
}

int dp[N];

int f(int n)
{
    if(n == 0) return 1;
    int &d = dp[n];
    if(d != -1) return d;
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        res = modAdd(res,modMul(nCr(n,i),f(n-i)));
    }

    return d = res;
}
int cs;
void solve()
{
    int n;
    cin >> n;
    cout << "Case " << ++cs << ": ";
    cout << f(n) << endl;
}

int32_t main()
{
    //    Bismillah
    memset(ncr,-1,sizeof ncr);
    memset(dp,-1,sizeof dp);
    
    // f(10);
    int t = 1;
    cin >> t;
    while(t--) solve();
}
