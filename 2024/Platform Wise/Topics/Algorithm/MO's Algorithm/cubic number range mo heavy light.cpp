/* 
Multiply all numbers from L to R. Is the result number a cubic number or not?

sol: heavy light trick...there will be only one prime greter than > 1000. Will do mo's for only that number. < 1000 can be done by pref sum. 

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

// array is 0-Indexed
int n,q,k,freq[1000006],arr[500005]; // k is block size
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
        if(L/k != Q.L/k) 
        {
            return L < Q.L;
        }else 
        {
            if((L/k)%2 == 0)
            {
                return R > Q.R; 
            }else 
            {
                return R < Q.R; 
            }
        }
    }
}queries[500005]; 

const int N = 1e6+10;
vector<int> primes;
vector<int> prime_idx(1001,0);
vector<int> lp(N,0);
vector<int> prev_val(N,0);
vector<vector<int>> pref(170,vector<int>(N,0));
void prime_gen()
{
    for(int i = 2; i < N; i++)
    {
        if(lp[i] == 0)
        {
            if(i < 1000)
            prime_idx[i] = primes.size();
            primes.push_back(i);
            lp[i] = i;
            prev_val[i] = i;
        }
        for(int j = 0; i*primes[j] < N; j++)
        {
            lp[i*primes[j]] = primes[j];
            prev_val[i*primes[j]] = i;
            if(lp[i] == primes[j]) break;
        }
    }
}

int res;
inline void add(int idx)
{
    if(arr[idx] == 0) return;
    freq[arr[idx]]++;
    if(freq[arr[idx]]%3 == 1) res++;
    else if(freq[arr[idx]]%3 == 0) res--;
}

void remove(int idx)
{
    if(arr[idx] == 0) return;
    freq[arr[idx]]--;
    if(freq[arr[idx]]%3 == 0) res--;
    else if(freq[arr[idx]]%3 == 2) res++;
}

void solve()
{
    cin >> n >> q;
    k = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        int val = arr[i];
        int largest_prime = 0;
        if(val == 1) 
        {
            arr[i] = 0;
            continue;
        }
        // cout << val << ": ";
        while(true)
        {
            int cur_prime = lp[val];
            // cout << cur_prime << " ";
            if(cur_prime < 1000)
            pref[prime_idx[cur_prime]][i]++;
            else 
            {   
                largest_prime = cur_prime;
            }
            if(val == lp[val]) break;
            val = prev_val[val];
        }
        // cout << endl;
        arr[i] = largest_prime;
    }

    for(int i = 0; i < 170; i++)
    {
        for(int j = 1; j < n; j++)
        {
            pref[i][j] += pref[i][j-1];
        }
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
    vector<bool> ans(q,false);
    for(int i = 0; i < q; i++)
    {
        int l = queries[i].L;
        int r = queries[i].R;
        int idx = queries[i].idx;
        l--,r--;
        bool cubeRoot = true;
        for(int j = 0; j < 170; j++)
        {
            int cnt = 0;
            if(l)
            {
                cnt = pref[j][r]-pref[j][l-1];
            }else cnt = pref[j][r];
            // debug(pref[0][4]);
            if(cnt%3 != 0)
            {
                cubeRoot = false;
                break;
            }
        }
        if(cubeRoot)
        {
            while(curL > l) add(curL--);
            while(curR < r) add(++curR);
            while(curL < l) remove(curL++);
            while(curR > r) remove(curR--);
            cubeRoot &= !res;
        }

        ans[idx] = cubeRoot;
    }

    for(auto x : ans) 
    {
        if(x) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}

int32_t main()
{
    prime_gen();

    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}