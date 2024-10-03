#include <bits/stdc++.h>
using namespace std;


int get_pivot(int l, int r, vector<int>&v)
{
    srand(time(0));
    int i = l+rand()%(r-l+1);
    swap(v[l],v[i]);
    int pivot = l;
    while(l < r)
    {
        do{
            l++;
        }while(v[l] <= v[pivot]);
        do{
            r--;
        }while(v[r] > v[pivot]);

        if(l < r) swap(v[l],v[r]);
    }
    swap(v[pivot],v[r]);
    return r;

}

int quickselect(int l, int r, int kth_largest,vector<int> &v)
{
    if(l < r)
    {
        int pivot = get_pivot(l,r,v);
        int cur = r-pivot;
        if(cur == kth_largest)
        {
            return v[pivot];
        }
        if(cur < kth_largest)
        {
            return quickselect(l,pivot,kth_largest-cur, v);
        }else 
        {
            return quickselect(pivot+1,r,kth_largest,v);
        }
    }
    return -1;
}


int main()
{
    //    Bismillah
    srand(time(0));
    vector<int> v = {14,5,1,6,12,11,16,7};
    v.clear();
    int n = 8;
    // cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x = rand()%21;
        v.push_back(x);
    }


    int kth_largest = 5;

    for(auto x : v) cout << x << " ";cout << endl;
    v.push_back(1e8);

    cout << quickselect(0, n,kth_largest,v) << endl;
    v.pop_back();
    for(auto x : v) cout << x << " ";cout << endl;
    
}