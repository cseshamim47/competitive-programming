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