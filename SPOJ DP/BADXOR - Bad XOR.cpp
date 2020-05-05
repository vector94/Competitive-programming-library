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

const int mod = 100000007;
map<int, bool> visit;
int n, m, cs;
int a[1005], b[1005];
int dp[1005][10005], mark[1005][10005];


int solve(int pos, int Xor)
{
    if (pos == n){
        if (!visit[Xor]){
            return 1;
        }
        return 0;
    }
    int &ret = dp[pos][Xor];
    int &m = mark[pos][Xor];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    ret += solve(pos + 1, Xor ^ a[pos]);
    ret %= mod;
    ret += solve(pos + 1, Xor);
    ret %= mod;
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
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < m; i++){
            cin >> b[i];
            visit[b[i]] = true;
        }
        printf ("Case %d: %d\n", cs, solve(0, 0));
        visit.clear();
    }
    return 0;
}

