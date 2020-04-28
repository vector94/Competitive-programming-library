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

const int nax = 2005;
int dp[nax][nax];
int mx[nax];
int a[nax][nax];
int t, h, f;

void reset()
{
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= t; j++){
            a[i][j] = 0;
            dp[i][j] = 0;
        }
        mx[i] = 0;
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int cs;
    cin >> cs;
    while (cs--){
        cin >> t >> h >> f;
        for (int i = 1; i <= t; i++){
            int n;
            cin >> n;
            while (n--){
                int pos;
                cin >> pos;
                a[pos][i]++;
            }
        }
        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= t; j++){
                dp[i][j] = dp[i - 1][j];
                if (i - f >= 0){
                    dp[i][j] = max(dp[i][j], mx[i - f]);
                }
                dp[i][j] += a[i][j];
                mx[i] = max(mx[i], dp[i][j]);
            }
        }
        cout << mx[h] << endl;
        reset();
    }
    cin >> cs;
    return 0;
}


