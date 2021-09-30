#include <bits/stdc++.h>
using namespace std;
#define ll                      unsigned long long int
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

ll dp[2][55][55];
int mark[2][55][55];
int cs;

ll solve(int type, int a, int b)
{
    if (a == 0 && b == 0)   return 1;
    if (type == 0 && a == 0)    return 0;
    if (type == 1 && b == 0)    return 0;
    ll &ret = dp[type][a][b];
    int &m = mark[type][a][b];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    if (type == 0){
        for (int i = 1; i <= a; i++){
            ret += solve(1, i - 1, b + a - i);
        }
    }
    else{
        for (int i = 1; i <= b; i++){
            ret += solve(0, a + i - 1, b - i);
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
    for (cs = 1; cs <= t; cs++){
        int n, m;
        cin >> n >> m;
        ll res;
        if (n <= 3){
            res = 1;
        }
        else if (m == 1){
            res = solve(0, 1, n - 3);
        }
        else{
            res = solve(0, m - 1, n - m);
        }
        printf ("Case %d: %llu\n", cs, res);
    }
    return 0;
}

