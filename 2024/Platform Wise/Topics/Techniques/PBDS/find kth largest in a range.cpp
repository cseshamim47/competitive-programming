#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#define inf 1e9
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// put it under all macros 
#define oset tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > 
#define get_kth_iterator(os, k) os.find_by_order(k) // finds the element at position k
#define get_count(os, val) os.order_of_key({val,inf}) // finds how many values are there in the set that are less/greater than given val 

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
uniform_int_distribution<int> uid(0,lim-1);
return uid(rang);
}

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

const int N = 2e5+10;
oset mst[4*N];
vector<int> arr(N);


void init(int n,int b,int e) // TC : N log^2 N
{
    if(b == e)
    {
        mst[n].insert({arr[b],b});
        return;
    }

    int mid = (b+e)/2;
    int left = n*2;
    int right = left+1;

    init(left,b,mid);
    init(right,mid+1,e);
    for(int i = b; i <= e; i++)
    {
        mst[n].insert({arr[i],i});
    }
}

int query(int n, int b, int e, int l, int r, int k) // TC : logn * logn
{
    if(r < b or e < l) return 0;

    if(l <= b and e <= r) 
    {
        return get_count(mst[n],k); 
    }

    int mid = (b+e)/2;
    int left = n*2;
    int right = left+1;

    return query(left,b,mid,l,r,k)+query(right,mid+1,e,l,r,k);
}

void update(int n, int b, int e, int i, int dlt, int ins) // TC: logn * logn 
{
    if(i < b || e < i) return;

    if(i == b and i == e) 
    {
        mst[n].erase({dlt,i});
        mst[n].insert({ins,i});
        return;
    }

    int mid = (b+e)>>1;
    int left = n*2;
    int right = left+1;
    update(left,b,mid,i,dlt,ins);
    update(right,mid+1,e,i,dlt,ins);
    mst[n].erase({dlt,i});
    mst[n].insert({ins,i});
}



void solve()
{   
    int n = rng(20)+1;
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        // cin >> arr[i+1];
        arr[i+1] = rng(n);

        cout << arr[i+1] << " ";
    }   
    cout << endl;

    init(1,1,n);

    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l,r,k;
            cin >> l >> r >> k;
            int low = (*get_kth_iterator(mst[1],0)).first;
            int high = (*get_kth_iterator(mst[1],n-1)).first;
            int res = 0;
            debug(low,high);
            while(low <= high)
            {
                int mid = (low+high)/2;
                debug(mid,query(1,1,n,l,r,mid));
                if(query(1,1,n,l,r,mid) >= k)
                {
                    res = mid;
                    high = mid-1;
                }else 
                {
                    low = mid+1;
                }
            }
            cout << res << endl;
        }else 
        {
            int i, val;
            cin >> i >> val;
            update(1,1,n,i,arr[i],val);
            arr[i] = val;
            
        }
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}