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
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

void merge(int l, int r, vector<int> &v)
{
    int mid = (l+r)/2;
    vector<int> a;
    for(int i = l; i <= mid; i++)
    {
        a.push_back(v[i]);
    }

    vector<int> b;
    for(int i = mid+1; i <= r; i++)
    {
        b.push_back(v[i]);
    }

    int i = 0;
    int j = 0; 
    while(i < a.size() && j < b.size())
    {
        if(a[i] <= b[j])
        {
            v[l++] = a[i++];
        }else 
        {
            v[l++] = b[j++];
        }
    }

    while(i < a.size()) v[l++] = a[i++];
    while(j < b.size()) v[l++] = b[j++];
}

void merge_sort(int l, int r, vector<int> &v)
{
    int mid = (l+r)/2;
    if(l == r) return;

    merge_sort(l,mid,v);
    merge_sort(mid+1,r,v);

    merge(l,r,v);
}


void solve()
{
    int n = rng(20)+1;
    // cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        // cin >> v[i]; 
        v[i] = rng(n);
    }
    debug(v);

    merge_sort(0,v.size()-1,v);
    for(auto x : v) cout << x << " ";
    cout << endl;

    /* 
    11
    7 5 3 1 4 9 2 0 8 6 2
     */
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}