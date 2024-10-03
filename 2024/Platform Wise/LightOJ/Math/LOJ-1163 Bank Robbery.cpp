#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int unsigned long long


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

int cs;
void solve()
{
    int n;
    cin >> n;
    int sz = 0;
    
    cout << "Case " << ++cs << ": ";

    int a = n+1;
    while(true)
    {
        int gap = a-n;
        int aa = a/10;

        debug(a);

        if(aa == gap)
        {
            cout << a << " ";
            a++;
        }else if(aa > gap)
        {
            int jetehobe = aa-gap;
            a += jetehobe;
        }else
        {
           break;
        }

    }
    cout << endl;
}


int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}

