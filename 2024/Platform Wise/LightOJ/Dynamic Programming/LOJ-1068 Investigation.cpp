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

string s[2];
int k;

int dp[10][90][90][2][2][2];
int f(int pos, int sum, int prod,bool flag, bool taken, int t)
{
    string &str = s[t];
    if(pos == str.size())
    {
        return sum == 0 && prod == 0 && taken;
    }

    int &d = dp[pos][sum][prod][flag][taken][t];
    if(d != -1) return d;

    int lim = 9;
    if(flag == false) lim = str[pos]-'0';
    int ans = 0;
    for(int i = 0; i <= lim; i++)
    {
        ans += f(pos+1,(sum+i)%k, (prod*10 + i)%k, (flag | (i < lim)),(i != 0 | taken),t);
    }

    return d = ans;

    
}

int cs;
void solve()
{
    cin >> s[0] >> s[1] >> k;
    
    cout << "Case " << ++cs << ": ";
    if(k > 90) 
    {
        cout << 0 << endl;
        return;
    }

    memset(dp,-1,sizeof dp);

    int r = f(0,0,0,false,false,1);
    int l = f(0,0,0,false,false,0);
    int ans = r-l;
    int a = 0;
    int sum = 0;
    for(auto x: s[0])
    {
        a *= 10;
        a += (x-'0');
        sum += (x-'0');
    }
    if(sum%k == 0 && a%k == 0) ans++;
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