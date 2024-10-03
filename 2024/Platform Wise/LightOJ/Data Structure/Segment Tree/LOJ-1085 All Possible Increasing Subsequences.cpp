/* 
ith position e koto gula increasing subsequence ase 
we first compute count of increasing subsequences ending at every index. Finally, we return sum of all values (In LCS problem, we return max of all values).
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


const int MOD=1000000007;
inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }

inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }

inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }

inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }

inline int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }

inline int modInverse(int a) { return modPow(a, MOD-2); }

inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }

  /// Segment Tree Start
const int MX = 2e5+10;
int arr[MX];
int Tree[MX*4];

void init(int node, int b, int e)  // O(n) --> 2n nodes
{
    if(b==e)
    {
        Tree[node] = 0;
        return;
    }
    int Left = node*2; 
    int Right = (node*2)+1; 
    int mid = (b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    Tree[node] = modAdd(Tree[Left] , Tree[Right]);
}

int query(int node, int b, int e, int l, int r) // O(4*Log(n))
{
    if(l > e || r < b) return 0;
    if(l<=b && e<=r)
    {
        return Tree[node];
    }

    int Left = node*2;
    int Right = (node*2)+1;
    int mid = (b+e)/2;
    int leftTreeVal = query(Left,b,mid,l,r);
    int rightTreeVal = query(Right,mid+1,e,l,r);
    return modAdd(leftTreeVal,rightTreeVal);
}

void update(int node, int b, int e, int i, int val) // O(LogN)
{
    if(i > e || i < b) return;
    if(b>=i && e<=i)
    {
        Tree[node] += val;
        return;
    }

    int Left = node*2;
    int Right = (node*2)+1;
    int mid = (b+e)/2;
    update(Left,b,mid,i,val);
    update(Right,mid+1,e,i,val);
    Tree[node] = modAdd(Tree[Left] , Tree[Right]);
}
/// Segment Tree end

int cs;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    init(1,1,n);
    map<int,int> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    int compress = 1;
    for(auto &[x,y]: mp)
    {
        y = compress++;
    }
    int ans = 0;
    for(auto &x : v)
    {
        debug(x,mp[x]);
        x = mp[x];

        int cnt = 0;
        if(x-1 >= 1)
        {
            cnt = query(1,1,n,1,x-1);
        }
        cnt++;
        ans = modAdd(ans,cnt);
        
        update(1,1,n,x,cnt);
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