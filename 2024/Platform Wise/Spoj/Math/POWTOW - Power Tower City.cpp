#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


int mul(int a, int b, int mod)
{
    a *= b;
    if(a >= mod) return a%mod+mod;
    else return a;
}

int modPow(int b,int p,int mod)
{
    int res = 1;
    while(p)
    {
        if(p%2 == 0)
        {
            b = mul(b,b,mod);
            p /= 2;
        }else 
        {
            res = mul(res,b,mod);
            p--;
        }
    }
    return res;
}

map<int,int> phi;
// O(n*log(n))
int getPhi(int n)
{
    int p = 1; 
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            int k = 1;
            while(n%i == 0)
            {
                k *= i;
                n/=i;
            }
            int ans = k-k/i;
            p *= ans;
        }
    }
    if(n > 1)
    {
        p *= (n-1);
    }
    return p;
}

int f(int a, int b, int mod)
{   
    if(b == 0) return 1;
    if(mod == 1) return 0;
    int k = f(a,b-1,phi[mod]);
    return modPow(a,k,mod);
}

void solve()
{
    int a,b;
    cin >> a >> b;

    
    if(a == 0)
    {
        if(b%2 == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }

    int ans = f(a,b,1000000000);
    if(ans >= 1e9) 
    {
        ans %= 1'000'000'000;
        cout << "..." << setw(9) << setfill('0') << ans << endl;
    }else cout << ans << endl;
}

int32_t main()
{
    int mod = 1e9;
    while(mod > 1)
    {
        phi[mod] = getPhi(mod);
        mod = phi[mod];
    }
    int t = 1;
    cin >> t;
    while(t--) solve();
}