// https://lightoj.com/problem/lcm-from-1-to-n

/* 
    -> dont use vector when the Memory limit is tight
    -> bitwise sieve can generate upto 1e8 

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ll long long int

ll MOD= (1ll << 32);
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }


const int MX = 1e8+5;
bitset<MX> is_prime;
vector<int> prime;

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

vector<pair<ll,int>> v;

int cs;

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    primeGen(1e8);
   
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        v.push_back({x,i});
    }
    sort(all(v));
    
    int idx = 0;
    int k = 0;
    ll cum = 1;
    while(idx < t)
    {
       
        if(k < prime.size() && prime[k] <= v[idx].first)
        {
            cum = modMul(cum, prime[k++]);   
        }else 
        {
            ll ans = cum;
            for(ll x: prime)
            {
                if(x*x > v[idx].first) break;
                ll p = x*x;
                while(p <= v[idx].first)
                {
                    ans = modMul(ans, x);
                    p *= x;
                }
            }
            normal(ans);
            v[idx].first = ans;
            idx++;
        }
        
    }

    sort(all(v),[&](pair<ll,int> a, pair<ll,int> b) 
    {
        return a.second < b.second;
    });

    for(int i = 0; i < t; i++)
    {
        cout << "Case " << ++cs << ": ";
        cout << v[i].first << endl;
    }
}



/* 

another approach

// https://lightoj.com/problem/lcm-from-1-to-n
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ll long long

const int MX = 1e8+5;
bitset<MX> is_prime;
vector<int> prime;
unsigned int cum[MX];

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
        if ( is_prime[i] == 1 ) 
        {
            prime.push_back ( i );
        }
    }

    unsigned int c = 1;
    int idx = 0;
    for(auto x : prime)
    {
        c = (c*x);
        cum[idx++] = c;
    }


}

int cs;

void solve()
{
    int n;
    cin >> n;
    
    int ub = upper_bound(all(prime),n)-prime.begin();
    ub--;

    unsigned int ans = cum[ub];

    cout << "Case " << ++cs << ": ";
    for(ll x : prime)
    {
        if(x*x > n) break;

        int cnt = 0;
        int val = n;
        while(val >= x)
        {
            val /= x;
            cnt++;
        }

        ans = (ans * pow(x,cnt-1));
    }

    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    primeGen(1e8);
    int t = 1;
    cin >> t;
    while(t--) solve();
}


*/