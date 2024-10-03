#include <bits/stdc++.h>
using namespace std;


const int N = 1e7;
vector<int> prime;
vector<int> lp(N,0);
void lin_sieve()
{
    for(int i = 2; i < N; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.push_back(i);
        }

        for(int j = 0; j < prime.size() && prime[j]*i < N; j++)
        {
            lp[i*prime[j]] = prime[j];

            if(lp[i] == prime[j])
            {
                break;
            }
        }
    }

    // for(int i = 2; i < 30; i++) 
    // {
    //     cout << i << " : " << lp[i] << endl;
    // }
}

int main()
{
    //    Bismillah

    lin_sieve();
    
}