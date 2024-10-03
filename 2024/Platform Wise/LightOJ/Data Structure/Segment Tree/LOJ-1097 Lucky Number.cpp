#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif


  /// Segment Tree Start
const int MX = 1429431+100;
int arr[MX];
struct {
    int idx,val;
}Tree[MX*4];

void init(int node, int b, int e)  // O(n) --> 2n nodes
{
    if(b==e)
    {
        Tree[node].idx = 1;
        Tree[node].val = arr[b];
        return;
    }
    int left = node*2; 
    int right = (node*2)+1; 
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    Tree[node].idx = Tree[left].idx + Tree[right].idx;
}


int query(int node, int b, int e, int pos) // O(4*Log(n))
{
    if(b == e)
    {
        return Tree[node].val;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    if(Tree[left].idx < pos)
    {
        return query(right,mid+1,e,pos-Tree[left].idx);
    }else 
    {
        return query(left,b,mid,pos);
    }
}

void update(int node, int b, int e, int pos) // O(LogN)
{
    if(b == e)
    {
        Tree[node].idx = 0;
        Tree[node].val = 0;
        return;
    }

    int left = node*2;
    int right = (node*2)+1;
    int mid = (b+e)/2;

    if(Tree[left].idx < pos)
    {
        update(right,mid+1,e,pos-Tree[left].idx);
    }else 
    {
        update(left,b,mid,pos);
    }
    Tree[node].idx = Tree[left].idx + Tree[right].idx;
}
/// Segment Tree end

int lim = 1429431+10;
int cs;
void solve()
{
    int n;
    cin >> n;
    cout << "Case " << ++cs << ": ";
    cout << query(1,1,lim,n) << endl;

    

}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int val = 1;
    for(int i = 1; i <= lim; i++)
    {
        arr[i] = val;
        val+=2;
    }

    init(1,1,lim);

    for(int i = 2; i <= 100000; i++)
    {   
        int baad = 0;
        int curVal = query(1,1,lim,i);
        for(int j = curVal; j <= lim; j+=curVal)
        {
            update(1,1,lim,j-baad);
            baad++;
        }
    }
    int t = 1;
    cin >> t;
    while(t--) solve();
}