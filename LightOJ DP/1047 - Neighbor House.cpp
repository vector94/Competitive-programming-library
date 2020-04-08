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

const int inf = 1e9;
int a[25][5];
int dp[5][25], mark[5][25];
int n, tc;

int solve(int pre, int pos)
{
    if (pos > n){
        return 0;
    }
    int &ret = dp[pre][pos];
    if (mark[pre][pos] == tc){
        return ret;
    }
    mark[pre][pos] = tc;
    ret = inf;
    for (int i = 1; i <= 3; i++){
        if (i != pre){
            ret = min(ret, a[pos][i] + solve(i, pos + 1));
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
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= 3; j++){
                cin >> a[i][j];
            }
        }
        printf ("Case %d: %d\n", tc, solve(1, 0));
    }
    return 0;
}


