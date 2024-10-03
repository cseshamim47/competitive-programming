#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 21;
bool vis[N][N];
char a[N][N];

int dx[] = {-1, 1, 0, 0,-1,-1, 1,1};
int dy[] = { 0, 0,-1, 1,-1, 1,-1,1};


int n,m;
bool is_valid(int i, int j)
{
    if(i == m || j == n || i < 0 || j < 0 || vis[i][j] || a[i][j] == '#') return false;

    return true;
}

int dfs(int i, int j)
{
    vis[i][j] = true;

    int sum = 0;
    for(int x = 0; x < 4; x++)
    {
        int ni = i+dx[x];
        int nj = j+dy[x];
        if(is_valid(ni,nj))
        {
            sum += 1 + dfs(ni,nj);
        }
    }
    return sum;
}

int cs;


void solve()
{
    cin >> n >> m;
    int si,sj;
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            vis[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '@') si = i, sj = j;
        }
    }
    cout << "Case " << ++cs << ": ";
    cout << dfs(si,sj)+1 << endl;
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}