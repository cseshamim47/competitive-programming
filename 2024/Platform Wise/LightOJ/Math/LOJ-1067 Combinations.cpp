#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int mod = 1000003;

int modMul(int a,int b)
{
    a *= b;
    a %= mod;
    if(a < 0) a += mod;
    return a;
}

int modPow(int b, int p)
{
    int res = 1;
    while(p)
    {
        if(p%2==0)
        {
            b = modMul(b,b);
            p/=2;
        }else 
        {
            res = modMul(res,b);
            p--;
        }
    }
    return res;
}

const int N = 1e6+5;
int fact[N];
int ifact[N];


void gen()
{   
    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = modMul(fact[i-1],i);
        ifact[i] = modMul(ifact[i-1], modPow(i,mod-2));
    }
}

int cs;
void solve()
{
    int n,r;
    cin >> n >> r;
    int ans = modMul(fact[n],modMul(ifact[n-r],ifact[r]));

    cout << "Case " << ++cs << ": ";
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