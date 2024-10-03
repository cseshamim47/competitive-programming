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

pair<int,int> f(int pos,int sum, const vector<int> &v,vector<vector<pair<int,int>>>&dp)
{
    if(sum == 0) return {0,0};
    if(pos < 0) return {0,0};

    auto &d = dp[pos][sum];
    if(d != make_pair(-1,-1)) return d;

    pair<int,int> take = {0,0};
    pair<int,int> nottake = {0,0};

    if(sum >= v[pos]) 
    {
        take = f(pos-1,sum-v[pos],v,dp);
        take.first++;
        take.second += v[pos];
    }

    nottake = f(pos-1,sum,v,dp);

    return d = max(take,nottake);
}

int cs;
void solve()
{
    int n,t;
    cin >> n >> t;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sum = min(sum,t);
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(sum+1,{-1,-1}));
    if(t == sum) sum--;
    auto [cnt,sang] = f(n-1,sum,v,dp);
    cout << "Case " << ++cs << ": ";
    cout << cnt+1 << " " << sang+678 << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}