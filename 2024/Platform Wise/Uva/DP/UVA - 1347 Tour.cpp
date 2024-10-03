#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifndef ONLINE_JUDGE
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

struct point{
    double x,y;
};
double sq(double x)
{
    return x*x;
}

double dist(point a, point b)
{
    return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}

double f(int i, int j, vector<point> &v, vector<vector<double>> &dp)
{
    if(i == v.size()-1 || j == v.size()-1)
    {
        return dist(v[j],v[i]);
    }

    if(dp[i][j] != -1) return dp[i][j];

    int k = max(i,j)+1;
    if(k < v.size()) return dp[i][j] = min(f(i,k,v,dp)+dist(v[j],v[k]), f(k,j,v,dp)+dist(v[i],v[k]));
    return dp[i][j] = 0;
}


void solve()
{
    int n;
    while(cin >> n)
    {
        vector<point> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].x >> v[i].y;
        }
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        cout << fixed << setprecision(2) << f(0,0,v,dp) << endl;
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}