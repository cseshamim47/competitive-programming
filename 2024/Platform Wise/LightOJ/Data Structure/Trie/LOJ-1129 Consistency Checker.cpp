#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 10;
struct node{
    node* arr[N];
    bool end;
};

node* get_node()
{
    node* root = new node;
    for(int i = 0; i < N; i++)
    {
        root->arr[i] = NULL;
    }
    root->end = false;
    return root;
}

bool insert(node* root, string &s)
{
    node* tmp = root;
    bool ok = true;
    for(int i = 0; i < s.size(); i++)
    {
        int idx = s[i]-'0';
        if(tmp->arr[idx] == NULL)
        {
            tmp->arr[idx] = get_node();
            ok = false;
        }
        tmp = tmp->arr[idx];
        if(tmp->end) return true;
    }
    tmp->end = true;
    return ok;
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


int cs;
void solve()
{
    int n;
    cin >> n;
    node* root = get_node();
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;   
        if(!ok)
        {
            ok = insert(root,s);
        }
    }   
    cout << "Case " << ++cs << ": ";
    if(ok) 
    {
        cout << "NO" << endl;
    }else cout << "YES" << endl;

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