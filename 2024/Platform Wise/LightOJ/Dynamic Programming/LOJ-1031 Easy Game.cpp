#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[101][101];

int f(int i, int j, vector<int> &v)
{
    if(i > j) return 0;

    int &d = dp[i][j];
    if(d != -1) return d;
    
    int res = -1e5;
    int sum = 0;
    for(int k = i; k <= j; k++)
    {
        sum += v[k];    
        res = max(res,sum-f(k+1,j,v));
    }   

    sum = 0;
    for(int k = j; k >= i; k--)
    {
        sum += v[k];
        res = max(res,sum-f(i,k-1,v));
    }

    return d = res;
}

int cs;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Case " << ++cs << ": ";
    cout << f(0,n-1,v) << endl;

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}