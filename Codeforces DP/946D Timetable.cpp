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

const int inf = 1e8;
const int nax = 505;
int n, m, k;
int need[nax][nax];
int dp[nax][nax];
int l[nax], r[nax];
string ara[nax];

int solve(int day, int rem)
{
    if (day > n){
        return 0;
    }
    int &ret = dp[day][rem];
    if (ret != -1){
        return ret;
    }
    ret = inf;
    for (int j = m; j >= 0 && need[day][j] <= rem; j--){
        ret = min(ret, j + solve(day + 1, rem - need[day][j]));
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("in1.txt", "r", stdin);
        //freopen ("ans1.txt", "w", stdout);
    #endif
    fastRead;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> ara[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++){
            l[j + 1] = l[j] + (ara[i][j] - '0');
        }
        for (int j = m - 1; j >= 0; j--){
            r[j + 1] = r[j + 2] + (ara[i][j] - '0');
        }
        int total = l[m];
        need[i][0] = total;
        for (int j = 1; j <= m; j++){
            need[i][j] = inf;
            for (int p = 1; p <= m - j + 1; p++){
                need[i][j] = min(need[i][j], total - (l[p + j - 1] - l[p - 1]));
            }
            for (int p = m; p >= j; p--){
                need[i][j] = min(need[i][j], total - (r[p - j + 1] - r[p + 1]));
            }
        }
    }
    mem(dp, -1);
    cout << solve(1, k) << endl;
    return 0;
}
