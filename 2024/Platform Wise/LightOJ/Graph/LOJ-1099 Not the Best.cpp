#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


const int N = 5002;
vector<pair<int,int>> adj[N];
int wt[2][N];

void dijkstra(int source)
{
    int t = 0;
	if(source > 1) t = 1; 

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,source});
    wt[t][source] = 0;

    while(pq.size())
    {
        auto [vcost,v] = pq.top();
        pq.pop();

		if(wt[t][v] < vcost) continue;

        for(auto [c,ccost]: adj[v])
        {
            if(ccost+vcost < wt[t][c])
            {
                wt[t][c] = ccost+vcost;

                pq.push({wt[t][c],c});
            }
        }
    }
}

int cs;

void solve()
{
    int n,r;
    cin >> n >> r;

    for(int i = 0; i <= n;i++)  
    {
        adj[i].clear();
        wt[0][i] = wt[1][i] = 1e14;
    }

    for(int i = 0; i < r; i++)
    {
        int a,b,w;
        cin >> a>> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }



    dijkstra(1);

    dijkstra(n);

  
    cout << "Case " << ++cs << ": ";
    set<int> s;
    if(n == 1)
    {
        s.insert(0);
        for(int u = 1; u <= n; u++)
        {
            for(auto [v,w]: adj[u])
            {
                s.insert(w);
            }
        }
        cout << *next(s.begin()) << endl;
        return;
    }


    for(int u = 1; u <= n; u++)
    {
        for(auto [v,cost]: adj[u])
        {
            s.insert(wt[0][u]+wt[1][v]+cost);
            s.insert(wt[1][u]+wt[0][v]+cost);
        }
    }

    cout << *next(s.begin()) << endl;
}

int32_t main()
{
    //    Bismillah
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}


// other way solution

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"

// const int N = 5002;
// vector<pair<int,int>> adj[N];

// int cs;
// void solve()
// {
//     int n,r;
//     cin >> n >> r;
//     for(int i = 0; i <= n; i++)
//     {
//         adj[i].clear();
//     }
//     for(int i = 0; i < r; i++)
//     {
//         int a,b,w;
//         cin >> a >> b >> w;
//         adj[a].push_back({b,w});
//         adj[b].push_back({a,w});
        
//     }

//     /// dijkstra

//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

//     pq.push({0,1}); 

//     set<int> s;
//     if(n == 1) s.insert(0);

//     vector<int> vis(n+1,0);

//     while(pq.size())
//     {
//         int vertex = pq.top().second;
//         int v_cost = pq.top().first;
//         pq.pop();

//         vis[vertex]++;

//         if(vis[vertex] > 2) continue;

//         for(auto [child, c_cost]: adj[vertex])
//         {
//             if(vis[child] < 3)
//             {
//                 pq.push({c_cost+v_cost, child});
//             }

//             if(child == n)
//             {
//                 s.insert(c_cost+v_cost);
//             }
//         } 
//     }

//     cout << "Case " << ++cs << ": ";
//     cout << *next(s.begin()) << endl;


// }

// int32_t main()
// {
//     //    Bismillah
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
// }

// /* 
// 6 10
// 1 2 1
// 1 3 2
// 1 4 3
// 1 5 4
// 2 3 5
// 2 4 6
// 3 4 7 
// 3 5 8
// 3 6 9
// 5 6 10

//  */