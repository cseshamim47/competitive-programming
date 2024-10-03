#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int legendre(int n)
{
    int five = 5;
    int ans = 0;
    while(n/five > 0)
    {
        ans += n/five;
        five *= 5;
    }
    return ans;
}

int Case;
void solve()
{
    int n;
    cin >> n;
    int l = 5;
    int r = 1e9;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(legendre(mid) >= n)
        {
            ans = mid;
            r = mid-1;
        }else 
        {
            l = mid+1;
        }
    }

    printf("Case %lld: ",++Case);
    if(legendre(ans) == n)
    {
        cout << ans << endl;
    }else cout << "impossible" << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}