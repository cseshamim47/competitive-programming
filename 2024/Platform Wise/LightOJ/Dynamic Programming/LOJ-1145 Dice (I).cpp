#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define int long long

const int MOD=100000007;
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

int n,k,s;
int dp[2][15001];

int f(int pos, int sum)
{
    if(pos == n) return sum == 0;
    if(sum == 0) return 0;

    int res = 0;
    for(int i = 1; i <= min(k,sum); i++)
    {
        res = modAdd(res,f(pos+1,sum-i));
    }
    return res;
}
int cs;
void solve()
{
    cin >> n >> k >> s;

    memset(dp,0,sizeof dp);
    //for(int i = 0; i <= s; i++) dp[n%2][i] = 1;

     dp[n%2][0] = 1;

    for(int pos = n-1; pos >= 0; pos--)
    {
        int cur = pos%2;
        int next = (pos+1)%2;
        dp[cur][0] = 0;
        for(int sum = 1; sum <= s; sum++)
        {
            int baad = 0;

            if(sum-k-1 >= 0) 
            {
                baad = dp[next][sum-k-1];
            }

            dp[cur][sum] = modSub(dp[next][sum-1],baad);            

            dp[next][sum] = modAdd(dp[next][sum],dp[next][sum-1]);
        }
    }
    cout << "Case " << ++cs << ": ";
    cout << dp[0][s] << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}