#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve()
{
    int r;
    cin >> r;
    int l = 1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        cout << "guess " << mid << endl;
        string a;
        cin >> a;
        if(a == "correct")
        {
            break;
        }
        if(a == "low")
        {
            l = mid+1;
        }else 
        {
            r = mid-1;
        }

    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}