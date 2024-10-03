#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int f(int n, int k)
{   
    int ans = 0;
    int b = k;
    while(n >= k)
    {
        ans += n/k;
        k *= b;
    }
    return ans;
}

int cs;
void solve()
{
    int n,r,p,q;
    cin >> n >> r >> p >> q;

    map<int,int> mp;
    for(int i = 2; i*i <= p; i++)
    {
        if(i > 5) break;
        int cnt = 0;
        while(p%i == 0)
        {
            p /= i;
            cnt++;
        }
        mp[i] = cnt;
    }
    if(p) mp[p]++;

    mp[2] *= q;
    mp[5] *= q;
    
    mp[2] += f(n,2)-f(r,2)-f(n-r,2);
    mp[5] += f(n,5)-f(r,5)-f(n-r,5);

    int res = min(mp[2],mp[5]);

    cout << "Case " << ++cs << ": ";
    cout << res << endl;

    

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}