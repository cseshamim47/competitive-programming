#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }   

    int res = 0;

    for(int i = 0; i < 30; i++)
    {
        int one = 0;
        int zero = 0;
        for(int j = 0; j < n; j++)
        {
            if((v[j] >> i) & 1)
            {
                one++;
            }else 
            {
                zero++;
            }
        }

        res += (one*zero*(1 << i));
    }
    cout << res << endl;
}


int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}