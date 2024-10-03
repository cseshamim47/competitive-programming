/* 
question : 
Given n,q

find number of prime that has max number of multiple in a range

ex : 3 3 5 7 7 3 3 2 2 2 2 

2 -> 4
3 -> 4
7 -> 2
5 -> 1

res = 2 because there are two primes (2 and 3) who have maximum number of multiple in the array


Idea: mo's algo
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

const int N = 1e6+10;
vector<int> lp(N,0);
vector<int> last(N,0); 
vector<int> primes;

void sieveLinear()
{
    for(int i = 2; i < N; i++)
    {
        if(lp[i] == 0)
        {
            primes.push_back(i);
            lp[i] = i;
        }
        for(int j = 0; i * primes[j] < N; j++)
        {
            lp[i*primes[j]] = primes[j];
            last[i*primes[j]] = i; // this is to prevent division in query
            if(lp[i] == primes[j]) break;
        }
    }
}

// 0-indexed
int n,q,k,arr[50005];
struct query{
    int l, r, idx;
    query(){}
    query(int l, int r, int idx){
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
    bool operator<(const query &q) const{
        if(l/k == q.l/k) 
        {
            if((l/k)%2 == 0)
            {
                return r > q.r;
            }else{
                return r < q.r;
            }
        }else 
        {
            return l < q.l;
        }
    }
}queries[50005];


int cnt = 0; 
int mx_multiple = 0;

int prime_cnt[N]; // prime_cnt[5] = 8 mane hocche -> prime 5 ta 8 ta number er moddhe pawa gese
int cnt_res[N]; // cnt_res[3] = 5 mane hocche -> 5 ta prime number ase jara atleast 3 ta number er divisor

void add(int idx)
{
    int val = arr[idx];
    int prev_prime = -1;
    while(lp[val] != val)
    {
        int cur_prime = lp[val];
        val = last[val];

        if(cur_prime == prev_prime) continue; // unique prime gula nicchi khali
        prev_prime = cur_prime;

        prime_cnt[cur_prime]++;
        cnt_res[prime_cnt[cur_prime]]++;
        if(prime_cnt[cur_prime] > mx_multiple)
        {
            mx_multiple = prime_cnt[cur_prime];
            cnt = cnt_res[mx_multiple];
        }
    }
    if(lp[val] != prev_prime)
    {
        int cur_prime = lp[val];
        prime_cnt[cur_prime]++;
        cnt_res[prime_cnt[cur_prime]]++;
        if(prime_cnt[cur_prime] > mx_multiple)
        {
            mx_multiple = prime_cnt[cur_prime];
            cnt = cnt_res[mx_multiple];
        }
    }
}
void remove(int idx)
{
    int val = arr[idx];
    int prev_prime = -1;
    while(lp[val] != val)
    {
        int cur_prime = lp[val];
        val = last[val];

        if(cur_prime == prev_prime) continue; // unique prime gula nicchi khali
        prev_prime = cur_prime;

        cnt_res[prime_cnt[cur_prime]]--;
        prime_cnt[cur_prime]--;
        if(cnt_res[mx_multiple] == 0)
        {
            mx_multiple--;
        }
        cnt = cnt_res[mx_multiple];
    }
    if(lp[val] != prev_prime)
    {
        int cur_prime = lp[val];
        cnt_res[prime_cnt[cur_prime]]--;
        prime_cnt[cur_prime]--;
         if(cnt_res[mx_multiple] == 0)
        {
            mx_multiple--;
        }
        cnt = cnt_res[mx_multiple];
    }
}


void solve()
{
    memset(arr,0,sizeof arr);
    memset(queries,0,sizeof queries);
    memset(prime_cnt,0,sizeof prime_cnt);

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
        l--,r--;
        queries[i] = query(l,r,i);
    }
    sort(queries,queries+q);


    int curL = 0;
    int curR = -1;

    vector<int> res(q,0);
    
    for(int i = 0; i < q; i++)
    {
        int L = queries[i].l;
        int R = queries[i].r;
        int idx = queries[i].idx;

        // debug(idx);

        while(curR < R) add(++curR);
        while(curL > L) add(--curL);
        while(curL < L) remove(curL++);
        while(curR > R) remove(curR--);

        res[idx] = cnt;
    }

    for(auto x : res) cout << x << endl;

}

int32_t main()
{
    //    Bismillah
    sieveLinear();
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
