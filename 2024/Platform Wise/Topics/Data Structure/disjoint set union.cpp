#include <bits/stdc++.h>
using namespace std;

struct DisjointSet{
    vector<int> size, parent; 
    DisjointSet(){}
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int find_parent(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = find_parent(parent[u]);
    }

    bool union_by_size(int u, int v)
    {
        int pu = find_parent(u); // ultimate parent of u
        int pv = find_parent(v); // ultimate parent of v

        if(pu == pv) return false;

        if(size[pu] >= size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }else 
        {
            parent[pu] = pv;
            size[pv]  += size[pu];
        }
        return true;
    }
};

int main()
{
    //    Bismillah
    DisjointSet ds(7);
    ds.union_by_size(1,2);
    ds.union_by_size(2,3);

    ds.union_by_size(4,5);
    ds.union_by_size(6,7);
    ds.union_by_size(5,6);

    if(ds.find_parent(2) != ds.find_parent(6))
    {
        cout << "Not Connected" << endl;
    }else cout << "Connected" << endl;

    ds.union_by_size(2,6);
    if(ds.find_parent(1) != ds.find_parent(7))
    {
        cout << "Not Connected" << endl;
    }else cout << "Connected" << endl;
}