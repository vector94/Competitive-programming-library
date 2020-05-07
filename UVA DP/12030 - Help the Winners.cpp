#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii                     pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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

ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

int grid[26][20];
int n, cs;
ll dp[2][2][20][1 << 16];
int mark[2][2][20][1 << 16];

ll solve(int zero, int two, int row, int mask)
{
    if (row == n){
        if (two){
            return 1;
        }
        else{
            return !zero;
        }
    }
    ll &ret = dp[zero][two][row][mask];
    int &m = mark[zero][two][row][mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    for (int i = 0; i < n; i++){
        if (!Check(mask, i)){
            ret += solve(zero | (grid[row][i] == 0), two | (grid[row][i] == 2), row + 1, Set(mask, i));
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
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> n;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        printf ("Case %d: %lld\n", cs, solve(0, 0, 0, 0));
    }
    return 0;
}

