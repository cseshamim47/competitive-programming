#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()

int Case;
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    printf("Case %lld: \n",++Case);
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int ans = upper_bound(all(v),b) - v.begin();
        ans -= lower_bound(all(v),a) - v.begin();
        cout << ans << endl;
    }
    
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}