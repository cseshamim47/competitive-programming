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

const int N = 1e5+10;
vector<double> expected_value(N,-1);
double exp(int n)
{
    if(n == 1) return expected_value[n] = 0;
    if(n == 2) return expected_value[n] = 2;
    if(n == 3) return expected_value[n] = 2;
    if(expected_value[n] != -1) return expected_value[n];
    double ev = 1+1; // divisor 1 er jonne ev[0]+1 = 1, nijer jonne 1  
    double cnt = 1;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            cnt++;
            ev += exp(i)+1;
            if(n/i != i) 
            {
                cnt++;
                ev += exp(n/i)+1;
            }
        }
    }
    return expected_value[n] = ev /= cnt;
}

int cs;
void solve()
{
    int n;
    cin >> n;
    cout << "Case " << ++cs << ": ";
    cout << fixed << setprecision(10) <<  exp(n) << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}