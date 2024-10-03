#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()

int cs;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));

    int ans = 0;

    for(int i = 0; i+1 < n; i++)
    {
        for(int j = i+2; j < n; j++)
        {
            int gap = v[j]-v[i];
            int l = i+1;
            int r = j-1;
            int lb = upper_bound(v.begin()+i+1, v.end(), gap)-v.begin();
            ans += (j-lb);
        }
    }
    cout << "Case " << ++cs << ": ";
    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}