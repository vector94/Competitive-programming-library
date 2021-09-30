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
#define bitcount(number)        __builtin_popcount(number)
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

const int inf = 1 << 30;
int R, C;
int dp[10][(1 << 8) + 5][(1 << 8) + 5], mark[10][(1 << 8) + 5][(1 << 8) + 5];
char grid[10][10];
int light[10];
int cs;

int solve(int pos, int cur_mask, int pre_mask)
{
    if (pos == R){
        if (bitcount(pre_mask) == C){
            return 0;
        }
        return inf;
    }
    int &ret = dp[pos][cur_mask][pre_mask];
    int &m = mark[pos][cur_mask][pre_mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = inf;
    for (int i = 0; i < (1 << C); i++){
        int mask[3] = {pre_mask, cur_mask, light[pos + 1]};
        for (int j = 0; j < C; j++){
            if (!Check(i, j)){
                continue;
            }
            for (int k = 0; k < 3; k++){
                mask[k] ^= (1 << j);
                if (j - 1 >= 0){
                    mask[k] ^= (1 << (j - 1));
                }
                if (j + 1 < C){
                    mask[k] ^= (1 << (j + 1));
                }
            }
        }
        if (pos == 0){
            ret = min(ret, bitcount(i) + solve(pos + 1, mask[2], mask[1]));
        }
        else if (bitcount(mask[0]) == C){
            ret = min(ret, bitcount(i) + solve(pos + 1, mask[2], mask[1]));
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
        cin >> R >> C;
        mem(light, 0);
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                cin >> grid[i][j];
                if (grid[i][j] == '*'){
                    light[i] = Set(light[i], j);
                }
            }
        }
        int res = solve(0, light[0], 0);
        if (res == inf){
            printf ("Case %d: impossible\n", cs);
        }
        else{
            printf ("Case %d: %d\n", cs, res);
        }
    }
    return 0;
}

