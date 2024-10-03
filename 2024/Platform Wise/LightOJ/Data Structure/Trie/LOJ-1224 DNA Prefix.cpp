#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 4;
struct node{
    node* arr[N]; // making a pointer array of size 26. the type is node struct here 
    int cnt; // for prefix count
};

node* get_node()
{   
    node* root = new node;
    for(int i = 0; i < N; i++) 
    {
        root->arr[i] = NULL;
    }
    root->cnt = 0;
    return root;
}

int insert(node* root, string &s)
{
    node* tmp = root;
    int mx = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int idx = 0;
        if(s[i] == 'A') idx = 0;
        if(s[i] == 'C') idx = 1;
        if(s[i] == 'G') idx = 2;
        if(s[i] == 'T') idx = 3;
        
        if(tmp->arr[idx] == NULL)
        {
            tmp->arr[idx] = get_node();
            
        }
        tmp = tmp->arr[idx];
        tmp->cnt++;
        mx = max(mx,(tmp->cnt * (i+1)));
    }
    return mx;
}

void delete_trie(node* root)
{
    for(int i = 0; i < N; i++)
    {
        if(root->arr[i])
        {
            delete_trie(root->arr[i]);
        }
    }
    delete root;
}

// ACGT
// ACGTGCGT
// ACCGTGC
// ACGCCGT

int cs;
void solve()
{
    int n;
    cin >> n;
    node* root = get_node();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        ans = max(ans,insert(root,a));
    }    

    cout << "Case " << ++cs << ": "; 
    cout << ans << endl;
    delete_trie(root);
}

int32_t main()
{
    //    Bismillah
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) solve();
}