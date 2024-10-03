// https://codeforces.com/gym/104283/problem/F

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int MOD=1000000007;
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }

inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }

inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }

inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

inline int modInverse(int a) { return modPow(a, MOD-2); }

inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }

const int N = 1e5+10;
int fact[N];
void gen()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        MOD = 1000000006;
        fact[i] = modMul(fact[i-1],i);
    }
}

void solve()
{
    int a,b,n;
    cin >> a >> b >> n;
    MOD = 1000000007;

    int ans = modPow(n,fact[min(a,b)]);
    cout << ans << endl;
}

int32_t main()
{

    //    Bismillah
    gen();
    int t = 1;
    cin >> t;
    while(t--) solve();
}