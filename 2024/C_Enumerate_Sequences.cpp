#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif



vector<int> mp[1000000];
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(2*n,0);
    int tot = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }    
    int cnt = 0;

    mp[0].push_back(-1);
    
    for(int i = 0; i < n; i++)
    {
        tot += v[i];
        tot%=m;
        cnt += mp[tot].size();
        mp[tot].push_back(i);
    }

    if(tot == 0) cnt--;

    debug(cnt);
    int last = tot;
    for(int i = 0; i < n-2; i++)
    {
        tot += v[i];
        tot %= m;

        int l = 0;
        int r = mp[tot].size()-1;
        auto &vect = mp[tot];
        int k = 0;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(vect[mid] >= i+1)
            {
                k = vect.size()-mid;
                r = mid-1;
            }else 
            {
                l = mid+1;
            }
        }
        if(tot == last) cnt--;
        cnt += k;
    }

    cout << cnt << endl;

    
    



}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}