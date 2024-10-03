/* 
Multiply all numbers from L to R. Is the result number a cubic number or not?

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

int n,q,k,arr[50005];
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
}queries[50005];

const int N = 1e6+10;
vector<int> primes;
vector<int> lp(N,0);
vector<int> n_div_lp(N,0);
void prime_gen()
{
    for(int i = 2; i < N; i++)
    {
        if(lp[i] == 0)
        {
            primes.push_back(i);
            lp[i] = i;
        }
        for(int j = 0; i*primes[j] < N; j++)
        {
            lp[primes[j]*i] = primes[j];
            n_div_lp[primes[j]*i] = i;
            if(lp[i] == primes[j]) break;
        }
    }
}
int not_cubic = 0;
vector<int> cnt(N,0);
vector<int> is_divisible(N,0);

void add(int idx)
{
    int value = arr[idx];
    while(value != lp[value])
    {
        int cur_prime = lp[value];
        cnt[cur_prime]++;
        if(cnt[cur_prime]%3 == 0) 
        {
            not_cubic--;
        }else if(cnt[cur_prime]%3 == 1) 
        {
            not_cubic++;
        }
        
        value = n_div_lp[value];
    }
    int cur_prime = lp[value];
    cnt[cur_prime]++;

    if(cnt[cur_prime]%3 == 0) 
    {
        not_cubic--;
    }else if(cnt[cur_prime]%3 == 1) 
    {
        not_cubic++;
    }
}

void remove(int idx)
{
    int value = arr[idx];
    while(value != lp[value])
    {
        int cur_prime = lp[value];
        cnt[cur_prime]--;
        if(cnt[cur_prime]%3 == 0) 
        {
            not_cubic--;
        }else if(cnt[cur_prime]%3 == 2) 
        {
            not_cubic++;
        }
        value = n_div_lp[value];
    }
    int cur_prime = lp[value];
    cnt[cur_prime]--;
    if(cnt[cur_prime]%3 == 0) 
    {
        not_cubic--;
    }else if(cnt[cur_prime]%3 == 2) 
    {
        not_cubic++;
    }
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
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries,queries+q);
    vector<bool> res(q,false);
    int curL = 0, curR = -1;
    for(int i = 0; i < q; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        int idx = queries[i].idx;
        l--;
        r--;

        while(curL > l) add(--curL);
        while(curR < r) add(++curR);
        while(curL < l) remove(curL++);
        while(curR > r) remove(curR--);

        res[idx] = (not_cubic == 0 ? true : false); 
    }   
    for(auto x : res)
    {
        cout << (x?"YES":"NO") << endl;
    }
}

int32_t main()
{
    //    Bismillah
    prime_gen();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}