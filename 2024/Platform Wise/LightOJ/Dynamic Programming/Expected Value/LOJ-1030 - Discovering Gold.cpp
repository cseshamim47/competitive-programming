#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "-> " << #x <<" "; _print(x); cerr << endl;
#define debug2(x,y) cerr << "-> " << #x <<" = " << x << ", " << #y << " = " << y << endl;
#else
#define debug(x)
#define debug2(x,y)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int v[101];
double dp[101];
int n;

double f(int pos)
{
    if(pos == n) return v[n];
    if(dp[pos] != -1) return dp[pos];

    double exp = v[pos];
    for(int i = 1; i <= 6; i++)
    {
        if(pos+i <= n)
        {
            int ss = min((n-pos),6); // sample space
            double exv = (1.0/ss)*f(pos+i); // cur pos theke pos+i tomo pos er expected value
            exp += exv;
        }
    }

    return dp[pos] = exp;
}

int cs;
void solve()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++) 
    {
        cin >> v[i];
        dp[i] = -1;
    }

    cout << "Case " << ++cs << ": ";
    cout << fixed << setprecision(8) << f(1) << endl;
    
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}