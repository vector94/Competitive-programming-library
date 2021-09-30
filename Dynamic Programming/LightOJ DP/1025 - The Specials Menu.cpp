#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef Lollipop
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

string s;
ll dp[65][65], mark[65][65];
int tc;

ll solve(int i, int j)
{
    if (i > j)  return 0;
    if (i == j) return 1;
    ll &ret = dp[i][j];
    if (mark[i][j] == tc)   return ret;
    mark[i][j] = tc;
    if (s[i] == s[j]){
        ret = 1 +  solve(i + 1, j) + solve(i, j - 1);
    }
    else{
        ret = solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (tc = 1; tc <= t; tc++){
        cin >> s;
        printf ("Case %d: %lld\n", tc, solve(0, s.size() - 1));
    }
    return 0;
}

