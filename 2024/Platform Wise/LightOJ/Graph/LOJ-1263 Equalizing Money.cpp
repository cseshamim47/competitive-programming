#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 1005;
vector<int> adj[N];
vector<int> money(N);
bool vis[N];
int cnt = 0;
int dfs(int parent)
{
    vis[parent] = true;
    int sum = 0;
    for(auto child: adj[parent])
    {
        if(vis[child]) continue;
        cnt++;
        sum += money[child] + dfs(child);
    }
    return sum;
}

int cs;
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        money[i] = 0;
        cnt = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> money[i];
    }

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> s;
    cout << "Case " << ++cs << ": ";
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == false)
        {
            cnt = 1;
            int sum = money[i] + dfs(i);

            if(sum%cnt != 0)
            {
                cout << "No" << endl;
                return;
            }
            s.insert(sum/cnt);
        }
    }
    if(s.size() > 1) cout << "No" << endl;
    else cout << "Yes" << endl;
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}