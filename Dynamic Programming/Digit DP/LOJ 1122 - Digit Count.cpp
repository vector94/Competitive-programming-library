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

const ll inf = 1e18;
int m, n;
int cs;
int ara[15];
ll dp[15][15];
ll mark[15][15];

ll cal(int pre, int cnt)
{
    ll &ret = dp[pre][cnt];
    ll &mk = mark[pre][cnt];
    if (mk == cs){
        return ret;
    }
    if (cnt == n){
        return ret = 1;
    }
    ret = 0;
    mk = cs;

    for (int i = 0; i < m; i++){
        if (pre != 0){
            if (abs(pre - ara[i]) <= 2){
                ret += cal(ara[i], cnt + 1);
            }
        }
        else{
            ret += cal(ara[i], cnt + 1);
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
        cin >> m >> n;
        for (int i = 0; i < m; i++){
            cin >> ara[i];
        }
        ll ans = cal(0, 0);
        printf ("Case %d: %lld\n", cs, ans);
    }
    return 0;
}

