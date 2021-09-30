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

int n, m, k;
vector<int> a[505];
int cnt[505][505];
int dp[505][505];

int solve(int pos, int rem)
{
    if (pos == n){
        return 0;
    }
    int &ret = dp[pos][rem];
    if (ret != -1){
        return ret;
    }
    ret = INT_MAX;
    for (int i = 0; i <= a[pos].size(); i++){
        if (rem >= i){
            ret = min(ret, cnt[pos][i] + solve(pos + 1, rem - i));
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
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == '1'){
                a[i].pb(j);
            }
        }
        for (int j = 0; j < a[i].size(); j++){
            cnt[i][j] = INT_MAX;
            for (int k = 0; k <= j; k++){
                int l = k;
                int r = a[i].size() - (j - k) - 1;
                cnt[i][j] = min(cnt[i][j], a[i][r] - a[i][l] + 1);
            }
        }
        cnt[i][a[i].size()] = 0;
    }
    mem(dp, -1);
    cout << solve(0, k) << endl;
    return 0;
}
 
