#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
// #define int long long

#ifdef SHAMIM_AHMED
#include <G:\Desktop Items\STATION\CPP\debug.h>
#else
#define debug(x...)
#define debug2(x...)
#define debug3(x...)
#endif

int n;
string a, b;
string dp[101][101];
int vis[101][101];
int cs;

string f(int i, int j)
{
    if(i == a.size() || j == b.size()) return "";

    string &d = dp[i][j];
    int &vs = vis[i][j];
    if(vs == cs) return d;
    vs = cs;

    if(a[i] == b[j]) return d = a[i] + f(i+1,j+1);
    string aa = f(i+1,j);
    string bb = f(i,j+1);

    if(aa.size() == bb.size())
    {
        if(aa < bb) return d =  aa;
        else return d = bb;
    }else 
    {
        if(aa.size() < bb.size()) return d = bb;
        else return d = aa;
    }

}

void solve()
{
    cin >> a >> b;
    string res = f(0,0);
    
    cout << "Case " << ++cs << ": ";
    if(res.size() == 0) 
    {
        cout << ":(" << endl;
    }else cout << res << endl;


}

int32_t main()
{
    //    Bismillah
    memset(vis,-1,sizeof vis);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}