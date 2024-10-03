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
    int n,k;
    cin >> n >> k; 
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cnt = 0;
    int pxor = 0;
    map<int,int> mp;
    for(int i = 0; i < n; i++)
    {
        pxor ^= v[i];
        cnt += mp[pxor^k];
        if(pxor == k) cnt++; // when the prefix is equal to k...this line can be erased if we had set mp[0] = 1
        mp[pxor]++;
    }

    cout << cnt << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}