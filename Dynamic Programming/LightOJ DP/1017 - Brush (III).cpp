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

int n, w, k;
int a[105];
int dp[105][105], mark[105][105];
int cs;

int solve(int pos, int rem)
{
    if (pos == n){
        return 0;
    }
    int &ret = dp[pos][rem];
    int &m = mark[pos][rem];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    for (int i = pos; i < n; i++){
        int cur = a[pos] - a[i];
        if (rem > 0 &&  cur <= w){
            ret = max(ret, (i - pos + 1) + solve(i + 1, rem - 1));
        }
    }
    ret = max(ret, solve(pos + 1, rem));
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> n >> w >> k;
        for (int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            a[i] = y;
        }
        sort(a, a + n, greater<int>());
        printf ("Case %d: %d\n", cs, solve(0, k));
    }
    return 0;
}

