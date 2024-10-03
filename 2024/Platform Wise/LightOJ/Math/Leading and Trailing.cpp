#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int MOD=1000000007;
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }

inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }

inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }

inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

inline int modInverse(int a) { return modPow(a, MOD-2); }

inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }


/* 
Given n and k, find first and last 3 digits of n^k.

last 3 digits can be found easily. -> n^k mod 1000 

first 3 digits can be found by using logarithm. 

[log means log10]

log(n^k) = k*log(n) = p
10^p = n^k

k*log(n) will be in form : abc.cdefg -> [15.412314];
abc--- indicates how many digits the numbers will be.

so 10^5.20696342 will be 5+1 = 6 digits number. +1 because of decimal part. 

10^abc.cdefg = 10^abc   *   10^0.cdefg

we know, x*10^k = x[k zeroes];  -> 5*10^3 = 5000

in similar way we can ignore 10^abc and now can only think of 10^0.cdefg
let 10^0.cdefg = x.some numbers 

so x will be our first digit. x*10 will be second digit. x*100 will be third one. 

try 11^5 to understand. 
*/


int cs;
void solve()
{
    int b,n;
    cin >> b >> n;
    MOD = 1000;
    int last = modPow(b,n);
    int d = n*log10(b);
    double p = n*log10(b)-d;
    double first = pow(10,p);

    cout << "Case " << ++cs << ": ";

    int k = first;
    for(int i = 0; i < 3; i++)
    {
        int f = first;
        f %= 10;
        cout << f;
        first *= 10;
    }

    cout << " ";
    
    if(last/100 == 0) cout << 0;
    if(last/10 == 0) cout << 0;
    cout << last;
    cout << endl;

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}