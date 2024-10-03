#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


void f(int pos,int sum,vector<int> &v,vector<int> &a)
{
    if(pos == v.size())
    {
        a.push_back(sum);
        return;
    }

    f(pos+1,sum, v,a);
    f(pos+1,sum+v[pos], v,a);
    f(pos+1,sum+v[pos]+v[pos], v,a);
    return;
}

int Case;
void solve()
{
    int n,k;
    cin >> n >> k;

    vector<int> a;
    for(int i = 0; i < n/2; i++) 
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> b;
    for(int i = n/2; i < n; i++) 
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    vector<int> aa,bb;
    f(0,0,a,aa);
    f(0,0,b,bb);

    cout << "Case " << ++Case << ": ";
    // for(auto x : bb) cout << x << " ";
    // cout << endl;
    sort(bb.begin(),bb.end());
    for(auto x : aa)
    {
        // cout <<  x << " ";
        if(binary_search(bb.begin(),bb.end(),k-x))
        {
            cout << "Yes" << endl;
            return;
        }
    }
    
    
    cout << "No" << endl;


}

int32_t main()
{
    //    Bismillah
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}