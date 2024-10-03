/* 

1
8
baggers -> bs
beggars -> bs
in -> in 
the -> te
blowed -> bd
bowled -> bd
barn -> bn
bran -> bn
1
beggars bowled in the barn

bs bd in te bn
bs(2) bd(2) in(1) te(1) bn(2)

baggers blowed in the barn
baggers blowed in the bran
baggers bowled in the barn
baggers bowled in the bran

beggers blowed in the barn
beggers blowed in the bran
beggers bowled in the barn
beggers bowled in the bran
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

const int N = 53;
struct node{
    node* arr[N];
    int cnt;
};

node* get_node()
{
    node* root = new node;
    for (int i = 0; i < N; i++)
    {
        root->arr[i] = NULL;
    }
    root->cnt = 0;
    return root;
}

void insert(node* root, string &s)
{
    node* tmp = root;
    for(int i = 0; i < s.size(); i++)
    {
        int idx = 0;
        if(s[i] < 'a') idx = s[i]-'A'+26;
        else idx = s[i]-'a';

        if(tmp->arr[idx] == NULL)
        {
            tmp->arr[idx] = get_node();
        }
        tmp = tmp->arr[idx];
    }
    tmp->cnt++;
}

int ask(node* root, string &s)
{
    node* tmp = root;
    for(int i = 0; i < s.size(); i++)
    {
        int idx = 0;
        if(s[i] < 'a') idx = s[i]-'A'+26;
        else idx = s[i]-'a';

        if(tmp->arr[idx] == NULL) return 0;
        tmp = tmp->arr[idx];
    }
    if(s.size() == 0) return 1;
    return tmp->cnt;
}

void delete_trie(node* root)
{
    for(int i = 0; i < N; i++)
    {
        if(root->arr[i]) delete_trie(root->arr[i]);
    }
    delete root;
}

int cs;
void solve()
{
    int n;
    cin >> n;
    string s;
    node* root = get_node();
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(s.size() > 2)
        sort(s.begin()+1,s.end()-1);

        insert(root,s);
    }

    int q;
    cin >> q;
    cout << "Case " << ++cs << ":\n";
    getchar();

    while(q--)
    {   
        int ans = 1;
        getline(cin,s);
        string t = "";
        s.push_back(' ');
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ') t.push_back(s[i]);
            else 
            {
                if(t.size() > 2)
                sort(t.begin()+1,t.end()-1);

                ans *= ask(root,t);
                t.clear();
            }
        }
        cout << ans << endl;
    }

    delete_trie(root);
}

int32_t main()
{
    //    Bismillah
    int t = 1;
    cin >> t;
    while(t--) solve();
}