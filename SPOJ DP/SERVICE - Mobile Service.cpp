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

int cost[1005][1005];
int l, n, cs;
int req[1005];
int dp[1005][205][205], mark[1005][205][205];

int solve(int pos, int a, int b)
{
    if (pos > n){
        return 0;
    }
    int &ret = dp[pos][a][b];
    int &m = mark[pos][a][b];
    if (m == cs){
        return ret;
    }
    int c = req[pos - 1];
    int next = req[pos];
    m = cs;
    ret = 1e8;
    if (next != a && next != b){
        ret = min(ret, cost[c][next] + solve(pos + 1, a, b));
    }
    if (next != c && next != b){
        ret = min(ret, cost[a][next] + solve(pos + 1, c, b));
    }
    if (next!= c && next != a){
        ret = min(ret, cost[b][next] + solve(pos + 1, c, a));
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
    for (cs = 1; cs <= t; cs++){
        cin >> l >> n;
        for (int i = 1; i <= l; i++){
            for (int j = 1; j <= l; j++){
                cin >> cost[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            cin >> req[i];
        }
        req[0] = 3;
        int res = INT_MAX;
        cout << solve(1, 1, 2) << endl;
    }
    return 0;
}

