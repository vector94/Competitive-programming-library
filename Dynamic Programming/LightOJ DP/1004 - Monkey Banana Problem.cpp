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

int n, tc;
int a[205][105];
int dp[205][105], mark[205][105];

int solve(int i, int j)
{
    if (i == 2 * n || j < 1 || j > n){
        return 0;
    }
    int &ret = dp[i][j];
    if (mark[i][j] == tc){
        return ret;
    }
    mark[i][j] = tc;
    if (i < n){
        ret = max(solve(i + 1, j), solve(i + 1, j + 1)) + a[i][j];
    }
    else{
        ret = max(solve(i + 1, j), solve(i + 1, j - 1)) + a[i][j];
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
        mem(a, 0);
        cin >> n;
        for (int i = 1; i <= 2 * n - 1; i ++){
            if (i <= n){
                for (int j = 1; j <= i; j++){
                    cin >> a[i][j];
                }
            }
            else{
                for (int j = 1; j <= 2 * n - i; j++){
                    cin >> a[i][j];
                }
            }
        }
        printf ("Case %d: %d\n", tc, solve(1, 1));
    }
    return 0;
}
