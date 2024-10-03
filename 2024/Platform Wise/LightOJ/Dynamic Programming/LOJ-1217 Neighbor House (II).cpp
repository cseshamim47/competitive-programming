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
int n;
int a[1001];
int dp[1001][2];

int f(int pos, bool firstHouse)
{
    if(firstHouse && pos == n-1) return 0;
    if(pos >= n) return 0;
    int &d = dp[pos][firstHouse];
    if(d != -1) return d;

    int take = a[pos] + f(pos+2,(pos==0 | firstHouse));
    int nottake = f(pos+1,firstHouse);

    return d = max(take,nottake);

}

int cs;
void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    memset(dp,-1,sizeof dp);
    int ans = f(0,0);
    
    cout << "Case " << ++cs << ": " << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}