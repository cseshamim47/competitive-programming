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

int f(int pos,int w, vector<int>&v, vector<int> &dp)
{
    if(pos == v.size()) return 0;
    int &d = dp[pos];
    if(d != -1) return d;

    int res = 1e5;
    int ub = upper_bound(all(v),v[pos]+w)-v.begin();
    return d = min(f(pos+1,w,v,dp)+1, f(ub,w,v,dp)+1);
}

int cs;
void solve()
{
    int n,w;
    cin >> n >> w;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        v[i] = y;
    }
    sort(all(v));
    vector<int> dp(n,-1);
    cout << "Case " << ++cs << ": ";
    cout << f(0,w,v,dp) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}