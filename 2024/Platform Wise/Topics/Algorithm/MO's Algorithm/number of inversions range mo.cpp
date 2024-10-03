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

// 0-indexed mo
int n,q,k,arr[5*10004];
struct query{
    int l,r,idx;

    bool operator<(const query &q) const {
        if(l/k == q.l/k)
        {
            if((l/k)%2 == 0)
            {
                return r > q.r;
            }else 
            {
                return r < q.r;
            }
        }else 
        {
            return l < q.l;
        }
    }
}queries[5*10004];


// 1 indexed bit
const int N = 1e5+100;
vector<int> bit(N,0);
void update(int idx,int val)
{
    while(idx < N)
    {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
int ask(int idx)
{
    int sum = 0;
    while(idx)
    {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int range_query(int l, int r)
{
    return ask(r)-ask(l-1);
}

int res = 0;
void add(int idx, char t)
{
    if(t == 'r')
    {
        res += range_query(arr[idx]+1,N-1);
    }else 
    {
        res += range_query(1,arr[idx]-1);
    }
    update(arr[idx],1);
}

void remove(int idx, char t)
{
    if(t == 'r')
    {
        res -= range_query(arr[idx]+1,N-1);
    }else 
    {
        res -= range_query(1,arr[idx]-1);
    }
    update(arr[idx],-1);
}


void solve()
{
    cin >> n >> q;
    k = sqrt(n);
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(all(v));
    int compress = 0;
    int prev = -1;
    for(auto &[x,y]: v)
    {
        if(x != prev)
        {
            prev = x;
            x = ++compress;
        }else 
        {
            x = compress;
        }
        arr[y] = x;
    }

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries,queries+q);

    int curL = 0,curR = -1;

    vector<int> ans(q);

    for(int i = 0; i < q; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        int idx = queries[i].idx;

        while(curL > l) add(--curL,'l'); // check smaller
        while(curR < r) add(++curR,'r'); // check greater
        while(curL < l) remove(curL++,'l');
        while(curR > r) remove(curR--,'r');

        ans[idx] = res;
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}