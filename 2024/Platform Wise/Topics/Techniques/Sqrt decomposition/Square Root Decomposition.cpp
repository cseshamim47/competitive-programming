#include <bits/stdc++.h>
using namespace std;

// This code is for summation

const int N = 1e4;
vector<int> segment(N);
int preproces(vector<int> &input) 
{
    int n = input.size();
    int currentSegment = -1;
    int segmentSize = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        if(i%segmentSize == 0) currentSegment++; // new segment

        segment[currentSegment] += input[i];
    }

    return segmentSize;
}

int query(vector<int> &input, int segmentSize, int l, int r) // 0 indexed
{
    int sum = 0;

    int lblock = l/segmentSize; // left tail block index
    int rblock = r/segmentSize; // right tail block index

    if(lblock == rblock) // if l and r lies in same block
    {
        while(l <= r)
        {
            sum += input[l++];
        }
    }else 
    {
        // looping the first segment
        int lim = (lblock+1)*segmentSize;
        while(l < lim)
        {
            sum += input[l];
            l++;
        }

        // jumping the in between segments
        lblock += 1;
        while(lblock < rblock)
        {
            sum += segment[lblock++];
            l += segmentSize;
        }

        // looping the last segment
        while(l<=r)
        {
            sum += input[l++];
        }
    }

    return sum;
}

void update(int idx, int val, int segmentSize, vector<int> &input)
{
    int seg = idx/segmentSize;
    segment[seg] -= input[idx];
    input[idx] = val;
    segment[seg] += input[idx];
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
    

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(v,segSize,l,r) << endl;
    }

    /* 
    10 100
    1 2 3 4 5 6 7 8 9 -10 
    
    */
    
}