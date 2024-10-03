// https://toph.co/p/going-round-in-circles

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N = 2e5+100;
const int INF = 1e9;
int arr[N];
struct{
    int val,idx;
}Tree[4*N];

void init(int node,int b,int e)
{
    if(b == e)
    {
        Tree[node].val = arr[b];
        Tree[node].idx = b; 
        return;
    }

    int left = node*2;
    int right = left+1;
    int mid = (b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);

    Tree[node].val = Tree[left].val + Tree[right].val;
    Tree[node].idx = min(Tree[left].idx,Tree[right].idx);
}

void update(int node, int b, int e, int i, int val, bool done)
{
    if(i < b || i > e) return;
    if(b == i && e == i)
    {
        Tree[node].val = val;
        if(done) Tree[node].idx = INF;
        return;
    } 
    int left = node*2;
    int right = left+1;
    int mid = (b+e)>>1;
    update(left,b,mid,i,val,done);
    update(right,mid+1,e,i,val,done);
    Tree[node].val = Tree[left].val + Tree[right].val;
    Tree[node].idx = min(Tree[left].idx,Tree[right].idx);
}

int minIdx(int node, int b, int e, int l, int r)
{
    // base case 
    if(e < l || r < b) return 1e9;
    if(l <= b && e <= r)
    {
        return Tree[node].idx;
    }
    int left = node*2;
    int right = left+1;
    int mid = (b+e)>>1;
    return min(minIdx(left,b,mid,l,r),minIdx(right,mid+1,e,l,r));
}

int query(int node,int b, int e, int l, int r)
{
    if(e < l || r < b) return 0;
    if(l <= b && e <= r)
    {
        return Tree[node].val;
    }
    int left = node*2;
    int right = left+1;
    int mid = (b+e)>>1;
    return query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}


void solve()
{
    int n,q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    init(1,1,n);
    while(q--)
    {
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1)
        {
            while(l <= r)
            {
                int val = query(1,1,n,l,l);
                
                deque<int> dq;
                while(val)
                {
                    dq.push_front(val%2);
                    val/=2;
                }
                if(dq.size())
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    while(dq.size() && dq.front() == 0) dq.pop_front();
                    val = 0;
                    bool noZero = true;
                    int i = 0;
                    while(dq.size())
                    {
                        if(dq.back()==1)
                        {
                            val += (1 << i);
                        }else 
                        {
                            noZero = false;
                        }
                        dq.pop_back();
                        i++;
                    }

                    update(1,1,n,l,val,noZero);

                }else 
                {
                    update(1,1,n,l,0,true);
                }
                l++;
                l = minIdx(1,1,n,l,r);
            }
        }else 
        {
            cout << query(1,1,n,l,r) << endl;
        }
    }

}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}