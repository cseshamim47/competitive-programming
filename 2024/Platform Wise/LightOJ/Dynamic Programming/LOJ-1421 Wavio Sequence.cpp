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


int cs;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> left_to_right;
    vector<int> lis;
    for(int i = 0; i < n; i++)
    {
        if(lis.size() == 0)
        {
            lis.push_back(v[i]);
        }else 
        {
            int lb = lower_bound(all(lis),v[i])-lis.begin();
            if(lb == lis.size()) lis.push_back(v[i]);
            else lis[lb] = v[i];
        }

        left_to_right.push_back(lis.size());
    }

    vector<int> right_to_left;
    lis.clear();
    for(int i = n-1; i >= 0; i--)
    {
        if(lis.size() == 0)
        {
            lis.push_back(v[i]);
        }else 
        {
            int lb = lower_bound(all(lis),v[i])-lis.begin();
            if(lb == lis.size()) lis.push_back(v[i]);
            else lis[lb] = v[i];
        }

        right_to_left.push_back(lis.size());
    }
    reverse(all(right_to_left));
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(left_to_right[i] == right_to_left[i])
        {
            ans = max(ans,left_to_right[i]);
        }
    }
    ans *= 2;
    ans--;
    cout << "Case " << ++cs << ": ";
    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}