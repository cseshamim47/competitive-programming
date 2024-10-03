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

int n,k;

int dp[1001][1001][2];
int f(int plane, int decay, int direction)
{
    if(plane == 0 || plane == n+1 ||  decay == 1) return 0;
    int &d = dp[plane][decay][direction];
    if(d != -1) return d;

    int res = 0;
    if(direction) // going towards right
    {   
        // right + left + 1
        res = modAdd(f(plane+1,decay,1) , f(plane-1,decay-1,0));
        res = modAdd(res,1);

    }else 
    {
        res = modAdd(f(plane-1,decay,0), f(plane+1,decay-1,1));
        res = modAdd(res,1); 
    }

    return d = res;
}

void solve()
{
    cin >> n >> k;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    cout << modAdd(f(1,k,1),1) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}