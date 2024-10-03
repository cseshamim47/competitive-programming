#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int gcd(int a, int b) // O(logN)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(lcm(i,j) == n)
            {
                // if(i != n && j != n)
                {
                    cout << i << " " << j << endl;

                }
                    cnt++;
            }
        }
    }   
    cout << cnt << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}


/* 

      
 
     
           
*/