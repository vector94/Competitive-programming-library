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

const int inf = 1e8;
int dp[805][205][105], mark[805][205][105];
int cs;

int solve(int rem, int n1, int n5, int n10)
{
    if (n1 < 0 || n5 < 0 || n10 < 0)    return inf;
    if (rem == 0)   return 0;
    int &ret = dp[n1][n5][n10];
    if (mark[n1][n5][n10] == cs)    return ret;
    mark[n1][n5][n10] = cs;
    ret = inf;
    ret = min(ret, solve(rem - 1, n1 + 2, n5, n10 - 1) + 1);
    ret = min(ret, solve(rem - 1, n1 + 2, n5 - 2, n10) + 2);
    ret = min(ret, solve(rem - 1, n1 - 3, n5 - 1, n10) + 4);
    ret = min(ret, solve(rem - 1, n1 - 3, n5 + 1, n10 - 1) + 4);
    ret = min(ret, solve(rem - 1, n1 - 8, n5, n10) + 8);
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
    for (cs = 1; cs <= t; cs++){
        int n, n1, n5, n10;
        scanf ("%d %d %d %d", &n, &n1, &n5, &n10);
        printf ("%d\n", solve(n, n1, n5, n10));
    }
    return 0;
}


