#include <bits/stdc++.h>
using namespace std;


int findPivot(int l, int r, vector<int>&v) /// meaning it's left side will be less than and right side will be greater than. 
{   
    int pivot = l;

    while(l < r)
    {
        do{
            l++;
        }while(v[l] <= v[pivot]);

        do{
            r--;
        }while(v[r] > v[pivot]);

        if(l < r)
        swap(v[l],v[r]);
    }
    swap(v[r],v[pivot]);
    return r;

}

void quicksort(int l, int r, vector<int> &v)
{
    if(l < r)
    {
        int p = findPivot(l,r,v);
        quicksort(l,p,v);
        quicksort(p+1,r,v);
    }
}


int main()
{
    //    Bismillah
    srand(time(0));
    vector<int> v;
    int n = 8;
    // cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x = rand()%21;
        v.push_back(x);
    }

    for(auto x : v) cout << x << " ";cout << endl;
    v.push_back(1e8);

    quicksort(0, n,v);
    
    v.pop_back();
    for(auto x : v) cout << x << " ";cout << endl;
}