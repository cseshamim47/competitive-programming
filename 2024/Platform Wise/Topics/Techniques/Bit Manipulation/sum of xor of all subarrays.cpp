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

    vector<int> prefXor(n,0);
    int pxor = 0;

    for(int i = 0; i < n; i++)
    {
        pxor ^= v[i];
        prefXor[i] = pxor;
    }

    int res = 0;
    // for(int i = 0; i <= 30; i++)
    // {
    //     map<int,int> mp;
    //     for(int j = 0; j < n; j++)
    //     {
    //         int cur_bit = ((prefXor[j] >> i) & 1);
    //         res += mp[cur_bit^1]*(1 << i);

    //         if(cur_bit == 1) res += (1 << i); // mp[0] = 1 set kora thakle eta lagto na

    //         mp[cur_bit]++;
    //     }
    // }

    // another way

    for(int i = 0; i <= 30; i++)
    {   
        int zero = 1;
        int one = 0;
        for(auto p: prefXor)
        {
            if((p >> i)&1)
            {
                one++;
            }else zero++;
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