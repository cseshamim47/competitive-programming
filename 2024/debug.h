#include <bits/stdc++.h>
using namespace std;

bool ok = true;
#ifdef SHAMIM_AHMED
#define debug(x...) ok = true; cerr << "-> " << #x <<" "; _print(x); cerr << endl;
#define debug2(x,y) cerr << "-> [ " << #x <<" = " << x << " ], [ " << #y << " = " << y << " ]" << endl;
#define debug3(x,y,z) cerr << "-> [ " << #x <<" = " << x << " ], [ " << #y << " = " << y << " ], [ " << #z << " = " << z << " ]"<< endl;
#else
#define debug(x...)
#define debug2(x,y)
#define debug3(x,y,z)
#endif

void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(int a,int b) {cerr << a << ' ' << b;}
void _print(int a,int b,int c) {cerr << a << ' ' << b << ' ' << c;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]" << endl;
}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}