
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

int n, m, cs;
pii a[105];
bool dp[105][105][105];
int mark[105][105][105];

bool solve(int pos, int need1, int need2, int time)
{
    if (pos == n){
        return (need1 + need2 == 0);
    }
    bool &ret = dp[pos][need1][need2];
    int &m = mark[pos][need1][need2];
    if (m == cs){
        return ret;
    }
    ret = false;
    m = cs;
    for (int i = 0; i <= need1 && a[pos].fi * i <= time; i++){
        int cnt = (time - (a[pos].fi * i)) / a[pos].se;
        cnt = min(cnt, need2);
        ret |= solve(pos + 1, need1 - i, need2 - cnt, time);
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
    for (int tc = 1; tc <= t; tc++){
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> a[i].fi >> a[i].se;
        }
        int lo = 1;
        int hi = 50000;
        int res;
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            cs++;
            if (solve(0, m, m, mid)){
                res = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        printf ("Case %d: %d\n", tc, res);
    }
    return 0;
}

