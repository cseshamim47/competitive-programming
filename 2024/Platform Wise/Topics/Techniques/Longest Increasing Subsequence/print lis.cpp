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

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
uniform_int_distribution<int> uid(1,lim);
return uid(rang);
}





void longest_increasing_subsequence(int n, vector<int> &v)
{
    // set approach     
    set<int> s;
    for(auto x : v)
    {
        s.insert(x);
        auto it = s.upper_bound(x);
        if(it != s.end()) s.erase(it);
    }
    cout << "lis size is -> " << s.size() << endl;

    vector<int> max_lis_taking_vi;
    vector<int> helper;
    // binary search approach with printing
    for(int i = 0; i < n; i++)
    {
        int lb = lower_bound(all(helper),v[i])-helper.begin();

        if(lb == helper.size()) 
        {
            helper.push_back(v[i]);
        }

        helper[lb] = v[i];
        max_lis_taking_vi.push_back(lb+1);

    }

    debug(max_lis_taking_vi);

    int lis = helper.size();
    vector<int> print_lis;
    for(int i = n-1; i >= 0; i--)
    {
        if(max_lis_taking_vi[i] == lis)
        {
            print_lis.push_back(v[i]);
            lis--;
        }
    }
    reverse(all(print_lis));
    debug(print_lis);
}


void longest_non_decreasing_subsequence(int n, vector<int> &v)
{
    // multiset approach
    multiset<int> ms;
    for(int i = 0; i < n; i++)
    {
        ms.insert(v[i]);
        auto it = ms.upper_bound(v[i]);
        if(it != ms.end()) ms.erase(it);
    }

    cout << "longest non decreasing subsequence -> " << ms.size() << endl;

    // printing 

    vector<int> helper;
    vector<int> max_taking_vi;
    for(int i = 0; i < n; i++)
    {
        int ub = upper_bound(all(helper),v[i])-helper.begin();

        if(ub == helper.size()) helper.push_back(v[i]);

        helper[ub] = v[i];
        max_taking_vi.push_back(ub+1);
    }
    int lis = helper.size();

    vector<int> original;
    for(int i = n-1; i >= 0; i--)
    {
        if(lis == max_taking_vi[i])
        {
            original.push_back(v[i]);
            lis--;
        }
    }
    reverse(all(original));
    debug(original);
}


void prev_vector_way(){

    vector<int> S = {5,10,3,20,1,30,8,40,0};

    debug(S);
    vector<int> prev(S.size(),-1);

    typedef pair<int, int> p;

    vector<pair<int,int>> res;
    for(int i = 0; i < S.size(); i++) {
        // change 0 -> i for longest non-decreasing subsequence
        auto it = lower_bound(all(res), p{S[i], 0});

        if (it == res.end()) res.emplace_back(), it = res.end()-1;
            

        *it = {S[i], i};
        debug(S[i]);
        prev[i] = (it == res.begin() ? 0 : (it-1)->second);
        debug(prev);
    }
    int L = res.size(), cur = res.back().second;
    vector<int> ans(L);
    debug(cur);
    while (L--) ans[L] = S[cur], cur = prev[cur];
    debug(ans);
}


void lis_using_segment_tree(int n, vector<int> &v)
{
    // do later
}


void solve()
{
    int n;
    // cin >> n;
    n = rng(15);
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = rng(10);
    debug(v);

    // longest_increasing_subsequence(n,v);
    // longest_non_decreasing_subsequence(n,v);

    

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}