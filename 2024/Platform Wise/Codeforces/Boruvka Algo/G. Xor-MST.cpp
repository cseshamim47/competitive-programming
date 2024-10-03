#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ll long long

#ifndef ONLINE_JUDGE
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

const int N = 30;
int trie[200001*30][2],node;
int cnt[200001*30];
int id[200001*30];

void insert(int n, int index)
{
    int root = 1;
    for(int i = 29; i >= 0; i--)
    {
        int idx = (1 & (n >> i));

        if(trie[root][idx] == 0)
        {
            trie[root][idx] = node++;
        }
        root = trie[root][idx];
        cnt[root]++;
    }
    id[root] = index;
}

bool check(int n)
{
    int root = 1;
    for(int i = 29; i >= 0; i--)
    {
        int idx = (1 & (n >> i));
        if(trie[root][idx] == 0) return false;

        root = trie[root][idx];
    }
    return cnt[root];
}

void remove(int n)
{
    int root = 1;
    for(int i = 29; i >= 0; i--)
    {
        int idx = (1 & (n >> i));
        root = trie[root][idx];
        cnt[root]--;
    }
}

pair<int,int> getMinXor(int n)
{
    int root = 1;
    int x = 0;
    for(int i = 29; i >= 0; i--)
    {
        int idx = (1 & (n>>i));
        if(trie[root][idx] && cnt[trie[root][idx]])
        {
            root = trie[root][idx];
        }else 
        {
            x += (1 << i);
            root = trie[root][idx^1];
        }
    }

    return {x,id[root]};
}


struct Edge{
    int u,v,cost;
    Edge(){}
    Edge(int u, int v, int cost){
        this->u = u;
        this->v = v;
        this->cost = cost;
    }
};
vector<int> Size,parent;
vector<vector<int>> comp;
vector<Edge> min_edge;


void init(int n)
{
    Size.resize(n+1);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++)
    {
        Size[i] = 1;
        parent[i] = i;
    }
}

int find_parent(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}

bool merge(int u, int v)
{
    int pu = find_parent(u);
    int pv = find_parent(v);
    if(pu == pv) return false;

    if(Size[pu] >= Size[pv])
    {
        Size[pu] += Size[pv];
        parent[pv] = pu;
    }else 
    {
        Size[pv] += Size[pu];
        parent[pu] = pv;
    }
    return true;
}



void solve()
{

    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(all(a));
    unique(all(a));

    n = a.size();
    int component = n;

    init(n);
    min_edge.resize(n);

    comp.resize(n+1,vector<int>());

    ll ans = 0;

    while(component > 1)
    {
        for(int i = 0; i < n; i++) comp[i].clear();
        for(int i = 0; i <= node; i++) 
        {
            trie[i][0] = trie[i][1] = 0;
            id[i] = cnt[i] = 0;
        }

        node = 2;
        for(int i = 0; i < n; i++)
        {
            insert(a[i],i);
            min_edge[i].cost = -1;
            int par = find_parent(i);
            comp[par].push_back(i);
        }
       

        for(int i = 0; i < n; i++)
        {
            for(auto x : comp[i])
            {
                remove(a[x]);
            }
                    
            for(auto x : comp[i])
            {
                auto [min_xor,idx] = getMinXor(a[x]);

                int u = x;
                int v = idx;

                int pu = find_parent(u);
                int pv = find_parent(v);

                if(pu == pv) continue;
                
                if(min_edge[pu].cost == -1 || min_edge[pu].cost > min_xor)
                {
                    min_edge[pu].cost = min_xor;
                    min_edge[pu].u = u;
                    min_edge[pu].v = v;
                }

                if(min_edge[pv].cost == -1 || min_edge[pv].cost > min_xor)
                {
                    min_edge[pv].cost = min_xor;
                    min_edge[pv].u = u;
                    min_edge[pv].v = v;
                }

            }
            for(auto x : comp[i])
            {
                insert(a[x],x);
            }

        }

        for(int i = 0; i < n; i++)
        {
            auto [u,v,cost] = min_edge[i];
          
            if(cost == -1) continue;

            if(merge(u,v))
            {
                ans += cost;
                component--;
            }
        }        
    }

    cout << ans << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}