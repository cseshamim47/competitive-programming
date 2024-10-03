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


void solve()
{
    deque<char> dq;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        dq.push_back(s[i]);
    }
    int ans = n;
    for(int i = 0; i < n; i++)
    {
        dq.push_back(dq.front());
        dq.pop_front();
        string tmp = "";
        for(auto x : dq) tmp.push_back(x);
        tmp.push_back('#');
        int cnt = 0;
        for(int i = 1; i < n; i++)
        {
            if(tmp[i] == tmp[i-1])
            {
                cnt++;
                for(auto ch = 'a'; ch <= 'z'; ch++)
                {
                    if(ch != tmp[i] && tmp[i+1] != ch)
                    {
                        tmp[i] = ch;
                        break;
                    }
                }
            }
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}