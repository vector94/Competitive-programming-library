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

int k, m, cs;
int dp[105][105][105];

int solve(int cnt, int l, int r)
{
    if (l > r){
        return 0;
    }
    if (cnt == 1){
        return (r * (r + 1)) / 2 - (l * (l - 1)) / 2;
    }
    int &ret = dp[cnt][l][r];
    if (ret != -1){
        return ret;
    }
    ret = INT_MAX;
    for (int i = l; i <= r; i++){
        ret = min(ret, i + max(solve(cnt - 1, l, i - 1), solve(cnt, i + 1, r)));
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
    scanf ("%d", &t);
    mem(dp, -1);
    for (cs = 1; cs <= t; cs++){
        scanf ("%d %d", &k, &m);
        printf ("Case %d: %d\n", cs, solve(k, 1, m));
    }
    return 0;
}


