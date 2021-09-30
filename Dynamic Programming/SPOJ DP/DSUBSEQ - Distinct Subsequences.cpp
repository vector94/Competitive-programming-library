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

const int nax = 1e5 + 5;
const ll mod = 1000000007;
ll dp[nax];
int last[30];
string s;

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    while (t--){
        cin >> s;
        int n = s.size();
        mem(last, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            dp[i] = 2 * dp[i - 1];
            int pre = last[s[i - 1] - 'A'];
            if (pre != -1){
                dp[i] -= dp[pre];
            }
            dp[i] = (dp[i] + mod) % mod;
            last[s[i - 1] - 'A'] = i - 1;
        }
        cout << dp[n] << endl;
    }
    return 0;
}



