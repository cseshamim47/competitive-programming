#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifndef ONLINE_JUDGE
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

const int MX = 2e4+123;
bitset<MX> is_prime;
vector<int> prime;

void primeGen ( int n )
{
    n += 100;
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;

    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 ) {
        if ( is_prime[i] == 1 ) {
            for ( int j = i*i; j <= n; j += ( i + i ) ) {
                is_prime[j] = 0;
            }
        }
    }

    is_prime[2] = 1;
    prime.push_back (2);

    for ( int i = 3; i <= n; i += 2 ) {
        if ( is_prime[i] == 1 ) prime.push_back ( i );
    }
}

bool vis[MX];
int lvl[MX];
int parent[MX];

int bfs(string source, string destination)
{
    memset(lvl,-1,sizeof lvl);
    memset(vis,false,sizeof vis);
    lvl[stoi(source)] = 0;
    vis[stoi(source)] = true;
    queue<string> q;
    q.push(source);
    parent[stoi(source)] = -1; 
    /* 
    1033 

    1733  

    3733     
    3739     
    3779
    8779
    8179    
    
     */

    int dest = stoi(destination);

    while(q.size())
    {
        auto cur = q.front();
        // debug(cur);
        // getchar();
        string a=  cur;
        int curInt = stoi(a);
        
        q.pop();
        // first dig 
        for(int i = 1; i < 10; i++)
        {
            a[0] = i+'0';
            int aint = stoi(a);
           
            if(is_prime[aint] && vis[aint] == false)
            {
                vis[aint] = true;
                lvl[aint] = lvl[curInt]+1;
                // parent[aint] = curInt;
                
                q.push(a);
            }
        }
        a = cur;
        // first dig 
        for(int i = 0; i < 10; i++)
        {
            a[1] = i+'0';
            int aint = stoi(a);
            
            if(is_prime[aint] && vis[aint] == false)
            {
                vis[aint] = true;

                lvl[aint] = lvl[curInt]+1;
                // parent[aint] = curInt;

                q.push(a);
            }
        }

        a = cur;
        // third dig 
        for(int i = 0; i < 10; i++)
        {
            a[2] = i+'0';
            int aint = stoi(a);
            if(is_prime[aint] && vis[aint] == false)
            {
                vis[aint] = true;
                lvl[aint] = lvl[curInt]+1;
                    // parent[aint] = curInt;

                q.push(a);
            }
        }
        a = cur;
        // fourth dig 
        for(int i = 0; i < 10; i++)
        {
            a[3] = i+'0';
            int aint = stoi(a);
            if(is_prime[aint] && vis[aint] == false)
            {
                vis[aint] = true;
                lvl[aint] = lvl[curInt]+1;
                // parent[aint] = curInt;

                q.push(a);
            }
        }
    }
    // // debug(lvl[1733]);
    // for(int p = dest; p != -1; p = parent[p])
    // {
    //     debug(p);
    // }
    return lvl[dest];
}



void solve()
{
    string a = "1373";
    string b = "8017";

    cin >> a >> b;
    int cnt = bfs(a,b);
    if(cnt == -1) cout << "IMPOSSIBLE" << endl;
    else cout << cnt << endl;
}

int32_t main()
{
    //    Bismillah
    primeGen(10000);
    int t = 1;
    cin >> t;
    while(t--) solve();
}