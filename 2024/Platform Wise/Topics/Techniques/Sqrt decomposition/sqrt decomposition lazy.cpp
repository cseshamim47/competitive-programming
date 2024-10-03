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

int block[320];
int lazy[320];
vector<int> v;
int block_size;
void init(int n)
{
    block_size = sqrt(n);
    int cur_block = -1;
    for(int i = 0; i < 320; i++) 
    {
        block[i] = lazy[i] = 0;
    }
    v.clear();
    v.resize(n,0);
}

void push(int l_block)
{
    int l = l_block*block_size;
    int r = (l_block+1)*block_size;
    while(l < r)
    {
        v[l] += lazy[l_block];
        l++;
    }
    lazy[l_block] = 0;
}


int query(int l,int r)
{
    int l_block = l/block_size;
    int r_block = r/block_size;
    int sum = 0;
    if(l_block == r_block)
    {
        if(lazy[l_block]) push(l_block);

        while(l <= r) sum += v[l++]; 
    }else 
    {
        if(lazy[l_block]) push(l_block);

        int lim = (l_block+1)*block_size;
        while(l < lim) 
        {
            sum += v[l];
            l++;
        }

        l_block++;
        while(l_block < r_block)
        {
            sum += block[l_block];
            l_block++;
            l += block_size;
        }

        if(lazy[l_block]) push(l_block);
        while(l <= r)
        {
            sum += v[l++];
        }
    }
    return sum;
}


void update(int l,int r,int val)
{
    int l_block = l/block_size;
    int r_block = r/block_size;

    if(l_block == r_block)
    {
        while(l <= r)
        {
            v[l] += val;
            block[l_block] += val;
            l++;
        }
        // debug("done");
    }else
    {
        int lim = (l_block+1)*block_size;
        while(l < lim)
        {
            v[l] += val;
            block[l_block] += val;
            l++;
        }

        l_block++;
        while(l_block < r_block)
        {
            block[l_block] += val*block_size;
            lazy[l_block] += val;
            l_block++;
            l += block_size;
        }

        while(l <= r)
        {
            v[l] += val;
            block[l_block] += val;
            l++;
        }


    }
}

int cs;
void solve()
{
    int n,q;
    cin >> n >> q;

    init(n);

    cout << "Case " << ++cs << ":\n";
    for(int i = 0; i < q; i++)
    {
        int t,l,r;
        cin >> t >> l >> r;
        
        if(t == 0)
        {
            int v;
            cin >> v;
            update(l,r,v);
        }else 
        {
            cout << query(l,r) << endl;
        }
    }

}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) solve();
}