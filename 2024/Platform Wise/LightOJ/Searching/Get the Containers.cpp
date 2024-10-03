#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool f(int mid, vector<int> &v, int m)
{
    int sum = 0;
    for(auto x : v)
    {
        if(mid < x) return false;
        if(sum + x <= mid)
        {
            sum += x;
        }else 
        {
            m--;
            sum = x;
        }
    }
    if(sum) m--;
    return m>=0;
}

int Case;
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 1;
    int r = 1e9;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(f(mid,v,m))
        {
            ans = mid;
            r = mid-1;
        }else 
        {
            l = mid+1;
        }
    }
    printf("Case %lld: ",++Case);
    cout << ans << endl;    
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}