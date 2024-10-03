#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct point{
    int x,y;
};

int cs;
void solve()
{
    point a,b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;

    cout << "Case " << ++cs << ": ";
    if(a.x == b.x && a.y == b.y)
    {
        cout << 1 << endl;
        return;
    }else if(a.x == b.x)
    {
        cout << abs(a.y-b.y)+1 << endl;
        return;
    }else if(a.y == b.y)
    {
        cout << abs(a.x-b.x)+1 << endl;
        return;
    }

    int delY = b.y-a.y;
    int delX = b.x-a.x;
    int g = __gcd(delX,delY);

    int sm = delX/g;
    int ans = abs(delX/sm)+1;
    cout << ans << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}