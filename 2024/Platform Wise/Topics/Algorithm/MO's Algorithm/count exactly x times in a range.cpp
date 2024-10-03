/* 
# How many values are there in a range that has frequency equals to exactly X. 
*/

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

// 0-indexed
int n,q,x,k,arr[50000];
struct query{
    int l,r,idx;
}queries[50000];

bool cmp(query &a, query &b)
{
    if(a.l/k == b.l/k)
    {
        if((a.l/k)%2 == 0)
        {
            return a.r > b.r;
        }else 
        {
            return a.r < b.r;
        }
    }else 
    {
        return a.l < b.l;
    }
}
int freq[1000005];
int cnt;
void add(int idx)
{
    freq[arr[idx]]++;
    if(freq[arr[idx]] == x) cnt++;
    if(freq[arr[idx]] == x+1) cnt--;
}

void remove(int idx)
{
    freq[arr[idx]]--;
    if(freq[arr[idx]] == x) cnt++;
    if(freq[arr[idx]] == x-1) cnt--;
}


void solve()
{
    cin >> n >> q >> x;
    k = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]] = 0;
    }

    for(int i = 0; i < q; i++)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(queries,queries+q,cmp);

    int curL = 0;
    int curR = -1;
    cnt = 0;
    vector<int> res(q);
    for(int i = 0; i < n; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        l--;
        r--;
        int idx = queries[i].idx;

        while(l < curL) add(--curL);
        while(curR < r) add(++curR);
        while(curL < l) remove(curL++);
        while(r < curR) remove(curR--);

        res[idx] = cnt; 
    }

    for(int x: res) cout << x << endl;
    
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}