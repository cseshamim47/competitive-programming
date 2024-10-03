#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pi 3.141592653589793238462643383279502884197

void solve()
{
    double R,n;
    cin >> R >> n;
    double c = 2*pi*R;
    double l = 0;
    double r = 1e4;
    int loop = 200;
    while(loop--)
    {
        double mid = (l+r)/2.0;
        if(c-(2*mid*n) <= 0.000000001)
        {
            r = mid;
        }else 
        {
            l = mid;
        }
    }

    cout << l << endl;

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}