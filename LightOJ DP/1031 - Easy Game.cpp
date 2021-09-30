#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii                     pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
int n, cs;
int a[105], sum[105];
int dp[105][105], mark[105][105];

int solve(int l, int r)
{
    if (l > r){
        return 0;
    }
    int &ret = dp[l][r];
    int &m = mark[l][r];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = -inf;
    for (int i = l; i <= r; i++){
        ret = max(ret, sum[i] - sum[l - 1] - solve(i + 1, r));
    }
    for (int i = r; i >= l; i--){
        ret = max(ret, sum[r] - sum[i - 1] - solve(l, i - 1));
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
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        printf ("Case %d: %d\n", cs, solve(1, n));
    }
    return 0;
}
