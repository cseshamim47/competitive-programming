#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


int cs;
void solve()
{
    int n;
    cin >> n;

    int cnt = 0;
    int sum = 0;
    for(int i = 2; i*i <= n; i++)
    {
        int howmany = n/i - 1 - cnt;
        sum += (howmany-1)*i;
        sum += (1ull*howmany*(2*i + howmany-1))/2;

        cnt++;
    }

    cout << "Case " << ++cs << ": "; 
    cout << sum << endl;

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}