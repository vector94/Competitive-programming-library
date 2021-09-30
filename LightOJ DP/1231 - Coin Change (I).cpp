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
int a[55], c[55];
int dp[55][1005], mark[55][1005];
int n, k, tc;

int solve(int pos, int rem)
{
    if (pos == n){
        if (rem == 0)   return 1;
        return 0;
    }
    int &ret = dp[pos][rem];
    if (mark[pos][rem] == tc){
        return ret;
    }
    mark[pos][rem] = tc;
    ret = 0;
    for (int i = 0; i <= c[pos]; i++){
        if (rem >= (a[pos] * i)){
            ret += solve(pos + 1, rem - (a[pos] * i));
            ret %= mod;
        }
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
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        printf ("Case %d: %d\n", tc, solve(0, k));
    }
    return 0;
}


