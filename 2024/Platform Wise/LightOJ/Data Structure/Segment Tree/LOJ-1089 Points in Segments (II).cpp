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

// Segment Tree with Lazy Propagation start
const int mx = 2e5+10;
int arr[mx];
struct
{
    int sum,prop;
}Tree[mx*4];

void init(int node, int b, int e) // O(NlogN)
{
    if(b==e)
    {
        Tree[node].sum = 0;
        Tree[node].prop = 0;
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    init(left,b,mid);
    init(right,mid+1,e);
    Tree[node].sum = Tree[left].sum+Tree[right].sum;    
    Tree[node].prop = 0;
}

void push(int node, int b, int e)
{
    if(b != e)
    {
        int mid = (b+e)/2;
        int left = node*2;
        int right = left+1;
        Tree[left].sum += (mid-b+1)*Tree[node].prop;
        Tree[right].sum += (e-mid)*Tree[node].prop;
        Tree[left].prop += Tree[node].prop;
        Tree[right].prop += Tree[node].prop;
    }
    Tree[node].prop = 0;
}

void update(int node,int b, int e, int l, int r, int val) // O(4*logN)
{
    if(Tree[node].prop != 0)
    {
        push(node,b,e);
    }
    if(l > e || r < b) return;
    if(l <= b && r >= e)
    {
        Tree[node].sum += (val*(e-b+1));
        Tree[node].prop += val;
        if(Tree[node].prop != 0)
        {
            push(node,b,e);
        }
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    update(left,b,mid,l,r,val);
    update(right,mid+1,e,l,r,val);
    Tree[node].sum = Tree[left].sum+Tree[right].sum;  
}

int query(int node,int b,int e,int l,int r) // O(4*logN)
{
    if(Tree[node].prop != 0)
    {
        push(node,b,e);
    }
    if(l > e || r < b) return 0;
    if(l <= b && r >= e)
    {
        return Tree[node].sum;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    int val1 = query(left,b,mid,l,r);
    int val2 = query(right,mid+1,e,l,r);
    return val1 + val2;
}
// Segment Tree with Lazy Propagation end

int cs;
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> lr(n);
    map<int,int> mp;
    for(auto &[l,r]: lr)
    {
        cin >> l >> r;
        mp[l]++;
        mp[r]++;
    }
    vector<int> queries(q);
    for(int i = 0; i < q; i++)
    {
        cin >> queries[i];
        mp[queries[i]]++;
    }

    int k = 1;
    for(auto &[x,y]: mp)
    {
        y = k++;
    }

    init(1,1,k);

    for(auto &[l,r]: lr)
    {
        l = mp[l];
        r = mp[r];
        update(1,1,k,l,r,1);
    }

    cout << "Case " << ++cs << ":\n";
    for(auto &x: queries)
    {
        x = mp[x];
        cout << query(1,1,k,x,x) << endl;
    }

}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}


/* 
Case 1:
5
5
7
5
2
4
6
6
1
7
5
2
1
4
6
6
5
5
8
2
5
6
5
1
1
7
7
1
Case 2:
26
20
22
21
13
17
21
15
20
17
20
Case 3:
17
8
20
16
0
7
4
6
6
14
20
13
13
15
21
18
18
21
19
19
14
9
20
12
14
2
14
3
18
20
6
0
12
19
14
11
15
19
4
20
21
6
16
12
12
21
15
20
20
Case 4:
2
19
24
24
19
11
22
4
10
23
21
22
22
22
22
23
22
13
7
14
22
22
13
21
5
22
19
7
8
16
12
7
1
22
23
21
23
12
19
18
21
10
2
14
22
23
19
23
23
22
21
14
24
23
19
22
9
23
Case 5:
7
10
7
3




 */