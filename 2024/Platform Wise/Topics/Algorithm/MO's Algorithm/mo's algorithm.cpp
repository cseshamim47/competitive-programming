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

// array is 0-Indexed
int n,q,k,freq[1000006],arr[100005]; // k is block size
struct query
{
    int L,R,idx;
    query(){}
    query(int L, int R, int idx)
    {
        this->L = L;
        this->R = R;
        this->idx = idx;
    }
    inline bool operator<(const query &Q) const {
        if(L/k != Q.L/k) // block are not same
        {
            return L < Q.L;
        }else 
        {
            if((L/k)%2 == 0)
            {
                return R > Q.R; // descending order
            }else 
            {
                return R < Q.R; 
            }
        }
    }
}queries[200005]; // change accordingly

int res;
inline void add(int idx)
{
    freq[arr[idx]]++;
}

void remove(int idx)
{
    freq[arr[idx]]--;
}

void solve()
{
    cin >> n >> q;
    k = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l >> r;
        queries[i] = query(l,r,i);
    }
    
    sort(queries,queries+q);

    int curL = 0;
    int curR = -1;

    res = 0;
    for(int i = 0; i < q; i++)
    {
        int l = queries[i].L;
        int r = queries[i].R;
        int idx = queries[i].idx;

        while(curL > l) add(curL--);
        while(curR < r) add(++curR);
        while(curL < l) remove(curL++);
        while(curR > r) remove(curR--);
    }

    // this is basic MO's algo...do stuffs accordingly
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}