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


// count number of elements that are less than or equal to K in a range

const int N = 100;
vector<vector<int>> segment(N);
int preproces(vector<int> &input) 
{
    int n = input.size();
    int currentSegment = -1;
    int segmentSize = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        if(i%segmentSize == 0) 
        {
            if(currentSegment != -1)
            {
                sort(all(segment[currentSegment]));
            }
            currentSegment++; // new segment
        }

        segment[currentSegment].push_back(input[i]);
    }

    return segmentSize;
}

int query(vector<int> &input, int segmentSize, int l, int r, int k) // 0 indexed
{
    int cnt = 0;

    int lblock = l/segmentSize; // left tail block index
    int rblock = r/segmentSize; // right tail block index

    if(lblock == rblock) // if l and r lies in same block
    {
        while(l <= r)
        {
           if(input[l] <= k)
           {
                cnt++;
           }
           l++;
        }
    }else 
    {
        // looping the first segment
        int lim = (lblock+1)*segmentSize;
        while(l < lim)
        {
            if(input[l] <= k)
            {
                cnt++;
            }
            l++;
        }

        // jumping the in between segments
        lblock += 1;
        while(lblock < rblock)
        {
            auto &v = segment[lblock];
            debug(v);
            debug((int)v.size())
            auto ub = upper_bound(all(v),k) - v.begin();
            l += segmentSize;
            lblock++;
            cnt += ub;

        }

        // looping the last segment
        while(l<=r)
        {
            if(input[l]  <= k)
            {
                cnt++;
            }

            l++;
        }
    }

    return cnt;
}




int main()
{
    //    Bismillah
    int n,q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int segSize = preproces(v);
    
    debug(v);

    while(q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        l--;
        r--;
        cout << query(v,segSize,l,r,k) << endl;
    }

    /* 
    10 100
    1 2 3 4 5 6 7 8 9 -10 
    
    */
    
}