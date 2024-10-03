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

// Segment Tree with Lazy Propagation start
const int mx = 2e5+10;
int arr[mx];
struct
{
    int sum,prop;
}Tree[mx*4];

void init(int node, int b, int e) // O(NlogN)
{
    if(b==e)
    {
        Tree[node].sum = 0;
        Tree[node].prop = 0;
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    init(left,b,mid);
    init(right,mid+1,e);
    Tree[node].sum = Tree[left].sum+Tree[right].sum;    
    Tree[node].prop = 0;    
}

void push(int node, int b, int e)
{
    if(b != e)
    {
        int mid = (b+e)/2;
        int left = node*2;
        int right = left+1;
        Tree[left].sum = (mid-b+1)*Tree[node].prop;
        Tree[right].sum = (e-mid)*Tree[node].prop;
        Tree[left].prop = Tree[node].prop;
        Tree[right].prop = Tree[node].prop;
    }
    Tree[node].prop = 0;
}

void update(int node,int b, int e, int l, int r, int val) // O(4*logN)
{
    if(Tree[node].prop != 0)
    {
        push(node,b,e);
    }
    if(l > e || r < b) return;
    if(l <= b && r >= e)
    {
        Tree[node].sum = (val*(e-b+1));
        Tree[node].prop = val;
        if(Tree[node].prop != 0)
        {
            push(node,b,e);
        }
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    update(left,b,mid,l,r,val);
    update(right,mid+1,e,l,r,val);
    Tree[node].sum = Tree[left].sum+Tree[right].sum;  
}

int query(int node,int b,int e,int l,int r) // O(4*logN)
{
    if(Tree[node].prop != 0)
    {
        push(node,b,e);
    }
    if(l > e || r < b) return 0;
    if(l <= b && r >= e)
    {
        return Tree[node].sum;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    int val1 = query(left,b,mid,l,r);
    int val2 = query(right,mid+1,e,l,r);
    return val1 + val2;
}
// Segment Tree with Lazy Propagation end

int cs;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &[l,r]: v)
    {
        cin >> l >> r;
    }
    init(1,1,2*n);
    int ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        auto [l,r] = v[i];
        if(query(1,1,2*n,l,r) == (r-l+1)) continue;
        else 
        {
            ans++;
            update(1,1,2*n,l,r,1);
        }
    }
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