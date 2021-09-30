
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

const int nax = 105;
const ll mod = 1000000007;
ll dp[2][nax][nax][nax];
int mark[2][nax][nax][nax];
string a, b, c;
int sz1, sz2, sz3, cs;

ll solve(int flag, int i, int j, int k)
{
    if (k == sz3){
        return 1;
    }
    ll &ret = dp[flag][i][j][k];
    int &m = mark[flag][i][j][k];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    if (i < sz1 && !flag){
        ret += solve(0, i + 1, j, k);
        ret %= mod;
        if (a[i] == c[k]){
            ret += solve(0, i + 1, j, k + 1);
            ret %= mod;
            if (k + 1 < sz3){
                ret += solve(1, i + 1, j, k + 1);
                ret %= mod;
            }
        }
    }
    else if (j < sz2 && flag){
        ret += solve(1, i, j + 1, k);
        ret %= mod;
        if (b[j] == c[k]){
            ret += solve(1, i, j + 1, k + 1);
            ret %= mod;
            if (k + 1 < sz3){
                ret += solve(0, i, j + 1, k + 1);
                ret %= mod;
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
    fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> a >> b >> c;
        sz1 = a.size();
        sz2 = b.size();
        sz3 = c.size();
        ll res = solve(0, 0, 0, 0);
        res += solve(1, 0, 0, 0);
        res %= mod;
        printf ("Case %d: %lld\n", cs, res);
    }
    return 0;
}

