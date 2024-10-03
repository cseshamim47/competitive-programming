#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> block(400,0);
vector<int> v;
int block_size;
void gen()
{
    int n = v.size();
    block_size = sqrt(n)+1;

    int block_index = -1;
    for(int i = 0; i < n; i++)
    {
        if(i%block_size == 0) block_index++;
        block[block_index] += v[i];
    }
}

void update(int i, int val, int t)
{
    if(t == 1)
    {
        block[i/block_size] -= v[i];
        v[i] = 0;
    }else 
    {
        block[i/block_size] += val;
        v[i] += val;
    }
}


int query(int l, int r)
{
    int lblock = l/block_size;
    int rblock = r/block_size;

    int sum = 0;

    if(lblock == rblock)
    {
        while(l <= r) sum += v[l++];
    }else 
    {
        int lim = (lblock+1)*block_size;
        while(l < lim) sum += v[l++];

        lblock++;
        while(lblock < rblock) sum += block[lblock++],l+=block_size;

        while(l <= r) sum += v[l++];
    }

    return sum;
}

int cs;
void solve()
{
    int n,q;
    cin >> n >> q;
    v.clear();
    fill(block.begin(),block.end(),0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    gen();

    cout << "Case " << ++cs << ":\n";
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int i;
            cin >> i;
            cout << query(i,i) << endl;
            update(i,0,1);
        }else if(t == 2)
        {
            int i,val;
            cin >> i >> val;
            update(i,val,2);
        }else 
        {
            int l,r;
            cin >> l >> r;
            cout << query(l,r) << endl;
        }

    }
    
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}