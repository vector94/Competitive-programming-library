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

const int mod = 1000007;
const int nax = 1005;
int lcs[nax][nax], dp[nax][nax];

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        string a, b;
        cin >> a >> b;
        int len1 = a.size();
        int len2 = b.size();
        for (int i = 0; i <= len1; i++){
            dp[0][i] = dp[i][0] = 1;
        }
        for (int i = 1; i <= len1; i++){
            for (int j = 1; j <= len2; j++){
                if (a[i - 1] == b[j - 1]){
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (lcs[i - 1][j] > lcs[i][j - 1]){
                    lcs[i][j] = lcs[i - 1][j];
                    dp[i][j] = dp[i - 1][j];
                }
                else if (lcs[i - 1][j] < lcs[i][j - 1]){
                    lcs[i][j] = lcs[i][j - 1];
                    dp[i][j] = dp[i][j - 1];
                }
                else{
                    lcs[i][j] = lcs[i][j - 1];
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    if (lcs[i][j] == lcs[i - 1][j - 1]){
                        dp[i][j] -= dp[i - 1][j - 1];
                    }
                    dp[i][j] = (dp[i][j] + mod) % mod;
                }
            }
        }
        printf ("Case %d: %d\n", cs, dp[len1][len2]);
    }
    return 0;
}


