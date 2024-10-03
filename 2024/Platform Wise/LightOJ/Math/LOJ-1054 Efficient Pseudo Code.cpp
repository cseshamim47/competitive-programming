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



const int MX = 50000+123;
bitset<MX> is_prime;
vector<int> prime;

// TC: O(nlog(log(n)))
void primeGen ( int n ) 
{
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;

    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 ) {
        if ( is_prime[i] == 1 ) {
            for ( int j = i*i; j <= n; j += ( i + i ) ) {
                is_prime[j] = 0;
            }
        }
    }

    is_prime[2] = 1;
    prime.push_back (2);

    for ( int i = 3; i <= n; i += 2 ) {
        if ( is_prime[i] == 1 ) prime.push_back ( i );
    }
}




// ** primeGen(n)
// TC : O(sqrt(n))
map<int,int> primeFactorization(int n)
{
    map<int,int> pf;
    for(auto x : prime)
    {
        if(x*x > n) break;

        while(n%x == 0)
        {
            n/=x;
            pf[x]++;
        }
    }
    if(n > 1) pf[n]++;
    return pf;
}


int sumdiv(int p,int n)
{
    n++;
    assert(n < 1e16);
    n %= (MOD-1);
    int ans = modSub(modPow(p,n),1);
    // debug(ans);
    ans = modDiv(ans,modSub(p,1));
    return ans;
}

int cs;
void solve()
{
    int n,m;
    cin >> n >> m;


    auto pf = primeFactorization(n);
    int k = 0;
    int last = 1;
    int ans = 1;

    for(auto [x,y] : pf)
    {
        ans = modMul(ans,sumdiv(x,(y*m)));
    }

    cout << "Case " << ++cs << ": ";
    cout << ans << endl;

}

int32_t main()
{
    //    Bismillah
    primeGen(50000);
    // cout << SOD(144) << endl;
    int t = 1;
    cin >> t;
    while(t--) solve();
}