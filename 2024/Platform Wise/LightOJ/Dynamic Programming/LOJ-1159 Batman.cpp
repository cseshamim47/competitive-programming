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
string a,b,c;
int dp[50][50][50];
int vis[50][50][50];
int cs;
int f(int i, int j, int k)
{
    if(i < 0 || j < 0 || k < 0) return 0;
    int &d = dp[i][j][k];
    int &v = vis[i][j][k];
    if(v == cs) return d;
    v = cs;

    int lcs = 0;
    if(a[i] == b[j] && b[j] == c[k])
    {   
        lcs = 1 + f(i-1,j-1,k-1);
    }else 
    {
        lcs = max(lcs,f(i-1,j,k));
        lcs = max(lcs,f(i,j-1,k));
        lcs = max(lcs,f(i,j,k-1));
        lcs = max(lcs,f(i-1,j-1,k));
        lcs = max(lcs,f(i-1,j,k-1));
        lcs = max(lcs,f(i,j-1,k-1));
    }

    return d = lcs;
}

void solve()
{
    a.clear();
    b.clear();
    c.clear();
    cin >> a >> b >> c;
    cout << "Case " << ++cs << ": ";
    cout << f(a.size()-1, b.size()-1, c.size()-1) << endl;
    
}

int32_t main()
{
    //    Bismillah
    memset(vis,-1,sizeof vis);
    int t = 1;
    cin >> t;
    while(t--) solve();
}