#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve()
{
    double n,p,i;
    cin >> n >> p >> i;

    double losing = (1-p);
    double winning = 0;
    while(p*pow(losing,i-1) >= 0.00000001) // cur e jitle ar age shob harle probability jodi 0 er kasakasi hoy mane jitar kono change taile break
    {
        winning += (p*pow(losing,i-1)); // cur state e jodi jiti -> jitar probablity * ager shob state e harar probability. 
        i += n; // next amar turn ashbe n ta player er por.
    }

    
    cout << fixed << setprecision(4) << winning << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}