#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int unsigned long long


const int N = 5*1e6+10;
int phi[N];

// O(n*loglog(n))
void phiSieve(int n)
{
    phi[0] = phi[1] = 1;
    for(int i = 2; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(phi[i] == i)
        {
            phi[i]-=1;
            for(int j = i+i; j <= n; j+=i)
            {
                phi[j] = (phi[j] * (i-1));
                phi[j] /= i;
            }
        }
        phi[i] = (phi[i]*phi[i]);
    }

    phi[0] = phi[1] = 0;
    int sum = 0;
    for(int i = 2; i <= n; i++)
    {
        sum += phi[i];
        phi[i] = sum;
    }


}

int cs;
void solve()
{
    int a,b;
    cin >> a >> b;
    cout << "Case " << ++cs << ": ";
    cout << phi[b]-phi[a-1] << endl;
}

int32_t main()
{
    //    Bismillah
    phiSieve(5*1e6);
    int t = 1;
    cin >> t;
    while(t--) solve();
}