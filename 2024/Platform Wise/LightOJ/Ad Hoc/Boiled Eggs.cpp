#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int cs;
void solve()
{
    int n,p,q;
    cin >> n >> p >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int w = 0;
    int ans = 0;
    for(int i = 0; i < min(p,n); i++)
    {
        if(w + v[i] <= q)
        {
            ans++;
            w += v[i];
        }else break;
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