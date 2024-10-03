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
const int mx = 2e5+100;
int arr[mx];
struct
{
    int one,two,zero,prop;
}Tree[mx*4];

void init(int node, int b, int e) // O(NlogN)
{
    if(b==e)
    {
        Tree[node].zero = 1;
        Tree[node].one = 0;
        Tree[node].two = 0;
        Tree[node].prop = 0;
        return;
    }
    int mid = (b+e)/2;
    int left = node*2;
    int right = (node*2)+1;
    init(left,b,mid);
    init(right,mid+1,e);
    Tree[node].zero = Tree[left].zero+Tree[right].zero; 
    Tree[node].one = Tree[left].one+Tree[right].one; 
    Tree[node].two = Tree[left].two+Tree[right].two; 
    Tree[node].prop = 0;   
}

void normal(int &x)
{
    x %= 3;
}

void push(int node, int b, int e)
{
	if(b != e)
	{
		int mid = (b+e)/2;
		int left = node*2;
		int right = left+1;
        if(Tree[node].prop == 1)
        {
            int one = Tree[left].one;
            Tree[left].one = Tree[left].two;
            Tree[left].two = Tree[left].zero;
            Tree[left].zero = one;

            one = Tree[right].one;
            Tree[right].one = Tree[right].two;
            Tree[right].two = Tree[right].zero;
            Tree[right].zero = one;
        }else if(Tree[node].prop == 2) 
        {
            int one = Tree[left].one;
            Tree[left].one = Tree[left].zero;
            Tree[left].zero = Tree[left].two;
            Tree[left].two = one;

            one = Tree[right].one;
            Tree[right].one = Tree[right].zero;
            Tree[right].zero = Tree[right].two;
            Tree[right].two = one;
        }
		Tree[left].prop += Tree[node].prop;
		Tree[right].prop += Tree[node].prop;
	}
	Tree[node].prop = 0;
}

void update(int node,int b, int e, int l, int r, int val) // O(4*logN)
{

    normal(Tree[node].prop);
    if(Tree[node].prop != 0)
    {
        push(node,b,e);
    }
    if(l > e || r < b) return;
    if(l <= b && r >= e)
    {
        int one = Tree[node].one;
        Tree[node].one = Tree[node].two;
        Tree[node].two = Tree[node].zero;
        Tree[node].zero = one;

        Tree[node].prop += val;
        normal(Tree[node].prop);
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
    Tree[node].zero = Tree[left].zero+Tree[right].zero;  
    Tree[node].one = Tree[left].one+Tree[right].one;  
    Tree[node].two = Tree[left].two+Tree[right].two;  
}

int query(int node,int b,int e,int l,int r) // O(4*logN)
{
    normal(Tree[node].prop);
    if(Tree[node].prop != 0)
    {
        push(node,b,e);
    }
    if(l > e || r < b) return 0;
    if(l <= b && r >= e)
    {
        return Tree[node].zero;
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
    
    init(1,1,n);

    cout << "Case " << ++cs << ":\n";
    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        int l,r;
        cin >> l >> r;
        l++;
        r++;
        if(t == 0)
        {
            update(1,1,n,l,r,1);
        }else 
        {
            cout << query(1,1,n,l,r) << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}