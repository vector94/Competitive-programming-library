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

const int mod = 100000007;
int a[105], c[105];
int dp[10005];
int n, k, tc;

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
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        mem(dp, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 1; j <= k; j++){
                if (a[i] <= j){
                    dp[j] = dp[j] + dp[j - a[i]];
                    dp[j] %= mod;
                }
            }
        }
        printf ("Case %d: %d\n", tc, dp[k]);
    }
    return 0;
}
