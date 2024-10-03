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

char a[1001][1001];
int dp[1001][1001];
int n;

bool isValid(int i, int j)
{
    if(i >= n || j >= n || a[i][j] == '*') return false;
    return true;
}

int f(int i, int j)
{
    if(i == n-1 && j == n-1) return 1;
    int &d = dp[i][j];
    if(d != -1) return d;
    
    int res = 0;
    if(isValid(i,j+1)) 
    {
        res = f(i,j+1);
        normal(res);
    }
    
    
    if(isValid(i+1,j)) res = modAdd(f(i+1,j),res);
    normal(res);

    return d = res;
}

void solve()
{
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    if(a[0][0] == '*') 
    {
        cout << 0 << endl;
        return;
    }
    cout << f(0,0) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}