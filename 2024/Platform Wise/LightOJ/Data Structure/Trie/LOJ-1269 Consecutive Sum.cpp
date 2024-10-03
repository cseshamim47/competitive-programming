#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 2;
struct node{
    node* arr[2];
};

node* get_node()
{
    node* root = new node();
    root->arr[0] = root->arr[1] = NULL;
    return root;
}

void insert(node* root, int n)
{
    node* tmp = root;
    for(int i = 31; i >= 0; i--)
    {
        int idx = (1 & (n >> i));
        if(tmp->arr[idx] == NULL)
        {
            tmp->arr[idx] = get_node();
        }
        tmp = tmp->arr[idx];
    }
}

int ask(node* root, int n,string s)
{
    node* tmp = root;
    int ans = 0;
    for(int i = 31; i >= 0; i--)
    {
        if(s == "max")
        {
            int idx = (1 & (n >> i));
            if(tmp->arr[idx^1])
            {
                ans += (1 << i);
                tmp = tmp->arr[idx^1];
            }else 
            {
                tmp = tmp->arr[idx];
            }
        }else 
        {
            int idx = (1 & (n >> i));
            // cout << s << " " <<  idx << " " << i << endl;
            if(tmp->arr[idx])
            {
                tmp = tmp->arr[idx];
            }else 
            {
                ans += (1 << i);
                tmp = tmp->arr[idx^1];
            }
        }
    }
    return ans;
}

void dlt(node* root)
{
    if(root->arr[0]) dlt(root->arr[0]);
    if(root->arr[1]) dlt(root->arr[1]);
    delete root;
}

int cs;
void solve()
{
    int n;
    cin >> n;
    int x = 0;
    node* root = get_node();
    insert(root,0);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        x ^= k;
        mn = min(mn,ask(root,x, "min"));
        mx = max(mx,ask(root,x,"max"));
        insert(root,x);
    }

    cout << "Case " << ++cs << ": ";
    cout << mx << " " << mn << endl;
    dlt(root);
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}