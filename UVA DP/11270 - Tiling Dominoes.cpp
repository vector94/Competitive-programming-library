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
ll Reset(ll num, int pos){
    return num & ~(1LL << pos);
}

bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

ll dp[105][105][(1 << 10) + 5];
int mark[105][105][(1 << 10) + 5];
int row, col, cs;

ll solve(int r, int c, int mask)
{
    if (c == col){
        r++;
        c = 0;
    }
    if (r == row){
        return 1;
    }
    ll &ret = dp[r][c][mask];
    int &m = mark[r][c][mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    if (Check(mask, c)){
        ret = solve(r, c + 1, Reset(mask, c));
    }
    else{
        if (c + 1 < col && !Check(mask, c + 1)){
            ret = solve(r, c + 2, mask);
        }
        if (r + 1 < row){
            ret += solve(r, c + 1, Set(mask, c));
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
    while (cin >> row >> col){
        if (row < col){
            swap(row, col);
        }
        cs++;
        cout << solve(0, 0, 0) << endl;
    }
    return 0;
}


