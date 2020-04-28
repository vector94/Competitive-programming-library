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

int cost[205][205];
int req[1005];
int dp[2][205][205];
int n, l;

int solve()
{
    mem(dp, 0x3f);
    dp[0][1][2] = 0;
    req[0] = 3;
    for (int i = 1; i <= n; i++){
        int a = req[i - 1];
        int next = req[i];
        int cur = i % 2;
        int pre = cur ^ 1;
        for (int b = 1; b <= l; b++){
            for (int c = 1; c <= l; c++){
                dp[cur][b][c] = INT_MAX;
            }
        }
        for (int b = 1; b <= l; b++){
            for (int c = 1; c <= l; c++){
                if (a == b || a == c || b == c){
                    continue;
                }
                if (b != next && c != next){
                    dp[cur][b][c] = min(dp[cur][b][c], dp[pre][b][c] + cost[a][next]);
                }
                if (a != next && c != next){
                    dp[cur][a][c] = min(dp[cur][a][c], dp[pre][b][c] + cost[b][next]);
                }
                if (b != next && a != next){
                    dp[cur][b][a] = min(dp[cur][b][a], dp[pre][b][c] + cost[c][next]);
                }
            }
        }
    }
    int ret = INT_MAX;
    for (int i = 1; i <= l; i++){
        for (int j = 1; j <= l; j++){
            ret = min (ret, dp[n % 2][i][j]);
        }
    }
    return ret;
}

int main()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    while (t--){
        cin >> l >> n;
        for (int i = 1; i <= l; i++){
            for (int j = 1; j <= l; j++){
                cin >> cost[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            cin >> req[i];
        }
        cout << solve() << endl;
    }
}
