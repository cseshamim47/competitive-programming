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

int dp[100005];
int n,k;
int f(int pos, vector<int> &v)
{
    if(pos >= v.size())
    {
        return 0;
    }

    int &d = dp[pos];
    if(d != -1) return d;


    int l = pos;
    int r = v.size()-1;
    int idx = pos;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(v[mid]-v[pos] <= k*2)
        {
            idx = mid;
            l = mid+1;
        }else 
        {
            r = mid-1;
        }
    }

    if(idx-pos+1 < 3)
    {
        return d = n;
    }else 
    {
        int res = 1+f(idx+1,v);
        if(idx-pos >= 3) res = min(res,1+f(idx,v));
        if(idx-pos-1 >= 3) res = min(res,1+f(idx-1,v));
        return d = res;
    }
}

int cs;
void solve()
{
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x: v) cin >> x;

    sort(all(v));   

    fill(dp,dp+n,-1);
    int ans = f(0,v);
    if(ans >= n) ans = -1;
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