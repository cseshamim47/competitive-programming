#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(i) i.begin(),i.end()
// #define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(i...) 
    #define debug2(i...) 
    #define debug3(i...)
#endif

struct point{
    int i,j;
    point(){}
    point(int i, int j){this->i = i; this->j = j;}
};

int dist(point a, point b)
{
    return max(abs(a.i-b.i),abs(a.j-b.j));
}

int dp[(1 << 16)][16];
int vis[(1 << 16)][16];
int cs;
int f(int mask, int prev, vector<point> &p)
{
    int pos = __builtin_popcount(mask);
    // debug(pos,p.size());
    if(pos == p.size())
    {
        return dist(p[prev],p[0]);
    }

    int &d = dp[mask][prev];
    int &v = vis[mask][prev];
    if(v == cs) return d;
    v = cs;

    int res = 1e7;
    for(int i = 1; i < p.size(); i++)
    {
        if((mask & (1 << i))) continue;

        res = min(res,dist(p[i],p[prev])+f((mask | (1 << i)), i, p));
    }

    return d = res;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<point> p;
    p.push_back(point(0,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if(ch == 'x')
            {
                p[0].i = i;
                p[0].j = j;
            }
            if(ch == 'g')
            {
                p.push_back(point(i,j));
            }
        }
    } 

    cout << "Case " << ++cs << ": ";
    cout << f(1,0,p) << endl;
}

int32_t main()
{
    //    Bismillah
    memset(vis,-1,sizeof vis);
    int t = 1;
    cin >> t;
    while(t--) solve();
}