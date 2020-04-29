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
#define endl                    "\n"
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

const int mod = 1e9 + 7;
int dp[1005][1005], mark[1005][1005];
int n, k, d, cs;

int solve(int pos, int cnt)
{
    if (pos <= 0){
        if (cnt == 0){
            return 1;
        }
        return 0;
    }
    int &ret = dp[pos][cnt];
    int &m = mark[pos][cnt];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    ret += solve(pos - 1, cnt);
    ret %= mod;
    if (cnt){
        ret += solve(pos - d, cnt - 1);
    }
    ret %= mod;
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> n >> k >> d;
        int res = 0;
        for (int i = 1; i <= n; i++){
            int cur = n - i + 1 - d - max(0, d - i);
            res += solve(cur, k - 1);
            res %= mod;
        }
        printf ("Case %d: %d\n", cs, res);
    }
    return 0;
}


