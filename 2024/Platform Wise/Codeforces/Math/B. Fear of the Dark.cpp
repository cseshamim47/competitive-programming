// https://codeforces.com/contest/1886/problem/B
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) x.begin(),x.end()


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

struct point{
    double x,y;
};
double sq(int n)
{
    return n*n;
}

double dist(point a, point b)
{
    return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}


void solve()
{
    point p,a,b,o;
    o.x = 0;
    o.y = 0;
    cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y;

    double ob = dist(o,b);
    double bp = dist(b,p);

    double oa = dist(o,a);
    double ap = dist(a,p);

    double ans = min(max(ob,bp), max(oa,ap)); // single circle

    double ab = dist(a,b)/2.0; 

    double ans2 = min(max(ab,max(oa,bp)), max(ab,max(ob,ap)));
    ans = min(ans, ans2); 
    cout << fixed << setprecision(20) << ans << endl;



}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}