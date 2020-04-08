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

int dp[10][12], mark[10][12];
int a[10];
int n, sz, tc;

int solve(int pre, int pos)
{
    if (pos == sz){
        return 1;
    }
    int &ret = dp[pre][pos];
    if (mark[pre][pos] == tc){
        return ret;
    }
    mark[pre][pos] = tc;
    ret = 0;
    if (pre == 0){
        for (int i = 0; i < n; i++){
            ret += solve(a[i], pos + 1);
        }
    }
    else{
        for (int i = 0; i < n; i++){
            if (abs(pre - a[i]) <= 2){
                ret += solve(a[i], pos + 1);
            }
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
        cin >> n >> sz;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        printf ("Case %d: %d\n", tc, solve(0, 0));
    }
    return 0;
}


