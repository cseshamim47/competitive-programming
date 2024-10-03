#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,m;
char c[21][21];
bool vis[21][21];
struct node{
    int i, j;
    int cost;
    node(){
    }
    node(int i, int j, int cost){this->i = i; this->j = j; this->cost = cost;}
};
int dx[] = {-1, 1, 0, 0,-1,-1, 1,1};
int dy[] = { 0, 0,-1, 1,-1, 1,-1,1};
int bfs(int i, int j)
{
    memset(vis,false,sizeof vis);
    queue<node> q;
    q.push(node(i,j,0));
    vis[i][j] = true;
    while(q.size())
    {
        auto [i,j,cost] = q.front();
        q.pop();
        
        for(int x = 0; x < 4; x++)
        {
            int ni = i + dx[x];
            int nj = j + dy[x];
            if(ni < n && nj < m && ni >= 0 && nj >= 0)
            {
                if(vis[ni][nj] || c[ni][nj] == '#') continue;
                vis[ni][nj] = true;
                q.push(node(ni,nj,cost+1));
            }
        }
        if(c[i][j] == 'h') return cost;
    }

    return 0;

}


int cs;
void solve()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if(c[i][j] == 'm') c[i][j] = '#';
        }
    }
    int cost = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(c[i][j] == 'a') 
            {
                int k = bfs(i,j);
                cost = max(cost,k);
            }
            if(c[i][j] == 'b') 
            {
                int k = bfs(i,j);
                cost = max(cost,k);
            }
            if(c[i][j] == 'c') 
            {
                int k = bfs(i,j);
                cost = max(cost,k);
            }
        }
    }
    cout << "Case " << ++cs << ": ";
    cout << cost << endl;

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}