#include<bits/stdc++.h>
using namespace std;

const int N = 20;

// NEVER use get_rand() function because get_rand() will always generate same random values even if you run the same code multiple times
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); // using current time as seed, so it will always generate different random values if you run this code multiple times
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int t = 1;
   cout << t << endl;
  string s = "";
  vector<char> v;
  for(char ch = 'a'; ch <= 'z'; ch++)
  {
    v.push_back(ch);
  }
  int n = get_rand(2,15);
  for(int i = 0; i < n; i++)
  {
    int idx = get_rand(0,2);
    s.push_back(v[idx]);
  }
  cout << s << endl;
  //  int n = get_rand(1,10);
  //   cout << n << endl;
  //  int q = get_rand(2,4);
  //  cout << n << " " << q << endl;
  //  for(int i = 0; i < n; i++)
  //  {
  //     cout << get_rand(1,100) << " ";
  //  }
  //  cout << endl;

  //  while(q--)
  //  {
  //     int l = get_rand(1,n);
  //     int r = get_rand(l,n);
  //     cout << l << " " << r << endl;
  //  }
   
  return 0;
}