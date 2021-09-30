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

ll dp[35][35][35];

ll solve(int n, int m, int k)
{
    if (k > n || k > m) return 0;
    if (k == 0)         return 1;
    if (m == 1)         return n;
    ll &ret = dp[n][m][k];
    if (ret != -1)  return ret;
    ret = n * solve(n - 1, m - 1, k - 1) + solve(n, m - 1, k);
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    mem(dp, -1);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        int n, k;
        cin >> n >> k;
        printf ("Case %d: %lld\n", cs, solve(n, n, k));
    }
    return 0;
}

