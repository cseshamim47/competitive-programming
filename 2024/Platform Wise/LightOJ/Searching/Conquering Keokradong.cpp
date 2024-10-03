#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool f(vector<int> &v, int mid,int k)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] > mid) return false;
        if(sum+v[i] <= mid)
        {
            sum += v[i];
        }else 
        {
            k--;
            sum = 0;
            sum = v[i];

        }
    }
    if(sum != 0) k--;
    return k>=0;
}

int Case;
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i = 0; i < n+1; i++)
    {
        cin >> v[i];
    }

    int l = 1;
    int r = 1e9;
    int mn = 0;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(f(v,mid,k+1))
        {
            mn = mid;
            r = mid-1;
        }else 
        {
            l = mid+1;
        }
    }

    vector<int> ans;
    n = v.size();
    int left = n;
    k++;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(left < k)
        {
            if(sum) ans.push_back(sum);
            sum = 0;
            k--;
        }

        if(sum + v[i] <= mn)
        {
            sum += v[i];
            left--;
        }else 
        {
            ans.push_back(sum);
            sum = v[i];
            k--;
            left--;
        }
    }

    if(sum) ans.push_back(sum);

    printf("Case %lld: ",++Case);
    cout << mn << endl;
    for(auto x : ans) cout << x << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}