#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define int long long

#ifdef SHAMIM_AHMED
#include <G:\Desktop Items\STATION\CPP\debug.h>
#else
#define debug(x...)
#define debug2(x...)
#define debug3(x...)
#endif

int f(string &s)
{
    int n = s.size();
    s.push_back('#');
    s.push_back('#');
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != s[i] && ch != s[i + 1])
                {
                    s[i] = ch;
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if(n == 2)
    {
        if(s[0] == s[1])
        {
            cout << 1 << endl;
        }else cout << 0 << endl;
        return;
    }

    bool same = true;
    for(int i = 1; i < n; i++)
    {
      if(s[i] != s[i-1]) same = false;
    }
    if(same)
    {
      cout << n/2 << endl;
      return;
    }

    vector<int> pref(n+1, 0);
    vector<int> suff(n+1, 0);
    string t = s;
    int tot = 0;
    t.push_back('#');
    t.push_back('#');
    t.push_back('#');
    for (int i = 1; i < n; i++)
    {
        if (t[i] == t[i - 1])
        {
            tot++;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != t[i] && ch != t[i + 1])
                {
                    t[i] = ch;
                    break;
                }
            }
        }
        pref[i] = tot;
    }
    t = '#' + s;
    tot = 0;
    int idx = n-2;
    for (int i = t.size() - 2; i >= 1; i--)
    {
        if (t[i] == t[i + 1])
        {
            tot++;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != t[i] && ch != t[i - 1])
                {
                    t[i] = ch;
                    break;
                }
            }
        }
        suff[idx--] = tot;
    }

    int start = 0;
    int end = 0;
    int i = 0;
    while(i < n && s[i] == s[0]) start++,i++;
    i = n-1;
    while(i >=0 && s[i] == s[n-1]) end++,i--;



    int ans = pref[n-1];
    for(int i = 1; i < n; i++)
    {
        int cur = pref[i-1]+suff[i];
        if(s[n-1] == s[0]) 
        {
            int tot = end+start;
            int last = n-i;
            
            if(start > i)
            {
                tot -= (start-i);
            }else if(last <= end)
            {
                tot -= (end-last);
            }
            if((tot)%2 == 0) cur++;
        }
        ans = min(ans,cur);
    }

    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}