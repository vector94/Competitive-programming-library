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

char grid[25][25];
int n, m;
pii p[20];
int dis[20][20];
int dp[20][1 << 17], mark[20][1 << 17];
int cs, node;

int cal(pii a, pii b)
{
    return max(abs(a.fi - b.fi), abs(a.se - b.se));
}

ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

int solve(int cur, int mask)
{

    if (mask == ((1 << node) - 1)){
        return dis[cur][0];
    }
    int &ret = dp[cur][mask];
    int &m = mark[cur][mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 1e4;
    for (int i = 1; i <= node; i++){
        if (!Check(mask, i)){
            ret = min(ret, dis[cur][i] + solve(i, Set(mask, i)));
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
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        node = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 'x'){
                    p[0].fi = i;
                    p[0].se = j;
                }
                else if (grid[i][j] == 'g'){
                    p[node].fi = i;
                    p[node].se = j;
                    node++;
                }
            }
        }
        for (int i = 0; i < node; i++){
            for (int j = 0; j < node; j++){
                dis[i][j] = cal(p[i], p[j]);
            }
        }
        printf ("Case %d: %d\n", cs, solve(0, 1));
    }
    return 0;
}

