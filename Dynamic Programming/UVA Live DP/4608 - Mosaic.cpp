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

ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

const int mod = 1e6;
int row, col, cs;
int dp[505][1 << 10], mark[505][1 << 10];

bool check(int r, int c)
{
    return (r >= 0 && r < row && c >= 0 && c < col);
}

int solve(int, int);
int backtrack(int r, int c, int cur_mask, int next_mask)
{
    if (r == row){
        return solve(c + 1, next_mask);
    }
    int ret = 0;
    if (Check(cur_mask, r)){
        ret = backtrack(r + 1, c, cur_mask, next_mask);
        ret %= mod;
        return ret;
        return ret;
    }
    //  **
    //  **
    if (check(r + 1, c + 1) && !Check(cur_mask, r + 1) && !Check(next_mask, r) && !Check(next_mask, r + 1)){
        int cur = Set(next_mask, r);
        ret += backtrack(r + 2, c, cur_mask, Set(cur, r + 1));
    }
    //  **
    //  *
    if (check(r + 1, c + 1) && !Check(cur_mask, r + 1) && !Check(next_mask, r)){
        ret += backtrack(r + 2, c, cur_mask, Set(next_mask, r));
    }
    //  **
    //   *
    if (check(r + 1, c + 1) && !Check(next_mask, r) && !Check(next_mask, r + 1)){
        int cur = Set(next_mask, r);
        ret += backtrack(r + 1, c, cur_mask, Set(cur, r + 1));
    }
    //  *
    //  **
    if (check(r + 1, c + 1) && !Check(cur_mask, r + 1) && !Check(next_mask, r + 1)){
        ret += backtrack(r + 2, c, cur_mask, Set(next_mask, r + 1));
    }
    //   *
    //  **
    if (check(r - 1, c + 1) && !Check(next_mask, r - 1) && !Check(next_mask, r)){
        int cur = Set(next_mask, r - 1);
        ret += backtrack(r + 1, c, cur_mask, Set(cur, r));
    }
    ret %= mod;
    return ret;
}

int solve(int c, int mask)
{
    if (c == col){
        return (mask == 0);
    }
    int &ret = dp[c][mask];
    int &m = mark[c][mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = backtrack(0, c, mask, 0);
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    while (cin >> row >> col){
        if (row == 0 && col == 0){
            break;
        }
        cs++;
        cout << solve(0, 0) << endl;
    }
    return 0;
}

