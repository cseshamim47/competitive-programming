#include <bits/stdc++.h>
using namespace std;
#define endl "\n"



int dx[] = {-1, 1, 0, 0,-1,-1, 1,1};
int dy[] = { 0, 0,-1, 1,-1, 1,-1,1};

int cs;
void solve()
{
    int n,m;
    cin >> n >> m;
    char v[n][m];
    queue<pair<pair<int,int>,int>> q;
    int lvl[2][n][m];
    bool vis[2][n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            lvl[0][i][j] = lvl[1][i][j] = 1e6;
            vis[0][i][j] = vis[1][i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if(v[i][j] == 'J')
            {
                q.push({{i,j},0});
                lvl[0][i][j] = 0;
                vis[0][i][j] = true;
            }else  if(v[i][j] == 'F') 
            {
                q.push({{i,j},1});
                lvl[1][i][j] = 0;
                vis[1][i][j] = true;
            }
        }
    }   

    int mn = 1e8;
    while(q.size())
    {
        auto [pos,t]=q.front();
        auto [i,j] = pos;

        q.pop();
        
        for(int x = 0; x < 4; x++)
        {
            int ni = i+dx[x];
            int nj = j+dy[x];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m)
            {
                if(vis[t][ni][nj] || v[ni][nj] == '#') continue;
                // debug(v[ni][nj]);
                lvl[t][ni][nj] = 1 + lvl[t][i][j];
                q.push({{ni,nj},t});
                vis[t][ni][nj] = true;
            }
        }
    }


    cout << "Case " << ++cs << ": ";
    int ans = 1e6;
    for(int i = 0; i < m; i++)
    {
        if(lvl[0][0][i] < lvl[1][0][i])
        {
            ans = min(ans,lvl[0][0][i]+1);
        }
        if(lvl[0][n-1][i] < lvl[1][n-1][i])
        {
            ans =  min(ans,lvl[0][n-1][i]+1);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(lvl[0][i][0] < lvl[1][i][0])
        {
            ans = min(ans,lvl[0][i][0]+1);
        }
        if(lvl[0][i][m-1] < lvl[1][i][m-1])
        {
            ans = min(ans,lvl[0][i][m-1]+1);
        }
    }


    if(ans == 1e6)
    cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;

}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}