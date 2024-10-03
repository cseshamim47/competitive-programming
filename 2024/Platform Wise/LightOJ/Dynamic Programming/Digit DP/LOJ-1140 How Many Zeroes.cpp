#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

/* 
is_smaller -> is cur number smaller than R
is_greater -> is cur number greater than L 
*/

string l,r;

int dp[11][2][2][2];
int dp2[11][2][2];
int f2(int pos, bool is_smaller, bool is_greater)
{
    if(pos == l.size()) return 1;
    int &d = dp2[pos][is_smaller][is_greater];
    if(d != -1) return d;

    int end = r[pos]-'0';
    if(is_smaller) end = 9;

    int start = l[pos]-'0';
    if(is_greater) start = 0;

    int ways = 0;
    for(int i = start; i <= end; i++)
    {
        ways += f2(pos+1,(is_smaller | (i < end)),(is_greater | (i > start)));
    }
    return d = ways;
}


int f(int pos, bool has_started, bool is_smaller, bool is_greater)
{
    if(pos == l.size()) return 0;
    int &d = dp[pos][has_started][is_smaller][is_greater];
    if(d != -1) return d;
    int end = r[pos]-'0';
    if(is_smaller) end = 9;

    int start = l[pos]-'0';
    if(is_greater) start = 0;

    int ways = 0;
    for(int i = start; i <= end; i++)
    {
        if(has_started)
        {
            if(i == 0)
            {
                ways += f2(pos+1,(is_smaller | (i < end)),(is_greater | (i > start)))+f(pos+1,has_started,(is_smaller | (i < end)),(is_greater | (i > start)));
            }else 
            {
                ways += f(pos+1,has_started,(is_smaller | (i < end)),(is_greater | (i > start)));
            }
        }else 
        {
            ways += f(pos+1,i,(is_smaller | (i < end)),(is_greater | (i > start)));
        }
    }

    return d = ways;

}

int cs;
void solve()
{
    cin >> l >> r;
    int ans = 0;
    if(stoi(l) == 0)
    {
        ans++;
    }

    reverse(all(l));
    while(r.size() != l.size()) l.push_back('0');
    reverse(all(l));

    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    ans += f(0,0,0,0);
    cout << "Case " << ++cs << ": ";
    cout << ans << endl;


}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}