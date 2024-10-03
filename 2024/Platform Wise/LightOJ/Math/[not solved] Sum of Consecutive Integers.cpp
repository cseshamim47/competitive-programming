#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool f(int n, int i)
{
    int a = (n/i) - (i-1);
    if(a <= 0) return false;
    if(a%2 == 0)
    {
        a /= 2;
    }else return false;
    return i > 1;

}

int cs;
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    n *= 2;
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            
            ans += f(n,i);
            // if(n/i != i)
            // ans += f(n,n/i);

            // cout << i << " " << f(n,i) << endl;
            // cout << f(n,i) << endl;
            // cout << f(n,n/i) << endl;
        }
    }

    cout << "Case " << ++cs << ": ";
    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}