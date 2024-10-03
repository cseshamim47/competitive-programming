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
vector<int> number_of_divisors(N,0);
vector<double> expected_value(N,0);

void gen()
{   
    expected_value[1] = 0;
    for(int i = 2; i < N; i++)
    {
        expected_value[i] = (expected_value[1]+1) + 1; // adding the contribution of expected value of 1 + self contribution;
        number_of_divisors[i] = 1; // 1 is divisor of everyone
    }

    for(int i = 2; i < N; i++)
    {
        expected_value[i] /= number_of_divisors[i];
        for(int j = i+i; j < N; j+=i)
        {
            expected_value[j] += (expected_value[i]+1);
            number_of_divisors[j]++;
        }
    }

    // cout << expected_value[50] << endl;
}

int cs;
void solve()
{
    int n;
    cin >> n;
    cout << "Case " << ++cs << ": ";
    cout << fixed << setprecision(10) << expected_value[n] << endl;
}

int32_t main()
{
    //    Bismillah
    gen();
    int t = 1;
    cin >> t;
    while(t--) solve();
}