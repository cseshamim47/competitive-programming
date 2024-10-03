#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
bitset<N> is_prime;
vector<int> prime;

vector<int> segmented_sieve(int l,int r)
{
    int n = sqrt(r)+1;
    is_prime.reset();
    for(int i = 2; i*i <= n; i++)
    {
        if(is_prime[i] == 0)
        {
            for(int j = i*i; j <= n; j+=i)
            {
                is_prime[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for(int i = 3; i <= n; i+=2)
    {
        if(is_prime[i] == 0) prime.push_back(i);
    }

    vector<int> ss;
    is_prime.reset();

    for(auto p : prime)
    {
        for(int j = max(p*p,(l+p-1)/p * p); j <= r; j+=p)
        {
            is_prime[j-l] = 1; // 1 means false
        }
    }
    
    if(l == 1) is_prime[0] = 1;
    for(int i = l; i <= r; i++)
    {
        if(is_prime[i-l] == 0)
        {
            ss.push_back(i);
        }
    }
    return ss;
}

int main()
{
    //    Bismillah

    auto p = segmented_sieve(3,50);
    for(auto x : p)
    {
        cout << x << " ";
    }
    
}