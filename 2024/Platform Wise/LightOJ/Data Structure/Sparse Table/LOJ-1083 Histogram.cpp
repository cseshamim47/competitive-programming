#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

int cs;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> next_smaller(n,n-1);
    vector<int> prev_smaller(n,0);
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        if(s.empty()) s.push(i);
        else 
        {
            while(s.size() && v[s.top()] > v[i]) 
            {
                next_smaller[s.top()] = i-1;
                s.pop();
            }
            s.push(i);
        }
    }

    while(s.size()) s.pop();

    for(int i = n-1; i >= 0; i--)
    {
        if(s.empty()) s.push(i);
        else 
        {
            while(s.size() && v[s.top()] > v[i])
            {
                prev_smaller[s.top()] = i+1;
                s.pop();
            }
            s.push(i);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int width = next_smaller[i]-i+1;
        width += i-prev_smaller[i]+1;
        width--;
        res = max(res,v[i]*width);
    }
    cout << "Case " << ++cs << ": ";
    cout << res << endl;
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define all(x) x.begin(),x.end()
// // #define int long long

// #ifdef SHAMIM_AHMED
//     #include <G:\Desktop Items\STATION\CPP\debug.h>
// #else
//     #define debug(x...) 
//     #define debug2(x...) 
//     #define debug3(x...)
// #endif

// const int N = 50005;
// int t[16][N];
// void init(int n)
// {
//     int lg = log2(n);
//     for(int p = 1; p <= lg; p++)
//     {
//         for(int i = 0; i < n; i++)
//         {
//             t[p][i] = 1e5;
//         }
//     }

//     for(int p = 1; p <= lg; p++)
//     {
//         for(int i = 1; i <= n; i++)
//         {
//             if(i+(1 << p-1) <= n)
//             {
//                 t[p][i] = min(t[p-1][i],t[p-1][i+(1 << (p-1))]);
//             }else 
//             {
//                 t[p][i] = t[p-1][i];
//             }
//         }
//     }
// }

// int query(int l, int r)
// {
//     int p = log2(r-l+1);
//     return min(t[p][l],t[p][r-(1 << p)+1]);
// }


// int cs;
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n+1,0);
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> t[0][i];
//     }

//     init(n);
//     int ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         int l = i;
//         int r = n;
//         int res = 1;
//         while(l <= r)
//         {
//             int mid = (l+r)/2;
//             if(query(i,mid) == t[0][i])
//             {
//                 res = mid-i+1;
//                 l = mid+1;
//             }else{
//                 r = mid-1;
//             }
//         }
//         v[i] = res;

//         l = 1;
//         r = i;
//         res = 0;
//         // debug(i);
//         while(l <= r)
//         {
//             int mid = (l+r)/2;
//             if(query(mid,i) == t[0][i])
//             {
//                 res = i-mid;
//                 r = mid-1;
//             }else{
//                 l = mid+1;
//             }
//         }

//         v[i] += res;
//         ans = max(ans,v[i]*t[0][i]);
//     }

//     // debug(v);

//     cout << "Case " << ++cs << ": ";
//     cout << ans << endl;

// }


// int32_t main()
// {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     //    Bismillah
//     // test();
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
// }