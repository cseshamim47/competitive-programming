#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define endl "\n"
#define all(x) x.begin(),x.end()

// put it under all macros 
#define oset tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > 
#define get_kth_iterator(os, k) os.find_by_order(k) // finds the element at position k
#define get_count(os, val) os.order_of_key(val) // finds how many values are there in the set that are less/greater than given val 
// #define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

struct query{
    int l,r,idx;
    query(){}
    query(int l,int r,int idx){
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    bool operator<(const query &q) const{
        return r < q.r;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    vector<query> k;
    for(int i = 0; i < q; i++) 
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        k.push_back(query(l,r,i));
    } 
    sort(all(k));
    oset os;
    int cr = -1;
    map<int,int> mp;
    vector<int> res(q);
    for(int i = 0; i < q; i++)
    {   
        auto [l,r,idx] = k[i];
        while(cr < r) 
        {
            cr++;
            if(mp.count(v[cr]))
            {
                os.erase(mp[v[cr]]);
            }
            os.insert(cr);
            mp[v[cr]] = cr;
        }

        res[idx] = get_count(os,l-1);
    }

    for(auto x : res) cout << x << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}