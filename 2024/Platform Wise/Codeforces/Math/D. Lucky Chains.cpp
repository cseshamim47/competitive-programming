// https://codeforces.com/contest/1766/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N = 1e7+5;
vector<int> spf(N);

void gen()
{
    for(int i = 1; i < N; i++) 
    {
        spf[i] = i;
    }

    for(int i = 2; i < N; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i*i; j < N; j += i)
            {
                spf[j] = i; 
            }
        }
    }
}

void solve()
{
    int x,y;
    cin >> x >> y;
    // gcd(x,y) = gcd(x,y-x);  if gcd(x,y-x) > 1 then y-x and x has atleast one prime factor in common.

    // similarly gcd(x+k, y+k) = gcd(x+k,y-x);

    int gap = y-x; 
    int ans = 1e15;
    if(x == y-1)
    {
        cout << -1 << endl;
        return;
    }

    while(gap > 1)
    {
        int smpf = spf[gap];
        int xplusk = ((x+smpf-1)/smpf)*smpf;
        int k = xplusk-x;
        int nx =  xplusk;
        int ny = y + k;
        if(__gcd(nx,ny) > 1)
        ans = min(ans,k);
        while(gap%smpf == 0) gap/=smpf; 
    }

    if(ans == 1e15) ans = 0;
    cout << ans << endl;

}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    gen();
    int t = 1;
    cin >> t;

    while(t--) solve();
}