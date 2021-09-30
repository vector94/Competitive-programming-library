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

int a[104];
int dp[104][104], mark[104][104];
int n, cs;

int solve(int l, int r)
{
    if (l > r)  return 0;
    if (l == r) return 1;
    int &ret = dp[l][r];
    if (mark[l][r] == cs)   return ret;
    mark[l][r] = cs;
    ret = 1 + solve(l + 1, r);
    for (int i = l + 1; i < n; i++){
        if (a[l] == a[i]){
            ret = min(ret, solve(l, i - 1) + solve(i + 1, r));
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
    fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        printf ("Case %d: %d\n", cs, solve(0, n - 1));
    }
    return 0;
}
