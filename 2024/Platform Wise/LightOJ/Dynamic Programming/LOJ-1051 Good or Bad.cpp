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

bool isVowel(char c){
    if(c=='A' or c=='E' or c=='I' or c=='O' or c=='U')
        return true;
    return false;
}
int dp[50][3][5];
int vis[50][3][5];
int cs;
int f(int pos,int vowel, int cons, string &s)
{
    if(vowel == 3 || cons == 5) return 1;
    if(pos == s.size()) return 0;
    
    int &d = dp[pos][vowel][cons];
    int &v = vis[pos][vowel][cons];

    if(v == cs) return d;
    v = cs;

    if(s[pos] == '?')
    {
        int v = f(pos+1,vowel+1,0,s);
        int c = f(pos+1,0,cons+1, s);

        // if vowel and consonant both return 1 meaning the string is definately bad then return 1
        if(v == 1 && c == 1)
        {
            return d = 1;
        }
        if(v == 1 && c == 1)
        {
            return d = 1;
        }

        // if vowel and consonant returns different meaning one of them retured bad and other one returned good

        if(v == 0 && c == 1) return d = 2;
        if(v == 1 && c == 0) return d = 2;

        // they might return 2 also if the next part of the string is mixed 

        if(v == 2 || c == 2) return d = 2;

        // if both returns 0 meaning the string is good. There is no way making is bad or mixed

        return d = 0;
    }else if(isVowel(s[pos]))
    {
        return d = f(pos+1,vowel+1,0,s);
    }else 
    {
        return d = f(pos+1,0,cons+1,s);
    }
}

void solve()
{
    vector<string> res = {"GOOD", "BAD", "MIXED"};
    string s;
    cin >> s;
    int idx = f(0,0,0,s);
    cout << "Case " << ++cs << ": ";
    cout << res[idx] << endl;
}

int32_t main()
{
    //    Bismillah
    memset(vis,-1,sizeof vis);
    int t = 1;
    cin >> t;
    while(t--) solve();
}









// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define all(x) x.begin(),x.end()
// // #define int long long

// #ifdef SHAMIM_AHMED
//     #include <G:\Desktop Items\STATION\CPP\debug.h>
// #else
//     #define debug(x...) 
//     #define debug2(x...) 
//     #define debug3(x...)
// #endif


// int check(string &s)
// {
//     // cons a
//     int a = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         if(s[i] == 'a')
//         {
//             int j = i;
//             int cnt = 0;
//             while(j < s.size() && s[j] == 'a') cnt++,j++;
//             i = j;
//             a = max(a,cnt);
//         }
//     }

//     // cons b
//     int b = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         if(s[i] == 'b')
//         {
//             int j = i;
//             int cnt = 0;
//             while(j < s.size() && s[j] == 'b') cnt++,j++;
//             i = j;
//             b = max(b,cnt);
//         }
//     }
//     return (a >= 3 || b >= 5);
// }

// int gen(int pos, string k)
// {
//     if(pos == k.size())
//     {
//         int chk = check(k);

//         return (1 << chk);
//     }
//     int res = 0;
//     if(k[pos] != '?') res |= gen(pos+1,k);
//     else 
//     {
//         k[pos] = 'a';
//         res |= gen(pos+1,k);
//         k[pos] = 'b';
//         res |= gen(pos+1,k);
//     }
//     return res;
// } 

// int cs;
// void solve()
// {
//     string a;
//     cin >> a;
//     transform(all(a),a.begin(),::tolower);
//     for(int i = 0; i < a.size(); i++)
//     {
//         if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
//         {
//             a[i] = 'a';
//         }else if(a[i] != '?')
//         {
//             a[i] = 'b';
//         }
//     }

//     // debug(a);
//     int n = a.size();
    
//     map<int,int> mp;

//     for(int i = 0; i < a.size();)
//     {
//         string str = "";
//         int cnt = 0;
//         int j = i;
//         for(j = i; j < a.size(); j++)
//         {
//             if(a[j] == '?') cnt++;
//             if(cnt > 15) break;
//             str.push_back(a[j]);
//         }
//         int g = gen(0,str);
//         mp[g]++;
//         if(j-5 > i)
//         i = j-5;
//         else i = j;
//     }

//     cout << "Case " << ++cs << ": ";
//     if(mp[2]) cout << "BAD" << endl;
//     else if(mp[3]) cout << "MIXED" << endl;
//     else cout << "GOOD" << endl;

// }

// int32_t main()
// {
//     //    Bismillah
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     int t = 1;
//     cin >> t;

//     while(t--) solve();
// }