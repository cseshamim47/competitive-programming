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


// Must use as 1-indexed
const int N = 1e5+100;
vector<int> Tree(N,0);

void add(int idx,int val)
{
    while(idx < N)
    {
        Tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx)
    {
        sum += Tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int rangeQuery(int l, int r)
{
    return query(r)-query(l-1); 
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        add(i+1,val);
    }
    
    while(true)
    {
        int l,r;
        cin >> l >> r;
        cout << rangeQuery(l,r) << endl;
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}