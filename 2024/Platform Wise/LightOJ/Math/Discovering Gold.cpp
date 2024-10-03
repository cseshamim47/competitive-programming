#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int cs;
void solve()
{
    int n;
    cin >> n;
    double x;
    int ss = n;
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(i)
        {
            ans += (x*(1.00/ss));
        }else ans = x;
        ss--;
    }
    cout << "Case " << ++cs << ": ";
    cout << fixed << setprecision(8) << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}