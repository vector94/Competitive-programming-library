#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define ull                     unsigned long long int
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
#define Binary(number, digit)   bitset<digit>( number ).to_string()
ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}
ll Reset(ll num, int pos){
    return num & ~(1LL << pos);
}

int row, col, cs;
ull dp[105][(1 << 8) + 5];
int mark[105][(1 << 8) + 5];
char grid[105][105], inp[105][105];

bool check(int r, int c)
{
    return (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] != '#');
}

ull solve(int, int);

ull backtrack(int r, int c, int cur_mask, int next_mask)
{
    if (c == col){
        return solve(r + 1, next_mask);
    }
    ull ret = 0;
    if (Check(cur_mask, c) || grid[r][c] == '#'){
        ret = backtrack(r, c + 1, cur_mask, next_mask);
        return ret;
    }

    // **
    if (check(r, c + 1) && !Check(cur_mask, c + 1)){
        ret += backtrack(r, c + 2, cur_mask, next_mask);
    }
    //  *
    //  *
    if (check(r + 1, c) && !Check(next_mask, c)){
        ret += backtrack(r, c + 1, cur_mask, Set(next_mask, c));
    }
    //  **
    //  *
    if (check(r, c + 1) && check(r + 1, c) && !Check(cur_mask, c + 1) && !Check(next_mask, c)){
        ret += backtrack(r, c + 2, cur_mask, Set(next_mask, c));
    }
    //  **
    //   *
    if (check(r, c + 1) && check(r + 1, c + 1) && !Check(cur_mask, c + 1) && !Check(next_mask, c + 1)){
        ret += backtrack(r, c + 2, cur_mask, Set(next_mask, c + 1));
    }
    //  *
    //  **
    if (check(r + 1, c) && check(r + 1, c + 1) && !Check(next_mask, c) && !Check(next_mask, c + 1)){
        int cur = Set(next_mask, c);
        ret += backtrack(r, c + 1, cur_mask, Set(cur, c + 1));
    }
    //   *
    //  **
    if (c - 1 >= 0 && check(r + 1, c - 1) && check(r + 1, c) && !Check(next_mask, c - 1) && !Check(next_mask, c)){
        int cur = Set(next_mask, c - 1);
        ret += backtrack(r, c + 1, cur_mask, Set(cur, c));
    }
    return ret;
}

ull solve(int r, int mask)
{
    if (r == row){
        return (mask == 0);
    }
    ull &ret = dp[r][mask];
    int &m = mark[r][mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = backtrack(r, 0, mask, 0);
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
        cin >> row >> col;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cin >> inp[i][j];
            }
        }
        if (row < col){
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    grid[j][i] = inp[i][j];
                }
            }
            swap(row, col);
        }
        else{
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    grid[i][j] = inp[i][j];
                }
            }
        }
        printf ("Case %d: %llu\n", cs, solve(0, 0));
    }
    return 0;
}


