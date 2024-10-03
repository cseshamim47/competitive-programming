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

int dp[12][2];
int f(int pos, bool is_smaller, string &s)
{
    if(pos == (s.size()+1)/2)
    {
        return 1;
    }

    int &d = dp[pos][is_smaller];
    if(d != -1) return d;

    int end = s[pos]-'0';
    if(is_smaller) end = 9;
    int start = 0;
    if(pos == 0) start = 1;

    int pre = 0;
    for(int i = start; i <= end; i++)
    {
        pre += f(pos+1,(is_smaller | (i < end)),s);
    }

    return d = pre;
}

bool pal(string &s)
{
    string t = "";
    for(int i = 0; i < (s.size()+1)/2; i++) t.push_back(s[i]);
    string tmp = t;
    if(s.size()%2 != 0)
    {
        tmp.pop_back();
    }

    if(tmp.size())
    reverse(all(tmp));

    t += tmp;

    return stoll(t) > stoll(s);
}

vector<int> pre = {0,9,9,90,90,900,900,9000,9000};

int cs;
void solve()
{
    int l,r;
    cin >> l >> r;
    if(l > r) swap(l,r);

    string s = to_string(r);
    memset(dp,-1,sizeof dp);
    int r_res = f(0,0,s);
    r_res -= pal(s);

    for(int i = 1; i <= s.size()-1; i++)
    {
        r_res += pre[i];
    }
    r_res++;


    int l_res = 0;
    if(l > 0)
    {
        s = to_string(l-1);
        memset(dp,-1,sizeof dp);
        l_res = f(0,0,s);
        l_res -= pal(s);
        for(int i = 1; i <= s.size()-1; i++)
        {
            l_res += pre[i];
        }
        l_res++;
    }

    cout << "Case " << ++cs << ": ";
    cout << r_res-l_res << endl;    


}

int32_t main()
{
    //    Bismillah
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(pre.size() < 22) 
    {
        int k = pre.back()*10;
        pre.push_back(k);
        pre.push_back(k);
    }

    int t = 1;
    cin >> t;
    while(t--) solve();
}