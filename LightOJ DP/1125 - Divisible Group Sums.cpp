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

ll dp[205][12][22];
int mark[205][12][22];
ll a[205], add;
int n, m, d, cs;

ll solve(int pos, int cnt, int sum)
{
    if (pos == n){
        if (cnt == 0 && sum == 0){
            return 1;
        }
        return 0;
    }
    ll &ret = dp[pos][cnt][sum];
    if (mark[pos][cnt][sum] == cs){
        return ret;
    }
    mark[pos][cnt][sum] = cs;
    ret = 0;
    if (cnt){
        ret += solve(pos + 1, cnt - 1, (sum + a[pos] + add) % d);
    }
    ret += solve(pos + 1, cnt, sum);
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
    for (int tc = 1; tc <= t; tc++){
        int q;
        cin >> n >> q;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        printf ("Case %d:\n", tc);
        while (q--){
            cin >> d >> m;
            ll cnt = 1e18 / d;
            add = cnt * d;
            cs++;
            cout << solve(0, m, 0) << endl;
        }
    }
    return 0;
}

