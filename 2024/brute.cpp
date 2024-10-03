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
    for(int i = 0; i < n; i++) v[i] = i;

    do{
        int x = 0;
        bool ok = true;
        for(auto y: v) 
        {
            x ^= y;
            if(x == 0)
            {   
                ok = false;
            }
        }
        if(ok)
        {
            debug(v);
            getchar();
        }
    }while(next_permutation(v.begin(),v.end()));
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}