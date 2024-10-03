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

const int N = 1e5 ;
int k;
int a[N];
int ans[N];
struct moQuery{
    int l; int r; int idx;
    moQuery(){}
    moQuery(int l, int r, int idx){
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
    bool operator<(moQuery &q)
    {
        if( (l/k) == (q.l/k))
        {
            if((l/k)&1) return r > q.r;
            else return r < q.r;
        }else 
        {
            return (l/k) < (q.l/k);
        }
    }
}queries[N];

  /// Segment Tree Start
const int MX = N;
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
    Tree[node] = max(Tree[Left] , Tree[Right]);
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
    return max(leftTreeVal,rightTreeVal);
}

void update(int node, int b, int e, int i, int val) // O(LogN)
{
    if( (i > e) or (i < b) ) return;
    if(b==e)
    {
        Tree[node] = val;
        return;
    }

    int Left = node*2;
    int Right = (node*2)+1;
    int mid = (b+e)/2;
    update(Left,b,mid,i,val);
    update(Right,mid+1,e,i,val);
    Tree[node] = max(Tree[Left] , Tree[Right]);
}
/// Segment Tree end

deque<int> dq[N];
int n,q;
int freq[N];

void add(int idx, char t)
{
    int val = a[idx];
    deque<int> &d = dq[val];
    if(d.size())
    {
        int mx = d.back()-d.front();
        freq[mx]--;
        if(mx && freq[mx]==0)
        {
            update(1,1,n,mx,0);
        }
    }
    if(t == 'L') 
    {
        d.push_front(idx);
    }else{
        d.push_back(idx);
    }
    int mx = d.back()-d.front();
    freq[mx]++;
    if(mx && freq[mx] == 1)
    {
        update(1,1,n,mx,mx);
    }
}

void remove(int idx, char t)
{
    int val = a[idx];
    deque<int> &d = dq[val];
    if(d.size())
    {
        int mx = d.back()-d.front();
        freq[mx]--;
        if(mx && freq[mx] == 0)
        {
            update(1,1,n,mx,0);
        }
    }
    if(t == 'L') 
    {
        d.pop_front();
    }else{
        d.pop_back();
    }
    if(d.size())
    {
        int mx = d.back()-d.front();
        freq[mx]++;
        if(mx && freq[mx] == 1)
        {
            update(1,1,n,mx,mx);
        }
    }
}

void solve()
{
    cin >> n >> q;
    k = sqrtl(n);
    int tot = 0;
    map<int,int> mp;
    int id = 1;
    mp[0] = 0;
    a[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
        a[i] = tot;
        if(mp.count(a[i]) == 0) mp[a[i]] = id++;
        a[i] = mp[a[i]];
    }   
    
    init(1,1,n);

    for(int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l >> r;
        l--;
        queries[i] = moQuery(l,r,i);
    } 

    sort(queries,queries+q);

    int curR = -1;
    int curL = 0;
    
    for(int i = 0; i < q; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        int idx = queries[i].idx;

        while(curL > l) add(--curL,'L');
        while(curR < r) add(++curR,'R');
        while(curL < l) remove(curL++,'L');
        while(curR > r) remove(curR--,'R');

        ans[idx] = Tree[1];
    }

    for(int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}