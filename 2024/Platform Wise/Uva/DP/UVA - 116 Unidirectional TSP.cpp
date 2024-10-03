#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifndef ONLINE_JUDGE
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

int vis[11][101];
int cs = 1;
int f(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp,vector<vector<int>> &path)
{
    int n = v.size();
    int m = v[0].size();
    i %= n;
    if(i == -1) i = n-1;
    if(j == m)
    {
        return 0;
    }
    int &d = dp[i][j];
    int &vs = vis[i][j];
    int &p = path[i][j];
    if(vs == cs) return d;
    vs = cs;

    int r = v[i][j] + f(i,j+1,v,dp,path);
    int rd = v[i][j] + f(i+1,j+1,v,dp,path);
    int ru = v[i][j] + f(i-1,j+1,v,dp,path);

    int mn = min({r,rd,ru});
    vector<pair<int,int>> t;
    if(mn == r) t.push_back({i,0});
    if(mn == ru) t.push_back({i-1,-1});
    if(mn == rd) t.push_back({i+1,+1});
    for(auto &[x,y] : t)
    {
        if(x < 0) x = n-1;
        if(x == n) x = 0;
    }
    sort(all(t));
    p = t[0].second;

    return d = min({r,rd,ru});
}

void solve()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<vector<int>> v(n,vector<int>(m));
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> path(n,vector<int>(m,-2));
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        int start =0;
        
        int ans = 1e15;
        for(int i = 0; i < n; i++)
        {
            int x = f(i,0,v,dp,path);
            if(ans > x)
            {
                start = i;
                ans = x;
            }
        }

        int i = start;
        int j = 0;
        while(true)
        {
            if(j == m-1)
            {
                cout << i+1 << endl;
                break;
            }
            cout << i+1 << " ";
            i += path[i][j];
            if(i < 0) i = n-1;
            if(i == n) i = 0;
            j++;
        }
        cout << ans << endl;
        cs++;
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    memset(vis,0,sizeof vis);
    // cin >> t;
    while(t--) solve();
}

/* 
 [ 1 1 1 1 1 1 ]
 [ 0 1 1 1 1 1 ]
 [ 0 0 1 1 1 1 ]
 [ 0 0 1 1 1 1 ]
 [ 0 1 1 1 1 1 ]

 [ 11 11 7 7 11 6 ]
 [ 0 8 15 13 13 1000000000000004 ]
 [ 0 0 11 14 15 1000000000000005 ]
 [ 0 0 7 8 5 6 ]
 [ 0 14 8 6 5 3 ]


 [ 3 2 1 1 1 1 ]
 [ 0 1 1 1 1 1 ]
 [ 0 0 3 3 3 1 ]
 [ 0 0 3 2 3 3 ]
 [ 0 1 2 1 2 2 ]
 ]


 [ 1  0 -1 -1 -1 -1 ]
 [ -2 -1 -1 -1 -1 -1 ]
 [ -2 -2 1 1 1 -1 ]
 [ -2 -2 1 0 1 1 ]
 [ -2 -1 0 -1 0 0 ]
 ]

 3 6
 1 3 1 5 1 3
 1 2 2 3 2 20 
 1 1 2 1 3 10

  */