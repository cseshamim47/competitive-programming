#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long


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
vector<int> Tree[4*N];
vector<int> arr(N);

vector<int> merge(vector<int> &a, vector<int> &b) 
{
    int i = 0, j = 0; 
    vector<int> res;
    while(i < a.size() && j < b.size())
    {
        if(a[i] <= b[j])
        {
            res.push_back(a[i++]);
        }else 
        {
            res.push_back(b[j++]);
        }
    }
    while(i < a.size()) res.push_back(a[i++]);
    while(j < b.size()) res.push_back(b[j++]);

    return res;
}

void init(int n,int b,int e) // TC : N log N
{
    if(b == e)
    {
        Tree[n].push_back(arr[b]);
        return;
    }

    int mid = (b+e)/2;
    int left = n*2;
    int right = left+1;

    init(left,b,mid);
    init(right,mid+1,e);

    Tree[n] = merge(Tree[left],Tree[right]);
}

int query(int n, int b, int e, int l, int r, int k) // TC : logn * logn
{
    if(r < b or e < l) return 0;

    if(l <= b and e <= r) 
    {
        return lower_bound(all(Tree[n]),k)-Tree[n].begin();
    }

    int mid = (b+e)/2;
    int left = n*2;
    int right = left+1;

    return query(left,b,mid,l,r,k)+query(right,mid+1,e,l,r,k);
}



void solve()
{   
    int n = rng(20)+1;
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
        int l,r,k;
        cin >> l >> r >> k;
        cout << query(1,1,n,l,r,k) << endl;
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}