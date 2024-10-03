
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> block(320,1e8);
int preprocess(vector<int> &v)
{
    int n = v.size();
    int blk = sqrt(n);

    int idx = -1;

    for(int i = 0; i < n; i++)
    {
        if(i%blk == 0) idx++;
        block[idx] = min(block[idx],v[i]);
    }

    return blk;
}

int query(vector<int> &v, int blk, int l, int r)
{
    int mn = 1e8;
    while(l <= r && l%blk != 0) mn = min(mn,v[l++]);

    while(l+blk <= r)
    {
        mn = min(mn,block[l/blk]);
        l += blk;
    }

    while(l <= r) mn = min(mn,v[l++]);

    return mn;
}

int cs;
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    // memset(block,0,sizeof block);
    for(int i = 0; i < 320; i++) block[i] = 1e8;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int blk = preprocess(v);

    cout << "Case " << ++cs << ":\n";
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(v,blk,l,r) << endl;
    }
    

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}


/* 

// using sparse table
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int cs;
void solve()
{
    int n,q;
    cin >> n >> q;
    int lgn = log2(n)+1;
    vector<vector<int>> t(lgn,vector<int>(n)); // [pow][numbe of elements]
    for(int i = 0; i < n; i++)
    {
        cin >> t[0][i];
    }

    for(int p = 1; p < lgn; p++)
    {
        for(int i = 0; i < n; i++)
        {
           int next = i+(1 << (p-1));
           if(next < n)
           {
                t[p][i] = min(t[p-1][i],t[p-1][next]);
           }else break;
        }
    }

    cout << "Case " << ++cs << ":\n";
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int range = r-l+1;
        int lg = log2(range);
        int ans = min(t[lg][l],t[lg][r-(1 << lg)+1]);
        cout << ans << endl;
    }
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
} 

*/