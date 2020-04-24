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

string a, b;
int dp[65][65][65][65], mark[65][65][65][65];
int cs;

int solve(int l1, int r1, int l2, int r2)
{
    if (l1 > r1 || l2 > r2) return 0;
    if (l1 == r1 && l2 == r2 && a[l1] == b[l2]) return 1;
    int &ret = dp[l1][r1][l2][r2];
    if (mark[l1][r1][l2][r2] == cs) return ret;
    mark[l1][r1][l2][r2] = cs;
    ret = 0;
    if (l1 < r1 && l2 < r2 && a[l1] == a[r1] && b[l2] == b[r2] && a[l1] == b[l2]){
        ret = 2 + solve(l1 + 1, r1 - 1, l2 + 1, r2 - 1);
    }
    ret = max(ret, solve(l1 + 1, r1, l2, r2));
    ret = max(ret, solve(l1, r1 - 1, l2, r2));
    ret = max(ret, solve(l1, r1, l2 + 1, r2));
    ret = max(ret, solve(l1, r1, l2, r2 - 1));
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
        cin >> a >> b;
        printf ("Case %d: %d\n", cs, solve(0, a.size() - 1, 0, b.size() - 1));
    }
    return 0;
}

